#include <core/Functions.h>

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
	class HookTarget
	{
	public:
		int member(float, bool) { return 0; }
		int constMember(float) const { return 0; }
		static int staticFunction(float) { return 0; }
	};

	typedef int (HookTarget::*MemberTarget)(float, bool);
	typedef int (HookTarget::*ConstMemberTarget)(float) const;
	typedef int (*StaticTarget)(float);
	typedef int (*MemberHook)(HookTarget*, float, bool);
	typedef int (*ConstMemberHook)(const HookTarget*, float);
	typedef int (*StaticHook)(float);

	BOOST_STATIC_ASSERT((boost::is_same<KenshiLib::HookTraits<MemberTarget>::Function, MemberHook>::value));
	BOOST_STATIC_ASSERT((boost::is_same<KenshiLib::HookTraits<ConstMemberTarget>::Function, ConstMemberHook>::value));
	BOOST_STATIC_ASSERT((boost::is_same<KenshiLib::HookTraits<StaticTarget>::Function, StaticHook>::value));

	int memberDetour(HookTarget*, float, bool)
	{
		return 0;
	}

	int constMemberDetour(const HookTarget*, float)
	{
		return 0;
	}

	int staticDetour(float)
	{
		return 0;
	}

	void compileTypedHookCalls()
	{
		MemberHook memberOriginal = 0;
		ConstMemberHook constMemberOriginal = 0;
		StaticHook staticOriginal = 0;

		KenshiLib::AddHook(&HookTarget::member, &memberDetour, &memberOriginal);
		KenshiLib::QueueHook(&HookTarget::constMember, &constMemberDetour, &constMemberOriginal);
		KenshiLib::AddHook(&HookTarget::staticFunction, &staticDetour, &staticOriginal);

		// Existing plugins can keep using the address-based overload.
		KenshiLib::AddHook(KenshiLib::GetRealAddress(&HookTarget::member), &memberDetour, &memberOriginal);
	}
}
