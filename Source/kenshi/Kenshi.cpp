#include <kenshi/CharStats.h>

#include <kenshi/Kenshi.h>

#include <kenshi/GameWorld.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/GlobalConstants.h>
#include <core/Functions.h>

#include <core/RVA.h>

#include <core/md5.h>

#include <Debug.h>
#include <Release_Assert.h>

/**
 * Kenshi.cpp
 * 
 * This file will house the majority if not all memory-related actions to act as one centralized file that needs to be updated for new versions as they come out.
 * 
 */

std::string GetEXEHash()
{
    WCHAR path[MAX_PATH];
    GetModuleFileNameW(NULL, path, MAX_PATH);
    std::ifstream file(std::wstring(path), std::ios::ate | std::ios::binary);
    if (file.is_open())
    {
        size_t size = file.tellg();
        std::vector<char> fileBytes(size);
        file.seekg(0);
        file.read(&fileBytes[0], fileBytes.size());
        md5::md5_t hasher(&fileBytes[0], fileBytes.size());
        char hashStr[33];
        hasher.get_string(hashStr);
        return std::string(hashStr);
    }
    return "ERROR";
}

// nicer static initialization in C++03
template<typename T1, typename T2>
class StaticMap : public std::map<T1, T2>
{
public:
    StaticMap()
        : std::map<T1, T2>()
    {

    }
    StaticMap& Add(T1 key, T2 value)
    {
        this->insert(std::make_pair(key, value));
        return *this;
    }
};

StaticMap<std::string, KenshiLib::BinaryVersion> HashToVersionMap = StaticMap<std::string, KenshiLib::BinaryVersion>()
    .Add("df4a5a7ef8a29deb24b70e7b7f4a222a", KenshiLib::BinaryVersion(KenshiLib::BinaryVersion::STEAM, "1.0.65"))
    .Add("213349bf76a0a758067f9ed0aef2ab01", KenshiLib::BinaryVersion(KenshiLib::BinaryVersion::GOG, "1.0.65"));

// Search for 2000.000f in non-writable and one of those will be the correct value
// CAMERA_FAR
StaticMap<KenshiLib::BinaryVersion, offset_t> MaxCameraDistanceOffset = StaticMap<KenshiLib::BinaryVersion, offset_t>()
    .Add(KenshiLib::BinaryVersion(KenshiLib::BinaryVersion::STEAM, "1.0.65"), 0x016FF770)
    .Add(KenshiLib::BinaryVersion(KenshiLib::BinaryVersion::GOG, "1.0.65"), 0x016FE300);

// CAMERA_CLOSE
StaticMap<KenshiLib::BinaryVersion, offset_t> MinCameraDistanceOffset = StaticMap<KenshiLib::BinaryVersion, offset_t>()
    .Add(KenshiLib::BinaryVersion(KenshiLib::BinaryVersion::STEAM, "1.0.65"), 0x0167EAD4)
    .Add(KenshiLib::BinaryVersion(KenshiLib::BinaryVersion::GOG, "1.0.65"), 0x0167DAD4);

std::string kenshiHash = GetEXEHash();
KenshiLib::BinaryVersion kenshiVersion = HashToVersionMap.count(kenshiHash) > 0 ? HashToVersionMap.at(kenshiHash) : KenshiLib::BinaryVersion(KenshiLib::BinaryVersion::UNKNOWN, "UNKNOWN");

bool KenshiLib::Init()
{
    // Version number: [update breaking backwards-compatibility (hopefully never)].[update on Nexus].[update on GitHub]
    DebugLog("KenshiLib 0.3.3");
    return InitRVAs();
}
// force override - used for hash mismatches, which can occur if the user has modified the executable
// there are a few mods on Nexus that need this
bool KenshiLib::OverrideKenshiVersion(BinaryVersion newVersion)
{
    StaticMap<std::string, KenshiLib::BinaryVersion>::iterator entryIter = HashToVersionMap.begin();
    while (entryIter != HashToVersionMap.end())
    {
        // if the new version is in our list of supported versions, accept it
        if (entryIter->second == newVersion)
        {
            kenshiVersion = entryIter->second;
            return true;
        }
        ++entryIter;
    }
    // version isn't in supported versions
    return false;
}

KenshiLib::BinaryVersion KenshiLib::GetKenshiVersion()
{
    return kenshiVersion;
}

float& KenshiLib::GetMaxCameraDistance()
{
    KenshiLib::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t maxCameraDistanceOffset = MaxCameraDistanceOffset.at(kenshiVersion);
    static RVAPtr<float> c_inst(maxCameraDistanceOffset);
    return *c_inst.GetPtr();
}

float& KenshiLib::GetMinCameraDistance()
{
    KenshiLib::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t minCameraDistanceOffset = MinCameraDistanceOffset.at(kenshiVersion);
    static RVAPtr<float> c_inst(minCameraDistanceOffset);
    return *c_inst.GetPtr();
}
