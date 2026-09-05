
?_CONSTRUCTOR@TaskPathfinder@@QEAAPEAV1@PEAVAI@@@Z proc EXPORT
?_CONSTRUCTOR@TaskPathfinder@@QEAAPEAV1@PEAVAI@@@Z endp

; TaskPathfinder::TaskPathfinder(class AI *);
??0TaskPathfinder@@QEAA@PEAVAI@@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+0*8]
??0TaskPathfinder@@QEAA@PEAVAI@@@Z endp

?_DESTRUCTOR@TaskPathfinder@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@TaskPathfinder@@QEAAXXZ endp

; TaskPathfinder::~TaskPathfinder();
??1TaskPathfinder@@QEAA@XZ proc EXPORT
jmp function_pointers[_TaskPathfinder_base+1*8]
??1TaskPathfinder@@QEAA@XZ endp

; TaskPathfinder::meIsPlayer();
?meIsPlayer@TaskPathfinder@@QEAA_NXZ proc EXPORT
jmp function_pointers[_TaskPathfinder_base+2*8]
?meIsPlayer@TaskPathfinder@@QEAA_NXZ endp

; TaskPathfinder::solve(class std::deque<TaskPathfinder::Node *,std::allocator<TaskPathfinder::Node *> > &, enum TaskType, const class hand &, const class Ogre::Vector3 &, const class hand &, bool);
?solve@TaskPathfinder@@QEAA_NAEAV?$deque@PEAVNode@TaskPathfinder@@V?$allocator@PEAVNode@TaskPathfinder@@@std@@@std@@W4TaskType@@AEBVhand@@AEBVVector3@Ogre@@2_N@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+3*8]
?solve@TaskPathfinder@@QEAA_NAEAV?$deque@PEAVNode@TaskPathfinder@@V?$allocator@PEAVNode@TaskPathfinder@@@std@@@std@@W4TaskType@@AEBVhand@@AEBVVector3@Ogre@@2_N@Z endp

; TaskPathfinder::getLowestScore(const class std::deque<TaskPathfinder::Node *,std::allocator<TaskPathfinder::Node *> > &);
?getLowestScore@TaskPathfinder@@QEAAMAEBV?$deque@PEAVNode@TaskPathfinder@@V?$allocator@PEAVNode@TaskPathfinder@@@std@@@std@@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+4*8]
?getLowestScore@TaskPathfinder@@QEAAMAEBV?$deque@PEAVNode@TaskPathfinder@@V?$allocator@PEAVNode@TaskPathfinder@@@std@@@std@@@Z endp

; TaskPathfinder::getDuplicateCount(class TaskPathfinder::Node *);
?getDuplicateCount@TaskPathfinder@@QEAAHPEAVNode@1@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+5*8]
?getDuplicateCount@TaskPathfinder@@QEAAHPEAVNode@1@@Z endp

; TaskPathfinder::createDeadEndNode(class TaskPathfinder::Node *);
?createDeadEndNode@TaskPathfinder@@QEAAPEAVNode@1@PEAV21@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+6*8]
?createDeadEndNode@TaskPathfinder@@QEAAPEAVNode@1@PEAV21@@Z endp

; TaskPathfinder::createNode(class TaskData *, const class hand &, const class Ogre::Vector3 &, class TaskPathfinder::Node *);
?createNode@TaskPathfinder@@QEAAPEAVNode@1@PEAVTaskData@@AEBVhand@@AEBVVector3@Ogre@@PEAV21@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+7*8]
?createNode@TaskPathfinder@@QEAAPEAVNode@1@PEAVTaskData@@AEBVhand@@AEBVVector3@Ogre@@PEAV21@@Z endp

; TaskPathfinder::isAllowedDuplicates(enum TaskType);
?isAllowedDuplicates@TaskPathfinder@@SA_NW4TaskType@@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+8*8]
?isAllowedDuplicates@TaskPathfinder@@SA_NW4TaskType@@@Z endp

; TaskPathfinder::successCheck(bool &, class std::deque<TaskPathfinder::Node *,std::allocator<TaskPathfinder::Node *> > &, class TaskPathfinder::Node * *, const class hand &, bool);
?successCheck@TaskPathfinder@@QEAA_NAEA_NAEAV?$deque@PEAVNode@TaskPathfinder@@V?$allocator@PEAVNode@TaskPathfinder@@@std@@@std@@PEAPEAVNode@1@AEBVhand@@_N@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+9*8]
?successCheck@TaskPathfinder@@QEAA_NAEA_NAEAV?$deque@PEAVNode@TaskPathfinder@@V?$allocator@PEAVNode@TaskPathfinder@@@std@@@std@@PEAPEAVNode@1@AEBVhand@@_N@Z endp

; TaskPathfinder::clearSatisfiedSuccessors(class TaskPathfinder::Node *);
?clearSatisfiedSuccessors@TaskPathfinder@@QEAAXPEAVNode@1@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+10*8]
?clearSatisfiedSuccessors@TaskPathfinder@@QEAAXPEAVNode@1@@Z endp

; TaskPathfinder::getNextBranch(class TaskPathfinder::Node *);
?getNextBranch@TaskPathfinder@@QEAAPEAVNode@1@PEAV21@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+11*8]
?getNextBranch@TaskPathfinder@@QEAAPEAVNode@1@PEAV21@@Z endp

; TaskPathfinder::takeBestNode(class lektor<TaskPathfinder::Node *> &);
?takeBestNode@TaskPathfinder@@QEAAPEAVNode@1@AEAV?$lektor@PEAVNode@TaskPathfinder@@@@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+12*8]
?takeBestNode@TaskPathfinder@@QEAAPEAVNode@1@AEAV?$lektor@PEAVNode@TaskPathfinder@@@@@Z endp

; TaskPathfinder::nodeIsInList(class TaskPathfinder::Node *, const class lektor<TaskPathfinder::Node *> &);
?nodeIsInList@TaskPathfinder@@QEAA_NPEAVNode@1@AEBV?$lektor@PEAVNode@TaskPathfinder@@@@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+13*8]
?nodeIsInList@TaskPathfinder@@QEAA_NPEAVNode@1@AEBV?$lektor@PEAVNode@TaskPathfinder@@@@@Z endp

; TaskPathfinder::duplicateNodeWasCompleted(class TaskPathfinder::Node *, class std::deque<TaskPathfinder::Node *,std::allocator<TaskPathfinder::Node *> > &);
?duplicateNodeWasCompleted@TaskPathfinder@@QEAA_NPEAVNode@1@AEAV?$deque@PEAVNode@TaskPathfinder@@V?$allocator@PEAVNode@TaskPathfinder@@@std@@@std@@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+14*8]
?duplicateNodeWasCompleted@TaskPathfinder@@QEAA_NPEAVNode@1@AEAV?$deque@PEAVNode@TaskPathfinder@@V?$allocator@PEAVNode@TaskPathfinder@@@std@@@std@@@Z endp

; TaskPathfinder::removeFromList(class TaskPathfinder::Node *, class lektor<TaskPathfinder::Node *> &);
?removeFromList@TaskPathfinder@@QEAAXPEAVNode@1@AEAV?$lektor@PEAVNode@TaskPathfinder@@@@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+15*8]
?removeFromList@TaskPathfinder@@QEAAXPEAVNode@1@AEAV?$lektor@PEAVNode@TaskPathfinder@@@@@Z endp

; TaskPathfinder::addToOpen(class TaskPathfinder::Node *);
?addToOpen@TaskPathfinder@@QEAAXPEAVNode@1@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+16*8]
?addToOpen@TaskPathfinder@@QEAAXPEAVNode@1@@Z endp

; TaskPathfinder::addToClosed(class TaskPathfinder::Node *);
?addToClosed@TaskPathfinder@@QEAAXPEAVNode@1@@Z proc EXPORT
jmp function_pointers[_TaskPathfinder_base+17*8]
?addToClosed@TaskPathfinder@@QEAAXPEAVNode@1@@Z endp

; TaskPathfinder::cleanup();
?cleanup@TaskPathfinder@@QEAAXXZ proc EXPORT
jmp function_pointers[_TaskPathfinder_base+18*8]
?cleanup@TaskPathfinder@@QEAAXXZ endp
