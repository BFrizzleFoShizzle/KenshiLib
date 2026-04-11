#pragma once

#include <ogre/OgreMovableObject.h>
#include <ogre/OgreFrameListener.h>
#include <boost/function.hpp>

class TiffStream;
class Landscape;
class TerrainDecal;
class TerrainCamera;

class Terrain : public Ogre::MovableObject, public Ogre::FrameListener
{
public:
    // Ogre::MovableObject offset = 0x0, length = 0x170
    // Ogre::FrameListener offset = 0x170, length = 0x8
    // no_addr void Terrain(const class Terrain & _a1);// public missing arg names
    // no_addr void Terrain(unsigned int _a1, class Ogre::ObjectMemoryManager * _a2);// public missing arg names
    virtual ~Terrain() = 0;// public vtable offset = 0x0
    //void _DESTRUCTOR() = 0;// public vtable offset = 0x0
    virtual const std::string& getMovableType() const override = 0;// public vtable offset = 0x0
    virtual const Ogre::AxisAlignedBox& getBoundingBox() = 0;// public vtable offset = 0x78
    virtual float getBoundingRadius() = 0;// public vtable offset = 0x80
    virtual void _updateRenderQueue(Ogre::RenderQueue* _a1, Ogre::Camera* _a2, const Ogre::Camera* _a3) override = 0;// public vtable offset = 0x0 missing arg names
    virtual void visitRenderables(Ogre::Renderable::Visitor* _a1, bool _a2) override = 0;// public vtable offset = 0x0 missing arg names
    virtual void _notifyCurrentCamera(Ogre::Camera* _a1) = 0;// public vtable offset = 0x88 missing arg names
    virtual bool frameStarted(const Ogre::FrameEvent& _a1) override = 0;// public vtable offset = 0x0 missing arg names
    // no_addr void setPatchSize(int _a1);// public missing arg names
    // no_addr void setTerrainScale(float _a1, float _a2);// public missing arg names
    // no_addr void setLodRange(int _a1, int _a2);// public missing arg names
    // no_addr void setDetailThreshold(float _a1, float _a2, float _a3);// public missing arg names
    // no_addr bool openStream(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1);// public missing arg names
    // no_addr void closeStream();// public
    // no_addr void setOgreBuildLimits(int _a1, int _a2);// public missing arg names
    // no_addr void setHeightCacheSize(int _a1);// public missing arg names
    // no_addr unsigned __int64 getRawData(int _a1, int _a2, int _a3, int _a4, char * _a5);// public missing arg names
    // no_addr int getPatchInfo(unsigned int _a1, class Ogre::Vector2 & _a2, class Ogre::Vector2 & _a3);// public missing arg names
    // no_addr unsigned int getPatchInfo(const class Ogre::Vector3 & _a1, int _a2, class Ogre::Vector2 & _a3, class Ogre::Vector2 & _a4);// public missing arg names
    // no_addr unsigned int getPatchInfo(const class Ogre::Vector3 & _a1, int _a2);// public missing arg names
    // no_addr unsigned __int64 getBloodPatches(float _a1, class std::vector<std::pair<unsigned int,float>,std::allocator<std::pair<unsigned int,float> > > & _a2);// public missing arg names
    // no_addr void drawBloodPatch(unsigned int _a1, class Ogre::SharedPtr<Ogre::Texture> _a2, int _a3, int _a4);// public missing arg names
    // Typedef        : MaterialCreateFunc
    // Typedef        : MaterialDestroyFunc
    // no_addr void setDefaultMaterial(class Ogre::SharedPtr<Ogre::Material> _a1);// public missing arg names
    // no_addr void setDefaultMaterialName(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1);// public missing arg names
    // no_addr void setMaterialCallbacks(const class boost::function<Ogre::SharedPtr<Ogre::Material> __cdecl(Ogre::AxisAlignedBox const &,int)> & _a1, const class boost::function<void __cdecl(Ogre::AxisAlignedBox const &,Ogre::SharedPtr<Ogre::Material>)> & _a2);// public missing arg names
    // no_addr void setMaterialDistance(float _a1);// public missing arg names
    // no_addr void setBloodMaterial(class Ogre::SharedPtr<Ogre::Material> _a1);// public missing arg names
    // no_addr void setBloodMaterialName(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1);// public missing arg names
    struct Hit
    {
        bool hit; // 0x0 Member
        unsigned char level; // 0x1 Member
        Ogre::Vector3 point; // 0x4 Member
        Ogre::Vector3 normal; // 0x10 Member
        // no_addr void Hit();// public
        // no_addr struct Terrain::Hit & operator=(const struct Terrain::Hit & _a1);// public missing arg names
    };
    // no_addr float getHeight(const class Ogre::Vector3 & _a1, int _a2);// protected missing arg names
    // no_addr struct Terrain::Hit getHeight(const class Ogre::Vector3 & _a1);// public missing arg names
    // no_addr struct Terrain::Hit getApproximateHeight(const class Ogre::Vector3 & _a1);// public missing arg names
    // no_addr struct Terrain::Hit intersect(const class Ogre::Ray & _a1);// public missing arg names
    struct Info
    {
        unsigned __int64 memory; // 0x0 Member
        unsigned __int64 patches; // 0x8 Member
        unsigned __int64 visible; // 0x10 Member
        unsigned __int64 triangles; // 0x18 Member
        unsigned __int64 ogre; // 0x20 Member
        unsigned __int64 unbuilt; // 0x28 Member
    };
    // no_addr struct Terrain::Info getDebugInfo();// public
    static std::vector<std::string, std::allocator<std::string > > debugMessages; // RVA = 0x0 Static Member
    // no_addr int patchCreated(struct PatchGeometry * _a1);// protected missing arg names
    // no_addr int patchDestroyed(struct PatchGeometry * _a1);// protected missing arg names
    // no_addr void patchChanged(struct PatchGeometry * _a1, int _a2);// protected missing arg names
    // no_addr int visitorCallback(struct PatchGeometry * _a1);// protected missing arg names
    // no_addr int updateMaterial(struct PatchGeometry * _a1);// protected missing arg names
    // no_addr void createDrawable(struct PatchGeometry * _a1);// protected missing arg names
    // no_addr void preBuildCallback(int _a1);// protected missing arg names
    const Ogre::Camera* mCamera; // 0x178 Member
    Ogre::Vector3 mCameraPosition; // 0x180 Member
    Ogre::AxisAlignedBox mBounds; // 0x190 Member
    TiffStream* mStream; // 0x1B8 Member
    Landscape* mTerrain; // 0x1C0 Member
    float mSize; // 0x1C8 Member
    float mHeight; // 0x1CC Member
    float mHeightScale; // 0x1D0 Member
    float mOffset; // 0x1D4 Member
    float mSizeScale; // 0x1D8 Member
    int mBuildCounter; // 0x1DC Member
    bool mNeedsBuilding; // 0x1E0 Member
    int mPatchesToBuild; // 0x1E4 Member
    int mOnscreenLimit; // 0x1E8 Member
    int mOffscreenLimit; // 0x1EC Member
    int mDrawableCount; // 0x1F0 Member
    float mMaterialDistance; // 0x1F4 Member
    Ogre::SharedPtr<Ogre::Material> mDefaultMaterial; // 0x1F8 Member
    boost::function<Ogre::SharedPtr<Ogre::Material> __cdecl(Ogre::AxisAlignedBox const&, int)> mCreateMaterialCallback; // 0x208 Member
    boost::function<void __cdecl(Ogre::AxisAlignedBox const&, Ogre::SharedPtr<Ogre::Material>)> mDestroyMaterialCallback; // 0x230 Member
    struct Box
    {
        int top; // 0x0 Member
        int left; // 0x4 Member
        int right; // 0x8 Member
        int bottom; // 0xC Member
        int cx; // 0x10 Member
        int cy; // 0x14 Member
    };
    int mHeightCacheSize; // 0x258 Member
    Terrain::Box mHeightCacheBox; // 0x25C Member
    int mCachePositionX; // 0x274 Member
    int mCachePositionY; // 0x278 Member
    float* mHeightCache[0x4]; // 0x280 Member
    // no_addr void updateHeightCache();// protected
    // no_addr void createBloodPatches();// protected
    struct BloodQueue
    {
        unsigned int patch; // 0x0 Member
        int sector; // 0x4 Member
        int depth; // 0x8 Member
        Ogre::SharedPtr<Ogre::Texture> texture; // 0x10 Member
        // no_addr void BloodQueue(const struct Terrain::BloodQueue & _a1);// public missing arg names
        // no_addr void BloodQueue();// public
        // no_addr void ~BloodQueue();// public
        // no_addr struct Terrain::BloodQueue & operator=(const struct Terrain::BloodQueue & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    std::vector<Terrain::BloodQueue> mDecalQueue; // 0x2A0 Member
    std::vector<TerrainDecal*> mDecals; // 0x2C0 Member
    Ogre::SharedPtr<Ogre::Material> mBloodMaterial; // 0x2E0 Member
    TerrainCamera* mBloodCamera; // 0x2F0 Member
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};