#pragma once

#include <mygui/common/itembox/BaseItemBox.h>
#include <mygui/common/itembox/BaseCellView.h>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <kenshi/Enums.h>
#include <kenshi/util/hand.h>
#include <kenshi/util/lektor.h>

class Tasker;
class OrdersPanel;

// TODO move?
class OrderData : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void OrderData(const class OrderData & _a1);// public missing arg names
    OrderData();// public RVA = 0x721B50
    OrderData* _CONSTRUCTOR();// public RVA = 0x721B50
    void set(const Tasker* _task, int _index, bool _enabled);// public RVA = 0x7251C0
    void updateText();// public RVA = 0x723AE0
    const Tasker* task; // 0x0 Member
    int index; // 0x8 Member
    std::string text; // 0x10 Member
    bool enabled; // 0x38 Member
    ~OrderData();// public RVA = 0x737AC0
    void _DESTRUCTOR();// public RVA = 0x737AC0
    OrderData& operator=(const OrderData& __that);// public RVA = 0x739490
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

// TODO move?
class OrderCellView : public wraps::BaseCellView<OrderData*>, public Ogre::GeneralAllocatedObject
{
public:
    // wraps::BaseCellView<OrderData *> offset = 0x0, length = 0xA0
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xA1, length = 0x1
    // no_addr void OrderCellView(const class OrderCellView & _a1);// public missing arg names
    OrderCellView(MyGUI::Widget* parent);// public RVA = 0x728B80
    OrderCellView* _CONSTRUCTOR(MyGUI::Widget* parent);// public RVA = 0x728B80
    virtual ~OrderCellView();// public RVA = 0x721F90 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x721F90 vtable offset = 0x0
    void update(const MyGUI::IBDrawItemInfo& _info, OrderData* _data);// public RVA = 0x722D10
    static void getCellDimension(MyGUI::Widget* _sender, MyGUI::types::TCoord<int>& _coord, bool _drop);// public RVA = 0x7212C0
    MyGUI::Widget* getWidget() const;// public RVA = 0x720160
    MyGUI::TextBox* orderText; // 0xA8 Member
    MyGUI::Button* removeButton; // 0xB0 Member
    void onRemove(MyGUI::Widget* _a1);// private RVA = 0x7256E0 missing arg names
    void resize();// private RVA = 0x721260
    OrderData* data; // 0xB8 Member
    static MyGUI::types::TSize<int> CellSize; // RVA = 0x1F44128 Static Member
    static OrdersPanel* ordersPanel; // RVA = 0x212FB48 Static Member
    // no_addr class OrderCellView & operator=(const class OrderCellView & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class OrdersItemBox : public wraps::BaseItemBox<OrderCellView>, public Ogre::GeneralAllocatedObject
{
public:
    // wraps::BaseItemBox<OrderCellView> offset = 0x0, length = 0xF8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xF9, length = 0x1
    // no_addr void OrdersItemBox(const class OrdersItemBox & _a1);// public missing arg names
    OrdersItemBox(MyGUI::Widget* parent);// public RVA = 0x72A320
    OrdersItemBox* _CONSTRUCTOR(MyGUI::Widget* parent);// public RVA = 0x72A320
    virtual ~OrdersItemBox();// public RVA = 0x73DE60 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x73DE60 vtable offset = 0x0
    // no_addr class OrdersItemBox & operator=(const class OrdersItemBox & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class MainBarGUI;
class Character;

class OrdersPanel : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void OrdersPanel(const class OrdersPanel & _a1);// public missing arg names
    OrdersPanel(MainBarGUI* mainbar, MyGUI::Widget* panel);// public RVA = 0x72A370
    OrdersPanel* _CONSTRUCTOR(MainBarGUI* mainbar, MyGUI::Widget* panel);// public RVA = 0x72A370
    ~OrdersPanel();// public RVA = 0x723560
    void _DESTRUCTOR();// public RVA = 0x723560
    void update(Character* character);// public RVA = 0x725760
    void clear();// public RVA = 0x7212E0
    void command(int cmd);// public RVA = 0x721510
    void refreshOrders();// private RVA = 0x7251E0
    void moveJob(int orderIdx, int targetIdx);// private RVA = 0x720170
    void removeJob(OrderData* data);// private RVA = 0x7253D0
    void notifyStartDropOrder(wraps::BaseLayout* _sender, wraps::DDItemInfo _info, bool& _result);// private RVA = 0x7201C0
    void notifyRequestDropOrder(wraps::BaseLayout* _sender, wraps::DDItemInfo _info, bool& _result);// private RVA = 0x7201E0
    void notifyEndDropOrder(wraps::BaseLayout* _sender, wraps::DDItemInfo _info, bool _result);// private RVA = 0x725420
    void toggleStealth(MyGUI::Widget* _sender);// private RVA = 0x720240
    void toggleRanged(MyGUI::Widget* _sender);// private RVA = 0x720380
    void setSpeed(MoveSpeed moveSpeed);// private RVA = 0x721330
    void setSpeedImage(MoveSpeed moveSpeed);// private RVA = 0x721300
    void speedPrevious(MyGUI::Widget* _sender);// private RVA = 0x7213B0
    void speedNext(MyGUI::Widget* _sender);// private RVA = 0x721460
    void blockmodeButton(MyGUI::Widget* _sender);// private RVA = 0x720310
    void holdButtonCallback(MyGUI::Widget* _sender);// private RVA = 0x720400
    void passiveButtonCallback(MyGUI::Widget* _sender);// private RVA = 0x720470
    void chaseButtonCallback(MyGUI::Widget* _sender);// private RVA = 0x7204E0
    void tauntButtonCallback(MyGUI::Widget* _sender);// private RVA = 0x720550
    void medicButton(MyGUI::Widget* _sender);// private RVA = 0x7F99C0
    void liftButton(MyGUI::Widget* _sender);// private RVA = 0x7205C0
    void prospectingButton(MyGUI::Widget* _sender);// private RVA = 0x720630
    hand ordersCharacter; // 0x0 Member
    OrdersItemBox* ordersItemBox; // 0x20 Member
    int ordersItemWidth; // 0x28 Member
    int ordersItemBoxScrollBarSize; // 0x2C Member
    int ordersItemBoxMaxVisible; // 0x30 Member
    MyGUI::Widget* ordersEmptyPanel; // 0x38 Member
    lektor<OrderData> orders; // 0x40 Member
    MyGUI::Button* blocksCheckbox; // 0x58 Member
    MyGUI::Button* holdCheckBox; // 0x60 Member
    MyGUI::Button* passiveCheckBox; // 0x68 Member
    MyGUI::Button* chaseCheckBox; // 0x70 Member
    MyGUI::Button* tauntCheckBox; // 0x78 Member
    MyGUI::Button* rangedCheckBox; // 0x80 Member
    MyGUI::Button* stealthCheckBox; // 0x88 Member
    MyGUI::Button* speedPrevButton; // 0x90 Member
    MyGUI::Button* speedNextButton; // 0x98 Member
    MyGUI::ImageBox* speedImagePanel; // 0xA0 Member
    Ogre::vector<std::string>::type speedImageNames; // 0xA8 Member
    char speedImageNamesIdx; // 0xC8 Member
    // no_addr class OrdersPanel & operator=(const class OrdersPanel & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};