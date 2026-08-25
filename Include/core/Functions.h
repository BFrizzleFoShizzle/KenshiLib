#pragma once

#include <Defines.h>
#include <stdint.h>

namespace KenshiLib
{
	KLIB_EXPORT intptr_t GetRealAddress(void* fun);

	//       convenience functions

	// usage: GetRealAddress(&Class::function)
	// NOTE: doesn't work with virtual functions
	template<typename T>
	inline intptr_t GetRealAddress(T fun)
	{
		return GetRealAddress((void*&)fun);
	}

	// NOTE: doesn't work with virtual functions
	template<typename T>
	inline T GetRealFunction(T fun)
	{
		return (T)GetRealAddress(fun);
	}

	enum HookStatus
	{
		SUCCESS,
		FAIL
	};

	// immediately add hook (high overhead)
	KLIB_EXPORT HookStatus AddHook(void* target, void* detour, void** original);
	// queue hook to be added (note: each module/DLL has it's own global queue)
	HookStatus QueueHook(void* target, void* detour, void** original);
	// flushes the hook queue for our module
	HookStatus ApplyQueuedHooks();

	// convenience functions
	template<typename T>
	inline HookStatus AddHook(intptr_t target, void* detour, T** original)
	{
		return AddHook((void*)target, detour, (void**)original);
	}
	template<typename T1, typename T2>
	inline HookStatus AddHook(T1* target, void* detour, T2** original)
	{
		return AddHook((void*)target, detour, (void**)original);
	}
	template<typename T>
	inline HookStatus QueueHook(intptr_t target, void* detour, T** original)
	{
		return QueueHook((void*)target, detour, (void**)original);
	}
	template<typename T1, typename T2>
	inline HookStatus QueueHook(T1* target, void* detour, T2** original)
	{
		return QueueHook((void*)target, detour, (void**)original);
	}

	// *********** DO NOT USE ***********
	// BACKWARDS COMPATIBILITY WILL NOT BE MAINTAINED FOR INTERNAL FUNCTIONS
#ifdef KENSHILIB_INTERNAL
	bool InitRVAs();
#endif
}