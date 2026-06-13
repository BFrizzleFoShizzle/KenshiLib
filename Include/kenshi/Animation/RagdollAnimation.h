#pragma once

#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>

class AnimationClass;

class RagdollAnimation
{
public:
    // no_addr void RagdollAnimation(const class RagdollAnimation & _a1);// public missing arg names
    RagdollAnimation(AnimationClass* animationClass);// public RVA = 0x7D1E80
    RagdollAnimation* _CONSTRUCTOR(AnimationClass* animationClass);// public RVA = 0x7D1E80
    bool isAnimating() const;// public RVA = 0x7D01A0
    void update();// public RVA = 0x7D1680
    void setTargetAnimation(Ogre::Entity* ent, Ogre::OldSkeletonInstance* skel, Ogre::Animation* animation, float duration);// public RVA = 0x7D1ED0
    const std::string& getTargetAnimation() const;// public RVA = 0x7D01B0
    float getAnimationTime() const;// public RVA = 0x7D01C0
    class RagdollAnimationTrack
    {
    public:
        bool active; // 0x0 Member
        Ogre::Quaternion startRotation; // 0x4 Member
        Ogre::Quaternion endRotation; // 0x14 Member
        Ogre::Vector3 startPosition; // 0x24 Member
        Ogre::Vector3 endPosition; // 0x30 Member
        Ogre::OldBone* bone; // 0x40 Member
        RagdollAnimationTrack();// public RVA = 0x7D6040
        RagdollAnimationTrack* _CONSTRUCTOR();// public RVA = 0x7D6040
        RagdollAnimation::RagdollAnimationTrack& operator=(const RagdollAnimation::RagdollAnimationTrack& __that);// public RVA = 0x7D6090
    };
    AnimationClass* animationClass; // 0x0 Member
    std::string targetAnimationName; // 0x8 Member
    Ogre::OldSkeletonInstance* skeleton; // 0x30 Member
    Ogre::Entity* entity; // 0x38 Member
    Ogre::vector<RagdollAnimation::RagdollAnimationTrack>::type tracks; // 0x40 Member
    bool firstUpdate; // 0x60 Member
    bool animating; // 0x61 Member
    float endTime; // 0x64 Member
    float curTime; // 0x68 Member
    ~RagdollAnimation();// public RVA = 0x5C2D20
    void _DESTRUCTOR();// public RVA = 0x5C2D20
    // no_addr class RagdollAnimation & operator=(const class RagdollAnimation & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};