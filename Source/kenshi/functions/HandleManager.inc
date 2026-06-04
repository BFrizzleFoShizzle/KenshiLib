
?_CONSTRUCTOR@HandleManager@@QEAAPEAV1@XZ proc EXPORT
?_CONSTRUCTOR@HandleManager@@QEAAPEAV1@XZ endp

; HandleManager::HandleManager();
??0HandleManager@@QEAA@XZ proc EXPORT
jmp function_pointers[_HandleManager_base+0*8]
??0HandleManager@@QEAA@XZ endp

?_DESTRUCTOR@HandleManager@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@HandleManager@@QEAAXXZ endp

; HandleManager::~HandleManager();
??1HandleManager@@QEAA@XZ proc EXPORT
jmp function_pointers[_HandleManager_base+1*8]
??1HandleManager@@QEAA@XZ endp

?_NV_serialise@HandleManager@@QEAAXAEAV?$basic_ofstream@DU?$char_traits@D@std@@@std@@@Z proc EXPORT
?_NV_serialise@HandleManager@@QEAAXAEAV?$basic_ofstream@DU?$char_traits@D@std@@@std@@@Z endp

; HandleManager::serialise(class std::basic_ofstream<char,std::char_traits<char> > &);
?serialise@HandleManager@@UEAAXAEAV?$basic_ofstream@DU?$char_traits@D@std@@@std@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+2*8]
?serialise@HandleManager@@UEAAXAEAV?$basic_ofstream@DU?$char_traits@D@std@@@std@@@Z endp

?_NV_restore@HandleManager@@QEAAXAEAV?$basic_ifstream@DU?$char_traits@D@std@@@std@@@Z proc EXPORT
?_NV_restore@HandleManager@@QEAAXAEAV?$basic_ifstream@DU?$char_traits@D@std@@@std@@@Z endp

; HandleManager::restore(class std::basic_ifstream<char,std::char_traits<char> > &);
?restore@HandleManager@@UEAAXAEAV?$basic_ifstream@DU?$char_traits@D@std@@@std@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+3*8]
?restore@HandleManager@@UEAAXAEAV?$basic_ifstream@DU?$char_traits@D@std@@@std@@@Z endp

; HandleManager::getRedirect(const class hand &);
?getRedirect@HandleManager@@QEBAAEBVhand@@AEBV2@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+4*8]
?getRedirect@HandleManager@@QEBAAEBVhand@@AEBV2@@Z endp

; HandleManager::removeRedirect(const class hand &);
?removeRedirect@HandleManager@@QEAAXAEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+5*8]
?removeRedirect@HandleManager@@QEAAXAEBVhand@@@Z endp

; HandleManager::clearRedirectForHandle(const class hand &);
?clearRedirectForHandle@HandleManager@@QEAAXAEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+6*8]
?clearRedirectForHandle@HandleManager@@QEAAXAEBVhand@@@Z endp

; HandleManager::reset();
?reset@HandleManager@@QEAAXXZ proc EXPORT
jmp function_pointers[_HandleManager_base+7*8]
?reset@HandleManager@@QEAAXXZ endp

; HandleManager::setUnloaded(const class hand &);
?setUnloaded@HandleManager@@QEAAXAEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+8*8]
?setUnloaded@HandleManager@@QEAAXAEBVhand@@@Z endp

; HandleManager::destroy(const class hand &, const char *);
?destroy@HandleManager@@QEAAXAEBVhand@@PEBD@Z proc EXPORT
jmp function_pointers[_HandleManager_base+9*8]
?destroy@HandleManager@@QEAAXAEBVhand@@PEBD@Z endp

; HandleManager::getAnything(const class hand &, bool);
?getAnything@HandleManager@@QEAAPEAVRootObjectBase@@AEBVhand@@_N@Z proc EXPORT
jmp function_pointers[_HandleManager_base+10*8]
?getAnything@HandleManager@@QEAAPEAVRootObjectBase@@AEBVhand@@_N@Z endp

; HandleManager::getTownBase(const class hand &, const class Ogre::Vector3 &);
?getTownBase@HandleManager@@QEBAPEAVTownBase@@AEBVhand@@AEBVVector3@Ogre@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+11*8]
?getTownBase@HandleManager@@QEBAPEAVTownBase@@AEBVhand@@AEBVVector3@Ogre@@@Z endp

; HandleManager::getTown(const class hand &, const class Ogre::Vector3 &);
?getTown@HandleManager@@QEBAPEAVTown@@AEBVhand@@AEBVVector3@Ogre@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+12*8]
?getTown@HandleManager@@QEBAPEAVTown@@AEBVhand@@AEBVVector3@Ogre@@@Z endp

; HandleManager::getAnythingButBase(const class hand &, bool);
?getAnythingButBase@HandleManager@@QEAAPEAVRootObject@@AEBVhand@@_N@Z proc EXPORT
jmp function_pointers[_HandleManager_base+13*8]
?getAnythingButBase@HandleManager@@QEAAPEAVRootObject@@AEBVhand@@_N@Z endp

; HandleManager::getShopTrader(const class hand &);
?getShopTrader@HandleManager@@QEAAPEAVCharacter@@AEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+14*8]
?getShopTrader@HandleManager@@QEAAPEAVCharacter@@AEBVhand@@@Z endp

; HandleManager::getBuilding(const class hand &);
?getBuilding@HandleManager@@QEAAPEAVBuilding@@AEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+15*8]
?getBuilding@HandleManager@@QEAAPEAVBuilding@@AEBVhand@@@Z endp

; HandleManager::getBuilding_UseableStuff(const class hand &);
?getBuilding_UseableStuff@HandleManager@@QEAAPEAVUseableStuff@@AEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+16*8]
?getBuilding_UseableStuff@HandleManager@@QEAAPEAVUseableStuff@@AEBVhand@@@Z endp

; HandleManager::getCharacter(const class hand &, bool, bool);
?getCharacter@HandleManager@@QEAAPEAVCharacter@@AEBVhand@@_N1@Z proc EXPORT
jmp function_pointers[_HandleManager_base+17*8]
?getCharacter@HandleManager@@QEAAPEAVCharacter@@AEBVhand@@_N1@Z endp

; HandleManager::getPlatoon(const class hand &);
?getPlatoon@HandleManager@@QEAAPEAVPlatoon@@AEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+18*8]
?getPlatoon@HandleManager@@QEAAPEAVPlatoon@@AEBVhand@@@Z endp

; HandleManager::getItem(const class hand &);
?getItem@HandleManager@@QEAAPEAVItem@@AEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+19*8]
?getItem@HandleManager@@QEAAPEAVItem@@AEBVhand@@@Z endp

; HandleManager::isPlayerFaction(const class hand &);
?isPlayerFaction@HandleManager@@QEAA_NAEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+20*8]
?isPlayerFaction@HandleManager@@QEAA_NAEBVhand@@@Z endp

; HandleManager::addExistingObjectHandleToZone(class hand &);
?addExistingObjectHandleToZone@HandleManager@@QEAA_NAEAVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+21*8]
?addExistingObjectHandleToZone@HandleManager@@QEAA_NAEAVhand@@@Z endp

; HandleManager::getFromDeathParade(const class hand &);
?getFromDeathParade@HandleManager@@QEAAPEAVCharacter@@AEBVhand@@@Z proc EXPORT
jmp function_pointers[_HandleManager_base+22*8]
?getFromDeathParade@HandleManager@@QEAAPEAVCharacter@@AEBVhand@@@Z endp
