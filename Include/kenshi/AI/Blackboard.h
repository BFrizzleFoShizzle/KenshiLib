#pragma once

#include <kenshi/util/OgreUnordered.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/hand.h>
#include "AI.h"
#include "AITaskSystem.h"

class AIPackage;
class GameData;
class Ownerships;
class Tasker;
class DatapanelGUI;
class TaskRepertoire;
class ZoneMap;

enum BlackboardSignalFunctions
{
    SIGNAL_NONE,
    SIG_RETREAT_CANNIBAL_RAID,
    SIG_AT_SAFE_TOWN,
    SIG_AT_HOME_TOWN,
    SIG_CANNIBAL_START_PATROL,
    SIG_SQUAD_NOT_INTACT,
    SIG_START_PATROL,
    SIG_DIPLOMAT_MISSION,
    SIG_DEFEAT_SQUAD,
    SIG_HOME_OWNER_KEEP_LOCKED,
    SIG_GATHER_UP_ALL_LOCAL_PRISONERS,
    SIG_SLAVER_SHIP_TO_WORKCAMPS,
    SIG_BODYGUARD,
    SIG_BECOME_EX_SLAVE,
    SIG_OUT_OF_DANGER,
    SIG_DEFEND_PLAYER_TOWN_TIMED,
    SIG_WANDERING_TOWN_TO_TOWN,
    SIG_HANG_OUT_AT_BAR,
    SIG_RAIDING_WEAK_VILLAGES,
    WAR_GATHER_FORCES,
    WAR_ASSAULT_TOWN,
    WAR_BATTLE_MEETING,
    SIG_REFUGEE_DISBAND,
    SIG_START_PATROL_RUNNING,
    SIG_GATHER_UP_ALL_LOCAL_PRISONERS_UNHOLY,
    SIG_RETREAT_CANNIBAL_RAID_TO_NEAREST_NEST,
    SIG_HANG_OUT_OUTDOORS_ONLY,
    SIG_CANNIBALS_AT_HOME,
    SIG_SLAVER_SHIP_TO_ANYWHERE_CLOSE,
    SIG_PASSING_BY_TOWN_ASSAULT,
    SIG_OCCUPY_CONQUERED_TOWN,
    SIG_DEFEND_PLAYER_TOWN_CAMPAIGN,
    WAR_ASSAULT_TOWN_CANNIBAL,
    SIG_TIMED_CONTRACT
};

class Blackboard : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    ogre_unordered_map<int, lektor<AIPackage*>>::type packagesMain; // 0x8 Member
    AIPackage* currentPackage; // 0x48 Member
    int currentPackagePriorityLevel; // 0x50 Member
    std::string replacementAIPackageSID; // 0x58 Member
    AIPackage* createNewPackage(BlackboardSignalFunctions key, GameData* data, int priority, const hand& giver);// private RVA = 0x2856F0
    void _setContractJob(GameData* package, int hours, const hand& giver);// private RVA = 0x271D90
    void _addPackage(GameData* package, int type);// private RVA = 0x26BCB0
    void clearAllPackages();// private RVA = 0x26B730
    void _activateCurrentPackage(AIPackage* package);// private RVA = 0x271CF0
    void _addFromData(GameData* data);// private RVA = 0x2703A0
    AIPackage* getPackage(const std::string& sid);// private RVA = 0x27E8B0
    lektor<AIPackage*>* getPackageList(int type);// private RVA = 0x284B20
    bool periodicPackageCheck(int type, float frameTime);// private RVA = 0x2720C0
    static void resetAllTheStaticData();// public RVA = 0x285410
    void dialogEventsCheck(GameData* line, const hand& target);// public RVA = 0x272E80
    void setContractJob(GameData* packageCollection, const hand& giver);// public RVA = 0x272290
    void endContractJob();// public RVA = 0x269C60
    bool isMissionComplete();// public RVA = 0x9A5B10
    hand cageMarkedForDeath; // 0x80 Member
    bool isTargetMarkedForDeath(Building* cage, TownBase* t);// public RVA = 0x32E690
    // no_addr void Blackboard(const class Blackboard & _a1);// public missing arg names
    Blackboard(Platoon* owner);// public RVA = 0x26B840
    Blackboard* _CONSTRUCTOR(Platoon* owner);// public RVA = 0x26B840
    ~Blackboard();// public RVA = 0x26BB40
    void _DESTRUCTOR();// public RVA = 0x26BB40
    Platoon* squad; // 0xA0 Member
    void update(float frameTime);// public RVA = 0x269E70
    void periodicUpdate(float frameTime);// public RVA = 0x272E00
    void addPackages(GameData* packageCollection);// public RVA = 0x271170
    void addFallbackPackages(GameData* packageCollection_faction);// public RVA = 0x271B20
    void replaceAIPackage(GameData* package);// public RVA = 0x271F80
    std::string getCurrentAIPackageName() const;// public RVA = 0x269430
    void getCurrentAIPackageGUIData(DatapanelGUI* panel, int cat);// public RVA = 0x26A070
    void assessNeutral(Character* who);// public RVA = 0x850590
    bool assessEnemy(Character* who);// public RVA = 0x8505B0
    AIPackage* getCurrentPackage();// public RVA = 0x287290
    const Ogre::Vector3& getFormationPositionOffset(Character* character);// public RVA = 0x26FF40
    void nodifyFormationUpdate();// public RVA = 0x4A70F0
    Ownerships* getOwnerships();// public RVA = 0x268550
    void notifyGoalStart(Tasker* t, const hand& me);// public RVA = 0x2699E0
    void notifyGoalEnd(const hand& me);// public RVA = 0x269A80
    void notifySubTarget(const hand& me, const hand& target);// public RVA = 0x269AC0
    int howManyGuysDoingThisGoal(Tasker* t, const hand& me) const;// public RVA = 0x268A80
    int howManyGuysWorkingOnThisSubTarget(Tasker* t, const hand& me, const hand& subtarget) const;// public RVA = 0x268B60
    int howManyGuysWorkingOnThisSubTarget(const hand& me, const hand& subtarget) const;// public RVA = 0x268C30
    bool isMySubTarget(Tasker* t, const hand& me, const hand& subtarget) const;// public RVA = 0x268CE0
    void getSubTarget(const hand& me, hand& subtarget);// public RVA = 0x269B00
    // no_addr float getSubTargetMultiplier(const class hand & _a1, const class hand & _a2, float _a3);// public missing arg names
    void addRequest(const hand& from, const hand& to, TaskType key, const hand& subject, taskPriority pri, float weight);// public RVA = 0x269B40
    void removeRequest(const hand& from);// public RVA = 0x269C40
    void getRequests(lektor<Tasker*>& out, taskPriority pri, const hand& whoFor, TaskRepertoire* aiImp);// public RVA = 0x268D90
    void notifyJobCompleted(TaskType key, const hand& subj, const hand& me);// public RVA = 0x2683B0
    // no_addr void removeLeaderJob(enum TaskType _a1);// public missing arg names
    void addSquadJob(SquadMemberType type, TaskType key, const hand& subject, taskPriority pri, float weight, TaskTargetType targeting, TaskEndEvent ending, int startTime, int endTime);// public RVA = 0x268960
    void getSquadJobs(SquadMemberType type, lektor<Tasker*>& out, unsigned int priorityFlag, const hand& who, TaskRepertoire* aiImp);// public RVA = 0x26B2E0
    UnloadedPlatoonJob getUnloadedPlatoonJob() const;// public RVA = 0x268390
    // no_addr void clearJobs(enum SquadMemberType _a1);// public missing arg names
    void clearAllTheJobs();// public RVA = 0x278CB0
    void serialise(GameData* state);// public RVA = 0x26BE20
    void load(GameData* state);// public RVA = 0x272770
    ogre_unordered_map<TaskType, hand>::type actionTargets; // 0xA8 Member
    bool homeIsLockedUp; // 0xE8 Member
    TownBase* targetTown; // 0xF0 Member
    ZoneMap* targetZoneHunting; // 0xF8 Member
    void stateUpdate(float frameTime);// public RVA = 0x268420
    void notifyMissionTargetPathfindImpossible(Character* forWho, const hand& target);// public RVA = 0x268570
    TargetInfo getMissionTarget(Character* who);// public RVA = 0x2696B0
    hand getMissionTown(bool getHometownAsFallback);// public RVA = 0x269820
    hand getMissionGiver();// public RVA = 0x278CE0
    GameData* missionData; // 0x100 Member
    TownBase* getCurrentTownLocation();// public RVA = 0x2683C0
    float getTimeSpentInTown_inGameHours();// public RVA = 0x2683E0
    bool moraleIsBroken; // 0x108 Member
    void setMyHomeIsLocked(bool on);// public RVA = 0x792140
    bool getMyHomeIsLocked() const;// public RVA = 0x335940
    // no_addr int getNumConsciousCharacters();// public
    hand getHomeGate();// public RVA = 0x26AF60
    bool hasContractJob() const;// public RVA = 0x6323C0
    TimeOfDay getContractExpiryTime() const;// public RVA = 0x2868F0
    void contractJobNotifyBetrayal(Character* myWitness, Character* betrayer);// public RVA = 0x8505D0
    bool contractJobWasBetrayal();// public RVA = 0x850600
    virtual void showEndedMessage();// public RVA = 0x284B50 vtable offset = 0x0
    void _NV_showEndedMessage();// public RVA = 0x284B50 vtable offset = 0x0
    hand _homeGateTarget; // 0x110 Member
    bool _flagCleared; // 0x130 Member
    bool needsStateUpdate; // 0x131 Member
    TownBase* currentTownLocation; // 0x138 Member
    TimeOfDay townArrivalTime; // 0x140 Member
    int HIGHEST_PRIORITY_LEVEL; // 0x148 Member
    void _serialiseJobList(GameData* state, const lektor<TaskRequest>& theList, const std::string& name);// private RVA = 0x26C750
    void _loadJobList(GameData* state, lektor<TaskRequest>& theList, const std::string& name);// private RVA = 0x26CEE0
    void _setupJobFromData(GameData* data, const std::string& listname, SquadMemberType listEnum);// private RVA = 0x270030
    void countCharacters();// private RVA = 0x2685D0
    void runAwayCheck();// private RVA = 0x2694A0
    void runAway();// private RVA = 0x268E70
    bool runningAwayMode; // 0x14C Member
    int characterCount; // 0x150 Member
    int enemyCount; // 0x154 Member
    ogre_unordered_map<hand, TaskRequest>::type requests; // 0x158 Member
    lektor<TaskRequest> leaderJobs; // 0x198 Member
    lektor<TaskRequest> squadJobs; // 0x1B0 Member
    lektor<TaskRequest> squadJobs2; // 0x1C8 Member
    lektor<TaskRequest> signalJobs; // 0x1E0 Member
    lektor<TaskRequest> slaveJobs; // 0x1F8 Member
    AIPackage* contractJob; // 0x210 Member
    TimeOfDay contractExpiryTime; // 0x218 Member
    lektor<TaskRequest>* getJobList(SquadMemberType type);// private RVA = 0x268170
    // no_addr const class lektor<TaskRequest> * getJobList(enum SquadMemberType _a1);// private missing arg names
    class TaskInfo
    {
    public:
        // no_addr void TaskInfo(const class Blackboard::TaskInfo & _a1);// public missing arg names
        // no_addr void TaskInfo(enum TaskType _a1, const class hand & _a2);// public missing arg names
        TaskInfo();// public RVA = 0x2681D0
        TaskInfo* _CONSTRUCTOR();// public RVA = 0x2681D0
        TaskType type; // 0x0 Member
        hand subject; // 0x8 Member
        hand subTarget; // 0x28 Member
        Blackboard::TaskInfo& operator=(const Blackboard::TaskInfo& __that);// public RVA = 0x2682E0
    };
    ogre_unordered_map<hand, Blackboard::TaskInfo>::type currentTasks; // 0x220 Member
    void buildFormation();// private RVA = 0x26D680
    void getGridPositions(Ogre::vector<Ogre::Vector3>::type& positions, int gridWidth, int gridHeight, int size, float initialX, float radius, float spacingX, float spacingZ);// private RVA = 0x2694B0
    bool formationNeedUpdate; // 0x260 Member
    ogre_unordered_map<hand, Ogre::Vector3>::type characterFormationPosition; // 0x268 Member
    // no_addr class Blackboard & operator=(const class Blackboard & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};