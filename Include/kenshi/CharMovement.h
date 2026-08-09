#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreSharedPtr.h>
#include "util/hand.h"
#include "util/lektor.h"
#include "util/OgreUnordered.h"
#include "MedianFilter.h"

class NxController;
class NxShape;
struct NxControllerShapeHit;
struct NxControllersHit;
class RoadFollower;
class PatrolInfo;
class AnimationClass;


enum UpdatePriority
{
    LOW_PRIORITY,
    MED_PRIORITY,
    HIGH_PRIORITY
};

enum NxControllerAction
{
    NX_ACTION_NONE,
    NX_ACTION_PUSH
};

// TODO move
class physHit
{
public:
    float _defaultAltitudeFallback; // 0x0 Member
    bool _traceWasAborted; // 0x4 Member
    bool _doNotAbort; // 0x5 Member
    bool _needsGroup; // 0x6 Member
    physHit(const physHit& __that);// public RVA = 0x441090
    physHit* _CONSTRUCTOR(const physHit& __that);// public RVA = 0x441090
    physHit(int _a1);// public RVA = 0x43F9D0 missing arg names
    physHit* _CONSTRUCTOR(int _a1);// public RVA = 0x43F9D0 missing arg names
    physHit(bool doNotAbort, bool needsGroup, float defaultAltitudeFallback);// public RVA = 0x168E20
    physHit* _CONSTRUCTOR(bool doNotAbort, bool needsGroup, float defaultAltitudeFallback);// public RVA = 0x168E20
    physHit& operator=(const physHit& __that);// public RVA = 0x4CB000
    // no_addr const class physHit & operator=(const int & _a1);// public missing arg names
    bool traceWasAborted() const;// public RVA = 0x337600
    operator bool() const;// public RVA = 0x43FA40
    void reset();// public RVA = 0x4CAF40
    RootObject* hitObjectUnsafePtr();// public RVA = 0x445010
    Building* getBuilding();// public RVA = 0x79AE60
    bool hit; // 0x7 Member
    Ogre::Vector3 position; // 0x8 Member
    Ogre::Vector3 normal; // 0x14 Member
    float distance; // 0x20 Member
    NxShape* shape; // 0x28 Member
    hand hitObject; // 0x30 Member
    unsigned short _group; // 0x50 Member
    unsigned short group() const;// public RVA = 0x3D1D60
    RootObject* _hitObjectUnsafePtr; // 0x58 Member
};

class SpeedGroup
{
public:
    // no_addr void SpeedGroup(const class SpeedGroup & _a1);// public missing arg names
    SpeedGroup();// public RVA = 0x80EC50
    SpeedGroup* _CONSTRUCTOR();// public RVA = 0x80EC50
    void insert(const hand& h);// public RVA = 0x810410
    void erase(const hand& h);// public RVA = 0x664530
    float getSpeed(Character* who);// public RVA = 0x7F44E0
    ogre_unordered_set<hand>::type members; // 0x0 Member
    Ogre::Vector3 position; // 0x40 Member
    Ogre::Vector3 direction; // 0x4C Member
    float speed; // 0x58 Member
    unsigned long last; // 0x5C Member
    ~SpeedGroup();// public RVA = 0x80F6F0
    void _DESTRUCTOR();// public RVA = 0x80F6F0
    // no_addr class SpeedGroup & operator=(const class SpeedGroup & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class NxUserControllerHitReport
{
public:
    // VTable         : (none)
    virtual NxControllerAction onShapeHit(const NxControllerShapeHit& _a1) = 0;// public vtable offset = 0x0 missing arg names
    virtual NxControllerAction onControllerHit(const NxControllersHit& _a1) = 0;// public vtable offset = 0x8 missing arg names
    virtual ~NxUserControllerHitReport();// protected RVA = 0x663FD0 vtable offset = 0x10
    void _DESTRUCTOR();// protected RVA = 0x663FD0 vtable offset = 0x10
    // no_addr void NxUserControllerHitReport(const class NxUserControllerHitReport & _a1);// public missing arg names
    NxUserControllerHitReport();// public RVA = 0x663E10
    NxUserControllerHitReport* _CONSTRUCTOR();// public RVA = 0x663E10
    // no_addr class NxUserControllerHitReport & operator=(const class NxUserControllerHitReport & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x10 missing arg names
};

class AbstractMovementBase : public NxUserControllerHitReport, public Ogre::GeneralAllocatedObject
{
public:
    // NxUserControllerHitReport offset = 0x0, length = 0x8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // no_addr void AbstractMovementBase(const class AbstractMovementBase & _a1);// public missing arg names
    AbstractMovementBase();// public RVA = 0x664740
    AbstractMovementBase* _CONSTRUCTOR();// public RVA = 0x664740
    virtual ~AbstractMovementBase();// public RVA = 0x662330 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x662330 vtable offset = 0x0
    void create(Ogre::Vector3 _pos);// public RVA = 0x7EA9E0
    virtual hand getHandle();// public RVA = 0x664A40 vtable offset = 0x18
    hand _NV_getHandle();// public RVA = 0x664A40 vtable offset = 0x18
    virtual void _setPositionAndTeleport(Ogre::Vector3 p, int floor);// public RVA = 0x6648F0 vtable offset = 0x20
    void _NV__setPositionAndTeleport(Ogre::Vector3 p, int floor);// public RVA = 0x6648F0 vtable offset = 0x20
    virtual void _setPositionSimple(Ogre::Vector3 p);// public RVA = 0x664910 vtable offset = 0x28
    void _NV__setPositionSimple(Ogre::Vector3 p);// public RVA = 0x664910 vtable offset = 0x28
    virtual void faceDirection(const Ogre::Vector3& dir);// public RVA = 0x664930 vtable offset = 0x30
    void _NV_faceDirection(const Ogre::Vector3& dir);// public RVA = 0x664930 vtable offset = 0x30
    virtual void lookatPosition(const Ogre::Vector3& pos);// public RVA = 0x664940 vtable offset = 0x38
    void _NV_lookatPosition(const Ogre::Vector3& pos);// public RVA = 0x664940 vtable offset = 0x38
    virtual const Ogre::Vector3& getPosition() const;// public RVA = 0x664950 vtable offset = 0x40
    const Ogre::Vector3& _NV_getPosition() const;// public RVA = 0x664950 vtable offset = 0x40
    const Ogre::Vector3& getFacingDirection() const;// public RVA = 0x2ADB90
    Ogre::Vector3 getDestination() const;// public RVA = 0x65E050
    bool isProbablyStuck() const;// public RVA = 0x60C4B0
    virtual bool pathOk() const;// public RVA = 0x664960 vtable offset = 0x48
    bool _NV_pathOk() const;// public RVA = 0x664960 vtable offset = 0x48
    virtual bool pathFailed() const;// public RVA = 0x664970 vtable offset = 0x50
    bool _NV_pathFailed() const;// public RVA = 0x664970 vtable offset = 0x50
    virtual void update(float _TIME);// public RVA = 0x65E800 vtable offset = 0x58
    void _NV_update(float _TIME);// public RVA = 0x65E800 vtable offset = 0x58
    virtual bool isDestinationReached() const;// public RVA = 0x664980 vtable offset = 0x60
    bool _NV_isDestinationReached() const;// public RVA = 0x664980 vtable offset = 0x60
    virtual int amInsideTownWalls();// public RVA = 0x664990 vtable offset = 0x68
    int _NV_amInsideTownWalls();// public RVA = 0x664990 vtable offset = 0x68
    virtual void manualMovement(const Ogre::Vector3& desiredMotion);// public RVA = 0x65D680 vtable offset = 0x70
    void _NV_manualMovement(const Ogre::Vector3& desiredMotion);// public RVA = 0x65D680 vtable offset = 0x70
    virtual void setDestination(const Ogre::Vector3& dest, UpdatePriority pri, bool _a3);// public RVA = 0x65F470 vtable offset = 0x90
    void _NV_setDestination(const Ogre::Vector3& dest, UpdatePriority pri, bool _a3);// public RVA = 0x65F470 vtable offset = 0x90
    virtual void setDestination(RootObjectBase* target, UpdatePriority pri);// public RVA = 0x65DBF0 vtable offset = 0x88
    void _NV_setDestination(RootObjectBase* target, UpdatePriority pri);// public RVA = 0x65DBF0 vtable offset = 0x88
    virtual void setDestination(Character* who, UpdatePriority pri);// public RVA = 0x6649A0 vtable offset = 0x80
    void _NV_setDestination(Character* who, UpdatePriority pri);// public RVA = 0x6649A0 vtable offset = 0x80
    virtual void setDestination(Building* who, UpdatePriority pri);// public RVA = 0x6649B0 vtable offset = 0x78
    void _NV_setDestination(Building* who, UpdatePriority pri);// public RVA = 0x6649B0 vtable offset = 0x78
    virtual void halt();// public RVA = 0x65DB90 vtable offset = 0x98
    void _NV_halt();// public RVA = 0x65DB90 vtable offset = 0x98
    bool setRoadDestination(const Ogre::Vector3& dest);// public RVA = 0x65F1C0
    void setRoadPreference(float w);// public RVA = 0x663DB0
    RoadFollower* extractRoadFollower();// public RVA = 0x65DC50
    void setCurrentRoadFollower(const Ogre::Vector3& d, RoadFollower* r);// public RVA = 0x65F780
    virtual void setPatrolInput(PatrolInfo& patrol);// public RVA = 0x6649C0 vtable offset = 0xA0
    void _NV_setPatrolInput(PatrolInfo& patrol);// public RVA = 0x6649C0 vtable offset = 0xA0
    virtual void setDesiredSpeed(MoveSpeed speed);// public RVA = 0x6649D0 vtable offset = 0xA8
    void _NV_setDesiredSpeed(MoveSpeed speed);// public RVA = 0x6649D0 vtable offset = 0xA8
    void setDesiredSpeed(float speed);// public RVA = 0x332E40
    void setDesiredSpeedOrders(MoveSpeed speed);// public RVA = 0x331C60
    void setDesiredSpeedOrders(float speed);// public RVA = 0x335B00
    void setStandardWalkSpeed(float s);// public RVA = 0x620850
    float getStandardWalkSpeed();// public RVA = 0x332DF0
    void restoreDesiredSpeed();// public RVA = 0x333040
    void setMaxSpeed(float ms);// public RVA = 0x663E00
    float getMaxSpeed() const;// public RVA = 0x8055E0
    bool isCurrentlyMoving() const;// public RVA = 0x333830
    float getCurrentSpeed() const;// public RVA = 0x2ADBA0
    Ogre::Vector3 getCurrentMotion() const;// public RVA = 0x5C70C0
    float getCurrentSpeedRelativeToMax01() const;// public RVA = 0x5C70F0
    bool officiallyStopped; // 0x8 Member
    MoveSpeed getSpeedOrders() const;// public RVA = 0x331C70
    Ogre::SharedPtr<SpeedGroup> speedGroup; // 0x10 Member
    void leaveSpeedGroup();// public RVA = 0x662410
    // no_addr void speedLimit(class Ogre::Vector3 & _a1, float _a2, float _a3);// protected missing arg names
    MoveSpeed speedOrders; // 0x20 Member
    bool currentlyMoving; // 0x24 Member
    MedianFilter2DVector positionSmoother; // 0x28 Member
    Ogre::Vector3 currentMotion; // 0xA8 Member
    float maxSpeed; // 0xB4 Member
    float currentSpeed; // 0xB8 Member
    float desiredSpeed; // 0xBC Member
    float walkSpeed; // 0xC0 Member
    Ogre::Vector3 pos; // 0xC4 Member
    Ogre::Vector3 direction; // 0xD0 Member
    Ogre::Vector3 destination; // 0xDC Member
    Ogre::Vector3 pathDestination; // 0xE8 Member
    RoadFollower* roadFollower; // 0xF8 Member
    float roadWeight; // 0x100 Member
    virtual NxControllerAction onShapeHit(const NxControllerShapeHit& hit) override;// protected RVA = 0x664A20 vtable offset = 0x0
    NxControllerAction _NV_onShapeHit(const NxControllerShapeHit& hit);// protected RVA = 0x664A20 vtable offset = 0x0
    virtual NxControllerAction onControllerHit(const NxControllersHit& hit) override;// protected RVA = 0x664A30 vtable offset = 0x0
    NxControllerAction _NV_onControllerHit(const NxControllersHit& hit);// protected RVA = 0x664A30 vtable offset = 0x0
    // no_addr class AbstractMovementBase & operator=(const class AbstractMovementBase & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};

class SensoryData;
class CombatMovementController;
class Character;

class FlockingTools
{
public:
    // no_addr void FlockingTools(const class FlockingTools & _a1);// public missing arg names
    FlockingTools();// public RVA = 0x663CB0
    FlockingTools* _CONSTRUCTOR();// public RVA = 0x663CB0
    void create(Character* chme, CombatMovementController* c);// public RVA = 0x663D00
    float getDistanceToClosestCharacter(bool enemies, bool allies, const hand& skip) const;// public RVA = 0x2E9170
    void getOutOfTheWay(const hand& caller);// public RVA = 0x663D10
    void setCurrentPosition(const Ogre::Vector3& _pos);// public RVA = 0x663D40
    static float getRepulsionMagnitude(const Ogre::Vector3& mypos, const Ogre::Vector3& repulsionPoint, float MAX_DISTANCE, float distance);// public RVA = 0x2E8F10
    static Ogre::Vector3 getRepulsionVector(const Ogre::Vector3& mypos, const Ogre::Vector3& repulsionPoint, float MAX_DISTANCE, float distance);// public RVA = 0x2E8F70
    static void clampRepulsionVectorTo90Degrees(Ogre::Vector3& repulsionVector, const Ogre::Vector3& desiredDirection, bool alwaysStrafe);// public RVA = 0x2E9080
    Ogre::Vector3 calculateCurrentRepulsionVector(float MAX_DISTANCE, Ogre::Vector3 desiredDirection, Character* skip, bool includeEnemies, bool includeFriends, bool strafeOnly);// public RVA = 0x2E9290
    SensoryData* getSensoryData() const;// public RVA = 0x2E8EF0
    hand getOutOfTheWayOfCharacter; // 0x0 Member
    Ogre::Vector3 currentPosition; // 0x20 Member
    Character* me; // 0x30 Member
    CombatMovementController* combatMover; // 0x38 Member
    // no_addr class FlockingTools & operator=(const class FlockingTools & _a1);// public missing arg names
};

class CharStats;
class DatapanelGUI;

class MotionFilter
{
public:
    // no_addr void MotionFilter(const class MotionFilter & _a1);// public missing arg names
    MotionFilter(int length, float weight_modifier, float fill);// public RVA = 0x63E6B0
    MotionFilter* _CONSTRUCTOR(int length, float weight_modifier, float fill);// public RVA = 0x63E6B0
    // no_addr void MotionFilter();// public
    bool SetHistoryBufferLength(int length, float fill);// public RVA = 0x63DC50
    void Apply(float& x);// public RVA = 0x2B2190
    // no_addr void ApplyAbs(float & _a1);// public missing arg names
    // no_addr float GetWeightModifier();// public
    // no_addr void SetWeightModifier(float _a1);// public missing arg names
    // no_addr int GetHistoryBufferLength();// public
    float mWeightModifier; // 0x0 Member
    std::deque<float, std::allocator<float> > mHistoryBufferX; // 0x8 Member
    ~MotionFilter();// public RVA = 0x5C20B0
    void _DESTRUCTOR();// public RVA = 0x5C20B0
    // no_addr class MotionFilter & operator=(const class MotionFilter & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class CharMovement;

class CombatMovementController
{
public:
    // no_addr void CombatMovementController(const class CombatMovementController & _a1);// public missing arg names
    CombatMovementController();// private RVA = 0x621AD0
    CombatMovementController* _CONSTRUCTOR();// private RVA = 0x621AD0
    ogre_unordered_map<hand, float>::type characterCollisions; // 0x0 Member
    void collisionUpdate(float time);// private RVA = 0x2AE860
    CharMovement* movement; // 0x40 Member
    bool chaseMode; // 0x48 Member
    bool chasingModeCheck(Character* whoTarget);// private RVA = 0x2ADC30
    float chaseStateTimer; // 0x4C Member
    void create(FlockingTools* flock, CharMovement* move, CharStats* med, bool strafe);// public RVA = 0x663D50
    bool areTherePeopleInMyWay();// public RVA = 0x2AE640
    void addACharacterObstruction(Character* c);// public RVA = 0x2AE760
    void setupCombatMovementVariables(Character* me);// public RVA = 0x2AE220
    void combatMovementUpdate(float frametime, const Ogre::Vector3& currentPos, const Ogre::Vector3& currentDirIn, bool isCurrentlyMoving, Ogre::Vector3& repulsionVector, Ogre::Vector3& facingDirOut, bool defensive, swordStateEnum combatState, float raceSpeedMult);// public RVA = 0x2AED30
    void combatMovementUpdate_crippleMode(float frametime, const Ogre::Vector3& currentPos, const Ogre::Vector3& currentDirIn, bool isCurrentlyMoving, Ogre::Vector3& repulsionVector, Ogre::Vector3& facingDirOut, bool defensive, swordStateEnum combatState, float raceSpeedMult);// public RVA = 0x2AEB30
    Ogre::Vector3 getUrgentVelocities(const Ogre::Vector3& pos, const Ogre::Vector3& facingDir);// public RVA = 0x2AF890
    void checkWeDontCollideWithCharacters(const Ogre::Vector3& pos, Ogre::Vector3& newpos);// public RVA = 0x2AF8C0
    bool checkCharacterCollision(const Ogre::Vector3& pos, const Ogre::Vector3& movement) const;// public RVA = 0x2AF9E0
    void setForcedWP(const Ogre::Vector3& v);// public RVA = 0x663D90
    bool hasForcedWP; // 0x50 Member
    Ogre::Vector3 forcedWP; // 0x54 Member
    void getGUIData(DatapanelGUI* panel, int category);// public RVA = 0x798270
    MotionFilter flockFilterX; // 0x60 Member
    MotionFilter flockFilterZ; // 0x98 Member
    void combatMovementOffensive(const hand& target, float minDistance, float maxDistance, float circle, bool power, float _speedLimit);// private RVA = 0x2ADE70
    void disable();// private RVA = 0x664100
    FlockingTools* flockingControl; // 0xD0 Member
    CharStats* stats; // 0xD8 Member
    float radius; // 0xE0 Member
    bool jogMode; // 0xE4 Member
    float TOTALREPULSION_DAMPING; // 0xE8 Member
    float STRAFE_STATE_DAMPING; // 0xEC Member
    float STRAFE_THRESHOLD; // 0xF0 Member
    float FORWARD_THRESHOLD; // 0xF4 Member
    float MIN_RANGE_FW; // 0xF8 Member
    float ENEMY_DIST; // 0xFC Member
    float ALLY_DIST; // 0x100 Member
    float STOP_THRESHOLD; // 0x104 Member
    float START_THRESHOLD; // 0x108 Member
    float ACCEL_RATE_COMBATMODE; // 0x10C Member
    float meiMin; // 0x110 Member
    void combatMovementAnimationUpdate(const Ogre::Vector3& motion, const Ogre::Vector3& facingDirection, AnimationClass* animation, bool crippled);// private RVA = 0x2ADD00
    float circlingSpeed; // 0x114 Member
    float combatMinDistance; // 0x118 Member
    float combatMaxDistance; // 0x11C Member
    float strafeStateTimer; // 0x120 Member
    bool strafing; // 0x124 Member
    bool powerThrough; // 0x125 Member
    bool canStrafe; // 0x126 Member
    float speedLimit; // 0x128 Member
    float currentAccelSpeed; // 0x12C Member
    hand lookAtCharacter; // 0x130 Member
    hand combatTarget; // 0x150 Member
    ~CombatMovementController();// public RVA = 0x664540
    void _DESTRUCTOR();// public RVA = 0x664540
    // no_addr class CombatMovementController & operator=(const class CombatMovementController & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class FormationMover
{
public:
    Character* me; // 0x0 Member
    // no_addr void FormationMover(const class FormationMover & _a1);// public missing arg names
    FormationMover();// public RVA = 0x663E30
    FormationMover* _CONSTRUCTOR();// public RVA = 0x663E30
    ~FormationMover();// public RVA = 0x663EA0
    void _DESTRUCTOR();// public RVA = 0x663EA0
    // no_addr void setup(class Character * _a1);// public missing arg names
    void update();// public RVA = 0x2AFB60
    Ogre::Vector3 destination; // 0x8 Member
    Ogre::Vector3 direction; // 0x14 Member
    void getSpeeds(float& speed, float& strafeSpeed, const Ogre::Vector3& motion, float frameTime);// public RVA = 0x2AE060
    void setFormationMode(const hand& target);// public RVA = 0x2AFE20
    void stopFormationMode();// public RVA = 0x2AFCF0
    hand movementTarget; // 0x20 Member
    int currentFormationID; // 0x40 Member
    // no_addr class FormationMover & operator=(const class FormationMover & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class HavokCharacter;
class ConstantTracerT;

enum MovementMode
{
    MOVE_NORMAL,
    MOVE_COMBAT,
    MOVE_DIRECTION
};

class PhysicsHullT;

class Formation
{
public:
    // VTable         : (none)
    // no_addr void Formation(const class Formation & _a1);// public missing arg names
    Formation(RootObject* ownedby);// public RVA = 0x664250
    Formation* _CONSTRUCTOR(RootObject* ownedby);// public RVA = 0x664250
    // no_addr void cleanup();// public
    virtual int addToFormation(const hand& h);// public RVA = 0x2AE570 vtable offset = 0x0
    int _NV_addToFormation(const hand& h);// public RVA = 0x2AE570 vtable offset = 0x0
    virtual void removeFromFormation(const hand& h);// public RVA = 0x2AE4E0 vtable offset = 0x8
    void _NV_removeFromFormation(const hand& h);// public RVA = 0x2AE4E0 vtable offset = 0x8
    virtual Ogre::Vector3 getFormationPos(int id, float tightness);// public RVA = 0x2AE130 vtable offset = 0x10
    Ogre::Vector3 _NV_getFormationPos(int id, float tightness);// public RVA = 0x2AE130 vtable offset = 0x10
    RootObject* character; // 0x8 Member
    lektor<hand> followers; // 0x10 Member
    ~Formation();// public RVA = 0x664130
    void _DESTRUCTOR();// public RVA = 0x664130
    // no_addr class Formation & operator=(const class Formation & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class CharMovement : public AbstractMovementBase
{
public:
    // AbstractMovementBase offset = 0x0, length = 0x108
    Ogre::Vector3 flockingVector; // 0x108 Member
    // no_addr void CharMovement(const class CharMovement & _a1);// public missing arg names
    CharMovement();// public RVA = 0x662490
    CharMovement* _CONSTRUCTOR();// public RVA = 0x662490
    virtual ~CharMovement();// public RVA = 0x662620 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x662620 vtable offset = 0x0
    virtual void create(Character* c, AnimationClass* an, const Ogre::Vector3& _pos);// public RVA = 0x662160 vtable offset = 0xB0
    void _NV_create(Character* c, AnimationClass* an, const Ogre::Vector3& _pos);// public RVA = 0x662160 vtable offset = 0xB0
    virtual void _setPositionAndTeleport(const Ogre::Vector3& p, int floor);// public RVA = 0x65E1C0 vtable offset = 0xB8
    void _NV__setPositionAndTeleport(const Ogre::Vector3& p, int floor);// public RVA = 0x65E1C0 vtable offset = 0xB8
    virtual void _setPositionDirectionAndTeleport(const Ogre::Vector3& position, const Ogre::Quaternion& orientation);// public RVA = 0x65E260 vtable offset = 0xC0
    void _NV__setPositionDirectionAndTeleport(const Ogre::Vector3& position, const Ogre::Quaternion& orientation);// public RVA = 0x65E260 vtable offset = 0xC0
    virtual void _setPositionSimple(const Ogre::Vector3& p);// public RVA = 0x65E0F0 vtable offset = 0xC8
    void _NV__setPositionSimple(const Ogre::Vector3& p);// public RVA = 0x65E0F0 vtable offset = 0xC8
    bool isRunning();// public RVA = 0x65E6C0
    bool isRunningAway(const Ogre::Vector3& from);// public RVA = 0x65E6F0
    CombatMovementController combatMover; // 0x118 Member
    FormationMover combatMover2; // 0x288 Member
    FlockingTools flockingTools; // 0x2D0 Member
    Formation* formation; // 0x310 Member
    Formation* enemyFormation; // 0x318 Member
    HavokCharacter* havokCharacter; // 0x320 Member
    ConstantTracerT* tracer; // 0x328 Member
    void formationUpdateCallback(const Ogre::Vector3& _pos, const hand& target, const Ogre::Vector3& heading, Formation* caller);// public RVA = 0x2AE050
    void trackAnimationMovement(bool on);// public RVA = 0x65DAC0
    virtual hand getHandle() override;// public RVA = 0x65F170 vtable offset = 0x0
    hand _NV_getHandle();// public RVA = 0x65F170 vtable offset = 0x0
    virtual void handleChanged();// public RVA = 0x6617B0 vtable offset = 0xD0
    void _NV_handleChanged();// public RVA = 0x6617B0 vtable offset = 0xD0
    float getRadius();// public RVA = 0x65D4B0
    virtual void update(float _TIME) override;// public RVA = 0x65F820 vtable offset = 0x0
    void _NV_update(float _TIME);// public RVA = 0x65F820 vtable offset = 0x0
    void pausedUpdate();// public RVA = 0x65D930
    void twoFrameUpdate(float _TIME);// public RVA = 0x65D650
    void postAnimationUpdate();// public RVA = 0x65DAB0
    void periodicUpdate(float time);// public RVA = 0x660640
    Ogre::Vector3 predictNextPosition(bool accurate);// public RVA = 0x65D960
    float getMaximumPossibleMovement() const;// public RVA = 0x65DA60
    virtual void faceDirection(const Ogre::Vector3& dir) override;// public RVA = 0x664AD0 vtable offset = 0x0
    void _NV_faceDirection(const Ogre::Vector3& dir);// public RVA = 0x664AD0 vtable offset = 0x0
    virtual void lookatPosition(const Ogre::Vector3& pos) override;// public RVA = 0x65D510 vtable offset = 0x0
    void _NV_lookatPosition(const Ogre::Vector3& pos);// public RVA = 0x65D510 vtable offset = 0x0
    virtual bool pathOk() const override;// public RVA = 0x65E080 vtable offset = 0x0
    bool _NV_pathOk() const;// public RVA = 0x65E080 vtable offset = 0x0
    virtual bool pathFailed() const override;// public RVA = 0x65E0B0 vtable offset = 0x0
    bool _NV_pathFailed() const;// public RVA = 0x65E0B0 vtable offset = 0x0
    virtual bool isDestinationReached() const override;// public RVA = 0x65E630 vtable offset = 0x0
    bool _NV_isDestinationReached() const;// public RVA = 0x65E630 vtable offset = 0x0
    virtual bool isIdle() const;// public RVA = 0x65E670 vtable offset = 0xD8
    bool _NV_isIdle() const;// public RVA = 0x65E670 vtable offset = 0xD8
    const hand& isStandingOnSomething();// public RVA = 0x64620
    virtual void setDestination(const Ogre::Vector3& dest, UpdatePriority priority, bool notVertical) override;// public RVA = 0x660AF0 vtable offset = 0x0
    void _NV_setDestination(const Ogre::Vector3& dest, UpdatePriority priority, bool notVertical);// public RVA = 0x660AF0 vtable offset = 0x0
    virtual void setDestination(RootObjectBase* target, UpdatePriority pri) override;// public RVA = 0x65DCA0 vtable offset = 0x0
    void _NV_setDestination(RootObjectBase* target, UpdatePriority pri);// public RVA = 0x65DCA0 vtable offset = 0x0
    virtual void setDestination(Character* who, UpdatePriority pri) override;// public RVA = 0x65DD00 vtable offset = 0x0
    void _NV_setDestination(Character* who, UpdatePriority pri);// public RVA = 0x65DD00 vtable offset = 0x0
    virtual void setDestination(Building* who, UpdatePriority pri) override;// public RVA = 0x65DEB0 vtable offset = 0x0
    void _NV_setDestination(Building* who, UpdatePriority pri);// public RVA = 0x65DEB0 vtable offset = 0x0
    virtual bool playerMoveOrderWhileInCombatMode(const Ogre::Vector3& pos);// public RVA = 0x65DF10 vtable offset = 0xE0
    bool _NV_playerMoveOrderWhileInCombatMode(const Ogre::Vector3& pos);// public RVA = 0x65DF10 vtable offset = 0xE0
    virtual void halt() override;// public RVA = 0x65F4F0 vtable offset = 0x0
    void _NV_halt();// public RVA = 0x65F4F0 vtable offset = 0x0
    void invalidatePath();// public RVA = 0x65E010
    virtual void setPatrolInput(PatrolInfo& patrol) override;// public RVA = 0x65E320 vtable offset = 0x0
    void _NV_setPatrolInput(PatrolInfo& patrol);// public RVA = 0x65E320 vtable offset = 0x0
    void movedBy(const Ogre::Vector3& pos);// public RVA = 0x65DA80
    void combatMovementOffensive(const hand& target, float minDistance, float maxDistance, float circle, bool power, float speedLimit);// public RVA = 0x2AE450
    bool isCombatMovementBlockedByCharacters();// public RVA = 0x2AE740
    void setLookatTarget(const hand& lookatCharacter);// public RVA = 0x2ADE30
    void destroy();// public RVA = 0x65F6C0
    void restore();// public RVA = 0x661810
    bool dontEverRecreateMe; // 0x330 Member
    Ogre::Aabb getAABB() const;// public RVA = 0x661570
    void refreshClickHull();// public RVA = 0x6612F0
    void teleportCollisionHull(const Ogre::Vector3& _pos);// public RVA = 0x65D4E0
    int getCurrentFloor() const;// public RVA = 0x660960
    bool isIndoorsHideMeCheck() const;// public RVA = 0x65E7B0
    bool isIndoors() const;// public RVA = 0x65D570
    virtual void manualMovement(const Ogre::Vector3& v) override;// public RVA = 0x65D740 vtable offset = 0x0
    void _NV_manualMovement(const Ogre::Vector3& v);// public RVA = 0x65D740 vtable offset = 0x0
    bool isInsideBuildingLoadedInterior() const;// public RVA = 0x65D5A0
    bool hasClickHull() const;// public RVA = 0x4CB140
    bool isTrackingAnimationMode() const;// public RVA = 0x595E00
    bool isWaypointMoveMode() const;// public RVA = 0x2ADBB0
    void setMovementMode(MovementMode mode);// public RVA = 0x65E990
    void setDirectMovement(const Ogre::Vector3& d, float limit);// public RVA = 0x332E50
    physHit getLastGroundTraceResultMT();// public RVA = 0x65F5E0
    Character* getCharacter();// public RVA = 0x2ADBC0
    virtual NxControllerAction onShapeHit(const NxControllerShapeHit& hit) override;// private RVA = 0x65DAF0 vtable offset = 0x0
    NxControllerAction _NV_onShapeHit(const NxControllerShapeHit& hit);// private RVA = 0x65DAF0 vtable offset = 0x0
    virtual NxControllerAction onControllerHit(const NxControllersHit& hit) override;// private RVA = 0x65DB00 vtable offset = 0x0
    NxControllerAction _NV_onControllerHit(const NxControllersHit& hit);// private RVA = 0x65DB00 vtable offset = 0x0
    bool toGround();// private RVA = 0x65E9E0
    void updateGroundMaterial();// private RVA = 0x65D800
    int floorGroup; // 0x334 Member
    hand building; // 0x338 Member
    bool initCheck; // 0x358 Member
    float _combatMoveSpeedMult; // 0x35C Member
    float getCombatMoveSpeedMult();// private RVA = 0x65D420
    bool destinationLoaded; // 0x360 Member
    float footprintRadius; // 0x364 Member
    int edgeTarget; // 0x368 Member
    float _lastOffMeshCheck; // 0x36C Member
    bool movingToEdge; // 0x370 Member
    float lastStepTime; // 0x374 Member
    MovementMode movementMode; // 0x378 Member
    bool animationOverride; // 0x37C Member
    Ogre::Vector3 trackingAnimRelocationVector; // 0x380 Member
    Ogre::Vector3 desiredMotion; // 0x38C Member
    float moveLimit; // 0x398 Member
    AnimationClass* animation; // 0x3A0 Member
    Character* character; // 0x3A8 Member
    PhysicsHullT* clickHull; // 0x3B0 Member
    // no_addr class CharMovement & operator=(const class CharMovement & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};