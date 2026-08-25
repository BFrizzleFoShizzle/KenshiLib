#pragma once

#include <kenshi/util/lektor.h>
#include <kenshi/util/OgreUnordered.h>
#include "Enums.h"
#include "GameDataGroup.h"

class ResearchItem
{
public:
    ResearchItem(GameData* d);// public RVA = 0x8379E0
    ResearchItem* _CONSTRUCTOR(GameData* d);// public RVA = 0x8379E0
    ResearchItem();// public RVA = 0x8379D0
    ResearchItem* _CONSTRUCTOR();// public RVA = 0x8379D0
    GameData* data; // 0x0 Member
    float progress; // 0x8 Member
    GameData* getCostItem(int id);// public RVA = 0x831790
    int getCostItemQuantity(int id);// public RVA = 0x82E100
    int getNumDifferentCostItems();// public RVA = 0x82DDF0
};

class ManagementScreen;
class Building;

class Research
{
public:
    class BuildingUpgrades
    {
    public:
        BuildingUpgrades();// public RVA = 0x837A00
        BuildingUpgrades* _CONSTRUCTOR();// public RVA = 0x837A00
        float productionMult; // 0x0 Member
        float powerBoost; // 0x4 Member
        float powerCapacity; // 0x8 Member
    };
    // no_addr void Research(const class Research & _a1);// public missing arg names
    Research();// public RVA = 0x830390
    Research* _CONSTRUCTOR();// public RVA = 0x830390
    void _reset();// public RVA = 0x835720
    void _setup();// public RVA = 0x8335E0
    void getAvailableCrafts(lektor<GameDataGroup>& out, itemType type1, itemType type2paired);// public RVA = 0x82DC20
    int getArmourCraftLevel(GameData* armour, int skill, bool crit);// public RVA = 0x82D120
    void getAvailableResearch(lektor<GameData*>& out, const std::string& category);// public RVA = 0x82FA60
    const lektor<std::string >& getCategories() const;// public RVA = 0x82D110
    // no_addr int getTechLevelOf(class GameData * _a1);// public missing arg names
    bool startResearch(GameData* d);// public RVA = 0x833310
    void stopResearch(GameData* d);// public RVA = 0x82F850
    float getResearchProgress(GameData* d);// public RVA = 0x4A6D20
    float getResearchProgress(const ResearchItem* d) const;// public RVA = 0x82DB00
    void completeResearch(GameData* d);// public RVA = 0x832FC0
    bool isFinished(GameData* what);// public RVA = 0x82DD70
    bool isBuildingResearched(GameData* d);// public RVA = 0x82D4D0
    std::string getETA(GameData* d, bool simple);// public RVA = 0x82FFC0
    bool payCosts(GameData* d);// public RVA = 0x832E30
    bool canPayCosts(GameData* data);// public RVA = 0x8318C0
    GameData* getBlueprintsFor(GameData* item);// public RVA = 0x82DBA0
    void staticUpdate();// public RVA = 0x82D100
    float getCurrentResearchRate() const;// public RVA = 0x82D0F0
    void serialise(GameData* data);// public RVA = 0x82FB20
    void load(GameData* data);// public RVA = 0x834B60
    void progressResearch(float amount);// public RVA = 0x8355E0
    bool checkRequirementsForInvisibility(GameData* what, bool twoLevels);// public RVA = 0x82EF00
    bool checkRequirements(GameData* what, bool twoLevels, bool checkCost);// public RVA = 0x831A10
    bool checkRequirements_andQueue(GameData* what);// public RVA = 0x834450
    bool isInQueue(GameData* what);// public RVA = 0x82D510
    void _updateTheAllList();// public RVA = 0x831E20
    std::deque<ResearchItem, Ogre::STLAllocator<ResearchItem, Ogre::GeneralAllocPolicy > >& getResearchQueue();// public RVA = 0x2967E0
    void setResearchDeskLevel(int level);// public RVA = 0x832E00
    void refreshTheoreticalTechLevel();// public RVA = 0x82F2F0
    int needsATechBench(GameData* d);// public RVA = 0x82F4A0
    const Research::BuildingUpgrades& getUpgrades(const Building* building) const;// public RVA = 0x82D6E0
    bool hasPaidFor(GameData* d) const;// public RVA = 0x82D4B0
    int getResearchDeskLevel() const;// public RVA = 0x4A6D50
    bool hasArtifact(GameData* artifact, int quantity);// public RVA = 0x82D280
    ResearchItem getResearchItem(GameData* d);// public RVA = 0x82F650
    ManagementScreen* screen; // 0x0 Member
    int theoreticalTechLevel; // 0x8 Member
    bool changedSoUpdateGUI; // 0xC Member
    void getAllResearchBenches(lektor<Building*>& out);// private RVA = 0x82D1C0
    void _deleteArtifact(GameData* artifact, int quantity);// private RVA = 0x82D370
    bool deleteAllArtifactsFor(GameData* research);// private RVA = 0x831990
    void _updateTheEnabledItemsList();// private RVA = 0x82F5B0
    void cleanupQueue();// private RVA = 0x82DF70
    void removeFromQueue(GameData* d);// private RVA = 0x82D5C0
    void upgradeShit(GameData* tech);// private RVA = 0x8304D0
    void _createBlueprintsFor(GameData* itemData);// private RVA = 0x830F60
    std::map<itemType, lektor<GameData*>, std::less<itemType>, Ogre::STLAllocator<std::pair<itemType const, lektor<GameData*> >, Ogre::GeneralAllocPolicy > > craftableThings; // 0x10 Member
    std::deque<ResearchItem, Ogre::STLAllocator<ResearchItem, Ogre::GeneralAllocPolicy > > current; // 0x38 Member
    std::map<GameData*, Research::BuildingUpgrades, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, Research::BuildingUpgrades>, Ogre::GeneralAllocPolicy > > buildingUpgrades; // 0x70 Member
    std::map<std::string, Ogre::vector<ResearchItem>::type, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<ResearchItem>::type >, Ogre::GeneralAllocPolicy > > all; // 0x98 Member
    lektor<std::string > categories; // 0xC0 Member
    lektor<std::string > paidFor; // 0xD8 Member
    ogre_unordered_set<GameData*>::type finished; // 0xF0 Member
    ogre_unordered_set<GameData*>::type enabledObjects; // 0x130 Member
    int researchDeskLevel; // 0x170 Member
    int numResearchers; // 0x174 Member
    float totalResearchThisFrame; // 0x178 Member
    ~Research();// public RVA = 0x8115B0
    void _DESTRUCTOR();// public RVA = 0x8115B0
    // no_addr class Research & operator=(const class Research & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};