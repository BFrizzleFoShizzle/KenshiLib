#pragma once

#include <ogre/OgreEntity.h>
#include <kenshi/util/lektor.h>
#include <boost/unordered_map.hpp>

// TODO move?
class MeshDataLookup : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    enum Dir
    {
        FRONT,
        BACK,
        NUM_DIRS
    };

    // no_addr static enum MeshDataLookup::Dir getOppositeDirection(enum MeshDataLookup::Dir _a1);// public missing arg names
    // Typedef        : DirectionBoneList
    // Typedef        : BoneDataMap
    // no_addr void MeshDataLookup(const class MeshDataLookup & _a1);// public missing arg names
    MeshDataLookup(const Ogre::Entity* model);// public RVA = 0x78A8C0
    MeshDataLookup* _CONSTRUCTOR(const Ogre::Entity* model);// public RVA = 0x78A8C0
    ~MeshDataLookup();// public RVA = 0x789EC0
    void _DESTRUCTOR();// public RVA = 0x789EC0
    boost::unordered::unordered_map<Ogre::IdString, lektor<lektor<int> >, boost::hash<Ogre::IdString>, std::equal_to<Ogre::IdString>, Ogre::STLAllocator<std::pair<Ogre::IdString const, lektor<lektor<int> > >, Ogre::GeneralAllocPolicy > > boneAssignments; // 0x0 Member
    unsigned __int64 vertCount; // 0x40 Member
    Ogre::Vector3* verts; // 0x48 Member
    Ogre::Vector2* uvs; // 0x50 Member
    void init(const Ogre::Entity* model);// private RVA = 0x789F70
    // no_addr class MeshDataLookup & operator=(const class MeshDataLookup & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
