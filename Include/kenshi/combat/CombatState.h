#pragma once

class CombatClass;

class CombatState
{
public:
    // VTable         : (none)
    CombatClass* combat; // 0x8 Member
    float stateTimer; // 0x10 Member
    // no_addr void CombatState(const class CombatState & _a1);// public missing arg names
    CombatState(CombatClass* c);// public RVA = 0x2B25B0
    CombatState* _CONSTRUCTOR(CombatClass* c);// public RVA = 0x2B25B0
    virtual bool validate() = 0;// public vtable offset = 0x0
    virtual bool initialise() = 0;// public vtable offset = 0x8
    virtual void update(float _a1) = 0;// public vtable offset = 0x10 missing arg names
    virtual void end() = 0;// public vtable offset = 0x18
    // no_addr class CombatState & operator=(const class CombatState & _a1);// public missing arg names
};

class Character;

class AttackState : public CombatState
{
public:
    // CombatState offset = 0x0, length = 0x18
    float techniqueIntegrityCheckTimer; // 0x18 Member
    // no_addr void AttackState(const class AttackState & _a1);// public missing arg names
    AttackState(CombatClass* c);// public RVA = 0x2B2870
    AttackState* _CONSTRUCTOR(CombatClass* c);// public RVA = 0x2B2870
    virtual bool validate() override;// public RVA = 0x2B3590 vtable offset = 0x0
    bool _NV_validate();// public RVA = 0x2B3590 vtable offset = 0x0
    bool initialiseAttack(Character* target);// public RVA = 0x2B40C0
    virtual bool initialise() override;// public RVA = 0x2B4640 vtable offset = 0x0
    bool _NV_initialise();// public RVA = 0x2B4640 vtable offset = 0x0
    virtual void update(float time) override;// public RVA = 0x2B28A0 vtable offset = 0x0
    void _NV_update(float time);// public RVA = 0x2B28A0 vtable offset = 0x0
    virtual void end() override;// public RVA = 0x2B28B0 vtable offset = 0x0
    void _NV_end();// public RVA = 0x2B28B0 vtable offset = 0x0
    // no_addr class AttackState & operator=(const class AttackState & _a1);// public missing arg names
};

class CircleStateAI : public CombatState
{
public:
    // CombatState offset = 0x0, length = 0x18
    float circlingDirection; // 0x18 Member
    // no_addr void CircleStateAI(const class CircleStateAI & _a1);// public missing arg names
    CircleStateAI(CombatClass* c);// public RVA = 0x2B25D0
    CircleStateAI* _CONSTRUCTOR(CombatClass* c);// public RVA = 0x2B25D0
    bool amOverCrowded();// public RVA = 0x2B2620
    virtual bool validate() override;// public RVA = 0x2B2BC0 vtable offset = 0x0
    bool _NV_validate();// public RVA = 0x2B2BC0 vtable offset = 0x0
    virtual bool initialise() override;// public RVA = 0x2B2C30 vtable offset = 0x0
    bool _NV_initialise();// public RVA = 0x2B2C30 vtable offset = 0x0
    virtual void update(float time) override;// public RVA = 0x2B2CD0 vtable offset = 0x0
    void _NV_update(float time);// public RVA = 0x2B2CD0 vtable offset = 0x0
    virtual void end() override;// public RVA = 0x2B2640 vtable offset = 0x0
    void _NV_end();// public RVA = 0x2B2640 vtable offset = 0x0
    // no_addr class CircleStateAI & operator=(const class CircleStateAI & _a1);// public missing arg names
};

class WaitingStateAI : public CombatState
{
public:
    // CombatState offset = 0x0, length = 0x18
    float circlingDirection; // 0x18 Member
    // no_addr void WaitingStateAI(const class WaitingStateAI & _a1);// public missing arg names
    WaitingStateAI(CombatClass* c);// public RVA = 0x2B2650
    WaitingStateAI* _CONSTRUCTOR(CombatClass* c);// public RVA = 0x2B2650
    virtual bool validate() override;// public RVA = 0x2B3250 vtable offset = 0x0
    bool _NV_validate();// public RVA = 0x2B3250 vtable offset = 0x0
    virtual bool initialise() override;// public RVA = 0x2B32B0 vtable offset = 0x0
    bool _NV_initialise();// public RVA = 0x2B32B0 vtable offset = 0x0
    virtual void update(float time) override;// public RVA = 0x2B3350 vtable offset = 0x0
    void _NV_update(float time);// public RVA = 0x2B3350 vtable offset = 0x0
    virtual void end() override;// public RVA = 0x2B2690 vtable offset = 0x0
    void _NV_end();// public RVA = 0x2B2690 vtable offset = 0x0
    // no_addr class WaitingStateAI & operator=(const class WaitingStateAI & _a1);// public missing arg names
};