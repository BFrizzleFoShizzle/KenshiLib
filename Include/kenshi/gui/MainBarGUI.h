#pragma once

#include "GUIWindow.h"
#include <mygui/common/baselayout/BaseLayout.h>
#include <boost/unordered_map.hpp>
#include <kenshi/util/OgreUnordered.h>
#include "SquadManagementScreen.h"

class RootObjectContainer;
class MedicalDatapanel;
class ToolTip;
class DatapanelGUI;
class PortraitMainItemBox;
class DatapanelGUI;
class MainBarGUI;

// TODO move?
class MainTabPortraitPlatoon : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    MainTabPortraitPlatoon(ActivePlatoon* platoon, MainBarGUI* mainbar);// public RVA = 0x411AD0
    MainTabPortraitPlatoon* _CONSTRUCTOR(ActivePlatoon* platoon, MainBarGUI* mainbar);// public RVA = 0x411AD0
    MainTabPortraitPlatoon();// public RVA = 0x411A80
    MainTabPortraitPlatoon* _CONSTRUCTOR();// public RVA = 0x411A80
    void addTab(MyGUI::TabControl* tabControl, bool visible);// public RVA = 0x415680
    void detach();// public RVA = 0x412570
    void setFlash(bool flash);// public RVA = 0x411B30
    void update();// public RVA = 0x414C90
    PortraitMainItemBox* portraitBox; // 0x0 Member
    ActivePlatoon* platoon; // 0x8 Member
    MyGUI::TabItem* tab; // 0x10 Member
    int tabIndex; // 0x18 Member
    MyGUI::ImageBox* flashImage; // 0x20 Member
    char flashing; // 0x28 Member
    float animationTime; // 0x2C Member
    float currentAlpha; // 0x30 Member
    MainBarGUI* mainbar; // 0x38 Member
    ~MainTabPortraitPlatoon();// public RVA = 0x417320
    void _DESTRUCTOR();// public RVA = 0x417320
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class TownPanel;
class OrdersPanel;
class ToolTipFixed;

class MainBarGUI : public GUIWindow, public wraps::BaseLayout
{
public:
    // GUIWindow offset = 0x0, length = 0x30
    // wraps::BaseLayout offset = 0x30, length = 0xA0
    // Typedef        : PortraitsItemBoxMap
    // Typedef        : DatapanelMap
    // no_addr void MainBarGUI(const class MainBarGUI & _a1);// public missing arg names
    MainBarGUI();// protected RVA = 0x72C1E0
    MainBarGUI* _CONSTRUCTOR();// protected RVA = 0x72C1E0
    virtual ~MainBarGUI();// protected RVA = 0x7275B0 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x7275B0 vtable offset = 0x0
    virtual void clear() override;// public RVA = 0x722140 vtable offset = 0x0
    void _NV_clear();// public RVA = 0x722140 vtable offset = 0x0
    virtual void show(bool on) override;// public RVA = 0x721F00 vtable offset = 0x0
    void _NV_show(bool on);// public RVA = 0x721F00 vtable offset = 0x0
    virtual void update() override;// public RVA = 0x727B80 vtable offset = 0x0
    void _NV_update();// public RVA = 0x727B80 vtable offset = 0x0
    void speedChanged();// public RVA = 0x7236B0
    virtual void autoChangeSelectedObject(const hand& obj) override;// public RVA = 0x728AB0 vtable offset = 0x0
    void _NV_autoChangeSelectedObject(const hand& obj);// public RVA = 0x728AB0 vtable offset = 0x0
    virtual void updateBountyPanelVisibility();// public RVA = 0x71FFE0 vtable offset = 0x68
    void _NV_updateBountyPanelVisibility();// public RVA = 0x71FFE0 vtable offset = 0x68
    void setLevelEditMode(bool on);// public RVA = 0x721B00
    void setLevelEditInteriorMode(bool interiorMode);// public RVA = 0x721AB0
    void pressedKey(unsigned int keycode);// public RVA = 0x7250E0
    PortraitData* getPortrait(const MyGUI::types::TPoint<int>& position);// public RVA = 0x4137C0
    PortraitData* getPortrait(const hand& character);// public RVA = 0x412970
    void updatePortrait(const hand& character);// public RVA = 0x412A40
    void platoonUpdated(RootObjectContainer* platoon, bool charAdded);// public RVA = 0x416030
    void updatePotraitsPlatoon();// public RVA = 0x415100
    void updatePortraits();// public RVA = 0x414EB0
    void refreshPortraitTabs();// public RVA = 0x4159C0
    void updatePortraitSize(ActivePlatoon* platoon);// public RVA = 0x412A60
    void closeMapWindow(MyGUI::Widget* _sender);// public RVA = 0x4A70E0
    void toggleMapWindow(MyGUI::Widget* _sender);// public RVA = 0x71FCD0
    void toggleFactionWindow(MyGUI::Widget* _sender);// public RVA = 0x71FCE0
    void toggleTechWindow(MyGUI::Widget* _sender);// public RVA = 0x71FCF0
    void toggleCraftWindow(MyGUI::Widget* _sender);// public RVA = 0x71FD00
    void toggleSquadWindow(MyGUI::Widget* _sender);// public RVA = 0x71FD10
    void changeFloorButtonUp(MyGUI::Widget* _sender);// public RVA = 0x71FED0
    void changeFloorButtonDown(MyGUI::Widget* _sender);// public RVA = 0x71FF20
    MyGUI::Widget* getPausePanel();// public RVA = 0x71FD80
    MyGUI::Widget* getLoadingPanel();// public RVA = 0x71FD90
    MedicalDatapanel* getMedicalPanel() const;// public RVA = 0x71FDA0
    void ordersPanelFill(const hand& c);// public RVA = 0x7289A0
    void ordersPanelClear();// public RVA = 0x7219A0
    virtual ToolTip* getToolTip();// public RVA = 0x71FD70 vtable offset = 0x70
    ToolTip* _NV_getToolTip();// public RVA = 0x71FD70 vtable offset = 0x70
    DatapanelGUI* getDatapanel(const std::string& id) const;// public RVA = 0x722F60
    const MyGUI::types::TPoint<int>& getBuildingInventoryPosition() const;// public RVA = 0x6EE140
    void setMessagePosition();// public RVA = 0x721220
    void serialise(GameData* data);// public RVA = 0x727920
    void loadFromSerialise(GameData* data);// public RVA = 0x727A40
    const MainTabPortraitPlatoon& getTabPlatoonPortrait(int tabIndex);// private RVA = 0x411E50
    const MainTabPortraitPlatoon& getTabPlatoonPortrait(ActivePlatoon* platoon);// private RVA = 0x411E00
    void portraitChangeSelection(MyGUI::ItemBox* _sender, unsigned __int64 _index, bool follow);// private RVA = 0x413550
    void portraitSelectItemAccept(MyGUI::ItemBox* _sender, unsigned __int64 _index);// private RVA = 0x4135B0
    void portraitNotifyItem(MyGUI::ItemBox* _sender, const MyGUI::IBNotifyItemData& _info);// private RVA = 0x413600
    void tabPlatoonChange(MyGUI::TabControl* _sender, unsigned __int64 _index);// private RVA = 0x411EA0
    void setExtendInfoPanelEnabled(bool enabled);// private RVA = 0x71FE20
    void extendInfoPanel(MyGUI::Widget* _sender, int _a2, int _a3, MyGUI::MouseButton _id);// private RVA = 0x722FE0
    void toggleInventory(MyGUI::Widget* _sender);// private RVA = 0x7237B0
    void toggleStatsWindow(MyGUI::Widget* _sender);// private RVA = 0x71FF70
    void toggleHelpWindow(MyGUI::Widget* _a1);// private RVA = 0x71FFA0 missing arg names
    void changeSpeed(MyGUI::Widget* _sender);// private RVA = 0x723750
    void buildButton(MyGUI::Widget* _sender);// private RVA = 0x71FDB0
    MyGUI::Widget* _getWidget(const std::string& name);// private RVA = 0x723780
    int closeManagerWindowMsg; // 0xD0 Member
    bool isLevelEditMode; // 0xD4 Member
    bool isInteriorLevelEditMode; // 0xD5 Member
    boost::unordered::unordered_map<std::string, DatapanelGUI*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, DatapanelGUI*>, Ogre::GeneralAllocPolicy > > datapanels; // 0xD8 Member
    MyGUI::Widget* bountyPanel; // 0x118 Member
    DatapanelGUI* bountyDatapanel; // 0x120 Member
    TownPanel* townPanel; // 0x128 Member
    MyGUI::TabControl* portraitsTabPanel; // 0x130 Member
    MyGUI::Button* floorDownButton; // 0x138 Member
    MyGUI::Button* floorUpButton; // 0x140 Member
    MyGUI::TextBox* floorText; // 0x148 Member
    Ogre::FastArray<MyGUI::Button*> speedButtons; // 0x150 Member
    MyGUI::TextBox* dayText; // 0x168 Member
    MyGUI::TextBox* moneyLabel; // 0x170 Member
    MyGUI::TextBox* moneyText; // 0x178 Member
    MyGUI::TextBox* timeText; // 0x180 Member
    MedicalDatapanel* medicalPanel; // 0x188 Member
    OrdersPanel* ordersDataPanel; // 0x190 Member
    MyGUI::Button* extendInfoPanelButton; // 0x198 Member
    MyGUI::Widget* extendedInfoPanel; // 0x1A0 Member
    MyGUI::types::TPoint<int> extendedInfoPanelShow; // 0x1A8 Member
    MyGUI::types::TPoint<int> extendedInfoPanelHide; // 0x1B0 Member
    float extendedInfoPanelDuration; // 0x1B8 Member
    bool infoPanelEnabled; // 0x1BC Member
    bool infoPanelExtended; // 0x1BD Member
    MyGUI::Widget* biomePanel; // 0x1C0 Member
    MyGUI::TextBox* biomePanelText; // 0x1C8 Member
    float biomePanelVisibleTimer; // 0x1D0 Member
    float biomeTimer; // 0x1D4 Member
    GameData* lastFrameBiomeGroup; // 0x1D8 Member
    GameData* rememberlastBiomeGroup; // 0x1E0 Member
    hand portraitContextMenuTarget; // 0x1E8 Member
    float portraitContextMenuTimer; // 0x208 Member
    Ogre::FastArray<MainTabPortraitPlatoon> tabPortraits; // 0x210 Member
    char portraitSelectedContextIndex; // 0x228 Member
    ogre_unordered_map<hand, PortraitData*>::type portraits; // 0x230 Member
    boost::unordered::unordered_map<PortraitData*, std::pair<PortraitMainItemBox*, unsigned char>, boost::hash<PortraitData*>, std::equal_to<PortraitData*>, Ogre::STLAllocator<std::pair<PortraitData* const, std::pair<PortraitMainItemBox*, unsigned char> >, Ogre::GeneralAllocPolicy > > portraitsIndices; // 0x270 Member
    bool portraitsUpdating; // 0x2B0 Member
    ToolTipFixed* toolTip; // 0x2B8 Member
    MyGUI::types::TPoint<int> toolTipBasePosition; // 0x2C0 Member
    MyGUI::Widget* pausePanel; // 0x2C8 Member
    MyGUI::Widget* loadingPanel; // 0x2D0 Member
    MyGUI::types::TPoint<int> buildingInventoryPosition; // 0x2D8 Member
    MyGUI::types::TPoint<int> messagePosition; // 0x2E0 Member
    // no_addr class MainBarGUI & operator=(const class MainBarGUI & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};
