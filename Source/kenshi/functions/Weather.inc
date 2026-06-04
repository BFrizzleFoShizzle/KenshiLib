
?_CONSTRUCTOR@Weather@@QEAAPEAV1@PEAVGameData@@PEAVSeason@@MHH@Z proc EXPORT
?_CONSTRUCTOR@Weather@@QEAAPEAV1@PEAVGameData@@PEAVSeason@@MHH@Z endp

; Weather::Weather(class GameData *, class Season *, float, int, int);
??0Weather@@QEAA@PEAVGameData@@PEAVSeason@@MHH@Z proc EXPORT
jmp function_pointers[_Weather_base+0*8]
??0Weather@@QEAA@PEAVGameData@@PEAVSeason@@MHH@Z endp

?_DESTRUCTOR@Weather@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@Weather@@QEAAXXZ endp

; Weather::~Weather();
??1Weather@@QEAA@XZ proc EXPORT
jmp function_pointers[_Weather_base+1*8]
??1Weather@@QEAA@XZ endp

; Weather::getName();
?getName@Weather@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc EXPORT
jmp function_pointers[_Weather_base+2*8]
?getName@Weather@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp
