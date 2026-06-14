#pragma once

#include <string>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/Enums.h>
#include <kenshi/MedicalSystem.h>

class GameData;

class CombatTechniqueData
{
public:
    // no_addr void CombatTechniqueData(const class CombatTechniqueData & _a1);// public missing arg names
    CombatTechniqueData(GameData* data);// public RVA = 0x667D40
    CombatTechniqueData* _CONSTRUCTOR(GameData* data);// public RVA = 0x667D40
    class ImpactPoint
    {
    public:
        ImpactPoint();// public RVA = 0x664B80
        ImpactPoint* _CONSTRUCTOR();// public RVA = 0x664B80
        CutDirection direction; // 0x0 Member
        float power; // 0x4 Member
        float impactAnimationFrame; // 0x8 Member
        float motionStopsAnimationFrame; // 0xC Member
        RobotLimbs::Limb limb; // 0x10 Member
        const CombatTechniqueData::ImpactPoint& operator=(const CombatTechniqueData::ImpactPoint& a);// public RVA = 0x664BB0
    };
    std::string animation; // 0x0 Member
    float animSpeedMultiplier; // 0x28 Member
    bool isBlock; // 0x2C Member
    bool isDodge; // 0x2D Member
    bool stumbleDodge; // 0x2E Member
    bool gainsGround; // 0x2F Member
    bool isProne; // 0x30 Member
    bool lowStrike; // 0x31 Member
    float hesitationPoint; // 0x34 Member
    float initialDistance; // 0x38 Member
    float minDistanceVsStatic; // 0x3C Member
    float acceptableEndTime01; // 0x40 Member
    float minSkill; // 0x44 Member
    float maxSkill; // 0x48 Member
    float maxEncumbrance; // 0x4C Member
    float chanceMult; // 0x50 Member
    int maxTargetHits; // 0x54 Member
    ogre_unordered_map<GameData*, float>::type events; // 0x58 Member
    bool hasSkillType(WeaponCategory type) const;// public RVA = 0x2B2890
    int numImpactPoints() const;// public RVA = 0x60B210
    CombatTechniqueData::ImpactPoint* impactPoint(int i);// public RVA = 0x2B3960
    bool skillTypes[0x16]; // 0x98 Member
    lektor<CombatTechniqueData::ImpactPoint> impactPoints; // 0xB0 Member
    // no_addr void ~CombatTechniqueData();// public
    // no_addr class CombatTechniqueData & operator=(const class CombatTechniqueData & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};