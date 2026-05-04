#pragma once

#include <ogre/OgreTexture.h>
#include <kenshi/util/iVector2.h>
#include <boost/unordered_map.hpp>

class Item;
class GameData;
class Character;

class RenderToTextureotron
{
public:
    RenderToTextureotron();// public RVA = 0x844520
    RenderToTextureotron* _CONSTRUCTOR();// public RVA = 0x844520
    ~RenderToTextureotron();// public RVA = 0x844540
    void _DESTRUCTOR();// public RVA = 0x844540
    Ogre::SharedPtr<Ogre::Texture> createTexture(const std::string& name, const iVector2& size, bool antialiased);// public RVA = 0x8455D0
    bool renderItem(Item* item, GameData* data, const std::string& filename, const iVector2& imgSize, const iVector2& textureSize, float pitch, float yaw, float roll, float zoom);// private RVA = 0x845E40
    void renderItem(Item* item, std::string& filename, iVector2& size);// public RVA = 0x846660
    void renderBuilding(GameData* data, std::string& filename, const iVector2& size, float yaw, float pitch);// public RVA = 0x8499B0
    void createBuilding(Ogre::SceneNode* node, GameData* data, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >& mats);// public RVA = 0x8473C0
    void renderCharacter(Character* character, Ogre::SharedPtr<Ogre::Texture> texture, const iVector2& size, const Ogre::TRect<float>& rect);// public RVA = 0x84A300
    std::string renderCharacterNPC(Character* character, const iVector2& size, float distance);// public RVA = 0x84B200
    void saveTexture(Ogre::SharedPtr<Ogre::Texture> texture, const std::string& fileName);// public RVA = 0x845900
    void loadOrCreateTexture(Ogre::SharedPtr<Ogre::Texture>& texture, const std::string& folder, const std::string& name, const iVector2& size);// public RVA = 0x8459B0
    void buildAllItemsIcons();// public RVA = 0x849010
    void setupSceneManager();// private RVA = 0x844580
    Ogre::Camera* setupCamera(const iVector2& size, float fov, float farClip);// private RVA = 0x8449A0
    void getItemName(std::string& name, GameData* dataA, GameData* dataB, GameData* dataC);// private RVA = 0x8448F0
    Ogre::Entity* createItemModel(Item* item, GameData* data);// private RVA = 0x844AD0
    Ogre::SceneManager* sceneManager; // 0x0 Member
    Ogre::Camera* camera; // 0x8 Member
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};