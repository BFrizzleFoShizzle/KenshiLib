#pragma once

#include "RootObject.h"
#include <ogre/OgreVector3.h>
#include "Building/Building.h"
#include "util/TagsClass.h"
#include "util/TimeOfDay.h"
#include "util/iVector2.h"
// TODO move FactoryCallbackInterface
#include "PlayerInterface.h"

enum TownAlarmState
{
    ALARM_NONE,
    ALARM_INTRUDER,
    ALARM_ESCAPE,
    ALARM_ATTACK
};

class BuildingFinderClass;
class AlarmManager;
class Nest;
class ArtifactItemData;

enum TownType
{
    TOWN_NEST,
    TOWN_OUTPOST,
    TOWN_TOWN,
    TOWN_VILLAGE,
    TOWN_RUINS,
    TOWN_SLAVE_CAMP,
    TOWN_MILITARY,
    TOWN_PRISON,
    TOWN_NEST_MARKER,
    TOWN_POI,
    TOWN_NULL
};

class BasePopulationManager;
class ScreenLabel;
class PhysicsHullT;

// TODO move?
class TownBuildingsManager : public FactoryCallbackInterface, public Ogre::GeneralAllocatedObject
{
public:
    // FactoryCallbackInterface offset = 0x0, length = 0x8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    struct BuildingInfo
    {
        Ogre::FastArray<Ogre::MovableObject*> entities[0x4]; // 0x0 Member
        unsigned char visibleFloor; // 0x60 Member
        BuildingInfo(const TownBuildingsManager::BuildingInfo& __that);// public RVA = 0x9415B0
        BuildingInfo* _CONSTRUCTOR(const TownBuildingsManager::BuildingInfo& __that);// public RVA = 0x9415B0
        BuildingInfo();// public RVA = 0x93F480
        BuildingInfo* _CONSTRUCTOR();// public RVA = 0x93F480
        ~BuildingInfo();// public RVA = 0x93EBC0
        void _DESTRUCTOR();// public RVA = 0x93EBC0
        // no_addr struct TownBuildingsManager::BuildingInfo & operator=(const struct TownBuildingsManager::BuildingInfo & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    // Typedef        : EntitesList
    // Typedef        : BuildingEntitiesMap
    // Typedef        : SignsList
    // Typedef        : InstanceManagerMap
    // no_addr void TownBuildingsManager(const class TownBuildingsManager & _a1);// public missing arg names
    TownBuildingsManager(TownBase* town);// public RVA = 0x92F390
    TownBuildingsManager* _CONSTRUCTOR(TownBase* town);// public RVA = 0x92F390
    virtual ~TownBuildingsManager();// public RVA = 0x92F470 vtable offset = 0x8
    void _DESTRUCTOR();// public RVA = 0x92F470 vtable offset = 0x8
    void clear();// public RVA = 0x92DC20
    void moveBuildingsTo(TownBuildingsManager* to);// public RVA = 0x92FC30
    Ogre::MovableObject* addEntity(Building* building, Ogre::MovableObject* obj, int floor, bool isSign, bool instance);// public RVA = 0x9328F0
    static bool removeEntity(Ogre::FastArray<Ogre::MovableObject*>& list, Ogre::MovableObject* item);// private RVA = 0x926F50
    void removeEntity(Building* building, Ogre::MovableObject* entity);// public RVA = 0x929290
    void removeBuilding(Building* building);// public RVA = 0x92C710
    bool switchInstancing(Building* building, Ogre::MovableObject*& obj, int floor, bool instance);// public RVA = 0x932E80
    void addInteriorShell(Building* building, Ogre::MovableObject* entity, int floor);// public RVA = 0x92DE80
    void removeInteriorShell(Building* building, Ogre::MovableObject* entity, int floor);// public RVA = 0x929400
    void setFloorVisible(Building* building, int floor);// public RVA = 0x929540
    int getFloorVisible(Building* building) const;// public RVA = 0x929680
    bool getFloorVisible(Building* building, int floor) const;// public RVA = 0x929620
    void setAllVisible(int floor, bool onlyPlayerBuildings);// public RVA = 0x928AC0
    void resetAllVisible();// public RVA = 0x928C00
    void setSignsVisible(bool value);// public RVA = 0x926FB0
    virtual void factoryObjectCreatedCallback(RootObject* _a1) override;// public RVA = 0x9261A0 vtable offset = 0x0 missing arg names
    void _NV_factoryObjectCreatedCallback(RootObject* _a1);// public RVA = 0x9261A0 vtable offset = 0x0 missing arg names
    static bool isInstanced(Ogre::MovableObject* obj);// public RVA = 0x927D10
    static bool isEntity(Ogre::MovableObject* obj);// public RVA = 0x927D80
    bool makeInstance(Ogre::MovableObject*& obj);// private RVA = 0x92F4E0
    bool makeEntity(Ogre::MovableObject*& obj);// private RVA = 0x932C50
    ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>::type buildingEntities; // 0x8 Member
    boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > > instancesManagers; // 0x48 Member
    Ogre::FastArray<std::pair<Building*, Ogre::Entity*> > signs; // 0x88 Member
    bool signsVisible; // 0xA0 Member
    TownBase* town; // 0xA8 Member
    // no_addr class TownBuildingsManager & operator=(const class TownBuildingsManager & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x8 missing arg names
};

class TradeCulture;
class DistantTown;
class NestBatcher;

class TownBase : public RootObject, public Ogre::GeneralAllocatedObject
{
public:
    // RootObject offset = 0x0, length = 0xC0
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xC0, length = 0x1
    // no_addr void TownBase(const class TownBase & _a1);// public missing arg names
    TownBase(GameData* d);// public RVA = 0x92F8E0
    TownBase* _CONSTRUCTOR(GameData* d);// public RVA = 0x92F8E0
    virtual ~TownBase();// public RVA = 0x933080 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x933080 vtable offset = 0x0
    virtual void activate(ZoneMap* zone);// public RVA = 0x92C400 vtable offset = 0x228
    void _NV_activate(ZoneMap* zone);// public RVA = 0x92C400 vtable offset = 0x228
    virtual bool isActive() const;// public RVA = 0x926150 vtable offset = 0x230
    bool _NV_isActive() const;// public RVA = 0x926150 vtable offset = 0x230
    virtual void setup(GameData* _town, Ogre::Vector3 _pos, hand h);// public RVA = 0x92ABB0 vtable offset = 0x238
    void _NV_setup(GameData* _town, Ogre::Vector3 _pos, hand h);// public RVA = 0x92ABB0 vtable offset = 0x238
    virtual void _reset();// public RVA = 0x92B410 vtable offset = 0x240
    void _NV__reset();// public RVA = 0x92B410 vtable offset = 0x240
    std::string getKnownName();// public RVA = 0x928E30
    virtual TownAlarmState getAlarmState() const;// public RVA = 0x94F8D0 vtable offset = 0x248
    TownAlarmState _NV_getAlarmState() const;// public RVA = 0x94F8D0 vtable offset = 0x248
    virtual void setAlarmState(TownAlarmState s);// public RVA = 0x94F8E0 vtable offset = 0x250
    void _NV_setAlarmState(TownAlarmState s);// public RVA = 0x94F8E0 vtable offset = 0x250
    virtual void reassessTownPosition();// public RVA = 0x94F8F0 vtable offset = 0x258
    void _NV_reassessTownPosition();// public RVA = 0x94F8F0 vtable offset = 0x258
    virtual bool isNotFriendly();// public RVA = 0x925810 vtable offset = 0x260
    bool _NV_isNotFriendly();// public RVA = 0x925810 vtable offset = 0x260
    virtual bool isPhysical() const override;// public RVA = 0x94F900 vtable offset = 0x0
    bool _NV_isPhysical() const;// public RVA = 0x94F900 vtable offset = 0x0
    virtual void setVisible(bool on) override;// public RVA = 0x9323E0 vtable offset = 0x0
    void _NV_setVisible(bool on);// public RVA = 0x9323E0 vtable offset = 0x0
    virtual void setHandle(const hand& h) override;// public RVA = 0x36C290 vtable offset = 0x0
    void _NV_setHandle(const hand& h);// public RVA = 0x36C290 vtable offset = 0x0
    virtual itemType getDataType() const override;// public RVA = 0x94F910 vtable offset = 0x0
    itemType _NV_getDataType() const;// public RVA = 0x94F910 vtable offset = 0x0
    virtual Town* isTown();// public RVA = 0x94F920 vtable offset = 0x268
    Town* _NV_isTown();// public RVA = 0x94F920 vtable offset = 0x268
    virtual Nest* isNest() = 0;// public vtable offset = 0x270
    virtual void nestUpThisSpot(GameData* nestInfo, const Ogre::Vector3& pos, Building* keepInside);// public RVA = 0x927830 vtable offset = 0x278
    void _NV_nestUpThisSpot(GameData* nestInfo, const Ogre::Vector3& pos, Building* keepInside);// public RVA = 0x927830 vtable offset = 0x278
    virtual GameSaveState serialise(GameDataContainer* c, GameData* r, PosRotPair* offsetPosToSubtract) override;// public RVA = 0x36E3D0 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer* c, GameData* r, PosRotPair* offsetPosToSubtract);// public RVA = 0x36E3D0 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* state) override;// public RVA = 0x94F930 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState* state);// public RVA = 0x94F930 vtable offset = 0x0
    bool isOutpost() const;// public RVA = 0x335B10
    bool withinBordersRange(const Ogre::Vector3& p, float mult) const;// public RVA = 0x9255A0
    bool withinDiscoveryRange(const Ogre::Vector3& p, bool explored) const;// public RVA = 0x925640
    virtual bool isIllegal(Item* what);// public RVA = 0x94F940 vtable offset = 0x280
    bool _NV_isIllegal(Item* what);// public RVA = 0x94F940 vtable offset = 0x280
    float distanceTo(const Ogre::Vector3& to) const;// public RVA = 0x4EB780
    float squaredDistanceTo(const Ogre::Vector3& to) const;// public RVA = 0x6D7C40
    virtual bool isDead();// public RVA = 0x925CC0 vtable offset = 0x288
    bool _NV_isDead();// public RVA = 0x925CC0 vtable offset = 0x288
    virtual Ogre::Vector3 getPositionOutsideTownGates(float dist);// public RVA = 0x94F950 vtable offset = 0x290
    Ogre::Vector3 _NV_getPositionOutsideTownGates(float dist);// public RVA = 0x94F950 vtable offset = 0x290
    virtual void setFaction(Faction* faction, ActivePlatoon* _a2) override;// public RVA = 0x927020 vtable offset = 0x0
    void _NV_setFaction(Faction* faction, ActivePlatoon* _a2);// public RVA = 0x927020 vtable offset = 0x0
    virtual bool isPublic() const;// public RVA = 0x94F970 vtable offset = 0x298
    bool _NV_isPublic() const;// public RVA = 0x94F970 vtable offset = 0x298
    virtual float getRadius() const;// public RVA = 0x9256D0 vtable offset = 0x2A0
    float _NV_getRadius() const;// public RVA = 0x9256D0 vtable offset = 0x2A0
    virtual void getGUIData(DatapanelGUI* _a1, int category) override;// public RVA = 0x94F980 vtable offset = 0x0
    void _NV_getGUIData(DatapanelGUI* _a1, int category);// public RVA = 0x94F980 vtable offset = 0x0
    virtual void saveState(GameData* state);// public RVA = 0x3704B0 vtable offset = 0x2A8
    void _NV_saveState(GameData* state);// public RVA = 0x3704B0 vtable offset = 0x2A8
    virtual void loadState(GameData* state);// public RVA = 0x36F710 vtable offset = 0x2B0
    void _NV_loadState(GameData* state);// public RVA = 0x36F710 vtable offset = 0x2B0
    virtual void update() override;// public RVA = 0x927650 vtable offset = 0x0
    void _NV_update();// public RVA = 0x927650 vtable offset = 0x0
    virtual void periodicUpdate() override;// public RVA = 0x925C40 vtable offset = 0x0
    void _NV_periodicUpdate();// public RVA = 0x925C40 vtable offset = 0x0
    virtual void updatePowerGrid();// public RVA = 0x94F990 vtable offset = 0x2B8
    void _NV_updatePowerGrid();// public RVA = 0x94F990 vtable offset = 0x2B8
    virtual bool hasResidentHQ(Faction* f) const;// public RVA = 0x94FAC0 vtable offset = 0x2C0
    bool _NV_hasResidentHQ(Faction* f) const;// public RVA = 0x94FAC0 vtable offset = 0x2C0
    virtual void findAllBuildings(BuildingFinderClass* finder);// public RVA = 0x8CF940 vtable offset = 0x2C8
    void _NV_findAllBuildings(BuildingFinderClass* finder);// public RVA = 0x8CF940 vtable offset = 0x2C8
    virtual lektor<Building*>* findAllBuildingsOfType(BuildingDesignation func, Character* me);// public RVA = 0x8CB320 vtable offset = 0x2D0
    lektor<Building*>* _NV_findAllBuildingsOfType(BuildingDesignation func, Character* me);// public RVA = 0x8CB320 vtable offset = 0x2D0
    virtual lektor<Building*>* findAllBuildingsWithFunction(BuildingFunction func, Character* me);// public RVA = 0x8CFA40 vtable offset = 0x2D8
    lektor<Building*>* _NV_findAllBuildingsWithFunction(BuildingFunction func, Character* me);// public RVA = 0x8CFA40 vtable offset = 0x2D8
    virtual bool allBuildingsDoorsOpen();// public RVA = 0x8CB180 vtable offset = 0x2E0
    bool _NV_allBuildingsDoorsOpen();// public RVA = 0x8CB180 vtable offset = 0x2E0
    virtual void destroyPhysical() override;// public RVA = 0x925AC0 vtable offset = 0x0
    void _NV_destroyPhysical();// public RVA = 0x925AC0 vtable offset = 0x0
    virtual Ogre::Vector3 getPosition() override;// public RVA = 0x925B10 vtable offset = 0x0
    Ogre::Vector3 _NV_getPosition();// public RVA = 0x925B10 vtable offset = 0x0
    virtual Ogre::Vector3 getPositionForWaypoint(const Ogre::Vector3& from) override;// public RVA = 0x925970 vtable offset = 0x0
    Ogre::Vector3 _NV_getPositionForWaypoint(const Ogre::Vector3& from);// public RVA = 0x925970 vtable offset = 0x0
    class TownPositionCacher
    {
    public:
        TownPositionCacher();// public RVA = 0x925380
        TownPositionCacher* _CONSTRUCTOR();// public RVA = 0x925380
        TimeOfDay lastUpdateStamp; // 0x0 Member
        float updateRateInHours; // 0x8 Member
        Ogre::Vector3 pos; // 0xC Member
        void stampUpdate();// public RVA = 0x9253C0
        bool needsUpdate();// public RVA = 0x9253F0
        // no_addr class TownPositionCacher & operator=(const class TownPositionCacher & _a1);// public missing arg names
    };
    TownPositionCacher positionCacher; // 0xC0 Member
    virtual bool createPhysical() override;// public RVA = 0x94F9A0 vtable offset = 0x0
    bool _NV_createPhysical();// public RVA = 0x94F9A0 vtable offset = 0x0
    virtual AlarmManager* getAlarmMgr();// public RVA = 0x94F9C0 vtable offset = 0x2E8
    AlarmManager* _NV_getAlarmMgr();// public RVA = 0x94F9C0 vtable offset = 0x2E8
    virtual bool hasGates();// public RVA = 0x94F9D0 vtable offset = 0x2F0
    bool _NV_hasGates();// public RVA = 0x94F9D0 vtable offset = 0x2F0
    virtual void addGate(const hand& h);// public RVA = 0x94F9E0 vtable offset = 0x2F8
    void _NV_addGate(const hand& h);// public RVA = 0x94F9E0 vtable offset = 0x2F8
    virtual bool gatesAllClosed();// public RVA = 0x94F9F0 vtable offset = 0x300
    bool _NV_gatesAllClosed();// public RVA = 0x94F9F0 vtable offset = 0x300
    virtual GatewayBuilding* getNearestGate(const Ogre::Vector3& to);// public RVA = 0x94FA00 vtable offset = 0x308
    GatewayBuilding* _NV_getNearestGate(const Ogre::Vector3& to);// public RVA = 0x94FA00 vtable offset = 0x308
    virtual AreaBiomeGroup* getBiome();// public RVA = 0x94FA10 vtable offset = 0x310
    AreaBiomeGroup* _NV_getBiome();// public RVA = 0x94FA10 vtable offset = 0x310
    virtual bool isRecentlyDiscovered() const;// public RVA = 0x94FA20 vtable offset = 0x318
    bool _NV_isRecentlyDiscovered() const;// public RVA = 0x94FA20 vtable offset = 0x318
    virtual void setRecentlyDiscovered(bool value);// public RVA = 0x94FA30 vtable offset = 0x320
    void _NV_setRecentlyDiscovered(bool value);// public RVA = 0x94FA30 vtable offset = 0x320
    virtual bool isDiscovered() const;// public RVA = 0x94FA40 vtable offset = 0x328
    bool _NV_isDiscovered() const;// public RVA = 0x94FA40 vtable offset = 0x328
    virtual void setDiscovered(bool value);// public RVA = 0x94FA50 vtable offset = 0x330
    void _NV_setDiscovered(bool value);// public RVA = 0x94FA50 vtable offset = 0x330
    virtual void setDead();// public RVA = 0x94FA60 vtable offset = 0x338
    void _NV_setDead();// public RVA = 0x94FA60 vtable offset = 0x338
    virtual bool isExplored() const;// public RVA = 0x94FA70 vtable offset = 0x340
    bool _NV_isExplored() const;// public RVA = 0x94FA70 vtable offset = 0x340
    virtual void setExplored(bool value);// public RVA = 0x94FA80 vtable offset = 0x348
    void _NV_setExplored(bool value);// public RVA = 0x94FA80 vtable offset = 0x348
    virtual const std::string& getUnexploredName() const;// public RVA = 0x94FA90 vtable offset = 0x350
    const std::string& _NV_getUnexploredName() const;// public RVA = 0x94FA90 vtable offset = 0x350
    virtual unsigned int getItemArtifactsMinValue() const;// public RVA = 0x94FB40 vtable offset = 0x358
    unsigned int _NV_getItemArtifactsMinValue() const;// public RVA = 0x94FB40 vtable offset = 0x358
    virtual unsigned int getItemArtifactsMaxValue() const;// public RVA = 0x94FC00 vtable offset = 0x360
    unsigned int _NV_getItemArtifactsMaxValue() const;// public RVA = 0x94FC00 vtable offset = 0x360
    virtual unsigned int getGearArtifactsMinValue() const;// public RVA = 0x94FCC0 vtable offset = 0x368
    unsigned int _NV_getGearArtifactsMinValue() const;// public RVA = 0x94FCC0 vtable offset = 0x368
    virtual unsigned int getGearArtifactsMaxValue() const;// public RVA = 0x94FD80 vtable offset = 0x370
    unsigned int _NV_getGearArtifactsMaxValue() const;// public RVA = 0x94FD80 vtable offset = 0x370
    void addArtifactItem(const ArtifactItemData& item);// public RVA = 0x927B20
    void setZonePopulated(ZoneMap* zoneMap);// public RVA = 0x92BF80
    TownBuildingsManager* getBuildingsManager();// public RVA = 0x569C70
    int getBuildingFloorVisibility(Building* building) const;// public RVA = 0x92A7C0
    void setBuildingsFloorVisibility(Building* building, int floor);// public RVA = 0x92A810
    void resetBuildingsFloorVisibility();// public RVA = 0x928EB0
    int getTownFloorVisiblity() const;// public RVA = 0x805590
    void setTownFloorVisiblity(int floor, bool onlyPlayerBuildings);// public RVA = 0x928ED0
    void resetTownFloorVisibility();// public RVA = 0x928EF0
    virtual TownBase* getCurrentTownLocation() override;// public RVA = 0x94FAA0 vtable offset = 0x0
    TownBase* _NV_getCurrentTownLocation();// public RVA = 0x94FAA0 vtable offset = 0x0
    static int delayedSpawningChecks();// public RVA = 0x926C60
    const ogre_unordered_set<ZoneMap*>::type& getZonesCoverage() const;// public RVA = 0xD5F50
    static void clearDelayedItemLoadingMessages();// public RVA = 0x926BF0
    TownType townType; // 0xD8 Member 
    BasePopulationManager* population; // 0xE0 Member
    std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > > factionsResidentHere; // 0xE8 Member
    bool alreadyInitialisedPopulationParams; // 0x110 Member
    bool isSecret; // 0x111 Member
    virtual std::string getMapMarker();// public RVA = 0x48D180 vtable offset = 0x378
    std::string _NV_getMapMarker();// public RVA = 0x48D180 vtable offset = 0x378
    virtual MapZoomLevel getMapMarkerZoomLevel();// public RVA = 0x94FAB0 vtable offset = 0x380
    MapZoomLevel _NV_getMapMarkerZoomLevel();// public RVA = 0x94FAB0 vtable offset = 0x380
    std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > occupiers; // 0x118 Member
    void addOccupier(const hand& p);// public RVA = 0x28F4C0
    void removeOccupier(const hand& p);// public RVA = 0x28D4E0
    bool isOccupied();// public RVA = 0x5ABA80
    virtual void _nestUpThisSpot(GameData* nestInfo, const Ogre::Vector3& pos, Building* keepInside);// protected RVA = 0x936C90 vtable offset = 0x388
    void _NV__nestUpThisSpot(GameData* nestInfo, const Ogre::Vector3& pos, Building* keepInside);// protected RVA = 0x936C90 vtable offset = 0x388
    void spawnDebris(NestBatcher* staticGeometry, GameData* itemData, GameData* materialData, Ogre::Vector3 centerpos, float range, int num, float scale, Building* keepInside, bool spawnItems);// protected RVA = 0x935D60
    void distributeArtifacts();// protected RVA = 0x9302E0
    TimeOfDay timeOfDeath; // 0x140 Member
    float p_TIME; // 0x148 Member
    NestBatcher* nestBatcher; // 0x150 Member
    std::string unexploredName; // 0x158 Member
    bool discovered; // 0x180 Member
    bool explored; // 0x181 Member
    bool recentlyDiscovered; // 0x182 Member
    Ogre::Entity* entityMarker; // 0x188 Member
    ScreenLabel* entityLabel; // 0x190 Member
    PhysicsHullT* clickHull; // 0x198 Member
    AreaBiomeGroup* biome; // 0x1A0 Member
    TownAlarmState alarmState; // 0x1A8 Member
    bool isActivated; // 0x1AC Member
    ogre_unordered_set<ZoneMap*>::type myZoneCoverage; // 0x1B0 Member
    ogre_unordered_map<ZoneMap*, bool>::type populatedZones; // 0x1F0 Member
    Ogre::FastArray<ArtifactItemData> artifacts; // 0x230 Member
    unsigned char currentFloorVisibility; // 0x248 Member
    TownBuildingsManager buildingsManager; // 0x250 Member
    struct ResidentData
    {
        GameData* data; // 0x0 Member
        ogre_unordered_set<GameData*>::type buildingsBad; // 0x8 Member
        ogre_unordered_set<GameData*>::type buildingsGood; // 0x48 Member
        int count; // 0x88 Member
        int chance; // 0x8C Member
        int priority; // 0x90 Member
        ResidentData(const ResidentData& __that);// public RVA = 0x94B580
        ResidentData* _CONSTRUCTOR(const ResidentData& __that);// public RVA = 0x94B580
        ResidentData();// public RVA = 0x94B4C0
        ResidentData* _CONSTRUCTOR();// public RVA = 0x94B4C0
        ~ResidentData();// public RVA = 0x94B540
        void _DESTRUCTOR();// public RVA = 0x94B540
        ResidentData& operator=(const ResidentData& __that);// public RVA = 0x94DC90
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    lektor<ResidentData> residentsSpawned; // 0x300 Member
    lektor<ResidentData> residentsSpawned_BarsOrSomething; // 0x318 Member
    GameData* defaultResident; // 0x330 Member
    // no_addr void _initialiseResidentData(class GameData * _a1);// protected missing arg names
    class DelayedSpawnMsg
    {
    public:
        // no_addr void DelayedSpawnMsg(const class DelayedSpawnMsg & _a1);// public missing arg names
        DelayedSpawnMsg(TownBase* t, GameData* nest, const Ogre::Vector3& p, const hand& b);// public RVA = 0x93F4D0
        DelayedSpawnMsg* _CONSTRUCTOR(TownBase* t, GameData* nest, const Ogre::Vector3& p, const hand& b);// public RVA = 0x93F4D0
        DelayedSpawnMsg(Item* i, const Ogre::Vector3& p);// public RVA = 0x925430
        DelayedSpawnMsg* _CONSTRUCTOR(Item* i, const Ogre::Vector3& p);// public RVA = 0x925430
        // no_addr void DelayedSpawnMsg();// public
        hand parentTown; // 0x0 Member
        Item* item; // 0x20 Member
        GameData* nestData; // 0x28 Member
        Ogre::Vector3 pos; // 0x30 Member
        hand insideBuilding; // 0x40 Member
        // no_addr class DelayedSpawnMsg & operator=(const class DelayedSpawnMsg & _a1);// public missing arg names
    };
    static lektor<DelayedSpawnMsg*> delayedItemLoading; // RVA = 0x2054798 Static Member
    // no_addr class TownBase & operator=(const class TownBase & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class Town : public TownBase
{
public:
    // TownBase offset = 0x0, length = 0x338
    // no_addr void Town(const class Town & _a1);// public missing arg names
    Town(GameData* d);// public RVA = 0x933330
    Town* _CONSTRUCTOR(GameData* d);// public RVA = 0x933330
    virtual ~Town();// public RVA = 0x933560 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x933560 vtable offset = 0x0
    void initialiseResidentData();// public RVA = 0x9356B0
    virtual GameData* getGameData() const override;// public RVA = 0x9507C0 vtable offset = 0x0
    GameData* _NV_getGameData() const;// public RVA = 0x9507C0 vtable offset = 0x0
    GameData* replacementTown; // 0x338 Member
    GameData* getOriginalGameData() const;// public RVA = 0x925490
    void notifyRepopulation(GameData* newTowndata);// public RVA = 0x9FCFF0
    // no_addr bool townReplacementCheck(class ZoneMap * _a1);// public missing arg names
    bool isMyOldHomeTownStillValid(GameData* myHomeTown);// public RVA = 0x4FE180
    virtual void setup(GameData* _town, Ogre::Vector3 _pos, hand h) override;// public RVA = 0x933C10 vtable offset = 0x0
    void _NV_setup(GameData* _town, Ogre::Vector3 _pos, hand h);// public RVA = 0x933C10 vtable offset = 0x0
    virtual void _reset() override;// public RVA = 0x92B4A0 vtable offset = 0x0
    void _NV__reset();// public RVA = 0x92B4A0 vtable offset = 0x0
    virtual itemType getDataType() const override;// public RVA = 0x9507E0 vtable offset = 0x0
    itemType _NV_getDataType() const;// public RVA = 0x9507E0 vtable offset = 0x0
    virtual void reassessTownPosition() override;// public RVA = 0x548170 vtable offset = 0x0
    void _NV_reassessTownPosition();// public RVA = 0x548170 vtable offset = 0x0
    void showDistantTown(bool vis);// public RVA = 0x92C5F0
    // no_addr class DistantTown * getDistantTown();// public
    virtual AlarmManager* getAlarmMgr() override;// public RVA = 0x9507F0 vtable offset = 0x0
    AlarmManager* _NV_getAlarmMgr();// public RVA = 0x9507F0 vtable offset = 0x0
    bool isOutpost() const;// public RVA = 0x877250
    bool _setMainResident(Building* building, GameData* residents, bool forceForGates);// public RVA = 0x92CD00
    void chooseResidents(const lektor<Building*>& buildings);// public RVA = 0x935920
    void spawnTheBarFlies();// public RVA = 0x9FB570
    Building* chooseBuildingForResident(const lektor<Building*>& buildings, ResidentData* resident);// public RVA = 0x92D0C0
    void townLoadedEvent(bool newGameFirstTime);// public RVA = 0x92DAB0
    void notifyUnloading();// public RVA = 0x92DC10
    virtual void setHandle(const hand& h) override;// public RVA = 0x36AFA0 vtable offset = 0x0
    void _NV_setHandle(const hand& h);// public RVA = 0x36AFA0 vtable offset = 0x0
    GameData* getBuildingMaterial() const;// public RVA = 0x569C80
    float getLocalTradePriceMult(GameData* item);// public RVA = 0x92BDE0
    float getFactionTradeCultureMult(GameData* item);// public RVA = 0x92A710
    // no_addr bool isItemIllegal(class GameData * _a1);// public missing arg names
    virtual Town* isTown() override;// public RVA = 0x950800 vtable offset = 0x0
    Town* _NV_isTown();// public RVA = 0x950800 vtable offset = 0x0
    virtual Nest* isNest() override;// public RVA = 0x950810 vtable offset = 0x0
    Nest* _NV_isNest();// public RVA = 0x950810 vtable offset = 0x0
    virtual bool isPublic() const override;// public RVA = 0x950820 vtable offset = 0x0
    bool _NV_isPublic() const;// public RVA = 0x950820 vtable offset = 0x0
    virtual void getGUIData(DatapanelGUI* panel, int category) override;// public RVA = 0x794C50 vtable offset = 0x0
    void _NV_getGUIData(DatapanelGUI* panel, int category);// public RVA = 0x794C50 vtable offset = 0x0
    virtual void saveState(GameData* state) override;// public RVA = 0x376660 vtable offset = 0x0
    void _NV_saveState(GameData* state);// public RVA = 0x376660 vtable offset = 0x0
    virtual void loadState(GameData* state) override;// public RVA = 0x3710A0 vtable offset = 0x0
    void _NV_loadState(GameData* state);// public RVA = 0x3710A0 vtable offset = 0x0
    virtual GameSaveState serialise(GameDataContainer* c, GameData* r, PosRotPair* offsetPosToSubtract) override;// public RVA = 0x36E600 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer* c, GameData* r, PosRotPair* offsetPosToSubtract);// public RVA = 0x36E600 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* state) override;// public RVA = 0x950930 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState* state);// public RVA = 0x950930 vtable offset = 0x0
    virtual bool needsSaving(const std::string& mod) const override;// public RVA = 0x950830 vtable offset = 0x0
    bool _NV_needsSaving(const std::string& mod) const;// public RVA = 0x950830 vtable offset = 0x0
    void setPosition(const Ogre::Vector3& p);// public RVA = 0x4EB7B0
    virtual void saveStateEditor(GameData* state);// public RVA = 0x370E50 vtable offset = 0x390
    void _NV_saveStateEditor(GameData* state);// public RVA = 0x370E50 vtable offset = 0x390
    virtual void loadStateEditor(GameData* state);// public RVA = 0x36EAB0 vtable offset = 0x398
    void _NV_loadStateEditor(GameData* state);// public RVA = 0x36EAB0 vtable offset = 0x398
    virtual float getRadius() const override;// public RVA = 0x925700 vtable offset = 0x0
    float _NV_getRadius() const;// public RVA = 0x925700 vtable offset = 0x0
    virtual bool isActive() const override;// public RVA = 0x928700 vtable offset = 0x0
    bool _NV_isActive() const;// public RVA = 0x928700 vtable offset = 0x0
    virtual void update() override;// public RVA = 0x928540 vtable offset = 0x0
    void _NV_update();// public RVA = 0x928540 vtable offset = 0x0
    virtual void periodicUpdate() override;// public RVA = 0x92B570 vtable offset = 0x0
    void _NV_periodicUpdate();// public RVA = 0x92B570 vtable offset = 0x0
    virtual void updatePowerGrid() override;// public RVA = 0x92B5B0 vtable offset = 0x0
    void _NV_updatePowerGrid();// public RVA = 0x92B5B0 vtable offset = 0x0
    virtual bool hasResidentHQ(Faction* f) const override;// public RVA = 0x9508B0 vtable offset = 0x0
    bool _NV_hasResidentHQ(Faction* f) const;// public RVA = 0x9508B0 vtable offset = 0x0
    virtual void addGate(const hand& h) override;// public RVA = 0x950A10 vtable offset = 0x0
    void _NV_addGate(const hand& h);// public RVA = 0x950A10 vtable offset = 0x0
    virtual bool gatesAllClosed() override;// public RVA = 0x928070 vtable offset = 0x0
    bool _NV_gatesAllClosed();// public RVA = 0x928070 vtable offset = 0x0
    virtual bool hasGates() override;// public RVA = 0x9508A0 vtable offset = 0x0
    bool _NV_hasGates();// public RVA = 0x9508A0 vtable offset = 0x0
    void notifyAccesibility(bool accessible);// public RVA = 0x2E9E80
    bool isAccessible; // 0x340 Member
    virtual GatewayBuilding* getNearestGate(const Ogre::Vector3& to) override;// public RVA = 0x928160 vtable offset = 0x0
    GatewayBuilding* _NV_getNearestGate(const Ogre::Vector3& to);// public RVA = 0x928160 vtable offset = 0x0
    virtual Ogre::Vector3 getPositionOutsideTownGates(float dist) override;// public RVA = 0x927DB0 vtable offset = 0x0
    Ogre::Vector3 _NV_getPositionOutsideTownGates(float dist);// public RVA = 0x927DB0 vtable offset = 0x0
    void addBuilding(UseableStuff* b, bool powerIn, bool powerOut, bool battery);// public RVA = 0x92C2D0
    void removeBuilding(UseableStuff* b);// public RVA = 0x92BC00
    bool isPlayerBuildingsInThisTown() const;// public RVA = 0x9254A0
    void setPlayerBuildingsInThisTown();// public RVA = 0x5890D0
    float getRequiredPower() const;// public RVA = 0x2C27B0
    float getTotalPower() const;// public RVA = 0x2966E0
    bool hasSparePower() const;// public RVA = 0x2C27C0
    float getBatteryDrain() const;// public RVA = 0x2FD880
    float getBatteryChargeMax() const;// public RVA = 0x71FD20
    float getBatteryCharge() const;// public RVA = 0x71FD30
    float getBatteryCharge01() const;// public RVA = 0x71FD40
    float getBatteryChargingUpAmount() const;// public RVA = 0x2FD890
    float getBatteryPowerTotal() const;// public RVA = 0x2966F0
    bool isBatteryMode() const;// public RVA = 0x296700
    void addNest(GameData* nestInfo, const Ogre::Vector3& pos, Building* keepInside);// public RVA = 0x927B90
    bool removeNest(Building* b);// public RVA = 0x927730
    void clearNests();// public RVA = 0x926B90
    AlarmManager* alarms; // 0x348 Member
    InstanceID instanceID; // 0x350 Member
    bool openToPublic; // 0x380 Member
    float minFoliageRange; // 0x384 Member
    virtual std::string getMapMarker() override;// public RVA = 0x48D1F0 vtable offset = 0x0
    std::string _NV_getMapMarker();// public RVA = 0x48D1F0 vtable offset = 0x0
    virtual MapZoomLevel getMapMarkerZoomLevel() override;// public RVA = 0x48B530 vtable offset = 0x0
    MapZoomLevel _NV_getMapMarkerZoomLevel();// public RVA = 0x48B530 vtable offset = 0x0
    void recalculatePlayerTownLevel();// public RVA = 0x48BA80
    int playerTownLevel; // 0x388 Member
    TownType getPlayerTownTypeEnum();// public RVA = 0x48B4C0
    TagsClass<BuildingDesignation> facilitesWeHaveHere() const;// public RVA = 0x93F590
    void deActivationCheck();// private RVA = 0x928370
    bool powerBuilding(UseableStuff* what, int numUnPoweredBuildings, float& powerRemaining, bool addToStat);// private RVA = 0x925CE0
    bool drainBattery(UseableStuff* what, int numUnPoweredBuildings, float& powerRemaining);// private RVA = 0x925DE0
    ogre_unordered_set<hand>::type gates; // 0x390 Member
    bool playerHasBuildingsInThisTown; // 0x3D0 Member
    Ogre::FastArray<hand> powerInList; // 0x3D8 Member
    ogre_unordered_set<hand>::type powerOutList; // 0x3F0 Member
    ogre_unordered_set<hand>::type batteryList; // 0x430 Member
    bool batteryMode; // 0x470 Member
    float power_Stat; // 0x474 Member
    float maxPower_Stat; // 0x478 Member
    float neededPowerTotal_Stat; // 0x47C Member
    float batteryPowerTotal_Stat; // 0x480 Member
    float batteryDrain_Stat; // 0x484 Member
    float batteryChargingupTotal; // 0x488 Member
    float batteryCharge_Stat; // 0x48C Member
    float batteryChargeMax_Stat; // 0x490 Member
    TagsClass<BuildingDesignation> _facilitesWeHaveHere; // 0x498 Member
    void _initialiseResidentData(GameData* residentSourceData);// protected RVA = 0x934560
    TradeCulture* tradeCulture; // 0x4A8 Member
    ogre_unordered_map<GameData*, float>::type tradeGoodsMults; // 0x4B0 Member
    GameData* buildingMaterial; // 0x4F0 Member
    DistantTown* distantTown; // 0x4F8 Member
    struct NestSpot
    {
        Ogre::Vector3 pos; // 0x0 Member
        GameData* data; // 0x10 Member
        hand building; // 0x18 Member
        NestSpot(const Town::NestSpot& __that);// public RVA = 0x37F320
        NestSpot* _CONSTRUCTOR(const Town::NestSpot& __that);// public RVA = 0x37F320
        NestSpot();// public RVA = 0x37DA10
        NestSpot* _CONSTRUCTOR();// public RVA = 0x37DA10
        Town::NestSpot& operator=(const Town::NestSpot& __that);// public RVA = 0x37DEB0
    };
    lektor<Town::NestSpot> nestSpots; // 0x500 Member
    bool nestsLoaded; // 0x518 Member
    float overrideRange; // 0x51C Member
    float townRangeMultiplier; // 0x520 Member
    // no_addr class Town & operator=(const class Town & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class AreaSector;
class TownNull;

class TownList : public RootObjectContainer
{
public:
    // RootObjectContainer offset = 0x0, length = 0x68
    // Typedef        : TownsSet
    // Typedef        : TownsHandleList
    // no_addr void TownList(const class TownList & _a1);// public missing arg names
    TownList();// public RVA = 0x92A390
    TownList* _CONSTRUCTOR();// public RVA = 0x92A390
    virtual ~TownList();// public RVA = 0x92A520 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x92A520 vtable offset = 0x0
    virtual bool addActiveObject(RootObject* b) override;// public RVA = 0x92BEE0 vtable offset = 0x0
    bool _NV_addActiveObject(RootObject* b);// public RVA = 0x92BEE0 vtable offset = 0x0
    void updateTownCoverage(TownBase* n);// public RVA = 0x928590
    virtual void getSelectedObjects(lektor<RootObject*>& out, itemType type, bool selectedOnly) override;// public RVA = 0x9276A0 vtable offset = 0x0
    void _NV_getSelectedObjects(lektor<RootObject*>& out, itemType type, bool selectedOnly);// public RVA = 0x9276A0 vtable offset = 0x0
    void _clearAll();// public RVA = 0x926AB0
    void _resetGame();// public RVA = 0x92A100
    void destroyAllTheNests();// public RVA = 0x92ADF0
    void destroy(TownBase* t);// public RVA = 0x929C10
    Town* getTown(const std::string& instanceID);// public RVA = 0x928CF0
    void getTownsInArea(lektor<Town*>& out, AreaSector* area);// public RVA = 0x927450
    Town* getTownBySID(const std::string& name);// public RVA = 0x927A50
    Town* getNearestPlayerTown(const Ogre::Vector3& position, bool includePlayerResidenceTowns, float maxDistance) const;// public RVA = 0x926690
    Town* getNearestTown(const Ogre::Vector3& pos, Faction* townOwner, Town* except, Faction* myFaction, TownType type) const;// public RVA = 0x926760
    Town* getNearestTownWithBuildingDesignation(BuildingDesignation what, const Ogre::Vector3& pos, Faction* townFactionWanted, Town* except, Faction* notEnemiesOf, TownType type, float maxDistanceSquared);// public RVA = 0x9378E0
    Nest* getNearestNest(const Ogre::Vector3& pos, Faction* f, TownBase* except) const;// public RVA = 0x926320
    TownBase* getNearest(const Ogre::Vector3& pos, Faction* f, TownBase* except) const;// public RVA = 0x926400
    TownBase* getNearestWithinItsRadius(const Ogre::Vector3& position, bool skipPlayerTowns) const;// public RVA = 0x9270E0
    void getNearestInOrder(lektor<TownBase*>& out, Ogre::Vector3 pos, Faction* f, int maxNumToGet, TownBase* except);// public RVA = 0x927B40
    void getNearestInOrderWithResidentFaction(lektor<TownBase*>& out, Ogre::Vector3 pos, Faction* f, int maxNumToGet, TownBase* except);// public RVA = 0x925B70
    Town* getRetreatTown(const Ogre::Vector3& pos, Faction* owner, Town* except);// public RVA = 0x9261F0
    Town* createNewPlayerTown(const Ogre::Vector3& pos);// public RVA = 0x933660
    float getDistToNearestTown(const Ogre::Vector3& pos, Town* except);// public RVA = 0x9272A0
    float getSquaredDistToNearestTown(const Ogre::Vector3& pos, Town* except);// public RVA = 0x9268B0
    Town* getNearishTown(Faction* myFaction, const Ogre::Vector3& pos, Faction* owner, TownBase* except, bool publicOnly, unsigned int types);// public RVA = 0x92AE30
    lektor<RootObject*>& getAllTowns();// public RVA = 0xB85F0
    void getAllTownsOf(lektor<TownBase*>& out, Faction* f);// public RVA = 0x9275B0
    void getAllTownsOf(lektor<Town*>& out, Faction* f);// public RVA = 0x927510
    void getAllTownsInBiome(lektor<Town*>& out, AreaBiomeGroup* biome, TownType type);// public RVA = 0x9272C0
    void getAllTowsByGameData(lektor<Town*>& towns, GameData* data);// public RVA = 0x927380
    TownBase* getNullTown() const;// public RVA = 0x925B90
    virtual bool update() override;// public RVA = 0x92C0A0 vtable offset = 0x0
    bool _NV_update();// public RVA = 0x92C0A0 vtable offset = 0x0
    void updateTownsDiscovery();// public RVA = 0x92DF00
    void setAllTownsDebugVisible(bool on);// public RVA = 0x926A40
    virtual void saveToDisk(bool levelEditor, std::string forceFilename);// public RVA = 0x949B70 vtable offset = 0x40
    void _NV_saveToDisk(bool levelEditor, std::string forceFilename);// public RVA = 0x949B70 vtable offset = 0x40
    virtual bool loadFromDisk(bool force, Serialisable* extra) override;// public RVA = 0x925B80 vtable offset = 0x0
    bool _NV_loadFromDisk(bool force, Serialisable* extra);// public RVA = 0x925B80 vtable offset = 0x0
    void saveState(GameDataContainer* container);// public RVA = 0x36B1F0
    void loadState(GameDataContainer* container, bool isImportSoPlayerOnly);// public RVA = 0x371DB0
    void loadStateDiscovery(GameDataContainer* container, bool importOverride);// public RVA = 0x372040
    void loadLevelData(bool newGame);// public RVA = 0x3723A0
    void _saveLevelData(GameDataContainer* container, const std::string& mod);// public RVA = 0x36CC30
    void saveUniqueTownsAndNests(GameDataContainer* container);// public RVA = 0x928F10
    void listUniqueTownsFromPlayerOwnership();// public RVA = 0x9296D0
    void loadAllTowns_worldInit(GameDataContainer* saveSource);// public RVA = 0x933970
    lektor<RootObject*> uniqueTowns; // 0x68 Member
    void addNest(RootObject* n);// public RVA = 0x92BD00
    lektor<RootObject*> nests; // 0x80 Member
    lektor<Town*> deletedTowns; // 0x98 Member
    bool newTownsDiscovered; // 0xB0 Member
    void reassessTownPositions(TownBase* t);// public RVA = 0x54C900
    lektor<hand> townsByZone[0x40][0x40]; // 0xB8 Member
    const ogre_unordered_set<TownBase*>::type& getActiveTowns() const;// public RVA = 0x925E40
    void mergePlayerTowns(Town* a, Town* b);// public RVA = 0x930090
    void _getNearest(const iVector2& sector, TownBase*& nearestTown, float& nearestDistance, const Ogre::Vector3& position, bool skipPlayerTowns) const;// protected RVA = 0x926560
    ogre_unordered_set<TownBase*>::type activeTowns; // 0x180B8 Member
    TownNull* noTown; // 0x180F8 Member
    // no_addr class TownList & operator=(const class TownList & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};