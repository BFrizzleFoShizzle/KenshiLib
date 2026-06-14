
?_CONSTRUCTOR@OrdersReceiver@@QEAAPEAV1@PEAVAI@@PEAVCharacter@@@Z proc EXPORT
?_CONSTRUCTOR@OrdersReceiver@@QEAAPEAV1@PEAVAI@@PEAVCharacter@@@Z endp

; OrdersReceiver::OrdersReceiver(class AI *, class Character *);
??0OrdersReceiver@@QEAA@PEAVAI@@PEAVCharacter@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+0*8]
??0OrdersReceiver@@QEAA@PEAVAI@@PEAVCharacter@@@Z endp

?_DESTRUCTOR@OrdersReceiver@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@OrdersReceiver@@QEAAXXZ endp

; OrdersReceiver::~OrdersReceiver();
??1OrdersReceiver@@UEAA@XZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+1*8]
??1OrdersReceiver@@UEAA@XZ endp

?_NV_serialise@OrdersReceiver@@QEAAXPEAVGameData@@@Z proc EXPORT
?_NV_serialise@OrdersReceiver@@QEAAXPEAVGameData@@@Z endp

; OrdersReceiver::serialise(class GameData *);
?serialise@OrdersReceiver@@UEAAXPEAVGameData@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+2*8]
?serialise@OrdersReceiver@@UEAAXPEAVGameData@@@Z endp

?_NV_loadFromSerialise@OrdersReceiver@@QEAAXPEAVGameData@@@Z proc EXPORT
?_NV_loadFromSerialise@OrdersReceiver@@QEAAXPEAVGameData@@@Z endp

; OrdersReceiver::loadFromSerialise(class GameData *);
?loadFromSerialise@OrdersReceiver@@UEAAXPEAVGameData@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+3*8]
?loadFromSerialise@OrdersReceiver@@UEAAXPEAVGameData@@@Z endp

; OrdersReceiver::_forceOrderInsert(enum TaskType);
?_forceOrderInsert@OrdersReceiver@@QEAAPEAVTasker@@W4TaskType@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+4*8]
?_forceOrderInsert@OrdersReceiver@@QEAAPEAVTasker@@W4TaskType@@@Z endp

; OrdersReceiver::addOrder(enum TaskType, const class hand &, const class Ogre::Vector3 &, bool, bool);
?addOrder@OrdersReceiver@@QEAAXW4TaskType@@AEBVhand@@AEBVVector3@Ogre@@_N3@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+5*8]
?addOrder@OrdersReceiver@@QEAAXW4TaskType@@AEBVhand@@AEBVVector3@Ogre@@_N3@Z endp

; OrdersReceiver::addJob(enum TaskType, const class hand &, const class Ogre::Vector3 &, bool);
?addJob@OrdersReceiver@@QEAAXW4TaskType@@AEBVhand@@AEBVVector3@Ogre@@_N@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+6*8]
?addJob@OrdersReceiver@@QEAAXW4TaskType@@AEBVhand@@AEBVVector3@Ogre@@_N@Z endp

; OrdersReceiver::removeJob(enum TaskType);
?removeJob@OrdersReceiver@@QEAAXW4TaskType@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+7*8]
?removeJob@OrdersReceiver@@QEAAXW4TaskType@@@Z endp

; OrdersReceiver::removePermajob(int);
?removePermajob@OrdersReceiver@@QEAAXH@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+8*8]
?removePermajob@OrdersReceiver@@QEAAXH@Z endp

; OrdersReceiver::movePermajob(int, int);
?movePermajob@OrdersReceiver@@QEAAXHH@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+9*8]
?movePermajob@OrdersReceiver@@QEAAXHH@Z endp

; OrdersReceiver::clearPermajobs();
?clearPermajobs@OrdersReceiver@@QEAAXXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+10*8]
?clearPermajobs@OrdersReceiver@@QEAAXXZ endp

; OrdersReceiver::getPermajobName(int);
?getPermajobName@OrdersReceiver@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+11*8]
?getPermajobName@OrdersReceiver@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z endp

; OrdersReceiver::getPermajob(int);
?getPermajob@OrdersReceiver@@QEBA?AW4TaskType@@H@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+12*8]
?getPermajob@OrdersReceiver@@QEBA?AW4TaskType@@H@Z endp

; OrdersReceiver::getPermajobData(int);
?getPermajobData@OrdersReceiver@@QEBAPEBVTasker@@H@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+13*8]
?getPermajobData@OrdersReceiver@@QEBAPEBVTasker@@H@Z endp

; OrdersReceiver::getPermajobCount();
?getPermajobCount@OrdersReceiver@@QEBAHXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+14*8]
?getPermajobCount@OrdersReceiver@@QEBAHXZ endp

; OrdersReceiver::hasPermajob(enum TaskType);
?hasPermajob@OrdersReceiver@@QEBA_NW4TaskType@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+15*8]
?hasPermajob@OrdersReceiver@@QEBA_NW4TaskType@@@Z endp

; OrdersReceiver::addGoal(class Tasker *);
?addGoal@OrdersReceiver@@QEAAXPEAVTasker@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+16*8]
?addGoal@OrdersReceiver@@QEAAXPEAVTasker@@@Z endp

; OrdersReceiver::removeGoal(enum TaskType);
?removeGoal@OrdersReceiver@@QEAAXW4TaskType@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+17*8]
?removeGoal@OrdersReceiver@@QEAAXW4TaskType@@@Z endp

; OrdersReceiver::hasGoal(enum TaskType);
?hasGoal@OrdersReceiver@@QEAA_NW4TaskType@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+18*8]
?hasGoal@OrdersReceiver@@QEAA_NW4TaskType@@@Z endp

; OrdersReceiver::updateLastOrder(enum TaskType, const class hand &, const class Ogre::Vector3 &);
?updateLastOrder@OrdersReceiver@@QEAAXW4TaskType@@AEBVhand@@AEBVVector3@Ogre@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+19*8]
?updateLastOrder@OrdersReceiver@@QEAAXW4TaskType@@AEBVhand@@AEBVVector3@Ogre@@@Z endp

?_NV_setNeedGOAP@OrdersReceiver@@QEAAXXZ proc EXPORT
?_NV_setNeedGOAP@OrdersReceiver@@QEAAXXZ endp

; OrdersReceiver::setNeedGOAP();
?setNeedGOAP@OrdersReceiver@@UEAAXXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+20*8]
?setNeedGOAP@OrdersReceiver@@UEAAXXZ endp

; OrdersReceiver::getFirstOrder();
?getFirstOrder@OrdersReceiver@@QEAAPEAVTasker@@XZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+21*8]
?getFirstOrder@OrdersReceiver@@QEAAPEAVTasker@@XZ endp

; OrdersReceiver::clearOrders();
?clearOrders@OrdersReceiver@@QEAAXXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+22*8]
?clearOrders@OrdersReceiver@@QEAAXXZ endp

; OrdersReceiver::clearJobs();
?clearJobs@OrdersReceiver@@QEAAXXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+23*8]
?clearJobs@OrdersReceiver@@QEAAXXZ endp

; OrdersReceiver::_clearGoals();
?_clearGoals@OrdersReceiver@@QEAAXXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+24*8]
?_clearGoals@OrdersReceiver@@QEAAXXZ endp

; OrdersReceiver::getCurrentGoal();
?getCurrentGoal@OrdersReceiver@@QEBAAEBVTaskMatch@@XZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+25*8]
?getCurrentGoal@OrdersReceiver@@QEBAAEBVTaskMatch@@XZ endp

?_NV_setHoldPositionOrders@OrdersReceiver@@QEAAXPEAVTasker@@@Z proc EXPORT
?_NV_setHoldPositionOrders@OrdersReceiver@@QEAAXPEAVTasker@@@Z endp

; OrdersReceiver::setHoldPositionOrders(class Tasker *);
?setHoldPositionOrders@OrdersReceiver@@UEAAXPEAVTasker@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+26*8]
?setHoldPositionOrders@OrdersReceiver@@UEAAXPEAVTasker@@@Z endp

; OrdersReceiver::hasPlayerOrders();
?hasPlayerOrders@OrdersReceiver@@QEBA_NXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+27*8]
?hasPlayerOrders@OrdersReceiver@@QEBA_NXZ endp

; OrdersReceiver::hasPlayerOrder(enum TaskType);
?hasPlayerOrder@OrdersReceiver@@QEBA_NW4TaskType@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+28*8]
?hasPlayerOrder@OrdersReceiver@@QEBA_NW4TaskType@@@Z endp

; OrdersReceiver::isInChoosingGoalMode();
?isInChoosingGoalMode@OrdersReceiver@@QEBA_NXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+29*8]
?isInChoosingGoalMode@OrdersReceiver@@QEBA_NXZ endp

; OrdersReceiver::hasOrders();
?hasOrders@OrdersReceiver@@QEBA_NXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+30*8]
?hasOrders@OrdersReceiver@@QEBA_NXZ endp

; OrdersReceiver::getSlaveJobs(class lektor<Tasker *> &, class TaskRepertoire *, const class hand &);
?getSlaveJobs@OrdersReceiver@@QEAAXAEAV?$lektor@PEAVTasker@@@@PEAVTaskRepertoire@@AEBVhand@@@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+31*8]
?getSlaveJobs@OrdersReceiver@@QEAAXAEAV?$lektor@PEAVTasker@@@@PEAVTaskRepertoire@@AEBVhand@@@Z endp

; OrdersReceiver::clearSlaveJobs();
?clearSlaveJobs@OrdersReceiver@@QEAAXXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+32*8]
?clearSlaveJobs@OrdersReceiver@@QEAAXXZ endp

; OrdersReceiver::isJobsEnabled();
?isJobsEnabled@OrdersReceiver@@QEBA_NXZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+33*8]
?isJobsEnabled@OrdersReceiver@@QEBA_NXZ endp

; OrdersReceiver::setJobsEnabled(bool);
?setJobsEnabled@OrdersReceiver@@QEAAX_N@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+34*8]
?setJobsEnabled@OrdersReceiver@@QEAAX_N@Z endp

; OrdersReceiver::clearCurrentGoal(bool);
?clearCurrentGoal@OrdersReceiver@@QEAAX_N@Z proc EXPORT
jmp function_pointers[_OrdersReceiver_base+35*8]
?clearCurrentGoal@OrdersReceiver@@QEAAX_N@Z endp

; OrdersReceiver::tryToGetCurrentGoal();
?tryToGetCurrentGoal@OrdersReceiver@@QEAAPEAVTasker@@XZ proc EXPORT
jmp function_pointers[_OrdersReceiver_base+36*8]
?tryToGetCurrentGoal@OrdersReceiver@@QEAAPEAVTasker@@XZ endp
