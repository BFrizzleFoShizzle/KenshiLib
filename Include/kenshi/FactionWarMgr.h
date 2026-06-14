#pragma once

#include "FitnessSelector.h"
#include "util/TimeOfDay.h"
#include "util/hand.h"
#include "util/lektor.h"

class Faction;
class GameData;
class Platoon;
class DatapanelGUI;
class CampaignInstance;
class RootObjectBase;
class TownBase;
class CampaignData;
class CampaignTriggerData;
class AreaBiomeGroup;

class FactionWarMgr : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void FactionWarMgr(const class FactionWarMgr & _a1);// public missing arg names
    FactionWarMgr(Faction* f);// public RVA = 0x80ED70
    FactionWarMgr* _CONSTRUCTOR(Faction* f);// public RVA = 0x80ED70
    ~FactionWarMgr();// public RVA = 0x810710
    void _DESTRUCTOR();// public RVA = 0x810710
    Faction* me; // 0x0 Member
    int lastID; // 0x8 Member
    void reset();// public RVA = 0x9C27E0
    void save(GameData* s);// public RVA = 0x9C50E0
    void load(GameData* s);// public RVA = 0x9C8610
    void removePlatoon(Platoon* p);// public RVA = 0x6BB5C0
    void addPlatoon(Platoon* p);// public RVA = 0x9C2CC0
    void getGUIData(DatapanelGUI* panel, int cat, bool playeronly);// public RVA = 0x7AB760
    bool areAnyHostileCampaignsRunning(bool playeronly);// public RVA = 0x7920E0
    void endCampaign(CampaignInstance* c);// public RVA = 0x9D0EB0
    void getAllTheForces(RootObjectBase* target, CampaignInstance* c);// public RVA = 0x9C3890
    void _generateForcesForTown(TownBase* t, CampaignInstance* c);// public RVA = 0x9C29A0
    bool canGenerateThisManyForces(int num);// public RVA = 0x9C26D0
    void periodicUpdate();// public RVA = 0x9C9B60
    void debugButton();// public RVA = 0x9C1F90
    CampaignInstance* triggerCampaign(RootObjectBase* targetTown, CampaignData* data, TownBase* home);// public RVA = 0x9C8080
    void triggerCampaign(RootObjectBase* targetTown, GameData* _data, float minTime, float maxTime, TownBase* hometown, bool forceDuplicate, Faction* triggeringFaction);// public RVA = 0x9C7C60
    void triggerCampaign(const FitnessSelector<CampaignTriggerData*>& randomTriggers, RootObjectBase* targetTown, TownBase* hometown, bool forceDuplicate, Faction* triggeringFaction);// public RVA = 0x9CA3F0
    CampaignInstance* getCurrentCampaign(Platoon* who);// public RVA = 0x283050
    // no_addr class GameData * getAIPackage(class Platoon * _a1);// public missing arg names
    hand getAITarget(Platoon* who);// public RVA = 0x283170
    UnloadedPlatoonJob getMyUnloadedAI(Platoon* who);// public RVA = 0x9C3310
    lektor<TownBase*> myTowns; // 0x10 Member
    std::map<Platoon*, CampaignInstance*, std::less<Platoon*>, Ogre::STLAllocator<std::pair<Platoon* const, CampaignInstance*>, Ogre::GeneralAllocPolicy > > forces; // 0x28 Member
    lektor<hand> hiredForces; // 0x50 Member
    lektor<CampaignInstance*> activeCampaigns; // 0x68 Member
    lektor<AreaBiomeGroup*> biomeTerritories; // 0x80 Member
    lektor<AreaBiomeGroup*> biomeNoGoZones; // 0x98 Member
    bool isBiomeHomeTerritory(AreaBiomeGroup* area);// public RVA = 0x9C2380
    TownBase* getNearestTown(const Ogre::Vector3& p);// public RVA = 0x9C2520
    void getTownsInBiome(lektor<TownBase*>& out, AreaBiomeGroup* b);// public RVA = 0x9C2480
    void getMyTownsWithEnoughFreePopulation(lektor<TownBase*>& out, int popNeeded);// public RVA = 0x9C2610
    CampaignInstance* getActiveCampaign(int uniqueID);// public RVA = 0x9C23C0
    void setup();// private RVA = 0x9C9420
    TimeOfDay nextUpdateTime; // 0xB0 Member
    class CampaignRequest
    {
    public:
        // no_addr void CampaignRequest(const class FactionWarMgr::CampaignRequest & _a1);// public missing arg names
        CampaignRequest();// public RVA = 0x9C1F10
        CampaignRequest* _CONSTRUCTOR();// public RVA = 0x9C1F10
        TimeOfDay timeToStart; // 0x0 Member
        CampaignData* data; // 0x8 Member
        hand target; // 0x10 Member
        hand homeBase; // 0x30 Member
        Faction* enemy; // 0x50 Member
        int numAttempts; // 0x58 Member
        bool tryToChangeTarget();// public RVA = 0x9C3440
        // no_addr class FactionWarMgr::CampaignRequest & operator=(const class FactionWarMgr::CampaignRequest & _a1);// public missing arg names
    };
    lektor<FactionWarMgr::CampaignRequest*> campaignRequests; // 0xB8 Member
    CampaignData* _createCampaignData(GameData* dat);// private RVA = 0x9C7AD0
    lektor<CampaignData*> possibleCampaigns; // 0xD0 Member
    // no_addr class FactionWarMgr & operator=(const class FactionWarMgr & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};