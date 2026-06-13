#pragma once

#include "AnimationClass.h"

class Weapon;

class AnimationClassHuman : public AnimationClass
{
public:
    // AnimationClass offset = 0x0, length = 0x300
    // no_addr void AnimationClassHuman(class AnimationClassHuman & _a1);// public missing arg names
    AnimationClassHuman();// public RVA = 0x629000
    AnimationClassHuman* _CONSTRUCTOR();// public RVA = 0x629000
    virtual ~AnimationClassHuman();// public RVA = 0x5B91F0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x5B91F0 vtable offset = 0x0
    virtual AnimationClassHuman* isHuman() override;// public RVA = 0x5C4FC0 vtable offset = 0x0
    AnimationClassHuman* _NV_isHuman();// public RVA = 0x5C4FC0 vtable offset = 0x0
    virtual void ragdollModeUT(bool on, Ogre::Vector3 momentum, RagdollPart::Enum part, const std::string& physicsFile, Character* me) override;// public RVA = 0x5B98D0 vtable offset = 0x0
    void _NV_ragdollModeUT(bool on, Ogre::Vector3 momentum, RagdollPart::Enum part, const std::string& physicsFile, Character* me);// public RVA = 0x5B98D0 vtable offset = 0x0
    virtual float calculatePositionWithWaterHeight() override;// public RVA = 0x5B4E10 vtable offset = 0x0
    float _NV_calculatePositionWithWaterHeight();// public RVA = 0x5B4E10 vtable offset = 0x0
    virtual void update(float time) override;// public RVA = 0x5C4FD0 vtable offset = 0x0
    void _NV_update(float time);// public RVA = 0x5C4FD0 vtable offset = 0x0
    virtual bool create(CharMovement* move, GameDataCopyStandalone* appearanceData, GameData* factionColorScheme, Character* m, GameData* race) override;// public RVA = 0x5BCAC0 vtable offset = 0x0
    bool _NV_create(CharMovement* move, GameDataCopyStandalone* appearanceData, GameData* factionColorScheme, Character* m, GameData* race);// public RVA = 0x5BCAC0 vtable offset = 0x0
    virtual void setStance(bool crouch, bool prone) override;// public RVA = 0x51D620 vtable offset = 0x0
    void _NV_setStance(bool crouch, bool prone);// public RVA = 0x51D620 vtable offset = 0x0
    virtual void setStanceAnimation(StanceEnum stance) override;// public RVA = 0x51C220 vtable offset = 0x0
    void _NV_setStanceAnimation(StanceEnum stance);// public RVA = 0x51C220 vtable offset = 0x0
    void setEquipmentInHand(bool left, bool right, Weapon* what);// public RVA = 0x51C240
    virtual void setDesiredPainOverlayAnims(std::set<StringValuePair, std::less<StringValuePair>, Ogre::STLAllocator<StringValuePair, Ogre::GeneralAllocPolicy > > list) override;// public RVA = 0x51F270 vtable offset = 0x0
    void _NV_setDesiredPainOverlayAnims(std::set<StringValuePair, std::less<StringValuePair>, Ogre::STLAllocator<StringValuePair, Ogre::GeneralAllocPolicy > > list);// public RVA = 0x51F270 vtable offset = 0x0
    virtual void setDesiredPainOverlayAnimOverride(const std::string& anim) override;// public RVA = 0x51D6D0 vtable offset = 0x0
    void _NV_setDesiredPainOverlayAnimOverride(const std::string& anim);// public RVA = 0x51D6D0 vtable offset = 0x0
    virtual void animationSelectionCombatMode(float _TIME) override;// public RVA = 0x51F4E0 vtable offset = 0x0
    void _NV_animationSelectionCombatMode(float _TIME);// public RVA = 0x51F4E0 vtable offset = 0x0
    virtual void ragdollTheWeapons(const std::string& slotname, Item* item, bool attach) override;// public RVA = 0x5B1B40 vtable offset = 0x0
    void _NV_ragdollTheWeapons(const std::string& slotname, Item* item, bool attach);// public RVA = 0x5B1B40 vtable offset = 0x0
    virtual bool lookAt(const Ogre::Vector3& position) override;// public RVA = 0x5B7CB0 vtable offset = 0x0
    bool _NV_lookAt(const Ogre::Vector3& position);// public RVA = 0x5B7CB0 vtable offset = 0x0
    virtual Ogre::Vector3 getLookDirection() const override;// public RVA = 0x5B1B50 vtable offset = 0x0
    Ogre::Vector3 _NV_getLookDirection() const;// public RVA = 0x5B1B50 vtable offset = 0x0
    virtual AnimationData* getFloatingAnim() override;// public RVA = 0x51DBC0 vtable offset = 0x0
    AnimationData* _NV_getFloatingAnim();// public RVA = 0x51DBC0 vtable offset = 0x0
    virtual AnimationData* getStandingUpAnim() override;// public RVA = 0x51DC50 vtable offset = 0x0
    AnimationData* _NV_getStandingUpAnim();// public RVA = 0x51DC50 vtable offset = 0x0
    virtual void overlaidAnimationSelection() override;// private RVA = 0x51F880 vtable offset = 0x0
    void _NV_overlaidAnimationSelection();// private RVA = 0x51F880 vtable offset = 0x0
    bool usingRightArm; // 0x300 Member
    bool usingLeftArm; // 0x301 Member
    bool disabledRightArm; // 0x302 Member
    bool disabledLeftArm; // 0x303 Member
    AnimationData* canUseArmAnim(AnimationData* anim);// private RVA = 0x51F6E0
    std::string stanceAnimation; // 0x308 Member
    Ogre::Vector3 lookDirection; // 0x330 Member
    void calculatehipspos();// private RVA = 0x5B5D90
    Ogre::Vector3 hipspos; // 0x33C Member
    virtual void breathing(bool arms) override;// private RVA = 0x51D9D0 vtable offset = 0x0
    void _NV_breathing(bool arms);// private RVA = 0x51D9D0 vtable offset = 0x0
    float breatheTimer; // 0x348 Member
    lektor<float> breathePeaks; // 0x350 Member
    // no_addr class AnimationClassHuman & operator=(const class AnimationClassHuman & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};