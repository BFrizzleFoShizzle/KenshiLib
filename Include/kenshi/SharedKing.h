#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>

class AreasList;
class TownList;
class ZoneManagerInterfaceT;

class SharedKing : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    SharedKing();// public RVA = 0x867290
    SharedKing* _CONSTRUCTOR();// public RVA = 0x867290
    ~SharedKing();// public RVA = 0x867320
    void _DESTRUCTOR();// public RVA = 0x867320
    AreasList* areasList; // 0x0 Member
    TownList* townList; // 0x8 Member
    ZoneManagerInterfaceT* zoneMgr; // 0x10 Member
    bool isLevelEditMode();// public RVA = 0x790F70
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};