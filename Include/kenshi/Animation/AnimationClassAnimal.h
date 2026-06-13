#pragma once

#include "AnimationClass.h"

class AnimationClassAnimal : public AnimationClass
{
public:
    // AnimationClass offset = 0x0, length = 0x300
    float maxTurnSpeed; // 0x300 Member
    bool _isTurningFar; // 0x304 Member
    Ogre::Quaternion lastRot; // 0x308 Member
    // no_addr void AnimationClassAnimal(class AnimationClassAnimal & _a1);// public missing arg names
    AnimationClassAnimal();// public RVA = 0x5E83B0
    AnimationClassAnimal* _CONSTRUCTOR();// public RVA = 0x5E83B0
    virtual ~AnimationClassAnimal();// public RVA = 0x5E8420 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x5E8420 vtable offset = 0x0
    virtual bool create(CharMovement* move, GameDataCopyStandalone* appearanceData, GameData* factionColorScheme, Character* m, GameData* race) override;// public RVA = 0x5BCC10 vtable offset = 0x0
    bool _NV_create(CharMovement* move, GameDataCopyStandalone* appearanceData, GameData* factionColorScheme, Character* m, GameData* race);// public RVA = 0x5BCC10 vtable offset = 0x0
    virtual AnimationData* getIdleAnimation() override;// public RVA = 0x51EBA0 vtable offset = 0x0
    AnimationData* _NV_getIdleAnimation();// public RVA = 0x51EBA0 vtable offset = 0x0
    virtual void rotationUpdate(float frameTime) override;// public RVA = 0x5B0BF0 vtable offset = 0x0
    void _NV_rotationUpdate(float frameTime);// public RVA = 0x5B0BF0 vtable offset = 0x0
    virtual bool isTurning() const override;// public RVA = 0x51CE50 vtable offset = 0x0
    bool _NV_isTurning() const;// public RVA = 0x51CE50 vtable offset = 0x0
    virtual bool isTurningFar() const override;// public RVA = 0x5E8440 vtable offset = 0x0
    bool _NV_isTurningFar() const;// public RVA = 0x5E8440 vtable offset = 0x0
    virtual AnimationClassHuman* isHuman() override;// public RVA = 0x5E8450 vtable offset = 0x0
    AnimationClassHuman* _NV_isHuman();// public RVA = 0x5E8450 vtable offset = 0x0
    virtual float calculatePositionWithWaterHeight() override;// public RVA = 0x5B5050 vtable offset = 0x0
    float _NV_calculatePositionWithWaterHeight();// public RVA = 0x5B5050 vtable offset = 0x0
    // no_addr class AnimationClassAnimal & operator=(const class AnimationClassAnimal & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};