#pragma once

#include <ogre/OgreColourValue.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreVector4.h>
#include "util/lektor.h"
#include "util/TripleInt.h"
#include "Enums.h"

class GameData;
class WeatherRegion;
class Weather;

class WeatherInstance : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    WeatherInstance(WeatherRegion* region);// public RVA = 0x9DA750
    WeatherInstance* _CONSTRUCTOR(WeatherRegion* region);// public RVA = 0x9DA750
    ~WeatherInstance();// public RVA = 0x9DA7C0
    void _DESTRUCTOR();// public RVA = 0x9DA7C0
    const float& getTime() const;// public RVA = 0x9DA7E0
    float getTimeNormalized() const;// public RVA = 0x9DA7F0
    WeatherRegion* getWeatherBiome() const;// public RVA = 0x9DA850
    Weather* getWeather() const;// public RVA = 0x9DA860
    bool update();// public RVA = 0x9DA930
    bool getHasEnded() const;// public RVA = 0x9DA870
    bool getFogVisible() const;// public RVA = 0x9DA8C0
    float getFogDistance() const;// public RVA = 0x9DABA0
    const Ogre::ColourValue& getFogColour() const;// public RVA = 0x9DA8D0
    bool getFogEnabled() const;// public RVA = 0x9DA8E0
    float getGlobalEffectsStrength() const;// public RVA = 0x9DA8F0
    float getWindSpeed() const;// public RVA = 0x406820
    const Ogre::Vector3& getWindDirection() const;// public RVA = 0x406830
    Ogre::Vector3 getWindForce() const;// public RVA = 0x100940
    float getWetness() const;// public RVA = 0xDECD0
    float getWeatherStrength() const;// public RVA = 0x5C6DE0
    void save(GameData* data, const std::string& key);// public RVA = 0x9DBAA0
    void load(GameData* data, Weather* newWeather, const std::string& key);// public RVA = 0x9DBE30
    void setupWeather(Weather* newWeather);// private RVA = 0x9DB7B0
    WeatherRegion* regionWeather; // 0x0 Member
    Weather* weather; // 0x8 Member
    float effectStrength; // 0x10 Member
    float strength; // 0x14 Member
    float windSpeed; // 0x18 Member
    Ogre::Vector3 windDirection; // 0x1C Member
    bool windBuildUpEnded; // 0x28 Member
    int windBuildUpStart; // 0x2C Member
    int windBuildUpEnd; // 0x30 Member
    float windBuildUpSpeedStart; // 0x34 Member
    float windBuildUpSpeedEnd; // 0x38 Member
    float windBuildUpAngleStart; // 0x3C Member
    float windBuildUpAngleEnd; // 0x40 Member
    int startTimeMinutes; // 0x44 Member
    int endTimeMinutes; // 0x48 Member
    int updateTimeWindMinutes; // 0x4C Member
    float weatherTime; // 0x50 Member
    // no_addr class WeatherInstance & operator=(const class WeatherInstance & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class AreaBiomeGroup;
class EffectGroup;
class Season;

class WeatherRegion : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    class Listener
    {
    public:
        // VTable         : (none)
        virtual void weatherUpdated(WeatherInstance* _a1, bool _a2) = 0;// public vtable offset = 0x0 missing arg names
        // no_addr void Listener(const class WeatherRegion::Listener & _a1);// public missing arg names
        Listener();// public RVA = 0xFCCB0
        Listener* _CONSTRUCTOR();// public RVA = 0xFCCB0
        // no_addr class WeatherRegion::Listener & operator=(const class WeatherRegion::Listener & _a1);// public missing arg names
    };
    // Typedef        : WeatherListenerList
    // no_addr void WeatherRegion(const class WeatherRegion & _a1);// public missing arg names
    WeatherRegion(AreaBiomeGroup* biomeGroup);// public RVA = 0x9DE120
    WeatherRegion* _CONSTRUCTOR(AreaBiomeGroup* biomeGroup);// public RVA = 0x9DE120
    ~WeatherRegion();// public RVA = 0x9DB070
    void _DESTRUCTOR();// public RVA = 0x9DB070
    void reset();// public RVA = 0x9DCED0
    WeatherInstance* getWeatherInstance() const;// public RVA = 0x9DA920
    void setCurrentSeason(int seasonIndex, int seasonEnd);// public RVA = 0x9DAC10
    // no_addr class Season * getCurrentSeason();// public
    float getNewWeatherStrength() const;// public RVA = 0x9DAC30
    void update();// public RVA = 0x9DAD30
    void updateBT();// public RVA = 0x9DC6A0
    void addListener(WeatherRegion::Listener* listener);// public RVA = 0x9DB310
    void removeListener(WeatherRegion::Listener* listener);// public RVA = 0x9DAEB0
    void addGlobalEffect(EffectType::Enum type);// public RVA = 0x9DB6F0
    void getNewSeason();// private RVA = 0x9DC640
    void weatherChanged(bool newWeather);// private RVA = 0x9DACB0
    void updateWeatherEffects();// private RVA = 0x9DB340
    void save(GameData* data, const std::string& key);// private RVA = 0x9DC830
    void load(GameData* data, const std::string& key);// private RVA = 0x9DCA50
    AreaBiomeGroup* biomeGroup; // 0x0 Member
    Ogre::vector<Season*>::type seasons; // 0x8 Member
    float weatherStrengthMultiplierMin; // 0x28 Member
    float weatherStrengthMultiplierMax; // 0x2C Member
    WeatherInstance* weatherInstance; // 0x30 Member
    Season* currentSeason; // 0x38 Member
    int currentSeasonIndex; // 0x40 Member
    int currentSeasonEndDay; // 0x44 Member
    Ogre::vector<WeatherRegion::Listener*>::type listeners; // 0x48 Member
    bool biomeGroupLoaded; // 0x68 Member
    bool requestUpdateEffects; // 0x69 Member
    Ogre::vector<EffectGroup*>::type effects; // 0x70 Member
    std::vector<std::pair<EffectType::Enum, float>, Ogre::STLAllocator<std::pair<EffectType::Enum, float>, Ogre::GeneralAllocPolicy > > activeGlobalEffects; // 0x90 Member
    bool activeCameraBiome; // 0xB0 Member
    bool weatherUpdated; // 0xB1 Member
    bool instanceUpdated; // 0xB2 Member
    // no_addr class WeatherRegion & operator=(const class WeatherRegion & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class Weather;

// TODO move?
class Season : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void Season(const class Season & _a1);// public missing arg names
    Season(WeatherRegion* region, GameData* seasonData, int duration);// public RVA = 0x9DDA90
    Season* _CONSTRUCTOR(WeatherRegion* region, GameData* seasonData, int duration);// public RVA = 0x9DDA90
    ~Season();// public RVA = 0x9DAF70
    void _DESTRUCTOR();// public RVA = 0x9DAF70
    const std::string& getName() const;// public RVA = 0x9DA900
    void getNewWeather();// public RVA = 0x9DC1D0
    WeatherRegion* regionWeather; // 0x0 Member
    lektor<Weather*> weathers; // 0x8 Member
    bool hasConditionalWeather; // 0x20 Member
    int durationInDays; // 0x24 Member
    float weatherStrengthMin; // 0x28 Member
    float weatherStrengthMax; // 0x2C Member
    Ogre::ColourValue sunlightColor; // 0x30 Member
    GameData* seasonData; // 0x40 Member
    // no_addr class Season & operator=(const class Season & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class Weather : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // Typedef        : WeatherEffectsList
    // no_addr void Weather(const class Weather & _a1);// public missing arg names
    Weather(GameData* data, Season* season, float probOccurence, int minDuration, int maxDuration);// public RVA = 0x9DD000
    Weather* _CONSTRUCTOR(GameData* data, Season* season, float probOccurence, int minDuration, int maxDuration);// public RVA = 0x9DD000
    ~Weather();// public RVA = 0x9DAF00
    void _DESTRUCTOR();// public RVA = 0x9DAF00
    const std::string& getName() const;// public RVA = 0x9DA740
    WeatherAffecting affectCharactersType; // 0x0 Member
    float affectCharactersStrength; // 0x4 Member
    GameData* weatherData; // 0x8 Member
    std::vector<std::pair<GameData*, TripleInt>, Ogre::STLAllocator<std::pair<GameData*, TripleInt>, Ogre::GeneralAllocPolicy > > effects; // 0x10 Member
    float windSpeedMin; // 0x30 Member
    float windSpeedMax; // 0x34 Member
    int windUpdateTime; // 0x38 Member
    int windUpdateLimit; // 0x3C Member
    bool fogEnabled; // 0x40 Member
    float fogDistanceMin; // 0x44 Member
    float fogDistanceMax; // 0x48 Member
    float fogWindSpeedMin; // 0x4C Member
    float fogWindSpeedMax; // 0x50 Member
    Ogre::ColourValue fogColor; // 0x54 Member
    float cloudsDensity; // 0x64 Member
    Ogre::ColourValue cloudsColor; // 0x68 Member
    float probabilityOccurrence; // 0x78 Member
    float conditionStart; // 0x7C Member
    float conditionEnd; // 0x80 Member
    int durationMin; // 0x84 Member
    int durationMax; // 0x88 Member
    float rainSound; // 0x8C Member
    float windSound; // 0x90 Member
    float wetness; // 0x94 Member
    float dust; // 0x98 Member
    float dustInside; // 0x9C Member
    float dustSticky; // 0xA0 Member
    float heatHaze; // 0xA4 Member
    Season* season; // 0xA8 Member
    // no_addr class Weather & operator=(const class Weather & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class EffectHandler;
class MainFog;
class AreaSector;

class WeatherSystem : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    ~WeatherSystem();// public RVA = 0x9E83D0
    void _DESTRUCTOR();// public RVA = 0x9E83D0
    static WeatherSystem* getInstance();// public RVA = 0xF89A0
    void destroy();// public RVA = 0x9E8880
    void reset();// public RVA = 0x9E9060
    void updateMT();// public RVA = 0x9E8C60
    void updateBT();// public RVA = 0x9E77C0
    void updateUT();// public RVA = 0x9E75F0
    void addWeatherListener(const Ogre::Vector3& position, WeatherRegion::Listener* listener);// public RVA = 0x9E8AE0
    void addWeatherListener(GameData* biome, WeatherRegion::Listener* listener);// public RVA = 0x9E88B0
    void removeWeatherListener(WeatherRegion::Listener* listener);// public RVA = 0x9E82C0
    const std::vector<std::pair<EffectType::Enum, float>, Ogre::STLAllocator<std::pair<EffectType::Enum, float>, Ogre::GeneralAllocPolicy > >& getPositionGlobalEffects(const Ogre::Vector3& position) const;// public RVA = 0x9E7600
    void addWeatherEffect(EffectHandler* effect);// public RVA = 0x9E8360
    void removeWeatherEffect(EffectHandler* effect);// public RVA = 0x9E83A0
    void setDustShaderValue(const Ogre::Vector3& value);// public RVA = 0x9E8B20
    WeatherRegion* ActiveRegionWeather; // 0x0 Member
    AreaBiomeGroup* ActiveRegion; // 0x8 Member
    // no_addr void WeatherSystem(const class WeatherSystem & _a1);// public missing arg names
    WeatherSystem();// private RVA = 0x9E84A0
    WeatherSystem* _CONSTRUCTOR();// private RVA = 0x9E84A0
    struct FogValues
    {
        FogValues();// public RVA = 0x9E7370
        FogValues* _CONSTRUCTOR();// public RVA = 0x9E7370
        float alpha; // 0x0 Member
        float distance; // 0x4 Member
        Ogre::ColourValue colour; // 0x8 Member
        static WeatherSystem::FogValues lerp(const WeatherSystem::FogValues& v0, const WeatherSystem::FogValues& v1, const float value);// public RVA = 0x9E7630
    };
    class ZoneFog
    {
    public:
        ZoneFog();// public RVA = 0x9E73A0
        ZoneFog* _CONSTRUCTOR();// public RVA = 0x9E73A0
        void clear();// public RVA = 0x9E7410
        void set(AreaBiomeGroup* biome, const MainFog* fog);// public RVA = 0x9E7420
        WeatherSystem::FogValues getCurrentValues() const;// public RVA = 0x9E7760
        void update();// public RVA = 0x9E7510
        WeatherInstance* weatherInstance; // 0x0 Member
        WeatherSystem::FogValues prevFog; // 0x8 Member
        WeatherSystem::FogValues currFog; // 0x20 Member
        float lastBlendValue; // 0x38 Member
        bool blending; // 0x3C Member
    };
    bool exitingBiome; // 0x10 Member
    Ogre::Vector4 previousBiomeAABB; // 0x14 Member
    AreaBiomeGroup* previousArea; // 0x28 Member
    AreaBiomeGroup* areaGroups[0x4]; // 0x30 Member
    WeatherSystem::ZoneFog areaFog[0x4]; // 0x50 Member
    AreaSector* previousSector; // 0x150 Member
    Ogre::Vector3 previousPoint; // 0x158 Member
    Ogre::Vector3 zoneFogBlendingPosition; // 0x164 Member
    unsigned char zoneFogBlendingType; // 0x170 Member
    WeatherSystem::ZoneFog previousZoneFog; // 0x178 Member
    WeatherSystem::ZoneFog currentZoneFog; // 0x1B8 Member
    WeatherSystem::FogValues currentFogValues; // 0x1F8 Member
    float currentWindValue; // 0x210 Member
    float currentRainValue; // 0x214 Member
    bool rainValueUpdated; // 0x218 Member
    float globalWetness; // 0x21C Member
    Ogre::Vector3 currentDustAmount; // 0x220 Member
    bool heatHazeUpdated; // 0x22C Member
    float heatHazeValue; // 0x230 Member
    std::map<WeatherRegion::Listener*, WeatherRegion*, std::less<WeatherRegion::Listener*>, Ogre::STLAllocator<std::pair<WeatherRegion::Listener* const, WeatherRegion*>, Ogre::GeneralAllocPolicy > > weatherListeners; // 0x238 Member
    std::set<EffectHandler*, std::less<EffectHandler*>, Ogre::STLAllocator<EffectHandler*, Ogre::GeneralAllocPolicy > > activeEffects; // 0x260 Member
    // no_addr class WeatherSystem & operator=(const class WeatherSystem & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};