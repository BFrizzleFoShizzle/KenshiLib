#pragma once

#include <mygui/common/baselayout/BaseLayout.h>
#include <mygui/common/itembox/BaseItemBox.h>
#include <mygui/common/itembox/BaseCellView.h>
#include <kenshi/util/lektor.h>
#include <boost/function.hpp>
#include <boost/thread/shared_mutex.hpp>

class GameData;
class Platoon;
class hand;
class DatapanelGUI;
class SquadManagementScreen;
class MapScreen;
class FactionsScreen;
class ResearchItem;

// TODO move?
enum MessageLogColor
{
    ML_NORMAL,
    ML_PLAYER,
    ML_SYSTEM
};

// TODO move?
template<typename T>
class ReorderableListItem : public wraps::BaseCellView<T>, public Ogre::GeneralAllocatedObject
{
public:
    // wraps::BaseCellView<CraftingQueue::CraftItemViewData> offset = 0x0, length = 0xA0
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xA1, length = 0x1
    // no_addr void ReorderableListItem<CraftingQueue::CraftItemViewData>(const class ReorderableListItem<CraftingQueue::CraftItemViewData> & _a1);// public missing arg names
    ReorderableListItem<T>(MyGUI::Widget* parent);// public RVA = 0x2D3330
    //ReorderableListItem<T>* _CONSTRUCTOR(MyGUI::Widget* parent);// public RVA = 0x2D3330
    virtual ~ReorderableListItem<T>();// public RVA = 0x2D3720 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x2D3720 vtable offset = 0x0
    void update(const MyGUI::IBDrawItemInfo& info, const T& data);// public RVA = 0x2CC4B0
    static void getCellDimension(MyGUI::Widget* _sender, MyGUI::types::TCoord<int>& _coord, bool _drop);// public RVA = 0x2C75F0
    // no_addr class MyGUI::Widget * getWidget();// public
    MyGUI::TextBox* itemText; // 0xA8 Member
    MyGUI::TextBox* itemValue; // 0xB0 Member
    MyGUI::Widget* progress; // 0xB8 Member
    MyGUI::Button* removeButton; // 0xC0 Member
    int itemIndex; // 0xC8 Member
    boost::function<void __cdecl(int)> removeCallback; // 0xD0 Member
    void onRemove(MyGUI::Widget* _a1);// private RVA = 0x2CFA90 missing arg names
    void onMouseMove(MyGUI::Widget* w, int x, int y);// private RVA = 0x2CD670
    // no_addr class ReorderableListItem<CraftingQueue::CraftItemViewData> & operator=(const class ReorderableListItem<CraftingQueue::CraftItemViewData> & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

// TODO move?
template<typename T1, typename T2>
class ReorderableList : public wraps::BaseItemBox<ReorderableListItem<T2> >, public Ogre::GeneralAllocatedObject
{
public:
    // wraps::BaseItemBox<ReorderableListItem<CraftingQueue::CraftItemViewData> > offset = 0x0, length = 0xF8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xF9, length = 0x1
    // no_addr void ReorderableList<std::deque<CraftingItem,std::allocator<CraftingItem> >,CraftingQueue::CraftItemViewData>(const class ReorderableList<std::deque<CraftingItem,std::allocator<CraftingItem> >,CraftingQueue::CraftItemViewData> & _a1);// public missing arg names
    ReorderableList(MyGUI::Widget* parent);// public RVA = 0x2D45E0
    void setData(T1& data);// public RVA = 0x2D3860
    void clear();// public RVA = 0x2C5780
    void refresh(bool force);// public RVA = 0x2D3BA0
    MyGUI::delegates::CDelegate2<int, int> eventReordered; // 0x100 Member
    MyGUI::delegates::CDelegate2<int, T2 const&> eventRemove; // 0x108 Member
    MyGUI::delegates::CDelegate3<int, int, bool&> eventValidate; // 0x110 Member
    void notifyStartDrop(wraps::BaseLayout* sender, wraps::DDItemInfo info, bool& result);// protected RVA = 0x2C4060
    void notifyRequestDrop(wraps::BaseLayout* sender, wraps::DDItemInfo info, bool& result);// protected RVA = 0x2C7400
    void notifyEndDrop(wraps::BaseLayout* sender, wraps::DDItemInfo info, bool result);// protected RVA = 0x2D3CB0
    void notifyRemoved(int index);// protected RVA = 0x2D3200
    T1* data; // 0x118 Member
    virtual ~ReorderableList() override;// public RVA = 0x2D47E0 vtable offset = 0x0
    // TODO destructor NV ~ReorderableList();// public RVA = 0x2D47E0 vtable offset = 0x0
    // no_addr class ReorderableList<std::deque<CraftingItem,std::allocator<CraftingItem> >,CraftingQueue::CraftItemViewData> & operator=(const class ReorderableList<std::deque<CraftingItem,std::allocator<CraftingItem> >,CraftingQueue::CraftItemViewData> & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class CraftingQueue;
class ToolTip;

class ManagementScreen : public wraps::BaseLayout
{
public:
    // wraps::BaseLayout offset = 0x0, length = 0xA0
    static ManagementScreen* getSingleton();// public RVA = 0x2967F0
    virtual ~ManagementScreen();// public RVA = 0x4923C0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x4923C0 vtable offset = 0x0
    void update();// public RVA = 0x49AF60
    void clear();// public RVA = 0x49A330
    bool getVisible();// public RVA = 0x48B3F0
    void setVisible(bool on, int tab);// public RVA = 0x49BA90
    void closeEverythingButton(MyGUI::Window* _widget, const std::string& _name);// public RVA = 0x48B3D0
    void tabCallback(MyGUI::TabControl* _sender, unsigned __int64 _index);// public RVA = 0x49B810
    int getCurrentTab();// public RVA = 0x48B410
    MyGUI::TabItem* getTab(int index) const;// public RVA = 0x48B430
    MyGUI::Widget* getWidget(const std::string& name);// public RVA = 0x48F560
    void refresh(GameData* current, float progress);// public RVA = 0x48BA30
    void refreshResearchList();// public RVA = 0x499D40
    void refreshResearchRate();// public RVA = 0x494370
    void refreshDiplomacy();// public RVA = 0x499D20
    void refreshSquads();// public RVA = 0x49B7A0
    // no_addr void printResearchQueue(class DatapanelGUI * _a1, int _a2);// public missing arg names
    void refreshMap(bool centerCamera);// public RVA = 0x49ADD0
    // no_addr void refreshMapSquads();// public
    void showRoads(bool v);// public RVA = 0x494500
    void addSquadToMap(Platoon* squad);// public RVA = 0x494520
    void removeSquadFromMap(Platoon* squad);// public RVA = 0x48F510
    void addMessage(const std::string& owner, const std::string& message, MessageLogColor isPlayer);// public RVA = 0x499AF0
    void resetSquads();// public RVA = 0x48CFC0
    void refreshMessages();// public RVA = 0x4999B0
    void refreshAI();// public RVA = 0x494560
    void setCraftingBench(const hand& buildingHandle);// public RVA = 0x48B4A0
    // no_addr class Ogre::Vector2 worldToMapCoords(const class Ogre::Vector3 & _a1);// public missing arg names
    static void printResearch(DatapanelGUI* panel, GameData* d, const std::string& listname, const std::string& displayname, int cat);// public RVA = 0x48E440
    void showDebugMarker(const Ogre::Vector3& p);// public RVA = 0x48C0E0
    static ManagementScreen* singleton; // RVA = 0x212C428 Static Member
    // no_addr void ManagementScreen(const class ManagementScreen & _a1);// public missing arg names
    ManagementScreen();// protected RVA = 0x49EE30
    ManagementScreen* _CONSTRUCTOR();// protected RVA = 0x49EE30
    void updateResearchListRate();// protected RVA = 0x48B490
    void refreshResearchListDescription();// protected RVA = 0x495680
    void researchTypeSelect(MyGUI::ListBox* _sender, unsigned __int64 index);// protected RVA = 0x49AE60
    void addButtonPress(MyGUI::Widget* _sender, int _a2, int _a3, MyGUI::MouseButton _a4);// protected RVA = 0x496F40
    void removeButtonPress(MyGUI::Widget* _sender, int _a2, int _a3, MyGUI::MouseButton _a4);// protected RVA = 0x49A1B0
    void mouseOverCallback(MyGUI::Widget* _sender, int _a2, int _a3);// protected RVA = 0x48D0C0
    SquadManagementScreen* squadScreen; // 0xA0 Member
    MapScreen* mapScreen; // 0xA8 Member
    FactionsScreen* factionScreen; // 0xB0 Member
    MyGUI::ListBox* researchCategoriesListBox; // 0xB8 Member
    DatapanelGUI* availableList; // 0xC0 Member
    DatapanelGUI* info; // 0xC8 Member
    DatapanelGUI* info2; // 0xD0 Member
    std::string techCategory; // 0xD8 Member
    GameData* currentResearch; // 0x100 Member
    MyGUI::EditBox* researchBenchMessage; // 0x108 Member
    bool researchDescriptionUpdateRequest; // 0x110 Member
    lektor<GameData*> currentCategoryList; // 0x118 Member
    float lastResearchRate; // 0x130 Member
    struct TechItemViewData
    {
        ResearchItem* item; // 0x0 Member
        boost::function<void(int)> removeCallback; // 0x8 Member
        const std::string& getName() const;// public RVA = 0x4A6D60
        std::string getValue() const;// public RVA = 0x48C7B0
        float getProgress() const;// public RVA = 0x48B450
        void setItem(ResearchItem& i);// public RVA = 0x4A6D70
        TechItemViewData(const ManagementScreen::TechItemViewData& __that);// public RVA = 0x4B76E0
        TechItemViewData* _CONSTRUCTOR(const ManagementScreen::TechItemViewData& __that);// public RVA = 0x4B76E0
        TechItemViewData();// public RVA = 0x4BA030
        TechItemViewData* _CONSTRUCTOR();// public RVA = 0x4BA030
        ~TechItemViewData();// public RVA = 0x4B6A00
        void _DESTRUCTOR();// public RVA = 0x4B6A00
        // no_addr struct ManagementScreen::TechItemViewData & operator=(const struct ManagementScreen::TechItemViewData & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    ReorderableList<std::deque<ResearchItem, Ogre::STLAllocator<ResearchItem, Ogre::GeneralAllocPolicy > >, ManagementScreen::TechItemViewData>* todoList; // 0x138 Member
    void researchQueueTooltip(wraps::BaseLayout* _a1, const MyGUI::ToolTipInfo& _a2, ManagementScreen::TechItemViewData data);// protected RVA = 0x48CC90
    void researchRemoved(int _a1, const ManagementScreen::TechItemViewData& item);// protected RVA = 0x49A2D0
    void researchValidateOrder(int a, int b, bool& result);// protected RVA = 0x49EBA0
    CraftingQueue* craftingQueue; // 0x140 Member
    MyGUI::EditBox* messagesTextBox; // 0x148 Member
    std::basic_ostringstream<char, std::char_traits<char>, std::allocator<char> > messagesStream; // 0x150 Member
    bool messagesUpdated; // 0x238 Member
    boost::shared_mutex messagesMutex; // 0x240 Member
    std::string messagesPlayerColor; // 0x260 Member
    std::string messagesNPCColor; // 0x288 Member
    DatapanelGUI* aiScreen; // 0x2B0 Member
    ToolTip* aiToolTip; // 0x2B8 Member
    ToolTip* toolTip; // 0x2C0 Member
    MyGUI::Window* window; // 0x2C8 Member
    MyGUI::TabControl* tabs; // 0x2D0 Member
    // no_addr class ManagementScreen & operator=(const class ManagementScreen & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};