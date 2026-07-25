#pragma once

#include "Building.h"
#include <mygui/MyGUI_Widget.h>
#include "../gui/InventoryGUI.h"

class GenericInventoryLayout : public InventoryLayout
{
public:
    // InventoryLayout offset = 0x0, length = 0x3B8
    // no_addr void GenericInventoryLayout(const class GenericInventoryLayout & _a1);// public missing arg names
    GenericInventoryLayout(const std::string& layoutName);// protected RVA = 0x154F90
    GenericInventoryLayout* _CONSTRUCTOR(const std::string& layoutName);// protected RVA = 0x154F90
    GenericInventoryLayout();// protected RVA = 0x154D20
    GenericInventoryLayout* _CONSTRUCTOR();// protected RVA = 0x154D20
    virtual void setSize(int slotsW, int slotsH, bool hasArrange, bool hasType);// protected RVA = 0x14E410 vtable offset = 0x18
    void _NV_setSize(int slotsW, int slotsH, bool hasArrange, bool hasType);// protected RVA = 0x14E410 vtable offset = 0x18
    MyGUI::Widget* arrangeButton; // 0x3B8 Member
    virtual ~GenericInventoryLayout();// public RVA = 0x161F30 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x161F30 vtable offset = 0x0
    // no_addr class GenericInventoryLayout & operator=(const class GenericInventoryLayout & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class UseableStuff : public Building
{
public:
    // Building offset = 0x0, length = 0x360
    // no_addr void UseableStuff(const class UseableStuff & _a1);// public missing arg names
    UseableStuff(GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors);// public RVA = 0x2A0450
    UseableStuff* _CONSTRUCTOR(GameData* _data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors);// public RVA = 0x2A0450
    virtual ~UseableStuff();// public RVA = 0x562850 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x562850 vtable offset = 0x0
    virtual UseableStuff* getUseableStuff() override;// public RVA = 0x2AD8B0 vtable offset = 0x0
    UseableStuff* _NV_getUseableStuff();// public RVA = 0x2AD8B0 vtable offset = 0x0
    virtual InventoryLayout* createInventoryLayout() override;// public RVA = 0x296EE0 vtable offset = 0x0
    InventoryLayout* _NV_createInventoryLayout();// public RVA = 0x296EE0 vtable offset = 0x0
    hand shopOwner; // 0x360 Member
    hand callbackOwner; // 0x380 Member
    virtual void equipItem(const std::string& _a1, Item* _a2) override;// public RVA = 0xF6C90 vtable offset = 0x0 missing arg names
    void _NV_equipItem(const std::string& _a1, Item* _a2);// public RVA = 0xF6C90 vtable offset = 0x0 missing arg names
    virtual void unequipItem(const std::string& _a1, Item* _a2) override;// public RVA = 0xF6CA0 vtable offset = 0x0 missing arg names
    void _NV_unequipItem(const std::string& _a1, Item* _a2);// public RVA = 0xF6CA0 vtable offset = 0x0 missing arg names
    virtual void dropItem(RootObject* what) override;// public RVA = 0x54DEB0 vtable offset = 0x0
    void _NV_dropItem(RootObject* what);// public RVA = 0x54DEB0 vtable offset = 0x0
    virtual bool takeMoney(int n) override;// public RVA = 0x54DDE0 vtable offset = 0x0
    bool _NV_takeMoney(int n);// public RVA = 0x54DDE0 vtable offset = 0x0
    virtual int getMoney() const override;// public RVA = 0x54DE50 vtable offset = 0x0
    int _NV_getMoney() const;// public RVA = 0x54DE50 vtable offset = 0x0
    virtual Inventory* getInventory() const override;// public RVA = 0xF6CB0 vtable offset = 0x0
    Inventory* _NV_getInventory() const;// public RVA = 0xF6CB0 vtable offset = 0x0
    virtual bool canHaveSomeOfThese(GameData* input);// public RVA = 0x296A30 vtable offset = 0x4A0
    bool _NV_canHaveSomeOfThese(GameData* input);// public RVA = 0x296A30 vtable offset = 0x4A0
    virtual bool isAnyInputsEmpty() const;// public RVA = 0x2AD8C0 vtable offset = 0x4A8
    bool _NV_isAnyInputsEmpty() const;// public RVA = 0x2AD8C0 vtable offset = 0x4A8
    virtual bool needsUpdate() override;// public RVA = 0x5492D0 vtable offset = 0x0
    bool _NV_needsUpdate();// public RVA = 0x5492D0 vtable offset = 0x0
    virtual void threadedUpdate() override;// public RVA = 0x298FF0 vtable offset = 0x0
    void _NV_threadedUpdate();// public RVA = 0x298FF0 vtable offset = 0x0
    virtual void operate(Character* who, float _a2);// public RVA = 0x297080 vtable offset = 0x4B0
    void _NV_operate(Character* who, float _a2);// public RVA = 0x297080 vtable offset = 0x4B0
    virtual float calculateEfficiencyMult() const override;// public RVA = 0x296950 vtable offset = 0x0
    float _NV_calculateEfficiencyMult() const;// public RVA = 0x296950 vtable offset = 0x0
    virtual float isOutOfPower() const;// public RVA = 0x2969C0 vtable offset = 0x4B8
    float _NV_isOutOfPower() const;// public RVA = 0x2969C0 vtable offset = 0x4B8
    bool hasProgressBarWhenUsed; // 0x3A0 Member
    float progressBarLevel; // 0x3A4 Member
    virtual int getCostToUse(Character* who);// public RVA = 0x330600 vtable offset = 0x4C0
    int _NV_getCostToUse(Character* who);// public RVA = 0x330600 vtable offset = 0x4C0
    virtual void getGUIData(DatapanelGUI* datapanel, int category) override;// public RVA = 0x3049E0 vtable offset = 0x0
    void _NV_getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x3049E0 vtable offset = 0x0
    virtual void getGUIPower(DatapanelGUI* datapanel, int category);// public RVA = 0x307740 vtable offset = 0x4C8
    void _NV_getGUIPower(DatapanelGUI* datapanel, int category);// public RVA = 0x307740 vtable offset = 0x4C8
    virtual void getGUIEfficiency(DatapanelGUI* datapanel, int category);// public RVA = 0x305BA0 vtable offset = 0x4D0
    void _NV_getGUIEfficiency(DatapanelGUI* datapanel, int category);// public RVA = 0x305BA0 vtable offset = 0x4D0
    virtual void getGUIWorkers(DatapanelGUI* datapanel, int category);// public RVA = 0x307100 vtable offset = 0x4D8
    void _NV_getGUIWorkers(DatapanelGUI* datapanel, int category);// public RVA = 0x307100 vtable offset = 0x4D8
    virtual void getGUIToolTipForGroundResourceEfficiency(lektor<StringPair>& out);// public RVA = 0x3058C0 vtable offset = 0x4E0
    void _NV_getGUIToolTipForGroundResourceEfficiency(lektor<StringPair>& out);// public RVA = 0x3058C0 vtable offset = 0x4E0
    virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract) override;// public RVA = 0x2A1000 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x2A1000 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* wholeState) override;// public RVA = 0x2A12A0 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState* wholeState);// public RVA = 0x2A12A0 vtable offset = 0x0
    virtual HitMaterialType hitByMeleeAttack(CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID) override;// public RVA = 0x296E10 vtable offset = 0x0
    HitMaterialType _NV_hitByMeleeAttack(CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID);// public RVA = 0x296E10 vtable offset = 0x0
    virtual bool isBroken() const override;// public RVA = 0xF6CC0 vtable offset = 0x0
    bool _NV_isBroken() const;// public RVA = 0xF6CC0 vtable offset = 0x0
    virtual void setBroken(bool on) override;// public RVA = 0xF6CD0 vtable offset = 0x0
    void _NV_setBroken(bool on);// public RVA = 0xF6CD0 vtable offset = 0x0
    virtual bool isDisabled() override;// public RVA = 0xF6CE0 vtable offset = 0x0
    bool _NV_isDisabled();// public RVA = 0xF6CE0 vtable offset = 0x0
    virtual CursorType getMouseCursor() override;// public RVA = 0x546F40 vtable offset = 0x0
    CursorType _NV_getMouseCursor();// public RVA = 0x546F40 vtable offset = 0x0
    virtual TaskType getDefaultTask() override;// public RVA = 0x298D80 vtable offset = 0x0
    TaskType _NV_getDefaultTask();// public RVA = 0x298D80 vtable offset = 0x0
    const std::string& getAnimation();// public RVA = 0x296E80
    const std::string& getAnimationKO();// public RVA = 0x296EA0
    const std::string& getAnimationDazed();// public RVA = 0x296EC0
    virtual float getReachRange() const override;// public RVA = 0xF6CF0 vtable offset = 0x0
    float _NV_getReachRange() const;// public RVA = 0xF6CF0 vtable offset = 0x0
    virtual bool dontNeedWorkRightNow() const;// public RVA = 0x2AAF10 vtable offset = 0x4E8
    bool _NV_dontNeedWorkRightNow() const;// public RVA = 0x2AAF10 vtable offset = 0x4E8
    virtual bool isFreeSlot(const hand& h) const;// public RVA = 0xF7BB0 vtable offset = 0x4F0
    bool _NV_isFreeSlot(const hand& h) const;// public RVA = 0xF7BB0 vtable offset = 0x4F0
    virtual bool tryOperate(const hand& h);// public RVA = 0xF7FF0 vtable offset = 0x4F8
    bool _NV_tryOperate(const hand& h);// public RVA = 0xF7FF0 vtable offset = 0x4F8
    virtual bool couldIOperate(const hand& h) const;// public RVA = 0xF7C50 vtable offset = 0x500
    bool _NV_couldIOperate(const hand& h) const;// public RVA = 0xF7C50 vtable offset = 0x500
    void stopOperating(const hand& h);// public RVA = 0x2AC5E0
    const hand& getOccupant() const;// public RVA = 0x28C440
    void occupantHandleChangedEvent(const hand& h);// public RVA = 0x63F200
    // no_addr bool hasOperators();// public
    bool occupantSelection; // 0x3A8 Member
    bool needsOperating; // 0x3A9 Member
    int numOperatorsMax; // 0x3AC Member
    virtual void togglePowerButton(DataPanelLine* _a1);// public RVA = 0x2975B0 vtable offset = 0x508 missing arg names
    void _NV_togglePowerButton(DataPanelLine* _a1);// public RVA = 0x2975B0 vtable offset = 0x508 missing arg names
    virtual void toggleBattButton(DataPanelLine* _a1);// public RVA = 0x297630 vtable offset = 0x510 missing arg names
    void _NV_toggleBattButton(DataPanelLine* _a1);// public RVA = 0x297630 vtable offset = 0x510 missing arg names
    virtual bool isForSale() override;// public RVA = 0xF6D00 vtable offset = 0x0
    bool _NV_isForSale();// public RVA = 0xF6D00 vtable offset = 0x0
    float takePowerFrom(float amount, float frameTime);// public RVA = 0x297420
    float howMuchPowerDoYouWantMax() const;// public RVA = 0x2974B0
    virtual float howMuchPowerDoYouWantForSortingFunction() const;// public RVA = 0x299180 vtable offset = 0x518
    float _NV_howMuchPowerDoYouWantForSortingFunction() const;// public RVA = 0x299180 vtable offset = 0x518
    float howMuchPowerDoYouWantNow() const;// public RVA = 0x297520
    virtual bool needPowerRightNow() const;// public RVA = 0xF6D10 vtable offset = 0x520
    bool _NV_needPowerRightNow() const;// public RVA = 0xF6D10 vtable offset = 0x520
    virtual void givePower(float amount);// public RVA = 0x297580 vtable offset = 0x528
    void _NV_givePower(float amount);// public RVA = 0x297580 vtable offset = 0x528
    void resetPower();// public RVA = 0x296610
    float getMaxPower() const;// public RVA = 0x2971F0
    virtual float getPowerOutput() const;// public RVA = 0x297230 vtable offset = 0x530
    float _NV_getPowerOutput() const;// public RVA = 0x297230 vtable offset = 0x530
    virtual float getFuelConsumptionRate();// public RVA = 0xF6D20 vtable offset = 0x538
    float _NV_getFuelConsumptionRate();// public RVA = 0xF6D20 vtable offset = 0x538
    bool isBattery() const;// public RVA = 0x296630
    bool isGenerator() const;// public RVA = 0x296650
    float getBatteryCharge() const;// public RVA = 0x9254E0
    float getBatteryChargeMax() const;// public RVA = 0x2971A0
    virtual void setupFromData() override;// public RVA = 0x29DFB0 vtable offset = 0x0
    void _NV_setupFromData();// public RVA = 0x29DFB0 vtable offset = 0x0
    virtual void switchPowerOn(bool on) override;// public RVA = 0x296F40 vtable offset = 0x0
    void _NV_switchPowerOn(bool on);// public RVA = 0x296F40 vtable offset = 0x0
    bool hasPower();// public RVA = 0x298EC0
    virtual bool isPowerOn() const override;// public RVA = 0xF6D30 vtable offset = 0x0
    bool _NV_isPowerOn() const;// public RVA = 0xF6D30 vtable offset = 0x0
    bool isRecievesBatteryPower() const;// public RVA = 0x296680
    StatsEnumerated getStatUsed() const;// public RVA = 0x2B4A30
    virtual DoorLock* getDoorLock() override;// public RVA = 0xF6D40 vtable offset = 0x0
    DoorLock* _NV_getDoorLock();// public RVA = 0xF6D40 vtable offset = 0x0
    virtual bool hasDoorLock() const override;// public RVA = 0xF6D50 vtable offset = 0x0
    bool _NV_hasDoorLock() const;// public RVA = 0xF6D50 vtable offset = 0x0
    // no_addr float getSfxTime(int _a1);// public missing arg names
    // no_addr const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & getSfx(int _a1);// public missing arg names
    GameData* getFunctionalityData();// public RVA = 0x296690
    float hungerRate; // 0x3B0 Member
    virtual void setup() override;// protected RVA = 0x553DB0 vtable offset = 0x0
    void _NV_setup();// protected RVA = 0x553DB0 vtable offset = 0x0
    bool _recievesBatteryPower; // 0x3B4 Member
    bool powerOn; // 0x3B5 Member
    bool _isBroken; // 0x3B6 Member
    float batteryOutputStat; // 0x3B8 Member
    float _powerOutputMax; // 0x3BC Member
    float currentPower; // 0x3C0 Member
    float powerTimeStored; // 0x3C4 Member
    float _powerTimeStoreMax; // 0x3C8 Member
    std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > currentOperators; // 0x3D0 Member
    StatsEnumerated usesStat; // 0x3F8 Member
    GameData* functionalityData; // 0x400 Member
    GameData* animation; // 0x408 Member
    GameData* animationKO; // 0x410 Member
    GameData* animationDazed; // 0x418 Member
    float maxUseRange; // 0x420 Member
    float sfxTime[0x2]; // 0x424 Member
    Inventory* inventory; // 0x430 Member
    DoorLock* doorLock; // 0x438 Member
    virtual float getOutputBasedRotationSpeedMult() override;// protected RVA = 0x5479C0 vtable offset = 0x0
    float _NV_getOutputBasedRotationSpeedMult();// protected RVA = 0x5479C0 vtable offset = 0x0
    virtual std::string getGUIPowerEfficiencyToolTipString();// protected RVA = 0x309000 vtable offset = 0x540
    std::string _NV_getGUIPowerEfficiencyToolTipString();// protected RVA = 0x309000 vtable offset = 0x540
    // no_addr class UseableStuff & operator=(const class UseableStuff & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};