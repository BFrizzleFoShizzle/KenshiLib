#pragma once

#include "AI.h"
#include <kenshi/util/hand.h>


class Character;

// TODO move?
enum BlackboardSignalFunctions
{
    SIGNAL_NONE,
    SIG_RETREAT_CANNIBAL_RAID,
    SIG_AT_SAFE_TOWN,
    SIG_AT_HOME_TOWN,
    SIG_CANNIBAL_START_PATROL,
    SIG_SQUAD_NOT_INTACT,
    SIG_START_PATROL,
    SIG_DIPLOMAT_MISSION,
    SIG_DEFEAT_SQUAD,
    SIG_HOME_OWNER_KEEP_LOCKED,
    SIG_GATHER_UP_ALL_LOCAL_PRISONERS,
    SIG_SLAVER_SHIP_TO_WORKCAMPS,
    SIG_BODYGUARD,
    SIG_BECOME_EX_SLAVE,
    SIG_OUT_OF_DANGER,
    SIG_DEFEND_PLAYER_TOWN_TIMED,
    SIG_WANDERING_TOWN_TO_TOWN,
    SIG_HANG_OUT_AT_BAR,
    SIG_RAIDING_WEAK_VILLAGES,
    WAR_GATHER_FORCES,
    WAR_ASSAULT_TOWN,
    WAR_BATTLE_MEETING,
    SIG_REFUGEE_DISBAND,
    SIG_START_PATROL_RUNNING,
    SIG_GATHER_UP_ALL_LOCAL_PRISONERS_UNHOLY,
    SIG_RETREAT_CANNIBAL_RAID_TO_NEAREST_NEST,
    SIG_HANG_OUT_OUTDOORS_ONLY,
    SIG_CANNIBALS_AT_HOME,
    SIG_SLAVER_SHIP_TO_ANYWHERE_CLOSE,
    SIG_PASSING_BY_TOWN_ASSAULT,
    SIG_OCCUPY_CONQUERED_TOWN,
    SIG_DEFEND_PLAYER_TOWN_CAMPAIGN,
    WAR_ASSAULT_TOWN_CANNIBAL,
    SIG_TIMED_CONTRACT
};

class DatapanelGUI;

class AIPackage
{
public:
    // VTable         : (none)
    // no_addr void AIPackage(const class AIPackage & _a1);// public missing arg names
    AIPackage();// public RVA = 0x285070
    AIPackage* _CONSTRUCTOR();// public RVA = 0x285070
    virtual ~AIPackage();// public RVA = 0x285110 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x285110 vtable offset = 0x0
    virtual TargetInfo getMyTarget(Character* me);// public RVA = 0x285530 vtable offset = 0x8
    TargetInfo _NV_getMyTarget(Character* me);// public RVA = 0x285530 vtable offset = 0x8
    virtual void notifyMyTargetPathfindImpossible(Character* me, const hand& was);// public RVA = 0x2853C0 vtable offset = 0x10
    void _NV_notifyMyTargetPathfindImpossible(Character* me, const hand& was);// public RVA = 0x2853C0 vtable offset = 0x10
    virtual MoveSpeed getDesiredTravelSpeed(Character* me);// public RVA = 0x285120 vtable offset = 0x18
    MoveSpeed _NV_getDesiredTravelSpeed(Character* me);// public RVA = 0x285120 vtable offset = 0x18
    hand missionTown; // 0x8 Member
    hand missionTarget; // 0x28 Member
    hand missionEmployer; // 0x48 Member
    GameData* packageData; // 0x68 Member
    int priorityLevel; // 0x70 Member
    BlackboardSignalFunctions key; // 0x74 Member
    UnloadedPlatoonJob unloadedMode; // 0x78 Member
    Blackboard* blackboard; // 0x80 Member
    Platoon* squad; // 0x88 Member
    AIPackage* leadsToPackage; // 0x90 Member
    GameData* endingDialogPassive; // 0x98 Member
    GameData* endingDialogActive; // 0xA0 Member
    Character* getLeader();// public RVA = 0x2853D0
    bool wasBetrayed; // 0xA8 Member
    virtual void save(GameData* state);// public RVA = 0x269190 vtable offset = 0x20
    void _NV_save(GameData* state);// public RVA = 0x269190 vtable offset = 0x20
    virtual void load(GameData* state);// public RVA = 0x2692E0 vtable offset = 0x28
    void _NV_load(GameData* state);// public RVA = 0x2692E0 vtable offset = 0x28
    virtual void activateAndSetup();// public RVA = 0x285210 vtable offset = 0x30
    void _NV_activateAndSetup();// public RVA = 0x285210 vtable offset = 0x30
    virtual void endPackage();// public RVA = 0x285130 vtable offset = 0x38
    void _NV_endPackage();// public RVA = 0x285130 vtable offset = 0x38
    virtual bool notifyBetrayal(Character* myWitness, Character* betrayer);// public RVA = 0x2852B0 vtable offset = 0x40
    bool _NV_notifyBetrayal(Character* myWitness, Character* betrayer);// public RVA = 0x2852B0 vtable offset = 0x40
    virtual void periodicUpdate();// public RVA = 0x285140 vtable offset = 0x48
    void _NV_periodicUpdate();// public RVA = 0x285140 vtable offset = 0x48
    virtual void assessNeutral(Character* who);// public RVA = 0x2854A0 vtable offset = 0x50
    void _NV_assessNeutral(Character* who);// public RVA = 0x2854A0 vtable offset = 0x50
    virtual bool assessEnemy(Character* who);// public RVA = 0x285150 vtable offset = 0x58
    bool _NV_assessEnemy(Character* who);// public RVA = 0x285150 vtable offset = 0x58
    virtual bool signalStart();// public RVA = 0x285160 vtable offset = 0x60
    bool _NV_signalStart();// public RVA = 0x285160 vtable offset = 0x60
    virtual bool signalEnd();// public RVA = 0x285170 vtable offset = 0x68
    bool _NV_signalEnd();// public RVA = 0x285170 vtable offset = 0x68
    bool iAmActivePackage() const;// public RVA = 0x2853F0
    virtual bool getGUIData(DatapanelGUI* panel);// public RVA = 0x285180 vtable offset = 0x70
    bool _NV_getGUIData(DatapanelGUI* panel);// public RVA = 0x285180 vtable offset = 0x70
    virtual bool autoNotifyJobsPanel();// public RVA = 0x285610 vtable offset = 0x78
    bool _NV_autoNotifyJobsPanel();// public RVA = 0x285610 vtable offset = 0x78
    virtual bool wantsRenewButton();// public RVA = 0x285190 vtable offset = 0x80
    bool _NV_wantsRenewButton();// public RVA = 0x285190 vtable offset = 0x80
    virtual void showManagementPanelCallback();// public RVA = 0x2851A0 vtable offset = 0x88
    void _NV_showManagementPanelCallback();// public RVA = 0x2851A0 vtable offset = 0x88
    virtual bool wasASuccess();// public RVA = 0x2851B0 vtable offset = 0x90
    bool _NV_wasASuccess();// public RVA = 0x2851B0 vtable offset = 0x90
    // no_addr class AIPackage & operator=(const class AIPackage & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};