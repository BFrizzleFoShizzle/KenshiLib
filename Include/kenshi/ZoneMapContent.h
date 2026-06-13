#pragma once

#include "RootObject.h"
#include "util/iVector2.h"
#include "util/OgreUnordered.h"
#include <boost/thread/shared_mutex.hpp>

class RealWorldEditableImage;

class Town;
class BuildingFinderClass;
class FoliageSystem;

// TODO move?
template<typename T1, typename T2>
class CategorisedSet // <enum BuildingFunction, Building*>
{
public:
    // Typedef        : TSet
    // Typedef        : CATTMap
    // no_addr class std::set<Building *,std::less<Building *>,Ogre::STLAllocator<Building *,Ogre::CategorisedAllocPolicy<0> > > * getList(enum BuildingFunction _a1);// public missing arg names
    // no_addr void add(enum BuildingFunction _a1, class Building * _a2);// public missing arg names
    // no_addr void remove(class Building * _a1);// public missing arg names
    // no_addr bool remove_sure(class Building * _a1);// public missing arg names
    // no_addr bool find(class Building * _a1);// public missing arg names
    // no_addr void clear();// public
    // no_addr int getCount();// public
    // no_addr int getCount(enum BuildingFunction _a1);// public missing arg names
    /* TODO fix this
    class CategorisedSetIterator<enum BuildingFunction, Building*>
    {
    public:
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<BuildingFunction, std::set<Building*, std::less<Building*>, Ogre::STLAllocator<Building*, Ogre::GeneralAllocPolicy > >, std::less<BuildingFunction>, Ogre::STLAllocator<std::pair<BuildingFunction const, std::set<Building*, std::less<Building*>, Ogre::STLAllocator<Building*, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy >, 0> > > mapIt; // 0x0 Member
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<BuildingFunction, std::set<Building*, std::less<Building*>, Ogre::STLAllocator<Building*, Ogre::GeneralAllocPolicy > >, std::less<BuildingFunction>, Ogre::STLAllocator<std::pair<BuildingFunction const, std::set<Building*, std::less<Building*>, Ogre::STLAllocator<Building*, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy >, 0> > > mapEnd; // 0x8 Member
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Building*, std::less<Building*>, Ogre::STLAllocator<Building*, Ogre::GeneralAllocPolicy >, 0> > > setIt; // 0x10 Member
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Building*, std::less<Building*>, Ogre::STLAllocator<Building*, Ogre::GeneralAllocPolicy >, 0> > > setEnd; // 0x18 Member
        // no_addr void CategorisedSetIterator<enum BuildingFunction,Building *>(unsigned int _a1);// public missing arg names
        // no_addr bool ended();// public
        // no_addr void operator++(int _a1);// public missing arg names
        // no_addr void operator++();// public
        // no_addr void increment();// public
        // no_addr class Building * get();// public
        unsigned int flags; // 0x20 Member
    };
    */
    // no_addr class CategorisedSet<enum BuildingFunction,Building *>::CategorisedSetIterator<enum BuildingFunction,Building *> getIterator(unsigned int _a1);// public missing arg names
    std::map<T1, std::set<T2*, std::less<T2*>, Ogre::STLAllocator<T2*, Ogre::GeneralAllocPolicy > >, std::less<T1>, Ogre::STLAllocator<std::pair<T1 const, std::set<T2*, std::less<T2*>, Ogre::STLAllocator<T2*, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > list; // 0x0 Member
    // no_addr void CategorisedSet<enum BuildingFunction,Building *>(const class CategorisedSet<enum BuildingFunction,Building *> & _a1);// public missing arg names
    // no_addr void CategorisedSet<enum BuildingFunction,Building *>();// public
    // no_addr void ~CategorisedSet<enum BuildingFunction,Building *>();// public
    // no_addr class CategorisedSet<enum BuildingFunction,Building *> & operator=(const class CategorisedSet<enum BuildingFunction,Building *> & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class HandleList;
class AreaSector;

class ZoneMapContent : public RootObjectContainer
{
public:
    // RootObjectContainer offset = 0x0, length = 0x68
    class ZoneMapContentOrderLoader : public RootObjectContainer::SpecificItemLoadFirst
    {
    public:
        // RootObjectContainer::SpecificItemLoadFirst offset = 0x0, length = 0x40
        // no_addr void ZoneMapContentOrderLoader(const class ZoneMapContent::ZoneMapContentOrderLoader & _a1);// public missing arg names
        ZoneMapContentOrderLoader(bool newgame);// public RVA = 0xA09680
        ZoneMapContentOrderLoader* _CONSTRUCTOR(bool newgame);// public RVA = 0xA09680
        virtual bool shouldSkip(GameSaveState* state) override;// public RVA = 0xA0B8A0 vtable offset = 0x0
        bool _NV_shouldSkip(GameSaveState* state);// public RVA = 0xA0B8A0 vtable offset = 0x0
        bool newGameFirstTimeLoaded; // 0x40 Member
        ~ZoneMapContentOrderLoader();// public RVA = 0xA04EC0
        void _DESTRUCTOR();// public RVA = 0xA04EC0
        // no_addr class ZoneMapContent::ZoneMapContentOrderLoader & operator=(const class ZoneMapContent::ZoneMapContentOrderLoader & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    class HandleDummy : public RootObjectBase
    {
    public:
        // RootObjectBase offset = 0x0, length = 0x78
        // no_addr void HandleDummy(const class ZoneMapContent::HandleDummy & _a1);// public missing arg names
        HandleDummy(ZoneMapContent* m);// public RVA = 0xA04740
        HandleDummy* _CONSTRUCTOR(ZoneMapContent* m);// public RVA = 0xA04740
        virtual itemType getDataType() const override;// public RVA = 0xA047C0 vtable offset = 0x0
        itemType _NV_getDataType() const;// public RVA = 0xA047C0 vtable offset = 0x0
        virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract) override;// public RVA = 0xA065B0 vtable offset = 0x0
        GameSaveState _NV_serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0xA065B0 vtable offset = 0x0
        virtual void loadFromSerialise(GameSaveState* state) override;// public RVA = 0xA047D0 vtable offset = 0x0
        void _NV_loadFromSerialise(GameSaveState* state);// public RVA = 0xA047D0 vtable offset = 0x0
        ZoneMapContent* me; // 0x78 Member
        virtual ~HandleDummy();// public RVA = 0xA047E0 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0xA047E0 vtable offset = 0x0
        // no_addr class ZoneMapContent::HandleDummy & operator=(const class ZoneMapContent::HandleDummy & _a1);// public missing arg names
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    // no_addr void ZoneMapContent(const class ZoneMapContent & _a1);// public missing arg names
    ZoneMapContent(ZoneMap* parent);// public RVA = 0x9FFE40
    ZoneMapContent* _CONSTRUCTOR(ZoneMap* parent);// public RVA = 0x9FFE40
    virtual ~ZoneMapContent();// public RVA = 0x9FF1D0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x9FF1D0 vtable offset = 0x0
    bool isLoadedT();// public RVA = 0x904490
    virtual bool update() override;// public RVA = 0x9FEE50 vtable offset = 0x0
    bool _NV_update();// public RVA = 0x9FEE50 vtable offset = 0x0
    void threadedUpdate();// public RVA = 0x9F9B00
    void addToUpdateList(RootObject* b);// public RVA = 0xA03550
    void _reloadAllFoliage();// public RVA = 0x9F7DB0
    RealWorldEditableImage* getOverlayData() const;// public RVA = 0xA065E0
    iVector2 getOverlayPixelCoord() const;// public RVA = 0x9F8070
    void clearOverlay(int channel) const;// public RVA = 0x9FBD70
    int generateDirtMap(int channel) const;// public RVA = 0x9FF920
    void addLoadedBuilding(GameSaveState* buildingInstanceData, bool isActiveLevelFile);// public RVA = 0x36B930
    bool loadItems(GameDataContainer* source);// public RVA = 0x36F430
    void saveItems(GameDataContainer* dest, bool allItems);// public RVA = 0x36B330
    void saveLevelData(bool all, const std::string& modName, const std::string& pathOverride);// public RVA = 0x36D8C0
    void saveToDisk(const std::string& path);// public RVA = 0x36BB50
    void activate();// public RVA = 0xA19A50
    void deactivate(bool saveZoneState);// public RVA = 0x9FD1D0
    // no_addr class ZoneMap * getZoneMap();// public
    void reFactionBuildingsFromTown();// public RVA = 0x791DE0
    void updateItemsVisibility();// public RVA = 0x9F9D90
    void _setEnabledStaticGeometry(bool enable);// public RVA = 0x9F7F10
    Building* findBuildingTypePublic(Town* t);// public RVA = 0x9FAF10
    void findAllBuildingTypePublics(lektor<Building*>& out, Town* t, ItemFunction selling);// public RVA = 0x9FA4C0
    void findAllBuildingTypePublics(lektor<Building*>& out, Town* t);// public RVA = 0x9FA350
    void findAllBuildings(TownBase* t, Faction* f, BuildingFinderClass* out, bool internalToo);// public RVA = 0x9FA0D0
    void findAllBuildings(lektor<Building*>& out, TownBase* t, Faction* f, bool forSaleOnly, unsigned int func, Ownerships* ownership);// public RVA = 0x9FA220
    void findAllBuildingsThatLinkTo(lektor<Building*>& out, GameData* buildingType);// public RVA = 0x9FCA30
    Building* findBuildingByDataPosition(GameData* data, float x, float z);// public RVA = 0x9FA6F0
    void _populateTownsOnNewGame();// public RVA = 0x9FAFF0
    void forceLoadAllTheBuildingInteriorVisuals();// public RVA = 0x9F7FE0
    void addItem(Item* item);// public RVA = 0x9FC870
    void removeItem(Item* item);// public RVA = 0x9FC0E0
    bool changeItemZone(Item* item, ZoneMap* moveTo);// public RVA = 0x9FC950
    const ogre_unordered_set<hand>::type& _getItems() const;// public RVA = 0xD1450
    virtual bool removeObject(RootObject* obj) override;// public RVA = 0x9FB420 vtable offset = 0x0
    bool _NV_removeObject(RootObject* obj);// public RVA = 0x9FB420 vtable offset = 0x0
    void _addDeletedThing(const InstanceID& id);// public RVA = 0x9FB3A0
    const FoliageSystem* getFoliageSystem() const;// public RVA = 0x3B29F0
    int periodicUpdateIndex; // 0x68 Member
    CategorisedSet<BuildingFunction, Building*> buildingList; // 0x70 Member
    HandleList* myHandles; // 0x98 Member
    ZoneMapContent::HandleDummy* handleDummy; // 0xA0 Member
    bool newGameFirstTimeLoaded; // 0xA8 Member
    AreaSector* spawnAreaClass; // 0xB0 Member
    lektor<RootObject*> toUpdateList; // 0xB8 Member
    void _activate();// private RVA = 0x9FE320
    // no_addr void loadInPlayerImports(class Serialisable * _a1);// private missing arg names
    void populateAllTheBuildings(ogre_unordered_set<Town*>::type* townsOut, lektor<Building*>* buildingsToPopulate);// private RVA = 0x9FC420
    void createLoadedItems();// private RVA = 0x9FBE40
    void setLoadedT(bool t);// private RVA = 0xA06E80
    ZoneMap* zoneMap; // 0xD0 Member
    bool loaded; // 0xD8 Member
    boost::shared_mutex mutex; // 0xE0 Member
    FoliageSystem* foliageSystem; // 0x100 Member
    bool activationFlag; // 0x108 Member
    ogre_unordered_set<hand>::type items; // 0x110 Member
    lektor<InstanceID> deletedThings; // 0x150 Member
    // no_addr class ZoneMapContent & operator=(const class ZoneMapContent & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};