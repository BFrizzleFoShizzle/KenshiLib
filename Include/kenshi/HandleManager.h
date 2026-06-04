#pragma once

#include <iostream>
#include "util/OgreUnordered.h"
#include "util/hand.h"

// TODO move?
class Serialisable
{
public:
    // VTable         : (none)
    virtual void serialise(std::ofstream& _a1) = 0;// public vtable offset = 0x0 missing arg names
    virtual void restore(std::ifstream& _a1) = 0;// public vtable offset = 0x8 missing arg names
    // no_addr void Serialisable(const class Serialisable & _a1);// public missing arg names
    Serialisable();// public RVA = 0x37D6E0
    Serialisable* _CONSTRUCTOR();// public RVA = 0x37D6E0
    // no_addr class Serialisable & operator=(const class Serialisable & _a1);// public missing arg names
};

class Town;
class UseableStuff;

class HandleListBase : public Serialisable, public Ogre::GeneralAllocatedObject
{
public:
    // Serialisable offset = 0x0, length = 0x8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // no_addr void HandleListBase(const class HandleListBase & _a1);// public missing arg names
    HandleListBase(unsigned int _maxSize);// public RVA = 0x500F20
    HandleListBase* _CONSTRUCTOR(unsigned int _maxSize);// public RVA = 0x500F20
    virtual ~HandleListBase();// public RVA = 0x4FDF00 vtable offset = 0x10
    void _DESTRUCTOR();// public RVA = 0x4FDF00 vtable offset = 0x10
    virtual void clearToZero();// public RVA = 0x4FDF40 vtable offset = 0x18
    void _NV_clearToZero();// public RVA = 0x4FDF40 vtable offset = 0x18
    virtual RootObjectBase* get(const hand& handle) const;// public RVA = 0x3367B0 vtable offset = 0x20
    RootObjectBase* _NV_get(const hand& handle) const;// public RVA = 0x3367B0 vtable offset = 0x20
    virtual bool isUnloadedNotDead(const hand& handle) const;// public RVA = 0x4FDF60 vtable offset = 0x28
    bool _NV_isUnloadedNotDead(const hand& handle) const;// public RVA = 0x4FDF60 vtable offset = 0x28
    virtual hand add(RootObjectBase* _a1) = 0;// public vtable offset = 0x30 missing arg names
    virtual hand addExisting(RootObjectBase* o, const hand& _handle);// public RVA = 0x380550 vtable offset = 0x38
    hand _NV_addExisting(RootObjectBase* o, const hand& _handle);// public RVA = 0x380550 vtable offset = 0x38
    virtual void setUnloaded(const hand& handle);// public RVA = 0x4FE010 vtable offset = 0x40
    void _NV_setUnloaded(const hand& handle);// public RVA = 0x4FE010 vtable offset = 0x40
    virtual void destroy(const hand& handle);// public RVA = 0x37D6B0 vtable offset = 0x48
    void _NV_destroy(const hand& handle);// public RVA = 0x37D6B0 vtable offset = 0x48
    virtual void serialise(std::basic_ofstream<char, std::char_traits<char> >& out) override;// public RVA = 0x36DFB0 vtable offset = 0x0
    void _NV_serialise(std::basic_ofstream<char, std::char_traits<char> >& out);// public RVA = 0x36DFB0 vtable offset = 0x0
    virtual void restore(std::basic_ifstream<char, std::char_traits<char> >& in) override;// public RVA = 0x36E260 vtable offset = 0x0
    void _NV_restore(std::basic_ifstream<char, std::char_traits<char> >& in);// public RVA = 0x36E260 vtable offset = 0x0
    unsigned int addToList(RootObjectBase* o, bool reloadingFromUnloadedState, unsigned int id);// protected RVA = 0xD1B20
    virtual unsigned int getIndex(const hand& _a1) const = 0;// protected vtable offset = 0x50 missing arg names
    virtual void setIndex(hand& _a1, unsigned int _a2) const = 0;// protected vtable offset = 0x58 missing arg names
    virtual bool compareSerials(const hand& _a1, const hand& _a2) const = 0;// protected vtable offset = 0x60 missing arg names
    void resize(unsigned int siz);// protected RVA = 0xCD120
    RootObjectBase** objects; // 0x8 Member
    unsigned int maxSize; // 0x10 Member
    unsigned int getNewID();// private RVA = 0xCD1D0
    unsigned int lastID; // 0x14 Member
    // no_addr class HandleListBase & operator=(const class HandleListBase & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};

class HandleContainerList : public HandleListBase
{
public:
    // HandleListBase offset = 0x0, length = 0x18
    // no_addr void HandleContainerList(const class HandleContainerList & _a1);// public missing arg names
    HandleContainerList(int _maxSize);// public RVA = 0x878C20
    HandleContainerList* _CONSTRUCTOR(int _maxSize);// public RVA = 0x878C20
    virtual hand add(RootObjectBase* o) override;// public RVA = 0x39DD40 vtable offset = 0x0
    hand _NV_add(RootObjectBase* o);// public RVA = 0x39DD40 vtable offset = 0x0
    virtual void setIndex(hand& h, unsigned int index) const override;// protected RVA = 0x878C50 vtable offset = 0x0
    void _NV_setIndex(hand& h, unsigned int index) const;// protected RVA = 0x878C50 vtable offset = 0x0
    virtual unsigned int getIndex(const hand& h) const override;// protected RVA = 0x878C60 vtable offset = 0x0
    unsigned int _NV_getIndex(const hand& h) const;// protected RVA = 0x878C60 vtable offset = 0x0
    virtual bool compareSerials(const hand& a, const hand& b) const override;// protected RVA = 0x878C70 vtable offset = 0x0
    bool _NV_compareSerials(const hand& a, const hand& b) const;// protected RVA = 0x878C70 vtable offset = 0x0
    virtual ~HandleContainerList();// public RVA = 0x8770C0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x8770C0 vtable offset = 0x0
    // no_addr class HandleContainerList & operator=(const class HandleContainerList & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};

class PlatoonHandleContainerList : public HandleContainerList
{
public:
    // HandleContainerList offset = 0x0, length = 0x18
    // no_addr void PlatoonHandleContainerList(const class PlatoonHandleContainerList & _a1);// public missing arg names
    PlatoonHandleContainerList(int _maxSize);// public RVA = 0x878E40
    PlatoonHandleContainerList* _CONSTRUCTOR(int _maxSize);// public RVA = 0x878E40
    // no_addr class RootObject * getCharacter(const class hand & _a1);// public missing arg names
    RootObject* getCharacterOrZero(const hand& handle) const;// public RVA = 0x143D50
    RootObjectBase* getCharacterOrPlatoon(const hand& handle) const;// public RVA = 0x4FE2A0
    ActivePlatoon* getActivePlatoon(const hand& handle) const;// public RVA = 0x4FE320
    // no_addr bool characterLoaded(const class hand & _a1);// public missing arg names
    virtual void setUnloaded(const hand& handle) override;// public RVA = 0x4FE350 vtable offset = 0x0
    void _NV_setUnloaded(const hand& handle);// public RVA = 0x4FE350 vtable offset = 0x0
    virtual void destroy(const hand& handle) override;// public RVA = 0x4FE3D0 vtable offset = 0x0
    void _NV_destroy(const hand& handle);// public RVA = 0x4FE3D0 vtable offset = 0x0
    virtual ~PlatoonHandleContainerList();// public RVA = 0x877180 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x877180 vtable offset = 0x0
    // no_addr class PlatoonHandleContainerList & operator=(const class PlatoonHandleContainerList & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};

class ZoneMapContent;

class HandleList : public HandleListBase
{
public:
    // HandleListBase offset = 0x0, length = 0x18
    hand containerHandle; // 0x18 Member
    std::map<unsigned __int64, unsigned int, std::less<unsigned __int64>, Ogre::STLAllocator<std::pair<unsigned __int64 const, unsigned int>, Ogre::GeneralAllocPolicy > > handleShift; // 0x38 Member
    // no_addr void HandleList(const class HandleList & _a1);// public missing arg names
    HandleList(int _maxSize, hand _container);// public RVA = 0x503C70
    HandleList* _CONSTRUCTOR(int _maxSize, hand _container);// public RVA = 0x503C70
    virtual hand add(RootObjectBase* o) override;// public RVA = 0xD1BE0 vtable offset = 0x0
    hand _NV_add(RootObjectBase* o);// public RVA = 0xD1BE0 vtable offset = 0x0
    virtual RootObjectBase* get(const hand& handle) const override;// public RVA = 0x344F80 vtable offset = 0x0
    RootObjectBase* _NV_get(const hand& handle) const;// public RVA = 0x344F80 vtable offset = 0x0
    virtual hand addExisting(RootObjectBase* o, const hand& _handle) override;// public RVA = 0x504A40 vtable offset = 0x0
    hand _NV_addExisting(RootObjectBase* o, const hand& _handle);// public RVA = 0x504A40 vtable offset = 0x0
    virtual hand addExistingAndForceContainer(RootObjectBase* o, const hand& _handle);// public RVA = 0x38F880 vtable offset = 0x68
    hand _NV_addExistingAndForceContainer(RootObjectBase* o, const hand& _handle);// public RVA = 0x38F880 vtable offset = 0x68
    virtual void destroy(const hand& handle) override;// public RVA = 0xD52B0 vtable offset = 0x0
    void _NV_destroy(const hand& handle);// public RVA = 0xD52B0 vtable offset = 0x0
    virtual void setIndex(hand& h, unsigned int index) const override;// protected RVA = 0x503D00 vtable offset = 0x0
    void _NV_setIndex(hand& h, unsigned int index) const;// protected RVA = 0x503D00 vtable offset = 0x0
    virtual unsigned int getIndex(const hand& h) const override;// protected RVA = 0x503D10 vtable offset = 0x0
    unsigned int _NV_getIndex(const hand& h) const;// protected RVA = 0x503D10 vtable offset = 0x0
    virtual bool compareSerials(const hand& a, const hand& b) const override;// protected RVA = 0x503D20 vtable offset = 0x0
    bool _NV_compareSerials(const hand& a, const hand& b) const;// protected RVA = 0x503D20 vtable offset = 0x0
    virtual ~HandleList();// public RVA = 0x504C40 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x504C40 vtable offset = 0x0
    // no_addr class HandleList & operator=(const class HandleList & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};

class ZoneMapHandleContainerList : public HandleContainerList
{
public:
    // HandleContainerList offset = 0x0, length = 0x18
    // no_addr void ZoneMapHandleContainerList(const class ZoneMapHandleContainerList & _a1);// public missing arg names
    ZoneMapHandleContainerList(int _maxSize);// public RVA = 0x878DA0
    ZoneMapHandleContainerList* _CONSTRUCTOR(int _maxSize);// public RVA = 0x878DA0
    ZoneMapContent* getZoneMap(const hand& handle) const;// public RVA = 0x9F7700
    RootObject* getObject(const hand& handle) const;// public RVA = 0x9F7770
    virtual void setUnloaded(const hand& handle) override;// public RVA = 0x9F77D0 vtable offset = 0x0
    void _NV_setUnloaded(const hand& handle);// public RVA = 0x9F77D0 vtable offset = 0x0
    virtual void destroy(const hand& handle) override;// public RVA = 0x9F7850 vtable offset = 0x0
    void _NV_destroy(const hand& handle);// public RVA = 0x9F7850 vtable offset = 0x0
    HandleList* getCorrectHandleList(const hand& h) const;// public RVA = 0x9F7730
    virtual ~ZoneMapHandleContainerList();// public RVA = 0x877140 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x877140 vtable offset = 0x0
    // no_addr class ZoneMapHandleContainerList & operator=(const class ZoneMapHandleContainerList & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};

class TownHandleContainerList : public HandleContainerList
{
public:
    // HandleContainerList offset = 0x0, length = 0x18
    // no_addr void TownHandleContainerList(const class TownHandleContainerList & _a1);// public missing arg names
    TownHandleContainerList(int _maxSize);// public RVA = 0x878CF0
    TownHandleContainerList* _CONSTRUCTOR(int _maxSize);// public RVA = 0x878CF0
    virtual bool compareSerials(const hand& a, const hand& b) const override;// protected RVA = 0x878D20 vtable offset = 0x0
    bool _NV_compareSerials(const hand& a, const hand& b) const;// protected RVA = 0x878D20 vtable offset = 0x0
    virtual ~TownHandleContainerList();// public RVA = 0x877100 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x877100 vtable offset = 0x0
    // no_addr class TownHandleContainerList & operator=(const class TownHandleContainerList & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};

class ItemHandleList : public HandleList
{
public:
    // HandleList offset = 0x0, length = 0x60
    // no_addr void ItemHandleList(const class ItemHandleList & _a1);// public missing arg names
    ItemHandleList(int _maxSize);// public RVA = 0x87DCA0
    ItemHandleList* _CONSTRUCTOR(int _maxSize);// public RVA = 0x87DCA0
    virtual void setUnloaded(const hand& handle) override;// public RVA = 0x87DD00 vtable offset = 0x0
    void _NV_setUnloaded(const hand& handle);// public RVA = 0x87DD00 vtable offset = 0x0
    virtual ~ItemHandleList();// public RVA = 0x87D330 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x87D330 vtable offset = 0x0
    // no_addr class ItemHandleList & operator=(const class ItemHandleList & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x10 missing arg names
};

class HandleManager : public Serialisable, public Ogre::GeneralAllocatedObject
{
public:
    // Serialisable offset = 0x0, length = 0x8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // no_addr void HandleManager(const class HandleManager & _a1);// public missing arg names
    HandleManager();// public RVA = 0x87DDD0
    HandleManager* _CONSTRUCTOR();// public RVA = 0x87DDD0
    ~HandleManager();// public RVA = 0x87DFE0
    void _DESTRUCTOR();// public RVA = 0x87DFE0
    virtual void serialise(std::basic_ofstream<char, std::char_traits<char> >& out) override;// public RVA = 0x36AD90 vtable offset = 0x0
    void _NV_serialise(std::basic_ofstream<char, std::char_traits<char> >& out);// public RVA = 0x36AD90 vtable offset = 0x0
    virtual void restore(std::basic_ifstream<char, std::char_traits<char> >& out) override;// public RVA = 0x36ADF0 vtable offset = 0x0
    void _NV_restore(std::basic_ifstream<char, std::char_traits<char> >& out);// public RVA = 0x36ADF0 vtable offset = 0x0
    const hand& getRedirect(const hand& h) const;// public RVA = 0x14D780
    void removeRedirect(const hand& h);// public RVA = 0x2AC6D0
    void clearRedirectForHandle(const hand& h);// public RVA = 0x6400B0
    void reset();// public RVA = 0x385210
    void setUnloaded(const hand& handle);// public RVA = 0x7BF1B0
    void destroy(const hand& handle, const char* reason);// public RVA = 0x2AC790
    RootObjectBase* getAnything(const hand& handle, bool deadOnes);// public RVA = 0x284060
    TownBase* getTownBase(const hand& handle, const Ogre::Vector3& backupPos) const;// public RVA = 0x9F7950
    Town* getTown(const hand& handle, const Ogre::Vector3& backupPos) const;// public RVA = 0x9F79D0
    RootObject* getAnythingButBase(const hand& handle, bool deadOnes);// public RVA = 0x267230
    Character* getShopTrader(const hand& handle);// public RVA = 0x7903A0
    Building* getBuilding(const hand& handle);// public RVA = 0xD5F30
    UseableStuff* getBuilding_UseableStuff(const hand& handle);// public RVA = 0x9F7A50
    Character* getCharacter(const hand& handle, bool deadOnes, bool redirect);// public RVA = 0x14D7C0
    Platoon* getPlatoon(const hand& handle);// public RVA = 0x285040
    Item* getItem(const hand& handle);// public RVA = 0x166E40
    bool isPlayerFaction(const hand& h);// public RVA = 0x9FC830
    bool addExistingObjectHandleToZone(hand& handle);// public RVA = 0x9F78D0
    Character* getFromDeathParade(const hand& handle);// public RVA = 0x7959C0
    PlatoonHandleContainerList platoons; // 0x8 Member
    ZoneMapHandleContainerList zones; // 0x20 Member
    TownHandleContainerList towns; // 0x38 Member
    ItemHandleList items; // 0x50 Member
    ItemHandleList nodes; // 0xB0 Member
    HandleContainerList mapfeatures; // 0x110 Member
    ogre_unordered_map<hand, hand>::type redirect; // 0x128 Member
    // no_addr class HandleManager & operator=(const class HandleManager & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};