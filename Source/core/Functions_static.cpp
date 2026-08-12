// This file contains function definitions that are statically-linked
// This is added to the .lib in a post-build step
// DO NOT PUT DYNAMICALLY-LINKED FUNCTION BODIES IN THIS FILE!!!

#include <core/Functions.h>

#include <Debug.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// Forward-declare
KLIB_EXPORT KenshiLib::HookStatus QueueHookInternal(size_t ID, void* target, void* detour, void** original);
KLIB_EXPORT KenshiLib::HookStatus ApplyQueuedHooksInternal(size_t ID);

KenshiLib::HookStatus KenshiLib::QueueHook(void* target, void* detour, void** original)
{
    // use address of module as ID
    // Note: this function is statically-linked so this should get the address of the calling module as opposed to KenshiLib's address
    HMODULE module;
    if (!GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)(KenshiLib::HookStatus(*)(void*, void*, void**))(&QueueHook), &module))
    {
        ErrorLog("Could not get module address for hook ID");
        return KenshiLib::FAIL;
    }
    size_t ID = *reinterpret_cast<size_t*>(&module);

    return QueueHookInternal(ID, target, detour, original);
}


KenshiLib::HookStatus KenshiLib::ApplyQueuedHooks()
{
    // use address of module as ID
    // Note: this function is statically-linked so this should get the address of the calling module as opposed to KenshiLib's address
    HMODULE module;
    if (!GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)&QueueHookInternal, &module))
    {
        ErrorLog("Could not get module address for hook ID");
        return KenshiLib::FAIL;
    }
    size_t ID = *reinterpret_cast<size_t*>(&module);

    return ApplyQueuedHooksInternal(ID);
}