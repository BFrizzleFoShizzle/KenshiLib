#pragma once

#include <kenshi/ThreadClass.h>
#include <ogre/OgreVector3.h>
#include <ogre/Math/Simple/OgreAabb.h>
#include <kenshi/Havok.h>
#include <kenshi/util/hand.h>
#include <kenshi/util/lektor.h>

class hkaiWorld;
class ZoneMap;
class hand;
class Building;
class iVector2;
class hkaiSpatialQueryHitFilter;
class HavokCharacter;
class EdgePathNode;
class EdgeCache;
class HavokCharacterMessage;
class NavMeshSeeds;

// TODO templates
template<typename T>
class MessageQueue
{
public:
    struct Node
    {
        T value; // 0x0 Member
        Node* next; // 0x8 Member
        // no_addr void Node(struct HavokCharacterMessage * const & _a1);// public missing arg names
    };
    int s; // 0x0 Member
    Node* root; // 0x8 Member
    Node* split; // 0x10 Member
    Node* back; // 0x18 Member
    boost::shared_mutex mutex; // 0x20 Member
    // no_addr void MessageQueue<HavokCharacterMessage *>(const class MessageQueue<HavokCharacterMessage *> & _a1);// public missing arg names
    // no_addr void MessageQueue<HavokCharacterMessage *>();// public
    // no_addr void ~MessageQueue<HavokCharacterMessage *>();// public
    // no_addr void push(struct HavokCharacterMessage * const & _a1);// public missing arg names
    // no_addr struct HavokCharacterMessage * pop();// public
    // no_addr bool empty();// public
    // no_addr int size();// public
    // no_addr class MessageQueue<HavokCharacterMessage *> & operator=(const class MessageQueue<HavokCharacterMessage *> & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class NavMeshSector;
class NavInstance;
class NavMeshGenerator;
class hkaiAstarEdgeFilter;

class NavMesh : public ThreadClass
{
public:
    // ThreadClass offset = 0x0, length = 0x88
    // no_addr void NavMesh(const class NavMesh & _a1);// public missing arg names
    NavMesh();// public RVA = 0x880230
    NavMesh* _CONSTRUCTOR();// public RVA = 0x880230
    enum State
    {
        MISSING,
        ORIGINAL,
        MODIFIED,
        LOADING,
        GENERATING
    };

    hkaiWorld* world; // 0x88 Member
    void initialise();// public RVA = 0x3ABA80
    void shutdown();// public RVA = 0x3AAAB0
    void create(ZoneMap* zone);// public RVA = 0x3ABB20
    void unload(ZoneMap* zone);// public RVA = 0x3A4020
    void generate(const hand& building);// public RVA = 0x3ABA00
    void generate(const Ogre::Aabb& box);// public RVA = 0x3A61A0
    void generate(ZoneMap* zone);// public RVA = 0x3AB320
    void destroy(Building* b);// public RVA = 0x3A40C0
    bool isLoaded(const iVector2& zone);// public RVA = 0x3AB110
    bool isLoaded(ZoneMap* zone);// public RVA = 0x3AC430
    Ogre::Vector3 getZoneEdge(const Ogre::Vector3& start, const Ogre::Vector3& target, float offset);// public RVA = 0x3A35E0
    int getClosestPoint(const Ogre::Vector3& point, float radius, float inset, hkaiSpatialQueryHitFilter* filter, Ogre::Vector3& out, unsigned int& key);// public RVA = 0x3A1DE0
    int getClosestPoint(const Ogre::Vector3& point, float radius, float inset, bool water, Ogre::Vector3& out, unsigned int& key);// public RVA = 0x3A2A80
    int getClosestPoint(const Ogre::Vector3& point, float radius, float inset, bool water, Ogre::Vector3& out);// public RVA = 0x3A35A0
    int getClosestExteriorPoint(const Ogre::Vector3& point, float radius, float inset, Ogre::Vector3& out);// public RVA = 0x3A2B70
    void setDoorState(Building* door, bool open);// public RVA = 0x3A5B50
    int getGateCode(const HavokCharacter* c);// public RVA = 0x3A3010
    int getGateCode(const Ogre::Vector3& point);// public RVA = 0x3A2BD0
    bool isInterior(unsigned int key);// public RVA = 0x3A2110
    const hand& getHandle(unsigned int key);// public RVA = 0x3A3EA0
    unsigned int getFaceKey(const hkVector4f& local, float limit) const;// private RVA = 0x3A18D0
    unsigned int getFaceKey(const Ogre::Vector3& point);// public RVA = 0x3A2230
    bool getPositionValid(const Ogre::Vector3& point);// public RVA = 0x3A2410
    int getClosestBoundary(unsigned int face, const hkVector4f& point, float radius, EdgePathNode& edge);// public RVA = 0x3A2710
    int projectToNavMesh(hkVector4f& point, unsigned int& key, float limit);// public RVA = 0x3A1B90
    int getEdgesAroundPoint(unsigned int edgeKey, int side, unsigned int targetFaceKey, hkArray<EdgePathNode, hkContainerHeapAllocator>& out);// public RVA = 0x3A9D60
    int areEdgesConnected(const EdgePathNode& a, const EdgePathNode& b, int side);// public RVA = 0x3A2490
    int checkLineOfSight(HavokCharacter* a, const Ogre::Vector3& target);// public RVA = 0x3A5380
    int checkLineOfSight(HavokCharacter* a, HavokCharacter* b);// public RVA = 0x3A51C0
    int checkCollision(unsigned int face, hkVector4f& pos, hkVector4f& move, float& out, unsigned int& outKey);// public RVA = 0x3A4F40
    bool pathExists(unsigned int startKey, unsigned int goalKey);// private RVA = 0x3A5720
    int pathExists(HavokCharacter* c, const Ogre::Vector3& target);// public RVA = 0x3A5960
    // no_addr int fillEdgeCache(unsigned int _a1, const class hkVector4f & _a2, const class hkVector4f & _a3, float _a4, struct EdgeCache & _a5);// public missing arg names
    int fillEdgeCache(unsigned int faceKey, const hkVector4f& point, float radius, EdgeCache& cache);// public RVA = 0x3A4AB0
    int isWater(const hkArray<EdgePathNode, hkContainerHeapAllocator>& path, int start, int end);// public RVA = 0x3A1980
    bool isCharacterStuck(const hkVector4f& position, unsigned int key, float radius, float threshold) const;// public RVA = 0x3A4960
    void postMessage(HavokCharacterMessage* m, bool hi);// public RVA = 0x3AAB10
    void cancelMessage(HavokCharacterMessage* m);// public RVA = 0x3AABA0
    void processCompletedCharacterMessages();// public RVA = 0x661D70
    void processDoorRequests();// public RVA = 0x3ABED0
    std::string getPolygonID(const Ogre::Vector3& p);// public RVA = 0x3A9740
    bool validateFaceKey(unsigned int key) const;// public RVA = 0x3A1B30
    bool isGenerating() const;// public RVA = 0x3A1080
    NavMeshSeeds& getSeedData() const;// public RVA = 0x3A10A0
    Ogre::Vector3 getWorldShift() const;// public RVA = 0x3A18A0
    boost::shared_mutex shiftMutex; // 0x90 Member
    bool worldShiftEnabled; // 0xB0 Member
    virtual unsigned long threadProc() override;// private RVA = 0x3AEBD0 vtable offset = 0x0
    unsigned long _NV_threadProc();// private RVA = 0x3AEBD0 vtable offset = 0x0
    bool update();// private RVA = 0x3ADF70
    void setupHavok();// private RVA = 0x3AC080
    void shutdownHavok();// private RVA = 0x3A1410
    // no_addr void processCharacterMessages();// private
    enum MessageType
    {
        CREATE,
        DESTROY,
        DESTROY_BUILDING,
        DOOR_OPEN,
        DOOR_CLOSE
    };

    struct BuildingInfo
    {
        hand handle; // 0x0 Member
        unsigned int hash; // 0x20 Member
        Ogre::Aabb bounds; // 0x24 Member
        std::string name; // 0x40 Member
        BuildingInfo(const NavMesh::BuildingInfo& __that);// public RVA = 0x3BCE90
        BuildingInfo* _CONSTRUCTOR(const NavMesh::BuildingInfo& __that);// public RVA = 0x3BCE90
        BuildingInfo();// public RVA = 0x3B9890
        BuildingInfo* _CONSTRUCTOR();// public RVA = 0x3B9890
        ~BuildingInfo();// public RVA = 0x3B98F0
        void _DESTRUCTOR();// public RVA = 0x3B98F0
        NavMesh::BuildingInfo& operator=(const NavMesh::BuildingInfo& __that);// public RVA = 0x3BD860
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    // Typedef        : BuildingList
    struct NavMeshMessage
    {
        NavMesh::MessageType message; // 0x0 Member
        ZoneMap* zone; // 0x8 Member
        hand handle; // 0x10 Member
        unsigned int hash; // 0x30 Member
        Ogre::Aabb bounds; // 0x34 Member
        lektor<NavMesh::BuildingInfo> interiors; // 0x50 Member
        NavMesh::NavMeshMessage* next; // 0x68 Member
        // no_addr void NavMeshMessage(const struct NavMesh::NavMeshMessage & _a1);// public missing arg names
        NavMeshMessage();// public RVA = 0x3BCE40
        NavMeshMessage* _CONSTRUCTOR();// public RVA = 0x3BCE40
        ~NavMeshMessage();// public RVA = 0x3BCF40
        void _DESTRUCTOR();// public RVA = 0x3BCF40
        // no_addr struct NavMesh::NavMeshMessage & operator=(const struct NavMesh::NavMeshMessage & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    MessageQueue<HavokCharacterMessage*> characterMessages; // 0xB8 Member
    MessageQueue<HavokCharacterMessage*> completedMessages; // 0xF8 Member
    MessageQueue<NavMesh::NavMeshMessage*> navMessages; // 0x138 Member
    MessageQueue<ZoneMap*> doorRequests; // 0x178 Member
    hkArray<HavokCharacterMessage*, hkContainerHeapAllocator> pathRequests; // 0x1B8 Member
    enum FileMode
    {
        AUTO,
        BASE,
        USER
    };

    static std::string getFilename(const ZoneMap* zone, NavMesh::FileMode source, bool write);// private RVA = 0x3A5E50
    NavMeshSector* loadZone(const ZoneMap* zone, const std::string& file);// private RVA = 0x3A7B30
    int saveZone(NavMeshSector* s, const std::string& file);// private RVA = 0x3A6A20
    bool createZoneInstance(ZoneMap* zone, NavMeshSector* sector, const lektor<NavMesh::BuildingInfo>& buildings);// private RVA = 0x3AD420
    void deleteMesh(NavMeshSector* s);// private RVA = 0x3AC4D0
    void deleteMesh(NavInstance* s);// private RVA = 0x3AC460
    int createZone(ZoneMap* zone, unsigned int hash, const lektor<NavMesh::BuildingInfo>& interiors);// private RVA = 0x3ADB50
    void unloadZone(ZoneMap* zone);// private RVA = 0x3ACDE0
    void unloadBuilding(hand h);// private RVA = 0x3AD220
    // no_addr void generateBT(class ZoneMap * _a1, unsigned int _a2, const class lektor<NavMesh::BuildingInfo> & _a3);// private missing arg names
    NavMeshSector* getSector(const iVector2& index, bool create);// private RVA = 0x3AAE10
    NavMeshSector* getSector(int x, int y, bool create);// private RVA = 0x3AC400
    NavInstance* getInterior(const hand& building, bool create);// private RVA = 0x3AAF30
    bool removeSector(NavMeshSector* s);// private RVA = 0x3AB070
    int getSectors(NavInstance* interior, lektor<NavMeshSector*>& list, bool create);// private RVA = 0x3AC620
    void createInstance(NavInstance* n);// private RVA = 0x3AC940
    void deleteInstance(NavInstance* n);// private RVA = 0x3AB4C0
    int countInteriors(const iVector2& zone) const;// private RVA = 0x3A1470
    static unsigned int getUID(const hand& building);// private RVA = 0x3A1060
    static unsigned int getUID(const iVector2& zone);// private RVA = 0x3A1050
    static unsigned int hashBuilding(Building* b);// private RVA = 0x3A1560
    static unsigned int hashInterior(Building* b);// private RVA = 0x3AAC20
    static unsigned int hashZone(ZoneMap* z);// private RVA = 0x3A1790
    void shiftWorld(const hkVector4f& pos);// protected RVA = 0x3AB7A0
    // no_addr void initialiseDoorStates(class ZoneMap * _a1, struct NavInstance * _a2);// protected missing arg names
    void changeDoorState(const Ogre::Aabb& box, bool open, NavInstance* s);// protected RVA = 0x3A64E0
    bool validateStreamingData(NavInstance* instance);// protected RVA = 0x3A8610
    void shiftEdgePath(hkArray<EdgePathNode, hkContainerHeapAllocator>& path, const hkVector4f& shift) const;// protected RVA = 0x3A23C0
    bool directPath(unsigned int startKey, const hkVector4f& start, hkVector4f& goal, float radius, bool water, hkArray<EdgePathNode, hkContainerHeapAllocator>& out);// private RVA = 0x3AA570
    bool findPath(unsigned int startKey, const hkVector4f& start, unsigned int goalKey, const hkVector4f& goal, float radius, float water, bool heirachical, hkArray<EdgePathNode, hkContainerHeapAllocator>& out);// private RVA = 0x3AA810
    unsigned int resolvePoint(const hkVector4f& point, const hand& building, float radius, float search, hkVector4f& output) const;// private RVA = 0x3A4190
    int createEdgePath(unsigned int faceKey, hkArray<unsigned int, hkContainerHeapAllocator>& list, hkArray<EdgePathNode, hkContainerHeapAllocator>& out);// private RVA = 0x3A9B40
    int getClearance(unsigned int faceKey, unsigned int edgeKey, float& left, float& right, float& mcp);// private RVA = 0x3A8E90
    // no_addr int getBoundaries(unsigned int _a1, const class hkVector4f & _a2, float _a3, class hkArray<EdgePathNode,hkContainerHeapAllocator> & _a4);// private missing arg names
    int findEdges(unsigned int faceKey, const hkVector4f& point, float radius, hkArray<unsigned int, hkContainerHeapAllocator>& edges) const;// private RVA = 0x3A3990
    bool running; // 0x1C8 Member
    float worldX; // 0x1CC Member
    float worldY; // 0x1D0 Member
    float cellSize; // 0x1D4 Member
    hkVector4f* worldShift; // 0x1D8 Member
    boost::shared_mutex mutex; // 0x1E0 Member
    boost::shared_mutex changeMutex; // 0x200 Member
    std::map<iVector2, NavMeshSector*, std::less<iVector2>, Ogre::STLAllocator<std::pair<iVector2 const, NavMeshSector*>, Ogre::GeneralAllocPolicy > > sectors; // 0x220 Member
    std::map<hand, NavInstance*, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, NavInstance*>, Ogre::GeneralAllocPolicy > > interiors; // 0x248 Member
    lektor<NavInstance*> addList; // 0x270 Member
    hkaiAstarEdgeFilter* edgeFilter; // 0x288 Member
    NavMeshGenerator* generator; // 0x290 Member
    lektor<ZoneMap*> deferredList; // 0x298 Member
    hkArray<int, hkContainerHeapAllocator> removed; // 0x2B0 Member
    virtual ~NavMesh();// public RVA = 0x8805E0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x8805E0 vtable offset = 0x0
    // no_addr class NavMesh & operator=(const class NavMesh & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};