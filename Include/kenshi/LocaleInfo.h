#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <boost/unordered_map.hpp>
#include <boost/filesystem/path.hpp>

class ModInfo;

class LocaleInfo : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void LocaleInfo(const class LocaleInfo & _a1);// public missing arg names
    LocaleInfo(const std::string& id, const std::wstring& name, const std::string& sCode, bool base);// public RVA = 0x174D30
    LocaleInfo* _CONSTRUCTOR(const std::string& id, const std::wstring& name, const std::string& sCode, bool base);// public RVA = 0x174D30
    LocaleInfo();// public RVA = 0x174CD0
    LocaleInfo* _CONSTRUCTOR();// public RVA = 0x174CD0
    bool isBase; // 0x0 Member
    std::string id; // 0x8 Member
    std::wstring name; // 0x30 Member
    std::string steamCode; // 0x58 Member
    bool isMod; // 0x80 Member
    ~LocaleInfo();// public RVA = 0x17B100
    void _DESTRUCTOR();// public RVA = 0x17B100
    LocaleInfo& operator=(const LocaleInfo& __that);// public RVA = 0x17D160
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class LocaleManager
{
public:
    // Typedef        : LocaleIdMap
    // Typedef        : LocaleList
    // Typedef        : LocalePtrList
    static LocaleManager* getInstance();// public RVA = 0x120560
    // no_addr void LocaleManager(const class LocaleManager & _a1);// public missing arg names
    LocaleManager();// private RVA = 0x177720
    LocaleManager* _CONSTRUCTOR();// private RVA = 0x177720
    ~LocaleManager();// private RVA = 0x1777A0
    void _DESTRUCTOR();// private RVA = 0x1777A0
    void init();// public RVA = 0x175B40
    LocaleInfo* getCurrentLocale() const;// public RVA = 0x174CB0
    void setCurrentLocale(LocaleInfo* locale);// public RVA = 0x175490
    bool trySetCurrentLocaleFromMod(ModInfo* mod);// public RVA = 0x174E00
    std::string getCurrentLocalePath() const;// public RVA = 0x175150
    std::string getCurrentLocaleMod() const;// public RVA = 0x175280
    const Ogre::FastArray<LocaleInfo*>& getAvailableLanguages() const;// public RVA = 0x174CC0
    static bool isEastAsian(const std::string& id);// public RVA = 0x175770
    boost::unordered::unordered_map<std::string, LocaleInfo*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, LocaleInfo*>, Ogre::GeneralAllocPolicy > > localeById; // 0x0 Member
    Ogre::FastArray<LocaleInfo> localeList; // 0x40 Member
    Ogre::FastArray<LocaleInfo*> availableLanguages; // 0x58 Member
    LocaleInfo* modLocale; // 0x70 Member
    LocaleInfo* currentLocale; // 0x78 Member
    boost::filesystem::path localePath; // 0x80 Member
    // no_addr class LocaleManager & operator=(const class LocaleManager & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// private missing arg names
};