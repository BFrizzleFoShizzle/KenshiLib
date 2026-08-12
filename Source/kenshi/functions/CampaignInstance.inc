
?_CONSTRUCTOR@CampaignInstance@@QEAAPEAV1@HPEAVFaction@@0PEAVCampaignData@@AEBVhand@@@Z proc EXPORT
?_CONSTRUCTOR@CampaignInstance@@QEAAPEAV1@HPEAVFaction@@0PEAVCampaignData@@AEBVhand@@@Z endp

; CampaignInstance::CampaignInstance(int, class Faction *, class Faction *, class CampaignData *, const class hand &);
??0CampaignInstance@@QEAA@HPEAVFaction@@0PEAVCampaignData@@AEBVhand@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+0*8]
??0CampaignInstance@@QEAA@HPEAVFaction@@0PEAVCampaignData@@AEBVhand@@@Z endp

?_DESTRUCTOR@CampaignInstance@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@CampaignInstance@@QEAAXXZ endp

; CampaignInstance::~CampaignInstance();
??1CampaignInstance@@UEAA@XZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+1*8]
??1CampaignInstance@@UEAA@XZ endp

; CampaignInstance::getData();
?getData@CampaignInstance@@QEAAPEAVCampaignData@@XZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+2*8]
?getData@CampaignInstance@@QEAAPEAVCampaignData@@XZ endp

; CampaignInstance::changePhase(enum Phase);
?changePhase@CampaignInstance@@QEAAXW4Phase@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+3*8]
?changePhase@CampaignInstance@@QEAAXW4Phase@@@Z endp

; CampaignInstance::saveState(class GameData *, int);
?saveState@CampaignInstance@@QEAAXPEAVGameData@@H@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+4*8]
?saveState@CampaignInstance@@QEAAXPEAVGameData@@H@Z endp

; CampaignInstance::loadState(class GameData *, int);
?loadState@CampaignInstance@@QEAAXPEAVGameData@@H@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+5*8]
?loadState@CampaignInstance@@QEAAXPEAVGameData@@H@Z endp

?_NV_markOnMap@CampaignInstance@@QEAAXXZ proc EXPORT
?_NV_markOnMap@CampaignInstance@@QEAAXXZ endp

; CampaignInstance::markOnMap();
?markOnMap@CampaignInstance@@UEAAXXZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+6*8]
?markOnMap@CampaignInstance@@UEAAXXZ endp

; CampaignInstance::getDialogData(enum EventTriggerEnum);
?getDialogData@CampaignInstance@@QEAAPEAVGameData@@W4EventTriggerEnum@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+7*8]
?getDialogData@CampaignInstance@@QEAAPEAVGameData@@W4EventTriggerEnum@@@Z endp

; CampaignInstance::hasSufficientManpower();
?hasSufficientManpower@CampaignInstance@@QEAA_NXZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+8*8]
?hasSufficientManpower@CampaignInstance@@QEAA_NXZ endp

?_NV_victoryEvent@CampaignInstance@@QEAAXXZ proc EXPORT
?_NV_victoryEvent@CampaignInstance@@QEAAXXZ endp

; CampaignInstance::victoryEvent();
?victoryEvent@CampaignInstance@@UEAAXXZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+9*8]
?victoryEvent@CampaignInstance@@UEAAXXZ endp

?_NV_lossEvent@CampaignInstance@@QEAAXXZ proc EXPORT
?_NV_lossEvent@CampaignInstance@@QEAAXXZ endp

; CampaignInstance::lossEvent();
?lossEvent@CampaignInstance@@UEAAXXZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+10*8]
?lossEvent@CampaignInstance@@UEAAXXZ endp

?_NV_setLeader@CampaignInstance@@QEAAXAEBVhand@@@Z proc EXPORT
?_NV_setLeader@CampaignInstance@@QEAAXAEBVhand@@@Z endp

; CampaignInstance::setLeader(const class hand &);
?setLeader@CampaignInstance@@UEAAXAEBVhand@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+11*8]
?setLeader@CampaignInstance@@UEAAXAEBVhand@@@Z endp

?_NV_getLeader@CampaignInstance@@QEAAPEAVCharacter@@XZ proc EXPORT
?_NV_getLeader@CampaignInstance@@QEAAPEAVCharacter@@XZ endp

; CampaignInstance::getLeader();
?getLeader@CampaignInstance@@UEAAPEAVCharacter@@XZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+12*8]
?getLeader@CampaignInstance@@UEAAPEAVCharacter@@XZ endp

?_NV_getLeaderPlatoon@CampaignInstance@@QEAAPEAVPlatoon@@XZ proc EXPORT
?_NV_getLeaderPlatoon@CampaignInstance@@QEAAPEAVPlatoon@@XZ endp

; CampaignInstance::getLeaderPlatoon();
?getLeaderPlatoon@CampaignInstance@@UEAAPEAVPlatoon@@XZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+13*8]
?getLeaderPlatoon@CampaignInstance@@UEAAPEAVPlatoon@@XZ endp

?_NV_isEnemy@CampaignInstance@@QEAA_NPEAVCharacter@@@Z proc EXPORT
?_NV_isEnemy@CampaignInstance@@QEAA_NPEAVCharacter@@@Z endp

; CampaignInstance::isEnemy(class Character *);
?isEnemy@CampaignInstance@@UEAA_NPEAVCharacter@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+14*8]
?isEnemy@CampaignInstance@@UEAA_NPEAVCharacter@@@Z endp

?_NV_getName@CampaignInstance@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc EXPORT
?_NV_getName@CampaignInstance@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; CampaignInstance::getName();
?getName@CampaignInstance@@UEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+15*8]
?getName@CampaignInstance@@UEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

?_NV_setup@CampaignInstance@@QEAA_NXZ proc EXPORT
?_NV_setup@CampaignInstance@@QEAA_NXZ endp

; CampaignInstance::setup();
?setup@CampaignInstance@@UEAA_NXZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+16*8]
?setup@CampaignInstance@@UEAA_NXZ endp

?_NV_periodicUpdate@CampaignInstance@@QEAAXXZ proc EXPORT
?_NV_periodicUpdate@CampaignInstance@@QEAAXXZ endp

; CampaignInstance::periodicUpdate();
?periodicUpdate@CampaignInstance@@UEAAXXZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+17*8]
?periodicUpdate@CampaignInstance@@UEAAXXZ endp

?_NV_isEverybodyIdle@CampaignInstance@@QEAA_NXZ proc EXPORT
?_NV_isEverybodyIdle@CampaignInstance@@QEAA_NXZ endp

; CampaignInstance::isEverybodyIdle();
?isEverybodyIdle@CampaignInstance@@UEAA_NXZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+18*8]
?isEverybodyIdle@CampaignInstance@@UEAA_NXZ endp

?_NV_getUnloadedPlatoonBehavior@CampaignInstance@@QEAA?AW4UnloadedPlatoonJob@@PEAVPlatoon@@@Z proc EXPORT
?_NV_getUnloadedPlatoonBehavior@CampaignInstance@@QEAA?AW4UnloadedPlatoonJob@@PEAVPlatoon@@@Z endp

; CampaignInstance::getUnloadedPlatoonBehavior(class Platoon *);
?getUnloadedPlatoonBehavior@CampaignInstance@@UEAA?AW4UnloadedPlatoonJob@@PEAVPlatoon@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+19*8]
?getUnloadedPlatoonBehavior@CampaignInstance@@UEAA?AW4UnloadedPlatoonJob@@PEAVPlatoon@@@Z endp

?_NV_getAIPackage@CampaignInstance@@QEAAPEAVGameData@@PEAVPlatoon@@@Z proc EXPORT
?_NV_getAIPackage@CampaignInstance@@QEAAPEAVGameData@@PEAVPlatoon@@@Z endp

; CampaignInstance::getAIPackage(class Platoon *);
?getAIPackage@CampaignInstance@@UEAAPEAVGameData@@PEAVPlatoon@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+20*8]
?getAIPackage@CampaignInstance@@UEAAPEAVGameData@@PEAVPlatoon@@@Z endp

?_NV_addToCampaign@CampaignInstance@@QEAAXPEAVPlatoon@@_N@Z proc EXPORT
?_NV_addToCampaign@CampaignInstance@@QEAAXPEAVPlatoon@@_N@Z endp

; CampaignInstance::addToCampaign(class Platoon *, bool);
?addToCampaign@CampaignInstance@@UEAAXPEAVPlatoon@@_N@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+21*8]
?addToCampaign@CampaignInstance@@UEAAXPEAVPlatoon@@_N@Z endp

?_NV_areForcesAllTogether@CampaignInstance@@QEAA_NXZ proc EXPORT
?_NV_areForcesAllTogether@CampaignInstance@@QEAA_NXZ endp

; CampaignInstance::areForcesAllTogether();
?areForcesAllTogether@CampaignInstance@@UEAA_NXZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+22*8]
?areForcesAllTogether@CampaignInstance@@UEAA_NXZ endp

?_NV_removeFromCampaign@CampaignInstance@@QEAAXPEAVPlatoon@@@Z proc EXPORT
?_NV_removeFromCampaign@CampaignInstance@@QEAAXPEAVPlatoon@@@Z endp

; CampaignInstance::removeFromCampaign(class Platoon *);
?removeFromCampaign@CampaignInstance@@UEAAXPEAVPlatoon@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+23*8]
?removeFromCampaign@CampaignInstance@@UEAAXPEAVPlatoon@@@Z endp

?_NV_getAITarget@CampaignInstance@@QEAA?AVTargetInfo@@PEAVPlatoon@@@Z proc EXPORT
?_NV_getAITarget@CampaignInstance@@QEAA?AVTargetInfo@@PEAVPlatoon@@@Z endp

; CampaignInstance::getAITarget(class Platoon *);
?getAITarget@CampaignInstance@@UEAA?AVTargetInfo@@PEAVPlatoon@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+24*8]
?getAITarget@CampaignInstance@@UEAA?AVTargetInfo@@PEAVPlatoon@@@Z endp

?_NV_getMoveSpeedUnloaded@CampaignInstance@@QEAA?AW4MoveSpeed@@XZ proc EXPORT
?_NV_getMoveSpeedUnloaded@CampaignInstance@@QEAA?AW4MoveSpeed@@XZ endp

; CampaignInstance::getMoveSpeedUnloaded();
?getMoveSpeedUnloaded@CampaignInstance@@UEAA?AW4MoveSpeed@@XZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+25*8]
?getMoveSpeedUnloaded@CampaignInstance@@UEAA?AW4MoveSpeed@@XZ endp

?_NV_getMoveSpeedLoaded@CampaignInstance@@QEAA?AW4MoveSpeed@@XZ proc EXPORT
?_NV_getMoveSpeedLoaded@CampaignInstance@@QEAA?AW4MoveSpeed@@XZ endp

; CampaignInstance::getMoveSpeedLoaded();
?getMoveSpeedLoaded@CampaignInstance@@UEAA?AW4MoveSpeed@@XZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+26*8]
?getMoveSpeedLoaded@CampaignInstance@@UEAA?AW4MoveSpeed@@XZ endp

?_NV_getTargetTown@CampaignInstance@@QEAA?AVhand@@XZ proc EXPORT
?_NV_getTargetTown@CampaignInstance@@QEAA?AVhand@@XZ endp

; CampaignInstance::getTargetTown();
?getTargetTown@CampaignInstance@@UEAA?AVhand@@XZ proc EXPORT
jmp function_pointers[_CampaignInstance_base+27*8]
?getTargetTown@CampaignInstance@@UEAA?AVhand@@XZ endp

?_NV_getDestination@CampaignInstance@@QEAA?AVVector3@Ogre@@PEAVPlatoon@@@Z proc EXPORT
?_NV_getDestination@CampaignInstance@@QEAA?AVVector3@Ogre@@PEAVPlatoon@@@Z endp

; CampaignInstance::getDestination(class Platoon *);
?getDestination@CampaignInstance@@UEAA?AVVector3@Ogre@@PEAVPlatoon@@@Z proc EXPORT
jmp function_pointers[_CampaignInstance_base+28*8]
?getDestination@CampaignInstance@@UEAA?AVVector3@Ogre@@PEAVPlatoon@@@Z endp
