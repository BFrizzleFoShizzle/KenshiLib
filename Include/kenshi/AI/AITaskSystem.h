#pragma once

#include <kenshi/util/hand.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/TimeOfDay.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/Enums.h>
#include <ogre/OgreVector3.h>

class Character;
class AI;
class GameData;
class Tasker;

// TODO move?
enum TaskTargetType
{
    TARGET_SPECIFIC,
    TARGET_SELF,
    TARGET_LEADER,
    TARGET_SQUAD_MISSION,
    TARGET_HOME_GATE
};

class TaskData;

// TODO move?
class TaskMatch
{
public:
    const TaskData* taskData; // 0x0 Member
    TaskMatch(const TaskMatch& __that);// public RVA = 0x61A4D0
    TaskMatch* _CONSTRUCTOR(const TaskMatch& __that);// public RVA = 0x61A4D0
    TaskMatch(Tasker* k);// public RVA = 0x513840
    TaskMatch* _CONSTRUCTOR(Tasker* k);// public RVA = 0x513840
    TaskMatch(const TaskData* k, const hand& s, const hand& sub);// public RVA = 0x50A180
    TaskMatch* _CONSTRUCTOR(const TaskData* k, const hand& s, const hand& sub);// public RVA = 0x50A180
    TaskMatch();// public RVA = 0x506440
    TaskMatch* _CONSTRUCTOR();// public RVA = 0x506440
    hand subject; // 0x8 Member
    hand subtarget; // 0x28 Member
    const TaskData* getTaskData() const;// public RVA = 0x50BD30
    TaskType key() const;// public RVA = 0x2680F0
    // no_addr class TaskMatch & operator=(const class TaskMatch & _a1);// public missing arg names
    TaskMatch& operator=(Tasker* in);// public RVA = 0x5138B0
    TaskMatch& operator=(int _a1);// public RVA = 0x50A950 missing arg names
    void reset();// public RVA = 0x50A200
    bool operator==(const Tasker* a) const;// public RVA = 0x513950
    bool operator!=(const Tasker* a) const;// public RVA = 0x513960
    bool sameAs(const Tasker* t) const;// public RVA = 0x506480
    bool operator<(const TaskMatch& t) const;// public RVA = 0x50BD40
    operator bool() const;// public RVA = 0x506530
};

class TaskRepertoire;

// TODO move?
class ActionDeque
{
public:
    // VTable         : (none)
    // no_addr void ActionDeque(const class ActionDeque & _a1);// public missing arg names
    ActionDeque();// public RVA = 0x50B570
    ActionDeque* _CONSTRUCTOR();// public RVA = 0x50B570
    virtual ~ActionDeque();// public RVA = 0x50B5B0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x50B5B0 vtable offset = 0x0
    std::deque<Tasker*, std::allocator<Tasker*> > list; // 0x8 Member
    const Tasker* getFirstTask() const;// public RVA = 0x50B290
    Tasker* getFirstTask();// public RVA = 0x50B630
    Tasker* getSecondTask() const;// public RVA = 0x518490
    // no_addr class Tasker * getTaskBeforeLast();// public
    Tasker* getLastTask() const;// public RVA = 0x50B310
    bool hasTask(TaskMatch t);// public RVA = 0x50B6B0
    void insertTask(Tasker* task);// public RVA = 0x50B3A0
    void addTask(Tasker* task);// public RVA = 0x50B3D0
    void clearAndDelete();// public RVA = 0x50CA30
    void clearOnly();// public RVA = 0x518F90
    Tasker* passOnCurrentTask();// public RVA = 0x518520
    bool isEmpty() const;// public RVA = 0x50A230
    bool isOnlyOne() const;// public RVA = 0x50A240
    // no_addr class ActionDeque & operator=(const class ActionDeque & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class OrdersReceiver : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    Character* me; // 0x8 Member
    // no_addr void OrdersReceiver(const class OrdersReceiver & _a1);// public missing arg names
    OrdersReceiver(AI* _ai, Character* c);// public RVA = 0x5075A0
    OrdersReceiver* _CONSTRUCTOR(AI* _ai, Character* c);// public RVA = 0x5075A0
    virtual ~OrdersReceiver();// public RVA = 0x5077A0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x5077A0 vtable offset = 0x0
    virtual void serialise(GameData* data);// public RVA = 0x508430 vtable offset = 0x8
    void _NV_serialise(GameData* data);// public RVA = 0x508430 vtable offset = 0x8
    virtual void loadFromSerialise(GameData* data);// public RVA = 0x508690 vtable offset = 0x10
    void _NV_loadFromSerialise(GameData* data);// public RVA = 0x508690 vtable offset = 0x10
    hand mainGoalTarget; // 0x10 Member
    enum AggroType
    {
        AI_AGGRESSIVE,
        AI_DEFENSIVE,
        AI_EVASIVE
    };

    OrdersReceiver::AggroType aggroMode; // 0x30 Member
    bool superDefenseMode; // 0x34 Member
    Tasker* _forceOrderInsert(TaskType t);// public RVA = 0x507310
    void addOrder(TaskType t, const hand& subject, const Ogre::Vector3& location, bool clearOld, bool shift);// public RVA = 0x507C00
    void addJob(TaskType t, const hand& subject, const Ogre::Vector3& location, bool shift);// public RVA = 0x507F50
    void removeJob(TaskType typ);// public RVA = 0x506910
    void removePermajob(int typ);// public RVA = 0x506B80
    void movePermajob(int taskIdx, int targetIdx);// public RVA = 0x507120
    void clearPermajobs();// public RVA = 0x506B00
    const std::string& getPermajobName(int slot) const;// public RVA = 0x506A10
    TaskType getPermajob(int slot) const;// public RVA = 0x506A50
    const Tasker* getPermajobData(int slot) const;// public RVA = 0x506AD0
    int getPermajobCount() const;// public RVA = 0x506AF0
    bool hasPermajob(TaskType t) const;// public RVA = 0x506A80
    void addGoal(Tasker* task);// public RVA = 0x5071D0
    void removeGoal(TaskType task);// public RVA = 0x506C10
    bool hasGoal(TaskType task);// public RVA = 0x506CC0
    void updateLastOrder(TaskType t, const hand& subject, const Ogre::Vector3& location);// public RVA = 0x508210
    virtual void setNeedGOAP();// public RVA = 0x506570 vtable offset = 0x18
    void _NV_setNeedGOAP();// public RVA = 0x506570 vtable offset = 0x18
    Tasker* getFirstOrder();// public RVA = 0x507590
    void clearOrders();// public RVA = 0x506D20
    void clearJobs();// public RVA = 0x506DB0
    void _clearGoals();// public RVA = 0x50A250
    const TaskMatch& getCurrentGoal() const;// public RVA = 0x268230
    virtual void setHoldPositionOrders(Tasker* t);// public RVA = 0x50B8B0 vtable offset = 0x20
    void _NV_setHoldPositionOrders(Tasker* t);// public RVA = 0x50B8B0 vtable offset = 0x20
    bool hasPlayerOrders() const;// public RVA = 0x5073F0
    bool hasPlayerOrder(TaskType key) const;// public RVA = 0x507490
    bool isInChoosingGoalMode() const;// public RVA = 0x7BF370
    bool hasOrders() const;// public RVA = 0x68EB40
    class TaskRequestSimple
    {
    public:
        TaskType key; // 0x0 Member
        hand subject; // 0x8 Member
        TaskTargetType targeting; // 0x28 Member
        bool sameAs(Tasker* t) const;// public RVA = 0x268240
        // no_addr void TaskRequestSimple(const class OrdersReceiver::TaskRequestSimple & _a1);// public missing arg names
        // no_addr void TaskRequestSimple();// public
        // no_addr class OrdersReceiver::TaskRequestSimple & operator=(const class OrdersReceiver::TaskRequestSimple & _a1);// public missing arg names
    };
    void getSlaveJobs(lektor<Tasker*>& out, TaskRepertoire* aiImp, const hand& who);// public RVA = 0x26B080
    void clearSlaveJobs();// public RVA = 0x4ABC40
    // no_addr void addSlaveJob(const class OrdersReceiver::TaskRequestSimple & _a1);// public missing arg names
    bool isJobsEnabled() const;// public RVA = 0x50BE80
    void setJobsEnabled(bool on);// public RVA = 0x507A90
    bool doJobsEnabled; // 0x35 Member
    ActionDeque orders; // 0x38 Member
    lektor<Tasker*> jobs; // 0x70 Member
    lektor<Tasker*> permajobs; // 0x88 Member
    lektor<Tasker*> goals[0x5]; // 0xA0 Member
    lektor<Tasker*> squadAIPackage[0x5]; // 0x118 Member
    Tasker* holdPositionOrders; // 0x190 Member
    lektor<OrdersReceiver::TaskRequestSimple*> slaveJobs; // 0x198 Member
    bool needGOAP; // 0x1B0 Member
    bool choosingGoalMode; // 0x1B1 Member
    AI* aiImplementation; // 0x1B8 Member
    void clearCurrentGoal(bool force);// protected RVA = 0x50C640
    TaskMatch currentGoal; // 0x1C0 Member
    float currentGoalScore; // 0x208 Member
    taskPriority currentGoalPriority; // 0x20C Member
    Tasker* tryToGetCurrentGoal();// protected RVA = 0x50C470
    // no_addr class OrdersReceiver & operator=(const class OrdersReceiver & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class CharBody;
class DatapanelGUI;
class StateBroadcastData;

class AITaskSytem : public OrdersReceiver
{
public:
    // OrdersReceiver offset = 0x0, length = 0x210
    double infrequentTimeStamp; // 0x210 Member
    bool canIDoTheInfrequents();// private RVA = 0x50C630
    void infrequentsStampCheck();// private RVA = 0x50C6D0
    void currentActionChecks();// private RVA = 0x50D1F0
    void _logTheAI();// private RVA = 0x50C0C0
    ogre_unordered_map<hand, float>::type pathFailures; // 0x218 Member
    // no_addr void AITaskSytem(const class AITaskSytem & _a1);// public missing arg names
    AITaskSytem(AI* _imp, CharBody* bod, Character* me);// public RVA = 0x50D3F0
    AITaskSytem* _CONSTRUCTOR(AI* _imp, CharBody* bod, Character* me);// public RVA = 0x50D3F0
    virtual ~AITaskSytem();// public RVA = 0x50D600 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x50D600 vtable offset = 0x0
    virtual void serialise(GameData* data) override;// public RVA = 0x508930 vtable offset = 0x0
    void _NV_serialise(GameData* data);// public RVA = 0x508930 vtable offset = 0x0
    virtual void loadFromSerialise(GameData* data) override;// public RVA = 0x508B50 vtable offset = 0x0
    void _NV_loadFromSerialise(GameData* data);// public RVA = 0x508B50 vtable offset = 0x0
    bool _debugBreak; // 0x258 Member
    SquadMemberType _squadMemberType; // 0x25C Member
    hand getHandle() const;// public RVA = 0x50A300
    void notifyPathImpossible(const hand& target, const Ogre::Vector3& dest);// public RVA = 0x795C70
    bool isPathImpossible(const hand& target);// public RVA = 0x5AFB10
    void update(Ogre::Vector3 position, float time);// public RVA = 0x50D1A0
    void update4Frame(Ogre::Vector3 position, float time);// public RVA = 0x50E930
    void periodicUpdate(float time);// public RVA = 0x5109B0
    void taskImpossible();// public RVA = 0x50C110
    void _notifyBodyTaskComplete();// public RVA = 0x50BFB0
    void _forcedSetCurrentAction(Tasker* t, float score);// public RVA = 0x5C5E30
    void setTaskExpiryTimer();// public RVA = 0x50C9B0
    bool isGoalExpired();// public RVA = 0x50BFC0
    bool isTaskExpired();// public RVA = 0x50BFE0
    float getGOalExpiryTimeRemaining();// public RVA = 0x50C000
    bool tryAndRerunGOAP(Tasker* theRerun);// public RVA = 0x50FD50
    virtual void setCurrentGoal(Tasker* t, float score, taskPriority pri);// public RVA = 0x50C370 vtable offset = 0x28
    void _NV_setCurrentGoal(Tasker* t, float score, taskPriority pri);// public RVA = 0x50C370 vtable offset = 0x28
    void callForUpdate(bool superUrgent);// public RVA = 0x7908E0
    void getGUIData(DatapanelGUI* datapanel);// public RVA = 0x790F90
    std::string getCurrentGoalString();// public RVA = 0x50EC40
    int debugCount; // 0x260 Member
    bool intendsToAttackTarget(Character* who) const;// public RVA = 0x5C8B50
    void updateStateBroadcast(StateBroadcastData* stateBroadcast);// public RVA = 0x50E5E0
    void clearAllTasks();// public RVA = 0x4A6DF0
    void debugTargetInfo(const std::string& task, const hand& target, const std::string& info, bool isChosenTarget);// public RVA = 0x50C0D0
    virtual void setNeedGOAP() override;// public RVA = 0x519FC0 vtable offset = 0x0
    void _NV_setNeedGOAP();// public RVA = 0x519FC0 vtable offset = 0x0
    void setDialogueDeliveryTag(EventTriggerEnum d);// public RVA = 0x50BE90
    EventTriggerEnum currentDialogueDelivery; // 0x264 Member
    EventTriggerEnum _currentDialogueEnumQuery; // 0x268 Member
    Tasker* getCurrentDurationTimedTask();// private RVA = 0x50C870
    class FailedTask
    {
    public:
        hand subj; // 0x0 Member
        // no_addr void FailedTask(const class AITaskSytem::FailedTask & _a1);// public missing arg names
        // no_addr void FailedTask();// public
        // no_addr class AITaskSytem::FailedTask & operator=(const class AITaskSytem::FailedTask & _a1);// public missing arg names
    };
    // no_addr void rememberFailedGOAP(enum TaskType _a1, const class hand & _a2);// private missing arg names
    bool _taskCompletedFlag; // 0x26C Member
    bool _taskImpossibleFlag; // 0x26D Member
    void _taskImpossible();// private RVA = 0x50C900
    CharBody* body; // 0x270 Member
    Character* character; // 0x278 Member
    bool isThePlayer();// private RVA = 0x790E90
    bool checkOrders();// private RVA = 0x5101A0
    TimeOfDay currentGoalExpiryTime; // 0x280 Member
    TimeOfDay currentTaskExpiryTime; // 0x288 Member
    void chooseGoal(bool timedLockOnCurrentGoal);// protected RVA = 0x510770
    bool _chooseGoal(taskPriority priority, SquadMemberType squadMemberType);// protected RVA = 0x5105E0
    void chooseGoalFrom(std::map<float, Tasker*, std::less<float>, Ogre::STLAllocator<std::pair<float const, Tasker*>, Ogre::GeneralAllocPolicy > >& orderedGoals, TaskMatch& alreadyHasGoal, lektor<Tasker*>& goalListIn, bool theseAreBlackboard);// protected RVA = 0x50D790
    void choosePermaJob(std::map<float, Tasker*, std::less<float>, Ogre::STLAllocator<std::pair<float const, Tasker*>, Ogre::GeneralAllocPolicy > >& orderedGoals, TaskMatch& alreadyHasGoal, bool urgentOnes, bool _jobsEnabled);// protected RVA = 0x50DE30
    void setupParametersForCurrentGoal();// protected RVA = 0x50C2F0
    bool runGoals(std::map<float, Tasker*, std::less<float>, Ogre::STLAllocator<std::pair<float const, Tasker*>, Ogre::GeneralAllocPolicy > >& orderedGoals, bool playerOrder);// protected RVA = 0x50FED0
    Tasker* autoSleepTask; // 0x290 Member
    Tasker* autoGetupTask; // 0x298 Member
    Tasker* autoDitchTask; // 0x2A0 Member
    Tasker* autoSitTask; // 0x2A8 Member
    Tasker* autoEjectEnemiesTask1; // 0x2B0 Member
    Tasker* autoEjectEnemiesTask2; // 0x2B8 Member
    std::map<float, Tasker*, std::less<float>, Ogre::STLAllocator<std::pair<float const, Tasker*>, Ogre::GeneralAllocPolicy > > orderedGoals; // 0x2C0 Member
    lektor<Tasker*> requestsList; // 0x2E8 Member
    void clearRequestsList();// protected RVA = 0x513980
    void bodyTaskComplete();// protected RVA = 0x50D050
    void popFromOrders(Tasker* what);// protected RVA = 0x50C810
    class ActionsListMgr : public ActionDeque
    {
    public:
        // ActionDeque offset = 0x0, length = 0x38
        // no_addr void ActionsListMgr(const class AITaskSytem::ActionsListMgr & _a1);// public missing arg names
        ActionsListMgr();// public RVA = 0x5199B0
        ActionsListMgr* _CONSTRUCTOR();// public RVA = 0x5199B0
        virtual ~ActionsListMgr();// public RVA = 0x519A00 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0x519A00 vtable offset = 0x0
        void copyFrom(AITaskSytem::ActionsListMgr* a);// public RVA = 0x50CB60
        void addFrom(AITaskSytem::ActionsListMgr* a);// public RVA = 0x50CC90
        // no_addr bool hasTask(class Tasker * _a1);// public missing arg names
        Tasker* getTaskAfterCurrent();// public RVA = 0x50C8E0
        Tasker* get2TasksAfterCurrent();// public RVA = 0x50C8F0
        // no_addr class AITaskSytem::ActionsListMgr & operator=(const class AITaskSytem::ActionsListMgr & _a1);// public missing arg names
        // no_addr void __local_vftable_ctor_closure();// public
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    AITaskSytem::ActionsListMgr actions; // 0x300 Member
    AITaskSytem::ActionsListMgr actionsTryList; // 0x338 Member
    std::string failedGOAPGoalDebugString; // 0x370 Member
    Ogre::Vector3 pos; // 0x398 Member
    bool setCurrentTask(AITaskSytem::ActionsListMgr* from);// protected RVA = 0x50CDC0
    Tasker* currentlySubTasking; // 0x3A8 Member
    int setTaskRecursionCounter; // 0x3B0 Member
    TaskType taskRecursionLast; // 0x3B4 Member
    float runGOAP(Tasker* task, bool _a2, bool playerOrder);// public RVA = 0x50F690
    // no_addr class AITaskSytem & operator=(const class AITaskSytem & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};