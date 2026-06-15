#include <core/Functions.h>

#include <kenshi/Kenshi.h>
#include <core/RVA.h>

#include <Release_Assert.h>

#include <MinHook.h>
#include <boost/atomic.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

/* Here's how all this black magic fuckery works
* functions.asm declares an array of pointers to the game's functions
* it also generates a function defintion for every function defined in a header we use, using the function's mangled symbol name
* The function definition is one instruction - a jmp to the corresponding address in the function pointer table
* All function definitions become tightly-packed when assembled, and since each definition consists of one single
* identical instruction, each function body has the exact same size in bytes.
* Thus, we can get the "index" of a function in the address table by taking the function's address, subtracting
* the address of the first defined function, and dividing by the length of a jmp instruction.
* You can then use that index in the function pointer table to get the actual address of the function in the game's code.
* The end result is that you can call any function the game defines using it's regular C++ syntax, and the call will be passed on to the .exe
* as we've created a valid statically-linked definition for it, and you can also get the address of the function in the game's code
* in order to hook it by passing the address of the statically-linked function to GetRealAddress()
* As an added bonus, the pointer table is writeable, so we can dynamically load the offsets for the correct game version at runtime.
* Note: The order of pointers in the pointer array and the order functions are defined in inside functions.asm must be
* EXACTLY IDENTICAL else the whole system breaks.
*/

// array containing absolute function addresses - the length here doesn't matter as it's set in functions.asm
extern "C" uintptr_t function_pointers[1];
// address of first function definition
extern "C" void FUNC_BEGIN(void);
extern "C" void FUNC_END(void);
extern "C" const uint32_t FUNCTION_SIZE;
// amount of "error" in the compiled function table, this MUST be 0
extern "C" const uint32_t FUNCTION_ERROR;
extern "C" const uint32_t FULL_BUFF_LENGTH;

bool KenshiLib::InitRVAs()
{
    assert_release(FUNCTION_ERROR == 0);

    if (KenshiLib::GetKenshiVersion().GetPlatform() == BinaryVersion::UNKNOWN)
    {
        ErrorLog("KenshiLib could not detect Kenshi version.");
        return false;
    }

    // binary RVA path
    std::string RVAFilePath = "RE_Kenshi/RVAs/" + KenshiLib::GetKenshiVersion().GetPlatformStr() + "_" + KenshiLib::GetKenshiVersion().GetVersion() + ".br";
    std::ifstream rvaFile(RVAFilePath, std::ios::ate | std::ios::binary);
    if (!rvaFile.is_open())
    {
        ErrorLog("Unable to open RVA file at " + RVAFilePath);
        return false;
    }

    size_t end = rvaFile.tellg();
    if (end != (FULL_BUFF_LENGTH * sizeof(int)))
    {
        ErrorLog("RVA file has wrong length!");
        assert_release(end == (FULL_BUFF_LENGTH * sizeof(int)), L"RVA file has wrong length!\nCheck the files in \"RE_Kenshi\\RVAs\" match your KenshiLib version.");
        return false;
    }
    rvaFile.seekg(0);

    for (int i = 0; i < FULL_BUFF_LENGTH; ++i)
    {
        int offset;
        rvaFile.read((char*)(&offset), 4);
        RVAPtr<void> c_inst(offset);
        function_pointers[i] = (uintptr_t)c_inst.GetPtr();
    }
    DebugLog("RVAs loaded");

    // init MinHook
    MH_Initialize();
    
    return true;
}

static boost::atomic_uint64_t hookID(1);
KenshiLib::HookStatus KenshiLib::AddHook(void* target, void* detour, void** original)
{
    size_t ID = hookID.fetch_add(1);
    MH_STATUS status = MH_CreateHookEx(ID, target, detour, original);
    if (status != MH_OK)
    {
        ErrorLog("Error creating hook: " + std::to_string((int64_t)status));
        return FAIL;
    }
    status = MH_EnableHookEx(ID, target);
    if (status != MH_OK)
    {
        ErrorLog("Error enabling hook: " + std::to_string((int64_t)status));
        return FAIL;
    }
    return SUCCESS; 
}

// NOTE: doesn't work with virtual functions
static inline uintptr_t GetFunctionSlot(void* ptr)
{
	uintptr_t functionsStart = (uintptr_t)&FUNC_BEGIN;
	uintptr_t functionAddr = (uintptr_t)ptr;
	uintptr_t slot = (functionAddr - functionsStart) / FUNCTION_SIZE;
	return (functionAddr - functionsStart) / FUNCTION_SIZE;
}

intptr_t KenshiLib::GetRealAddress(void* fun)
{
    if (!((uintptr_t&)fun >= (uintptr_t)&FUNC_BEGIN && (uintptr_t&)fun <= (uintptr_t)&FUNC_END))
    {
        std::string moduleName = GetModuleName(fun) + ".dll";
        uintptr_t moduleBase = (uintptr_t)GetModuleHandleA(moduleName.c_str());
        uintptr_t offset = ((uintptr_t)fun) - moduleBase;
        // whitelisted modules - call is unnecessary but crashing here is annoying
        if (boost::iequals(moduleName, "Kenshi_x64.exe.dll") || boost::iequals(moduleName, "Kenshi_GOG_x64.exe.dll")
            || boost::iequals(moduleName, "OgreMain_x64.dll") || boost::iequals(moduleName, "OgreMain_x64.dll") || boost::iequals(moduleName, "MyGUIEngine_x64.dll")
            || boost::iequals(moduleName, "OIS64.dll") || boost::iequals(moduleName, "RenderSystem_Direct3D11_x64.dll") || boost::iequals(moduleName, "Plugin_Terrain_x64.dll")
            || boost::iequals(moduleName, "Plugin_ParticleUniverse_x64.dll") || boost::iequals(moduleName, "Plugin_OctreeSceneManager_x64.dll")
            || boost::iequals(moduleName, "NxCharacter.dll") || boost::iequals(moduleName, "PropertyGrid.dll") || boost::iequals(moduleName, "SkyX_x64.dll")
            || boost::iequals(moduleName, "D3DCompiler_43.dll") || boost::iequals(moduleName, "D3Dx11_43.dll") || boost::iequals(moduleName, "D3D11.dll"))
        {
            // unnecessary call
            ErrorLog("Unnecessary call to KenshiLib::GetRealAddress() from " + GetModuleName(_ReturnAddress()) + " for " + moduleName + (boost::format("+0x%x") % 1234).str());
            ErrorLog("KenshiLib::GetRealAddress() should only be used for KensihLib-exported function stubs with addresses in KenshiLib.dll");
            return (intptr_t)fun;
        }

        uintptr_t callerAddr = (uintptr_t)_ReturnAddress();
        uintptr_t callerBase = 0;
        GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)callerAddr, (HMODULE*)&callerBase);
        std::wstringstream str;
        str << L"Incorrect address in KenshiLib::GetRealAddress()\n";
        if (moduleBase == callerBase)
            // caller is hooking themselves
            str << L"The address you provided appears to be in your own module, try enabling \"whole program optimization\" in your compilation settings.\n";
        if (moduleName == "KenshiLib.dll")
            str << L"The function you are trying to hook appears to be a non-stub KenshiLib function. This is either a KenshiLib bug or you're trying to hook an internal KenshiLib function.\n";
        str << L"Function address: " << std::wstring(moduleName.begin(), moduleName.end()) << "+0x" << std::hex << offset << std::endl;
        str << L"KenshiLib::GetRealAddress() should only be called on KensihLib-exported function stubs with addresses in KenshiLib.dll\n";
        assert_release((uintptr_t&)fun >= (uintptr_t)&FUNC_BEGIN && (uintptr_t&)fun <= (uintptr_t)&FUNC_END, str.str().c_str());
        return (intptr_t)fun;
    }
	return function_pointers[GetFunctionSlot(fun)]; // the cast has to be to a ref to work with member functions in VC++
}
