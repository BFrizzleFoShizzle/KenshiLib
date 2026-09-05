
; GOAPTaskMgr::setupGOAP();
?setupGOAP@GOAPTaskMgr@@SAXXZ proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+0*8]
?setupGOAP@GOAPTaskMgr@@SAXXZ endp

?_DESTRUCTOR@GOAPTaskMgr@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@GOAPTaskMgr@@QEAAXXZ endp

; GOAPTaskMgr::~GOAPTaskMgr();
??1GOAPTaskMgr@@UEAA@XZ proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+1*8]
??1GOAPTaskMgr@@UEAA@XZ endp

?_NV_hasTask@GOAPTaskMgr@@QEAA_NW4TaskType@@@Z proc EXPORT
?_NV_hasTask@GOAPTaskMgr@@QEAA_NW4TaskType@@@Z endp

; GOAPTaskMgr::hasTask(enum TaskType);
?hasTask@GOAPTaskMgr@@UEAA_NW4TaskType@@@Z proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+2*8]
?hasTask@GOAPTaskMgr@@UEAA_NW4TaskType@@@Z endp

; GOAPTaskMgr::createNewTask(enum TaskType, const class hand &, enum taskPriority, float, class Ogre::Vector3, int, int);
?createNewTask@GOAPTaskMgr@@QEAAPEAVTasker@@W4TaskType@@AEBVhand@@W4taskPriority@@MVVector3@Ogre@@HH@Z proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+3*8]
?createNewTask@GOAPTaskMgr@@QEAAPEAVTasker@@W4TaskType@@AEBVhand@@W4taskPriority@@MVVector3@Ogre@@HH@Z endp

; GOAPTaskMgr::createNewTask(class Tasker *);
?createNewTask@GOAPTaskMgr@@QEAAPEAVTasker@@PEAV2@@Z proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+4*8]
?createNewTask@GOAPTaskMgr@@QEAAPEAVTasker@@PEAV2@@Z endp

; GOAPTaskMgr::createNewTask(class TaskRequest *);
?createNewTask@GOAPTaskMgr@@QEAAPEAVTasker@@PEAVTaskRequest@@@Z proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+5*8]
?createNewTask@GOAPTaskMgr@@QEAAPEAVTasker@@PEAVTaskRequest@@@Z endp

; GOAPTaskMgr::isPermaJob(enum TaskType);
?isPermaJob@GOAPTaskMgr@@SA_NW4TaskType@@@Z proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+6*8]
?isPermaJob@GOAPTaskMgr@@SA_NW4TaskType@@@Z endp

; GOAPTaskMgr::getTaskData(enum TaskType);
?getTaskData@GOAPTaskMgr@@SAPEBVTaskData@@W4TaskType@@@Z proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+7*8]
?getTaskData@GOAPTaskMgr@@SAPEBVTaskData@@W4TaskType@@@Z endp

; GOAPTaskMgr::createNewTaskData(enum TaskType, function  *, bool, bool, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, unsigned int);
?createNewTaskData@GOAPTaskMgr@@SAPEAVTaskData@@W4TaskType@@P8AI@@EAAMAEBVhand@@AEBVVector3@Ogre@@@Z_N4AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@I@Z proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+8*8]
?createNewTaskData@GOAPTaskMgr@@SAPEAVTaskData@@W4TaskType@@P8AI@@EAAMAEBVhand@@AEBVVector3@Ogre@@@Z_N4AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@I@Z endp

?_CONSTRUCTOR@GOAPTaskMgr@@QEAAPEAV1@XZ proc EXPORT
?_CONSTRUCTOR@GOAPTaskMgr@@QEAAPEAV1@XZ endp

; GOAPTaskMgr::GOAPTaskMgr();
??0GOAPTaskMgr@@QEAA@XZ proc EXPORT
jmp function_pointers[_GOAPTaskMgr_base+9*8]
??0GOAPTaskMgr@@QEAA@XZ endp
