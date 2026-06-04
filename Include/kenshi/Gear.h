#pragma once

#include "Item.h"

class Gear : public Item
{
public:
	// Item offset = 0x0, length = 0x1E8
	// no_addr void Gear(const class Gear & _a1);// public missing arg names
	Gear(GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Faction* uniform);// public RVA = 0xD3050
	Gear* _CONSTRUCTOR(GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Faction* uniform);// public RVA = 0xD3050
	virtual Gear* isGear() override;// public RVA = 0xD3160 vtable offset = 0x0
	Gear* _NV_isGear();// public RVA = 0xD3160 vtable offset = 0x0
	virtual float getLevel01() const;// public RVA = 0xD3170 vtable offset = 0x368
	float _NV_getLevel01() const;// public RVA = 0xD3170 vtable offset = 0x368
	virtual int getLevel() const override;// public RVA = 0xD3180 vtable offset = 0x0
	int _NV_getLevel() const;// public RVA = 0xD3180 vtable offset = 0x0
	virtual Faction* isAFactionUniform() override;// public RVA = 0xD3190 vtable offset = 0x0
	Faction* _NV_isAFactionUniform();// public RVA = 0xD3190 vtable offset = 0x0
	Faction* isUniform; // 0x1E8 Member
	int value; // 0x1F0 Member
	virtual GameData* _serialise(GameDataContainer* container, itemType type) override;// public RVA = 0x7609F0 vtable offset = 0x0
	GameData* _NV__serialise(GameDataContainer* container, itemType type);// public RVA = 0x7609F0 vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer* container, GameData* state) override;// public RVA = 0x760B70 vtable offset = 0x0
	void _NV__loadFromSerialise(GameDataContainer* container, GameData* state);// public RVA = 0x760B70 vtable offset = 0x0
	virtual void setInventoryWeAreIn(const hand& h) override;// public RVA = 0xD31A0 vtable offset = 0x0
	void _NV_setInventoryWeAreIn(const hand& h);// public RVA = 0xD31A0 vtable offset = 0x0
	bool isPlayerCrafted() const;// public RVA = 0x8A3B30
	std::string crafter; // 0x1F8 Member
	float level; // 0x220 Member
	int level_0_100; // 0x224 Member
	virtual ~Gear();// public RVA = 0xD31E0 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0xD31E0 vtable offset = 0x0
	// no_addr class Gear & operator=(const class Gear & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class Sword;
class Crossbow;

class Weapon : public Gear
{
public:
	// Gear offset = 0x0, length = 0x228
	virtual float getItemWeight() const override;// public RVA = 0x8A3AE0 vtable offset = 0x0
	float _NV_getItemWeight() const;// public RVA = 0x8A3AE0 vtable offset = 0x0
	virtual int getValueSingle(bool isPlayer) const override;// public RVA = 0x8A3B40 vtable offset = 0x0
	int _NV_getValueSingle(bool isPlayer) const;// public RVA = 0x8A3B40 vtable offset = 0x0
	WeaponCategory getCategory() const;// public RVA = 0x5C71D0
	WeaponCategory getCategory_animationOverride() const;// public RVA = 0x51C0E0
	bool is2HandedOnly() const;// public RVA = 0x595DD0
	float getCombatWeight() const;// public RVA = 0x881FB0
	virtual float getCraftTime() override;// public RVA = 0x2B7240 vtable offset = 0x0
	float _NV_getCraftTime();// public RVA = 0x2B7240 vtable offset = 0x0
	virtual float getCraftMaterialMult() override;// public RVA = 0x8A8740 vtable offset = 0x0
	float _NV_getCraftMaterialMult();// public RVA = 0x8A8740 vtable offset = 0x0
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& _a1) override = 0;// public vtable offset = 0x0 missing arg names
	virtual Weapon* isWeapon() override;// public RVA = 0x8A3AF0 vtable offset = 0x0
	Weapon* _NV_isWeapon();// public RVA = 0x8A3AF0 vtable offset = 0x0
	virtual Sword* isSword();// public RVA = 0x8A3B00 vtable offset = 0x370
	Sword* _NV_isSword();// public RVA = 0x8A3B00 vtable offset = 0x370
	virtual Crossbow* isCrossbow() override;// public RVA = 0x8A3B10 vtable offset = 0x0
	Crossbow* _NV_isCrossbow();// public RVA = 0x8A3B10 vtable offset = 0x0
	float bleedDamage; // 0x228 Member
	int modAttack; // 0x22C Member
	virtual int getSkillModIndoors() const;// public RVA = 0x8A3B20 vtable offset = 0x378
	int _NV_getSkillModIndoors() const;// public RVA = 0x8A3B20 vtable offset = 0x378
	// no_addr void Weapon(const class Weapon & _a1);// public missing arg names
	Weapon(GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level);// protected RVA = 0x897080
	Weapon* _CONSTRUCTOR(GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level);// protected RVA = 0x897080
	virtual ~Weapon();// protected RVA = 0x8A3A70 vtable offset = 0x0
	void _DESTRUCTOR();// protected RVA = 0x8A3A70 vtable offset = 0x0
	float combatWeight; // 0x230 Member
	WeaponCategory category; // 0x234 Member
	WeaponCategory category_animationOverride; // 0x238 Member
	// no_addr class Weapon & operator=(const class Weapon & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class Sword : public Weapon
{
public:
	// Weapon offset = 0x0, length = 0x240
	// no_addr void Sword(const class Sword & _a1);// public missing arg names
	Sword(GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level);// public RVA = 0x897330
	Sword* _CONSTRUCTOR(GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level);// public RVA = 0x897330
	virtual itemType getClassType() const override;// public RVA = 0x8A88A0 vtable offset = 0x0
	itemType _NV_getClassType() const;// public RVA = 0x8A88A0 vtable offset = 0x0
	virtual Sword* isSword() override;// public RVA = 0x8A88B0 vtable offset = 0x0
	Sword* _NV_isSword();// public RVA = 0x8A88B0 vtable offset = 0x0
	void setupStats(int _level, GameData* baseData, GameData* companyData, GameData* materialData);// public RVA = 0x888520
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7B17C0 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7B17C0 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x79EC20 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x79EC20 vtable offset = 0x0
	float cutDamage; // 0x240 Member
	float bluntDamage; // 0x244 Member
	float minCutDamage; // 0x248 Member
	int modDefence; // 0x24C Member
	int modIndoors; // 0x250 Member
	virtual int getSkillModIndoors() const override;// public RVA = 0x8A88C0 vtable offset = 0x0
	int _NV_getSkillModIndoors() const;// public RVA = 0x8A88C0 vtable offset = 0x0
	virtual ~Sword();// public RVA = 0x8A88D0 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0x8A88D0 vtable offset = 0x0
	// no_addr class Sword & operator=(const class Sword & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class GunClass;

class Crossbow : public Weapon
{
public:
	// Weapon offset = 0x0, length = 0x240
	// no_addr void Crossbow(const class Crossbow & _a1);// public missing arg names
	Crossbow(GameData* baseData, hand _handle, int _overalllevel);// private RVA = 0x8974E0
	Crossbow* _CONSTRUCTOR(GameData* baseData, hand _handle, int _overalllevel);// private RVA = 0x8974E0
	virtual Crossbow* isCrossbow() override;// public RVA = 0x8A89D0 vtable offset = 0x0
	Crossbow* _NV_isCrossbow();// public RVA = 0x8A89D0 vtable offset = 0x0
	virtual itemType getClassType() const override;// public RVA = 0x8A89E0 vtable offset = 0x0
	itemType _NV_getClassType() const;// public RVA = 0x8A89E0 vtable offset = 0x0
	// no_addr enum WeaponCategory getCategory();// public
	// no_addr bool is2HandedOnly();// public
	virtual float getCraftMaterialMult() override;// public RVA = 0x8A89F0 vtable offset = 0x0
	float _NV_getCraftMaterialMult();// public RVA = 0x8A89F0 vtable offset = 0x0
	virtual float getCraftTime() override;// public RVA = 0x2B8C70 vtable offset = 0x0
	float _NV_getCraftTime();// public RVA = 0x2B8C70 vtable offset = 0x0
	float getRangeInUnits() const;// public RVA = 0x434700
	float getEquipPositionOffset();// public RVA = 0x544420
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7AF4F0 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7AF4F0 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x79E920 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x79E920 vtable offset = 0x0
	virtual void createItemEntityCallback_Equipping(Ogre::Entity* ent, Ogre::SceneNode* node) override;// public RVA = 0x43C090 vtable offset = 0x0
	void _NV_createItemEntityCallback_Equipping(Ogre::Entity* ent, Ogre::SceneNode* node);// public RVA = 0x43C090 vtable offset = 0x0
	virtual void destroyItemEntityCallback_Equipping() override;// public RVA = 0x434B70 vtable offset = 0x0
	void _NV_destroyItemEntityCallback_Equipping();// public RVA = 0x434B70 vtable offset = 0x0
	GunClass* gunClass; // 0x240 Member
	virtual void setVisible(bool on) override;// public RVA = 0x4346B0 vtable offset = 0x0
	void _NV_setVisible(bool on);// public RVA = 0x4346B0 vtable offset = 0x0
	virtual ~Crossbow();// public RVA = 0x8A8A00 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0x8A8A00 vtable offset = 0x0
	// no_addr class Crossbow & operator=(const class Crossbow & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

enum ArmourClass
{
	GEAR_CLOTH,
	GEAR_LIGHT,
	GEAR_MEDIUM,
	GEAR_HEAVY,
	GEAR_MAX
};

class Armour : public Gear
{
public:
	// Gear offset = 0x0, length = 0x228
	virtual itemType getClassType() const override;// public RVA = 0x8A8430 vtable offset = 0x0
	itemType _NV_getClassType() const;// public RVA = 0x8A8430 vtable offset = 0x0
	virtual Armour* isArmour() override;// public RVA = 0x8A8440 vtable offset = 0x0
	Armour* _NV_isArmour();// public RVA = 0x8A8440 vtable offset = 0x0
	virtual float getItemWeight() const override;// public RVA = 0x8A8450 vtable offset = 0x0
	float _NV_getItemWeight() const;// public RVA = 0x8A8450 vtable offset = 0x0
	virtual int getValueSingle(bool isPlayer) const override;// public RVA = 0x8A8470 vtable offset = 0x0
	int _NV_getValueSingle(bool isPlayer) const;// public RVA = 0x8A8470 vtable offset = 0x0
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7A03F0 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7A03F0 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7A2140 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7A2140 vtable offset = 0x0
	bool didIHitFlesh(GameData* bodypart);// public RVA = 0x65CEA0
	bool hasArmourCoverage() const;// public RVA = 0x339E80
	virtual float getCraftTime() override;// public RVA = 0x8A8460 vtable offset = 0x0
	float _NV_getCraftTime();// public RVA = 0x8A8460 vtable offset = 0x0
	static float getArmourCraftingMaterialConsumptionRate(GameData* armour);// public RVA = 0x2B7350
	float cutResistance; // 0x228 Member
	float bluntResistance; // 0x22C Member
	float pierceResistance; // 0x230 Member
	float minCutResistance; // 0x234 Member
	float cutToStun; // 0x238 Member
	ArmourType materialType; // 0x23C Member
	ArmourClass armourClassEnum; // 0x240 Member
	CharacterTypeEnum stigma; // 0x244 Member
	float athleticsMult; // 0x248 Member
	int combatSkillBonusAttk; // 0x24C Member
	int combatSkillBonusDef; // 0x250 Member
	int perceptionBonus; // 0x254 Member
	float combatSpeedMult; // 0x258 Member
	float stealthMult; // 0x25C Member
	float assassinMult; // 0x260 Member
	float dexterityMult; // 0x264 Member
	float damageMult; // 0x268 Member
	float dodgeMult; // 0x26C Member
	int unarmedBonus; // 0x270 Member
	float fistInjuryMult; // 0x274 Member
	float weatherProtectionAmount; // 0x278 Member
	float rangedSkillMult; // 0x27C Member
	std::set<WeatherAffecting, std::less<WeatherAffecting>, Ogre::STLAllocator<WeatherAffecting, Ogre::GeneralAllocPolicy > > weatherProtections; // 0x280 Member
	// no_addr float getWeatherProtection(enum WeatherAffecting _a1, class GameData * _a2);// public missing arg names
	float getWeatherProtection_simple(WeatherAffecting weather);// public RVA = 0x65B240
	// no_addr void Armour(const class Armour & _a1);// public missing arg names
	Armour(GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level);// protected RVA = 0x8976E0
	Armour* _CONSTRUCTOR(GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level);// protected RVA = 0x8976E0
	virtual ~Armour();// protected RVA = 0x8A8340 vtable offset = 0x0
	void _DESTRUCTOR();// protected RVA = 0x8A8340 vtable offset = 0x0
	ogre_unordered_map<GameData*, float>::type bodypartCoverage; // 0x2A8 Member
	float craftTime; // 0x2E8 Member
	// no_addr class Armour & operator=(const class Armour & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class DoorLock;

class LockedArmour : public Armour
{
public:
	// Armour offset = 0x0, length = 0x2F0
	// no_addr void LockedArmour(const class LockedArmour & _a1);// public missing arg names
	LockedArmour(GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level);// public RVA = 0x898C90
	LockedArmour* _CONSTRUCTOR(GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level);// public RVA = 0x898C90
	virtual ~LockedArmour();// public RVA = 0x885C30 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0x885C30 vtable offset = 0x0
	virtual Armour* isArmour() override;// public RVA = 0x8A8590 vtable offset = 0x0
	Armour* _NV_isArmour();// public RVA = 0x8A8590 vtable offset = 0x0
	virtual LockedArmour* isLockedArmour() override;// public RVA = 0x8A85A0 vtable offset = 0x0
	LockedArmour* _NV_isLockedArmour();// public RVA = 0x8A85A0 vtable offset = 0x0
	DoorLock* lock; // 0x2F0 Member
	virtual GameData* _serialise(GameDataContainer* container, itemType type) override;// public RVA = 0x760C90 vtable offset = 0x0
	GameData* _NV__serialise(GameDataContainer* container, itemType type);// public RVA = 0x760C90 vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer* container, GameData* state) override;// public RVA = 0x760D40 vtable offset = 0x0
	void _NV__loadFromSerialise(GameDataContainer* container, GameData* state);// public RVA = 0x760D40 vtable offset = 0x0
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7A3C60 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7A3C60 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x8A85B0 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x8A85B0 vtable offset = 0x0
	// no_addr class LockedArmour & operator=(const class LockedArmour & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class RobotLimbItem : public Gear
{
public:
	// Gear offset = 0x0, length = 0x228
	ogre_unordered_map<StatsEnumerated, float>::type statMults; // 0x228 Member
	// no_addr void RobotLimbItem(const class RobotLimbItem & _a1);// public missing arg names
	RobotLimbItem(GameData* baseData, GameData* materialData, hand _handle, int _level);// public RVA = 0xCE290
	RobotLimbItem* _CONSTRUCTOR(GameData* baseData, GameData* materialData, hand _handle, int _level);// public RVA = 0xCE290
	float getStatMult(StatsEnumerated stat);// public RVA = 0xCD740
	float maxHP; // 0x268 Member
	float currentDamage; // 0x26C Member
	float wearDamage; // 0x270 Member
	float stunDamage; // 0x274 Member
	int unarmedDamage; // 0x278 Member
	virtual GameData* _serialise(GameDataContainer* container, itemType type) override;// public RVA = 0x760DF0 vtable offset = 0x0
	GameData* _NV__serialise(GameDataContainer* container, itemType type);// public RVA = 0x760DF0 vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer* container, GameData* state) override;// public RVA = 0x760F50 vtable offset = 0x0
	void _NV__loadFromSerialise(GameDataContainer* container, GameData* state);// public RVA = 0x760F50 vtable offset = 0x0
	virtual float getCraftTime() override;// public RVA = 0x2B8D20 vtable offset = 0x0
	float _NV_getCraftTime();// public RVA = 0x2B8D20 vtable offset = 0x0
	virtual void getTooltipData1(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x7A7E20 vtable offset = 0x0
	void _NV_getTooltipData1(Ogre::vector<StringPair>::type& lines);// public RVA = 0x7A7E20 vtable offset = 0x0
	virtual void getTooltipData2(Ogre::vector<StringPair>::type& lines) override;// public RVA = 0x79EAA0 vtable offset = 0x0
	void _NV_getTooltipData2(Ogre::vector<StringPair>::type& lines);// public RVA = 0x79EAA0 vtable offset = 0x0
	virtual ~RobotLimbItem();// public RVA = 0xD4D30 vtable offset = 0x0
	void _DESTRUCTOR();// public RVA = 0xD4D30 vtable offset = 0x0
	// no_addr class RobotLimbItem & operator=(const class RobotLimbItem & _a1);// public missing arg names
	// virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};