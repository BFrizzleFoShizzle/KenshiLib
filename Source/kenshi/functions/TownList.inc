
?_CONSTRUCTOR@TownList@@QEAAPEAV1@XZ proc EXPORT
?_CONSTRUCTOR@TownList@@QEAAPEAV1@XZ endp

; TownList::TownList();
??0TownList@@QEAA@XZ proc EXPORT
jmp function_pointers[_TownList_base+0*8]
??0TownList@@QEAA@XZ endp

?_DESTRUCTOR@TownList@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@TownList@@QEAAXXZ endp

; TownList::~TownList();
??1TownList@@UEAA@XZ proc EXPORT
jmp function_pointers[_TownList_base+1*8]
??1TownList@@UEAA@XZ endp

?_NV_addActiveObject@TownList@@QEAA_NPEAVRootObject@@@Z proc EXPORT
?_NV_addActiveObject@TownList@@QEAA_NPEAVRootObject@@@Z endp

; TownList::addActiveObject(class RootObject *);
?addActiveObject@TownList@@UEAA_NPEAVRootObject@@@Z proc EXPORT
jmp function_pointers[_TownList_base+2*8]
?addActiveObject@TownList@@UEAA_NPEAVRootObject@@@Z endp

; TownList::updateTownCoverage(class TownBase *);
?updateTownCoverage@TownList@@QEAAXPEAVTownBase@@@Z proc EXPORT
jmp function_pointers[_TownList_base+3*8]
?updateTownCoverage@TownList@@QEAAXPEAVTownBase@@@Z endp

?_NV_getSelectedObjects@TownList@@QEAAXAEAV?$lektor@PEAVRootObject@@@@W4itemType@@_N@Z proc EXPORT
?_NV_getSelectedObjects@TownList@@QEAAXAEAV?$lektor@PEAVRootObject@@@@W4itemType@@_N@Z endp

; TownList::getSelectedObjects(class lektor<RootObject *> &, enum itemType, bool);
?getSelectedObjects@TownList@@UEAAXAEAV?$lektor@PEAVRootObject@@@@W4itemType@@_N@Z proc EXPORT
jmp function_pointers[_TownList_base+4*8]
?getSelectedObjects@TownList@@UEAAXAEAV?$lektor@PEAVRootObject@@@@W4itemType@@_N@Z endp

; TownList::_clearAll();
?_clearAll@TownList@@QEAAXXZ proc EXPORT
jmp function_pointers[_TownList_base+5*8]
?_clearAll@TownList@@QEAAXXZ endp

; TownList::_resetGame();
?_resetGame@TownList@@QEAAXXZ proc EXPORT
jmp function_pointers[_TownList_base+6*8]
?_resetGame@TownList@@QEAAXXZ endp

; TownList::destroyAllTheNests();
?destroyAllTheNests@TownList@@QEAAXXZ proc EXPORT
jmp function_pointers[_TownList_base+7*8]
?destroyAllTheNests@TownList@@QEAAXXZ endp

; TownList::destroy(class TownBase *);
?destroy@TownList@@QEAAXPEAVTownBase@@@Z proc EXPORT
jmp function_pointers[_TownList_base+8*8]
?destroy@TownList@@QEAAXPEAVTownBase@@@Z endp

; TownList::getTown(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?getTown@TownList@@QEAAPEAVTown@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc EXPORT
jmp function_pointers[_TownList_base+9*8]
?getTown@TownList@@QEAAPEAVTown@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; TownList::getTownsInArea(class lektor<Town *> &, class AreaSector *);
?getTownsInArea@TownList@@QEAAXAEAV?$lektor@PEAVTown@@@@PEAVAreaSector@@@Z proc EXPORT
jmp function_pointers[_TownList_base+10*8]
?getTownsInArea@TownList@@QEAAXAEAV?$lektor@PEAVTown@@@@PEAVAreaSector@@@Z endp

; TownList::getTownBySID(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?getTownBySID@TownList@@QEAAPEAVTown@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc EXPORT
jmp function_pointers[_TownList_base+11*8]
?getTownBySID@TownList@@QEAAPEAVTown@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; TownList::getNearestPlayerTown(const class Ogre::Vector3 &, bool, float);
?getNearestPlayerTown@TownList@@QEBAPEAVTown@@AEBVVector3@Ogre@@_NM@Z proc EXPORT
jmp function_pointers[_TownList_base+12*8]
?getNearestPlayerTown@TownList@@QEBAPEAVTown@@AEBVVector3@Ogre@@_NM@Z endp

; TownList::getNearestTown(const class Ogre::Vector3 &, class Faction *, class Town *, class Faction *, enum TownType);
?getNearestTown@TownList@@QEBAPEAVTown@@AEBVVector3@Ogre@@PEAVFaction@@PEAV2@1W4TownType@@@Z proc EXPORT
jmp function_pointers[_TownList_base+13*8]
?getNearestTown@TownList@@QEBAPEAVTown@@AEBVVector3@Ogre@@PEAVFaction@@PEAV2@1W4TownType@@@Z endp

; TownList::getNearestTownWithBuildingDesignation(enum BuildingDesignation, const class Ogre::Vector3 &, class Faction *, class Town *, class Faction *, enum TownType, float);
?getNearestTownWithBuildingDesignation@TownList@@QEAAPEAVTown@@W4BuildingDesignation@@AEBVVector3@Ogre@@PEAVFaction@@PEAV2@2W4TownType@@M@Z proc EXPORT
jmp function_pointers[_TownList_base+14*8]
?getNearestTownWithBuildingDesignation@TownList@@QEAAPEAVTown@@W4BuildingDesignation@@AEBVVector3@Ogre@@PEAVFaction@@PEAV2@2W4TownType@@M@Z endp

; TownList::getNearestNest(const class Ogre::Vector3 &, class Faction *, class TownBase *);
?getNearestNest@TownList@@QEBAPEAVNest@@AEBVVector3@Ogre@@PEAVFaction@@PEAVTownBase@@@Z proc EXPORT
jmp function_pointers[_TownList_base+15*8]
?getNearestNest@TownList@@QEBAPEAVNest@@AEBVVector3@Ogre@@PEAVFaction@@PEAVTownBase@@@Z endp

; TownList::getNearest(const class Ogre::Vector3 &, class Faction *, class TownBase *);
?getNearest@TownList@@QEBAPEAVTownBase@@AEBVVector3@Ogre@@PEAVFaction@@PEAV2@@Z proc EXPORT
jmp function_pointers[_TownList_base+16*8]
?getNearest@TownList@@QEBAPEAVTownBase@@AEBVVector3@Ogre@@PEAVFaction@@PEAV2@@Z endp

; TownList::getNearestWithinItsRadius(const class Ogre::Vector3 &, bool);
?getNearestWithinItsRadius@TownList@@QEBAPEAVTownBase@@AEBVVector3@Ogre@@_N@Z proc EXPORT
jmp function_pointers[_TownList_base+17*8]
?getNearestWithinItsRadius@TownList@@QEBAPEAVTownBase@@AEBVVector3@Ogre@@_N@Z endp

; TownList::getNearestInOrder(class lektor<TownBase *> &, class Ogre::Vector3, class Faction *, int, class TownBase *);
?getNearestInOrder@TownList@@QEAAXAEAV?$lektor@PEAVTownBase@@@@VVector3@Ogre@@PEAVFaction@@HPEAVTownBase@@@Z proc EXPORT
jmp function_pointers[_TownList_base+18*8]
?getNearestInOrder@TownList@@QEAAXAEAV?$lektor@PEAVTownBase@@@@VVector3@Ogre@@PEAVFaction@@HPEAVTownBase@@@Z endp

; TownList::getNearestInOrderWithResidentFaction(class lektor<TownBase *> &, class Ogre::Vector3, class Faction *, int, class TownBase *);
?getNearestInOrderWithResidentFaction@TownList@@QEAAXAEAV?$lektor@PEAVTownBase@@@@VVector3@Ogre@@PEAVFaction@@HPEAVTownBase@@@Z proc EXPORT
jmp function_pointers[_TownList_base+19*8]
?getNearestInOrderWithResidentFaction@TownList@@QEAAXAEAV?$lektor@PEAVTownBase@@@@VVector3@Ogre@@PEAVFaction@@HPEAVTownBase@@@Z endp

; TownList::getRetreatTown(const class Ogre::Vector3 &, class Faction *, class Town *);
?getRetreatTown@TownList@@QEAAPEAVTown@@AEBVVector3@Ogre@@PEAVFaction@@PEAV2@@Z proc EXPORT
jmp function_pointers[_TownList_base+20*8]
?getRetreatTown@TownList@@QEAAPEAVTown@@AEBVVector3@Ogre@@PEAVFaction@@PEAV2@@Z endp

; TownList::createNewPlayerTown(const class Ogre::Vector3 &);
?createNewPlayerTown@TownList@@QEAAPEAVTown@@AEBVVector3@Ogre@@@Z proc EXPORT
jmp function_pointers[_TownList_base+21*8]
?createNewPlayerTown@TownList@@QEAAPEAVTown@@AEBVVector3@Ogre@@@Z endp

; TownList::getDistToNearestTown(const class Ogre::Vector3 &, class Town *);
?getDistToNearestTown@TownList@@QEAAMAEBVVector3@Ogre@@PEAVTown@@@Z proc EXPORT
jmp function_pointers[_TownList_base+22*8]
?getDistToNearestTown@TownList@@QEAAMAEBVVector3@Ogre@@PEAVTown@@@Z endp

; TownList::getSquaredDistToNearestTown(const class Ogre::Vector3 &, class Town *);
?getSquaredDistToNearestTown@TownList@@QEAAMAEBVVector3@Ogre@@PEAVTown@@@Z proc EXPORT
jmp function_pointers[_TownList_base+23*8]
?getSquaredDistToNearestTown@TownList@@QEAAMAEBVVector3@Ogre@@PEAVTown@@@Z endp

; TownList::getNearishTown(class Faction *, const class Ogre::Vector3 &, class Faction *, class TownBase *, bool, unsigned int);
?getNearishTown@TownList@@QEAAPEAVTown@@PEAVFaction@@AEBVVector3@Ogre@@0PEAVTownBase@@_NI@Z proc EXPORT
jmp function_pointers[_TownList_base+24*8]
?getNearishTown@TownList@@QEAAPEAVTown@@PEAVFaction@@AEBVVector3@Ogre@@0PEAVTownBase@@_NI@Z endp

; TownList::getAllTowns();
?getAllTowns@TownList@@QEAAAEAV?$lektor@PEAVRootObject@@@@XZ proc EXPORT
jmp function_pointers[_TownList_base+25*8]
?getAllTowns@TownList@@QEAAAEAV?$lektor@PEAVRootObject@@@@XZ endp

; TownList::getAllTownsOf(class lektor<TownBase *> &, class Faction *);
?getAllTownsOf@TownList@@QEAAXAEAV?$lektor@PEAVTownBase@@@@PEAVFaction@@@Z proc EXPORT
jmp function_pointers[_TownList_base+26*8]
?getAllTownsOf@TownList@@QEAAXAEAV?$lektor@PEAVTownBase@@@@PEAVFaction@@@Z endp

; TownList::getAllTownsOf(class lektor<Town *> &, class Faction *);
?getAllTownsOf@TownList@@QEAAXAEAV?$lektor@PEAVTown@@@@PEAVFaction@@@Z proc EXPORT
jmp function_pointers[_TownList_base+27*8]
?getAllTownsOf@TownList@@QEAAXAEAV?$lektor@PEAVTown@@@@PEAVFaction@@@Z endp

; TownList::getAllTownsInBiome(class lektor<Town *> &, class AreaBiomeGroup *, enum TownType);
?getAllTownsInBiome@TownList@@QEAAXAEAV?$lektor@PEAVTown@@@@PEAVAreaBiomeGroup@@W4TownType@@@Z proc EXPORT
jmp function_pointers[_TownList_base+28*8]
?getAllTownsInBiome@TownList@@QEAAXAEAV?$lektor@PEAVTown@@@@PEAVAreaBiomeGroup@@W4TownType@@@Z endp

; TownList::getAllTowsByGameData(class lektor<Town *> &, class GameData *);
?getAllTowsByGameData@TownList@@QEAAXAEAV?$lektor@PEAVTown@@@@PEAVGameData@@@Z proc EXPORT
jmp function_pointers[_TownList_base+29*8]
?getAllTowsByGameData@TownList@@QEAAXAEAV?$lektor@PEAVTown@@@@PEAVGameData@@@Z endp

; TownList::getNullTown();
?getNullTown@TownList@@QEBAPEAVTownBase@@XZ proc EXPORT
jmp function_pointers[_TownList_base+30*8]
?getNullTown@TownList@@QEBAPEAVTownBase@@XZ endp

?_NV_update@TownList@@QEAA_NXZ proc EXPORT
?_NV_update@TownList@@QEAA_NXZ endp

; TownList::update();
?update@TownList@@UEAA_NXZ proc EXPORT
jmp function_pointers[_TownList_base+31*8]
?update@TownList@@UEAA_NXZ endp

; TownList::updateTownsDiscovery();
?updateTownsDiscovery@TownList@@QEAAXXZ proc EXPORT
jmp function_pointers[_TownList_base+32*8]
?updateTownsDiscovery@TownList@@QEAAXXZ endp

; TownList::setAllTownsDebugVisible(bool);
?setAllTownsDebugVisible@TownList@@QEAAX_N@Z proc EXPORT
jmp function_pointers[_TownList_base+33*8]
?setAllTownsDebugVisible@TownList@@QEAAX_N@Z endp

?_NV_saveToDisk@TownList@@QEAAX_NV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc EXPORT
?_NV_saveToDisk@TownList@@QEAAX_NV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; TownList::saveToDisk(bool, class std::basic_string<char,std::char_traits<char>,std::allocator<char> >);
?saveToDisk@TownList@@UEAAX_NV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc EXPORT
jmp function_pointers[_TownList_base+34*8]
?saveToDisk@TownList@@UEAAX_NV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_NV_loadFromDisk@TownList@@QEAA_N_NPEAVSerialisable@@@Z proc EXPORT
?_NV_loadFromDisk@TownList@@QEAA_N_NPEAVSerialisable@@@Z endp

; TownList::loadFromDisk(bool, class Serialisable *);
?loadFromDisk@TownList@@UEAA_N_NPEAVSerialisable@@@Z proc EXPORT
jmp function_pointers[_TownList_base+35*8]
?loadFromDisk@TownList@@UEAA_N_NPEAVSerialisable@@@Z endp

; TownList::saveState(class GameDataContainer *);
?saveState@TownList@@QEAAXPEAVGameDataContainer@@@Z proc EXPORT
jmp function_pointers[_TownList_base+36*8]
?saveState@TownList@@QEAAXPEAVGameDataContainer@@@Z endp

; TownList::loadState(class GameDataContainer *, bool);
?loadState@TownList@@QEAAXPEAVGameDataContainer@@_N@Z proc EXPORT
jmp function_pointers[_TownList_base+37*8]
?loadState@TownList@@QEAAXPEAVGameDataContainer@@_N@Z endp

; TownList::loadStateDiscovery(class GameDataContainer *, bool);
?loadStateDiscovery@TownList@@QEAAXPEAVGameDataContainer@@_N@Z proc EXPORT
jmp function_pointers[_TownList_base+38*8]
?loadStateDiscovery@TownList@@QEAAXPEAVGameDataContainer@@_N@Z endp

; TownList::loadLevelData(bool);
?loadLevelData@TownList@@QEAAX_N@Z proc EXPORT
jmp function_pointers[_TownList_base+39*8]
?loadLevelData@TownList@@QEAAX_N@Z endp

; TownList::_saveLevelData(class GameDataContainer *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?_saveLevelData@TownList@@QEAAXPEAVGameDataContainer@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc EXPORT
jmp function_pointers[_TownList_base+40*8]
?_saveLevelData@TownList@@QEAAXPEAVGameDataContainer@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; TownList::saveUniqueTownsAndNests(class GameDataContainer *);
?saveUniqueTownsAndNests@TownList@@QEAAXPEAVGameDataContainer@@@Z proc EXPORT
jmp function_pointers[_TownList_base+41*8]
?saveUniqueTownsAndNests@TownList@@QEAAXPEAVGameDataContainer@@@Z endp

; TownList::listUniqueTownsFromPlayerOwnership();
?listUniqueTownsFromPlayerOwnership@TownList@@QEAAXXZ proc EXPORT
jmp function_pointers[_TownList_base+42*8]
?listUniqueTownsFromPlayerOwnership@TownList@@QEAAXXZ endp

; TownList::loadAllTowns_worldInit(class GameDataContainer *);
?loadAllTowns_worldInit@TownList@@QEAAXPEAVGameDataContainer@@@Z proc EXPORT
jmp function_pointers[_TownList_base+43*8]
?loadAllTowns_worldInit@TownList@@QEAAXPEAVGameDataContainer@@@Z endp

; TownList::addNest(class RootObject *);
?addNest@TownList@@QEAAXPEAVRootObject@@@Z proc EXPORT
jmp function_pointers[_TownList_base+44*8]
?addNest@TownList@@QEAAXPEAVRootObject@@@Z endp

; TownList::reassessTownPositions(class TownBase *);
?reassessTownPositions@TownList@@QEAAXPEAVTownBase@@@Z proc EXPORT
jmp function_pointers[_TownList_base+45*8]
?reassessTownPositions@TownList@@QEAAXPEAVTownBase@@@Z endp

; TownList::getActiveTowns();
?getActiveTowns@TownList@@QEBAAEBV?$unordered_set@PEAVTownBase@@U?$hash@PEAVTownBase@@@boost@@U?$equal_to@PEAVTownBase@@@std@@V?$STLAllocator@PEAVTownBase@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@XZ proc EXPORT
jmp function_pointers[_TownList_base+46*8]
?getActiveTowns@TownList@@QEBAAEBV?$unordered_set@PEAVTownBase@@U?$hash@PEAVTownBase@@@boost@@U?$equal_to@PEAVTownBase@@@std@@V?$STLAllocator@PEAVTownBase@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@XZ endp

; TownList::mergePlayerTowns(class Town *, class Town *);
?mergePlayerTowns@TownList@@QEAAXPEAVTown@@0@Z proc EXPORT
jmp function_pointers[_TownList_base+47*8]
?mergePlayerTowns@TownList@@QEAAXPEAVTown@@0@Z endp

; TownList::_getNearest(const class iVector2 &, class TownBase * &, float &, const class Ogre::Vector3 &, bool);
?_getNearest@TownList@@QEBAXAEBViVector2@@AEAPEAVTownBase@@AEAMAEBVVector3@Ogre@@_N@Z proc EXPORT
jmp function_pointers[_TownList_base+48*8]
?_getNearest@TownList@@QEBAXAEBViVector2@@AEAPEAVTownBase@@AEAMAEBVVector3@Ogre@@_N@Z endp
