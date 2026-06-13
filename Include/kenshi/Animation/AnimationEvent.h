#pragma once

#include <string>

class Character;

class AnimationEvent
{
public:
    // VTable         : (none)
    virtual ~AnimationEvent();// public RVA = 0x64550 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x64550 vtable offset = 0x0
    virtual void trigger(Character* _a1) const;// public RVA = 0x64560 vtable offset = 0x8 missing arg names
    void _NV_trigger(Character* _a1) const;// public RVA = 0x64560 vtable offset = 0x8 missing arg names
    virtual void finish(Character* _a1) const;// public RVA = 0x64570 vtable offset = 0x10 missing arg names
    void _NV_finish(Character* _a1) const;// public RVA = 0x64570 vtable offset = 0x10 missing arg names
    virtual std::string toString() const;// public RVA = 0x6A9B0 vtable offset = 0x18
    std::string _NV_toString() const;// public RVA = 0x6A9B0 vtable offset = 0x18
    // no_addr void AnimationEvent(const class AnimationEvent & _a1);// public missing arg names
    AnimationEvent();// public RVA = 0x65980
    AnimationEvent* _CONSTRUCTOR();// public RVA = 0x65980
    // no_addr class AnimationEvent & operator=(const class AnimationEvent & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class GameData;

class AnimationSFXEvent : public AnimationEvent
{
public:
    // AnimationEvent offset = 0x0, length = 0x8
    // no_addr void AnimationSFXEvent(const class AnimationSFXEvent & _a1);// public missing arg names
    AnimationSFXEvent(GameData* data);// public RVA = 0x64A70
    AnimationSFXEvent* _CONSTRUCTOR(GameData* data);// public RVA = 0x64A70
    virtual void trigger(Character* character) const override;// public RVA = 0x64980 vtable offset = 0x0
    void _NV_trigger(Character* character) const;// public RVA = 0x64980 vtable offset = 0x0
    virtual void finish(Character* character) const override;// public RVA = 0x64A30 vtable offset = 0x0
    void _NV_finish(Character* character) const;// public RVA = 0x64A30 vtable offset = 0x0
    virtual std::string toString() const override;// public RVA = 0x6D660 vtable offset = 0x0
    std::string _NV_toString() const;// public RVA = 0x6D660 vtable offset = 0x0
    std::string name; // 0x8 Member
    std::string key; // 0x30 Member
    std::string value; // 0x58 Member
    std::string stop; // 0x80 Member
    bool isFootstep; // 0xA8 Member
    virtual ~AnimationSFXEvent();// public RVA = 0x6D540 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x6D540 vtable offset = 0x0
    // no_addr class AnimationSFXEvent & operator=(const class AnimationSFXEvent & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class AnimationGroundEvent : public AnimationEvent
{
public:
    // AnimationEvent offset = 0x0, length = 0x8
    // no_addr void AnimationGroundEvent(const class AnimationGroundEvent & _a1);// public missing arg names
    AnimationGroundEvent(GameData* data);// public RVA = 0x64CF0
    AnimationGroundEvent* _CONSTRUCTOR(GameData* data);// public RVA = 0x64CF0
    virtual void trigger(Character* character) const override;// public RVA = 0x652F0 vtable offset = 0x0
    void _NV_trigger(Character* character) const;// public RVA = 0x652F0 vtable offset = 0x0
    virtual std::string toString() const override;// public RVA = 0x6D770 vtable offset = 0x0
    std::string _NV_toString() const;// public RVA = 0x6D770 vtable offset = 0x0
    std::string bone; // 0x8 Member
    virtual ~AnimationGroundEvent();// public RVA = 0x6D6B0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x6D6B0 vtable offset = 0x0
    // no_addr class AnimationGroundEvent & operator=(const class AnimationGroundEvent & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class AnimationReloadEvent : public AnimationEvent
{
public:
    // AnimationEvent offset = 0x0, length = 0x8
    virtual void trigger(Character* character) const override;// public RVA = 0x436A20 vtable offset = 0x0
    void _NV_trigger(Character* character) const;// public RVA = 0x436A20 vtable offset = 0x0
    // no_addr void AnimationReloadEvent(const class AnimationReloadEvent & _a1);// public missing arg names
    AnimationReloadEvent();// public RVA = 0x66FD0
    AnimationReloadEvent* _CONSTRUCTOR();// public RVA = 0x66FD0
    virtual ~AnimationReloadEvent();// public RVA = 0x66FF0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x66FF0 vtable offset = 0x0
    // no_addr class AnimationReloadEvent & operator=(const class AnimationReloadEvent & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};