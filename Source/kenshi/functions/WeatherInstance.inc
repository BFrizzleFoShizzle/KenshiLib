
?_CONSTRUCTOR@WeatherInstance@@QEAAPEAV1@PEAVWeatherRegion@@@Z proc EXPORT
?_CONSTRUCTOR@WeatherInstance@@QEAAPEAV1@PEAVWeatherRegion@@@Z endp

; WeatherInstance::WeatherInstance(class WeatherRegion *);
??0WeatherInstance@@QEAA@PEAVWeatherRegion@@@Z proc EXPORT
jmp function_pointers[_WeatherInstance_base+0*8]
??0WeatherInstance@@QEAA@PEAVWeatherRegion@@@Z endp

?_DESTRUCTOR@WeatherInstance@@QEAAXXZ proc EXPORT
?_DESTRUCTOR@WeatherInstance@@QEAAXXZ endp

; WeatherInstance::~WeatherInstance();
??1WeatherInstance@@QEAA@XZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+1*8]
??1WeatherInstance@@QEAA@XZ endp

; WeatherInstance::getTime();
?getTime@WeatherInstance@@QEBAAEBMXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+2*8]
?getTime@WeatherInstance@@QEBAAEBMXZ endp

; WeatherInstance::getTimeNormalized();
?getTimeNormalized@WeatherInstance@@QEBAMXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+3*8]
?getTimeNormalized@WeatherInstance@@QEBAMXZ endp

; WeatherInstance::getWeatherBiome();
?getWeatherBiome@WeatherInstance@@QEBAPEAVWeatherRegion@@XZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+4*8]
?getWeatherBiome@WeatherInstance@@QEBAPEAVWeatherRegion@@XZ endp

; WeatherInstance::getWeather();
?getWeather@WeatherInstance@@QEBAPEAVWeather@@XZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+5*8]
?getWeather@WeatherInstance@@QEBAPEAVWeather@@XZ endp

; WeatherInstance::update();
?update@WeatherInstance@@QEAA_NXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+6*8]
?update@WeatherInstance@@QEAA_NXZ endp

; WeatherInstance::getHasEnded();
?getHasEnded@WeatherInstance@@QEBA_NXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+7*8]
?getHasEnded@WeatherInstance@@QEBA_NXZ endp

; WeatherInstance::getFogVisible();
?getFogVisible@WeatherInstance@@QEBA_NXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+8*8]
?getFogVisible@WeatherInstance@@QEBA_NXZ endp

; WeatherInstance::getFogDistance();
?getFogDistance@WeatherInstance@@QEBAMXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+9*8]
?getFogDistance@WeatherInstance@@QEBAMXZ endp

; WeatherInstance::getFogColour();
?getFogColour@WeatherInstance@@QEBAAEBVColourValue@Ogre@@XZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+10*8]
?getFogColour@WeatherInstance@@QEBAAEBVColourValue@Ogre@@XZ endp

; WeatherInstance::getFogEnabled();
?getFogEnabled@WeatherInstance@@QEBA_NXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+11*8]
?getFogEnabled@WeatherInstance@@QEBA_NXZ endp

; WeatherInstance::getGlobalEffectsStrength();
?getGlobalEffectsStrength@WeatherInstance@@QEBAMXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+12*8]
?getGlobalEffectsStrength@WeatherInstance@@QEBAMXZ endp

; WeatherInstance::getWindSpeed();
?getWindSpeed@WeatherInstance@@QEBAMXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+13*8]
?getWindSpeed@WeatherInstance@@QEBAMXZ endp

; WeatherInstance::getWindDirection();
?getWindDirection@WeatherInstance@@QEBAAEBVVector3@Ogre@@XZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+14*8]
?getWindDirection@WeatherInstance@@QEBAAEBVVector3@Ogre@@XZ endp

; WeatherInstance::getWindForce();
?getWindForce@WeatherInstance@@QEBA?AVVector3@Ogre@@XZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+15*8]
?getWindForce@WeatherInstance@@QEBA?AVVector3@Ogre@@XZ endp

; WeatherInstance::getWetness();
?getWetness@WeatherInstance@@QEBAMXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+16*8]
?getWetness@WeatherInstance@@QEBAMXZ endp

; WeatherInstance::getWeatherStrength();
?getWeatherStrength@WeatherInstance@@QEBAMXZ proc EXPORT
jmp function_pointers[_WeatherInstance_base+17*8]
?getWeatherStrength@WeatherInstance@@QEBAMXZ endp

; WeatherInstance::save(class GameData *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?save@WeatherInstance@@QEAAXPEAVGameData@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc EXPORT
jmp function_pointers[_WeatherInstance_base+18*8]
?save@WeatherInstance@@QEAAXPEAVGameData@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; WeatherInstance::load(class GameData *, class Weather *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?load@WeatherInstance@@QEAAXPEAVGameData@@PEAVWeather@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc EXPORT
jmp function_pointers[_WeatherInstance_base+19*8]
?load@WeatherInstance@@QEAAXPEAVGameData@@PEAVWeather@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; WeatherInstance::setupWeather(class Weather *);
?setupWeather@WeatherInstance@@QEAAXPEAVWeather@@@Z proc EXPORT
jmp function_pointers[_WeatherInstance_base+20*8]
?setupWeather@WeatherInstance@@QEAAXPEAVWeather@@@Z endp
