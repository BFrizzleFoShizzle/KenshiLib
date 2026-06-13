#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/StringPair.h>
#include <kenshi/util/YesNoMaybe.h>
#include <kenshi/GameData.h>
#include <kenshi/Enums.h>
#include <kenshi/MedianFilter.h>

class CharMovement;
class CombatTechniqueData;
class AnimationData;
class Character;
class DatapanelGUI;
class DataPanelLine;
class AnimationEvent;

// TODO move?
enum CharacterAnimCategory
{
    ANIM_NORMAL,
    ANIM_IMPRISONED,
    ANIM_SLEEPING,
    ANIM_CARRIED,
    ANIM_SWIMMING,
    ANIM_GROUNDED,
    ANIM_COMBAT,
    ANIM_ATTACKS,
    ANIM_RANGED
};

enum AnimationLayerEnum
{
    LOWER,
    UPPER,
    OVERLAY,
    TAIL,
    EARS,
    ALL
};

// TODO move?
class AnimationEvents
{
public:
    // no_addr void AnimationEvents(const class AnimationEvents & _a1);// public missing arg names
    AnimationEvents(Character* c);// public RVA = 0x64720
    AnimationEvents* _CONSTRUCTOR(Character* c);// public RVA = 0x64720
    ~AnimationEvents();// public RVA = 0x647A0
    void _DESTRUCTOR();// public RVA = 0x647A0
    void setInitialFrame(float f);// public RVA = 0x64640
    void update(float frame, bool sound);// public RVA = 0x64650
    void addEvent(AnimationEvent* e, float time);// public RVA = 0x64830
    void addEvent(GameData* data, float time);// public RVA = 0x64DD0
    void addList(const ogre_unordered_map<GameData*, float>::type* list);// public RVA = 0x651C0
    void addList(const Ogre::vector<GameDataReference>::type* list);// public RVA = 0x65240
    int size() const;// public RVA = 0x5C0880
    struct Pair
    {
        AnimationEvent* event; // 0x0 Member
        float time; // 0x8 Member
    };
    lektor<AnimationEvents::Pair> events; // 0x0 Member
    float lastFrame; // 0x18 Member
    int nextEvent; // 0x1C Member
    Character* character; // 0x20 Member
    // no_addr class AnimationEvents & operator=(const class AnimationEvents & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class AnimationClassBase : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void AnimationClassBase(const class AnimationClassBase & _a1);// public missing arg names
    AnimationClassBase();// public RVA = 0x628850
    AnimationClassBase* _CONSTRUCTOR();// public RVA = 0x628850
    virtual ~AnimationClassBase();// public RVA = 0x626670 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x626670 vtable offset = 0x0
    void create(CharMovement* mov);// public RVA = 0x620F30
    void setVisible(bool on);// public RVA = 0x5B1C70
    bool getVisible() const;// public RVA = 0x5B1CC0
    void stopAllAnimation(bool hardStop);// public RVA = 0x5B30E0
    void clearAllAnimationUT();// public RVA = 0x5B41E0
    Ogre::Quaternion getBoneWorldOrientation(const std::string& name) const;// public RVA = 0x5B1650
    Ogre::Vector3 getBoneWorldPosition(const std::string& name, float scale) const;// public RVA = 0x5B14D0
    bool getHasBone(const std::string& name) const;// public RVA = 0x5B1610
    Ogre::OldBone* _getBone(const std::string& name);// public RVA = 0x5B1460
    bool hasAnimation(const std::string& s);// public RVA = 0x5B1F60
    const Ogre::Vector3 getSceneNodePosition() const;// public RVA = 0x5C6E60
    const Ogre::Quaternion getSceneNodeOrientation() const;// public RVA = 0x5C6EC0
    Ogre::Quaternion getBoneLocalOrientation(const std::string& name) const;// public RVA = 0x5B1A30
    Ogre::Vector3 getBoneLocalPosition(const std::string& name) const;// public RVA = 0x5B1740
    const Ogre::Vector3& getRootBoneWorldPosition() const;// public RVA = 0x5B1AB0
    Ogre::Vector3 getRootBoneLocalPosition() const;// public RVA = 0x5B5EC0
    Ogre::Vector3 getBoneInitialLocalPosition(const std::string& name) const;// public RVA = 0x5B17E0
    Ogre::Quaternion getBoneInitialLocalOrientation(const std::string& name) const;// public RVA = 0x5B18F0
    const Ogre::Vector3& getBoneInitialWorldPosition(const std::string& name) const;// public RVA = 0x5B7C20
    const Ogre::Quaternion& getBoneInitialWorldOrientation(const std::string& name) const;// public RVA = 0x5B7280
    bool zeroOutTheBlending; // 0x8 Member
    void resetOrientation();// public RVA = 0x5B0B90
    float getAnimationProgress(CombatTechniqueData* name);// public RVA = 0x5B4430
    float getAnimationProgress(AnimationData* name);// public RVA = 0x5B3270
    float getAnimationProgress(const std::string& name);// public RVA = 0x5B3CE0
    // no_addr class Ogre::Vector3 getPosition();// public
    Ogre::Quaternion getOrientation() const;// public RVA = 0x5C6F30
    void setVerticalPosition(float hpos);// public RVA = 0x5B1C10
    virtual unsigned __int64 getAudioObject() const = 0;// public vtable offset = 0x8
    virtual Character* getCharacter();// public RVA = 0x6412F0 vtable offset = 0x10
    Character* _NV_getCharacter();// public RVA = 0x6412F0 vtable offset = 0x10
    void setMasterTimeSpeed(float speed);// public RVA = 0x51C070
    float getMasterTimeSpeed() const;// public RVA = 0x51C080
    float getMasterTime() const;// public RVA = 0x5B0880
    // no_addr void setMasterTime(float _a1);// public missing arg names
    bool isVisibleEntity() const;// public RVA = 0x5C6FA0
    void initBoneInitialWorldPositions();// protected RVA = 0x5B8B20
    boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy > > boneInitialWorldPositions; // 0x10 Member
    std::map<std::string, Ogre::Quaternion, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy > > boneInitialWorldOrientations; // 0x50 Member
    Ogre::Quaternion desiredOrientation; // 0x78 Member
    bool isActivated; // 0x88 Member
    bool activateFlag; // 0x89 Member
    Ogre::Vector3 lastAnimRelocation; // 0x8C Member
    Ogre::Vector3 rootBonePosition; // 0x98 Member
    bool isVisible; // 0xA4 Member
    bool isIdle; // 0xA5 Member
    Ogre::Entity* body; // 0xA8 Member
    Ogre::SceneNode* node; // 0xB0 Member
    Ogre::OldSkeletonInstance* skeleton; // 0xB8 Member
    CharMovement* movement; // 0xC0 Member
    class SingleAnimation
    {
    public:
        // no_addr void SingleAnimation(const class AnimationClassBase::SingleAnimation & _a1);// public missing arg names
        SingleAnimation(const std::string& name, AnimationData* fixedData, float _speed, bool _slave, float fadein, bool loop, bool autoremove, float blend, bool norm, bool rightArm, bool leftArm, float offset, AnimationClassBase* animationClass, bool actio, float endsat);// public RVA = 0x5B4970
        SingleAnimation* _CONSTRUCTOR(const std::string& name, AnimationData* fixedData, float _speed, bool _slave, float fadein, bool loop, bool autoremove, float blend, bool norm, bool rightArm, bool leftArm, float offset, AnimationClassBase* animationClass, bool actio, float endsat);// public RVA = 0x5B4970
        ~SingleAnimation();// public RVA = 0x5B3490
        void _DESTRUCTOR();// public RVA = 0x5B3490
        float getAnimTime() const;// public RVA = 0x5B0EA0
        bool hasSound() const;// public RVA = 0x5B2050
        void _disable();// public RVA = 0x5B0E40
        void disable();// public RVA = 0x5B0890
        bool notStartedYet() const;// public RVA = 0x5B08A0
        bool isACombatAnimation() const;// public RVA = 0x5B08B0
        bool isABlockAnimation() const;// public RVA = 0x5B08C0
        void _debugCallback(DataPanelLine* _a1);// public RVA = 0x5B08E0 missing arg names
        bool initialiseMainState();// public RVA = 0x5B2910
        bool fade(float frameTIME, float blendrate);// public RVA = 0x5B0EB0
        void update(float masterTime, float frameTIME, bool playSounds);// public RVA = 0x5B0F80
        std::string animName; // 0x0 Member
        Ogre::AnimationState* mainState; // 0x28 Member
        const AnimationData* animationData; // 0x30 Member
        AnimationClassBase* animationClass; // 0x38 Member
        float speed; // 0x40 Member
        float weight; // 0x44 Member
        float desiredWeight; // 0x48 Member
        float synchOffset; // 0x4C Member
        float currentFrameTime; // 0x50 Member
        float currentFrameTime01; // 0x54 Member
        float acceptableEndTime01; // 0x58 Member
        bool isAWholeBodyAction; // 0x5C Member
        bool looped; // 0x5D Member
        bool synchSlave; // 0x5E Member
        bool normalise; // 0x5F Member
        bool msgSetToReversePosition; // 0x60 Member
        bool msgHardStop; // 0x61 Member
        bool reversePlayOnFadeOut; // 0x62 Member
        bool usingRightArm; // 0x63 Member
        bool usingLeftArm; // 0x64 Member
        bool _breakWhenEnded; // 0x65 Member
        bool autoRemove; // 0x66 Member
        bool stillWanted; // 0x67 Member
        bool movesFromOrigin; // 0x68 Member
        AnimationEvents events; // 0x70 Member
        // no_addr class AnimationClassBase::SingleAnimation & operator=(const class AnimationClassBase::SingleAnimation & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    class AnimationLayer
    {
    public:
        lektor<AnimationClassBase::SingleAnimation*> addList; // 0x0 Member
        lektor<AnimationClassBase::SingleAnimation*> removeList; // 0x18 Member
        void addToRemoveList(AnimationClassBase::SingleAnimation* anim);// private RVA = 0x5B2CE0
        void clearLists();// private RVA = 0x5B4550
        void _clearListsSafe();// private RVA = 0x5B4720
        void randomiseAnimationPosition(const std::string& name);// private RVA = 0x5B1150
        Ogre::Entity* body; // 0x30 Member
        CharMovement* movement; // 0x38 Member
        float fadeRate; // 0x40 Member
        AnimationClassBase* animationClass; // 0x48 Member
        AnimationClassBase::SingleAnimation* runAnimation(bool action, AnimationData* animData, const std::string& _nameDat, float speed, bool slavesynched, bool looped, bool normalised, float blend, bool rightArm, bool leftArm, float offset, bool movesFromOrigin, float acceptableEndTime);// private RVA = 0x5B4AF0
        AnimationClassBase::SingleAnimation* startAnimation(bool action, AnimationData* animData, const std::string& name, float speed, bool autoremove, bool movesFromOrigin, bool normalised, bool rightArm, bool leftArm, bool synchSlave, float startWeight, float acceptableEndTime);// private RVA = 0x5B5C90
        AnimationClassBase::SingleAnimation* isAnimationInRemoveList(AnimationData* state);// public RVA = 0x5B27F0
        AnimationClassBase::SingleAnimation* isAnimationInAddList(const std::string& state);// public RVA = 0x5B3900
        AnimationClassBase::SingleAnimation* isAnimationInAddList(CombatTechniqueData* state);// public RVA = 0x5B39D0
        AnimationClassBase::SingleAnimation* isAnimationInAddList(AnimationData* state);// public RVA = 0x5B2840
        AnimationClassBase::SingleAnimation* isAnimationInAddList_Datname(const std::string& state);// public RVA = 0x5B3830
        AnimationClassBase::SingleAnimation* takeFromRemoveList(const std::string& state);// public RVA = 0x5B3BD0
        AnimationClassBase::SingleAnimation* takeFromAddList(AnimationData* what);// public RVA = 0x5B2890
        AnimationClassBase::SingleAnimation* takeFromAddList(const std::string& what);// public RVA = 0x5B3AC0
        // no_addr void AnimationLayer(const class AnimationClassBase::AnimationLayer & _a1);// public missing arg names
        AnimationLayer(CharMovement* mov, float fadeMult, AnimationClassBase* parent);// public RVA = 0x636640
        AnimationLayer* _CONSTRUCTOR(CharMovement* mov, float fadeMult, AnimationClassBase* parent);// public RVA = 0x636640
        ~AnimationLayer();// public RVA = 0x636760
        void _DESTRUCTOR();// public RVA = 0x636760
        void debugGetAllAnimations(DatapanelGUI* panel);// public RVA = 0x5B6720
        float getTotalAnimationWeight(bool thisLayer, bool wholeBody, bool includeRemovelist);// public RVA = 0x5B2060
        float getTotalAnimationWeight(CharacterAnimCategory cat);// public RVA = 0x5B2260
        float getTotalActionAnimationWeight();// public RVA = 0x5B2430
        bool stillPlayingAnActionOrSomething();// public RVA = 0x5B25D0
        float getCurrentAnimationWeight(const std::string& name);// public RVA = 0x5B3DA0
        void setBody(Ogre::Entity* owner);// public RVA = 0x5B4DE0
        void updateAnimationSpeed(const std::string& name, float speed);// public RVA = 0x5B3530
        void removeAnimation(AnimationData* anim);// public RVA = 0x5B3190
        void removeAnimation(const std::string& name);// public RVA = 0x5B3700
        void update2frame();// public RVA = 0x5B3360
        Ogre::Vector3 update(float masterTime, CharMovement* movement, float frameTIME, bool zeroTheBlending, bool normalise, float normaliseTo);// public RVA = 0x5B54B0
        void moveAllToRemoveList();// public RVA = 0x5B2EE0
        void endAllAnimations();// public RVA = 0x5B2E40
        void stopActionAnimations();// public RVA = 0x5B2F70
        void stopAllAnimation(bool hardStop);// public RVA = 0x5B3080
        void stopAllAnimationThatMovesFromOrigin();// public RVA = 0x5B2780
        void clearAllAnimationUT();// public RVA = 0x5B40E0
        float getAnimTime() const;// public RVA = 0x5B26F0
        bool usingRightArm();// public RVA = 0x5B2630
        bool usingLeftArm();// public RVA = 0x5B2690
        // no_addr class AnimationClassBase::AnimationLayer & operator=(const class AnimationClassBase::AnimationLayer & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    float masterTime; // 0xC8 Member
    float masterSpeed; // 0xCC Member
    AnimationClassBase::SingleAnimation* getAnimationPlaying_animName(const std::string& name);// public RVA = 0x5B3E90
    AnimationClassBase::SingleAnimation* getAnimationPlaying_datName(const std::string& name);// public RVA = 0x5B3EF0
    AnimationClassBase::SingleAnimation* getAnimationPlaying(CombatTechniqueData* name);// public RVA = 0x5B3F50
    AnimationClassBase::SingleAnimation* getAnimationPlaying(AnimationData* name);// public RVA = 0x5B2B90
    bool isAnimationPlaying(const std::string& name);// public RVA = 0x5B3F70
    float getAnimationCurrentWeight(AnimationData* name);// public RVA = 0x5B3330
    float getTotalActionAnimationWeight();// public RVA = 0x5B2B50
    bool stillPlayingAnActionOrSomething();// public RVA = 0x5B2D30
    Ogre::AnimationState* getAnimationState(const std::string& name);// public RVA = 0x51C320
    Ogre::Animation* getAnimation(const std::string& name);// public RVA = 0x51C390
    AnimationData* getAnimation_Medic(const hand& inwhat);// public RVA = 0x520250
    AnimationData* getAnimation_Lockpick(const hand& inwhat);// public RVA = 0x520440
    virtual AnimationData* getAnimationData(const std::string& _a1) = 0;// public vtable offset = 0x18 missing arg names
    lektor<AnimationClassBase::AnimationLayer*> layer; // 0xD0 Member
    // no_addr class AnimationClassBase & operator=(const class AnimationClassBase & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class AnimationClassHuman;
class AppearanceBase;
class RagdollClass;

namespace Scythe
{
    class SkeletonData;
}

// TODO move?
class AnimsListsManager
{
public:
    struct AnimList
    {
        lektor<AnimationData*> movementAnimsBase; // 0x0 Member
        lektor<AnimationData*> movementAnimsUpper; // 0x18 Member
        lektor<AnimationData*> idleAnims; // 0x30 Member
        lektor<AnimationData*> strafeAnims; // 0x48 Member
        lektor<AnimationData*> attacks; // 0x60 Member
        boost::unordered::unordered_map<std::string, AnimationData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AnimationData*>, Ogre::GeneralAllocPolicy > > actionAnims; // 0x78 Member
        boost::unordered::unordered_map<std::string, AnimationData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AnimationData*>, Ogre::GeneralAllocPolicy > > allAnims; // 0xB8 Member
        AnimationData* turningAnim; // 0xF8 Member
        boost::unordered::unordered_map<GameData*, lektor<AnimationData*>, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, lektor<AnimationData*> >, Ogre::GeneralAllocPolicy > > stumbleAnims; // 0x100 Member
        boost::unordered::unordered_map<WeatherAffecting, lektor<AnimationData*>, boost::hash<WeatherAffecting>, std::equal_to<WeatherAffecting>, Ogre::STLAllocator<std::pair<WeatherAffecting const, lektor<AnimationData*> >, Ogre::GeneralAllocPolicy > > weatherOverlayAnims; // 0x140 Member
        lektor<AnimationData*>* getStumbles(GameData* bodypart);// public RVA = 0x445D90
        AnimationData* getStrafe();// public RVA = 0x522CB0
        AnimList(const AnimsListsManager::AnimList& __that);// public RVA = 0x5C50A0
        AnimList* _CONSTRUCTOR(const AnimsListsManager::AnimList& __that);// public RVA = 0x5C50A0
        AnimList();// public RVA = 0xB39C0
        AnimList* _CONSTRUCTOR();// public RVA = 0xB39C0
        ~AnimList();// public RVA = 0xB3CA0
        void _DESTRUCTOR();// public RVA = 0xB3CA0
        // no_addr struct AnimsListsManager::AnimList & operator=(const struct AnimsListsManager::AnimList & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    static AnimsListsManager* getSingleton();// public RVA = 0xB70A0
    AnimsListsManager::AnimList* getAnimalList(GameData* race, GameData* animationData);// public RVA = 0x5C5D60
    AnimsListsManager::AnimList* getCharacterList();// public RVA = 0x8AF50
    void setupCharacterList();// private RVA = 0x5BC990
    void setupAnimalList(GameData* animalRace, GameData* getAnimsFrom);// private RVA = 0x5BC2C0
    void setupList(lektor<GameData*>& data, AnimsListsManager::AnimList& list, lektor<GameData*>& combatTechniques);// private RVA = 0x5BB5C0
    AnimsListsManager::AnimList characterAnimations; // 0x0 Member
    std::map<GameData*, AnimsListsManager::AnimList, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, AnimsListsManager::AnimList>, Ogre::GeneralAllocPolicy > > animalAnimations; // 0x180 Member
    // no_addr void AnimsListsManager(const class AnimsListsManager & _a1);// public missing arg names
    AnimsListsManager();// public RVA = 0xB6EA0
    AnimsListsManager* _CONSTRUCTOR();// public RVA = 0xB6EA0
    // no_addr void ~AnimsListsManager();// public
    // no_addr class AnimsListsManager & operator=(const class AnimsListsManager & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

// TODO move?
enum StanceEnum
{
    STANDING,
    CROUCHED,
    PRONE,
    MIDAIR
};

// TODO move?

class AnimationRequirement
{
public:
    // no_addr void AnimationRequirement(class AnimationRequirement & _a1);// public missing arg names
    AnimationRequirement();// public RVA = 0x51F310
    AnimationRequirement* _CONSTRUCTOR();// public RVA = 0x51F310
    CharacterAnimCategory currentAnimCategory; // 0x0 Member
    MedianFilter filterFW; // 0x8 Member
    MedianFilter filterStrafe; // 0x48 Member
    float moveSpeed; // 0x88 Member
    float turnSpeed; // 0x8C Member
    float smoothedMoveSpeed; // 0x90 Member
    float strafeSpeed; // 0x94 Member
    float lastStrafeWeight; // 0x98 Member
    bool isStrafeMode; // 0x9C Member
    bool weaponL; // 0x9D Member
    bool weaponR; // 0x9E Member
    bool isAnimal; // 0x9F Member
    bool doWeatherAnimation; // 0xA0 Member
    bool holdBreath; // 0xA1 Member
    StanceEnum stance; // 0xA4 Member
    WeatherAffecting weatherType; // 0xA8 Member
    float maxSpeed; // 0xAC Member
    float weatherStrength; // 0xB0 Member
    float actionSpeedMult; // 0xB4 Member
    bool isActionSlave; // 0xB8 Member
    std::string attachRootToMastersBone; // 0xC0 Member
    float slaveSync; // 0xE8 Member
    hand slaveHandle; // 0xF0 Member
    AnimationData* forcedSlaveLoop; // 0x110 Member
    bool isUpperBodyOnlyAction();// public RVA = 0x51C2E0
    CombatTechniqueData* _currentCombatTechnique; // 0x118 Member
    AnimationData* _currentAction; // 0x120 Member
    bool hasAction() const;// public RVA = 0x2ADB20
    void clearAction();// public RVA = 0x51C040
    float stateTimer; // 0x128 Member
    bool crouched; // 0x12C Member
    bool prone; // 0x12D Member
    bool carryingLeft; // 0x12E Member
    bool carryingRight; // 0x12F Member
    bool carried; // 0x130 Member
    AnimationData* currentStumble; // 0x138 Member
    bool idle; // 0x140 Member
    AnimationData* idleState; // 0x148 Member
    float idleTimer; // 0x150 Member
    YesNoMaybe isCombatMode; // 0x154 Member
    YesNoMaybe isStealthMode; // 0x158 Member
    bool legsIdle; // 0x15C Member
    bool upperIdle; // 0x15D Member
    float legDamageR; // 0x160 Member
    float legDamageL; // 0x164 Member
    Ogre::Vector3 pos; // 0x168 Member
    WeaponCategory currentWeapon; // 0x174 Member
    std::set<StringValuePair, std::less<StringValuePair>, Ogre::STLAllocator<StringValuePair, Ogre::GeneralAllocPolicy > > desiredPainOverlayAnimations; // 0x178 Member
    std::string desiredPainOverlayAnimationOverride; // 0x1A0 Member
    ~AnimationRequirement();// public RVA = 0x5C4CA0
    void _DESTRUCTOR();// public RVA = 0x5C4CA0
    // no_addr class AnimationRequirement & operator=(const class AnimationRequirement & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class MotionFilter;
class RagdollAnimation;

// TODO move?
class AnimationChoices
{
public:
    ~AnimationChoices();// public RVA = 0x523FB0
    void _DESTRUCTOR();// public RVA = 0x523FB0
    lektor<AnimationData*> anims; // 0x0 Member
    lektor<float> weights; // 0x18 Member
    void normaliseWeights();// public RVA = 0x51C660
    float calculateSpeedOfMoveAnims(float travelSpeed, float characterHeight);// public RVA = 0x51C880
    AnimationData* chooseHighestScore();// public RVA = 0x522CD0
    // no_addr const class AnimationChoices & operator=(const class AnimationChoices & _a1);// public missing arg names
    AnimationChoices(const AnimationChoices& __that);// public RVA = 0x525C40
    AnimationChoices* _CONSTRUCTOR(const AnimationChoices& __that);// public RVA = 0x525C40
    AnimationChoices();// public RVA = 0x524030
    AnimationChoices* _CONSTRUCTOR();// public RVA = 0x524030
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class AnimationClass : public AnimationClassBase
{
public:
    // AnimationClassBase offset = 0x0, length = 0xE8
    // no_addr void AnimationClass(class AnimationClass & _a1);// public missing arg names
    AnimationClass();// public RVA = 0x5E8300
    AnimationClass* _CONSTRUCTOR();// public RVA = 0x5E8300
    void debugGetAllAnimations(DatapanelGUI* panel);// public RVA = 0x5B1140
    virtual ~AnimationClass();// public RVA = 0x5B9020 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x5B9020 vtable offset = 0x0
    virtual AnimationClassHuman* isHuman() = 0;// public vtable offset = 0x20
    AppearanceBase* appearance; // 0xE8 Member
    virtual bool create(CharMovement* _a1, GameDataCopyStandalone* _a2, GameData* _a3, Character* _a4, GameData* _a5) = 0;// public vtable offset = 0x28 missing arg names
    void startStumble(AnimationData* anim);// public RVA = 0x51FD10
    void endStumble();// public RVA = 0x51E0C0
    bool currentlyStumbling() const;// public RVA = 0x334AC0
    AnimationData* getCurrentlyStumbleAnim() const;// public RVA = 0x43FBC0
    bool isCurrentlyIncapableOfWaypointMovemode();// public RVA = 0x51C0F0
    void threadSafeRagdollUpdateUT();// public RVA = 0x5B7A00
    virtual void update(float frameTIME);// public RVA = 0x5B6140 vtable offset = 0x30
    void _NV_update(float frameTIME);// public RVA = 0x5B6140 vtable offset = 0x30
    virtual float calculatePositionWithWaterHeight() = 0;// public vtable offset = 0x38
    void updateAnimationCharacterEditor(float time);// public RVA = 0x5B6580
    void updateThreaded(float frameTIME);// public RVA = 0x5B3FF0
    virtual void rotationUpdate(float frameTime);// public RVA = 0x5B1D60 vtable offset = 0x40
    void _NV_rotationUpdate(float frameTime);// public RVA = 0x5B1D60 vtable offset = 0x40
    void updateAnimationTransforms();// public RVA = 0x5B0E30
    void setPosition(const Ogre::Vector3& pos);// public RVA = 0x5B1380
    void setPosition(const Ogre::Vector3& pos, const Ogre::Quaternion& dir);// public RVA = 0x5B12B0
    void setPosition(const Ogre::Vector3& pos, const Ogre::Vector3& dir);// public RVA = 0x5B1170
    bool getPosition(Ogre::Vector3& pos) const;// public RVA = 0x5B13B0
    Ogre::Vector3 rotateEntityAroundBone(const std::string& bone, Ogre::Vector3 dir);// public RVA = 0x5B29D0
    const Ogre::Vector3& getBoneScale(const std::string& bonename) const;// public RVA = 0x5B1400
    void deactivateVisuals();// public RVA = 0x5B8EB0
    bool getIsActivated() const;// public RVA = 0x43FBD0
    void setBodyEntity(Ogre::Entity* newbody);// public RVA = 0x5B8C20
    void resetBody();// public RVA = 0x5B4820
    bool restartAction(const std::string& name);// public RVA = 0x51C400
    void playAction(AnimationData* anim, float speedMult, float initialWeight, bool isStumble);// public RVA = 0x51E330
    void playAction(const std::string& dataname, float speedMult, float initialWeight, bool isStumble);// public RVA = 0x51FC30
    bool stopAction();// public RVA = 0x51D820
    bool stopAction(const std::string& name);// public RVA = 0x51D960
    void setAnimationMoveSpeed(float speed);// public RVA = 0x51EC30
    void setStrafeSpeed(float speed);// public RVA = 0x51EC70
    void setCombatMode(bool on);// public RVA = 0x51C4B0
    // no_addr void holdBreath(bool _a1);// public missing arg names
    void setWeatherType(WeatherAffecting w, float stren, bool doWeatherAnimation);// public RVA = 0x51C180
    WeatherAffecting getWeatherType() const;// public RVA = 0x5C6FB0
    float getWeatherStrength() const;// public RVA = 0x5C6FC0
    void setStealthMode(bool on);// public RVA = 0x51C4F0
    void setMaximumSpeed(float speed);// public RVA = 0x51C1E0
    float getMaximumSpeed();// public RVA = 0x663C20
    bool isLinearAnimationDone_byName(const std::string& name);// public RVA = 0x5B4480
    bool isLinearAnimationDone(AnimationData* anim);// public RVA = 0x5B32C0
    // no_addr float getAnimTime(enum AnimationLayerEnum _a1);// public missing arg names
    // no_addr void stopAllAnimationThatMovesFromOrigin(enum AnimationLayerEnum _a1);// public missing arg names
    float getFootHeight() const;// public RVA = 0x5B08F0
    void calculateFeetHeight();// public RVA = 0x5B5FD0
    void setBootHeight(float h);// public RVA = 0x53E600
    bool isBeingCarried() const;// public RVA = 0x7D0160
    bool isTotallyRagdoll() const;// public RVA = 0x7D0180
    void notifyRagdollNeedsAnUpdate();// public RVA = 0x7D00F0
    void setCarryMode(bool ed, bool left, bool right);// public RVA = 0x51C150
    void setCombatModeLegsIdle(bool on);// public RVA = 0x51C1A0
    void setCombatModeUpperIdle(bool on);// public RVA = 0x51C1C0
    virtual RagdollClass* getRagdoll() const;// public RVA = 0x5C4E10 vtable offset = 0x48
    RagdollClass* _NV_getRagdoll() const;// public RVA = 0x5C4E10 vtable offset = 0x48
    bool isRagdoll();// public RVA = 0x7D00A0
    bool setupRagdoll(Scythe::SkeletonData* skelData);// public RVA = 0x7D3910
    void ragdollAnimateTo(const std::string& targetAnimationName, float duration);// public RVA = 0x7D2480
    bool isRagdollAnimated() const;// public RVA = 0x334510
    virtual void ragdollModeUT(bool on, Ogre::Vector3 momentum, RagdollPart::Enum part, const std::string& physicsFile, Character* me);// public RVA = 0x5B9290 vtable offset = 0x50
    void _NV_ragdollModeUT(bool on, Ogre::Vector3 momentum, RagdollPart::Enum part, const std::string& physicsFile, Character* me);// public RVA = 0x5B9290 vtable offset = 0x50
    virtual void postRagdollCreationCallbackMT(bool on);// public RVA = 0x5B7FA0 vtable offset = 0x58
    void _NV_postRagdollCreationCallbackMT(bool on);// public RVA = 0x5B7FA0 vtable offset = 0x58
    bool hasRagdollPart(const RagdollPart::Enum& part);// public RVA = 0x7D0130
    bool isPhysical() const;// public RVA = 0x334C80
    float getHeight() const;// public RVA = 0x5B1BF0
    void randomiseAnimationPosition();// public RVA = 0x5B1160
    Ogre::Vector3 beingCarriedUpdate(const Ogre::Vector3& pos, const Ogre::Quaternion& rot);// public RVA = 0x5B5200
    void rangedCombatModeUpdate(const Ogre::Vector3& targetpos);// public RVA = 0x51D580
    void runAnimation(AnimationData* anim, float speed, AnimationLayerEnum lay, float blend);// public RVA = 0x5B7340
    void runAnimation(AnimationData* anim, float speed, AnimationLayerEnum lay, float blend, const std::string& ext);// public RVA = 0x5B7780
    void runAnimation(AnimationData* anim, float speed, float blend);// public RVA = 0x333F80
    void runAnimation(const std::string& name, float speed, float blend);// public RVA = 0x339D00
    void runAnimation_manualTiming(AnimationData* anim, float time01, float blend);// public RVA = 0x5B7550
    void endCombatAnimation();// public RVA = 0x5B34E0
    void runCombatAnimation(CombatTechniqueData* anim, float speed, std::string additionalString);// public RVA = 0x5B6E80
    void startCombatAnimation(CombatTechniqueData* anim, float speed, std::string additionalString);// public RVA = 0x5B7080
    void startAnimation(AnimationData* dat, float speed, float startWeight);// public RVA = 0x5B6DC0
    void startAnimation(const std::string& anim, float speed, float startWeight);// public RVA = 0x51C090
    void stopAnimation(const std::string& anim);// public RVA = 0x5B36C0
    void stopAnimation(AnimationData* ad);// public RVA = 0x5B3690
    AnimationEvents* getEvents(const std::string& animation);// public RVA = 0x5B2DA0
    void activateVisuals();// public RVA = 0x5B1AC0
    virtual AnimationData* getAnimationData(const std::string& name) override;// public RVA = 0x5C4EE0 vtable offset = 0x0
    AnimationData* _NV_getAnimationData(const std::string& name);// public RVA = 0x5C4EE0 vtable offset = 0x0
    virtual AnimationData* getAnimationData(GameData* dat);// public RVA = 0x5C4F10 vtable offset = 0x60
    AnimationData* _NV_getAnimationData(GameData* dat);// public RVA = 0x5C4F10 vtable offset = 0x60
    virtual AnimationData* getAnimationDataByOgreName(const std::string& name);// public RVA = 0x5B4340 vtable offset = 0x68
    AnimationData* _NV_getAnimationDataByOgreName(const std::string& name);// public RVA = 0x5B4340 vtable offset = 0x68
    AnimsListsManager::AnimList* getAnimationDatasList();// public RVA = 0x6DFF0
    float estimateAnimationTime(const std::string& name);// public RVA = 0x5B1CD0
    void notifyRelocatedAnimLoop();// public RVA = 0x5B0910
    void serialiseAppearance(GameData* state);// public RVA = 0x5B1B20
    void setAppearanceData(GameDataCopyStandalone* data);// public RVA = 0x5B9100
    GameDataCopyStandalone* getAppearanceData();// public RVA = 0x5B1B00
    virtual unsigned __int64 getAudioObject() const override;// public RVA = 0x5B0B10 vtable offset = 0x0
    unsigned __int64 _NV_getAudioObject() const;// public RVA = 0x5B0B10 vtable offset = 0x0
    void playSlaveAnim(const std::string& name, float speedMult, float sync, float startWeight);// public RVA = 0x51C3F0
    void runSlaveAnim(const std::string& name, float speedMult, float sync, float startWeight);// public RVA = 0x51CD90
    void endSlaveAnim(const std::string& anim);// public RVA = 0x51E2C0
    bool isSlaveAnimating() const;// public RVA = 0x5C6FD0
    void setSlaveHandle(const hand& h);// public RVA = 0x5C6FE0
    void slaveAttachToBoneMode(const std::string& bone);// public RVA = 0x5E75E0
    const std::string& isSlaveAttachToBoneMode() const;// public RVA = 0x5C7030
    virtual Character* getCharacter() override;// public RVA = 0x5C4E20 vtable offset = 0x0
    Character* _NV_getCharacter();// public RVA = 0x5C4E20 vtable offset = 0x0
    virtual void setLegDamage(float left, float right);// public RVA = 0x51C530 vtable offset = 0x70
    void _NV_setLegDamage(float left, float right);// public RVA = 0x51C530 vtable offset = 0x70
    virtual void setDesiredPainOverlayAnims(std::set<StringValuePair, std::less<StringValuePair>, Ogre::STLAllocator<StringValuePair, Ogre::GeneralAllocPolicy > > _a1);// public RVA = 0x5C4F50 vtable offset = 0x78 missing arg names
    void _NV_setDesiredPainOverlayAnims(std::set<StringValuePair, std::less<StringValuePair>, Ogre::STLAllocator<StringValuePair, Ogre::GeneralAllocPolicy > > _a1);// public RVA = 0x5C4F50 vtable offset = 0x78 missing arg names
    virtual void setDesiredPainOverlayAnimOverride(const std::string& anim);// public RVA = 0x5C4E30 vtable offset = 0x80
    void _NV_setDesiredPainOverlayAnimOverride(const std::string& anim);// public RVA = 0x5C4E30 vtable offset = 0x80
    virtual void ragdollTheWeapons(const std::string& slotname, Item* item, bool attach);// public RVA = 0x5C4E40 vtable offset = 0x88
    void _NV_ragdollTheWeapons(const std::string& slotname, Item* item, bool attach);// public RVA = 0x5C4E40 vtable offset = 0x88
    virtual void setStance(bool crouch, bool prone);// public RVA = 0x5C4E50 vtable offset = 0x90
    void _NV_setStance(bool crouch, bool prone);// public RVA = 0x5C4E50 vtable offset = 0x90
    virtual void setStanceAnimation(StanceEnum _a1);// public RVA = 0x5C4E60 vtable offset = 0x98 missing arg names
    void _NV_setStanceAnimation(StanceEnum _a1);// public RVA = 0x5C4E60 vtable offset = 0x98 missing arg names
    virtual void setEquipmentInHand(bool l, bool r);// public RVA = 0x5C4E70 vtable offset = 0xA0
    void _NV_setEquipmentInHand(bool l, bool r);// public RVA = 0x5C4E70 vtable offset = 0xA0
    virtual bool isTurning() const;// public RVA = 0x5C4E80 vtable offset = 0xA8
    bool _NV_isTurning() const;// public RVA = 0x5C4E80 vtable offset = 0xA8
    virtual bool isTurningFar() const;// public RVA = 0x5C4E90 vtable offset = 0xB0
    bool _NV_isTurningFar() const;// public RVA = 0x5C4E90 vtable offset = 0xB0
    virtual bool lookAt(const Ogre::Vector3& position);// public RVA = 0x5B0B30 vtable offset = 0xB8
    bool _NV_lookAt(const Ogre::Vector3& position);// public RVA = 0x5B0B30 vtable offset = 0xB8
    virtual Ogre::Vector3 getLookDirection() const;// public RVA = 0x5B0B40 vtable offset = 0xC0
    Ogre::Vector3 _NV_getLookDirection() const;// public RVA = 0x5B0B40 vtable offset = 0xC0
    AnimationData* chooseStumbleAnim(GameData* bodypart, CutOrigination hitFrom, bool bigone);// public RVA = 0x51ECA0
    virtual AnimationData* getIdleAnimation();// public RVA = 0x51EAB0 vtable offset = 0xC8
    AnimationData* _NV_getIdleAnimation();// public RVA = 0x51EAB0 vtable offset = 0xC8
    virtual AnimationData* getFloatingAnim();// public RVA = 0x5C4EA0 vtable offset = 0xD0
    AnimationData* _NV_getFloatingAnim();// public RVA = 0x5C4EA0 vtable offset = 0xD0
    virtual AnimationData* getStandingUpAnim();// public RVA = 0x5C4EB0 vtable offset = 0xD8
    AnimationData* _NV_getStandingUpAnim();// public RVA = 0x5C4EB0 vtable offset = 0xD8
    bool hasAction() const;// public RVA = 0x2ADB40
    AnimationRequirement animationRequirements; // 0xF0 Member
    MotionFilter* strafeBlendFilter; // 0x2B8 Member
    AnimsListsManager::AnimList* myAnimList; // 0x2C0 Member
    float feetHeight; // 0x2C8 Member
    float bootHeight; // 0x2CC Member
    float totalActionWeight; // 0x2D0 Member
    int disableRagdollKinematics; // 0x2D4 Member
    Character* me; // 0x2D8 Member
    void animationSelection(float _TIME);// protected RVA = 0x51FD80
    virtual void animationSelectionCombatMode(float _TIME);// protected RVA = 0x51E200 vtable offset = 0xE0
    void _NV_animationSelectionCombatMode(float _TIME);// protected RVA = 0x51E200 vtable offset = 0xE0
    virtual void runStrafe(AnimationData* strafe, float weightLimit);// protected RVA = 0x51D6F0 vtable offset = 0xE8
    void _NV_runStrafe(AnimationData* strafe, float weightLimit);// protected RVA = 0x51D6F0 vtable offset = 0xE8
    virtual void overlaidAnimationSelection();// protected RVA = 0x5C4EC0 vtable offset = 0xF0
    void _NV_overlaidAnimationSelection();// protected RVA = 0x5C4EC0 vtable offset = 0xF0
    virtual bool processTurnAnim();// protected RVA = 0x51C440 vtable offset = 0xF8
    bool _NV_processTurnAnim();// protected RVA = 0x51C440 vtable offset = 0xF8
    void chooseAnims(AnimationChoices& result, const lektor<AnimationData*>* candidates, const AnimationRequirement& requirements, bool isUpperBody, bool isIdles);// protected RVA = 0x51CEE0
    AnimationChoices chooseRandomAnim(lektor<AnimationData*>* candidates, AnimationRequirement& requirements, bool skipCarryModes);// protected RVA = 0x51E500
    float scoreAnim(AnimationData* candidate, AnimationRequirement& requirements, bool skipCarryModes);// protected RVA = 0x51CB90
    void processMoveAnims(lektor<AnimationData*>* listAnims, AnimationRequirement& requirements, bool isUpperBody, float weightHack);// protected RVA = 0x51D160
    bool processActionAnims(boost::unordered::unordered_map<std::string, AnimationData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AnimationData*>, Ogre::GeneralAllocPolicy > >* list, AnimationRequirement& requirements);// protected RVA = 0x51E100
    void processIdleAnims(lektor<AnimationData*>* list, AnimationRequirement& requirements, float frameTIME);// protected RVA = 0x51CC30
    void processCombatIdleAnims(lektor<AnimationData*>* list, AnimationRequirement& requirements, float frameTIME, float weightLimit);// protected RVA = 0x51D300
    virtual void breathing(bool armsToo);// protected RVA = 0x5C4ED0 vtable offset = 0x100
    void _NV_breathing(bool armsToo);// protected RVA = 0x5C4ED0 vtable offset = 0x100
    AnimationData* defaultIdleAnimation; // 0x2E0 Member
    RagdollClass* ragdoll; // 0x2E8 Member
    RagdollAnimation* ragdollAnimation; // 0x2F0 Member
    RagdollPart::Enum ragdollParts; // 0x2F8 Member
    // no_addr class AnimationClass & operator=(const class AnimationClass & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class AnimationData : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void AnimationData(class AnimationData & _a1);// public missing arg names
    AnimationData(GameData* dat);// public RVA = 0x5B9B00
    AnimationData* _CONSTRUCTOR(GameData* dat);// public RVA = 0x5B9B00
    CharacterAnimCategory category; // 0x0 Member
    std::string dataName; // 0x8 Member
    std::string animName; // 0x30 Member
    GameData* _rawData; // 0x58 Member
    AnimationLayerEnum layername; // 0x60 Member
    WeatherAffecting weatherType; // 0x64 Member
    float idealMoveSpeed; // 0x68 Member
    float maxMoveSpeed; // 0x6C Member
    float minMoveSpeed; // 0x70 Member
    float playSpeed; // 0x74 Member
    YesNoMaybe holdingWeaponL; // 0x78 Member
    YesNoMaybe holdingWeaponR; // 0x7C Member
    YesNoMaybe isCombatMode; // 0x80 Member
    YesNoMaybe isStealthMode; // 0x84 Member
    bool relocates; // 0x88 Member
    bool restrictsMovementOrders; // 0x89 Member
    bool looped; // 0x8A Member
    bool wholeBodyAllLayer; // 0x8B Member
    bool synched; // 0x8C Member
    bool isAction; // 0x8D Member
    float synchOffset; // 0x90 Member
    bool normalise; // 0x94 Member
    float possibleEndingPosition; // 0x98 Member
    bool crouched; // 0x9C Member
    bool prone; // 0x9D Member
    bool usesRightArm; // 0x9E Member
    bool usesLeftArm; // 0x9F Member
    bool carryingLeft; // 0xA0 Member
    bool carryingRight; // 0xA1 Member
    bool carried; // 0xA2 Member
    std::string slave; // 0xA8 Member
    float legDamageRmin; // 0xD0 Member
    float legDamageRmax; // 0xD4 Member
    float legDamageLmin; // 0xD8 Member
    float legDamageLmax; // 0xDC Member
    float legDamageLIdeal; // 0xE0 Member
    float legDamageRIdeal; // 0xE4 Member
    float idleTimeMin; // 0xE8 Member
    float idleTimeMax; // 0xEC Member
    float idleChance; // 0xF0 Member
    const Ogre::vector<GameDataReference>::type* events; // 0xF8 Member
    unsigned int weaponTypeFlags; // 0x100 Member
    ogre_unordered_set<GameData*>::type stumbleBodyParts; // 0x108 Member
    CutOrigination stumbleOrigination; // 0x148 Member
    bool bigStumble; // 0x14C Member
    float stumbleRarityMult; // 0x150 Member
    bool checkWeaponArms(const AnimationRequirement& requirements);// public RVA = 0x51CAC0
    bool checkModes(const AnimationRequirement& requirements);// public RVA = 0x51CB50
    float scoreInjury(const AnimationRequirement& requirements);// public RVA = 0x51CA00
    float scoreSpeed(const AnimationRequirement& requirements, float speedAgeMultiplier);// public RVA = 0x51C980
    float scoreCarryMode(const AnimationRequirement& requirements);// public RVA = 0x51C290
    float scoreWeaponType(const AnimationRequirement& requirements);// public RVA = 0x51CA70
    // no_addr void ~AnimationData();// public
    // no_addr class AnimationData & operator=(const class AnimationData & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};