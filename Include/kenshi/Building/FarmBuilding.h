#pragma once

#include "ProductionBuilding.h"

#include <ogre/OgreMesh.h>

enum CropType
{
    CROP_NULL,
    CROP_GREEN,
    CROP_ARID,
    CROP_SWAMP
};

class StaticBoxEntity;

class FarmBuilding : public ProductionBuilding
{
public:
    // ProductionBuilding offset = 0x0, length = 0x490
    // no_addr void FarmBuilding(const class FarmBuilding & _a1);// public missing arg names
    FarmBuilding(GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors);// public RVA = 0xE83E0
    FarmBuilding* _CONSTRUCTOR(GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors);// public RVA = 0xE83E0
    virtual ~FarmBuilding();// public RVA = 0xE4410 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0xE4410 vtable offset = 0x0
    virtual bool createPhysical() override;// public RVA = 0xE8EB0 vtable offset = 0x0
    bool _NV_createPhysical();// public RVA = 0xE8EB0 vtable offset = 0x0
    virtual void destroyPhysical() override;// public RVA = 0xE5E60 vtable offset = 0x0
    void _NV_destroyPhysical();// public RVA = 0xE5E60 vtable offset = 0x0
    virtual void setVisible(bool on) override;// public RVA = 0xDEE50 vtable offset = 0x0
    void _NV_setVisible(bool on);// public RVA = 0xDEE50 vtable offset = 0x0
    virtual void update() override;// public RVA = 0xE5540 vtable offset = 0x0
    void _NV_update();// public RVA = 0xE5540 vtable offset = 0x0
    virtual bool needsUpdate() override;// public RVA = 0xF6DB0 vtable offset = 0x0
    bool _NV_needsUpdate();// public RVA = 0xF6DB0 vtable offset = 0x0
    virtual void operate(Character* who, float amount) override;// public RVA = 0xE59A0 vtable offset = 0x0
    void _NV_operate(Character* who, float amount);// public RVA = 0xE59A0 vtable offset = 0x0
    virtual bool isAnyInputsEmpty() const override;// public RVA = 0xDF240 vtable offset = 0x0
    bool _NV_isAnyInputsEmpty() const;// public RVA = 0xDF240 vtable offset = 0x0
    virtual bool isProductionFull() override;// public RVA = 0xDEE90 vtable offset = 0x0
    bool _NV_isProductionFull();// public RVA = 0xDEE90 vtable offset = 0x0
    virtual float howMuchPowerDoYouWantForSortingFunction() const override;// public RVA = 0xDF2F0 vtable offset = 0x0
    float _NV_howMuchPowerDoYouWantForSortingFunction() const;// public RVA = 0xDF2F0 vtable offset = 0x0
    virtual void setupMiningResourceLevel() override;// public RVA = 0xE8260 vtable offset = 0x0
    void _NV_setupMiningResourceLevel();// public RVA = 0xE8260 vtable offset = 0x0
    virtual void getGUIData(DatapanelGUI* datapanel, int category) override;// public RVA = 0xE2160 vtable offset = 0x0
    void _NV_getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0xE2160 vtable offset = 0x0
    virtual void getGUIEfficiency(DatapanelGUI* datapanel, int category) override;// public RVA = 0xE2D10 vtable offset = 0x0
    void _NV_getGUIEfficiency(DatapanelGUI* datapanel, int category);// public RVA = 0xE2D10 vtable offset = 0x0
    virtual void getGUIWorkers(DatapanelGUI* datapanel, int category) override;// public RVA = 0xDFFE0 vtable offset = 0x0
    void _NV_getGUIWorkers(DatapanelGUI* datapanel, int category);// public RVA = 0xDFFE0 vtable offset = 0x0
    virtual void getGUIState(DatapanelGUI* datapanel, int category) override;// public RVA = 0xE02D0 vtable offset = 0x0
    void _NV_getGUIState(DatapanelGUI* datapanel, int category);// public RVA = 0xE02D0 vtable offset = 0x0
    bool destroyAPlant();// public RVA = 0xE47C0
    void timeSkip(float h, bool ignoreWater);// public RVA = 0xDF6A0
    bool _updateInputs(float rate);// public RVA = 0xDF480
    virtual void upgrade(DataPanelLine* _a1) override;// public RVA = 0xDEED0 vtable offset = 0x0 missing arg names
    void _NV_upgrade(DataPanelLine* _a1);// public RVA = 0xDEED0 vtable offset = 0x0 missing arg names
    virtual void downgrade(DataPanelLine* _a1) override;// public RVA = 0xDEFE0 vtable offset = 0x0 missing arg names
    void _NV_downgrade(DataPanelLine* _a1);// public RVA = 0xDEFE0 vtable offset = 0x0 missing arg names
    virtual void getGUIFertility(DatapanelGUI* datapanel, int category) override;// public RVA = 0xE0970 vtable offset = 0x0
    void _NV_getGUIFertility(DatapanelGUI* datapanel, int category);// public RVA = 0xE0970 vtable offset = 0x0
    bool isCropsEdible();// public RVA = 0x8C8920
    void eat(float rate);// public RVA = 0xE5E20
    static float getYieldChancePerCrop(GameData* farmData, AreaBiomeGroup* biome, float skillMult, float resourceMult);// public RVA = 0xE4060
    float getYieldChancePerCrop(float skillMult);// public RVA = 0xDFDD0
    float getCropMult(CropType typ);// public RVA = 0xF53A0
    ogre_unordered_map<CropType, float>::type cropMultipliers; // 0x490 Member
    virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract) override;// public RVA = 0xE3B40 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0xE3B40 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* stateList) override;// public RVA = 0xE3DA0 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState* stateList);// public RVA = 0xE3DA0 vtable offset = 0x0
    virtual Ogre::Vector3 getDirectionMarker(const Ogre::Vector3& currentPosition) override;// public RVA = 0xDF2A0 vtable offset = 0x0
    Ogre::Vector3 _NV_getDirectionMarker(const Ogre::Vector3& currentPosition);// public RVA = 0xDF2A0 vtable offset = 0x0
    virtual bool dontNeedWorkRightNow() const override;// public RVA = 0xF6DC0 vtable offset = 0x0
    bool _NV_dontNeedWorkRightNow() const;// public RVA = 0xF6DC0 vtable offset = 0x0
    static float getFertilityMultiplier(float resourceLevel, GameData* farmData);// public RVA = 0xE42E0
    struct PlantSource
    {
        GameData* data; // 0x0 Member
        Ogre::SharedPtr<Ogre::Mesh> mesh; // 0x8 Member
        float scaleStart; // 0x18 Member
        float scaleEnd; // 0x1C Member
        float scaleVariance; // 0x20 Member
        float offsetStart; // 0x24 Member
        float offsetEnd; // 0x28 Member
        float delay; // 0x2C Member
        float delayScale; // 0x30 Member
        bool isStatic; // 0x34 Member
        int count; // 0x38 Member
        int group; // 0x3C Member
        // no_addr void PlantSource(const struct FarmBuilding::PlantSource & _a1);// public missing arg names
        PlantSource();// public RVA = 0xF8420
        PlantSource* _CONSTRUCTOR();// public RVA = 0xF8420
        // no_addr void ~PlantSource();// public
        // no_addr struct FarmBuilding::PlantSource & operator=(const struct FarmBuilding::PlantSource & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    class FarmBatch
    {
    public:
        // no_addr void FarmBatch(const class FarmBuilding::FarmBatch & _a1);// public missing arg names
        FarmBatch(GameData* data);// public RVA = 0xE7A30
        FarmBatch* _CONSTRUCTOR(GameData* data);// public RVA = 0xE7A30
        void load();// public RVA = 0xE8BB0
        void meshLoaded(Ogre::SharedPtr<Ogre::Resource> _a1, void* entityData);// public RVA = 0xE6080
        void createGeometry();// public RVA = 0xE49E0
        lektor<FarmBuilding::PlantSource*> plantSource; // 0x0 Member
        lektor<int> plantGroups; // 0x18 Member
        Ogre::SharedPtr<Ogre::Mesh> geometry; // 0x30 Member
        float height; // 0x40 Member
        int size; // 0x44 Member
        int meshesLoaded; // 0x48 Member
        lektor<FarmBuilding*> farms; // 0x50 Member
        ~FarmBatch();// public RVA = 0xF8320
        void _DESTRUCTOR();// public RVA = 0xF8320
        // no_addr class FarmBuilding::FarmBatch & operator=(const class FarmBuilding::FarmBatch & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    static boost::unordered::unordered_map<std::string, FarmBuilding::FarmBatch*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, FarmBuilding::FarmBatch*>, Ogre::GeneralAllocPolicy > > farmBatches; // RVA = 0x1C0A810 Static Member
    struct SubPlant
    {
        float scale; // 0x0 Member
        float offset; // 0x4 Member
        float rv; // 0x8 Member
        FarmBuilding::PlantSource* data; // 0x10 Member
        int index; // 0x18 Member
    };
    struct Plant
    {
        float age; // 0x0 Member
        Ogre::Vector3 position; // 0x4 Member
        lektor<FarmBuilding::SubPlant> parts; // 0x10 Member
        Plant(const FarmBuilding::Plant& __that);// public RVA = 0xF1680
        Plant* _CONSTRUCTOR(const FarmBuilding::Plant& __that);// public RVA = 0xF1680
        Plant();// public RVA = 0xEFCA0
        Plant* _CONSTRUCTOR();// public RVA = 0xEFCA0
        ~Plant();// public RVA = 0xEFD30
        void _DESTRUCTOR();// public RVA = 0xEFD30
        FarmBuilding::Plant& operator=(const FarmBuilding::Plant& __that);// public RVA = 0xF01B0
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    Ogre::SharedPtr<Ogre::Material> material; // 0x4D0 Member
    Ogre::Entity* plantEntity; // 0x4E0 Member
    lektor<FarmBuilding::Plant> plants; // 0x4E8 Member
    StaticBoxEntity* clickHull; // 0x500 Member
    FarmBuilding::FarmBatch* batch; // 0x508 Member
    float lastUpdated; // 0x510 Member
    void setupMaterial();// protected RVA = 0xE7060
    void updateMaterial();// protected RVA = 0xE4500
    void updatePlantInstance(FarmBuilding::Plant& p);// protected RVA = 0xDF320
    void createPlants(FarmBuilding::FarmBatch* batch);// protected RVA = 0xE61F0
    void createClickHull(FarmBuilding::FarmBatch* batch);// protected RVA = 0xDFB40
    void createEntity(FarmBuilding::FarmBatch* batch);// protected RVA = 0xDF100
    void resetFarm();// protected RVA = 0xE48A0
    float eatingTime; // 0x514 Member
    float grown; // 0x518 Member
    float died; // 0x51C Member
    float cleared; // 0x520 Member
    float growStart; // 0x524 Member
    int harvested; // 0x528 Member
    float itemsPerPlant; // 0x52C Member
    float clearRate; // 0x530 Member
    float consumptionRate; // 0x534 Member
    float harvestRate; // 0x538 Member
    float growthTime; // 0x53C Member
    float harvestTime; // 0x540 Member
    float deathTime; // 0x544 Member
    float droughtTime; // 0x548 Member
    float deathThreshold; // 0x54C Member
    float droughtMultiplier; // 0x550 Member
    float fertilityMultiplier; // 0x554 Member
    bool isHydroponic; // 0x558 Member
    // no_addr class FarmBuilding & operator=(const class FarmBuilding & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};
