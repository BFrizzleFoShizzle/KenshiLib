#pragma once

#include "AIPackage.h"

class Contract_Timed : public AIPackage
{
public:
    // AIPackage offset = 0x0, length = 0xB0
    virtual bool signalStart() override;// public RVA = 0x286950 vtable offset = 0x0
    bool _NV_signalStart();// public RVA = 0x286950 vtable offset = 0x0
    virtual bool signalEnd() override;// public RVA = 0x286960 vtable offset = 0x0
    bool _NV_signalEnd();// public RVA = 0x286960 vtable offset = 0x0
    // no_addr void Contract_Timed(const class Contract_Timed & _a1);// public missing arg names
    Contract_Timed();// public RVA = 0x286850
    Contract_Timed* _CONSTRUCTOR();// public RVA = 0x286850
    virtual ~Contract_Timed();// public RVA = 0x287470 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x287470 vtable offset = 0x0
    // no_addr class Contract_Timed & operator=(const class Contract_Timed & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class Contract_UntilOutOfDanger : public Contract_Timed
{
public:
    // Contract_Timed offset = 0x0, length = 0xB0
    virtual void activateAndSetup() override;// private RVA = 0x289390 vtable offset = 0x0
    void _NV_activateAndSetup();// private RVA = 0x289390 vtable offset = 0x0
    virtual void periodicUpdate() override;// private RVA = 0x290AE0 vtable offset = 0x0
    void _NV_periodicUpdate();// private RVA = 0x290AE0 vtable offset = 0x0
    virtual MoveSpeed getDesiredTravelSpeed(Character* me) override;// private RVA = 0x2893A0 vtable offset = 0x0
    MoveSpeed _NV_getDesiredTravelSpeed(Character* me);// private RVA = 0x2893A0 vtable offset = 0x0
    virtual bool signalEnd() override;// private RVA = 0x2893C0 vtable offset = 0x0
    bool _NV_signalEnd();// private RVA = 0x2893C0 vtable offset = 0x0
    // no_addr void Contract_UntilOutOfDanger(const class Contract_UntilOutOfDanger & _a1);// public missing arg names
    Contract_UntilOutOfDanger();// public RVA = 0x2892F0
    Contract_UntilOutOfDanger* _CONSTRUCTOR();// public RVA = 0x2892F0
    virtual ~Contract_UntilOutOfDanger();// public RVA = 0x2893B0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x2893B0 vtable offset = 0x0
    // no_addr class Contract_UntilOutOfDanger & operator=(const class Contract_UntilOutOfDanger & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class Contract_UntilExSlave : public AIPackage
{
public:
    // AIPackage offset = 0x0, length = 0xB0
    virtual MoveSpeed getDesiredTravelSpeed(Character* me) override;// private RVA = 0x286A50 vtable offset = 0x0
    MoveSpeed _NV_getDesiredTravelSpeed(Character* me);// private RVA = 0x286A50 vtable offset = 0x0
    virtual bool signalEnd() override;// private RVA = 0x288670 vtable offset = 0x0
    bool _NV_signalEnd();// private RVA = 0x288670 vtable offset = 0x0
    // no_addr void Contract_UntilExSlave(const class Contract_UntilExSlave & _a1);// public missing arg names
    Contract_UntilExSlave();// public RVA = 0x2869B0
    Contract_UntilExSlave* _CONSTRUCTOR();// public RVA = 0x2869B0
    virtual ~Contract_UntilExSlave();// public RVA = 0x287500 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x287500 vtable offset = 0x0
    // no_addr class Contract_UntilExSlave & operator=(const class Contract_UntilExSlave & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class Contract_HiredAlly : public Contract_Timed
{
public:
    // Contract_Timed offset = 0x0, length = 0xB0
    virtual MoveSpeed getDesiredTravelSpeed(Character* me) override;// public RVA = 0x288FD0 vtable offset = 0x0
    MoveSpeed _NV_getDesiredTravelSpeed(Character* me);// public RVA = 0x288FD0 vtable offset = 0x0
    virtual void activateAndSetup() override;// public RVA = 0x288FE0 vtable offset = 0x0
    void _NV_activateAndSetup();// public RVA = 0x288FE0 vtable offset = 0x0
    virtual void periodicUpdate() override;// public RVA = 0x290C30 vtable offset = 0x0
    void _NV_periodicUpdate();// public RVA = 0x290C30 vtable offset = 0x0
    virtual void assessNeutral(Character* who) override;// public RVA = 0x2890C0 vtable offset = 0x0
    void _NV_assessNeutral(Character* who);// public RVA = 0x2890C0 vtable offset = 0x0
    virtual bool assessEnemy(Character* who) override;// public RVA = 0x290D80 vtable offset = 0x0
    bool _NV_assessEnemy(Character* who);// public RVA = 0x290D80 vtable offset = 0x0
    virtual bool notifyBetrayal(Character* me, Character* betrayer) override;// public RVA = 0x289170 vtable offset = 0x0
    bool _NV_notifyBetrayal(Character* me, Character* betrayer);// public RVA = 0x289170 vtable offset = 0x0
    virtual void endPackage() override;// public RVA = 0x289260 vtable offset = 0x0
    void _NV_endPackage();// public RVA = 0x289260 vtable offset = 0x0
    virtual void showEndedMessage();// public RVA = 0x2946D0 vtable offset = 0x98
    void _NV_showEndedMessage();// public RVA = 0x2946D0 vtable offset = 0x98
    virtual bool signalEnd() override;// public RVA = 0x289270 vtable offset = 0x0
    bool _NV_signalEnd();// public RVA = 0x289270 vtable offset = 0x0
    virtual bool getGUIData(DatapanelGUI* panel) override;// public RVA = 0x294A90 vtable offset = 0x0
    bool _NV_getGUIData(DatapanelGUI* panel);// public RVA = 0x294A90 vtable offset = 0x0
    virtual bool wantsRenewButton() override;// public RVA = 0x2892D0 vtable offset = 0x0
    bool _NV_wantsRenewButton();// public RVA = 0x2892D0 vtable offset = 0x0
    virtual void showManagementPanelCallback() override;// public RVA = 0x2892E0 vtable offset = 0x0
    void _NV_showManagementPanelCallback();// public RVA = 0x2892E0 vtable offset = 0x0
    // no_addr void Contract_HiredAlly(const class Contract_HiredAlly & _a1);// public missing arg names
    Contract_HiredAlly();// public RVA = 0x288EB0
    Contract_HiredAlly* _CONSTRUCTOR();// public RVA = 0x288EB0
    virtual ~Contract_HiredAlly();// public RVA = 0x2874C0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x2874C0 vtable offset = 0x0
    // no_addr class Contract_HiredAlly & operator=(const class Contract_HiredAlly & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class Contract_DefendPlayerBase : public Contract_HiredAlly
{
public:
    // Contract_HiredAlly offset = 0x0, length = 0xB0
    virtual bool getGUIData(DatapanelGUI* panel) override;// private RVA = 0x294F40 vtable offset = 0x0
    bool _NV_getGUIData(DatapanelGUI* panel);// private RVA = 0x294F40 vtable offset = 0x0
    virtual TargetInfo getMyTarget(Character* me) override;// private RVA = 0x28F560 vtable offset = 0x0
    TargetInfo _NV_getMyTarget(Character* me);// private RVA = 0x28F560 vtable offset = 0x0
    virtual MoveSpeed getDesiredTravelSpeed(Character* me) override;// private RVA = 0x289CB0 vtable offset = 0x0
    MoveSpeed _NV_getDesiredTravelSpeed(Character* me);// private RVA = 0x289CB0 vtable offset = 0x0
    virtual void activateAndSetup() override;// private RVA = 0x289CC0 vtable offset = 0x0
    void _NV_activateAndSetup();// private RVA = 0x289CC0 vtable offset = 0x0
    virtual void periodicUpdate() override;// private RVA = 0x290F60 vtable offset = 0x0
    void _NV_periodicUpdate();// private RVA = 0x290F60 vtable offset = 0x0
    virtual void assessNeutral(Character* who) override;// private RVA = 0x289DE0 vtable offset = 0x0
    void _NV_assessNeutral(Character* who);// private RVA = 0x289DE0 vtable offset = 0x0
    // no_addr void Contract_DefendPlayerBase(const class Contract_DefendPlayerBase & _a1);// public missing arg names
    Contract_DefendPlayerBase();// public RVA = 0x289C10
    Contract_DefendPlayerBase* _CONSTRUCTOR();// public RVA = 0x289C10
    virtual ~Contract_DefendPlayerBase();// public RVA = 0x2874F0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x2874F0 vtable offset = 0x0
    // no_addr class Contract_DefendPlayerBase & operator=(const class Contract_DefendPlayerBase & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};
