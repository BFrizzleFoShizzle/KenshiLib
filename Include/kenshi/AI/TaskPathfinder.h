#pragma once

#include "../util/hand.h"
#include "../util/OgreUnordered.h"
#include "../util/lektor.h"
#include <ogre/OgreVector3.h>

class AI;
class TaskStateData;
class TaskData;

class TaskPathfinder
{
public:
    hand debugHandle; // 0x0 Member
    // no_addr void TaskPathfinder(const class TaskPathfinder & _a1);// public missing arg names
    TaskPathfinder(AI* _ai);// public RVA = 0x518670
    TaskPathfinder* _CONSTRUCTOR(AI* _ai);// public RVA = 0x518670
    ~TaskPathfinder();// public RVA = 0x51BF20
    void _DESTRUCTOR();// public RVA = 0x51BF20
    bool isRunningAPlayerOrder; // 0x20 Member
    bool meIsPlayer();// public RVA = 0x50C0E0
    class Node
    {
    public:
        // no_addr void Node(const class TaskPathfinder::Node & _a1);// public missing arg names
        Node(TaskType key, const hand& subj, const Ogre::Vector3& loc, bool action, TaskPathfinder* _pathfinder);// public RVA = 0x51AD80
        Node* _CONSTRUCTOR(TaskType key, const hand& subj, const Ogre::Vector3& loc, bool action, TaskPathfinder* _pathfinder);// public RVA = 0x51AD80
        TaskType type; // 0x0 Member
        bool isAction; // 0x4 Member
        hand subject; // 0x8 Member
        hand subTarget; // 0x28 Member
        Ogre::Vector3 location; // 0x48 Member
        float lowestScore; // 0x54 Member
        float score; // 0x58 Member
        TaskPathfinder::Node* parentLink; // 0x60 Member
        ogre_unordered_map<TaskStateData*, lektor<TaskPathfinder::Node*>>::type successorNodes;
        lektor<TaskPathfinder::Node*>& getFirstSuccessorList();// public RVA = 0x51AEB0
        bool satisfiesState(TaskStateData* what);// public RVA = 0x51A4A0
        float getScore(const hand& subject, Ogre::Vector3& location);// public RVA = 0x51A600
        bool calculateSuccessorNodes();// public RVA = 0x51B360
        float queryScoreSoFar(TaskPathfinder::Node* _parent);// public RVA = 0x50BEC0
        void setParent(TaskPathfinder::Node* _parent);// public RVA = 0x50BED0
        TaskData* getTask();// public RVA = 0x519F60
        bool sameAs(const TaskPathfinder::Node& other) const;// public RVA = 0x50BF10
        TaskPathfinder* pathfinder; // 0xA8 Member
        ~Node();// public RVA = 0x51B350
        void _DESTRUCTOR();// public RVA = 0x51B350
        // no_addr class TaskPathfinder::Node & operator=(const class TaskPathfinder::Node & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    bool solve(std::deque<TaskPathfinder::Node*>& output, TaskType desiredTask, const hand& target, const Ogre::Vector3& loc, const hand& _debugHandle, bool playerOrder);// public RVA = 0x50F080
    float getLowestScore(const std::deque<TaskPathfinder::Node*>& in);// public RVA = 0x5187E0
    lektor<TaskPathfinder::Node*> duplicates; // 0x28 Member
    int getDuplicateCount(TaskPathfinder::Node* who);// public RVA = 0x513A10
    TaskPathfinder::Node* createDeadEndNode(TaskPathfinder::Node* _creator);// public RVA = 0x51B200
    TaskPathfinder::Node* createNode(TaskData* dat, const hand& subj, const Ogre::Vector3& loc, TaskPathfinder::Node* _creator);// public RVA = 0x51BAC0
    Ogre::vector<TaskPathfinder::Node*>::type allNodes; // 0x40 Member
    static bool isAllowedDuplicates(TaskType key);// public RVA = 0x50BF90
    AI* ai; // 0x60 Member
    bool successCheck(bool& success, std::deque<TaskPathfinder::Node*>& output, TaskPathfinder::Node** best, const hand& debugHandle, bool duplicatedAlready);// private RVA = 0x50ED70
    void clearSatisfiedSuccessors(TaskPathfinder::Node* pathEnd);// private RVA = 0x51A9E0
    TaskPathfinder::Node* getNextBranch(TaskPathfinder::Node* pathEnd);// private RVA = 0x513AD0
    TaskPathfinder::Node* takeBestNode(lektor<TaskPathfinder::Node*>& list);// private RVA = 0x518FB0
    bool nodeIsInList(TaskPathfinder::Node* node, const lektor<TaskPathfinder::Node*>& list);// private RVA = 0x513B20
    bool duplicateNodeWasCompleted(TaskPathfinder::Node* best, std::deque<TaskPathfinder::Node*>& output);// private RVA = 0x5188F0
    // no_addr bool duplicateNodeIsInList(class TaskPathfinder::Node * _a1, const class lektor<TaskPathfinder::Node *> & _a2);// private missing arg names
    void removeFromList(TaskPathfinder::Node* node, lektor<TaskPathfinder::Node*>& list);// private RVA = 0x513B50
    lektor<TaskPathfinder::Node*> open; // 0x68 Member
    lektor<TaskPathfinder::Node*> closed; // 0x80 Member
    void addToOpen(TaskPathfinder::Node* n);// private RVA = 0x514C50
    void addToClosed(TaskPathfinder::Node* n);// private RVA = 0x514D80
    void cleanup();// private RVA = 0x51BD90
    // no_addr class TaskPathfinder & operator=(const class TaskPathfinder & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};