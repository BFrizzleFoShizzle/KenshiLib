#pragma once

#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include "Enums.h"
#include "util/lektor.h"
#include "util/hand.h"
#include "util/OgreUnordered.h"

class Character;
class Damages;
class RootObject;
class CombatTechniqueData;
class CharMovement;
class AI;
class AnimationClass;
class CharStats;
class MedicalSystem;
class CombatState;
class ParticleSystemHandler;

// TODO move?
class ParticlePool : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    struct ParticleData
    {
        ParticleData();// public RVA = 0x409300
        ParticleData* _CONSTRUCTOR();// public RVA = 0x409300
        ParticleSystemHandler* particle; // 0x0 Member
        GameData* effectData; // 0x8 Member
        Ogre::SceneNode* node; // 0x10 Member
    };
    ParticlePool(int limit, float ttl);// public RVA = 0x409650
    ParticlePool* _CONSTRUCTOR(int limit, float ttl);// public RVA = 0x409650
    ~ParticlePool();// public RVA = 0x40B810
    void _DESTRUCTOR();// public RVA = 0x40B810
    void init();// public RVA = 0x409320
    void destroy();// public RVA = 0x40B460
    int getSize() const;// public RVA = 0x4093A0
    bool addParticle(GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, Ogre::SceneNode* parentNode);// public RVA = 0x40B540
    void update();// public RVA = 0x40B680
    void shiftParticles(const Ogre::Vector3& shift);// public RVA = 0x4093B0
    unsigned int limit; // 0x0 Member
    unsigned int lastIndex; // 0x4 Member
    ParticlePool::ParticleData* particles; // 0x8 Member
    float maxTTL; // 0x10 Member
    // no_addr void __dflt_ctor_closure();// public
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class CombatClass : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    virtual ~CombatClass();// public RVA = 0x608F70 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x608F70 vtable offset = 0x0
    virtual bool isAI() const;// public RVA = 0x60BD70 vtable offset = 0x8
    bool _NV_isAI() const;// public RVA = 0x60BD70 vtable offset = 0x8
    virtual bool initCombatMode(const hand& subject, int end, bool focusedTarget);// public RVA = 0x665230 vtable offset = 0x10
    bool _NV_initCombatMode(const hand& subject, int end, bool focusedTarget);// public RVA = 0x665230 vtable offset = 0x10
    virtual void go(float _frameTime);// public RVA = 0x60C4D0 vtable offset = 0x18
    void _NV_go(float _frameTime);// public RVA = 0x60C4D0 vtable offset = 0x18
    swordStateEnum getCombatState() const;// public RVA = 0x333D30
    swordStateEnum getBlockStateEnum();// public RVA = 0x664BD0
    virtual void periodicUpdate(float time);// public RVA = 0x60CCF0 vtable offset = 0x20
    void _NV_periodicUpdate(float time);// public RVA = 0x60CCF0 vtable offset = 0x20
    virtual swordStateEnum whoAttacksYouOrMe(Character* _a1, float _a2, float& _a3) = 0;// public vtable offset = 0x28 missing arg names
    HitMaterialType _iHitYouAreYouHit(CutDirection dir, Damages& damage, Character* who);// public RVA = 0x665820
    void _getHit(CutDirection dir, const Damages& damage, RootObject* who, bool stumble);// public RVA = 0x664D10
    void _blockHit(CutDirection dir, const Damages& damage, RootObject* who);// public RVA = 0x664DC0
    float isAttacking(Character* who);// public RVA = 0x664CA0
    virtual void informOfFreeAttackSlot(Character* _a1);// public RVA = 0x60BD80 vtable offset = 0x30 missing arg names
    void _NV_informOfFreeAttackSlot(Character* _a1);// public RVA = 0x60BD80 vtable offset = 0x30 missing arg names
    bool isStationary();// public RVA = 0x664C80
    hand _getAttackTarget() const;// public RVA = 0x339E30
    bool isFightingAnAllyOfMine(Character* who);// public RVA = 0x996FE0
    CombatTechniqueData* getCurrentTechnique() const;// public RVA = 0x607A80
    int getCurrentTechniqueSection() const;// public RVA = 0x607A90
    // no_addr int getLastTechniqueSection();// public
    float getMeiMin() const;// public RVA = 0x2ADB80
    float areYouFightingAndInNeedOfHelp();// public RVA = 0x9989E0
    lektor<hand>& getAttackers();// public RVA = 0x5C70B0
    int getNumOpponents() const;// public RVA = 0x2B2B90
    float getTotalRelativeStrengthOfAttackers();// public RVA = 0x997310
    bool _isInCombatMode() const;// public RVA = 0x43FCD0
    // no_addr bool get_IsAttacking();// public
    void checkForBadHandles();// public RVA = 0x9970D0
    bool addAttackerH(Character* c);// public RVA = 0x6666A0
    bool isInAttackerListH(Character* c);// public RVA = 0x664FD0
    bool removeAttackerH(Character* c);// public RVA = 0x665050
    class AttackSlotManager : public Ogre::GeneralAllocatedObject
    {
    public:
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
        // no_addr void AttackSlotManager(const class CombatClass::AttackSlotManager & _a1);// public missing arg names
        AttackSlotManager(Character* _me, CombatClass* c);// public RVA = 0x60B220
        AttackSlotManager* _CONSTRUCTOR(Character* _me, CombatClass* c);// public RVA = 0x60B220
        bool hasFreeAttackSlot() const;// public RVA = 0x665AE0
        void freeSlotH(const hand& who);// public RVA = 0x665190
        void freeAllSlotsH();// public RVA = 0x665140
        bool addToSlotH(const hand& who);// public RVA = 0x665B90
        void periodicUpdate(float time);// public RVA = 0x667880
        void update();// public RVA = 0x664E90
        int getNumAttackSlots() const;// public RVA = 0x665A50
        // no_addr class hand getSlot(int _a1);// public missing arg names
        int getMaxPossibleAttackSlots() const;// private RVA = 0x664BE0
        struct SlotData : public Ogre::GeneralAllocatedObject
        {
            // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
            hand who; // 0x0 Member
            float time; // 0x20 Member
            // no_addr void SlotData(const struct CombatClass::AttackSlotManager::SlotData & _a1);// public missing arg names
            SlotData();// public RVA = 0x607AC0
            SlotData* _CONSTRUCTOR();// public RVA = 0x607AC0
            ~SlotData();// public RVA = 0x607B00
            void _DESTRUCTOR();// public RVA = 0x607B00
            // no_addr struct CombatClass::AttackSlotManager::SlotData & operator=(const struct CombatClass::AttackSlotManager::SlotData & _a1);// public missing arg names
            // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
        };
        Character* me; // 0x0 Member
        CombatClass* combatClass; // 0x8 Member
        CombatClass::AttackSlotManager::SlotData attackSlotH[0x5]; // 0x10 Member
        ~AttackSlotManager();// public RVA = 0x607B20
        void _DESTRUCTOR();// public RVA = 0x607B20
        // no_addr class CombatClass::AttackSlotManager & operator=(const class CombatClass::AttackSlotManager & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    CombatClass::AttackSlotManager attackSlots; // 0x8 Member
    void youDoKnowImAttackingYouRight(const hand& h);// public RVA = 0x60B570
    float getAttackAimAdjustmentThreshold(Character* target);// public RVA = 0x607D60
    int getNumWaitingAttackers() const;// public RVA = 0x2B2670
    bool readyToFinishCombatMode();// public RVA = 0x60C600
    float getTimeSinceLastCombatModeInHours();// public RVA = 0x665F80
    static void setup();// public RVA = 0x607BF0
    static void destroy();// public RVA = 0x607C10
    static GameData* getCombatEffect(Character* attacker, Character* victim, const Damages& damage, HitMaterialType hitType);// public RVA = 0x6089E0
    static void addEffect(GameData* effectData, const hand& character, const std::string& boneName, const Ogre::Vector3& position, const Ogre::Quaternion& rotation);// public RVA = 0x609280
    static void shiftEffects(const Ogre::Vector3& shift);// public RVA = 0x607C30
    static void updateEffects();// public RVA = 0x608720
    virtual hand hasFocusedTarget();// public RVA = 0x60BD90 vtable offset = 0x38
    hand _NV_hasFocusedTarget();// public RVA = 0x60BD90 vtable offset = 0x38
    // no_addr void CombatClass(const class CombatClass & _a1);// public missing arg names
    CombatClass(CharMovement* m, AI* a, AnimationClass* an, Character* character, CharStats* st, MedicalSystem* _med);// protected RVA = 0x60A260
    CombatClass* _CONSTRUCTOR(CharMovement* m, AI* a, AnimationClass* an, Character* character, CharStats* st, MedicalSystem* _med);// protected RVA = 0x60A260
    void changeState(swordStateEnum newState, float minTime);// protected RVA = 0x2B25F0
    virtual CombatState* getStateClass(swordStateEnum state);// protected RVA = 0x2B2710 vtable offset = 0x40
    CombatState* _NV_getStateClass(swordStateEnum state);// protected RVA = 0x2B2710 vtable offset = 0x40
    ogre_unordered_map<swordStateEnum, CombatState*>::type stateMap; // 0xE0 Member
    virtual void update(float frameTIME);// protected RVA = 0x60C6B0 vtable offset = 0x48
    void _NV_update(float frameTIME);// protected RVA = 0x60C6B0 vtable offset = 0x48
    float getMeiMax();// protected RVA = 0x60C5A0
    virtual bool startupState();// protected RVA = 0x60C7E0 vtable offset = 0x50
    bool _NV_startupState();// protected RVA = 0x60C7E0 vtable offset = 0x50
    void stumbleState();// protected RVA = 0x607E60
    bool wantsToBlock; // 0x120 Member
    bool isStumbleBlocking; // 0x121 Member
    float stumbleTimer; // 0x124 Member
    float whenCanStopStumble; // 0x128 Member
    float stumbleForce; // 0x12C Member
    bool combatModeActive; // 0x130 Member
    double lastCombatModeTimeStamp; // 0x138 Member
    float _isAttackingUpdate();// protected RVA = 0x665570
    float _isAttacking; // 0x140 Member
    bool inDeadTime; // 0x144 Member
    float deadTimer; // 0x148 Member
    float stateTimer; // 0x14C Member
    CombatTechniqueData* currentTechnique; // 0x150 Member
    bool currentTechniqueHasFinished; // 0x158 Member
    bool canBlock();// protected RVA = 0x607B70
    Ogre::Vector3 attackStartPos; // 0x15C Member
    float frameTIME; // 0x168 Member
    CharMovement* movement; // 0x170 Member
    AI* ai; // 0x178 Member
    AnimationClass* animation; // 0x180 Member
    Character* me; // 0x188 Member
    CharStats* stats; // 0x190 Member
    MedicalSystem* medical; // 0x198 Member
    float myRadiusX; // 0x1A0 Member
    virtual bool attackState();// protected RVA = 0x609E10 vtable offset = 0x58
    bool _NV_attackState();// protected RVA = 0x609E10 vtable offset = 0x58
    bool checkForNeedBlock(float thresholdMyAttack, float thresholdIncomingAttack);// protected RVA = 0x607C50
    void setCombatState(swordStateEnum state);// protected RVA = 0x60C550
    bool initialiseBlock(bool isStumbling);// protected RVA = 0x608B10
    virtual bool blockState(bool stumbleBlocking);// protected RVA = 0x6094F0 vtable offset = 0x60
    bool _NV_blockState(bool stumbleBlocking);// protected RVA = 0x6094F0 vtable offset = 0x60
    Character* blockingTarget; // 0x1A8 Member
    hand blockingTargetH; // 0x1B0 Member
    int lastIncomingAttackComboSection; // 0x1D0 Member
    void blockWaitingState();// protected RVA = 0x608A80
    void attackImpactCheck();// protected RVA = 0x609B70
    void calculateTargetsInAttackZone();// protected RVA = 0x608020
    bool calculatedTargetsInAttackZoneThisFrame; // 0x1D4 Member
    lektor<hand> targetsInAttackZone; // 0x1D8 Member
    bool isInAttackZone(Character* who);// protected RVA = 0x607CE0
    Character* getNearestEnemyInAttackZone();// protected RVA = 0x6090B0
    void assessIncomingAttacks(lektor<Character*>& out);// protected RVA = 0x6673C0
    void notifyBlockNeeded();// protected RVA = 0x607AA0
    swordStateEnum combatState; // 0x1F0 Member
    swordStateEnum nextMove; // 0x1F4 Member
    lektor<hand> attackersH; // 0x1F8 Member
    int numEnemiesWaitingForMe1; // 0x210 Member
    int numEnemiesWaitingForMe2; // 0x214 Member
    bool waitCountAlternator; // 0x218 Member
    lektor<Character*> threats; // 0x220 Member
    lektor<hand> threatsH; // 0x238 Member
    lektor<hand> notifiedThreats; // 0x250 Member
    void calculateCurrentTechniqueSection(int& section, float& progress01);// protected RVA = 0x665DA0
    int currentComboSection; // 0x268 Member
    int lastComboSection; // 0x26C Member
    int lastSoundIndex; // 0x270 Member
    float techniqueIntegrityCheckTimer; // 0x274 Member
    float MEI_MIN; // 0x278 Member
    float MEI_MAX; // 0x27C Member
    float weaponReach();// protected RVA = 0x607BA0
    Character* getBiggestThreat(const lektor<Character*>& list, float minThreshold);// protected RVA = 0x665680
    virtual bool gotMoreImportantThingsToDoThanFightingYou(Character* who);// protected RVA = 0x60BDC0 vtable offset = 0x68
    bool _NV_gotMoreImportantThingsToDoThanFightingYou(Character* who);// protected RVA = 0x60BDC0 vtable offset = 0x68
    float MINIMUM_DISTANCE_TO_OTHERS; // 0x280 Member
    float BLOCKING_MEI_DISTANCE_MIN; // 0x284 Member
    float BLOCKING_MEI_DISTANCE_MAX; // 0x288 Member
    void setAttackTarget(Character* c);// protected RVA = 0x664E00
    void setAttackTargetHandle(Character* c);// protected RVA = 0x664ED0
    Character* currentTarget; // 0x290 Member
    hand currentTargetHandle; // 0x298 Member
    void lookatTarget(Character* target);// protected RVA = 0x665C80
    virtual void packPtrsToHandles();// protected RVA = 0x60CB10 vtable offset = 0x70
    void _NV_packPtrsToHandles();// protected RVA = 0x60CB10 vtable offset = 0x70
    virtual void unpackHandlesToPtrs();// protected RVA = 0x60D4E0 vtable offset = 0x78
    void _NV_unpackHandlesToPtrs();// protected RVA = 0x60D4E0 vtable offset = 0x78
    struct EffectData : public Ogre::GeneralAllocatedObject
    {
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
        // no_addr void EffectData(const struct CombatClass::EffectData & _a1);// public missing arg names
        EffectData();// public RVA = 0x60B610
        EffectData* _CONSTRUCTOR();// public RVA = 0x60B610
        GameData* data; // 0x0 Member
        hand character; // 0x8 Member
        std::string boneName; // 0x28 Member
        Ogre::Vector3 pos; // 0x50 Member
        Ogre::Quaternion rot; // 0x5C Member
        ~EffectData();// public RVA = 0x60B6E0
        void _DESTRUCTOR();// public RVA = 0x60B6E0
        CombatClass::EffectData& operator=(const CombatClass::EffectData& __that);// public RVA = 0x60BB60
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    static ParticlePool effectsPool; // RVA = 0x212D198 Static Member
    static Ogre::FastArray<CombatClass::EffectData> effectsToAdd; // RVA = 0x212D1B0 Static Member
    // no_addr class CombatClass & operator=(const class CombatClass & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class CombatClassPlayer : public CombatClass
{
public:
    // CombatClass offset = 0x0, length = 0x2B8
    // no_addr void CombatClassPlayer(const class CombatClassPlayer & _a1);// public missing arg names
    // no_addr void CombatClassPlayer(class CharMovement * _a1, class AI * _a2, class AnimationClass * _a3, class Character * _a4, class CharStats * _a5, class MedicalSystem * _a6);// private missing arg names
    virtual ~CombatClassPlayer() = 0;// private vtable offset = 0x0
    //void _DESTRUCTOR() = 0;// private vtable offset = 0x0
    virtual swordStateEnum whoAttacksYouOrMe(Character* _a1, float _a2, float& _a3) override = 0;// public vtable offset = 0x0 missing arg names
    virtual void update() = 0;// public vtable offset = 0x80
    // no_addr class CombatClassPlayer & operator=(const class CombatClassPlayer & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// private vtable offset = 0x0 missing arg names
};

class ConstantTracerT;

class CombatClassAI : public CombatClass
{
public:
    // CombatClass offset = 0x0, length = 0x2B8
    // no_addr void CombatClassAI(const class CombatClassAI & _a1);// public missing arg names
    CombatClassAI(CharMovement* m, AI* a, AnimationClass* an, Character* c, CharStats* s, MedicalSystem* med);// private RVA = 0x60BE10
    CombatClassAI* _CONSTRUCTOR(CharMovement* m, AI* a, AnimationClass* an, Character* c, CharStats* s, MedicalSystem* med);// private RVA = 0x60BE10
    virtual ~CombatClassAI();// private RVA = 0x60BEA0 vtable offset = 0x0
    void _DESTRUCTOR();// private RVA = 0x60BEA0 vtable offset = 0x0
    virtual void update(float frameTIME) override;// public RVA = 0x60CF20 vtable offset = 0x0
    void _NV_update(float frameTIME);// public RVA = 0x60CF20 vtable offset = 0x0
    virtual void periodicUpdate(float time) override;// public RVA = 0x60CED0 vtable offset = 0x0
    void _NV_periodicUpdate(float time);// public RVA = 0x60CED0 vtable offset = 0x0
    virtual bool initCombatMode(const hand& subject, int end, bool focusedTargetMode) override;// public RVA = 0x667A60 vtable offset = 0x0
    bool _NV_initCombatMode(const hand& subject, int end, bool focusedTargetMode);// public RVA = 0x667A60 vtable offset = 0x0
    virtual bool isAI() const override;// public RVA = 0x60C3D0 vtable offset = 0x0
    bool _NV_isAI() const;// public RVA = 0x60C3D0 vtable offset = 0x0
    virtual hand hasFocusedTarget() override;// public RVA = 0x60C3E0 vtable offset = 0x0
    hand _NV_hasFocusedTarget();// public RVA = 0x60C3E0 vtable offset = 0x0
    ConstantTracerT* tracer; // 0x2B8 Member
    void tracerUpdate();// private RVA = 0x60C650
    bool targetPathBlocked() const;// private RVA = 0x2B2610
    bool targetTraceBlocked; // 0x2C0 Member
    hand focusedTarget; // 0x2C8 Member
    bool reFocusableMode; // 0x2E8 Member
    bool decisionState();// private RVA = 0x60C130
    virtual bool startupState() override;// private RVA = 0x60C930 vtable offset = 0x0
    bool _NV_startupState();// private RVA = 0x60C930 vtable offset = 0x0
    bool isInMeiDistance();// private RVA = 0x60BEF0
    void waitState();// private RVA = 0x60C0C0
    void circleState();// private RVA = 0x60C0F0
    void hesitateState();// private RVA = 0x60C120
    virtual bool attackState() override;// private RVA = 0x60A1F0 vtable offset = 0x0
    bool _NV_attackState();// private RVA = 0x60A1F0 vtable offset = 0x0
    virtual bool blockState(bool stumbleBlocking) override;// private RVA = 0x609A10 vtable offset = 0x0
    bool _NV_blockState(bool stumbleBlocking);// private RVA = 0x609A10 vtable offset = 0x0
    virtual void informOfFreeAttackSlot(Character* who) override;// private RVA = 0x664EA0 vtable offset = 0x0
    void _NV_informOfFreeAttackSlot(Character* who);// private RVA = 0x664EA0 vtable offset = 0x0
    virtual swordStateEnum whoAttacksYouOrMe(Character* who, float opponentAttackChance, float& returnValue) override;// private RVA = 0x6662B0 vtable offset = 0x0
    swordStateEnum _NV_whoAttacksYouOrMe(Character* who, float opponentAttackChance, float& returnValue);// private RVA = 0x6662B0 vtable offset = 0x0
    Character* chooseAttackTarget();// private RVA = 0x666760
    double targetLastChangedTimer; // 0x2F0 Member
    virtual bool gotMoreImportantThingsToDoThanFightingYou(Character* who) override;// private RVA = 0x607BC0 vtable offset = 0x0
    bool _NV_gotMoreImportantThingsToDoThanFightingYou(Character* who);// private RVA = 0x607BC0 vtable offset = 0x0
    // no_addr class CombatClassAI & operator=(const class CombatClassAI & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// private vtable offset = 0x0 missing arg names
};
