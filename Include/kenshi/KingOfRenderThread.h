#pragma once

#include <mygui/MyGUI_Widget.h>
#include <ogre/OgreMath.h>
#include <ogre/OgreIdString.h>
#include <kenshi/util/iVector2.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/MeshDataLookup.h>

class GameData;
class Renderer;
class CameraClass;
class Terrain;
class TitleScreen;

class KingOfRenderThread : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void KingOfRenderThread(const class KingOfRenderThread & _a1);// public missing arg names
    KingOfRenderThread();// public RVA = 0x789E50
    KingOfRenderThread* _CONSTRUCTOR();// public RVA = 0x789E50
    ~KingOfRenderThread();// public RVA = 0x78A950
    void _DESTRUCTOR();// public RVA = 0x78A950
    void startup();// public RVA = 0x86BA00
    void initialisation();// public RVA = 0x867340
    void mainloop(float time);// public RVA = 0x789A90
    void newGame(MyGUI::Widget* _a1);// public RVA = 0x871680 missing arg names
    void newGameWithCharEdit(GameData* starter);// public RVA = 0x871710
    void error(const std::string& msg);// public RVA = 0x82CFC0
    void errorD(const std::string& msg);// public RVA = 0x82CFE0
    void loadTerrain(const std::string& name);// public RVA = 0x873240
    void analyseModel(const std::string& name, Ogre::Entity* model);// public RVA = 0x78AAF0
    const lektor<int>& getBonesVertices(const std::string& modelName, const std::string& boneName, MeshDataLookup::Dir facing) const;// public RVA = 0x789AE0
    MeshDataLookup* getMeshData(const std::string& meshName);// public RVA = 0x789D40
    void addTerrainBloodSplat(const float x, const float z, const float rad, const Ogre::Radian rotationAngle, const iVector2 UVOffset, const std::string material, bool slowSpreading);// public RVA = 0x789AA0
    float TIME; // 0x0 Member
    Renderer* render; // 0x8 Member
    CameraClass* camera; // 0x10 Member
    Terrain* terrain; // 0x18 Member
    TitleScreen* titleScreen; // 0x20 Member
    void deleteTitleScreen();// public RVA = 0x911630
    void processThreadMessages();// private RVA = 0x789A80
    ogre_unordered_map<Ogre::IdString, MeshDataLookup*>::type globalMeshDataLookup; // 0x28 Member
    // no_addr class KingOfRenderThread & operator=(const class KingOfRenderThread & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};