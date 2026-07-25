#pragma once

#include "ProductionBuilding.h"
#include <mygui/MyGUI.h>
#include <kenshi/util/YesNoMaybe.h>

class InventoryLayout;
class Faction;
class DatapanelGUI;
class CraftingItem;

// TODO move?
class GameDataGroup
{
public:
    GameDataGroup();// public RVA = 0x2B49E0
    GameDataGroup* _CONSTRUCTOR();// public RVA = 0x2B49E0
    GameData* g1; // 0x0 Member
    GameData* g2; // 0x8 Member
};

class CraftingItem
{
public:
    enum ErrorCode
    {
        CEC_NONE,
        CEC_BENCH_LEVEL,
        CEC_BENCH_NO_RESOURCES,
        CEC_BENCH_NO_WORKERS
    };

    CraftingItem(const CraftingItem& c);// public RVA = 0x2CCCF0
    CraftingItem* _CONSTRUCTOR(const CraftingItem& c);// public RVA = 0x2CCCF0
    CraftingItem(Item* i);// public RVA = 0x2C9D40
    CraftingItem* _CONSTRUCTOR(Item* i);// public RVA = 0x2C9D40
    Item* item; // 0x0 Member
    float endTime; // 0x8 Member
    float progress01; // 0xC Member
    hand smithBench; // 0x10 Member
    float rate; // 0x30 Member
    std::string name; // 0x38 Member
    int lastErrorCode; // 0x60 Member
    YesNoMaybe criticalSuccess; // 0x64 Member
    ~CraftingItem();// public RVA = 0x2C9E60
    void _DESTRUCTOR();// public RVA = 0x2C9E60
    CraftingItem& operator=(const CraftingItem& __that);// public RVA = 0x2CD840
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class CraftingInventoryLayout : public BuildInventoryLayout
{
public:
    // BuildInventoryLayout offset = 0x0, length = 0x440
    // no_addr void CraftingInventoryLayout(const class CraftingInventoryLayout & _a1);// public missing arg names
    CraftingInventoryLayout(const std::string& title, int ins, int outs);// public RVA = 0x157180
    CraftingInventoryLayout* _CONSTRUCTOR(const std::string& title, int ins, int outs);// public RVA = 0x157180
    virtual void setupSections(InventoryGUI* inventoryGUI, std::map<std::string, InventorySectionGUI*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySectionGUI*>, Ogre::GeneralAllocPolicy > >& sections, Inventory* inventory) override;// public RVA = 0x1523D0 vtable offset = 0x0
    void _NV_setupSections(InventoryGUI* inventoryGUI, std::map<std::string, InventorySectionGUI*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySectionGUI*>, Ogre::GeneralAllocPolicy > >& sections, Inventory* inventory);// public RVA = 0x1523D0 vtable offset = 0x0
    void refresh();// public RVA = 0x14DCA0
    void setOutputType(itemType type);// public RVA = 0x14DC80
    void setCraftingName(const std::string& name);// public RVA = 0x14E210
    MyGUI::Button* getQueueButton() const;// public RVA = 0x14DC90
    MyGUI::Button* queueBtn; // 0x440 Member
    MyGUI::TextBox* craftingName; // 0x448 Member
    itemType outputType; // 0x450 Member
    virtual ~CraftingInventoryLayout();// public RVA = 0x161FD0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x161FD0 vtable offset = 0x0
    // no_addr class CraftingInventoryLayout & operator=(const class CraftingInventoryLayout & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class CraftingBuilding : public ProductionBuilding
{
public:
    // ProductionBuilding offset = 0x0, length = 0x490
    // no_addr void CraftingBuilding(const class CraftingBuilding & _a1);// public missing arg names
    CraftingBuilding(GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors);// public RVA = 0x2BE430
    CraftingBuilding* _CONSTRUCTOR(GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors);// public RVA = 0x2BE430
    virtual ~CraftingBuilding();// public RVA = 0x2B62E0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x2B62E0 vtable offset = 0x0
    virtual InventoryLayout* createInventoryLayout() override;// public RVA = 0x29B030 vtable offset = 0x0
    InventoryLayout* _NV_createInventoryLayout();// public RVA = 0x29B030 vtable offset = 0x0
    virtual void update() override;// public RVA = 0x2B51D0 vtable offset = 0x0
    void _NV_update();// public RVA = 0x2B51D0 vtable offset = 0x0
    virtual void operate(Character* stats, float _amount) override;// public RVA = 0x2B5590 vtable offset = 0x0
    void _NV_operate(Character* stats, float _amount);// public RVA = 0x2B5590 vtable offset = 0x0
    virtual void givePower(float amount) override;// public RVA = 0x2B4D10 vtable offset = 0x0
    void _NV_givePower(float amount);// public RVA = 0x2B4D10 vtable offset = 0x0
    virtual void getGUIData(DatapanelGUI* datapanel, int category) override;// public RVA = 0x2FEBC0 vtable offset = 0x0
    void _NV_getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x2FEBC0 vtable offset = 0x0
    virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract) override;// public RVA = 0x2B7F90 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x2B7F90 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* wholeState) override;// public RVA = 0x2B8600 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState* wholeState);// public RVA = 0x2B8600 vtable offset = 0x0
    virtual bool hasCraftingQueued() const;// public RVA = 0x2B4D60 vtable offset = 0x5D8
    bool _NV_hasCraftingQueued() const;// public RVA = 0x2B4D60 vtable offset = 0x5D8
    virtual bool isProductionFull() override;// public RVA = 0x2B4E70 vtable offset = 0x0
    bool _NV_isProductionFull();// public RVA = 0x2B4E70 vtable offset = 0x0
    virtual GameData* getProductionItemData() override;// public RVA = 0x2B5160 vtable offset = 0x0
    GameData* _NV_getProductionItemData();// public RVA = 0x2B5160 vtable offset = 0x0
    virtual int getCurrentProductionQuantity() override;// public RVA = 0x2B4C90 vtable offset = 0x0
    int _NV_getCurrentProductionQuantity();// public RVA = 0x2B4C90 vtable offset = 0x0
    virtual bool isAnyInputsInvalidType() const override;// public RVA = 0x2B50B0 vtable offset = 0x0
    bool _NV_isAnyInputsInvalidType() const;// public RVA = 0x2B50B0 vtable offset = 0x0
    virtual void newCraftingButton(MyGUI::Widget* _sender);// public RVA = 0x2B4BE0 vtable offset = 0x5E0
    void _NV_newCraftingButton(MyGUI::Widget* _sender);// public RVA = 0x2B4BE0 vtable offset = 0x5E0
    void addFinishedCraftItem(Item* what);// public RVA = 0x2BC610
    void notifyCraftFailiure();// public RVA = 0x796920
    virtual bool tryOperate(const hand& h) override;// public RVA = 0x2B5740 vtable offset = 0x0
    bool _NV_tryOperate(const hand& h);// public RVA = 0x2B5740 vtable offset = 0x0
    static GameData* playerManufacturerData();// public RVA = 0x2CDB90
    void getAvailableCrafts(lektor<GameDataGroup>& out);// public RVA = 0x2BB870
    CraftingItem* _addCraft(GameData* basedata, GameData* matdata, float progress, YesNoMaybe crit);// public RVA = 0x2B57F0
    void _removeCraft(int index);// public RVA = 0x2B6570
    CraftingItem* getCraft(int id);// public RVA = 0x2B53E0
    void destroyProductionItem();// public RVA = 0x2B4BB0
    // no_addr enum itemType getItemCategory();// public
    // no_addr enum itemType getSecondaryItemCategory();// public
    int maxCraftLevel; // 0x490 Member
    std::deque<CraftingItem, std::allocator<CraftingItem> > crafting; // 0x498 Member
    itemType specialCraftItemType; // 0x4C8 Member
    bool repeat; // 0x4CC Member
    hand whosCrafting; // 0x4D0 Member
    GameData* predictCraftersBestWeapon(const hand& who, int levelcap);// public RVA = 0x2BAB70
    float calculateCriticalChance(Character* smith);// public RVA = 0x2B5450
    GameData* getCriticalSuccessWeapon(int normalWeaponLevel);// public RVA = 0x2BAE00
    virtual void getItemsWeWantRidOf(lektor<GameData*>& out, bool looting) override;// public RVA = 0x2B4FA0 vtable offset = 0x0
    void _NV_getItemsWeWantRidOf(lektor<GameData*>& out, bool looting);// public RVA = 0x2B4FA0 vtable offset = 0x0
    virtual bool canHaveSomeOfThese(GameData* these) override;// public RVA = 0x2985D0 vtable offset = 0x0
    bool _NV_canHaveSomeOfThese(GameData* these);// public RVA = 0x2985D0 vtable offset = 0x0
    virtual void setupFromData() override;// protected RVA = 0x2B95F0 vtable offset = 0x0
    void _NV_setupFromData();// protected RVA = 0x2B95F0 vtable offset = 0x0
    virtual void updateOutput(float rate) override;// protected RVA = 0x2BE680 vtable offset = 0x0
    void _NV_updateOutput(float rate);// protected RVA = 0x2BE680 vtable offset = 0x0
    float getPlayerCraftedWeaponLevel(GameData* matspec);// protected RVA = 0x2B7DF0
    virtual void getGUIState(DatapanelGUI* datapanel, int category) override;// protected RVA = 0x3011F0 vtable offset = 0x0
    void _NV_getGUIState(DatapanelGUI* datapanel, int category);// protected RVA = 0x3011F0 vtable offset = 0x0
    virtual void updateInventoryWindow() override;// protected RVA = 0x2B5C60 vtable offset = 0x0
    void _NV_updateInventoryWindow();// protected RVA = 0x2B5C60 vtable offset = 0x0
    virtual void setProductionItem(GameData* itemData, int stack, float progress01) override;// protected RVA = 0x2BAFC0 vtable offset = 0x0
    void _NV_setProductionItem(GameData* itemData, int stack, float progress01);// protected RVA = 0x2BAFC0 vtable offset = 0x0
    bool itemCrafted; // 0x4F0 Member
    bool failiureNotified; // 0x4F1 Member
    GameData* biggestCraftableItem; // 0x4F8 Member
    Item* outItem; // 0x500 Member
    lektor<Item*> inItems; // 0x508 Member
    ogre_unordered_map<GameData*, float>::type partialItems; // 0x520 Member
    // no_addr class CraftingBuilding & operator=(const class CraftingBuilding & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};