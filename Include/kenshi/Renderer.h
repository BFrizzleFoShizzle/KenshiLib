#pragma once

#include <kenshi/util/lektor.h>

#include <ogre/OgreIdString.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Windef.h>

class RenderEntityT;

class RendererT
{
public:
    // VTable         : (none)
    virtual ~RendererT();// public RVA = 0x81DA60 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x81DA60 vtable offset = 0x0
    virtual void update() = 0;// public vtable offset = 0x8
    lektor<RenderEntityT*> debugEntsUpdateListT; // 0x8 Member
    // no_addr void RendererT(const class RendererT & _a1);// public missing arg names
    RendererT();// public RVA = 0x81DB20
    RendererT* _CONSTRUCTOR();// public RVA = 0x81DB20
    // no_addr class RendererT & operator=(const class RendererT & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class TerrainDecalsManager;
class RenderToTextureotron;
class GameData;
class PMBListener;

class Renderer : public RendererT
{
public:
    // RendererT offset = 0x0, length = 0x20
    // no_addr void Renderer(const class Renderer & _a1);// public missing arg names
    Renderer();// public RVA = 0x814820
    Renderer* _CONSTRUCTOR();// public RVA = 0x814820
    virtual ~Renderer();// public RVA = 0x8140E0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x8140E0 vtable offset = 0x0
    void shutDown();// public RVA = 0x812120
    virtual void update() override;// public RVA = 0x82CFF0 vtable offset = 0x0
    void _NV_update();// public RVA = 0x82CFF0 vtable offset = 0x0
    TerrainDecalsManager* terrainDecalManager; // 0x20 Member
    RenderToTextureotron* renderToTextureIconMachine; // 0x28 Member
    Ogre::Light* createLight(GameData* data, bool indoors, int floor);// public RVA = 0x814190
    Ogre::Camera* initialiseRoot(HWND__* winhandle);// public RVA = 0x8176E0
    void go();// public RVA = 0x8121D0
    void initialiseScene();// public RVA = 0x8148B0
    Ogre::Entity* createDebugBox(Ogre::Vector3 a, Ogre::Vector3 b);// public RVA = 0x812CC0
    void destroy(Ogre::SceneNode* node, bool destroyAttached);// public RVA = 0x8123E0
    void destroy(Ogre::Light* light);// public RVA = 0x8121F0
    Ogre::SceneManager* getSceneManager() const;// public RVA = 0x6DF60
    Ogre::RenderSystem* getRenderSystem() const;// public RVA = 0x2D53B0
    Ogre::SceneNode* getRootSceneNode() const;// public RVA = 0x3883D0
    Ogre::Camera* getCamera() const;// public RVA = 0x264180
    Ogre::Viewport* getViewport() const;// public RVA = 0x5E8580
    Ogre::Root* getRoot() const;// public RVA = 0x143D40
    float getScreenWidth() const;// public RVA = 0x805550
    float getScreenHeight() const;// public RVA = 0x805570
    Ogre::CompositorWorkspace* getWorkspace() const;// public RVA = 0x5E8590
    Ogre::Vector3 getSceneRelativeOrigin() const;// public RVA = 0xF8970
    bool validateCompositor(const std::string& node);// public RVA = 0x813270
    void setupPostProcessing(const Ogre::IdString& definitionName);// public RVA = 0x8125E0
    void refreshActiveCompositor();// public RVA = 0x8122C0
    // no_addr void renderOneFrame();// public
    static void getMeshInformation(const Ogre::SubMesh* const submesh, unsigned __int64& vertex_count, Ogre::Vector3*& vertices, Ogre::Vector2*& uvs, const Ogre::Vector3& position, const Ogre::Quaternion& orient, const Ogre::Vector3& scale);// public RVA = 0x812EF0
    bool paintImageOnTexture(Ogre::SharedPtr<Ogre::Texture> texture, std::string filename, int X, int Y, float scale, bool flipX, bool flipY);// public RVA = 0x814DA0
    // no_addr unsigned long getNextFrameNumber();// public
    static std::string DefaultMaterialName; // RVA = 0x1FC34E8 Static Member
    bool setupConfig();// private RVA = 0x813710
    void initPaintTextures();// private RVA = 0x812290
    std::map<std::string, Ogre::Image*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Image*>, Ogre::GeneralAllocPolicy > > preloadedPaints; // 0x30 Member
    void setupResources();// private RVA = 0x815B00
    Ogre::Camera* camera; // 0x58 Member
    Ogre::SceneManager* scene; // 0x60 Member
    Ogre::Root* root; // 0x68 Member
    Ogre::Viewport* viewport; // 0x70 Member
    Ogre::RenderWindow* window; // 0x78 Member
    Ogre::FrameListener* mFrameListener; // 0x80 Member
    Ogre::CompositorWorkspace* workspace; // 0x88 Member
    PMBListener* pixelMotionBlurListener; // 0x90 Member
    // no_addr class Renderer & operator=(const class Renderer & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};