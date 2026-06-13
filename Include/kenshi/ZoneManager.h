#pragma once

#include <ogre/OgreVector3.h>
#include <ogre/OgreVector4.h>
#include <ogre/Math/Simple/OgreAabb.h>
#include <kenshi/util/iVector2.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/Enums.h>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/recursive_mutex.hpp>

// TODO move?
class AABB2D
{
public:
    AABB2D(const Ogre::Vector4& a);// public RVA = 0x8F2E80
    AABB2D* _CONSTRUCTOR(const Ogre::Vector4& a);// public RVA = 0x8F2E80
    // no_addr void AABB2D(const class NxBounds3 & _a1);// public missing arg names
    // no_addr void AABB2D(const class AABB2D & _a1);// public missing arg names
    // no_addr void AABB2D(const class Ogre::AxisAlignedBox & _a1);// public missing arg names
    AABB2D();// public RVA = 0xA1BFA0
    AABB2D* _CONSTRUCTOR();// public RVA = 0xA1BFA0
    void setNull();// public RVA = 0xA07180
    // no_addr class NxBounds3 toNx();// public
    float x; // 0x0 Member
    float y; // 0x4 Member
    float x2; // 0x8 Member
    float y2; // 0xC Member
    // no_addr const class AABB2D & operator=(const struct Ogre::Aabb & _a1);// public missing arg names
    // no_addr const class AABB2D & operator=(const class Ogre::AxisAlignedBox & _a1);// public missing arg names
    // no_addr const class AABB2D & operator=(const class Ogre::Vector4 & _a1);// public missing arg names
    // no_addr const class AABB2D & operator=(const class AABB2D & _a1);// public missing arg names
    bool pointWithin(const Ogre::Vector3& v) const;// public RVA = 0x8F2EA0
    // no_addr class Ogre::Vector3 pointNearest(const class Ogre::Vector3 & _a1);// public missing arg names
    // no_addr class Ogre::Vector2 pointNearest(const class Ogre::Vector2 & _a1);// public missing arg names
    void inflate(float amount);// public RVA = 0x8F2EE0
    // no_addr void setWidthX(float _a1);// public missing arg names
    // no_addr void setWidthY(float _a1);// public missing arg names
    float sizeX() const;// public RVA = 0xA07190
    float sizeY() const;// public RVA = 0xA071A0
    // no_addr class Ogre::Vector4 operator class Ogre::Vector4();// public
    bool intersects(const Ogre::Vector3& pos, float radius) const;// public RVA = 0x9AFE90
    bool intersects(const AABB2D& b) const;// public RVA = 0x9AFE50
    bool intersects(const Ogre::Vector3& raypos, const Ogre::Vector3& raydest) const;// public RVA = 0x9AF8C0
    Ogre::Vector2 intersects2(const Ogre::Vector2& rayorig, const Ogre::Vector2& raydirection) const;// public RVA = 0x9AFBC0
};

class ZoneManagerInterfaceT
{
public:
    // VTable         : (none)
    virtual bool isZoneLoadedT(const Ogre::Vector3& _a1) = 0;// public vtable offset = 0x0 missing arg names
    virtual bool isZoneBeingLoadedT(const Ogre::Vector3& _a1) = 0;// public vtable offset = 0x8 missing arg names
    virtual AABB2D getZoneBoundsT(const Ogre::Vector3& _a1) = 0;// public vtable offset = 0x18 missing arg names
    virtual AABB2D getZoneBoundsT(const iVector2& _a1) = 0;// public vtable offset = 0x10 missing arg names
    virtual void getAllActiveZonesT(lektor<iVector2>& _a1) = 0;// public vtable offset = 0x20 missing arg names
    // no_addr void ZoneManagerInterfaceT(const class ZoneManagerInterfaceT & _a1);// public missing arg names
    ZoneManagerInterfaceT();// public RVA = 0xA19C40
    ZoneManagerInterfaceT* _CONSTRUCTOR();// public RVA = 0xA19C40
    // no_addr class ZoneManagerInterfaceT & operator=(const class ZoneManagerInterfaceT & _a1);// public missing arg names
};

class ZoneMap;
class Building;
class Town;
class TownBase;
class Faction;
class BuildingFinderClass;
class Ownerships;
class GameData;
class RootObject;
class hand;
class MapFeatureList;
class ZoneMapOverlay;
class BiomeMap;
class AreaBiomeGroup;

// TODO move?
enum ZoneActivationType
{
    ACTIVATION_CAMERA,
    ACTIVATION_PLAYER_CHARACTER,
    ACTIVATION_TOWN
};

class SpacialCell;
class function;

class ZoneSpacialGrid
{
public:
    enum Result
    {
        UNCHANGED,
        CHANGED_CELL,
        CHANGED_ZONE,
        UNLOADED_ZONE
    };

    // no_addr void ZoneSpacialGrid(const class ZoneSpacialGrid & _a1);// public missing arg names
    ZoneSpacialGrid();// public RVA = 0x9FCB60
    ZoneSpacialGrid* _CONSTRUCTOR();// public RVA = 0x9FCB60
    ~ZoneSpacialGrid();// public RVA = 0x9F98E0
    void _DESTRUCTOR();// public RVA = 0x9F98E0
    unsigned int add(RootObject* o);// public RVA = 0x9FD810
    bool remove(RootObject* o);// public RVA = 0x9FD900
    ZoneSpacialGrid::Result update(RootObject* o);// public RVA = 0x9FD9A0
    int getObjects(const Ogre::Vector3& point, float radius, lektor<RootObject*>& out, int max) const;// public RVA = 0x100980
    int getObjects(const Ogre::Vector3& point, float radius, int filter, lektor<RootObject*>& out, int maxnum) const;// public RVA = 0x9FDA60
    void addZone(ZoneMap* z);// public RVA = 0x9FD6A0
    void removeZone(ZoneMap* z);// public RVA = 0x9FD740
    struct ZoneCell
    {
        ZoneMap* zone; // 0x0 Member
        SpacialCell** cells; // 0x8 Member
    };
    ZoneSpacialGrid::ZoneCell** zones; // 0x0 Member
    unsigned int getZoneKey(const Ogre::Vector3& p) const;// private RVA = 0x9F7EE0
    unsigned int getCellKey(ZoneMap* zone, const Ogre::Vector3& p) const;// private RVA = 0x9F9940
    unsigned int getFullKey(const Ogre::Vector3& p) const;// private RVA = 0x9F9A20
    void initialiseGrid(float size);// private RVA = 0x9F7E40
    function* createCellsFunc; // 0x8 Member
    int cellCount; // 0x10 Member
    float cellSize; // 0x14 Member
    boost::shared_mutex mutex; // 0x18 Member
    // no_addr class ZoneSpacialGrid & operator=(const class ZoneSpacialGrid & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class AreaSector;
class TerrainSector;
class ZoneMapContent;
class ZoneSmell;

// TODO templates
template <typename T>
class BackThreadMessagesToMainT
{
public:
    // VTable         : (none)
    // no_addr void BackThreadMessagesToMainT<enum T>(const class BackThreadMessagesToMainT<enum T> & _a1);// public missing arg names
    BackThreadMessagesToMainT<T>();// public RVA = 0xA24B50
    BackThreadMessagesToMainT<T>* _CONSTRUCTOR();// public RVA = 0xA24B50
    virtual ~BackThreadMessagesToMainT<T>();// public RVA = 0xA253E0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0xA253E0 vtable offset = 0x0
    boost::recursive_mutex swapMutex; // 0x8 Member
    // no_addr void lock();// public
    // no_addr void unlock();// public
    virtual bool flush();// public RVA = 0xA257E0 vtable offset = 0x8
    bool _NV_flush();// public RVA = 0xA257E0 vtable offset = 0x8
    // no_addr void addMessageBT(enum T _a1);// public missing arg names
    // no_addr class std::set<enum T,std::less<enum T>,std::allocator<enum T> > & getMainData();// public
    // no_addr class std::set<enum T,std::less<enum T>,std::allocator<enum T> > & getBackData();// public
    std::set<T, std::less<T>, std::allocator<T> > mainThreadData; // 0x20 Member
    std::set<T, std::less<T>, std::allocator<T> > backThreadData; // 0x40 Member
    // no_addr class BackThreadMessagesToMainT<enum T> & operator=(const class BackThreadMessagesToMainT<enum T> & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

// TODO templates
template<typename T>
class MainthreadStateReaderT : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void MainthreadStateReaderT<T>(const class MainthreadStateReaderT<T> & _a1);// public missing arg names
    MainthreadStateReaderT<T>();// public RVA = 0xA256A0
    MainthreadStateReaderT<T>* _CONSTRUCTOR();// public RVA = 0xA256A0
    virtual ~MainthreadStateReaderT<T>();// public RVA = 0xA19D40 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0xA19D40 vtable offset = 0x0
    boost::shared_mutex swapMutex; // 0x8 Member
    // no_addr void lockEx();// public
    // no_addr void unlockEx();// public
    // no_addr void lockShared();// public
    // no_addr void unlockShared();// public
    virtual bool updateBackDataCheck();// public RVA = 0xA1BFF0 vtable offset = 0x8
    bool _NV_updateBackDataCheck();// public RVA = 0xA1BFF0 vtable offset = 0x8
    T& getMainData();// public RVA = 0xA19DB0
    const T& getMainData() const;// public RVA = 0xA19DA0
    const T& getBackData() const;// public RVA = 0xA19DC0
    // no_addr class T & getBackDataToWrite();// public
    T mainThreadData; // 0x28 Member
    T backThreadData; // 0x2A Member
    // no_addr class MainthreadStateReaderT<T> & operator=(const class MainthreadStateReaderT<T> & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

// TODO move?
class ZoneMap : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    enum ZONE_MESSAGE
    {
        BEING_LOADED_FALSE,
        BEING_LOADED_TRUE
    };

    // no_addr void ZoneMap(const class ZoneMap & _a1);// public missing arg names
    ZoneMap();// public RVA = 0xA0B340
    ZoneMap* _CONSTRUCTOR();// public RVA = 0xA0B340
    void init(const iVector2& coords);// public RVA = 0xA0A1A0
    void getActiveZoneIsland(lektor<ZoneMap*>& out) const;// public RVA = 0xA092B0
    bool isInIsland(ZoneMap* other) const;// public RVA = 0xA075D0
    void initialise();// public RVA = 0xA07940
    void threadedUpdate();// public RVA = 0xA0D860
    bool update();// public RVA = 0xA0A080
    int selectBiomes();// public RVA = 0xA09330
    int getBiomeCount() const;// public RVA = 0x6D9860
    GameData* getBiomeData(int i) const;// public RVA = 0x6D9870
    ZoneMapOverlay* getOverlay();// public RVA = 0xA15470
    AreaSector* getAreaSector();// public RVA = 0x8F3520
    float getTerrainHeight(float _x, float _y);// public RVA = 0xA072C0
    float getTerrainHeightWithNormal(float _x, float _y, Ogre::Vector3& normal);// public RVA = 0xA072F0
    float getTerrainSlope(float _x, float _y);// public RVA = 0xA07310
    const Ogre::Vector4& getBounds() const;// public RVA = 0x3D2120
    const Ogre::Aabb& getBoundingBox() const;// public RVA = 0x398C80
    Ogre::Vector4 getBoundsMinusUnloadedEdges(float borderThickness) const;// public RVA = 0xA07FC0
    bool isWithinBoundsMinusUnloadedEdges(float borderThickness, const Ogre::Vector3& v) const;// public RVA = 0xA080D0
    Ogre::Vector3 getCornerPos() const;// public RVA = 0xA023B0
    const Ogre::Vector3& getCenterPos() const;// public RVA = 0x8F2F20
    TerrainSector* getTerrainSector(bool force) const;// public RVA = 0xA07270
    // no_addr void forceMaterialSplatOverlayImage(class std::basic_string<char,std::char_traits<char>,std::allocator<char> > _a1);// public missing arg names
    bool isActive() const;// public RVA = 0xA07BB0
    bool isActivationType(ZoneActivationType t) const;// public RVA = 0xA07290
    float getDeactivationCountdown() const;// public RVA = 0xA07BD0
    bool isLoadedBT();// public RVA = 0xA0BA80
    bool isBeingLoadedBT();// public RVA = 0xA0BAE0
    bool isLoadedMT();// public RVA = 0xA07900
    bool isBeingLoadedMT();// public RVA = 0xA07920
    void getActiveNeighbours4(ogre_unordered_set<ZoneMap*>::type& maplist);// public RVA = 0x9ED0F0
    void getActiveNeighbours8(ogre_unordered_set<ZoneMap*>::type& maplist);// public RVA = 0x9ED170
    bool isANeighbour(ZoneMap* who);// public RVA = 0x9ED080
    bool isTerrainCollisionLoaded();// public RVA = 0xA08530
    static void getMaterialValues(GameData* data, Ogre::Vector4* scales, Ogre::Vector4& min, Ogre::Vector4& max, Ogre::Vector4& blend, Ogre::Vector4& overlayMult, float* absorbance);// public RVA = 0xA0C210
    static Ogre::SharedPtr<Ogre::Material> getTerrainMaterial_DX11(const std::string& base, const lektor<GameData*>& biomes, int* channels, ZoneMapOverlay* overlayMaps);// public RVA = 0xA134E0
    static std::string getBiomeTextureArrayData(GameData* biome, int type, Ogre::vector<std::string>::type& files);// public RVA = 0xA0BB40
    static Ogre::SharedPtr<Ogre::Texture> createTextureArray(GameData* biome, int type);// public RVA = 0xA0F7A0
    static Ogre::SharedPtr<Ogre::Material> materialCallback(const Ogre::AxisAlignedBox& box, int level);// public RVA = 0xA15B20
    static void destroyMaterialCallback(const Ogre::AxisAlignedBox& box, Ogre::SharedPtr<Ogre::Material> material);// public RVA = 0xA15900
    ZoneMapContent* mapContent; // 0x0 Member
    MapFeatureList* mapFeatures; // 0x8 Member
    ZoneSmell* zoneSmell; // 0x10 Member
    iVector2 coordinates; // 0x18 Member
    int island; // 0x20 Member
    bool hasFile; // 0x24 Member
    // Typedef        : ZoneStateMessagesT
    BackThreadMessagesToMainT<ZONE_MESSAGE> zoneIncomingMessagesT; // 0x28 Member
    class StateT
    {
    public:
        StateT();// public RVA = 0xA19A70
        StateT* _CONSTRUCTOR();// public RVA = 0xA19A70
        bool _zoneBeingLoaded; // 0x0 Member
        bool _zoneIsLoaded; // 0x1 Member
    };
    void _makeSureTerrainHeightmapLoaded();// private RVA = 0xA0B4A0
    bool _activate(int _range, ZoneActivationType type, float deactivationTimer);// private RVA = 0xA0CDC0
    void _dactivateMT(bool saveZoneState);// private RVA = 0xA08D40
    bool generateNavMeshes();// private RVA = 0xA0CF60
    void updateBuildingUsageNodes();// private RVA = 0xA07C00
    MainthreadStateReaderT<ZoneMap::StateT> stateT; // 0x88 Member
    TerrainSector* terrainCollision; // 0xB8 Member
    float activatedCountdown[0x3]; // 0xC0 Member
    bool _generateNavMeshesFlag; // 0xCC Member
    Ogre::Aabb bounds; // 0xD0 Member
    Ogre::Vector4 AABB; // 0xE8 Member
    Ogre::Vector3 center; // 0xF8 Member
    lektor<GameData*> biomes; // 0x108 Member
    int loadCount; // 0x120 Member
    ZoneMap* neighbors[0x4]; // 0x128 Member
    ZoneMap* neighborsDiagonal[0x4]; // 0x148 Member
    ~ZoneMap();// public RVA = 0xA25530
    void _DESTRUCTOR();// public RVA = 0xA25530
    // no_addr class ZoneMap & operator=(const class ZoneMap & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class ParticleSystemHandler;

class ParticlePool : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    struct ParticleData
    {
        ParticleData();// public RVA = 0x409300
        ParticleData* _CONSTRUCTOR();// public RVA = 0x409300
        ParticleSystemHandler* particle; // 0x0 Member
        GameData* effectData; // 0x8 Member
        Ogre::SceneNode* node; // 0x10 Member
    };
    ParticlePool(int limit, float ttl);// public RVA = 0x409650
    ParticlePool* _CONSTRUCTOR(int limit, float ttl);// public RVA = 0x409650
    ~ParticlePool();// public RVA = 0x40B810
    void _DESTRUCTOR();// public RVA = 0x40B810
    void init();// public RVA = 0x409320
    void destroy();// public RVA = 0x40B460
    int getSize() const;// public RVA = 0x4093A0
    bool addParticle(GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, Ogre::SceneNode* parentNode);// public RVA = 0x40B540
    void update();// public RVA = 0x40B680
    void shiftParticles(const Ogre::Vector3& shift);// public RVA = 0x4093B0
    unsigned int limit; // 0x0 Member
    unsigned int lastIndex; // 0x4 Member
    ParticlePool::ParticleData* particles; // 0x8 Member
    float maxTTL; // 0x10 Member
    // no_addr void __dflt_ctor_closure();// public
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class ZoneManager : public ZoneManagerInterfaceT, public Ogre::GeneralAllocatedObject
{
public:
    // ZoneManagerInterfaceT offset = 0x0, length = 0x8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // no_addr void ZoneManager(const class ZoneManager & _a1);// public missing arg names
    ZoneManager();// public RVA = 0xA0B520
    ZoneManager* _CONSTRUCTOR();// public RVA = 0xA0B520
    ~ZoneManager();// public RVA = 0xA0ADD0
    void _DESTRUCTOR();// public RVA = 0xA0ADD0
    virtual bool isZoneLoadedT(const Ogre::Vector3& pos) override;// public RVA = 0xA0CC80 vtable offset = 0x0
    bool _NV_isZoneLoadedT(const Ogre::Vector3& pos);// public RVA = 0xA0CC80 vtable offset = 0x0
    virtual bool isZoneBeingLoadedT(const Ogre::Vector3& pos) override;// public RVA = 0xA0CD20 vtable offset = 0x0
    bool _NV_isZoneBeingLoadedT(const Ogre::Vector3& pos);// public RVA = 0xA0CD20 vtable offset = 0x0
    virtual AABB2D getZoneBoundsT(const Ogre::Vector3& pos) override;// public RVA = 0xA07D60 vtable offset = 0x0
    AABB2D _NV_getZoneBoundsT(const Ogre::Vector3& pos);// public RVA = 0xA07D60 vtable offset = 0x0
    virtual AABB2D getZoneBoundsT(const iVector2& coord) override;// public RVA = 0xA07E10 vtable offset = 0x0
    AABB2D _NV_getZoneBoundsT(const iVector2& coord);// public RVA = 0xA07E10 vtable offset = 0x0
    virtual void getAllActiveZonesT(lektor<iVector2>& out) override;// public RVA = 0xA08EC0 vtable offset = 0x0
    void _NV_getAllActiveZonesT(lektor<iVector2>& out);// public RVA = 0xA08EC0 vtable offset = 0x0
    void getAllActiveIslandNumbers(ogre_unordered_set<int>::type& out);// public RVA = 0xA0AD40
    void getAllActiveZones(lektor<ZoneMap*>& out);// public RVA = 0xA08F60
    int getNumActiveZones() const;// public RVA = 0x902680
    Building* findShop(Town* t, ItemFunction selling);// public RVA = 0x9FA8C0
    Building* findAnyShop(Town* t);// public RVA = 0x9FAA00
    void findBuilding(TownBase* t, Faction* f, BuildingFinderClass* out);// public RVA = 0x9FACA0
    Building* findBuilding(TownBase* t, Faction* f, bool forSaleOnly, BuildingFunction fun, Ownerships* own);// public RVA = 0x9FAB30
    void getBuildingsThatLinkTo(lektor<Building*>& out, GameData* buildingType);// public RVA = 0x9FCF60
    void findAllBuildings(lektor<Building*>& out, TownBase* t, Faction* f, bool forSaleOnly, unsigned int fun, Ownerships* ownership);// public RVA = 0x9FEEE0
    void findOverlappingActiveZones(lektor<ZoneMap*>& out, const Ogre::Vector3& pos, float radius);// public RVA = 0x9F9EB0
    void setup();// public RVA = 0xA11FA0
    void updateMainThread(const Ogre::Vector3& camerapos);// public RVA = 0xA11290
    void updateRendertimeThread(const Ogre::Vector3& camerapos);// public RVA = 0xA0DB20
    void updateGPUSafeThread(const Ogre::Vector3& camerapos);// public RVA = 0xA114C0
    void spawnChecksUpdateThreaded(int island);// public RVA = 0x8F7A90
    void levelEditorDeleteAllSelectedObjects();// public RVA = 0x7A4E90
    void levelEditorGetAllSelectedObjects(lektor<RootObject*>& out, itemType type);// public RVA = 0x799C70
    iVector2 getCurrentMapSector() const;// public RVA = 0xA07C70
    ZoneMap* getCurrentZoneMap();// public RVA = 0x3B5180
    iVector2 getSubMapSector(float X, float Z) const;// public RVA = 0xA07420
    iVector2 getMapSector(const Ogre::Vector3& v) const;// public RVA = 0xA073A0
    iVector2 getMapSector(float x, float z) const;// public RVA = 0xA07370
    Ogre::Vector4 getZoneMapSectorBounds(const iVector2 sector);// public RVA = 0xA073D0
    iVector2 getZoneMapFromResolutionCoord(float X, float Z) const;// public RVA = 0xA07D30
    ZoneMap* getZoneMap(const Ogre::Vector3& v);// public RVA = 0x291160
    ZoneMap* getZoneMap(int x, int y);// public RVA = 0xA07330
    ZoneMap* getZoneMap(const iVector2& v);// public RVA = 0x1009B0
    ZoneMap* getZoneMapFromBuildingHandle(const hand& h);// public RVA = 0xA07CE0
    bool playerActivate(const Ogre::Vector3& pos);// public RVA = 0xA0DE90
    bool activateZoneMap(ZoneMap* map, iVector2 center, int range, ZoneActivationType type, float deactivationTimer);// public RVA = 0xA0D8D0
    bool activateZoneMap(const iVector2& co, int range, ZoneActivationType playerActivated, bool backThread);// public RVA = 0x8771C0
    void deactivateZoneMap(ZoneMap* map, bool saveZoneState);// public RVA = 0xA092D0
    void getZonesTouchingTown(lektor<ZoneMap*>& out, Town* town);// public RVA = 0x9FBB40
    const lektor<MapFeatureList*>& getLoadedFeatureLists() const;// public RVA = 0x780970
    ZoneMapOverlay* getOverlay(const iVector2& index, bool create);// public RVA = 0xA15310
    GameData* getBiome(const Ogre::Vector3& position) const;// public RVA = 0x64610
    int getBiomeCode(const Ogre::Vector3& position) const;// public RVA = 0x6D76C0
    const BiomeMap* getBiomeMap() const;// public RVA = 0x9D4F60
    int getGroundTypeIndex(const Ogre::Vector3& pos) const;// public RVA = 0xA154E0
    GroundType getGroundType(const Ogre::Vector3& pos) const;// public RVA = 0xA156A0
    static const char* getGroundSound(GroundType type, bool barefoot);// public RVA = 0xA074C0
    const char* getGroundSound(const Ogre::Vector3& pos) const;// public RVA = 0xA15720
    bool getGroundEffect(const Ogre::Vector3& position, GameData*& effectData, float& minSpeed, float& probability);// public RVA = 0xA157C0
    void addGroundEffect(GameData* effectData, const Ogre::Vector3& position);// public RVA = 0xA07450
    void shiftGroundEffects(const Ogre::Vector3& shift);// public RVA = 0xA07560
    bool checkZoneFiles() const;// public RVA = 0xA0A740
    void resetStates();// public RVA = 0xA091A0
    // no_addr float getResourceWater(class AreaBiomeGroup * _a1, const class Ogre::Vector3 & _a2);// public missing arg names
    // no_addr float getResourceFertility(class AreaBiomeGroup * _a1, const class Ogre::Vector3 & _a2);// public missing arg names
    // no_addr float getResourceStone(class AreaBiomeGroup * _a1, const class Ogre::Vector3 & _a2);// public missing arg names
    // no_addr float getResourceIron(class AreaBiomeGroup * _a1, const class Ogre::Vector3 & _a2);// public missing arg names
    // no_addr float getResourceCopper(class AreaBiomeGroup * _a1, const class Ogre::Vector3 & _a2);// public missing arg names
    // no_addr float getResourceCarbon(class AreaBiomeGroup * _a1, const class Ogre::Vector3 & _a2);// public missing arg names
    float getResource(MiningResource resource, AreaBiomeGroup* _biome, const Ogre::Vector3& positionAndAltitude);// public RVA = 0xA11D90
    float getResourceBase(MiningResource resource, AreaBiomeGroup* biome, const Ogre::Vector3& positionAndAltitude);// public RVA = 0xA11840
    std::string getResourceId(MiningResource resource) const;// public RVA = 0xA09570
    std::string getResourceName(MiningResource resource) const;// public RVA = 0xA0AB50
    bool saveMapFeatures();// public RVA = 0xA07890
    void saveLevelData(const std::string& path, const std::string& modName);// public RVA = 0x36E6F0
    void saveActiveZoneStates();// public RVA = 0x36DF30
    void resetGame();// public RVA = 0x36AD00
    void deactivateAllActiveZones();// public RVA = 0x36BE00
    void activateAllActiveZones();// public RVA = 0x36AD10
    void populateTownsForLevelEditor();// public RVA = 0x9FC350
    void calculateIslands();// public RVA = 0xA19A90
    void getIsland(const ZoneMap* zone, lektor<ZoneMap*>& out) const;// public RVA = 0xA09200
    void _reloadAllFoliage();// public RVA = 0xA08A40
    void _reloadGroundTextures();// public RVA = 0xA08AB0
    // no_addr void addNavMeshData(class NavMeshData * _a1);// public missing arg names
    void _unloadAllZones();// public RVA = 0xA09000
    bool checkForRepopulateTown(Town* t);// public RVA = 0x9FDDF0
    ZoneMap* getCentralZone();// public RVA = 0x1009C0
    int isLoading() const;// public RVA = 0x3B2A00
    bool justLoadedAGame; // 0x8 Member
    ZoneSpacialGrid characterGrid; // 0x10 Member
    ZoneSpacialGrid buildingGrid; // 0x48 Member
    ZoneSpacialGrid itemGrid; // 0x80 Member
    struct BiomeGroundEffects
    {
        GameData* effectDatas[0x5]; // 0x0 Member
        float minSpeeds[0x5]; // 0x28 Member
        float probabilities[0x5]; // 0x3C Member
        BiomeGroundEffects();// public RVA = 0xA089C0
        BiomeGroundEffects* _CONSTRUCTOR();// public RVA = 0xA089C0
    };
    bool _needCalculateIslands; // 0xB8 Member
    void _calculateIslands();// private RVA = 0xA08C40
    float spawnUpdateTimerMT; // 0xBC Member
    float spawnUpdateTimerTT; // 0xC0 Member
    ZoneMap worldMap[0x40][0x40]; // 0xC8 Member
    ogre_unordered_set<ZoneMap*>::type processingNewActiveZones; // 0x1680C8 Member
    ogre_unordered_set<ZoneMap*>::type activeZones; // 0x168108 Member
    ogre_unordered_set<Town*>::type updatedTownOverrides; // 0x168148 Member
    void loadFeatures();// private RVA = 0xA08130
    lektor<MapFeatureList*> loadedFeatureLists; // 0x168188 Member
    void loadDistantTowns();// private RVA = 0xA09B90
    std::set<Town*, std::less<Town*>, Ogre::STLAllocator<Town*, Ogre::GeneralAllocPolicy > > distantTownList; // 0x1681A0 Member
    iVector2 distantTownCentre; // 0x1681C8 Member
    ZoneMap* centralZone; // 0x1681D0 Member
    int loadingPhase; // 0x1681D8 Member
    bool processLoading();// private RVA = 0xA0E070
    void loadPhase1();// private RVA = 0xA0DDE0
    void loadPhase2();// private RVA = 0xA0CFB0
    void loadPhase3();// private RVA = 0xA0D300
    // no_addr void analyseWalls();// private
    ogre_unordered_map<iVector2, ZoneMapOverlay*>::type overlays; // 0x1681E0 Member
    BiomeMap* biomeMap; // 0x168220 Member
    ogre_unordered_map<int, unsigned char*>::type groundTypes; // 0x168228 Member
    ogre_unordered_map<int, ZoneManager::BiomeGroundEffects>::type groundEffects; // 0x168268 Member
    ParticlePool groundEffectsPool; // 0x1682A8 Member
    // no_addr class ZoneManager & operator=(const class ZoneManager & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class RealWorldEditableImage;

class ZoneMapOverlay : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // Typedef        : MaterialRefMap
    // no_addr void ZoneMapOverlay(const class ZoneMapOverlay & _a1);// public missing arg names
    ZoneMapOverlay(const iVector2& p);// public RVA = 0xA12E00
    ZoneMapOverlay* _CONSTRUCTOR(const iVector2& p);// public RVA = 0xA12E00
    ~ZoneMapOverlay();// public RVA = 0xA131E0
    void _DESTRUCTOR();// public RVA = 0xA131E0
    void enable();// public RVA = 0xA105C0
    void disable();// public RVA = 0xA0A2C0
    bool loadData();// public RVA = 0xA0A6E0
    std::string getName() const;// public RVA = 0xA0A710
    bool isEnabled() const;// public RVA = 0x780950
    void addMaterial(const Ogre::SharedPtr<Ogre::Material>& material);// public RVA = 0xA13260
    void removeMaterial(const Ogre::SharedPtr<Ogre::Material>& material);// public RVA = 0xA12CC0
    const iVector2& getIndex() const;// public RVA = 0xA19A60
    RealWorldEditableImage* getImage() const;// public RVA = 0x780960
    std::string colourMap; // 0x0 Member
    iVector2 index; // 0x28 Member
    RealWorldEditableImage* image; // 0x30 Member
    boost::unordered::unordered_map<Ogre::SharedPtr<Ogre::Material>, unsigned short, boost::hash<Ogre::SharedPtr<Ogre::Material> >, std::equal_to<Ogre::SharedPtr<Ogre::Material> >, Ogre::STLAllocator<std::pair<Ogre::SharedPtr<Ogre::Material> const, unsigned short>, Ogre::GeneralAllocPolicy > > materials; // 0x38 Member
    bool enabled; // 0x78 Member
    // no_addr class ZoneMapOverlay & operator=(const class ZoneMapOverlay & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};