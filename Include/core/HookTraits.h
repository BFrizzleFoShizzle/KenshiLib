#pragma once

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

namespace KenshiLib
{
	// Converts a Kenshi function declaration into the function pointer type a
	// MinHook detour must use. Member function detours receive the object as an
	// explicit first argument on Windows x64.
	template<typename Target>
	struct HookTraits;

#define KLIB_DEFINE_HOOK_TRAITS(z, argumentCount, unused) \
	template<typename ReturnType BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, typename Argument)> \
	struct HookTraits<ReturnType (*)(BOOST_PP_ENUM_PARAMS(argumentCount, Argument))> \
	{ \
		typedef ReturnType (*Function)(BOOST_PP_ENUM_PARAMS(argumentCount, Argument)); \
	}; \
	\
	template<typename ReturnType, typename Class BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, typename Argument)> \
	struct HookTraits<ReturnType (Class::*)(BOOST_PP_ENUM_PARAMS(argumentCount, Argument))> \
	{ \
		typedef ReturnType (*Function)(Class* BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, Argument)); \
	}; \
	\
	template<typename ReturnType, typename Class BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, typename Argument)> \
	struct HookTraits<ReturnType (Class::*)(BOOST_PP_ENUM_PARAMS(argumentCount, Argument)) const> \
	{ \
		typedef ReturnType (*Function)(const Class* BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, Argument)); \
	}; \
	\
	template<typename ReturnType, typename Class BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, typename Argument)> \
	struct HookTraits<ReturnType (Class::*)(BOOST_PP_ENUM_PARAMS(argumentCount, Argument)) volatile> \
	{ \
		typedef ReturnType (*Function)(volatile Class* BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, Argument)); \
	}; \
	\
	template<typename ReturnType, typename Class BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, typename Argument)> \
	struct HookTraits<ReturnType (Class::*)(BOOST_PP_ENUM_PARAMS(argumentCount, Argument)) const volatile> \
	{ \
		typedef ReturnType (*Function)(const volatile Class* BOOST_PP_COMMA_IF(argumentCount) BOOST_PP_ENUM_PARAMS(argumentCount, Argument)); \
	};

	// The largest recovered Kenshi declaration currently has fewer than 24
	// arguments. Keeping the limit here avoids one specialization per symbol.
	BOOST_PP_REPEAT(25, KLIB_DEFINE_HOOK_TRAITS, ~)

#undef KLIB_DEFINE_HOOK_TRAITS
}
