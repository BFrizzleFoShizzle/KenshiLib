#pragma once

#include "AI.h"

class Tasker;
class TaskRequest;
class TaskData;

// TODO move?
class StateStringInfos
{
public:
    // no_addr void StateStringInfos(const class StateStringInfos & _a1);// public missing arg names
    // no_addr void StateStringInfos(class std::basic_string<char,std::char_traits<char>,std::allocator<char> > _a1);// public missing arg names
    StateStringInfos();// public RVA = 0x61E9C0
    StateStringInfos* _CONSTRUCTOR();// public RVA = 0x61E9C0
    std::string debug; // 0x0 Member
    std::string speech; // 0x28 Member
    // no_addr class StateStringInfos & operator=(const class StateStringInfos & _a1);// public missing arg names
    StateStringInfos& operator=(std::string s);// public RVA = 0x61EA50
    ~StateStringInfos();// public RVA = 0x61D880
    void _DESTRUCTOR();// public RVA = 0x61D880
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class GOAPTaskMgr
{
public:
    // VTable         : (none)
    static void setupGOAP();// public RVA = 0x3195B0
    static ogre_unordered_map<StateType, StateStringInfos>::type stateDescriptions; // RVA = 0x1EA6350 Static Member
    virtual ~GOAPTaskMgr();// public RVA = 0x3175A0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x3175A0 vtable offset = 0x0
    virtual bool hasTask(TaskType key);// public RVA = 0x3175B0 vtable offset = 0x8
    bool _NV_hasTask(TaskType key);// public RVA = 0x3175B0 vtable offset = 0x8
    Tasker* createNewTask(TaskType key, const hand& subject, taskPriority priority, float weight, Ogre::Vector3 location, int startTime, int endTime);// public RVA = 0x32E720
    Tasker* createNewTask(Tasker* t);// public RVA = 0x3300E0
    Tasker* createNewTask(TaskRequest* t);// public RVA = 0x330080
    static bool isPermaJob(TaskType key);// public RVA = 0x32E6F0
    static const TaskData* getTaskData(TaskType key);// public RVA = 0x283AD0
    static ogre_unordered_map<TaskType, TaskData*>::type taskData; // RVA = 0x1CE60F0 Static Member
    static TaskData* createNewTaskData(TaskType key, float (AI::* score)(const hand&, const Ogre::Vector3&), bool func, bool needsSubjectOrLocation, const std::string& description, unsigned int flags);// protected RVA = 0x60E280
    // no_addr void GOAPTaskMgr(const class GOAPTaskMgr & _a1);// public missing arg names
    GOAPTaskMgr();// public RVA = 0x3175F0
    GOAPTaskMgr* _CONSTRUCTOR();// public RVA = 0x3175F0
    // no_addr class GOAPTaskMgr & operator=(const class GOAPTaskMgr & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class TaskRepertoire : public GOAPTaskMgr
{
public:
    // GOAPTaskMgr offset = 0x0, length = 0x8
    std::string name; // 0x8 Member
    // no_addr void TaskRepertoire(const class TaskRepertoire & _a1);// public missing arg names
    TaskRepertoire(const std::string& _name);// public RVA = 0x32D4F0
    TaskRepertoire* _CONSTRUCTOR(const std::string& _name);// public RVA = 0x32D4F0
    virtual ~TaskRepertoire();// public RVA = 0x32D7B0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x32D7B0 vtable offset = 0x0
    TaskData* getTaskData(TaskType key);// public RVA = 0x519F20
    virtual bool hasTask(TaskType key) override;// public RVA = 0x32D740 vtable offset = 0x0
    bool _NV_hasTask(TaskType key);// public RVA = 0x32D740 vtable offset = 0x0
    const Ogre::vector<TaskData*>::type* getTasksWithResult(TaskStateData* data);// public RVA = 0x60F860
    void initialiseOnceEverythingIsAdded();// public RVA = 0x60F6B0
    std::set<TaskType, std::less<TaskType>, Ogre::STLAllocator<TaskType, Ogre::GeneralAllocPolicy > > myTasks; // 0x30 Member
    ogre_unordered_map<StateType, Ogre::vector<TaskData*>::type>::type positiveResults; // 0x58 Member
    ogre_unordered_map<StateType, Ogre::vector<TaskData*>::type>::type negativeResults; // 0x98 Member
    // no_addr class TaskRepertoire & operator=(const class TaskRepertoire & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};