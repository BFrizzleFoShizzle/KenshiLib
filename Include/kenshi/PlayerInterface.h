#pragma once

#include "util/lektor.h"
#include "util/hand.h"
#include "util/OgreUnordered.h"
#include "Enums.h"

#include <ogre/OgreVector2.h>
#include <ogre/OgrePlaneBoundedVolume.h>

namespace MyGUI
{
    class Widget;
};

class FactoryCallbackInterface
{
public:
    // VTable         : (none)
    virtual void factoryObjectCreatedCallback(RootObject* _a1) = 0;// public vtable offset = 0x0 missing arg names
    // no_addr void FactoryCallbackInterface(const class FactoryCallbackInterface & _a1);// public missing arg names
    FactoryCallbackInterface();// public RVA = 0x4EB6A0
    FactoryCallbackInterface* _CONSTRUCTOR();// public RVA = 0x4EB6A0
    // no_addr class FactoryCallbackInterface & operator=(const class FactoryCallbackInterface & _a1);// public missing arg names
};

class ContextMenuGUI;
class RootObject;

// TODO move?
class ContextMenu : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void ContextMenu(const class ContextMenu & _a1);// public missing arg names
    ContextMenu();// public RVA = 0x793750
    ContextMenu* _CONSTRUCTOR();// public RVA = 0x793750
    ~ContextMenu();// public RVA = 0x793800
    void _DESTRUCTOR();// public RVA = 0x793800
    void showContextMenu(bool on, RootObject* what);// public RVA = 0x7A5960
    bool isVisible() const;// public RVA = 0x790B60
    void update();// public RVA = 0x8055A0
    bool rightMouseActivated; // 0x0 Member
    lektor<int> orders; // 0x8 Member
    std::string contextMenuName; // 0x20 Member
    ContextMenuGUI* menuGUI; // 0x48 Member
    ContextMenuGUI* menuGUI2; // 0x50 Member
    void _destroyMenuGUICheck();// private RVA = 0x7AB660
    bool delayedDestroyFlag; // 0x58 Member
    // no_addr class ContextMenu & operator=(const class ContextMenu & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

// TODO move?
class SelectionBox : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    Ogre::Vector2 startPos; // 0x0 Member
    Ogre::PlaneBoundedVolume volume; // 0x8 Member
    MyGUI::Widget* widget; // 0x30 Member
    bool active; // 0x38 Member
    void start(const Ogre::Vector2& m);// public RVA = 0x7F1300
    void update(const Ogre::Vector2& m);// public RVA = 0x7F19D0
    void cancel();// public RVA = 0x7F12B0
    bool isActive() const;// public RVA = 0x7F12D0
    bool contains(const Ogre::Vector3& a, const Ogre::Vector3& b, float radius);// public RVA = 0x7F1370
    bool contains(const Ogre::AxisAlignedBox& box) const;// public RVA = 0x7F1350
    bool contains(const Ogre::Vector3& point, float r) const;// public RVA = 0x7F1320
    // no_addr void SelectionBox(const class SelectionBox & _a1);// public missing arg names
    SelectionBox();// public RVA = 0x7F2A40
    SelectionBox* _CONSTRUCTOR();// public RVA = 0x7F2A40
    ~SelectionBox();// public RVA = 0x7F1260
    void _DESTRUCTOR();// public RVA = 0x7F1260
    // no_addr class SelectionBox & operator=(const class SelectionBox & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class CameraClass;
class LevelEditor;
class Research;
class MoveMarker;
class PlacementObject;
class Character;
class ZoneMap;
class TownBase;
class Faction;
class Platoon;
class GameData;
class InputHandler;
class Building;
class Item;
class RootObjectContainer;

class PlayerInterface : public FactoryCallbackInterface, public Ogre::GeneralAllocatedObject
{
public:
    // FactoryCallbackInterface offset = 0x0, length = 0x8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // no_addr void PlayerInterface(const class PlayerInterface & _a1);// public missing arg names
    PlayerInterface();// public RVA = 0x7F58D0
    PlayerInterface* _CONSTRUCTOR();// public RVA = 0x7F58D0
    ~PlayerInterface();// public RVA = 0x7F9F80
    void _DESTRUCTOR();// public RVA = 0x7F9F80
    CameraClass* getCamera();// public RVA = 0x3E6B40
    void playerSetup(CameraClass* cam);// public RVA = 0x7F1460
    void clearAndReset();// public RVA = 0x7F9280
    virtual void factoryObjectCreatedCallback(RootObject* building) override;// public RVA = 0x4D3190 vtable offset = 0x0
    void _NV_factoryObjectCreatedCallback(RootObject* building);// public RVA = 0x4D3190 vtable offset = 0x0
    void setFaction(Faction* f);// public RVA = 0x8012B0
    Faction* getFaction() const;// public RVA = 0x288FC0
    bool setCurrentPlatoon(Platoon* platoon);// public RVA = 0x7F15A0
    Platoon* getCurrentPlatoon();// public RVA = 0x7F42C0
    RootObjectContainer* getCurrentActivePlatoon();// public RVA = 0x7F44B0
    bool recruit(const lektor<Character*>& characters, bool editor);// public RVA = 0x7FE650
    bool recruit(Character* character, bool editor);// public RVA = 0x6920A0
    ActivePlatoon* createSquad();// public RVA = 0x7F36B0
    ActivePlatoon* getDeadSquad();// public RVA = 0x7F3700
    const hand& getDeadSquadHandle() const;// public RVA = 0x411950
    void update();// public RVA = 0x8003C0
    void updateUT();// public RVA = 0x7F6C80
    bool isBuildMode() const;// public RVA = 0x4D46D0
    void activateObjectPlacementMode(GameData* data);// public RVA = 0x4E0CC0
    // no_addr void setTaskClickMode(enum TaskType _a1, enum itemType _a2);// public missing arg names
    void activateCharacterEditMode(Character* character);// public RVA = 0x7F2410
    bool triggerAreaArrivalDialogue(GameData* area);// public RVA = 0x7FEBE0
    void setCharacterEditMode(bool on);// public RVA = 0x7F34E0
    bool getCharacterEditMode() const;// public RVA = 0x5B0A50
    void unselectAll();// public RVA = 0x7F7B40
    void selectAll();// public RVA = 0x7F7AA0
    void selectObject(RootObject* obj, bool modifier);// public RVA = 0x7F7DA0
    void selectPlayerCharacter(int index, bool modifier, bool track);// public RVA = 0x7F7E50
    void _selectPlayerCharacter(RootObject* obj, bool modifier, bool track);// public RVA = 0x7F7D00
    void activateSelection(RootObject* obj);// public RVA = 0x7F3B70
    const Ogre::Vector3 getCameraCenter() const;// public RVA = 0x7F1700
    float getDistanceFromCamera(const Ogre::Vector3& v) const;// public RVA = 0x7F1730
    float getSquaredDistanceFromCamera(const Ogre::Vector3& v) const;// public RVA = 0x7F17C0
    void startTrackCharacter(RootObject* target);// public RVA = 0x7F41A0
    void stopTrackCharacter();// public RVA = 0x7F1520
    bool isTrackingCharacter() const;// public RVA = 0x7F1580
    void focusCamera(const Ogre::Vector3& pos);// public RVA = 0x7F1850
    void manuallyOrientCamera(const Ogre::Quaternion& rot, float zoom);// public RVA = 0x7F1860
    void focusCameraSelectedCharacter();// public RVA = 0x7F2590
    void toggleLevelEditorOnSelectedTown();// public RVA = 0x7F24C0
    bool isLevelEditMode() const;// public RVA = 0xDEE20
    bool isObjectPlacementMode() const;// public RVA = 0x780940
    void setOrderSelectedCharacters(MessageForB::StandingOrder order);// public RVA = 0x7F2620
    LevelEditor* getLevelEditor();// public RVA = 0x4EB770
    void objectSelected(RootObject* obj, bool select);// public RVA = 0x7F6CC0
    void toggleObjectSelected(RootObject* obj);// public RVA = 0x7F71B0
    bool isObjectSelected(RootObject* obj);// public RVA = 0x7F3AC0
    void unselectPlayerCharacter(RootObject* obj);// public RVA = 0x7F71F0
    void updatePlayerSelection(const hand& oldHandle, const hand& newHandle);// public RVA = 0x7F5EB0
    int getCurrentFloor() const;// public RVA = 0x166E90
    void setCurrentFloor(int floor);// public RVA = 0x7F22D0
    void getAllSelectedObjects(lektor<RootObject*>& out, itemType type);// public RVA = 0x7F5560
    Character* getNearestSelectedCharacterTo(const Ogre::Vector3& pos);// public RVA = 0x7F3940
    Character* getNearestCharacterTo(const Ogre::Vector3& pos);// public RVA = 0x7F1D10
    void newPlayerTaskSelectedCharacters(TaskType t, const hand& targetH, Building* destinationIndoors, const Ogre::Vector3& clickpos, bool addDontClear);// public RVA = 0x7F93F0
    bool getPlayerTaskProbability(TaskType task, RootObject* target, float& probability);// public RVA = 0x7F5380
    void addOrderSelectedCharacters(Building* destinationIndoors, TaskType task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location);// public RVA = 0x7F8BC0
    void addJobSelectedCharacters(TaskType task, RootObject* subject, bool shift, bool add, const Ogre::Vector3& location);// public RVA = 0x7F4830
    void removeJobSelectedCharacters(TaskType t);// public RVA = 0x7F4A20
    void removePermaJobSelectedCharacters(int id);// public RVA = 0x7F4B90
    bool selectedCharactersUnconcious(bool displayMessage);// public RVA = 0x7F5CF0
    bool selectedCharactersLayingLow();// public RVA = 0x7F27C0
    void useSpeedGroup(bool use);// public RVA = 0x7F9810
    void assignSpeedGroup(bool create);// public RVA = 0x7F8560
    bool isEnemy(Character* who);// public RVA = 0x79B980
    bool isFactionKnown(Faction* f) const;// public RVA = 0x7F3860
    void encounterFaction(Faction* faction);// public RVA = 0x7F6C30
    void pickupItem(Item* item);// public RVA = 0x7FA140
    void cycleSquad();// public RVA = 0x7F5120
    void cycleCharacter(int d);// public RVA = 0x7F7ED0
    void stopCharactersMovement();// public RVA = 0x7F5210
    Character* getAnyPlayerCharacter() const;// public RVA = 0x7F19B0
    void getAllPlayerCharacters(lektor<RootObject*>& list);// public RVA = 0x7F1240
    const lektor<Character*>& getAllPlayerCharacters() const;// public RVA = 0x7F1230
    bool isOrderValidForSelection(TaskType task) const;// public RVA = 0x7F1150
    void serialise(GameData* data);// public RVA = 0x7F2C00
    void loadFromSerialise(GameData* data);// public RVA = 0x7F2D50
    bool getInteriorsVisible(Building* building);// public RVA = 0x7F11A0
    std::string factionName; // 0x8 Member
    CameraClass* camera; // 0x30 Member
    Research* technology; // 0x38 Member
    bool selectedObjectsChangedThisFrame; // 0x40 Member
    ContextMenu contextMenu; // 0x48 Member
    SelectionBox selectBox; // 0xA8 Member
    MoveMarker* moveMarker; // 0xE8 Member
    hand selectedCharacter; // 0xF0 Member
    void setVisibilityForReflections(bool set);// public RVA = 0x7F4E70
    class AIOptions
    {
    public:
        AIOptions();// public RVA = 0x8055B0
        AIOptions* _CONSTRUCTOR();// public RVA = 0x8055B0
        void load(GameData* data);// public RVA = 0x3EBA30
        void save(GameData* data);// public RVA = 0x3EB1F0
        bool healAllies; // 0x0 Member
        bool helpAllies; // 0x1 Member
        bool rescueAllies; // 0x2 Member
        bool stayInBase; // 0x3 Member
        bool feedAnimals; // 0x4 Member
        bool shareFood; // 0x5 Member
        bool autoSleep; // 0x6 Member
        bool autoDitchItems; // 0x7 Member
        bool autoSit; // 0x8 Member
        bool ejectEnemies; // 0x9 Member
        bool shootFirst; // 0xA Member
    };
    PlayerInterface::AIOptions aiOptions; // 0x110 Member
    // Typedef        : ZoneMapFloorMap
    // Typedef        : BuildingInteriorSet
    // Typedef        : TownsSet
    void updateFloorVisibility(const lektor<Character*>& characters);// private RVA = 0x7F5FD0
    void resetFloorsVisibility();// private RVA = 0x7F2760
    void setFloorsVisibility(int floor);// private RVA = 0x7F26E0
    void addTaskNearestSelectedCharacter(Building* dest, TaskType t, RootObject* subject, bool shift, const Ogre::Vector3& location, bool noAnimals);// private RVA = 0x7F9C10
    void updateLastMoveWaypointSelectedCharacters(const Ogre::Vector3& location, Building* dest);// private RVA = 0x7F4CF0
    void clearSelection();// private RVA = 0x7F28F0
    void playerControl(InputHandler& key);// private RVA = 0x7FFCA0
    void mouseScan();// private RVA = 0x7FEFF0
    // no_addr void itemInsideScan(class RootObject * & _a1, class Building * _a2, const class Ogre::Ray & _a3);// private missing arg names
    // no_addr void characterInsideScan(class RootObject * & _a1, class Building * _a2, const class Ogre::Ray & _a3);// private missing arg names
    void characterSelected(Character* target);// private RVA = 0x7FA1B0
    void itemSelected(Item* item);// private RVA = 0x7FB1E0
    bool buildingSelected(Building* building, const Ogre::Vector3& position, bool interiorsVisible);// private RVA = 0x7FB480
    void playerMove(const Ogre::Vector3& pos, Building* destBuilding);// private RVA = 0x7F95F0
    bool _isPlayerCharacter(RootObject* obj);// private RVA = 0x7F11E0
    ogre_unordered_map<ZoneMap*, unsigned char>::type zonesVisibilities; // 0x120 Member
    ogre_unordered_set<TownBase*>::type townsActive; // 0x160 Member
    ogre_unordered_set<hand>::type interiorsVisible; // 0x1A0 Member
    unsigned int interiorsVisibleHash; // 0x1E0 Member
    int currentFloor; // 0x1E4 Member
    TaskType currentMouseTask; // 0x1E8 Member
    itemType mouseTaskTypeRestriction; // 0x1EC Member
    bool mouseRightTargetSet; // 0x1F0 Member
    RootObject* mouseRightTarget; // 0x1F8 Member
    float rmouseTimer; // 0x200 Member
    ogre_unordered_set<hand>::type selectedCharacters; // 0x208 Member
    hand selectedObject; // 0x248 Member
    bool onlyAnimalsSelected; // 0x268 Member
    int selectedLoadedLeft; // 0x26C Member
    hand trackedCharacterHandle; // 0x270 Member
    int trackedCharacterFloor; // 0x290 Member
    LevelEditor* levelEditor; // 0x298 Member
    Faction* participant; // 0x2A0 Member
    Platoon* currentPlatoon; // 0x2A8 Member
    lektor<Character*> playerCharacters; // 0x2B0 Member
    hand deadPlayerSquad; // 0x2C8 Member
    PlacementObject* placementObject; // 0x2E8 Member
    bool characterEditorMode; // 0x2F0 Member
    bool mLeftUp; // 0x2F1 Member
    bool mLeftDown; // 0x2F2 Member
    bool mRightUp; // 0x2F3 Member
    bool mRightDown; // 0x2F4 Member
    // no_addr class PlayerInterface & operator=(const class PlayerInterface & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};