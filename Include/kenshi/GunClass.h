#pragma once

#include <ogre/OgreVector3.h>
#include <ogre/OgreSharedPtr.h>
#include "Enums.h"
#include "util/hand.h"
#include "util/lektor.h"

class GameData;
class Character;
class RootObject;
class physHit;
class DatapanelGUI;
class SoundPool;
class ConstantTracerT;
class GunClassTurret;

class GunClass : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void GunClass(const class GunClass & _a1);// public missing arg names
    GunClass(GameData* gundat);// public RVA = 0x43B320
    GunClass* _CONSTRUCTOR(GameData* gundat);// public RVA = 0x43B320
    virtual ~GunClass();// public RVA = 0x43AAC0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x43AAC0 vtable offset = 0x0
    virtual void setVisible(bool value);// public RVA = 0x435900 vtable offset = 0x8
    void _NV_setVisible(bool value);// public RVA = 0x435900 vtable offset = 0x8
    virtual void update(const Ogre::Vector3& fallback);// public RVA = 0x434A70 vtable offset = 0x10
    void _NV_update(const Ogre::Vector3& fallback);// public RVA = 0x434A70 vtable offset = 0x10
    void reloadAmmo(float frameTime);// public RVA = 0x436830
    void shoot(Character* me, RootObject* target, StatsEnumerated stat, const Ogre::Vector3& aimpos);// public RVA = 0x439FB0
    virtual bool createPhysical(Ogre::SceneNode* parentNode, const std::string& material);// public RVA = 0x43C9A0 vtable offset = 0x18
    bool _NV_createPhysical(Ogre::SceneNode* parentNode, const std::string& material);// public RVA = 0x43C9A0 vtable offset = 0x18
    virtual void destroyPhysical();// public RVA = 0x435A70 vtable offset = 0x20
    void _NV_destroyPhysical();// public RVA = 0x435A70 vtable offset = 0x20
    virtual void aimAt(const Ogre::Vector3& who);// public RVA = 0x434970 vtable offset = 0x28
    void _NV_aimAt(const Ogre::Vector3& who);// public RVA = 0x434970 vtable offset = 0x28
    virtual float scoreTarget(Character* _a1, Character* _a2) = 0;// public vtable offset = 0x30 missing arg names
    virtual bool isAnimationReadyToShoot();// public RVA = 0x446740 vtable offset = 0x38
    bool _NV_isAnimationReadyToShoot();// public RVA = 0x446740 vtable offset = 0x38
    virtual void setAnimationReadyToShoot(bool on);// public RVA = 0x446750 vtable offset = 0x40
    void _NV_setAnimationReadyToShoot(bool on);// public RVA = 0x446750 vtable offset = 0x40
    virtual Ogre::Vector3 getBarrelPos();// public RVA = 0x434840 vtable offset = 0x48
    Ogre::Vector3 _NV_getBarrelPos();// public RVA = 0x434840 vtable offset = 0x48
    virtual Ogre::Vector3 getBarrelPosForTrace(float dist);// public RVA = 0x4348C0 vtable offset = 0x50
    Ogre::Vector3 _NV_getBarrelPosForTrace(float dist);// public RVA = 0x4348C0 vtable offset = 0x50
    virtual bool didThisTraceHitOurMountedBuilding(physHit& hit);// public RVA = 0x446760 vtable offset = 0x58
    bool _NV_didThisTraceHitOurMountedBuilding(physHit& hit);// public RVA = 0x446760 vtable offset = 0x58
    Ogre::Vector3 getRelativeBarrelPos() const;// public RVA = 0x43FD00
    virtual Ogre::Vector3 getAimDir(const Ogre::Vector3& _a1);// public RVA = 0x4347C0 vtable offset = 0x60 missing arg names
    Ogre::Vector3 _NV_getAimDir(const Ogre::Vector3& _a1);// public RVA = 0x4347C0 vtable offset = 0x60 missing arg names
    virtual float getAimCloseness() = 0;// public vtable offset = 0x68
    physHit& trace(const Ogre::Vector3& dir, bool includeCharacters);// public RVA = 0x4353C0
    physHit& trace2(const Ogre::Vector3& dir, bool includeCharacters);// public RVA = 0x433FD0
    virtual void getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x30C970 vtable offset = 0x70
    void _NV_getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x30C970 vtable offset = 0x70
    virtual void setStateForGUI(float reloadprogress01);// public RVA = 0x446810 vtable offset = 0x78
    void _NV_setStateForGUI(float reloadprogress01);// public RVA = 0x446810 vtable offset = 0x78
    virtual void setSkillForGUI(float skill01, const hand& who);// public RVA = 0x446770 vtable offset = 0x80
    void _NV_setSkillForGUI(float skill01, const hand& who);// public RVA = 0x446770 vtable offset = 0x80
    virtual unsigned __int64 getAudioObject() const = 0;// public vtable offset = 0x88
    float calculateHeightBonus(const Ogre::Vector3& barrelPos, const Ogre::Vector3& target) const;// public RVA = 0x4357E0
    virtual float calculateWallBonusMult();// public RVA = 0x4467B0 vtable offset = 0x90
    float _NV_calculateWallBonusMult();// public RVA = 0x4467B0 vtable offset = 0x90
    virtual float getPowerEfficiencyMult();// public RVA = 0x4467C0 vtable offset = 0x98
    float _NV_getPowerEfficiencyMult();// public RVA = 0x4467C0 vtable offset = 0x98
    bool isReloading() const;// public RVA = 0x2FD8A0
    bool isActive() const;// public RVA = 0x43FD30
    float calculateAccuracyDeviationAngle(float derivedAccuracyStat01);// public RVA = 0x434A30
    float calculateReloadTime(float stat01);// public RVA = 0x435890
    virtual void serialise(GameData* state);// public RVA = 0x438920 vtable offset = 0xA0
    void _NV_serialise(GameData* state);// public RVA = 0x438920 vtable offset = 0xA0
    virtual void loadFromSerialise(GameData* state);// public RVA = 0x4389C0 vtable offset = 0xA8
    void _NV_loadFromSerialise(GameData* state);// public RVA = 0x4389C0 vtable offset = 0xA8
    float maxRange; // 0x8 Member
    float accuracySkillRequired; // 0xC Member
    float accuracyDeviationBase; // 0x10 Member
    float aimSpeed; // 0x14 Member
    float shotSpeed; // 0x18 Member
    int numShotsMax; // 0x1C Member
    int numShotsCurrent; // 0x20 Member
    float reloadTimeMin; // 0x24 Member
    float reloadTimeMax; // 0x28 Member
    float userSkill01; // 0x2C Member
    hand user; // 0x30 Member
    virtual int getDamageMin() = 0;// public vtable offset = 0xB0
    virtual int getDamageMax() = 0;// public vtable offset = 0xB8
    float getARandomDamage();// public RVA = 0x43FD40
    GameData* reloadAnimation; // 0x50 Member
    GameData* ammoType; // 0x58 Member
    static SoundPool* soundPool; // RVA = 0x212C0F0 Static Member
    virtual GunClassPersonal* isPersonalCrossbow();// public RVA = 0x4467D0 vtable offset = 0xC0
    GunClassPersonal* _NV_isPersonalCrossbow();// public RVA = 0x4467D0 vtable offset = 0xC0
    virtual GunClassTurret* isTurret();// public RVA = 0x4467E0 vtable offset = 0xC8
    GunClassTurret* _NV_isTurret();// public RVA = 0x4467E0 vtable offset = 0xC8
    float getReloadStateForGUI(bool divide) const;// public RVA = 0x43FDA0
    virtual void setCharacter(const hand& h);// public RVA = 0x4467F0 vtable offset = 0xD0
    void _NV_setCharacter(const hand& h);// public RVA = 0x4467F0 vtable offset = 0xD0
    void reactivationCheck();// public RVA = 0x435350
    void loadEntityCallback(Ogre::SharedPtr<Ogre::Resource> _a1, void* entityData);// protected RVA = 0x43ABA0
    virtual void onEntitiesLoaded();// protected RVA = 0x446800 vtable offset = 0xD8
    void _NV_onEntitiesLoaded();// protected RVA = 0x446800 vtable offset = 0xD8
    void updatePartVisibilities();// protected RVA = 0x435CE0
    virtual Ogre::SceneNode* getParentNode() = 0;// protected vtable offset = 0xE0
    bool active; // 0x60 Member
    bool visible; // 0x61 Member
    GameData* gunData; // 0x68 Member
    Ogre::SharedPtr<Ogre::Material> harpoonMaterial; // 0x70 Member
    ConstantTracerT* tracer; // 0x80 Member
    ConstantTracerT* cheatingTracer; // 0x88 Member
    Ogre::Vector3 gunBarrelOffsetPos; // 0x90 Member
    lektor<Ogre::MovableObject*> ammoObjects; // 0xA0 Member
    std::string liveAmmoMesh; // 0xB8 Member
    float reloadState; // 0xE0 Member
    Ogre::Vector3 position; // 0xE4 Member
    Ogre::Quaternion orientation; // 0xF0 Member
    Ogre::MovableObject* drawnStringMesh; // 0x100 Member
    Ogre::MovableObject* slackStringMesh; // 0x108 Member
    char loadingEntitesLeft; // 0x110 Member
    // no_addr class GunClass & operator=(const class GunClass & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class GunClassPersonal : public GunClass
{
public:
    // GunClass offset = 0x0, length = 0x118
    int minDamage; // 0x118 Member
    int maxDamage; // 0x11C Member
    bool animReadyToShoot; // 0x120 Member
    // no_addr void GunClassPersonal(const class GunClassPersonal & _a1);// public missing arg names
    GunClassPersonal(GameData* gundat, float level01);// public RVA = 0x43BA00
    GunClassPersonal* _CONSTRUCTOR(GameData* gundat, float level01);// public RVA = 0x43BA00
    virtual float scoreTarget(Character* me, Character* who) override;// public RVA = 0x434280 vtable offset = 0x0
    float _NV_scoreTarget(Character* me, Character* who);// public RVA = 0x434280 vtable offset = 0x0
    virtual bool isAnimationReadyToShoot() override;// public RVA = 0x446A90 vtable offset = 0x0
    bool _NV_isAnimationReadyToShoot();// public RVA = 0x446A90 vtable offset = 0x0
    virtual void setAnimationReadyToShoot(bool on) override;// public RVA = 0x446AA0 vtable offset = 0x0
    void _NV_setAnimationReadyToShoot(bool on);// public RVA = 0x446AA0 vtable offset = 0x0
    virtual float getAimCloseness() override;// public RVA = 0x446AB0 vtable offset = 0x0
    float _NV_getAimCloseness();// public RVA = 0x446AB0 vtable offset = 0x0
    virtual float getPowerEfficiencyMult() override;// public RVA = 0x446AC0 vtable offset = 0x0
    float _NV_getPowerEfficiencyMult();// public RVA = 0x446AC0 vtable offset = 0x0
    virtual float calculateWallBonusMult() override;// public RVA = 0x446AD0 vtable offset = 0x0
    float _NV_calculateWallBonusMult();// public RVA = 0x446AD0 vtable offset = 0x0
    virtual bool didThisTraceHitOurMountedBuilding(physHit& hit) override;// public RVA = 0x446AE0 vtable offset = 0x0
    bool _NV_didThisTraceHitOurMountedBuilding(physHit& hit);// public RVA = 0x446AE0 vtable offset = 0x0
    virtual int getDamageMin() override;// public RVA = 0x446AF0 vtable offset = 0x0
    int _NV_getDamageMin();// public RVA = 0x446AF0 vtable offset = 0x0
    virtual int getDamageMax() override;// public RVA = 0x446B00 vtable offset = 0x0
    int _NV_getDamageMax();// public RVA = 0x446B00 vtable offset = 0x0
    virtual unsigned __int64 getAudioObject() const override;// public RVA = 0x434CD0 vtable offset = 0x0
    unsigned __int64 _NV_getAudioObject() const;// public RVA = 0x434CD0 vtable offset = 0x0
    virtual GunClassPersonal* isPersonalCrossbow() override;// public RVA = 0x446B10 vtable offset = 0x0
    GunClassPersonal* _NV_isPersonalCrossbow();// public RVA = 0x446B10 vtable offset = 0x0
    void clearEntitesPtr();// public RVA = 0x434D00
    virtual Ogre::Vector3 getAimDir(const Ogre::Vector3& targ) override;// public RVA = 0x4347F0 vtable offset = 0x0
    Ogre::Vector3 _NV_getAimDir(const Ogre::Vector3& targ);// public RVA = 0x4347F0 vtable offset = 0x0
    // no_addr void equip(class Character * _a1);// public missing arg names
    virtual void setCharacter(const hand& h) override;// public RVA = 0x446B20 vtable offset = 0x0
    void _NV_setCharacter(const hand& h);// public RVA = 0x446B20 vtable offset = 0x0
    virtual void onEntitiesLoaded() override;// protected RVA = 0x43C330 vtable offset = 0x0
    void _NV_onEntitiesLoaded();// protected RVA = 0x43C330 vtable offset = 0x0
    hand character; // 0x128 Member
    virtual Ogre::SceneNode* getParentNode() override;// protected RVA = 0x436940 vtable offset = 0x0
    Ogre::SceneNode* _NV_getParentNode();// protected RVA = 0x436940 vtable offset = 0x0
    virtual ~GunClassPersonal();// public RVA = 0x446B60 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x446B60 vtable offset = 0x0
    // no_addr class GunClassPersonal & operator=(const class GunClassPersonal & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class TurretBuilding;

class GunClassTurret : public GunClass
{
public:
    // GunClass offset = 0x0, length = 0x118
    // no_addr void GunClassTurret(const class GunClassTurret & _a1);// public missing arg names
    GunClassTurret(GameData* gundat, TurretBuilding* tt);// public RVA = 0x43C2D0
    GunClassTurret* _CONSTRUCTOR(GameData* gundat, TurretBuilding* tt);// public RVA = 0x43C2D0
    virtual void getGUIData(DatapanelGUI* datapanel, int category) override;// public RVA = 0x30D170 vtable offset = 0x0
    void _NV_getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x30D170 vtable offset = 0x0
    virtual void aimAt(const Ogre::Vector3& who) override;// public RVA = 0x434980 vtable offset = 0x0
    void _NV_aimAt(const Ogre::Vector3& who);// public RVA = 0x434980 vtable offset = 0x0
    virtual float scoreTarget(Character* me, Character* who) override;// public RVA = 0x434160 vtable offset = 0x0
    float _NV_scoreTarget(Character* me, Character* who);// public RVA = 0x434160 vtable offset = 0x0
    virtual float getAimCloseness() override;// public RVA = 0x4347A0 vtable offset = 0x0
    float _NV_getAimCloseness();// public RVA = 0x4347A0 vtable offset = 0x0
    virtual float getPowerEfficiencyMult() override;// public RVA = 0x434C00 vtable offset = 0x0
    float _NV_getPowerEfficiencyMult();// public RVA = 0x434C00 vtable offset = 0x0
    virtual float calculateWallBonusMult() override;// public RVA = 0x434C30 vtable offset = 0x0
    float _NV_calculateWallBonusMult();// public RVA = 0x434C30 vtable offset = 0x0
    virtual bool didThisTraceHitOurMountedBuilding(physHit& hit) override;// public RVA = 0x4378D0 vtable offset = 0x0
    bool _NV_didThisTraceHitOurMountedBuilding(physHit& hit);// public RVA = 0x4378D0 vtable offset = 0x0
    virtual bool isOutOfPower() const;// public RVA = 0x435310 vtable offset = 0xE8
    bool _NV_isOutOfPower() const;// public RVA = 0x435310 vtable offset = 0xE8
    virtual int getDamageMin() override;// public RVA = 0x434BA0 vtable offset = 0x0
    int _NV_getDamageMin();// public RVA = 0x434BA0 vtable offset = 0x0
    virtual int getDamageMax() override;// public RVA = 0x434BD0 vtable offset = 0x0
    int _NV_getDamageMax();// public RVA = 0x434BD0 vtable offset = 0x0
    virtual unsigned __int64 getAudioObject() const override;// public RVA = 0x434CB0 vtable offset = 0x0
    unsigned __int64 _NV_getAudioObject() const;// public RVA = 0x434CB0 vtable offset = 0x0
    virtual bool createPhysical(Ogre::SceneNode* parentNode, const std::string& materialName) override;// public RVA = 0x43D420 vtable offset = 0x0
    bool _NV_createPhysical(Ogre::SceneNode* parentNode, const std::string& materialName);// public RVA = 0x43D420 vtable offset = 0x0
    virtual void destroyPhysical() override;// public RVA = 0x435B60 vtable offset = 0x0
    void _NV_destroyPhysical();// public RVA = 0x435B60 vtable offset = 0x0
    void clearEntitesPtr();// public RVA = 0x435CC0
    virtual GunClassTurret* isTurret() override;// public RVA = 0x446BB0 vtable offset = 0x0
    GunClassTurret* _NV_isTurret();// public RVA = 0x446BB0 vtable offset = 0x0
    Ogre::Vector3 lastTarget; // 0x118 Member
    virtual void onEntitiesLoaded() override;// protected RVA = 0x43AC30 vtable offset = 0x0
    void _NV_onEntitiesLoaded();// protected RVA = 0x43AC30 vtable offset = 0x0
    virtual Ogre::SceneNode* getParentNode() override;// protected RVA = 0x434D10 vtable offset = 0x0
    Ogre::SceneNode* _NV_getParentNode();// protected RVA = 0x434D10 vtable offset = 0x0
    TurretBuilding* turretBuilding; // 0x128 Member
    virtual ~GunClassTurret();// public RVA = 0x446BC0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x446BC0 vtable offset = 0x0
    // no_addr class GunClassTurret & operator=(const class GunClassTurret & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};