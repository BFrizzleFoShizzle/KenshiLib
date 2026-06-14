#pragma once

#include <kenshi/util/hand.h>

class AIEventClass
{
public:
    // VTable         : (none)
    virtual void update() = 0;// public vtable offset = 0x0
    hand target; // 0x8 Member
    hand sendWhoToDoIt; // 0x28 Member
    float repeatRate; // 0x48 Member
    float repeatTimer; // 0x4C Member
    // no_addr void AIEventClass(const class AIEventClass & _a1);// public missing arg names
    // no_addr void AIEventClass();// public
    // no_addr class AIEventClass & operator=(const class AIEventClass & _a1);// public missing arg names
};

class AIPatrolToTown : public AIEventClass
{
public:
    // AIEventClass offset = 0x0, length = 0x50
    virtual void update() override = 0;// public vtable offset = 0x0
    // no_addr void startEvent();// public
    // no_addr void endEvent();// public
    // no_addr void AIPatrolToTown(const class AIPatrolToTown & _a1);// public missing arg names
    // no_addr void AIPatrolToTown();// public
    // no_addr class AIPatrolToTown & operator=(const class AIPatrolToTown & _a1);// public missing arg names
};