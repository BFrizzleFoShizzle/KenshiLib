#pragma once

#include "../SensoryData.h"

class AITaskSytem;
class function;

// TODO move?
class StateFunctionList
{
public:
    void add(StateType key, function* f);// public RVA = 0x61F450
    bool isTrue(AI* ai, StateType key, const hand& h, const Ogre::Vector3& v, bool desired);// public RVA = 0x61F490
    bool hasState(StateType key);// public RVA = 0x61F520
    boost::unordered::unordered_map<StateType, bool(__cdecl AI::*)(hand const&, Ogre::Vector3 const&), boost::hash<StateType>, std::equal_to<StateType>, Ogre::STLAllocator<std::pair<StateType const, bool(__cdecl AI::*)(hand const&, Ogre::Vector3 const&)>, Ogre::GeneralAllocPolicy > > stateFuncs; // 0x0 Member
    // no_addr void StateFunctionList(const class StateFunctionList & _a1);// public missing arg names
    StateFunctionList();// public RVA = 0x5AFBF0
    StateFunctionList* _CONSTRUCTOR();// public RVA = 0x5AFBF0
    ~StateFunctionList();// public RVA = 0x5AFC40
    void _DESTRUCTOR();// public RVA = 0x5AFC40
    // no_addr class StateFunctionList & operator=(const class StateFunctionList & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class TaskMatch;
class StorageBuilding;

class TargetWithScore
{
public:
    TargetWithScore(const TargetWithScore& __that);// public RVA = 0x61A820
    TargetWithScore* _CONSTRUCTOR(const TargetWithScore& __that);// public RVA = 0x61A820
    TargetWithScore(const hand& t, float s);// public RVA = 0x61A490
    TargetWithScore* _CONSTRUCTOR(const hand& t, float s);// public RVA = 0x61A490
    hand target; // 0x0 Member
    float score; // 0x20 Member
    TargetWithScore& operator=(const TargetWithScore& __that);// public RVA = 0x60DF50
    // no_addr void __dflt_ctor_closure();// public
};

class TaskRepertoire;
class TaskStateData;
class Blackboard;
class CharBody;
class Inventory;
class CharStats;
class MedicalSystem;
class CharacterMessage;
class TradingInfo;

// TODO move?
enum TargetInfoType
{
    TI_TOWN,
    TI_CHARACTER
};

class TargetInfo
{
public:
    void setupType();// private RVA = 0x2680B0
    TargetInfo(const TargetInfo& __that);// public RVA = 0x7C21A0
    TargetInfo* _CONSTRUCTOR(const TargetInfo& __that);// public RVA = 0x7C21A0
    // no_addr void TargetInfo(const class Ogre::Vector3 & _a1);// public missing arg names
    TargetInfo(const hand& h, const Ogre::Vector3& v);// public RVA = 0x288060
    TargetInfo* _CONSTRUCTOR(const hand& h, const Ogre::Vector3& v);// public RVA = 0x288060
    TargetInfo(const hand& h);// public RVA = 0x278BF0
    TargetInfo* _CONSTRUCTOR(const hand& h);// public RVA = 0x278BF0
    TargetInfo(int _a1);// public RVA = 0x291110 missing arg names
    TargetInfo* _CONSTRUCTOR(int _a1);// public RVA = 0x291110 missing arg names
    TargetInfo();// public RVA = 0x9D2960
    TargetInfo* _CONSTRUCTOR();// public RVA = 0x9D2960
    hand what; // 0x0 Member
    Ogre::Vector3 pos; // 0x20 Member
    TargetInfoType targetType; // 0x2C Member
    // no_addr class TargetInfo & operator=(const class TargetInfo & _a1);// public missing arg names
    // no_addr const class TargetInfo & operator=(const int & _a1);// public missing arg names
    const TargetInfo& operator=(const hand& p);// public RVA = 0x9D29B0
    // no_addr class hand operator class hand();// public
    // no_addr class Ogre::Vector3 operator class Ogre::Vector3();// public
    operator bool() const;// public RVA = 0x7BF280
    bool isTown() const;// public RVA = 0x506320
    bool isCharacter() const;// public RVA = 0x506330
    TownBase* getTown() const;// public RVA = 0x506340
    Character* getCharacter() const;// public RVA = 0x506350
    Ogre::Vector3 getPositionForWaypoint(const Ogre::Vector3& from);// public RVA = 0x9B4E20
};

class UseableStuff;

// TODO move?
enum NodeType
{
    NODE_SHOPKEEPER,
    NODE_GENERAL,
    NODE_GUARD_POST,
    NODE_TURRET,
    NODE_USE,
    NODE_LIGHT,
    NODE_NULL
};

class AI : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    static StateFunctionList stateFuncs; // RVA = 0x1E43450 Static Member
    void _createTradingInfo();// private RVA = 0x99F860
    bool isWithinChoppingRange(RootObjectBase* subj, bool isMoving);// private RVA = 0x59BF50
    float meiDistance; // 0x8 Member
    float meiDistanceTolerance; // 0xC Member
    Platoon* platoon; // 0x10 Member
    StateBroadcastData* state; // 0x18 Member
    AITaskSytem* taskSystemAI; // 0x20 Member
    SensoryData sensoryData; // 0x28 Member
    unsigned int taskRepertoireFlags; // 0x200 Member
    class AIResultsCacher
    {
    public:
        AI* ai; // 0x0 Member
        // no_addr void AIResultsCacher(const class AI::AIResultsCacher & _a1);// public missing arg names
        AIResultsCacher(AI* _me);// public RVA = 0x640690
        AIResultsCacher* _CONSTRUCTOR(AI* _me);// public RVA = 0x640690
        void resetAllCaches();// public RVA = 0x518620
        void cacheResult_reqs(const TaskMatch& key, bool b);// public RVA = 0x61F560
        bool getCacheResult_reqs(const TaskMatch& key);// public RVA = 0x61F590
        bool hasCacheResult_reqs(const TaskMatch& key) const;// public RVA = 0x61DA70
        void cacheResult_results(const TaskMatch& key, bool b);// public RVA = 0x61F5B0
        bool getCacheResult_results(const TaskMatch& key);// public RVA = 0x61F5E0
        bool hasCacheResult_results(const TaskMatch& key) const;// public RVA = 0x61DB40
        float runTargetFinder(function* func, const TaskMatch& key, hand& out);// public RVA = 0x60EA50
        void resetSpecificTargetFinderCache(const TaskMatch& key);// public RVA = 0x518FA0
        float getResourceSource(hand& buildingFound, GameData* resourceNeeded, StorageBuilding* skip);// public RVA = 0x59C880
        void cacheResult_targetFinder(TaskMatch key, const hand& sub, float score);// private RVA = 0x61F600
        std::map<TaskMatch, TargetWithScore, std::less<TaskMatch>, Ogre::STLAllocator<std::pair<TaskMatch const, TargetWithScore>, Ogre::GeneralAllocPolicy > > targetFindersCache; // 0x8 Member
        std::map<TaskMatch, bool, std::less<TaskMatch>, Ogre::STLAllocator<std::pair<TaskMatch const, bool>, Ogre::GeneralAllocPolicy > > requirementsCache; // 0x30 Member
        std::map<TaskMatch, bool, std::less<TaskMatch>, Ogre::STLAllocator<std::pair<TaskMatch const, bool>, Ogre::GeneralAllocPolicy > > resultsCache; // 0x58 Member
        std::map<GameData*, hand, std::less<GameData*>, std::allocator<std::pair<GameData* const, hand> > > resourceSourceCache; // 0x80 Member
        ~AIResultsCacher();// public RVA = 0x63F330
        void _DESTRUCTOR();// public RVA = 0x63F330
        // no_addr class AI::AIResultsCacher & operator=(const class AI::AIResultsCacher & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    AI::AIResultsCacher resultsCache; // 0x208 Member
    static void setFunc(StateType t, function* func, const std::string& name, const std::string& speech);// public RVA = 0x60F9F0
    static void _setupGOAPFuncs();// public RVA = 0x60FAD0
    TaskRepertoire* taskRepertoire; // 0x2A8 Member
    void setTaskRepertoireFlag(unsigned int flag);// public RVA = 0x60E0C0
    void clearTaskRepertoireFlag(unsigned int flag);// public RVA = 0x60E140
    void forceOrderInsert(TaskType t);// public RVA = 0x507550
    virtual bool stateIsTrue(const TaskStateData& state, const hand& h, const Ogre::Vector3& v);// public RVA = 0x60EC00 vtable offset = 0x0
    bool _NV_stateIsTrue(const TaskStateData& state, const hand& h, const Ogre::Vector3& v);// public RVA = 0x60EC00 vtable offset = 0x0
    // no_addr bool isUnconcious();// public
    void addAIGoalsFrom(GameData* data, const std::string& goallistname);// public RVA = 0x508D70
    bool isWithinGivenRange(const hand& subject, const Ogre::Vector3& loc, float _range);// public RVA = 0x5A2900
    SensoryData* getSensoryData();// public RVA = 0x43FCC0
    AITaskSytem* getTaskSystem() const;// public RVA = 0x268290
    StateBroadcastData* getStateBroadcast();// public RVA = 0x32DAC0
    void _notifyTaskComplete();// public RVA = 0x3349D0
    enum AIAggressionOrders
    {
        AGGRESSIVE,
        DEFENSIVE,
        EVASIVE
    };

    enum AIManuverabilityOrders
    {
        HOLD_GROUND,
        STAY_CLOSE,
        ROAM_FAR
    };

    // no_addr void chooseNewDestinationTown();// public
    TownBase* getDestinationTown();// public RVA = 0x506F80
    void setPlatoon(Platoon* p);// public RVA = 0x506540
    Platoon* getPlatoon() const;// public RVA = 0x2682A0
    virtual Faction* getFaction();// public RVA = 0x506550 vtable offset = 0x8
    Faction* _NV_getFaction();// public RVA = 0x506550 vtable offset = 0x8
    Blackboard* getBlackboard();// public RVA = 0x5068F0
    hand getHandle() const;// public RVA = 0x50A360
    // no_addr void AI(const class AI & _a1);// public missing arg names
    AI(StateBroadcastData* _state, Character* c);// public RVA = 0x622F50
    AI* _CONSTRUCTOR(StateBroadcastData* _state, Character* c);// public RVA = 0x622F50
    virtual ~AI();// public RVA = 0x6230D0 vtable offset = 0x10
    void _DESTRUCTOR();// public RVA = 0x6230D0 vtable offset = 0x10
    void create(CharBody* b, Inventory* inv, CharStats* st, MedicalSystem* med, Platoon* p);// public RVA = 0x621990
    virtual void update4Frame(float frametime);// public RVA = 0x595E30 vtable offset = 0x18
    void _NV_update4Frame(float frametime);// public RVA = 0x595E30 vtable offset = 0x18
    virtual void periodicUpdate(float frametime);// public RVA = 0x510B30 vtable offset = 0x20
    void _NV_periodicUpdate(float frametime);// public RVA = 0x510B30 vtable offset = 0x20
    void periodicUpdate_KOed(float frametime);// public RVA = 0x50C040
    void sendMessage(CharacterMessage message, const hand& sender, const hand& subject);// public RVA = 0x595EF0
    void underMeleeAttack(Character* attacker, bool so, bool doAwarenessCheck);// public RVA = 0x998750
    void underRangedAttack(Character* attacker, bool so);// public RVA = 0x9985A0
    bool isTargetOutsideTheGates(RootObject* target);// public RVA = 0x597CD0
    bool amILockedWithinTownWalls();// public RVA = 0x597C80
    TradingInfo* tradingInfo; // 0x2B0 Member
    bool isEnemy(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A3680
    bool isEnemy(RootObjectBase* c);// public RVA = 0x5996B0
    void load(GameData* d);// public RVA = 0x9A0880
    void save(GameData* d);// public RVA = 0x9A08A0
    Ogre::Vector3 getPosWithinChoppingRange(RootObjectBase* subj, const Ogre::Vector3& clickPos);// public RVA = 0x59B7B0
    bool chooseBestAttackTarget(RootObject** targetOut, lektor<Character*>& enemies, float& _score, hand oldTarget, bool lawEnforcer, bool combatModeNow);// public RVA = 0x59DB80
    void setAggressionLevel(AI::AIAggressionOrders agg);// public RVA = 0x5C71A0
    // no_addr enum AI::AIAggressionOrders getAggressionLevel();// public
    void setManuveringFreedomLevel(AI::AIManuverabilityOrders agg);// public RVA = 0x595F00
    void setCenterOfMovement(const Ogre::Vector3& wher);// public RVA = 0x5991F0
    void setCenterOfMovementTarget(const hand& wher);// public RVA = 0x595F20
    virtual hand getCombatTarget();// public RVA = 0x435DF0 vtable offset = 0x28
    hand _NV_getCombatTarget();// public RVA = 0x435DF0 vtable offset = 0x28
    virtual void updateStateBroadcast(float time);// public RVA = 0x5A4360 vtable offset = 0x30
    void _NV_updateStateBroadcast(float time);// public RVA = 0x5A4360 vtable offset = 0x30
    bool buySomething(Building* shop);// public RVA = 0x99FD00
    bool IDontWantToLeaveTown();// public RVA = 0x598290
    AI::AIAggressionOrders ordersAggression; // 0x2B8 Member
    AI::AIManuverabilityOrders ordersMovement; // 0x2BC Member
    Ogre::Vector3 centerOfMovement; // 0x2C0 Member
    hand centerOfMovementTarget; // 0x2D0 Member
    double slaveStateTimeStamp; // 0x2F0 Member
    virtual Ogre::Vector3 getPosition();// private RVA = 0x640D90 vtable offset = 0x38
    Ogre::Vector3 _NV_getPosition();// private RVA = 0x640D90 vtable offset = 0x38
    virtual bool amMoving();// private RVA = 0x790A70 vtable offset = 0x40
    bool _NV_amMoving();// private RVA = 0x790A70 vtable offset = 0x40
    virtual void periodicUpdateStateBroadcast(float time);// private RVA = 0x5A4A60 vtable offset = 0x48
    void _NV_periodicUpdateStateBroadcast(float time);// private RVA = 0x5A4A60 vtable offset = 0x48
    Character* me; // 0x2F8 Member
    CharBody* body; // 0x300 Member
    Inventory* inventory; // 0x308 Member
    CharStats* stats; // 0x310 Member
    MedicalSystem* medical; // 0x318 Member
    Character* getCharacter();// public RVA = 0x2682B0
    TargetInfo getMyMissionTarget();// public RVA = 0x794EC0
    void getAllMyPermajobMachines(ogre_unordered_set<UseableStuff*>::type& out);// public RVA = 0x5A3A30
    bool hasPermajob(TaskType t) const;// public RVA = 0x596C00
    virtual bool noneState(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640DC0 vtable offset = 0x50
    bool _NV_noneState(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640DC0 vtable offset = 0x50
    virtual bool isAtLocation(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1CD0 vtable offset = 0x58
    bool _NV_isAtLocation(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1CD0 vtable offset = 0x58
    bool isLocationAccessible(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A1F90
    bool isDestinationAccessible(RootObject* target, bool outsideBuilding);// public RVA = 0x5968B0
    bool isDestinationAccessible(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A20A0
    bool isDestinationAccessibleAnimal(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A20E0
    bool isAtDoorOf(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A1E30
    bool isAtDoorOf_Inside(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x596570
    bool isAtDoorOf_Outside(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x596710
    bool isAtDoorOfCurrentLocation(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A1F00
    bool isBuildingComplete(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5963A0
    bool isSubjectInInventory(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59C6B0
    bool isNoEnemiesInVicinity(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596EB0
    bool isTargetDown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x998DF0
    bool targetIsConscious(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x998CD0
    bool isLeaderDown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x9964C0
    bool isTargetEnemy(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59AFE0
    bool crowdLimit8(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599390
    bool hasWeapon(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x59A240 missing arg names
    bool hasWeaponEquipped(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x5962B0 missing arg names
    bool hasCrossbowEquipped(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x5962F0 missing arg names
    bool hasAnythingEquipped(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x60DDC0
    bool isAlliesFighting(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x998BA0 missing arg names
    bool isSquadmatesFighting(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x998C30
    bool iAmBeingMeleeAttacked_immediate(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x435050
    bool iAmBeingMeleeAttacked_general(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x435FA0
    bool isAggressionTowards(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59D690
    bool isAggressionTowardsMe(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A2D20
    bool isGeneralAggressionLevel(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x597340 missing arg names
    bool isItemLootable(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59D540
    bool amIdle(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x60DE30
    bool needsFirstAid(const hand& _subject, const Ogre::Vector3& _a2);// public RVA = 0x99C140
    bool myLegsAreMessedUpButCouldBeFixed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x996910
    bool haveFirstAidKit(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5980E0
    bool needsFirstAid_robot(const hand& _subject, const Ogre::Vector3& _a2);// public RVA = 0x99C250
    bool haveFirstAidKit_robot(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5981E0
    bool needsSplint(const hand& _subject, const Ogre::Vector3& _a2);// public RVA = 0x99C360
    bool hasSplintKit(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598160
    bool hasTools(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598260
    bool isCrouching(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596EF0
    bool isCrouchingOrLying(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x599710
    bool isLyingProne(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596F10
    bool isMovementAllowed(const hand& subject, const Ogre::Vector3& location);// public RVA = 0x5A2BF0
    bool isAtHome(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x997EF0
    bool isAtHomeTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x996830
    bool targetStandingStill(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x799EC0
    bool hasOneWorkingArm(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x996CC0
    bool hasTwoWorkingArms(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x996D20
    bool isReadyForAction(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x996DA0
    bool iAmDown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598430
    bool iAmProne(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598470
    bool canGetUp(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5984A0
    float scoreCanGetUp(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x317720
    bool isCarryingSomething(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5985A0
    bool isCarriedDudeInBed(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x60DE40
    bool isCarriedDudeDead(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A0D60
    bool isCarryingTarget(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599B80
    bool final_gotAKidnapVictim(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A3200
    bool final_foundAndPutInCage(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598580
    bool targetIsArrested(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599C00
    bool alarmsInTheVicinity(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5988E0
    bool intruderIsOutside(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598770
    bool intruderIsOutsideGates(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598820
    bool amSwimming(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598710
    bool isTargetSwimming(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598740
    bool isBeingCarried(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5985C0
    bool hasBuildingMaterials(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59B2D0
    bool buildingHasBuildingMaterials(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A3240
    bool isDoorBroken(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A3290
    bool isDoorOpen(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A3350
    bool isDoorOpenHere(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x5A3410 missing arg names
    bool iAmInsideTargetBuilding(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599D30
    bool farmHasFood(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x8C8BA0
    bool amHungry(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x8C8B90
    bool iHaveSufficientLockSkill(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x8C8A80
    bool iHaveSufficientLockSkillForShackles(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x8C8970
    float scoreIAmInsideTargetBuilding(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x317750
    float scoreIAmOutsideTargetBuilding(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x317790
    bool machineHasEmptyInputs(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596D60
    bool isMachineOutputFull(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A2420
    bool machineHasFullInputs(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A2470
    bool isMachineOutputEmpty(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A24C0
    bool haveSomeResourcesFrom(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596DB0
    bool haveSomeResourcesFromThisMachineButWantThemGoneIfPossible(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A2510
    bool haveSomeResourcesFor(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A3E70
    bool isMachineJammed(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A26E0
    bool isAnyMachineJammed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A2780
    bool isMachineInputInvalid(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596E50
    bool gotInventoryRoomForResources(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59B600
    bool isRouteTraceBlocked(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596EA0
    bool isDoorLocked(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59F940
    bool isDoorLockedHere(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x5A3450 missing arg names
    bool isDoorLockedAndMeInside(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59FB50
    bool isDoorLockedAndMeOutside(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59FCF0
    bool isObjectMine(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A3490
    bool isBuildingDamaged(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5985E0
    bool isBuildingDestroyed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598620
    bool isFullyRested(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59FE90
    bool machineHasFreeOperatorSlot(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598660
    bool isDialogDelivered(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x790EE0
    bool isMessageDelivered(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x790F30
    bool isEnemyForceDefeated(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596ED0
    bool isInBed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598DC0
    bool isCarryingArmOK(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5C71B0
    bool isAtAShop(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x996ED0
    bool boughtShitComplete(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x9977F0
    bool isInsideTargetBuilding(const hand& what, const Ogre::Vector3& _a2);// public RVA = 0x596410
    bool allDoorsLocked(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x596450
    bool destinationNotBlockedByFortifications(RootObject* target);// public RVA = 0x5969E0
    bool destinationNotBlockedByFortifications(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A2120
    bool atLocationGate(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A2150
    bool isAlly(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A3730
    bool buildingHasPower(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x596330
    bool hasDestinationTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x506E50
    bool isCarryingHealthyTarget(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x59A3B0
    bool atDestinationTown(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x506E90
    bool atPackageTarget(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5065B0
    bool atATown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x506590
    bool targetAtATown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x508330
    bool isTiredFromTravel(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x506FB0
    float scoreGetNextDestinationTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x507000
    float scoreWantsToGetUp_toFeet(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598500
    float scoreWantsToGetUp_stayLow(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598540
    bool isNearTo(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A2AF0
    bool isWithin50Meters(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A2B10
    bool isWithin10Meters(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A2B30
    bool isWithinMyBowRange(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A2B50
    bool isTargetRestrainedOrKO(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1020
    bool isOccupantAlive(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A11C0
    bool cagesAreAllFull(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1330
    bool iAmImprisoned(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x598DF0
    bool targetIsImprisoned(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1540
    bool targetIsMySlave(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A19F0
    bool iveDitchedAllMyResources(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x997BC0
    bool targetHasBeenLootedOfResources(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x999070
    bool targetHasBeenLooted(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x998F60
    bool usingTurret_Any(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x9965B0
    bool usingTurret_Target(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x996580
    bool strangersAreInMyBuilding(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x60DE60
    bool strangersAreInMyBuilding_andPrivate(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x60DEC0
    bool buildingIsPublic(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x598F00
    bool targetIsUnarmed(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1B10
    bool _targetLooksLikeASlave(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A67E0
    bool carryingExcessLoot(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x59B030
    bool isWorking(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x596D50
    bool gotAFoodItem(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5976A0
    bool iHaveSomeSlaves(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x599960
    Item* getALootableResourceItemFromTargetThatWeHaveStorageFor(Character* target);// public RVA = 0x9971A0
    bool targetLooksLikeASlave(Character* who);// public RVA = 0x5A6430
    bool slaveIsEscaping(Character* who);// public RVA = 0x8544F0
    bool slaveIsFollowingOrders(Character* who);// public RVA = 0x851170
    bool isRunningAway(Character* who, RootObject* from);// public RVA = 0x8511C0
    bool isWearingShackles(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1630
    bool isWearingShackles_locked(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1780
    bool isTargetEscapee(const hand& subject, const Ogre::Vector3& loc);// public RVA = 0x5A1900
    bool isTargetInRangeForOrders(const Ogre::Vector3& location);// public RVA = 0x597010
    bool isTargetInRangeForOrders(RootObject* who);// public RVA = 0x5997B0
    bool isTargetInRangeForHOLDMode_hostiles(Character* who);// public RVA = 0x597EB0
    float getMaxTargetRangeForOrdersSq();// public RVA = 0x596FB0
    float targetMyself(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x597E60
    float findWeapon(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x999A20
    float findSomebodyToLoot(const hand& in, hand& out, bool justAsking);// public RVA = 0x99CED0
    float findAttackerOf(const hand& _of, hand& out, bool justAsking);// public RVA = 0x99AC00
    float findAggressiveFellows(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99A2F0
    bool wantGuardAggressionNeutralTargetCheck(Character* who);// public RVA = 0x99A070
    float findBounty(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99A810
    float findKOIntruder(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99A960
    float findKOIntruder_town(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99AAA0
    float findTurretToUse(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x8CB4C0
    float findTurretToUseOnMyBuilding(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CB7F0
    float findMeleeOpponentForTerritorialAggression(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x59EC20
    float findMeleeOpponentForFightingSlave(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x59E6D0
    float findMeleeOpponentForTerritorialAggressionWithNeutrals(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x59EFA0
    float findMeleeOpponent(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x59F2F0
    float findMeleeOpponentNearMyTown(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x59F5F0
    float findMeleeOpponentFromSquad(const hand& in, hand& out, bool justAsking);// public RVA = 0x792C50
    bool shouldIFreeMySlaveBuddies(Character* slave);// public RVA = 0x9966D0
    float findAllyInNeed(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99B260
    float findAllyInNeed_stayInTown(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99B7D0
    float findSquadmateInNeed(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99BD60
    float findHome(const hand& _a1, hand& _out, bool justAsking);// public RVA = 0x99DBC0
    float findShopkeeperNode(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99D4C0
    float findDefensiveNode(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99D5C0
    float findGuardNodeForBuilding_inOrOut(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99DEA0
    float findGuardNodeForBuilding_indoorOnly(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99DEC0
    float findGuardNodeForBuilding_nearestPlayer(hand& out, bool indoorsOnly);// public RVA = 0x99D620
    float findGuardNodeForTown(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99D9F0
    float findGeneralNode(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x99DAD0
    float findGoodRecruitNode(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x997540
    float findPublicGeneralNodeInTown(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x9982B0
    float findWoundedAllies(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x9A0840
    float findSplintableAllies(const hand& in, hand& out, bool justAsking);// public RVA = 0x99CA90
    float findWoundedAllies_Robots(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x9A0860
    float _findWoundedAllies(hand& out, bool robots);// public RVA = 0x99DEE0
    float findPrisonerFreeToGo(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x8CDC10
    float findPrisonerToLiberate(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x8CD990
    float findPrisonerWithContraband(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x8CDEF0
    float getCurrentBuilding(const hand& in, hand& out, bool justAsking);// public RVA = 0x596B00
    float getDestinationBuilding(const hand& in, hand& out, bool justAsking);// public RVA = 0x5A2270
    float findJammedMachine(const hand& in, hand& out, bool justAsking);// public RVA = 0x59A410
    float findResourceSourceForMe(const hand& in, hand& out, bool justAsking);// public RVA = 0x59D230
    float findResourceDestinationForMe(const hand& in, hand& out, bool justAsking);// public RVA = 0x5A6920
    bool findResourceDestinationFor(const hand& forwhat, hand& out, bool includeMyInventoryContents);// public RVA = 0x5A5220
    float findResourceDestinationForMyLoot(const hand& in, hand& out, bool justAsking);// public RVA = 0x59A8C0
    float findMineToWorkAt(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C94B0
    float findMineToWorkAt_pretend(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C9600
    float findSomethingToDoInHome(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CA450
    float findSomethingToDo_lazy(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C9750
    float findThrone(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CA5A0
    float findBuildingMaterials(const hand& in, hand& out, bool justAsking);// public RVA = 0x5A22E0
    float findTalkTarget(const hand& in, hand& out, bool justAsking);// public RVA = 0x792F00
    float findDisabledAlly(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CBDA0
    hand findDisabledDude(unsigned int flagsAny, unsigned int flagsNot, bool includeBeds);// public RVA = 0x8CBB20
    float findDisabledNonAlly(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CBE10
    float findSomeoneWhoWouldMakeAGoodSlave(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CC550
    float findBadSlaves(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CBE80
    float findNewSlaveOrPrisonerToProcess(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CA960
    float findRandomOneOfMySlaves(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CC190
    float findConsciousSlaveInTown(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CAD00
    float findConsciousSlaveInTownForShipping(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CAE50
    float findConsciousSlaveInTown_unholy(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CFC60
    float findKOedSlaveOfMine(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CC7A0
    float findCorpse_onGround(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CE630
    float findCorpse_onGround_detail(const hand& in, hand& out, bool justAsking, bool carriableOnly, bool edibleOnly);// public RVA = 0x8CC9C0
    float findCorpse_includingCages(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CE350
    float findDeadOrKOBody_onGround(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CCED0
    float findCrops(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CA060
    float findOwnedFreeBed(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CE650
    float findOwnedFreeCage(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CF580
    float findSlaveBuyer(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C91A0
    float findEmptyCageBelongingToMaster(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C9340
    float findOwnedFullCage_MarkForDeath(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CF5E0
    float findCorpseDisposal(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CF8E0
    float findShop(const hand& in, hand& out, bool justAsking);// public RVA = 0x998040
    float findPackageTarget(const hand& in, hand& out, bool justAsking);// public RVA = 0x997560
    float getDestinationGate(const hand& in, hand& out, bool justAsking);// public RVA = 0x5A2160
    float getBuildingToSmash(const hand& in, hand& out, bool justAsking);// public RVA = 0x5A37E0
    float findSomethingToBuild(const hand& in, hand& out, bool justAsking);// public RVA = 0x9978B0
    float findNearestHomeBase(const hand& in, hand& out, bool justAsking);// public RVA = 0x996750
    float findNextTown(const hand& _a1, hand& out, bool justAsking);// public RVA = 0x996890
    float findSomethingToLootFoodFrom(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C9EA0
    float findFoodOnGround(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x999180
    float findLimbOnGround(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x997BF0
    float targetMyLeader(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x597D60
    float targetMySlavemaster(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x59E370
    float targetMyLeader_theRealOne(const hand& oldSubject, hand& out, bool justAsking);// public RVA = 0x597DC0
    float findUnlockedDoorHere(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C9A10
    float findLockedOrClosedDoorHere(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C9BB0
    float findStrangersInMyBuilding(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CD5C0
    float findUnlockedCage(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CAAF0
    float findRandomBuildingInTown(const hand& in, hand& out, bool justAsking);// public RVA = 0x8C9D60
    float findFogmanWorshipTarget(const hand& in, hand& out, bool _a3);// public RVA = 0x8CD0D0
    float findAnimalsToLoot(const hand& in, hand& out, bool justAsking);// public RVA = 0x8CCBF0
    float findAllyAnimalWithFoodInMouth(const hand& in, hand& out, bool justAsking);// public RVA = 0x999590
    Character* findBodyWithResourceToLoot(GameData* resourceNeeded, bool animalsOnly);// public RVA = 0x8CCD70
    UseableStuff* _findOwnedCageThing(bool wantEmpty, BuildingFunction whatType);// public RVA = 0x8CEFC0
    // no_addr class hand chooseNewHome();// public
    hand findNode(NodeType t, bool forHomeBuildingOnly, bool indoorsOnly);// public RVA = 0x99D170
    bool itemOnGroundStealingCheckIsSafe(Item* item);// public RVA = 0x9965D0
    Character* findSomeoneToLoot(bool wantAWeapon);// public RVA = 0x999660
    void getAllLocalMachines(lektor<Building*>& out, unsigned int buildingFunctions);// public RVA = 0x8CA6F0
    StorageBuilding* findResourceStorageBulidingFor(GameData* needed, StorageBuilding* skip);// public RVA = 0x59A550
    virtual float rateWeapon(Item* item);// public RVA = 0x996530 vtable offset = 0x60
    float _NV_rateWeapon(Item* item);// public RVA = 0x996530 vtable offset = 0x60
    virtual bool canUseWeapon(Item* item) const;// public RVA = 0x997A20 vtable offset = 0x68
    bool _NV_canUseWeapon(Item* item) const;// public RVA = 0x997A20 vtable offset = 0x68
    float scoreTargetRange(float range);// public RVA = 0x5998B0
    float scoreDistanceTo(RootObject* target, bool holdPositionMode);// public RVA = 0x9973E0
    float scoreSplint(const hand& _subject, const Ogre::Vector3& _a2);// public RVA = 0x99C490
    float scoreFirstAid(const hand& _subject, const Ogre::Vector3& _a2);// public RVA = 0x99C8F0
    float scoreFixMyLegs(const hand& _subject, const Ogre::Vector3& v);// public RVA = 0x996C00
    float scoreFirstAidRobot(const hand& _subject, const Ogre::Vector3& _a2);// public RVA = 0x99C760
    float scorePutCarriedDudeDown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59FF90
    float scoreJobMedic(const hand& _subject, const Ogre::Vector3& _a2);// public RVA = 0x996C60
    float scorePutCarriedDudeInBed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A05D0
    float scorePutCarriedDudeInCage(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A09C0
    // no_addr float scorePutCarriedBountyInCage(const class hand & _a1, const class Ogre::Vector3 & _a2);// public missing arg names
    float scoreCarryingIntruder(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A0C20
    float scoreFindAndRescue(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598D00
    float scoreFindAndRescueIfTheresBeds(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598D40
    float scoreRescueLeader(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598C70
    float scoreFindAndKidnap(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599E80
    float scoreKidnapperCageJob(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A0B00
    float scoreShopping(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x997E70
    virtual float scoreProtectAllies(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599410 vtable offset = 0x70
    float _NV_scoreProtectAllies(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599410 vtable offset = 0x70
    virtual float scoreStayClose(const hand& subject, const Ogre::Vector3& p);// public RVA = 0x5A2C70 vtable offset = 0x78
    float _NV_scoreStayClose(const hand& subject, const Ogre::Vector3& p);// public RVA = 0x5A2C70 vtable offset = 0x78
    virtual float scoreStayCloseIsh(const hand& subject, const Ogre::Vector3& p);// public RVA = 0x597180 vtable offset = 0x80
    float _NV_scoreStayCloseIsh(const hand& subject, const Ogre::Vector3& p);// public RVA = 0x597180 vtable offset = 0x80
    float scorePutDudeInCage(const hand& who);// public RVA = 0x5A0790
    virtual float scoreUnderAttack(const hand& in, const Ogre::Vector3& _a2);// public RVA = 0x5995A0 vtable offset = 0x88
    float _NV_scoreUnderAttack(const hand& in, const Ogre::Vector3& _a2);// public RVA = 0x5995A0 vtable offset = 0x88
    virtual float scoreEmptyMachine(const hand& in, const Ogre::Vector3& _a2);// public RVA = 0x5A68D0 vtable offset = 0x90
    float _NV_scoreEmptyMachine(const hand& in, const Ogre::Vector3& _a2);// public RVA = 0x5A68D0 vtable offset = 0x90
    virtual float scoreNone(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640DD0 vtable offset = 0x98
    float _NV_scoreNone(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640DD0 vtable offset = 0x98
    virtual float scoreCannibalKill(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x32E500 vtable offset = 0xA0
    float _NV_scoreCannibalKill(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x32E500 vtable offset = 0xA0
    virtual float scoreAutoMachinery(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59D780 vtable offset = 0xA8
    float _NV_scoreAutoMachinery(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59D780 vtable offset = 0xA8
    virtual float scoreCollectOutputResource(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A60E0 vtable offset = 0xB0
    float _NV_scoreCollectOutputResource(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A60E0 vtable offset = 0xB0
    virtual float scoreCollectOutputResourceForBuildMats(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599990 vtable offset = 0xB8
    float _NV_scoreCollectOutputResourceForBuildMats(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599990 vtable offset = 0xB8
    virtual float scoreGetFood_inHomeTown(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x59B450 vtable offset = 0xC0
    float _NV_scoreGetFood_inHomeTown(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x59B450 vtable offset = 0xC0
    virtual float scoreFindFoodOnGround(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5975B0 vtable offset = 0xC8
    float _NV_scoreFindFoodOnGround(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5975B0 vtable offset = 0xC8
    virtual float scoreGetFood_inHomeTown_andFeedAnimals(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x597530 vtable offset = 0xD0
    float _NV_scoreGetFood_inHomeTown_andFeedAnimals(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x597530 vtable offset = 0xD0
    virtual float scoreUnlockDoorHere(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598980 vtable offset = 0xD8
    float _NV_scoreUnlockDoorHere(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598980 vtable offset = 0xD8
    virtual float scoreGetOutOfBed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A03D0 vtable offset = 0xE0
    float _NV_scoreGetOutOfBed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A03D0 vtable offset = 0xE0
    virtual float scoreGetOutOfBedOnceFullyHealed(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5989E0 vtable offset = 0xE8
    float _NV_scoreGetOutOfBedOnceFullyHealed(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5989E0 vtable offset = 0xE8
    virtual float scoreGoToBed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A0100 vtable offset = 0xF0
    float _NV_scoreGoToBed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A0100 vtable offset = 0xF0
    virtual float scoreHomeIsNotLockedUp(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x794D20 vtable offset = 0xF8
    float _NV_scoreHomeIsNotLockedUp(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x794D20 vtable offset = 0xF8
    virtual float scoreDontLeaveTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5982C0 vtable offset = 0x100
    float _NV_scoreDontLeaveTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5982C0 vtable offset = 0x100
    virtual float scoreFoundCages(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598310 vtable offset = 0x108
    float _NV_scoreFoundCages(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598310 vtable offset = 0x108
    virtual float scoreHasWorkingArm(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x599AE0 vtable offset = 0x110
    float _NV_scoreHasWorkingArm(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x599AE0 vtable offset = 0x110
    virtual float scoreUseTurret(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597900 vtable offset = 0x118
    float _NV_scoreUseTurret(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597900 vtable offset = 0x118
    virtual float scoreAggressiveAction(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x79BF40 vtable offset = 0x120
    float _NV_scoreAggressiveAction(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x79BF40 vtable offset = 0x120
    virtual float scoreBashGate(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x598B70 vtable offset = 0x128
    float _NV_scoreBashGate(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x598B70 vtable offset = 0x128
    virtual float scoreNPCEscapeCageOpportunity(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598AE0 vtable offset = 0x130
    float _NV_scoreNPCEscapeCageOpportunity(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598AE0 vtable offset = 0x130
    virtual float score01(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640DE0 vtable offset = 0x138
    float _NV_score01(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640DE0 vtable offset = 0x138
    virtual float score025(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640DF0 vtable offset = 0x140
    float _NV_score025(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640DF0 vtable offset = 0x140
    virtual float score05(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E00 vtable offset = 0x148
    float _NV_score05(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E00 vtable offset = 0x148
    virtual float score08(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E10 vtable offset = 0x150
    float _NV_score08(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E10 vtable offset = 0x150
    virtual float score10(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E20 vtable offset = 0x158
    float _NV_score10(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E20 vtable offset = 0x158
    virtual float scoreCanSeeTarget(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598A40 vtable offset = 0x160
    float _NV_scoreCanSeeTarget(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598A40 vtable offset = 0x160
    virtual float score12(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E30 vtable offset = 0x168
    float _NV_score12(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E30 vtable offset = 0x168
    virtual float score15(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E40 vtable offset = 0x170
    float _NV_score15(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E40 vtable offset = 0x170
    virtual float score20(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E50 vtable offset = 0x178
    float _NV_score20(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E50 vtable offset = 0x178
    virtual float scoreRandomFluff(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E60 vtable offset = 0x180
    float _NV_scoreRandomFluff(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E60 vtable offset = 0x180
    virtual float scoreHuntingBlood(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x793900 vtable offset = 0x188
    float _NV_scoreHuntingBlood(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x793900 vtable offset = 0x188
    virtual float scoreHuntingEggs(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x793A80 vtable offset = 0x190
    float _NV_scoreHuntingEggs(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x793A80 vtable offset = 0x190
    virtual float scoreTargetInDanger(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597870 vtable offset = 0x198
    float _NV_scoreTargetInDanger(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597870 vtable offset = 0x198
    virtual float scoreAttackEnemies(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5978A0 vtable offset = 0x1A0
    float _NV_scoreAttackEnemies(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5978A0 vtable offset = 0x1A0
    virtual float scoreMeleeAttack(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A3AE0 vtable offset = 0x1A8
    float _NV_scoreMeleeAttack(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5A3AE0 vtable offset = 0x1A8
    virtual float scoreRangedAttack(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597AE0 vtable offset = 0x1B0
    float _NV_scoreRangedAttack(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597AE0 vtable offset = 0x1B0
    virtual float scoreRunAway(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A2D60 vtable offset = 0x1B8
    float _NV_scoreRunAway(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A2D60 vtable offset = 0x1B8
    virtual float scoreRetreat(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A2F90 vtable offset = 0x1C0
    float _NV_scoreRetreat(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x5A2F90 vtable offset = 0x1C0
    virtual float scoreMove(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597C70 vtable offset = 0x1C8
    float _NV_scoreMove(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597C70 vtable offset = 0x1C8
    virtual float scoreDontWantToBeUnarmed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E90 vtable offset = 0x1D0
    float _NV_scoreDontWantToBeUnarmed(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x640E90 vtable offset = 0x1D0
    virtual float scoreLiftObject(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59DA20 vtable offset = 0x1D8
    float _NV_scoreLiftObject(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59DA20 vtable offset = 0x1D8
    virtual float scoreLiftIntruder(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5977A0 vtable offset = 0x1E0
    float _NV_scoreLiftIntruder(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5977A0 vtable offset = 0x1E0
    virtual float scoreChainNewSlave(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5973A0 vtable offset = 0x1E8
    float _NV_scoreChainNewSlave(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5973A0 vtable offset = 0x1E8
    virtual float scoreNotDown(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x597360 vtable offset = 0x1F0
    float _NV_scoreNotDown(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x597360 vtable offset = 0x1F0
    virtual float scoreNoMoreThan4Slaves(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59B1C0 vtable offset = 0x1F8
    float _NV_scoreNoMoreThan4Slaves(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x59B1C0 vtable offset = 0x1F8
    virtual float scoreSlaveExportTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597400 vtable offset = 0x200
    float _NV_scoreSlaveExportTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x597400 vtable offset = 0x200
    virtual float scoreHasSomeSlaves(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599920 vtable offset = 0x208
    float _NV_scoreHasSomeSlaves(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599920 vtable offset = 0x208
    virtual float scoreHasSomeSlavesAndAtImportTown(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5974F0 vtable offset = 0x210
    float _NV_scoreHasSomeSlavesAndAtImportTown(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5974F0 vtable offset = 0x210
    virtual float scoreAmTheRealLeader(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5974A0 vtable offset = 0x218
    float _NV_scoreAmTheRealLeader(const hand& subject, const Ogre::Vector3& v);// public RVA = 0x5974A0 vtable offset = 0x218
    virtual float scoreAtAttackableTown(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x5972A0 vtable offset = 0x220 missing arg names
    float _NV_scoreAtAttackableTown(const hand& _a1, const Ogre::Vector3& _a2);// public RVA = 0x5972A0 vtable offset = 0x220 missing arg names
    virtual float scoreDogPlaying(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598FA0 vtable offset = 0x228
    float _NV_scoreDogPlaying(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x598FA0 vtable offset = 0x228
    virtual float scoreDogPlayingChase(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599080 vtable offset = 0x230
    float _NV_scoreDogPlayingChase(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599080 vtable offset = 0x230
    virtual float scoreHomeIsPrivate(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599130 vtable offset = 0x238
    float _NV_scoreHomeIsPrivate(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599130 vtable offset = 0x238
    virtual float scoreNotKOOrPlayingDead(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x7913F0 vtable offset = 0x240
    float _NV_scoreNotKOOrPlayingDead(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x7913F0 vtable offset = 0x240
    virtual float scoreTargetInMyTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599180 vtable offset = 0x248
    float _NV_scoreTargetInMyTown(const hand& subject, const Ogre::Vector3& _a2);// public RVA = 0x599180 vtable offset = 0x248
    // no_addr class AI & operator=(const class AI & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};