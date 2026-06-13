#pragma once

#include <ogre/OgreVector3.h>

class ZoneMap;

enum SmellType
{
    SMELL_NULL,
    SMELL_BLOOD_AND_CORPSES,
    SMELL_EGG
};

class ZoneSmell : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    enum SmellMessageType
    {
        SMELLMSG_NONE,
        SMELLMSG_CORPSE,
        SMELLMSG_BLOOD,
        SMELLMSG_EGG
    };

    class SmellMsg
    {
    public:
        // no_addr void SmellMsg(enum ZoneSmell::SmellMessageType _a1, const class Ogre::Vector3 & _a2);// public missing arg names
        SmellMsg();// public RVA = 0x5C71E0
        SmellMsg* _CONSTRUCTOR();// public RVA = 0x5C71E0
        ZoneSmell::SmellMessageType type; // 0x0 Member
        Ogre::Vector3 pos; // 0x4 Member
        // no_addr class ZoneSmell::SmellMsg & operator=(const class ZoneSmell::SmellMsg & _a1);// public missing arg names
    };
    class Smell
    {
    public:
        // VTable         : (none)
        // no_addr float makeMultiplier(float _a1, float _a2, float _a3);// private missing arg names
        float decreaseRate; // 0x8 Member
        float increaseRate; // 0xC Member
        // no_addr void Smell(const class ZoneSmell::Smell & _a1);// public missing arg names
        Smell(float incRateInSecondsPerUnit, float decRateInSecondsPerUnit);// public RVA = 0x8F2F30
        Smell* _CONSTRUCTOR(float incRateInSecondsPerUnit, float decRateInSecondsPerUnit);// public RVA = 0x8F2F30
        virtual void update(float time);// public RVA = 0x8F2F90 vtable offset = 0x0
        void _NV_update(float time);// public RVA = 0x8F2F90 vtable offset = 0x0
        // no_addr float getStrength(const class Ogre::Vector3 & _a1);// public missing arg names
        Ogre::Vector3 pos; // 0x10 Member
        float numSources; // 0x1C Member
        float strength; // 0x20 Member
        // no_addr class ZoneSmell::Smell & operator=(const class ZoneSmell::Smell & _a1);// public missing arg names
    };
    ZoneSmell::Smell* smell_bloodAndCorpses; // 0x0 Member
    ZoneSmell::Smell* smell_eggs; // 0x8 Member
    std::map<void*, ZoneSmell::SmellMsg, std::less<void*>, Ogre::STLAllocator<std::pair<void* const, ZoneSmell::SmellMsg>, Ogre::GeneralAllocPolicy > > messages; // 0x10 Member
    // no_addr void ZoneSmell(const class ZoneSmell & _a1);// public missing arg names
    ZoneSmell(ZoneMap* m);// private RVA = 0xA24380
    ZoneSmell* _CONSTRUCTOR(ZoneMap* m);// private RVA = 0xA24380
    ZoneSmell::Smell* _getSmell(SmellType t);// private RVA = 0x333650
    ZoneMap* zoneMap; // 0x38 Member
    bool isEmpty();// public RVA = 0x8F2FF0
    void addSmell(ZoneSmell::SmellMessageType type, void* key, const Ogre::Vector3& _pos);// public RVA = 0x5E7C20
    float getSmell(Ogre::Vector3& posInOut, SmellType type);// public RVA = 0x333670
    float getGeneralSmellLevel(SmellType type);// public RVA = 0x7BF3E0
    void periodicUpdate(float time);// public RVA = 0x90B740
    ~ZoneSmell();// public RVA = 0x90EA80
    void _DESTRUCTOR();// public RVA = 0x90EA80
    // no_addr class ZoneSmell & operator=(const class ZoneSmell & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};