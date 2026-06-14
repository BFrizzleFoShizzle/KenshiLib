#pragma once

#include "util/hand.h"
#include "util/TimeOfDay.h"
#include "util/YesNoMaybe.h"
#include <ogre/OgreVector3.h>

class Faction;

// TODO move?
enum PersonalityTags
{
    PT_NONE,
    PT_HONORABLE,
    PT_TRAITOROUS,
    PT___,
    PT__,
    PT_SMART,
    PT_DUMB,
    PT____,
    PT_____,
    PT_BRAVE,
    PT_FEARFUL,
    PT_WARM_KIND,
    PT_COLD_CRUEL,
    PT_NORMAL,
    PT_MANIACAL,
    PT_END
};

class StateBroadcastData : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    SlaveStateEnum _slaveState; // 0x0 Member
    TimeOfDay _slaveStateChangedTime; // 0x8 Member
    // no_addr void StateBroadcastData(class StateBroadcastData & _a1);// public missing arg names
    StateBroadcastData(Character* _me);// public RVA = 0x634990
    StateBroadcastData* _CONSTRUCTOR(Character* _me);// public RVA = 0x634990
    Character* me; // 0x10 Member
    Faction* combatTargetsFaction; // 0x18 Member
    hand taskTarget; // 0x20 Member
    bool isAtHome; // 0x40 Member
    bool unconcious; // 0x41 Member
    hand homeBuilding; // 0x48 Member
    hand intendsToAttack; // 0x68 Member
    TownBase* currentTownLocation; // 0x88 Member
    float apparentStrength; // 0x90 Member
    float actualStrength; // 0x94 Member
    float distress; // 0x98 Member
    float mobility; // 0x9C Member
    float aggressionTowardsTarget; // 0xA0 Member
    float noise; // 0xA4 Member
    float followMe; // 0xA8 Member
    float intendedAggression; // 0xAC Member
    float intendedHelp; // 0xB0 Member
    YesNoMaybe isSleeping; // 0xB4 Member
    bool isSitting; // 0xB8 Member
    TimeOfDay lastSlept; // 0xC0 Member
    Ogre::Vector3 pos; // 0xC8 Member
    float relativeAttackerStrength; // 0xD4 Member
    PersonalityTags myPersonality; // 0xD8 Member
    CharacterTypeEnum NPCType; // 0xDC Member
    Faction* isSlaveOf; // 0xE0 Member
    bool isEscapedPrisoner; // 0xE8 Member
    bool isKidnapped; // 0xE9 Member
    bool isTemporaryNeutral; // 0xEA Member
    void save(GameData* state);// public RVA = 0x625E00
    void load(GameData* state);// public RVA = 0x6260B0
    void periodicUpdate();// public RVA = 0x5A47D0
    void setSlaveState(SlaveStateEnum s);// public RVA = 0x5A41C0
    SlaveStateEnum getSlaveState() const;// public RVA = 0x5C6E10
    int getSlaveStateHoursRemaining();// public RVA = 0x598390
    int slaveGUI_min; // 0xEC Member
    float slaveGUI_gear; // 0xF0 Member
    float looksLike_escapedSlave; // 0xF4 Member
    float looksLike_bounty; // 0xF8 Member
    float looksLike_intruder; // 0xFC Member
    float disguiseQuality; // 0x100 Member
    CharacterTypeEnum looksLike_clothingArchetype; // 0x104 Member
    Faction* disguiseFaction; // 0x108 Member
    float disguiseBlown; // 0x110 Member
    void notifyDisguiseBlown();// public RVA = 0x334900
    bool isDisguiseBlown();// public RVA = 0x5C6E20
    Faction* isDisguised();// public RVA = 0x7BF2C0
    bool isHiddenIdentitySlave() const;// public RVA = 0x8504D0
    Faction* getApparentFaction();// public RVA = 0x851690
    bool isAggressor; // 0x114 Member
    // no_addr void ~StateBroadcastData();// public
    // no_addr class StateBroadcastData & operator=(const class StateBroadcastData & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};