
?_CONSTRUCTOR@AnimationEvents@@QEAAPEAV1@PEAVCharacter@@@Z proc EXPORT
?_CONSTRUCTOR@AnimationEvents@@QEAAPEAV1@PEAVCharacter@@@Z endp

; AnimationEvents::AnimationEvents(class Character *);
??0AnimationEvents@@QEAA@PEAVCharacter@@@Z proc EXPORT
jmp function_pointers[_AnimationEvents_base+0*8]
??0AnimationEvents@@QEAA@PEAVCharacter@@@Z endp

?_DESTRUCTOR@AnimationEvents@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@AnimationEvents@@QEAAXXZ endp

; AnimationEvents::~AnimationEvents();
??1AnimationEvents@@QEAA@XZ proc EXPORT
jmp function_pointers[_AnimationEvents_base+1*8]
??1AnimationEvents@@QEAA@XZ endp

; AnimationEvents::setInitialFrame(float);
?setInitialFrame@AnimationEvents@@QEAAXM@Z proc EXPORT
jmp function_pointers[_AnimationEvents_base+2*8]
?setInitialFrame@AnimationEvents@@QEAAXM@Z endp

; AnimationEvents::update(float, bool);
?update@AnimationEvents@@QEAAXM_N@Z proc EXPORT
jmp function_pointers[_AnimationEvents_base+3*8]
?update@AnimationEvents@@QEAAXM_N@Z endp

; AnimationEvents::addEvent(class AnimationEvent *, float);
?addEvent@AnimationEvents@@QEAAXPEAVAnimationEvent@@M@Z proc EXPORT
jmp function_pointers[_AnimationEvents_base+4*8]
?addEvent@AnimationEvents@@QEAAXPEAVAnimationEvent@@M@Z endp

; AnimationEvents::addEvent(class GameData *, float);
?addEvent@AnimationEvents@@QEAAXPEAVGameData@@M@Z proc EXPORT
jmp function_pointers[_AnimationEvents_base+5*8]
?addEvent@AnimationEvents@@QEAAXPEAVGameData@@M@Z endp

; AnimationEvents::addList(const class boost::unordered::unordered_map<GameData *,float,boost::hash<GameData *>,std::equal_to<GameData *>,Ogre::STLAllocator<std::pair<GameData * const,float>,Ogre::CategorisedAllocPolicy<0> > > *);
?addList@AnimationEvents@@QEAAXPEBV?$unordered_map@PEAVGameData@@MU?$hash@PEAVGameData@@@boost@@U?$equal_to@PEAVGameData@@@std@@V?$STLAllocator@U?$pair@QEAVGameData@@M@std@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@@Z proc EXPORT
jmp function_pointers[_AnimationEvents_base+6*8]
?addList@AnimationEvents@@QEAAXPEBV?$unordered_map@PEAVGameData@@MU?$hash@PEAVGameData@@@boost@@U?$equal_to@PEAVGameData@@@std@@V?$STLAllocator@U?$pair@QEAVGameData@@M@std@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@@Z endp

; AnimationEvents::addList(const class std::vector<GameDataReference,Ogre::STLAllocator<GameDataReference,Ogre::CategorisedAllocPolicy<0> > > *);
?addList@AnimationEvents@@QEAAXPEBV?$vector@VGameDataReference@@V?$STLAllocator@VGameDataReference@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@std@@@Z proc EXPORT
jmp function_pointers[_AnimationEvents_base+7*8]
?addList@AnimationEvents@@QEAAXPEBV?$vector@VGameDataReference@@V?$STLAllocator@VGameDataReference@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@std@@@Z endp

; AnimationEvents::size();
?size@AnimationEvents@@QEBAHXZ proc EXPORT
jmp function_pointers[_AnimationEvents_base+8*8]
?size@AnimationEvents@@QEBAHXZ endp
