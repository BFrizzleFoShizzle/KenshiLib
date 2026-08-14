#pragma once

#include <Defines.h>
#include <core/HookTraits.h>
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
	// queue hook to be added (note: each module has it's own global queue)
	HookStatus QueueHook(void* target, void* detour, void** original);
	// flushes the hook queue for our module
	HookStatus ApplyQueuedHooks();

	// convenience functions
	//
	// Passing a Kenshi function directly selects these overloads. HookTraits
	// requires the detour and original pointer to exactly match the target's
	// return type and arguments (with an explicit first `this` argument for
	// member functions). Type erasure only happens after that compile-time check.
	template<typename Target>
	inline HookStatus AddHook(Target target, typename HookTraits<Target>::Function detour, typename HookTraits<Target>::Function* original)
	{
		return AddHook((void*)GetRealAddress(target), (void*)detour, (void**)original);
	}
	template<typename Target>
	inline HookStatus QueueHook(Target target, typename HookTraits<Target>::Function detour, typename HookTraits<Target>::Function* original)
	{
		return QueueHook((void*)GetRealAddress(target), (void*)detour, (void**)original);
	}

	// Backwards-compatible address-based overloads. Prefer passing the Kenshi
	// function directly so the target signature can also be checked.
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
