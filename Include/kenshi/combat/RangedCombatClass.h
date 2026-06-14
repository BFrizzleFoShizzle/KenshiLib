#pragma once

#include <kenshi/Enums.h>
#include <kenshi/util/YesNoMaybe.h>
#include <kenshi/util/hand.h>
#include <ogre/OgreVector3.h>

class Character;
class TurretBuilding;
class GunClass;
class DatapanelGUI;
class physHit;
class BadTargetRememberer;

class RangedCombatClass
{
public:
    // no_addr void RangedCombatClass(const class RangedCombatClass & _a1);// public missing arg names
    RangedCombatClass(Character* m);// public RVA = 0x4397A0
    RangedCombatClass* _CONSTRUCTOR(Character* m);// public RVA = 0x4397A0
    // no_addr void ~RangedCombatClass();// public
    enum RangedState
    {
        SHOOTING,
        MOVING,
        RELOADING,
        WAITING,
        THINKING
    };

    RangedCombatClass::RangedState state; // 0x0 Member
    void setState(RangedCombatClass::RangedState s);// public RVA = 0x433EE0
    void setup(TurretBuilding* _turret, StatsEnumerated stat);// public RVA = 0x433DF0
    GunClass* getGun();// public RVA = 0x433E40
    bool isInRangedCombatMode() const;// public RVA = 0x43FDB0
    void updateT(float frameTime, const hand& designatedTarget, const hand& suggestedTarget);// public RVA = 0x4384F0
    void updateMT(float frameTime);// public RVA = 0x43A760
    void end();// public RVA = 0x436CF0
    hand _getAttackTarget() const;// public RVA = 0x441050
    static float scoreTargetRange(const Ogre::Vector3& from, const Ogre::Vector3& target, float maxRange, float minRange);// public RVA = 0x435570
    void printGUIState(DatapanelGUI* datapanel, int category);// public RVA = 0x437EC0
    // no_addr bool isReloading();// public
    bool isInRange(const Ogre::Vector3& v) const;// public RVA = 0x4360E0
    float getGunRange(const Ogre::Vector3& v) const;// public RVA = 0x436190
    void animationUpdate(float frameTime, const Ogre::Vector3& aimpos, RootObject* target);// private RVA = 0x51DD60
    bool reloadCheck();// private RVA = 0x437560
    YesNoMaybe takeTheShotCheck(Character* target);// private RVA = 0x437350
    void aimAtTarget(const Ogre::Vector3& target);// private RVA = 0x434150
    Ogre::Vector3 getAimPos(Character* what);// private RVA = 0x436590
    float _lastAimAheadAmount; // 0x4 Member
    Character* chooseNewTarget(Character* oldTarget);// private RVA = 0x436D50
    void setTarget(Character* target);// private RVA = 0x436A70
    float scoreTarget(Character* who, float rangeMult);// private RVA = 0x4355F0
    void resetShotTimer();// private RVA = 0x4349D0
    bool traceHitFurtherThanTarget(const physHit& hit, const Ogre::Vector3& target);// private RVA = 0x433F50
    Character* reAssessTargeting(const hand& designatedTarget, const hand& suggestedTarget);// private RVA = 0x4377C0
    hand turret; // 0x8 Member
    GunClass* gun; // 0x28 Member
    StatsEnumerated currentStat; // 0x30 Member
    bool updateNeededMsg; // 0x34 Member
    bool takeAShotMsg; // 0x35 Member
    bool combatMode; // 0x36 Member
    Ogre::Vector3 currentAimPos; // 0x38 Member
    hand currentTarget; // 0x48 Member
    Character* me; // 0x68 Member
    float aimTimer; // 0x70 Member
    float reloadTimerMax; // 0x74 Member
    float reloadTimer; // 0x78 Member
    float stateTimer; // 0x7C Member
    bool _isReloading; // 0x80 Member
    BadTargetRememberer* badTargetRememberer; // 0x88 Member
    // no_addr class RangedCombatClass & operator=(const class RangedCombatClass & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};