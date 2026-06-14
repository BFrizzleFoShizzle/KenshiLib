
?_CONSTRUCTOR@RangedCombatClass@@QEAAPEAV1@PEAVCharacter@@@Z proc EXPORT
?_CONSTRUCTOR@RangedCombatClass@@QEAAPEAV1@PEAVCharacter@@@Z endp

; RangedCombatClass::RangedCombatClass(class Character *);
??0RangedCombatClass@@QEAA@PEAVCharacter@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+0*8]
??0RangedCombatClass@@QEAA@PEAVCharacter@@@Z endp

; RangedCombatClass::setState(enum RangedCombatClass::RangedState);
?setState@RangedCombatClass@@QEAAXW4RangedState@1@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+1*8]
?setState@RangedCombatClass@@QEAAXW4RangedState@1@@Z endp

; RangedCombatClass::setup(class TurretBuilding *, enum StatsEnumerated);
?setup@RangedCombatClass@@QEAAXPEAVTurretBuilding@@W4StatsEnumerated@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+2*8]
?setup@RangedCombatClass@@QEAAXPEAVTurretBuilding@@W4StatsEnumerated@@@Z endp

; RangedCombatClass::getGun();
?getGun@RangedCombatClass@@QEAAPEAVGunClass@@XZ proc EXPORT
jmp function_pointers[_RangedCombatClass_base+3*8]
?getGun@RangedCombatClass@@QEAAPEAVGunClass@@XZ endp

; RangedCombatClass::isInRangedCombatMode();
?isInRangedCombatMode@RangedCombatClass@@QEBA_NXZ proc EXPORT
jmp function_pointers[_RangedCombatClass_base+4*8]
?isInRangedCombatMode@RangedCombatClass@@QEBA_NXZ endp

; RangedCombatClass::updateT(float, const class hand &, const class hand &);
?updateT@RangedCombatClass@@QEAAXMAEBVhand@@0@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+5*8]
?updateT@RangedCombatClass@@QEAAXMAEBVhand@@0@Z endp

; RangedCombatClass::updateMT(float);
?updateMT@RangedCombatClass@@QEAAXM@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+6*8]
?updateMT@RangedCombatClass@@QEAAXM@Z endp

; RangedCombatClass::end();
?end@RangedCombatClass@@QEAAXXZ proc EXPORT
jmp function_pointers[_RangedCombatClass_base+7*8]
?end@RangedCombatClass@@QEAAXXZ endp

; RangedCombatClass::_getAttackTarget();
?_getAttackTarget@RangedCombatClass@@QEBA?AVhand@@XZ proc EXPORT
jmp function_pointers[_RangedCombatClass_base+8*8]
?_getAttackTarget@RangedCombatClass@@QEBA?AVhand@@XZ endp

; RangedCombatClass::scoreTargetRange(const class Ogre::Vector3 &, const class Ogre::Vector3 &, float, float);
?scoreTargetRange@RangedCombatClass@@SAMAEBVVector3@Ogre@@0MM@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+9*8]
?scoreTargetRange@RangedCombatClass@@SAMAEBVVector3@Ogre@@0MM@Z endp

; RangedCombatClass::printGUIState(class DatapanelGUI *, int);
?printGUIState@RangedCombatClass@@QEAAXPEAVDatapanelGUI@@H@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+10*8]
?printGUIState@RangedCombatClass@@QEAAXPEAVDatapanelGUI@@H@Z endp

; RangedCombatClass::isInRange(const class Ogre::Vector3 &);
?isInRange@RangedCombatClass@@QEBA_NAEBVVector3@Ogre@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+11*8]
?isInRange@RangedCombatClass@@QEBA_NAEBVVector3@Ogre@@@Z endp

; RangedCombatClass::getGunRange(const class Ogre::Vector3 &);
?getGunRange@RangedCombatClass@@QEBAMAEBVVector3@Ogre@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+12*8]
?getGunRange@RangedCombatClass@@QEBAMAEBVVector3@Ogre@@@Z endp

; RangedCombatClass::animationUpdate(float, const class Ogre::Vector3 &, class RootObject *);
?animationUpdate@RangedCombatClass@@QEAAXMAEBVVector3@Ogre@@PEAVRootObject@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+13*8]
?animationUpdate@RangedCombatClass@@QEAAXMAEBVVector3@Ogre@@PEAVRootObject@@@Z endp

; RangedCombatClass::reloadCheck();
?reloadCheck@RangedCombatClass@@QEAA_NXZ proc EXPORT
jmp function_pointers[_RangedCombatClass_base+14*8]
?reloadCheck@RangedCombatClass@@QEAA_NXZ endp

; RangedCombatClass::takeTheShotCheck(class Character *);
?takeTheShotCheck@RangedCombatClass@@QEAA?AVYesNoMaybe@@PEAVCharacter@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+15*8]
?takeTheShotCheck@RangedCombatClass@@QEAA?AVYesNoMaybe@@PEAVCharacter@@@Z endp

; RangedCombatClass::aimAtTarget(const class Ogre::Vector3 &);
?aimAtTarget@RangedCombatClass@@QEAAXAEBVVector3@Ogre@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+16*8]
?aimAtTarget@RangedCombatClass@@QEAAXAEBVVector3@Ogre@@@Z endp

; RangedCombatClass::getAimPos(class Character *);
?getAimPos@RangedCombatClass@@QEAA?AVVector3@Ogre@@PEAVCharacter@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+17*8]
?getAimPos@RangedCombatClass@@QEAA?AVVector3@Ogre@@PEAVCharacter@@@Z endp

; RangedCombatClass::chooseNewTarget(class Character *);
?chooseNewTarget@RangedCombatClass@@QEAAPEAVCharacter@@PEAV2@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+18*8]
?chooseNewTarget@RangedCombatClass@@QEAAPEAVCharacter@@PEAV2@@Z endp

; RangedCombatClass::setTarget(class Character *);
?setTarget@RangedCombatClass@@QEAAXPEAVCharacter@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+19*8]
?setTarget@RangedCombatClass@@QEAAXPEAVCharacter@@@Z endp

; RangedCombatClass::scoreTarget(class Character *, float);
?scoreTarget@RangedCombatClass@@QEAAMPEAVCharacter@@M@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+20*8]
?scoreTarget@RangedCombatClass@@QEAAMPEAVCharacter@@M@Z endp

; RangedCombatClass::resetShotTimer();
?resetShotTimer@RangedCombatClass@@QEAAXXZ proc EXPORT
jmp function_pointers[_RangedCombatClass_base+21*8]
?resetShotTimer@RangedCombatClass@@QEAAXXZ endp

; RangedCombatClass::traceHitFurtherThanTarget(const class physHit &, const class Ogre::Vector3 &);
?traceHitFurtherThanTarget@RangedCombatClass@@QEAA_NAEBVphysHit@@AEBVVector3@Ogre@@@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+22*8]
?traceHitFurtherThanTarget@RangedCombatClass@@QEAA_NAEBVphysHit@@AEBVVector3@Ogre@@@Z endp

; RangedCombatClass::reAssessTargeting(const class hand &, const class hand &);
?reAssessTargeting@RangedCombatClass@@QEAAPEAVCharacter@@AEBVhand@@0@Z proc EXPORT
jmp function_pointers[_RangedCombatClass_base+23*8]
?reAssessTargeting@RangedCombatClass@@QEAAPEAVCharacter@@AEBVhand@@0@Z endp
