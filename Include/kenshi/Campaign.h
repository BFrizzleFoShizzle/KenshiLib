#pragma once

#include "util/hand.h"
#include "util/lektor.h"
#include "util/TimeOfDay.h"
#include "FitnessSelector.h"
#include "WorldEventStateQuery.h"
#include "AI/AI.h"
#include "AI/Contract.h"

class GameData;
class Faction;

// TODO move?
enum Phase
{
    GATHERING,
    ASSAULTING,
    RETREATING,
    VICTORY,
    ASSAULT_2_HAPPY,
    ASSAULT_2_ANGRY
};

// TODO move?
class GameDataScoredList : public FitnessSelector<GameData*>
{
public:
    // FitnessSelector<GameData *> offset = 0x0, length = 0x60
    void setupFromData(GameData* spawnData, const std::string& listname, itemType typ);// public RVA = 0x9B7C50
    // no_addr void GameDataScoredList(const class GameDataScoredList & _a1);// public missing arg names
    GameDataScoredList();// public RVA = 0x80FA90
    GameDataScoredList* _CONSTRUCTOR();// public RVA = 0x80FA90
    ~GameDataScoredList();// public RVA = 0x80FF60
    void _DESTRUCTOR();// public RVA = 0x80FF60
    // no_addr class GameDataScoredList & operator=(const class GameDataScoredList & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

// TODO move?
enum WarCampaignEnum
{
    ASSAULT_TOWN,
    CONQUER_TOWN,
    DEFEND_TOWN,
    TRADER_VISIT
};

class CampaignTriggerData
{
public:
    GameData* what; // 0x0 Member
    int minTime; // 0x8 Member
    int maxTime; // 0xC Member
    float chance; // 0x10 Member
};

class CampaignInstance;

class CampaignData
{
public:
    // VTable         : (none)
    Faction* me; // 0x8 Member
    void _setupPackages(GameData* d, const std::string& listname, Phase state);// protected RVA = 0x9C6340
    void _addDataFrom(GameData* d);// protected RVA = 0x9C6690
    // no_addr void CampaignData(const class CampaignData & _a1);// public missing arg names
    CampaignData(Faction* _me, GameData* d);// protected RVA = 0x9C7420
    CampaignData* _CONSTRUCTOR(Faction* _me, GameData* d);// protected RVA = 0x9C7420
    ~CampaignData();// protected RVA = 0x810440
    void _DESTRUCTOR();// protected RVA = 0x810440
    void reset();// protected RVA = 0x9C1ED0
    bool targetCharacters; // 0x10 Member
    bool triggersRandomly_territorial; // 0x11 Member
    bool _isHostile; // 0x12 Member
    int triggerTargetTechLevel; // 0x14 Member
    int triggerTargetPopulation; // 0x18 Member
    float triggerChancePerDay01; // 0x1C Member
    int triggerTimeMin; // 0x20 Member
    int triggerTimeMax; // 0x24 Member
    float triggerRangeNear; // 0x28 Member
    float triggerRangeFurthest; // 0x2C Member
    WorldEventStateQueryList worldStateRequirements; // 0x30 Member
    lektor<GameData*> specificTargetCharacter; // 0x70 Member
    lektor<GameData*> specificLeaderCharacter; // 0x88 Member
    GameDataScoredList spawns; // 0xA0 Member
    float repeatLimit; // 0x100 Member
    WarCampaignEnum campaignType; // 0x104 Member
    WarCampaignEnum key();// public RVA = 0x9C1EE0
    TimeOfDay lastTerritorialTrigger; // 0x108 Member
    bool hasAssaultPhase; // 0x110 Member
    Faction* factionOverride; // 0x118 Member
    lektor<GameData*> allyTriggers; // 0x120 Member
    bool isHostile() const;// public RVA = 0x285200
    std::string getDisplayName();// public RVA = 0x9D2830
    GameData* data; // 0x138 Member
    bool isTriggersRandomly() const;// public RVA = 0x9C1EF0
    virtual RootObjectBase* chooseTarget(Faction* enemy, TownBase** homeTownOut);// public RVA = 0x9C46D0 vtable offset = 0x0
    RootObjectBase* _NV_chooseTarget(Faction* enemy, TownBase** homeTownOut);// public RVA = 0x9C46D0 vtable offset = 0x0
    virtual float territorialTriggerScore(Faction* enemy, RootObjectBase* target);// public RVA = 0x9C3F90 vtable offset = 0x8
    float _NV_territorialTriggerScore(Faction* enemy, RootObjectBase* target);// public RVA = 0x9C3F90 vtable offset = 0x8
    virtual bool canStart();// public RVA = 0x9C3720 vtable offset = 0x10
    bool _NV_canStart();// public RVA = 0x9C3720 vtable offset = 0x10
    virtual CampaignInstance* createCampaign(int _a1, Faction* _a2, const hand& _a3, const hand& _a4) = 0;// public vtable offset = 0x18 missing arg names
    int numForcesNeeded();// public RVA = 0x9C4320
    bool ignoresMults();// public RVA = 0x9D2770
    bool canUseThisSquad(GameData* squadTemplate);// public RVA = 0x9C2930
    std::map<Phase, GameData*, std::less<Phase>, Ogre::STLAllocator<std::pair<Phase const, GameData*>, Ogre::GeneralAllocPolicy > > aiPackagesLeader; // 0x140 Member
    std::map<Phase, GameData*, std::less<Phase>, Ogre::STLAllocator<std::pair<Phase const, GameData*>, Ogre::GeneralAllocPolicy > > aiPackages; // 0x168 Member
    FitnessSelector<CampaignTriggerData*> lossTriggers; // 0x190 Member
    FitnessSelector<CampaignTriggerData*> victoryTriggers; // 0x1F0 Member
    // no_addr class CampaignData & operator=(const class CampaignData & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// protected missing arg names
};

class CampaignInstance : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void CampaignInstance(const class CampaignInstance & _a1);// public missing arg names
    CampaignInstance(int _id, Faction* _me, Faction* enmy, CampaignData* dat, const hand& home);// protected RVA = 0x9D2FC0
    CampaignInstance* _CONSTRUCTOR(int _id, Faction* _me, Faction* enmy, CampaignData* dat, const hand& home);// protected RVA = 0x9D2FC0
    virtual ~CampaignInstance();// protected RVA = 0x9D2A90 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x9D2A90 vtable offset = 0x0
    int uniqueID; // 0x8 Member
    CampaignData* myData; // 0x10 Member
    TimeOfDay phaseChangeTime; // 0x18 Member
    TimeOfDay timeWithNoEnemies; // 0x20 Member
    MoveSpeed travelSpeedUnloaded; // 0x28 Member
    MoveSpeed travelSpeedLoaded; // 0x2C Member
    int manPowerMin; // 0x30 Member
    int manPowerMax; // 0x34 Member
    int manPowerLastCount; // 0x38 Member
    bool reachedDestination; // 0x3C Member
    bool hasTriggeredSomething; // 0x3D Member
    CampaignData* getData();// public RVA = 0x5C7230
    void changePhase(Phase p);// public RVA = 0x28A190
    void saveState(GameData* s, int id);// public RVA = 0x9C4DC0
    void loadState(GameData* s, int id);// public RVA = 0x9C43D0
    virtual void markOnMap();// public RVA = 0x9C2280 vtable offset = 0x8
    void _NV_markOnMap();// public RVA = 0x9C2280 vtable offset = 0x8
    TargetInfo _target; // 0x40 Member
    Faction* me; // 0x70 Member
    Faction* enemy; // 0x78 Member
    hand leader; // 0x80 Member
    hand homeTown; // 0xA0 Member
    Phase currentPhase; // 0xC0 Member
    GameData* getDialogData(EventTriggerEnum ev);// public RVA = 0x9C5810
    bool hasSufficientManpower();// public RVA = 0x9C1F00
    // no_addr int numManpowerNeeded();// public
    virtual void victoryEvent();// public RVA = 0x9CA470 vtable offset = 0x10
    void _NV_victoryEvent();// public RVA = 0x9CA470 vtable offset = 0x10
    virtual void lossEvent();// public RVA = 0x9CA770 vtable offset = 0x18
    void _NV_lossEvent();// public RVA = 0x9CA770 vtable offset = 0x18
    bool canTalkToBeforeArrival; // 0xC4 Member
    lektor<hand> membersInOrder; // 0xC8 Member
    virtual void setLeader(const hand& h);// public RVA = 0x9D2B00 vtable offset = 0x20
    void _NV_setLeader(const hand& h);// public RVA = 0x9D2B00 vtable offset = 0x20
    virtual Character* getLeader();// public RVA = 0x285370 vtable offset = 0x28
    Character* _NV_getLeader();// public RVA = 0x285370 vtable offset = 0x28
    virtual Platoon* getLeaderPlatoon();// public RVA = 0x9D2B40 vtable offset = 0x30
    Platoon* _NV_getLeaderPlatoon();// public RVA = 0x9D2B40 vtable offset = 0x30
    virtual bool isEnemy(Character* who);// public RVA = 0x285320 vtable offset = 0x38
    bool _NV_isEnemy(Character* who);// public RVA = 0x285320 vtable offset = 0x38
    virtual std::string getName();// public RVA = 0x9D3340 vtable offset = 0x40
    std::string _NV_getName();// public RVA = 0x9D3340 vtable offset = 0x40
    virtual bool setup();// public RVA = 0x9D2B80 vtable offset = 0x48
    bool _NV_setup();// public RVA = 0x9D2B80 vtable offset = 0x48
    virtual void periodicUpdate();// public RVA = 0x9C5940 vtable offset = 0x50
    void _NV_periodicUpdate();// public RVA = 0x9C5940 vtable offset = 0x50
    virtual bool isEverybodyIdle();// public RVA = 0x9C1FB0 vtable offset = 0x58
    bool _NV_isEverybodyIdle();// public RVA = 0x9C1FB0 vtable offset = 0x58
    virtual UnloadedPlatoonJob getUnloadedPlatoonBehavior(Platoon* who);// public RVA = 0x9D2B90 vtable offset = 0x60
    UnloadedPlatoonJob _NV_getUnloadedPlatoonBehavior(Platoon* who);// public RVA = 0x9D2B90 vtable offset = 0x60
    virtual GameData* getAIPackage(Platoon* who);// public RVA = 0x9C2E30 vtable offset = 0x68
    GameData* _NV_getAIPackage(Platoon* who);// public RVA = 0x9C2E30 vtable offset = 0x68
    virtual void addToCampaign(Platoon* who, bool forceLeader);// public RVA = 0x9C2F70 vtable offset = 0x70
    void _NV_addToCampaign(Platoon* who, bool forceLeader);// public RVA = 0x9C2F70 vtable offset = 0x70
    virtual bool areForcesAllTogether();// public RVA = 0x9C2160 vtable offset = 0x78
    bool _NV_areForcesAllTogether();// public RVA = 0x9C2160 vtable offset = 0x78
    virtual void removeFromCampaign(Platoon* who);// public RVA = 0x9C31B0 vtable offset = 0x80
    void _NV_removeFromCampaign(Platoon* who);// public RVA = 0x9C31B0 vtable offset = 0x80
    virtual TargetInfo getAITarget(Platoon* who);// public RVA = 0x9D2CD0 vtable offset = 0x88
    TargetInfo _NV_getAITarget(Platoon* who);// public RVA = 0x9D2CD0 vtable offset = 0x88
    virtual MoveSpeed getMoveSpeedUnloaded();// public RVA = 0x9D2BA0 vtable offset = 0x90
    MoveSpeed _NV_getMoveSpeedUnloaded();// public RVA = 0x9D2BA0 vtable offset = 0x90
    virtual MoveSpeed getMoveSpeedLoaded();// public RVA = 0x9D2BB0 vtable offset = 0x98
    MoveSpeed _NV_getMoveSpeedLoaded();// public RVA = 0x9D2BB0 vtable offset = 0x98
    virtual hand getTargetTown();// public RVA = 0x9D2BC0 vtable offset = 0xA0
    hand _NV_getTargetTown();// public RVA = 0x9D2BC0 vtable offset = 0xA0
    virtual Ogre::Vector3 getFormationPosition(Platoon* _a1) = 0;// public vtable offset = 0xA8 missing arg names
    virtual Ogre::Vector3 getDestination(Platoon* who);// public RVA = 0x9C3630 vtable offset = 0xB0
    Ogre::Vector3 _NV_getDestination(Platoon* who);// public RVA = 0x9C3630 vtable offset = 0xB0
    virtual bool isSuccessful() = 0;// public vtable offset = 0xB8
    // no_addr class CampaignInstance & operator=(const class CampaignInstance & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class Campaign_DefendPlayerBase : public Contract_DefendPlayerBase
{
public:
    // Contract_DefendPlayerBase offset = 0x0, length = 0xB0
    virtual bool signalEnd() override;// private RVA = 0x28A2B0 vtable offset = 0x0
    bool _NV_signalEnd();// private RVA = 0x28A2B0 vtable offset = 0x0
    // no_addr void Campaign_DefendPlayerBase(const class Campaign_DefendPlayerBase & _a1);// public missing arg names
    Campaign_DefendPlayerBase();// public RVA = 0x28A210
    Campaign_DefendPlayerBase* _CONSTRUCTOR();// public RVA = 0x28A210
    virtual ~Campaign_DefendPlayerBase();// public RVA = 0x28A330 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x28A330 vtable offset = 0x0
    // no_addr class Campaign_DefendPlayerBase & operator=(const class Campaign_DefendPlayerBase & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};