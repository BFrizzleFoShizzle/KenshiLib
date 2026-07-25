#pragma once

#include "RootObjectBase.h"
#include "RootObject.h"
#include "util/YesNoMaybe.h"
#include "util/TimeOfDay.h"
#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include "Enums.h"

enum PlatoonCreationMessage
{
    CM_NO_MESSAGE,
    CM_REFRESH,
    CM_DECIMATE,
    CM_DELETE,
    CM_EMPTY
};

class CampaignInstance;
class Blackboard;
class UniquePlatoon;
class Tasker;
class UnloadedPlatoon;
class PatrolInfo;
class AreaBiomeGroup;
class AreaSector;

enum BuildingFunction;

class Ownerships
{
public:
    // VTable         : (none)
    // no_addr void Ownerships(const class Ownerships & _a1);// public missing arg names
    Ownerships(Faction* f, Platoon* p);// public RVA = 0x7CA770
    Ownerships* _CONSTRUCTOR(Faction* f, Platoon* p);// public RVA = 0x7CA770
    void setHandle(Platoon* h);// public RVA = 0x7EA9D0
    void addOwnedObject(const hand& what);// public RVA = 0x7EB8A0
    void removeOwnedObject(const hand& what);// public RVA = 0x7EAE90
    bool isOwned(const hand& what);// public RVA = 0x7EAF90
    virtual bool takeMoney(int val);// public RVA = 0x7CA840 vtable offset = 0x0
    bool _NV_takeMoney(int val);// public RVA = 0x7CA840 vtable offset = 0x0
    virtual void takeMoneyByForce(int val);// public RVA = 0x7CA830 vtable offset = 0x8
    void _NV_takeMoneyByForce(int val);// public RVA = 0x7CA830 vtable offset = 0x8
    int getMoney() const;// public RVA = 0x37D720
    void addMoney(int amount);// public RVA = 0x32DAD0
    void setMoney(int amount);// public RVA = 0x37D730
    void setHomeBuildingDesignation(BuildingDesignation d);// public RVA = 0x791310
    void copyFrom(Ownerships* other);// public RVA = 0x7C4080
    std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > slaves; // 0x8 Member
    void serialise(GameData* state);// public RVA = 0x6239A0
    void load(GameData* state, SquadType st);// public RVA = 0x623EC0
    TownBase* _homeTown; // 0x30 Member
    hand _homeBuilding; // 0x38 Member
    void setHomeTown(TownBase* t, SquadType squadtype);// public RVA = 0x7EB670
    void setHomeBuilding(const hand& h, SquadType t);// public RVA = 0x7EB780
    void getOwnedBuildingsH(lektor<hand>& out);// public RVA = 0x5AD320
    void getOwnedBuildingPtrs(lektor<Building*>& out, TownBase* town);// public RVA = 0x7931C0
    // no_addr int getOwnedBuildingPtrs(class lektor<Building *> & _a1);// public missing arg names
    void getHomeFurnitureOfType(lektor<Building*>& out, BuildingFunction type);// public RVA = 0x792090
    int getOwnedPtrs(lektor<RootObject*>& out, itemType type);// public RVA = 0x9A5380
    void getBuildingsWithFunction(lektor<Building*>& out, BuildingFunction bf);// public RVA = 0x620E60
    bool isMyTown(TownBase* t);// public RVA = 0x620A60
    bool canIUseThisBuilding(Building* b, Character* _me);// public RVA = 0x620AB0
    void declareOccupiedTown(TownBase* t);// public RVA = 0x286770
    Faction* getOccupiedTownFaction();// public RVA = 0x620C10
    lektor<hand> stuff; // 0x58 Member
    Faction* faction; // 0x70 Member
    Platoon* me; // 0x78 Member
    TownBase* occupiedTown; // 0x80 Member
    int money; // 0x88 Member
    ~Ownerships();// public RVA = 0x7C98C0
    void _DESTRUCTOR();// public RVA = 0x7C98C0
    // no_addr class Ownerships & operator=(const class Ownerships & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class Platoon : public RootObjectBase, public Ogre::GeneralAllocatedObject
{
public:
    // RootObjectBase offset = 0x0, length = 0x78
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x78, length = 0x1
    std::string stringID; // 0x78 Member
    // no_addr void Platoon(class Platoon & _a1);// public missing arg names
    Platoon(Faction* f, GameData* _squadTemplate, GameData* platoonState, const Ogre::Vector3& p, bool _persistent);// protected RVA = 0x7ED070
    Platoon* _CONSTRUCTOR(Faction* f, GameData* _squadTemplate, GameData* platoonState, const Ogre::Vector3& p, bool _persistent);// protected RVA = 0x7ED070
    virtual ~Platoon();// protected RVA = 0x7EB380 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x7EB380 vtable offset = 0x0
    void setCharacterCount(int count);// protected RVA = 0x37D740
    int _characterCountCurrent; // 0xA0 Member
    int _characterCountOriginal; // 0xA4 Member
    SquadType squadType; // 0xA8 Member
    YesNoMaybe hasUniques; // 0xAC Member
    MoveSpeed speedOverride; // 0xB0 Member
    hand isSeparatedSquad; // 0xB8 Member
    bool canRefresh; // 0xD8 Member
    bool regenerates; // 0xD9 Member
    GameData* myBaseHomeTownData; // 0xE0 Member
    hand chooseNewHome();// public RVA = 0x99CF30
    virtual bool isUnconcious() const override;// public RVA = 0x997350 vtable offset = 0x0
    bool _NV_isUnconcious() const;// public RVA = 0x997350 vtable offset = 0x0
    SquadType getSquadType() const;// public RVA = 0x2872A0
    void setSquadType(SquadType t);// public RVA = 0x9C2D00
    virtual TownBase* getCurrentTownLocation() override;// public RVA = 0x9C1F70 vtable offset = 0x0
    TownBase* _NV_getCurrentTownLocation();// public RVA = 0x9C1F70 vtable offset = 0x0
    CampaignInstance* hasCampaign();// public RVA = 0x9C2D90
    float priceMultWhenITrade; // 0xE8 Member
    bool _iBuyStolenGoods; // 0xEC Member
    bool _iBuyIllegalGoods; // 0xED Member
    bool iBuyStolenGoods(Item* what);// public RVA = 0x7915D0
    bool iBuyIllegalGoods();// public RVA = 0x70B9F0
    virtual void setFaction(Faction* p);// public RVA = 0x794E60 vtable offset = 0xA8
    void _NV_setFaction(Faction* p);// public RVA = 0x794E60 vtable offset = 0xA8
    bool canTakeRefugees(Platoon* who);// public RVA = 0x7EAE60
    Ogre::Entity* locatorModel; // 0xF0 Member
    Blackboard* blackboard; // 0xF8 Member
    virtual UniquePlatoon* isUnique();// public RVA = 0x7F1090 vtable offset = 0xB0
    UniquePlatoon* _NV_isUnique();// public RVA = 0x7F1090 vtable offset = 0xB0
    std::string getPlatoonStringID() const;// public RVA = 0x384710
    Blackboard* getBlackboard();// public RVA = 0x268260
    virtual itemType getDataType() const override;// public RVA = 0x7F10A0 vtable offset = 0x0
    itemType _NV_getDataType() const;// public RVA = 0x7F10A0 vtable offset = 0x0
    void erasePlatoonFile();// public RVA = 0x7EB960
    void showDebugMarker(bool on);// public RVA = 0x7EAB80
    // no_addr int getIndex();// public
    virtual StateBroadcastData* getStateBroadcast() override;// public RVA = 0x792870 vtable offset = 0x0
    StateBroadcastData* _NV_getStateBroadcast();// public RVA = 0x792870 vtable offset = 0x0
    virtual GameData* serialiseEverything(GameDataContainer* dataContainer, bool levelEditor);// public RVA = 0x3729D0 vtable offset = 0xB8
    GameData* _NV_serialiseEverything(GameDataContainer* dataContainer, bool levelEditor);// public RVA = 0x3729D0 vtable offset = 0xB8
    virtual void loadStateData(GameData* state);// public RVA = 0x7EBE90 vtable offset = 0xC0
    void _NV_loadStateData(GameData* state);// public RVA = 0x7EBE90 vtable offset = 0xC0
    virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract) override;// public RVA = 0x7F10D0 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x7F10D0 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* state) override;// public RVA = 0x7F10B0 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState* state);// public RVA = 0x7F10B0 vtable offset = 0x0
    void reprocessTask(Tasker* t);// public RVA = 0x4FE290
    void taskIsComplete(Tasker* t);// public RVA = 0x7EACC0
    void setDataFilename(std::string f);// public RVA = 0x7EB240
    bool isIntact();// public RVA = 0x7AB550
    bool _isIntact; // 0x100 Member
    // no_addr void notifyCampaignFail();// public
    virtual void notifyMissionEnded();// public RVA = 0x9C2DC0 vtable offset = 0xC8
    void _NV_notifyMissionEnded();// public RVA = 0x9C2DC0 vtable offset = 0xC8
    void activate();// public RVA = 0x7EAB90
    void deactivate(GameDataContainer* forceCharacterStates);// public RVA = 0x7EE250
    void declareDead();// public RVA = 0x795E30
    void undeclareDead();// public RVA = 0x7904D0
    bool isFullyLoaded();// public RVA = 0x4FE1B0
    ActivePlatoon* getActivePlatoon();// public RVA = 0x268270
    UnloadedPlatoon* getUnloadedPlatoon();// public RVA = 0x5890C0
    virtual bool update();// public RVA = 0x7EAAE0 vtable offset = 0xD0
    bool _NV_update();// public RVA = 0x7EAAE0 vtable offset = 0xD0
    virtual void periodicUpdate_active(float time);// public RVA = 0x7EAA60 vtable offset = 0xD8
    void _NV_periodicUpdate_active(float time);// public RVA = 0x7EAA60 vtable offset = 0xD8
    virtual void periodicUpdate_unloaded();// public RVA = 0x7EAAA0 vtable offset = 0xE0
    void _NV_periodicUpdate_unloaded();// public RVA = 0x7EAAA0 vtable offset = 0xE0
    void setupPatrolSettings(int minRange, int maxRange);// public RVA = 0x7ECED0
    PatrolInfo* getPatrolInfo();// public RVA = 0x335AF0
    AreaBiomeGroup* getRoamingMapArea();// public RVA = 0x4FE0F0
    void setRoamingMapArea(AreaBiomeGroup* maparea);// public RVA = 0x7EBB60
    GameData* squadTemplate; // 0x108 Member
    float malnourishedLevel; // 0x110 Member
    bool hasNeverBeenActivated; // 0x114 Member
    bool _persistentSquad; // 0x115 Member
    bool isPersistentSquad();// public RVA = 0x7EB310
    void setPersistentSquad(bool on);// public RVA = 0x7EAB70
    bool isResidentSquad; // 0x116 Member
    virtual Ownerships* getOwnerships() override;// public RVA = 0x7F10C0 vtable offset = 0x0
    Ownerships* _NV_getOwnerships();// public RVA = 0x7F10C0 vtable offset = 0x0
    Character* getNearestActiveCharacter(const Ogre::Vector3& p, int floor);// public RVA = 0x792B00
    Character* getSquadLeader();// public RVA = 0x799C40
    const hand& getSquadLeader_theRealOne() const;// public RVA = 0x336360
    int getCharacterCount();// public RVA = 0x791D30
    int getCharacterCount_Original() const;// public RVA = 0x268280
    int needsNewCharacters();// public RVA = 0x9254F0
    PlatoonCreationMessage messageOnActivation; // 0x118 Member
    virtual void reCheckPersistenceOnUnload();// protected RVA = 0x9A5F80 vtable offset = 0xE8
    void _NV_reCheckPersistenceOnUnload();// protected RVA = 0x9A5F80 vtable offset = 0xE8
    AreaSector* currentSpawnArea; // 0x120 Member
    hand squadleader; // 0x128 Member
    Ownerships ownerships; // 0x148 Member
    ActivePlatoon* activePlatoon; // 0x1D8 Member
    UnloadedPlatoon* unloadedPlatoon; // 0x1E0 Member
    PatrolInfo* patrolSettings; // 0x1E8 Member
    bool isDead; // 0x1F0 Member
    bool imprisoned; // 0x1F1 Member
    short index; // 0x1F2 Member
    TimeOfDay traderInventoryRefreshTime; // 0x1F8 Member
    static float PLATOON_LOAD_DISTANCE; // RVA = 0x2130138 Static Member
    // no_addr class Platoon & operator=(const class Platoon & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class GroupSense;
class CharacterMemory;
class HandleList;
class PlayerInterface;

class ActivePlatoon : public RootObjectContainer
{
public:
    // RootObjectContainer offset = 0x0, length = 0x68
    virtual bool loadFromDisk(bool force, Serialisable* extra) override;// private RVA = 0x36B140 vtable offset = 0x0
    bool _NV_loadFromDisk(bool force, Serialisable* extra);// private RVA = 0x36B140 vtable offset = 0x0
    bool _recalculateIsIntact();// private RVA = 0x799A90
    bool isAnyoneCaptured();// private RVA = 0x7998E0
    virtual ~ActivePlatoon();// public RVA = 0x4FE7C0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x4FE7C0 vtable offset = 0x0
    GroupSense* _groupSense; // 0x68 Member
    GroupSense* getGroupSense();// public RVA = 0x850620
    CharacterMemory* getMemory();// public RVA = 0x2851F0
    virtual bool removeObject(RootObject* c) override;// public RVA = 0x794540 vtable offset = 0x0
    bool _NV_removeObject(RootObject* c);// public RVA = 0x794540 vtable offset = 0x0
    virtual bool addActiveObject(RootObject* c) override;// public RVA = 0x795FE0 vtable offset = 0x0
    bool _NV_addActiveObject(RootObject* c);// public RVA = 0x795FE0 vtable offset = 0x0
    void addCharacterAt(RootObject* c, int index);// public RVA = 0x7953C0
    void swapCharacters(int indexA, int indexB);// public RVA = 0x791C00
    void emptySquadCheck();// public RVA = 0x7998B0
    void clearAllTheUniqueNPCStates();// public RVA = 0x4FEFE0
    bool isIntact();// public RVA = 0x7A4980
    bool isAnimalsOnly; // 0x70 Member
    void getCharactersInArea(lektor<RootObject*>& out, const Ogre::Vector3& pos, float radius, bool standingOnly);// public RVA = 0x6B9590
    Character* getSquadLeader_theRealOne();// public RVA = 0x595E10
    Character* getNearestActiveCharacter(const Ogre::Vector3& p, int floor);// public RVA = 0x791A80
    Character* getSquadLeader();// public RVA = 0x791930
    int getSquadSize() const;// public RVA = 0x4197B0
    void setSquadLeader(Character* who);// public RVA = 0x790540
    virtual bool update() override;// public RVA = 0x4FFC40 vtable offset = 0x0
    bool _NV_update();// public RVA = 0x4FFC40 vtable offset = 0x0
    void refreshInventory(bool firstTime);// public RVA = 0x4FEE60
    void _forceRefreshInventory();// public RVA = 0x4FE1F0
    virtual bool periodicUpdate();// public RVA = 0x4FE8E0 vtable offset = 0x40
    bool _NV_periodicUpdate();// public RVA = 0x4FE8E0 vtable offset = 0x40
    void serialiseEverythingToDisk(bool levelEditor);// public RVA = 0x4FEE20
    bool isWholeSquadDown(int minusThis);// public RVA = 0x791F00
    void setDataFilename(const std::string& f);// public RVA = 0x7F0F60
    void setupLeaderDialogues();// public RVA = 0x2DF310
    bool isLoaded() const;// public RVA = 0x595E20
    void teleport(const Ogre::Vector3& pos);// public RVA = 0x37D750
    void setName(const std::string& name);// public RVA = 0x4BDD00
    const std::string& getName() const;// public RVA = 0x411980
    bool getIsTrader() const;// public RVA = 0x387440
    bool getHasVendorList() const;// public RVA = 0x4FE1D0
    bool getHasSpecialItemsList() const;// public RVA = 0x4FE1E0
    void setupTraderBuildings();// public RVA = 0x623810
    Platoon* me; // 0x78 Member
    HandleList* characterHandles; // 0x80 Member
    void putTheSpecialCharactersInNewSquads_captured();// public RVA = 0x79AF60
    bool checkForCharactersBeingCarried();// public RVA = 0x79B3A0
    void restoreSquad();// public RVA = 0x7B4A30
    // no_addr void ActivePlatoon(const class ActivePlatoon & _a1);// public missing arg names
    ActivePlatoon(Platoon* my, DataObjectContainer* doc, Faction* f, GameData* d, Tasker* _currentGoal, const Ogre::Vector3& _posOffset);// protected RVA = 0x4FFD80
    ActivePlatoon* _CONSTRUCTOR(Platoon* my, DataObjectContainer* doc, Faction* f, GameData* d, Tasker* _currentGoal, const Ogre::Vector3& _posOffset);// protected RVA = 0x4FFD80
    float p_TIME; // 0x88 Member
    ZoneMap* lastActiveZone; // 0x90 Member
    CharacterMemory* _myMemory; // 0x98 Member
    bool unloadCheck();// private RVA = 0x4FE450
    YesNoMaybe setupCheck();// private RVA = 0x4FF350
    void destroyCharacters(bool justUnload);// private RVA = 0x4FE750
    void serialiseCharacterData();// private RVA = 0x4FEC90
    void saveToDisk(bool levelEditor, const std::string& force);// private RVA = 0x36B770
    virtual void loadCharacters(Ogre::Vector3 _a1, FactoryCallbackInterface* _a2);// private RVA = 0x7948D0 vtable offset = 0x48 missing arg names
    void _NV_loadCharacters(Ogre::Vector3 _a1, FactoryCallbackInterface* _a2);// private RVA = 0x7948D0 vtable offset = 0x48 missing arg names
    virtual void loadInstance(GameSaveState& state, bool skipSaveState, const Ogre::Vector3& pos, const Ogre::Quaternion& rot, FactoryCallbackInterface* callback, const Ogre::Vector3& positionMoved) override;// private RVA = 0x36F190 vtable offset = 0x0
    void _NV_loadInstance(GameSaveState& state, bool skipSaveState, const Ogre::Vector3& pos, const Ogre::Quaternion& rot, FactoryCallbackInterface* callback, const Ogre::Vector3& positionMoved);// private RVA = 0x36F190 vtable offset = 0x0
    Ogre::Vector3 calculateCurrentPos();// private RVA = 0x4FE5D0
    void _checkForUniqueCharactersOnUnload();// private RVA = 0x9A6970
    Character* squadleader; // 0xA0 Member
    Character* backupLeader; // 0xA8 Member
    float deactivationTimer; // 0xB0 Member
    Ogre::Vector3 workingPos; // 0xB4 Member
    Tasker* currentGoal; // 0xC0 Member
    Ogre::Vector3 positionMoved; // 0xC8 Member
    Ogre::Vector3 teleportTo; // 0xD4 Member
    bool teleportMessage; // 0xE0 Member
    PlayerInterface* isPlayer; // 0xE8 Member
    bool isPhysical; // 0xF0 Member
    // no_addr class ActivePlatoon & operator=(const class ActivePlatoon & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};