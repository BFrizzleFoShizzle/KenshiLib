#pragma once

#include <kenshi/MeshDataLookup.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreVector4.h>
#include <ogre/OgreMaterial.h>
#include <ogre/OgreSharedPtr.h>
#include <ogre/OgreIdString.h>
#include "util/OgreUnordered.h"
#include "util/lektor.h"
#include <boost/thread/shared_mutex.hpp>

class Harpoon;
class AttachedEffect;
class Wound;
class AttachmentData;
class AttachedEntity;
class AnimationClass;
class GameDataCopyStandalone;
class Character;
class GameData;
class Item;
class AttachedObject;

class AppearanceBase : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // Typedef        : AttachmentMap
    // Typedef        : AttachedEffectList
    // Typedef        : HarpoonList
    const boost::unordered::unordered_map<std::string, AttachmentData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachmentData*>, Ogre::GeneralAllocPolicy > >* slots; // 0x8 Member
    boost::unordered::unordered_map<std::string, AttachedEntity*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, AttachedEntity*>, Ogre::GeneralAllocPolicy > > attachedObjects; // 0x10 Member
    Ogre::FastArray<Harpoon*> attachedHarpoons; // 0x50 Member
    bool msgClearHarpoons; // 0x68 Member
    Ogre::FastArray<AttachedEffect*> attachedEffects; // 0x70 Member
    Ogre::FastArray<AttachedEffect*> attachedEffectsToRemove; // 0x88 Member
    Ogre::FastArray<Wound*> woundsList; // 0xA0 Member
    boost::shared_mutex woundsListMutex; // 0xB8 Member
    // no_addr void AppearanceBase(const class AppearanceBase & _a1);// public missing arg names
    AppearanceBase(AnimationClass* animation, GameDataCopyStandalone* appearance, Character* character, GameData* factionColorScheme);// public RVA = 0x5300F0
    AppearanceBase* _CONSTRUCTOR(AnimationClass* animation, GameDataCopyStandalone* appearance, Character* character, GameData* factionColorScheme);// public RVA = 0x5300F0
    virtual ~AppearanceBase();// public RVA = 0x531AF0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x531AF0 vtable offset = 0x0
    void updateAnimationTransforms();// public RVA = 0x52BBA0
    void forceUpdateAnimationTransforms();// public RVA = 0x52BC20
    virtual void update();// public RVA = 0x5385B0 vtable offset = 0x8
    void _NV_update();// public RVA = 0x5385B0 vtable offset = 0x8
    virtual void periodicUpdate();// public RVA = 0x544800 vtable offset = 0x10
    void _NV_periodicUpdate();// public RVA = 0x544800 vtable offset = 0x10
    void setAppearanceData(GameDataCopyStandalone* data);// public RVA = 0x537BE0
    GameDataCopyStandalone* getAppearanceData() const;// public RVA = 0x5B0960
    virtual void activate();// public RVA = 0x52B2E0 vtable offset = 0x18
    void _NV_activate();// public RVA = 0x52B2E0 vtable offset = 0x18
    virtual void deactivate();// public RVA = 0x530640 vtable offset = 0x20
    void _NV_deactivate();// public RVA = 0x530640 vtable offset = 0x20
    bool isFemale() const;// public RVA = 0x53E610
    virtual void setGender(bool _female);// public RVA = 0x52D400 vtable offset = 0x28
    void _NV_setGender(bool _female);// public RVA = 0x52D400 vtable offset = 0x28
    GameData* getRace() const;// public RVA = 0x53E620
    const std::string& chooseBodyMesh();// public RVA = 0x52C5A0
    void addWound(Wound* wound);// public RVA = 0x52FFA0
    void removeWound(Wound* wound);// public RVA = 0x530040
    bool attachItem(Item* item, const std::string& mesh, const std::string& slot);// public RVA = 0x5356D0
    bool attachItem(Item* item, const std::string& slot);// public RVA = 0x5355D0
    bool attachHarpoon(Harpoon* harpoon, const std::string& boneName, const Ogre::Vector3& offsetPosition, const Ogre::Quaternion& offsetOrientation);// public RVA = 0x52B820
    AttachedEffect* attachEffect(GameData* data, const std::string& boneName, const Ogre::Vector3& offsetPosition, const Ogre::Quaternion& offsetOrientation, bool manual, float baseEmission);// public RVA = 0x52C0B0
    AttachedEntity* getAttachedEntity(const std::string& slot) const;// public RVA = 0x52D1E0
    bool detachItem(Item* item);// public RVA = 0x52DB10
    bool detachItem(const std::string& slot);// public RVA = 0x52D970
    bool detachHarpoon(Harpoon* h);// public RVA = 0x52B700
    void detachAllHarpoonsT();// public RVA = 0x643260
    void _detachAllHarpoons();// public RVA = 0x52B490
    void removeEffect(AttachedEffect* effect);// public RVA = 0x52B960
    void updateWetness(bool force);// public RVA = 0x52BCD0
    void updateBloodyness();// public RVA = 0x5303B0
    bool getAttachmentPosition(const std::string& slot, Ogre::Vector3& pos, Ogre::Quaternion& rot);// public RVA = 0x52DC20
    bool hasSlot(const std::string& slot) const;// public RVA = 0x5E7F90
    float getNormalisedCharacterHeight() const;// public RVA = 0x5C7110
    float getCharacterHeight() const;// public RVA = 0x663EE0
    AnimationClass* getAnimationSystem() const;// public RVA = 0x607B10
    Ogre::SceneNode* getSceneNode() const;// public RVA = 0x5C7120
    Ogre::OldSkeletonInstance* getSkeleton() const;// public RVA = 0xD1380
    Ogre::Entity* getBody() const;// public RVA = 0x64600
    float getBodyRadius() const;// public RVA = 0x5C7140
    bool failedToLoad() const;// public RVA = 0x5E85A0
    Ogre::Vector3 getBonePosition(const std::string& boneName);// public RVA = 0x52B190
    Ogre::Quaternion getBoneOrientation(const std::string& boneName);// public RVA = 0x52B1C0
    const Ogre::Vector3& getVertexPosition(const int vertex) const;// public RVA = 0x52B1F0
    Ogre::Vector3 getVertexWorldPosition(const std::string& boneName, const int vertex) const;// public RVA = 0x52B240
    int getRandomVertex(const std::string& boneName, MeshDataLookup::Dir direction) const;// public RVA = 0x52C6B0
    const Ogre::Vector3& getRandomVertexPosition(const std::string& boneName, MeshDataLookup::Dir direction) const;// public RVA = 0x52C790
    void notifyDirty();// public RVA = 0x52C020
    void reload();// public RVA = 0x52CA70
    void serialise(GameData* state);// public RVA = 0x535060
    virtual void updateAppearance();// public RVA = 0x532D50 vtable offset = 0x30
    void _NV_updateAppearance();// public RVA = 0x532D50 vtable offset = 0x30
    void updatePortrait();// public RVA = 0x52B420
    void updateMovementScale();// public RVA = 0x52B390
    void switchLights(bool on);// public RVA = 0x52C400
    bool hasLights() const;// public RVA = 0x52C480
    void getLights(lektor<Ogre::Light*>& list);// public RVA = 0x52C500
    bool attachItem_Hair(GameData* data, const std::string& slot);// public RVA = 0x531D10
    void shaveHead(bool on);// public RVA = 0x52D260
    bool isShaved() const;// public RVA = 0x5B0970
    virtual void setFlayed(bool on);// public RVA = 0x544810 vtable offset = 0x38
    void _NV_setFlayed(bool on);// public RVA = 0x544810 vtable offset = 0x38
    virtual bool isFlayed() const;// public RVA = 0x544820 vtable offset = 0x40
    bool _NV_isFlayed() const;// public RVA = 0x544820 vtable offset = 0x40
    virtual bool isBarefoot() const;// public RVA = 0x544830 vtable offset = 0x48
    bool _NV_isBarefoot() const;// public RVA = 0x544830 vtable offset = 0x48
    void setVisible(bool value);// public RVA = 0x52C280
    bool getVisible() const;// public RVA = 0x52B160
    bool getAttachmentsLoaded() const;// public RVA = 0x52C340
    virtual void setAttachmentsVisible(bool visible);// public RVA = 0x52B170 vtable offset = 0x50
    void _NV_setAttachmentsVisible(bool visible);// public RVA = 0x52B170 vtable offset = 0x50
    virtual void createBody() = 0;// protected vtable offset = 0x58
    void buildBody(Ogre::SharedPtr<Ogre::Resource> _a1, void* bodyData);// protected RVA = 0x5388A0
    void buildAttachments();// protected RVA = 0x537EB0
    void createEntity(AttachedEntity* e);// protected RVA = 0x536F10
    void createPhysicsAttachment(AttachedEntity* e);// protected RVA = 0x5357A0
    void createEntityCallback(Ogre::SharedPtr<Ogre::Resource> resource, void* data);// protected RVA = 0x5368A0
    void attachEntity(AttachedObject* e);// protected RVA = 0x52CD00
    bool getSlotPosition(const std::string& slot, AttachedObject* object) const;// protected RVA = 0x52D0D0
    void setupItemMaterial(AttachedEntity* item);// protected RVA = 0x535A90
    void setupHairMaterial(AttachedEntity* item);// protected RVA = 0x531E80
    void setHairTexture(const std::string& name, int channel, int alpha, const Ogre::Vector3& colour, bool beard);// protected RVA = 0x5308C0
    virtual void setupCharacterEntityTexture(Ogre::Entity* ent, const boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >& textureLayers, Ogre::ColourValue* colour);// protected RVA = 0x52B340 vtable offset = 0x60
    void _NV_setupCharacterEntityTexture(Ogre::Entity* ent, const boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >& textureLayers, Ogre::ColourValue* colour);// protected RVA = 0x52B340 vtable offset = 0x60
    AttachedEntity* createAttachedObject(Item* item);// protected RVA = 0x535120
    bool affectsPortrait(AttachedEntity* item) const;// protected RVA = 0x52D870
    void updateOverlap() const;// protected RVA = 0x52D510
    virtual void updateCharaterTexture() = 0;// protected vtable offset = 0x68
    // no_addr bool isActivated();// protected
    Ogre::Entity* body; // 0xD8 Member
    Ogre::Entity* bodyLoader; // 0xE0 Member
    bool isCreatingBody; // 0xE8 Member
    float bodyRadius; // 0xEC Member
    Character* me; // 0xF0 Member
    bool visible; // 0xF8 Member
    std::string bodyFilename; // 0x100 Member
    Ogre::SharedPtr<Ogre::Material> bodyMaterial; // 0x128 Member
    AnimationClass* animation; // 0x138 Member
    bool female; // 0x140 Member
    bool updatedAttachments; // 0x141 Member
    bool updatedAppearanceData; // 0x142 Member
    bool updateBody; // 0x143 Member
    int suid; // 0x144 Member
    GameDataCopyStandalone* appearanceData; // 0x148 Member
    GameData* raceData; // 0x150 Member
    GameData* factionColor; // 0x158 Member
    GameData* hairStyle; // 0x160 Member
    bool shaved; // 0x168 Member
    Ogre::Vector4 waterline; // 0x16C Member
    float waterLineFadeTimer; // 0x17C Member
    bool barefoot; // 0x180 Member
    bool hideAttachments; // 0x181 Member
    float characterHeight; // 0x184 Member
    float characterHeightSpeedMultiplier; // 0x188 Member
    float characterHeight_0to1; // 0x18C Member
    float getCharacterHeightSpeedMultiplier();// protected RVA = 0x52B350
    // no_addr class AppearanceBase & operator=(const class AppearanceBase & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class AnimationClassHuman;

class AppearanceHuman : public AppearanceBase
{
public:
    // AppearanceBase offset = 0x0, length = 0x190
    // no_addr void AppearanceHuman(const class AppearanceHuman & _a1);// public missing arg names
    AppearanceHuman(AnimationClassHuman* animation, GameDataCopyStandalone* appearance, Character* character, GameData* factionColorScheme);// private RVA = 0x5330C0
    AppearanceHuman* _CONSTRUCTOR(AnimationClassHuman* animation, GameDataCopyStandalone* appearance, Character* character, GameData* factionColorScheme);// private RVA = 0x5330C0
    virtual ~AppearanceHuman();// private RVA = 0x533140 vtable offset = 0x0
    void _DESTRUCTOR();// private RVA = 0x533140 vtable offset = 0x0
    virtual void setGender(bool female) override;// public RVA = 0x52D840 vtable offset = 0x0
    void _NV_setGender(bool female);// public RVA = 0x52D840 vtable offset = 0x0
    virtual void periodicUpdate() override;// public RVA = 0x533160 vtable offset = 0x0
    void _NV_periodicUpdate();// public RVA = 0x533160 vtable offset = 0x0
    virtual void setAttachmentsVisible(bool visible) override;// public RVA = 0x5378E0 vtable offset = 0x0
    void _NV_setAttachmentsVisible(bool visible);// public RVA = 0x5378E0 vtable offset = 0x0
    void setHiddenPartsEnabled(bool enabled);// public RVA = 0x531790
    void showFace(bool show);// public RVA = 0x537510
    virtual void setFlayed(bool f) override;// public RVA = 0x52B470 vtable offset = 0x0
    void _NV_setFlayed(bool f);// public RVA = 0x52B470 vtable offset = 0x0
    virtual bool isFlayed() const override;// public RVA = 0x544A90 vtable offset = 0x0
    bool _NV_isFlayed() const;// public RVA = 0x544A90 vtable offset = 0x0
    void updateProportions();// public RVA = 0x52DF40
    float robotLegScale; // 0x190 Member
    virtual void createBody() override;// private RVA = 0x539750 vtable offset = 0x0
    void _NV_createBody();// private RVA = 0x539750 vtable offset = 0x0
    virtual void updateAppearance() override;// private RVA = 0x533170 vtable offset = 0x0
    void _NV_updateAppearance();// private RVA = 0x533170 vtable offset = 0x0
    void updateHiddenParts();// private RVA = 0x531540
    void updatePysiqueFromStats();// private RVA = 0x5310A0
    void updatePhysiqueMuscleMults();// private RVA = 0x52B4F0
    Ogre::Vector3 lastPhysiqueStats; // 0x194 Member
    float bulkMult; // 0x1A0 Member
    float muscleMult; // 0x1A4 Member
    float skinnyMult; // 0x1A8 Member
    bool flayed; // 0x1AC Member
    virtual void updateCharaterTexture() override;// private RVA = 0x5333D0 vtable offset = 0x0
    void _NV_updateCharaterTexture();// private RVA = 0x5333D0 vtable offset = 0x0
    virtual void setupCharacterEntityTexture(Ogre::Entity* ent, const boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >& textureLayers, Ogre::ColourValue* colour) override;// private RVA = 0x530CB0 vtable offset = 0x0
    void _NV_setupCharacterEntityTexture(Ogre::Entity* ent, const boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >& textureLayers, Ogre::ColourValue* colour);// private RVA = 0x530CB0 vtable offset = 0x0
    void setPosture(float posture, float neck, float shoulders);// private RVA = 0x52C800
    GameData* beard; // 0x1B0 Member
    bool hiddenPartsEnabled; // 0x1B8 Member
    // no_addr class AppearanceHuman & operator=(const class AppearanceHuman & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// private vtable offset = 0x0 missing arg names
};

class AnimationClassAnimal;

class AppearanceAnimal : public AppearanceBase
{
public:
    // AppearanceBase offset = 0x0, length = 0x190
    // no_addr void AppearanceAnimal(const class AppearanceAnimal & _a1);// public missing arg names
    AppearanceAnimal(AnimationClassAnimal* animation, GameDataCopyStandalone* appearance, Character* character);// private RVA = 0x534A80
    AppearanceAnimal* _CONSTRUCTOR(AnimationClassAnimal* animation, GameDataCopyStandalone* appearance, Character* character);// private RVA = 0x534A80
    virtual ~AppearanceAnimal();// private RVA = 0x534AB0 vtable offset = 0x0
    void _DESTRUCTOR();// private RVA = 0x534AB0 vtable offset = 0x0
    virtual void createBody() override;// private RVA = 0x539F60 vtable offset = 0x0
    void _NV_createBody();// private RVA = 0x539F60 vtable offset = 0x0
    virtual void updateCharaterTexture() override;// private RVA = 0x534AD0 vtable offset = 0x0
    void _NV_updateCharaterTexture();// private RVA = 0x534AD0 vtable offset = 0x0
    // no_addr class AppearanceAnimal & operator=(const class AppearanceAnimal & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// private vtable offset = 0x0 missing arg names
};