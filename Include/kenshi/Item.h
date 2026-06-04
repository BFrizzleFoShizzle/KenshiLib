#pragma once

#include "RootObject.h"
#include "util/YesNoMaybe.h"
#include "util/TimeOfDay.h"
#include "util/OgreUnordered.h"
#include "util/iVector2.h"
#include <ogre/OgreVector4.h>
#include <ogre/OgreColourValue.h>

class BuildingItemGroup;
class InventorySection;

class InventoryItemBase : public RootObject, public Ogre::GeneralAllocatedObject
{
public:
	// RootObject offset = 0x0, length = 0xC0
	// Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xC0, length = 0x1
	virtual void activate(bool _a1, YesNoMaybe _a2) = 0;// public vtable offset = 0x230 missing arg names
	virtual void activate(bool _a1, const Ogre::Vector3& _a2, const Ogre::Quaternion& _a3, bool _a4, YesNoMaybe _a5, bool _a6) = 0;// public vtable offset = 0x228 missing arg names
	virtual void deactivate() = 0;// public vtable offset = 0x238
	virtual void resetAfterCopy() = 0;// public vtable offset = 0x240
	void resetCharges(bool randomise);// public RVA = 0x75C360
	void getStolenItemGUIInfo(Ogre::vector<StringPair>::type& lines);// public RVA = 0x79FC40
	void getBuyBackGUIInfo(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7A0140
	itemType getItemType() const;// public RVA = 0x296710
	virtual float getItemWeightSingle() const;// public RVA = 0xD20E0 vtable offset = 0x248
	float _NV_getItemWeightSingle() const;// public RVA = 0xD20E0 vtable offset = 0x248
	virtual float getItemWeight() const;// public RVA = 0xD20F0 vtable offset = 0x250
	float _NV_getItemWeight() const;// public RVA = 0xD20F0 vtable offset = 0x250
	virtual GameData* _serialise(GameDataContainer* _a1, itemType _a2) = 0;// public vtable offset = 0x258 missing arg names
	virtual void _loadFromSerialise(GameDataContainer* _a1, GameData* _a2) = 0;// public vtable offset = 0x260 missing arg names
	virtual GameSaveState serialise(GameDataContainer* _a1, GameData* _a2, PosRotPair* _a3) override = 0;// public vtable offset = 0x0 missing arg names
	virtual void loadFromSerialise(GameSaveState* _a1) override = 0;// public vtable offset = 0x0 missing arg names
	virtual GameData* serialiseInInventory(GameDataContainer* _a1, GameData* _a2) = 0;// public vtable offset = 0x268 missing arg names
	virtual void loadFromSerialiseInInventory(GameDataContainer* _a1, GameData* _a2) = 0;// public vtable offset = 0x270 missing arg names
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7ACED0 vtable offset = 0x278
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7ACED0 vtable offset = 0x278
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x79E270 vtable offset = 0x280
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x79E270 vtable offset = 0x280
	virtual void getGUIData(DatapanelGUI* datapanel, int category) override;// public RVA = 0x794060 vtable offset = 0x0
	void _NV_getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x794060 vtable offset = 0x0
	int getAvgPrice();// public RVA = 0x790310
	virtual int getValueSingle(bool isPlayer) const;// public RVA = 0x7A7D30 vtable offset = 0x288
	int _NV_getValueSingle(bool isPlayer) const;// public RVA = 0x7A7D30 vtable offset = 0x288
	virtual int getValueAll(bool isPlayer) const;// public RVA = 0x790350 vtable offset = 0x290
	int _NV_getValueAll(bool isPlayer) const;// public RVA = 0x790350 vtable offset = 0x290
	virtual int getMaxAffordableNum(int cashLimit, bool isPlayer);// public RVA = 0x75C3B0 vtable offset = 0x298
	int _NV_getMaxAffordableNum(int cashLimit, bool isPlayer);// public RVA = 0x75C3B0 vtable offset = 0x298
	int isStackable(InventorySection* section) const;// public RVA = 0x75CE80
	bool canStackWith(InventoryItemBase* other) const;// public RVA = 0x75C260
	virtual Inventory* getInventory() const override;// public RVA = 0x767960 vtable offset = 0x0
	Inventory* _NV_getInventory() const;// public RVA = 0x767960 vtable offset = 0x0
	virtual bool isSameAs(InventoryItemBase* who) const;// public RVA = 0x75C300 vtable offset = 0x2A0
	bool _NV_isSameAs(InventoryItemBase* who) const;// public RVA = 0x75C300 vtable offset = 0x2A0
	bool onGround() const;// public RVA = 0x37D770
	void addQuantity(int& amount, Item* addedItem, InventorySection* section);// public RVA = 0x75D010
	virtual const hand& getProperOwner() const;// public RVA = 0xD2110 vtable offset = 0x2A8
	const hand& _NV_getProperOwner() const;// public RVA = 0xD2110 vtable offset = 0x2A8
	virtual void setProperOwner(const hand& h);// public RVA = 0xD2120 vtable offset = 0x2B0
	void _NV_setProperOwner(const hand& h);// public RVA = 0xD2120 vtable offset = 0x2B0
	bool isResearchArtifact() const;// public RVA = 0x166EB0
	virtual int getLevel() const;// public RVA = 0x767970 vtable offset = 0x2B8
	int _NV_getLevel() const;// public RVA = 0x767970 vtable offset = 0x2B8
	GameData* manufacturerData; // 0xC0 Member
	GameData* materialData; // 0xC8 Member
	GameData* coloriseData; // 0xD0 Member
	bool isInInventory; // 0xD8 Member
	iVector2 inventoryPos; // 0xDC Member
	std::string inventorySection; // 0xE8 Member
	AttachSlot slotType; // 0x110 Member
	float originalFullChargeAmount; // 0x114 Member
	float chargesLeft; // 0x118 Member
	float quality; // 0x11C Member
	float weight; // 0x120 Member
	ItemFunction itemFunction; // 0x124 Member
	bool isTradeItem; // 0x128 Member
	bool isEquipped; // 0x129 Member
	bool isUnique; // 0x12A Member
	int quantity; // 0x12C Member
	int itemWidth; // 0x130 Member
	int itemHeight; // 0x134 Member
	bool deathItem; // 0x138 Member
	const char* getItemSound() const;// public RVA = 0x75D150
	bool isStolen(bool includeUnknown) const;// public RVA = 0x79D2F0
	// no_addr void InventoryItemBase(const class InventoryItemBase & _a1);// public missing arg names
	InventoryItemBase(GameData* dat, hand _handle, GameData* manufacturerData, GameData* materialData);// protected RVA = 0x75E8E0
	InventoryItemBase* _CONSTRUCTOR(GameData* dat, hand _handle, GameData* manufacturerData, GameData* materialData);// protected RVA = 0x75E8E0
	virtual ~InventoryItemBase();// protected RVA = 0x75C890 vtable offset = 0x0
	void _DESTRUCTOR();// protected RVA = 0x75C890 vtable offset = 0x0
	void getTooltipTradeValue(Ogre::vector<StringPair>::type& lines);// protected RVA = 0x79D540
	float merchantPriceMod() const;// protected RVA = 0x79D470
	itemType objectType; // 0x13C Member
	hand properOwner; // 0x140 Member
	hand _whosInventoryWeAreIn; // 0x160 Member
	bool _isResearchArtifact; // 0x180 Member
	BuildingItemGroup* itemGroup; // 0x188 Member
	// no_addr class InventoryItemBase & operator=(const class InventoryItemBase & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class Gear;
class Crossbow;
class Armour;
class Weapon;
class LockedArmour;
class SimplePhysXEntity;
class Item : public InventoryItemBase
{
public:
	// InventoryItemBase offset = 0x0, length = 0x190
	static bool isFood(GameData* f);// public RVA = 0x3551F0
	virtual Gear* isGear();// public RVA = 0xD2160 vtable offset = 0x2C0
	Gear* _NV_isGear();// public RVA = 0xD2160 vtable offset = 0x2C0
	virtual itemType getClassType() const;// public RVA = 0xD2170 vtable offset = 0x2C8
	itemType _NV_getClassType() const;// public RVA = 0xD2170 vtable offset = 0x2C8
	virtual void resetAfterCopy() override;// public RVA = 0x75C4A0 vtable offset = 0x0
	void _NV_resetAfterCopy();// public RVA = 0x75C4A0 vtable offset = 0x0
	virtual void activate(bool createPhysical, YesNoMaybe bareWeapon) override;// public RVA = 0x75C910 vtable offset = 0x0
	void _NV_activate(bool createPhysical, YesNoMaybe bareWeapon);// public RVA = 0x75C910 vtable offset = 0x0
	virtual void activate(bool createPhysical, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, bool fixedPosition, YesNoMaybe bareWeapon, bool dynamicPhysics) override;// public RVA = 0x75C7A0 vtable offset = 0x0
	void _NV_activate(bool createPhysical, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, bool fixedPosition, YesNoMaybe bareWeapon, bool dynamicPhysics);// public RVA = 0x75C7A0 vtable offset = 0x0
	virtual void deactivate() override;// public RVA = 0x75C410 vtable offset = 0x0
	void _NV_deactivate();// public RVA = 0x75C410 vtable offset = 0x0
	virtual void setPositionRotation(const Ogre::Vector3& position, const Ogre::Quaternion& rotation, bool fixedPosition);// public RVA = 0x75C450 vtable offset = 0x2D0
	void _NV_setPositionRotation(const Ogre::Vector3& position, const Ogre::Quaternion& rotation, bool fixedPosition);// public RVA = 0x75C450 vtable offset = 0x2D0
	virtual Crossbow* isCrossbow();// public RVA = 0xD2180 vtable offset = 0x2D8
	Crossbow* _NV_isCrossbow();// public RVA = 0xD2180 vtable offset = 0x2D8
	virtual Armour* isArmour();// public RVA = 0xD2190 vtable offset = 0x2E0
	Armour* _NV_isArmour();// public RVA = 0xD2190 vtable offset = 0x2E0
	virtual Weapon* isWeapon();// public RVA = 0xD21A0 vtable offset = 0x2E8
	Weapon* _NV_isWeapon();// public RVA = 0xD21A0 vtable offset = 0x2E8
	virtual LockedArmour* isLockedArmour();// public RVA = 0xD21B0 vtable offset = 0x2F0
	LockedArmour* _NV_isLockedArmour();// public RVA = 0xD21B0 vtable offset = 0x2F0
	virtual Faction* isAFactionUniform();// public RVA = 0xD21C0 vtable offset = 0x2F8
	Faction* _NV_isAFactionUniform();// public RVA = 0xD21C0 vtable offset = 0x2F8
	virtual bool isPhysical() const override;// public RVA = 0xD21D0 vtable offset = 0x0
	bool _NV_isPhysical() const;// public RVA = 0xD21D0 vtable offset = 0x0
	virtual void setVisible(bool on) override;// public RVA = 0xD21F0 vtable offset = 0x0
	void _NV_setVisible(bool on);// public RVA = 0xD21F0 vtable offset = 0x0
	virtual bool getVisible() const override;// public RVA = 0xD2230 vtable offset = 0x0
	bool _NV_getVisible() const;// public RVA = 0xD2230 vtable offset = 0x0
	virtual std::string getModelName();// public RVA = 0x75F0F0 vtable offset = 0x300
	std::string _NV_getModelName();// public RVA = 0x75F0F0 vtable offset = 0x300
	virtual Inventory* getInventory() const override;// public RVA = 0xD2240 vtable offset = 0x0
	Inventory* _NV_getInventory() const;// public RVA = 0xD2240 vtable offset = 0x0
	virtual bool hasIngredients();// public RVA = 0xD4820 vtable offset = 0x308
	bool _NV_hasIngredients();// public RVA = 0xD4820 vtable offset = 0x308
	virtual bool isGoodFood();// public RVA = 0xD2250 vtable offset = 0x310
	bool _NV_isGoodFood();// public RVA = 0xD2250 vtable offset = 0x310
	virtual Ogre::Entity* getEntity() const;// public RVA = 0xD2290 vtable offset = 0x318
	Ogre::Entity* _NV_getEntity() const;// public RVA = 0xD2290 vtable offset = 0x318
	virtual TimeOfDay getTimeout() const;// public RVA = 0xD3140 vtable offset = 0x320
	TimeOfDay _NV_getTimeout() const;// public RVA = 0xD3140 vtable offset = 0x320
	virtual GameData* _serialise(GameDataContainer* container, itemType type) override;// public RVA = 0x75F7D0 vtable offset = 0x0
	GameData* _NV__serialise(GameDataContainer* container, itemType type);// public RVA = 0x75F7D0 vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer* container, GameData* state) override;// public RVA = 0x760340 vtable offset = 0x0
	void _NV__loadFromSerialise(GameDataContainer* container, GameData* state);// public RVA = 0x760340 vtable offset = 0x0
	virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract) override;// public RVA = 0x75CD20 vtable offset = 0x0
	GameSaveState _NV_serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x75CD20 vtable offset = 0x0
	virtual void loadFromSerialise(GameSaveState* saveState) override;// public RVA = 0x75CBA0 vtable offset = 0x0
	void _NV_loadFromSerialise(GameSaveState* saveState);// public RVA = 0x75CBA0 vtable offset = 0x0
	virtual GameData* serialiseInInventory(GameDataContainer* container, GameData* refList) override;// public RVA = 0x75C4D0 vtable offset = 0x0
	GameData* _NV_serialiseInInventory(GameDataContainer* container, GameData* refList);// public RVA = 0x75C4D0 vtable offset = 0x0
	virtual void loadFromSerialiseInInventory(GameDataContainer* container, GameData* state) override;// public RVA = 0x75C4F0 vtable offset = 0x0
	void _NV_loadFromSerialiseInInventory(GameDataContainer* container, GameData* state);// public RVA = 0x75C4F0 vtable offset = 0x0
	// no_addr class Ogre::Entity * createPhysicalForInventoryIconPicture();// public
	virtual float getCraftTime();// public RVA = 0xD4BD0 vtable offset = 0x328
	float _NV_getCraftTime();// public RVA = 0xD4BD0 vtable offset = 0x328
	virtual float getCraftMaterialMult();// public RVA = 0xD22B0 vtable offset = 0x330
	float _NV_getCraftMaterialMult();// public RVA = 0xD22B0 vtable offset = 0x330
	virtual int getLevel() const override;// public RVA = 0xD22C0 vtable offset = 0x0
	int _NV_getLevel() const;// public RVA = 0xD22C0 vtable offset = 0x0
	virtual void createItemEntityCallback_Equipping(Ogre::Entity* ent, Ogre::SceneNode* node);// public RVA = 0xD22D0 vtable offset = 0x338
	void _NV_createItemEntityCallback_Equipping(Ogre::Entity* ent, Ogre::SceneNode* node);// public RVA = 0xD22D0 vtable offset = 0x338
	virtual void destroyItemEntityCallback_Equipping();// public RVA = 0xD22E0 vtable offset = 0x340
	void _NV_destroyItemEntityCallback_Equipping();// public RVA = 0xD22E0 vtable offset = 0x340
	virtual void notifyTheftFrom(const hand& owner);// public RVA = 0x7915A0 vtable offset = 0x350
	void _NV_notifyTheftFrom(const hand& owner);// public RVA = 0x7915A0 vtable offset = 0x350
	virtual void notifyTheftFrom(RootObject* obj);// public RVA = 0x791520 vtable offset = 0x348
	void _NV_notifyTheftFrom(RootObject* obj);// public RVA = 0x791520 vtable offset = 0x348
	static const hand& findProperOwner(RootObject* obj);// public RVA = 0x7914B0
	static const hand& findProperOwner(const hand& handle);// public RVA = 0x791420
	virtual void setInventoryWeAreIn(const hand& h);// public RVA = 0xD22F0 vtable offset = 0x358
	void _NV_setInventoryWeAreIn(const hand& h);// public RVA = 0xD22F0 vtable offset = 0x358
	const hand& getInventoryWeAreIn() const;// public RVA = 0x595DC0
	bool isPersistant() const;// public RVA = 0x37D7B0
	void setPersistant(const hand& anchor);// public RVA = 0x925520
	void setPersistant(bool p);// public RVA = 0x336860
	bool persistantOwnerExists() const;// public RVA = 0x386F90
	// no_addr void Item(const class Item & _a1);// public missing arg names
	Item(GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle);// protected RVA = 0x75EE40
	Item* _CONSTRUCTOR(GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle);// protected RVA = 0x75EE40
	virtual ~Item();// protected RVA = 0x75CB00 vtable offset = 0x0
	void _DESTRUCTOR();// protected RVA = 0x75CB00 vtable offset = 0x0
	virtual bool createPhysical() override;// protected RVA = 0x762D90 vtable offset = 0x0
	bool _NV_createPhysical();// protected RVA = 0x762D90 vtable offset = 0x0
	virtual void destroyPhysical() override;// protected RVA = 0x75C9E0 vtable offset = 0x0
	void _NV_destroyPhysical();// protected RVA = 0x75C9E0 vtable offset = 0x0
	virtual void loadUnloadCheck() override;// protected RVA = 0x75D3C0 vtable offset = 0x0
	void _NV_loadUnloadCheck();// protected RVA = 0x75D3C0 vtable offset = 0x0
	void createItemEntityCallback(Ogre::SharedPtr<Ogre::Resource> _a1, void* entityData);// protected RVA = 0x7614D0
	virtual void itemEntityCreated(Ogre::Entity* _a1);// protected RVA = 0xD3150 vtable offset = 0x360 missing arg names
	void _NV_itemEntityCreated(Ogre::Entity* _a1);// protected RVA = 0xD3150 vtable offset = 0x360 missing arg names
	bool physicalShouldExist; // 0x190 Member
	bool existAsBareWeapon; // 0x191 Member
	hand persistant; // 0x198 Member
	bool visible; // 0x1B8 Member
	SimplePhysXEntity* physical; // 0x1C0 Member
	bool _isPhysical; // 0x1C8 Member
	Ogre::Entity* physicalEntity; // 0x1D0 Member
	bool creatingPhysical; // 0x1D8 Member
	bool fixedPhysicalPosition; // 0x1D9 Member
	bool useDynamicPhysics; // 0x1DA Member
	Ogre::Entity* loadingEntity; // 0x1E0 Member
	// no_addr class Item & operator=(const class Item & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

// TODO move?
class RaceLimiter
{
public:
	// VTable         : (none)
	class Limiter
	{
	public:
		// VTable         : (none)
		std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > > racesExclude; // 0x8 Member
		std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > > racesInclude; // 0x30 Member
		virtual bool canEquip(RaceData* race, bool isAnimal);// public RVA = 0x592F30 vtable offset = 0x0
		bool _NV_canEquip(RaceData* race, bool isAnimal);// public RVA = 0x592F30 vtable offset = 0x0
		// no_addr void Limiter(const class RaceLimiter::Limiter & _a1);// public missing arg names
		Limiter();// public RVA = 0x592D90
		Limiter* _CONSTRUCTOR();// public RVA = 0x592D90
		~Limiter();// public RVA = 0x591D00
		void _DESTRUCTOR();// public RVA = 0x591D00
		// no_addr class RaceLimiter::Limiter & operator=(const class RaceLimiter::Limiter & _a1);// public missing arg names
		// no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
	};
	ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type limits; // 0x8 Member
	static RaceLimiter* getSingleton();// public RVA = 0x5938D0
	void addLimit(GameData* dat);// public RVA = 0x761F40
	virtual bool canEquip(GameData* item, RaceData* race, bool isAnimal);// public RVA = 0x593780 vtable offset = 0x8
	bool _NV_canEquip(GameData* item, RaceData* race, bool isAnimal);// public RVA = 0x593780 vtable offset = 0x8
	virtual bool canEquip(GameData* item, RootObject* who);// public RVA = 0x75C510 vtable offset = 0x0
	bool _NV_canEquip(GameData* item, RootObject* who);// public RVA = 0x75C510 vtable offset = 0x0
	// no_addr void RaceLimiter(const class RaceLimiter & _a1);// public missing arg names
	RaceLimiter();// public RVA = 0x592420
	RaceLimiter* _CONSTRUCTOR();// public RVA = 0x592420
	~RaceLimiter();// public RVA = 0x76AC30
	void _DESTRUCTOR();// public RVA = 0x76AC30
	// no_addr class RaceLimiter & operator=(const class RaceLimiter & _a1);// public missing arg names
	// no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class GameData;

class ContainerItem : public Item, public RaceLimiter
{
public:
	// Item offset = 0x0, length = 0x1E8
	// RaceLimiter offset = 0x1E8, length = 0x48
	virtual ~ContainerItem();// public RVA = 0x761EA0 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0x761EA0 vtable offset = 0x0
	virtual itemType getClassType() const override;// public RVA = 0x76AC40 vtable offset = 0x0
	itemType _NV_getClassType() const;// public RVA = 0x76AC40 vtable offset = 0x0
	virtual bool canEquip(GameData* race);// public RVA = 0x76AE00 vtable offset = 0x368
	bool _NV_canEquip(GameData* race);// public RVA = 0x76AE00 vtable offset = 0x368
	virtual void equipItem(const std::string& what, Item* who) override;// public RVA = 0x75C5A0 vtable offset = 0x0
	void _NV_equipItem(const std::string& what, Item* who);// public RVA = 0x75C5A0 vtable offset = 0x0
	virtual void unequipItem(const std::string& what, Item* item) override;// public RVA = 0x75C5D0 vtable offset = 0x0
	void _NV_unequipItem(const std::string& what, Item* item);// public RVA = 0x75C5D0 vtable offset = 0x0
	virtual void dropItem(RootObject* what) override;// public RVA = 0x75C600 vtable offset = 0x0
	void _NV_dropItem(RootObject* what);// public RVA = 0x75C600 vtable offset = 0x0
	virtual bool takeMoney(int n) override;// public RVA = 0x75C630 vtable offset = 0x0
	bool _NV_takeMoney(int n);// public RVA = 0x75C630 vtable offset = 0x0
	virtual int getMoney() const override;// public RVA = 0x75C660 vtable offset = 0x0
	int _NV_getMoney() const;// public RVA = 0x75C660 vtable offset = 0x0
	void doubleCheckHandle();// public RVA = 0x75CC80
	virtual Ogre::Vector3 getPosition() override;// public RVA = 0x75C690 vtable offset = 0x0
	Ogre::Vector3 _NV_getPosition();// public RVA = 0x75C690 vtable offset = 0x0
	virtual Inventory* getInventory() const override;// public RVA = 0x76AC50 vtable offset = 0x0
	Inventory* _NV_getInventory() const;// public RVA = 0x76AC50 vtable offset = 0x0
	virtual InventoryLayout* createInventoryLayout() override;// public RVA = 0x75C6E0 vtable offset = 0x0
	InventoryLayout* _NV_createInventoryLayout();// public RVA = 0x75C6E0 vtable offset = 0x0
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7A8E30 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7A8E30 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x79F970 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x79F970 vtable offset = 0x0
	virtual GameData* _serialise(GameDataContainer* container, itemType type) override;// public RVA = 0x7611B0 vtable offset = 0x0
	GameData* _NV__serialise(GameDataContainer* container, itemType type);// public RVA = 0x7611B0 vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer* container, GameData* state) override;// public RVA = 0x761210 vtable offset = 0x0
	void _NV__loadFromSerialise(GameDataContainer* container, GameData* state);// public RVA = 0x761210 vtable offset = 0x0
	virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract) override;// public RVA = 0x75CE00 vtable offset = 0x0
	GameSaveState _NV_serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x75CE00 vtable offset = 0x0
	virtual void loadFromSerialise(GameSaveState* state) override;// public RVA = 0x75CC40 vtable offset = 0x0
	void _NV_loadFromSerialise(GameSaveState* state);// public RVA = 0x75CC40 vtable offset = 0x0
	virtual void setProperOwner(const hand& h) override;// public RVA = 0x76AC70 vtable offset = 0x0
	void _NV_setProperOwner(const hand& h);// public RVA = 0x76AC70 vtable offset = 0x0
	RootObject* callbackOwner; // 0x230 Member
	float athleticsMult; // 0x238 Member
	float weightMult; // 0x23C Member
	float combatSpeedMult; // 0x240 Member
	int combatSkillBonus; // 0x244 Member
	float stealthMult; // 0x248 Member
	ogre_unordered_set<GameData*>::type racesExclude; // 0x250 Member
	// no_addr void ContainerItem(const class ContainerItem & _a1);// public missing arg names
	ContainerItem(GameData* dat, GameData* mat, hand _handle);// protected RVA = 0x762600
	ContainerItem* _CONSTRUCTOR(GameData* dat, GameData* mat, hand _handle);// protected RVA = 0x762600
	Inventory* inventory; // 0x290 Member
	// no_addr class ContainerItem & operator=(const class ContainerItem & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class SeveredLimbItem : public Item
{
public:
	// Item offset = 0x0, length = 0x1E8
	// no_addr void SeveredLimbItem(const class SeveredLimbItem & _a1);// public missing arg names
	SeveredLimbItem(GameData* baseData, const hand& handle);// public RVA = 0xCD630
	SeveredLimbItem* _CONSTRUCTOR(GameData* baseData, const hand& handle);// public RVA = 0xCD630
	void setupFromCharacter(Character* c, int limb, const Ogre::Vector3& force);// public RVA = 0xCECD0
	virtual GameData* _serialise(GameDataContainer* container, itemType type) override;// public RVA = 0xCEFA0 vtable offset = 0x0
	GameData* _NV__serialise(GameDataContainer* container, itemType type);// public RVA = 0xCEFA0 vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer* container, GameData* state) override;// public RVA = 0xCF1F0 vtable offset = 0x0
	void _NV__loadFromSerialise(GameDataContainer* container, GameData* state);// public RVA = 0xCF1F0 vtable offset = 0x0
	virtual TimeOfDay getTimeout() const override;// public RVA = 0xD2330 vtable offset = 0x0
	TimeOfDay _NV_getTimeout() const;// public RVA = 0xD2330 vtable offset = 0x0
	virtual void destroyPhysical() override;// public RVA = 0xCD830 vtable offset = 0x0
	void _NV_destroyPhysical();// public RVA = 0xCD830 vtable offset = 0x0
	virtual void itemEntityCreated(Ogre::Entity* e) override;// protected RVA = 0xCF450 vtable offset = 0x0
	void _NV_itemEntityCreated(Ogre::Entity* e);// protected RVA = 0xCF450 vtable offset = 0x0
	Ogre::Vector3 limbScale; // 0x1E8 Member
	Ogre::Vector4 skinTone; // 0x1F4 Member
	Ogre::ColourValue blood; // 0x204 Member
	Ogre::Vector3 impulse; // 0x214 Member
	TimeOfDay timeout; // 0x220 Member
	virtual ~SeveredLimbItem();// public RVA = 0xD2350 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0xD2350 vtable offset = 0x0
	// no_addr class SeveredLimbItem & operator=(const class SeveredLimbItem & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class NestItem : public Item
{
public:
	// Item offset = 0x0, length = 0x1E8
	virtual itemType getClassType() const override;// public RVA = 0x76A8B0 vtable offset = 0x0
	itemType _NV_getClassType() const;// public RVA = 0x76A8B0 vtable offset = 0x0
	virtual std::string getModelName() override;// public RVA = 0x75F340 vtable offset = 0x0
	std::string _NV_getModelName();// public RVA = 0x75F340 vtable offset = 0x0
	// no_addr void NestItem(const class NestItem & _a1);// public missing arg names
	NestItem(GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle);// protected RVA = 0x75F2D0
	NestItem* _CONSTRUCTOR(GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle);// protected RVA = 0x75F2D0
	virtual ~NestItem();// public RVA = 0x76A8C0 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0x76A8C0 vtable offset = 0x0
	// no_addr class NestItem & operator=(const class NestItem & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class BlueprintItem : public Item
{
public:
	// Item offset = 0x0, length = 0x1E8
	virtual itemType getClassType() const override;// public RVA = 0x2D2C20 vtable offset = 0x0
	itemType _NV_getClassType() const;// public RVA = 0x2D2C20 vtable offset = 0x0
	virtual float getItemWeight() const override;// public RVA = 0x2D2C30 vtable offset = 0x0
	float _NV_getItemWeight() const;// public RVA = 0x2D2C30 vtable offset = 0x0
	virtual int getValueSingle(bool isPlayer) const override;// public RVA = 0x2D2C40 vtable offset = 0x0
	int _NV_getValueSingle(bool isPlayer) const;// public RVA = 0x2D2C40 vtable offset = 0x0
	GameData* getResearchData();// public RVA = 0x2B4A40
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7AA1D0 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7AA1D0 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x79FAF0 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x79FAF0 vtable offset = 0x0
	virtual void getGUIData(DatapanelGUI* datapanel, int category) override;// public RVA = 0x4971B0 vtable offset = 0x0
	void _NV_getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x4971B0 vtable offset = 0x0
	bool learnResearch();// public RVA = 0x2B6120
	int value; // 0x1E8 Member
	// no_addr void BlueprintItem(const class BlueprintItem & _a1);// public missing arg names
	BlueprintItem(GameData* _itemData, GameData* _techData, hand _handle);// protected RVA = 0x2B73F0
	BlueprintItem* _CONSTRUCTOR(GameData* _itemData, GameData* _techData, hand _handle);// protected RVA = 0x2B73F0
	virtual ~BlueprintItem();// protected RVA = 0x2D2CB0 vtable offset = 0x0
	void _DESTRUCTOR();// protected RVA = 0x2D2CB0 vtable offset = 0x0
	static void printResearch(Ogre::vector<StringPair>::type& lines, GameData* d, const std::string& listName, const std::string& displayName);// protected RVA = 0x799630
	// no_addr class BlueprintItem & operator=(const class BlueprintItem & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class MapItem : public Item
{
public:
	// Item offset = 0x0, length = 0x1E8
	virtual float getItemWeight() const override;// public RVA = 0x75C730 vtable offset = 0x0
	float _NV_getItemWeight() const;// public RVA = 0x75C730 vtable offset = 0x0
	virtual int getValueSingle(bool isPlayer) const override;// public RVA = 0x75C740 vtable offset = 0x0
	int _NV_getValueSingle(bool isPlayer) const;// public RVA = 0x75C740 vtable offset = 0x0
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7B3BF0 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7B3BF0 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7A4960 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7A4960 vtable offset = 0x0
	int selectTowns();// public RVA = 0x75D770
	bool consume();// public RVA = 0x75E340
	int getTownsDiscovered() const;// public RVA = 0x70B9E0
	virtual void _loadFromSerialise(GameDataContainer* container, GameData* state) override;// public RVA = 0x761440 vtable offset = 0x0
	void _NV__loadFromSerialise(GameDataContainer* container, GameData* state);// public RVA = 0x761440 vtable offset = 0x0
	virtual GameData* _serialise(GameDataContainer* container, itemType type) override;// public RVA = 0x761450 vtable offset = 0x0
	GameData* _NV__serialise(GameDataContainer* container, itemType type);// public RVA = 0x761450 vtable offset = 0x0
	// no_addr void MapItem(const class MapItem & _a1);// public missing arg names
	MapItem(GameData* itemData, hand _handle);// protected RVA = 0x761310
	MapItem* _CONSTRUCTOR(GameData* itemData, hand _handle);// protected RVA = 0x761310
	virtual ~MapItem();// protected RVA = 0x75CB40 vtable offset = 0x0
	void _DESTRUCTOR();// protected RVA = 0x75CB40 vtable offset = 0x0
	void copy(MapItem* map);// protected RVA = 0x75C810
	int value; // 0x1E8 Member
	unsigned short townsDiscoveredCount; // 0x1EC Member
	Ogre::FastArray<hand> townsHandles; // 0x1F0 Member
	// no_addr class MapItem & operator=(const class MapItem & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class MoneyItem : public Item
{
public:
	// Item offset = 0x0, length = 0x1E8
	virtual int getValueSingle(bool isPlayer) const override;// public RVA = 0x75E450 vtable offset = 0x0
	int _NV_getValueSingle(bool isPlayer) const;// public RVA = 0x75E450 vtable offset = 0x0
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7B4820 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7B4820 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7A4970 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7A4970 vtable offset = 0x0
	bool consume() const;// public RVA = 0x75E4F0
	// no_addr void MoneyItem(const class MoneyItem & _a1);// public missing arg names
	MoneyItem(GameData* itemData, GameData* materialData, const hand& _handle);// protected RVA = 0x761460
	MoneyItem* _CONSTRUCTOR(GameData* itemData, GameData* materialData, const hand& _handle);// protected RVA = 0x761460
	virtual ~MoneyItem();// public RVA = 0x76A970 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0x76A970 vtable offset = 0x0
	// no_addr class MoneyItem & operator=(const class MoneyItem & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};