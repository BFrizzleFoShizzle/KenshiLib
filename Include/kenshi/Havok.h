#pragma once

#include <xmmintrin.h>

class hkSimdFloat32;

class hkVector4fComparison
{
public:
    // no_addr static void * operator new(unsigned __int64 _a1, void * _a2);// public missing arg names
    // no_addr static void * operator new(unsigned __int64 _a1);// public missing arg names
    // no_addr static void operator delete(void * _a1, void * _a2);// public missing arg names
    // no_addr static void operator delete(void * _a1, unsigned __int64 _a2);// public missing arg names
    // no_addr static void * operator new[](unsigned __int64 _a1, void * _a2);// public missing arg names
    // no_addr static void operator delete[](void * _a1, void * _a2);// public missing arg names
    class MustEndWithSemiColon
    {
    public:
    };
    enum Mask
    {
        INDEX_W = 0x3,
        INDEX_Z = 0x2,
        INDEX_Y = 0x1,
        INDEX_X = 0x0,
        MASK_NONE = 0x0,
        MASK_W = 0x8,
        MASK_Z = 0x4,
        MASK_ZW = 0xC,
        MASK_Y = 0x2,
        MASK_YW = 0xA,
        MASK_YZ = 0x6,
        MASK_YZW = 0xE,
        MASK_X = 0x1,
        MASK_XW = 0x9,
        MASK_XZ = 0x5,
        MASK_XZW = 0xD,
        MASK_XY = 0x3,
        MASK_XYW = 0xB,
        MASK_XYZ = 0x7,
        MASK_XYZW = 0xF
    };

    static const hkVector4fComparison convert(const union __m128& x);// public RVA = 0x14A440
    static Mask getMaskForComponent(int i);// public RVA = 0xDCE220
    int getIndexOfLastComponentSet() const;// public RVA = 0x3D1E10
    int getIndexOfFirstComponentSet() const;// public RVA = 0xC637D0
    void setAnd(const hkVector4fComparison& a, const hkVector4fComparison& b);// public RVA = 0x3D1DF0
    void setAndNot(const hkVector4fComparison& a, const hkVector4fComparison& b);// public RVA = 0xC63500
    void setXor(const hkVector4fComparison& a, const hkVector4fComparison& b);// public RVA = 0xCCD8E0
    void setOr(const hkVector4fComparison& a, const hkVector4fComparison& b);// public RVA = 0xCA93A0
    void setNot(const hkVector4fComparison& a);// public RVA = 0xC63510
    void setSelect(const hkVector4fComparison& comp, const hkVector4fComparison& trueValue, const hkVector4fComparison& falseValue);// public RVA = 0xCCD970
    void set(Mask m);// public RVA = 0x14A450
    unsigned int allAreSet() const;// public RVA = 0xC49130
    // no_addr unsigned int allAreSet(enum hkVector4ComparisonMask::Mask _a1);// public missing arg names
    unsigned int anyIsSet() const;// public RVA = 0x14A470
    unsigned int anyIsSet(Mask m) const;// public RVA = 0xE25EC0
    Mask getMask(Mask m) const;// public RVA = 0xDEEAA0
    Mask getMask() const;// public RVA = 0x3D1E00
    // no_addr static unsigned int getCombinedMask(const class hkVector4fComparison & _a1, const class hkVector4fComparison & _a2, const class hkVector4fComparison & _a3);// public missing arg names
    union __m128 m_mask; // 0x0 Member
};

class hkQuaternionf;
class hkMatrix3f;
class hkQTransformf;
class hkQsTransformf;
class hkTransformf;

enum hkVectorConstant
{
    HK_QUADREAL_BEGIN,
    HK_QUADREAL_MINUS1,
    HK_QUADREAL_0,
    HK_QUADREAL_1,
    HK_QUADREAL_2,
    HK_QUADREAL_3,
    HK_QUADREAL_4,
    HK_QUADREAL_5,
    HK_QUADREAL_6,
    HK_QUADREAL_7,
    HK_QUADREAL_8,
    HK_QUADREAL_15,
    HK_QUADREAL_16,
    HK_QUADREAL_255,
    HK_QUADREAL_256,
    HK_QUADREAL_2_POW_23,
    HK_QUADREAL_INV_0,
    HK_QUADREAL_INV_1,
    HK_QUADREAL_INV_2,
    HK_QUADREAL_INV_3,
    HK_QUADREAL_INV_4,
    HK_QUADREAL_INV_5,
    HK_QUADREAL_INV_6,
    HK_QUADREAL_INV_7,
    HK_QUADREAL_INV_8,
    HK_QUADREAL_INV_15,
    HK_QUADREAL_INV_127,
    HK_QUADREAL_INV_226,
    HK_QUADREAL_INV_255,
    HK_QUADREAL_1000,
    HK_QUADREAL_0100,
    HK_QUADREAL_0010,
    HK_QUADREAL_0001,
    HK_QUADREAL_MAX,
    HK_QUADREAL_HIGH,
    HK_QUADREAL_EPS,
    HK_QUADREAL_EPS_SQRD,
    HK_QUADREAL_MIN,
    HK_QUADREAL_MINUS_MAX,
    HK_QUADREAL_MINUS_MIN,
    HK_QUADREAL_m11m11,
    HK_QUADREAL_1m11m1,
    HK_QUADREAL_1010,
    HK_QUADREAL_1100,
    HK_QUADREAL_0011,
    HK_QUADREAL_1248,
    HK_QUADREAL_8421,
    HK_QUADREAL_PACK_HALF,
    HK_QUADREAL_PACK16_UNIT_VEC,
    HK_QUADREAL_UNPACK16_UNIT_VEC,
    HK_QUADREAL_PI,
    HK_QUADREAL_PI_HALF,
    HK_QUADREAL_PI_QUARTER,
    HK_QUADREAL_FOUR_PI_THIRD,
    HK_QUADREAL_TWO_PI,
    HK_QUADREAL_FOUR_PI,
    HK_QUADREAL_DEG2RAD,
    HK_QUADREAL_RAD2DEG,
    HK_QUADREAL_END
};

class hkBool
{
public:
    // Typedef        : CompileTimeTrueType
    // Typedef        : CompileTimeFalseType
    hkBool(bool b);// public RVA = 0x143DA0
    hkBool* _CONSTRUCTOR(bool b);// public RVA = 0x143DA0
    hkBool();// public RVA = 0xBAAF20
    hkBool* _CONSTRUCTOR();// public RVA = 0xBAAF20
    operator bool() const;// public RVA = 0x143DB0
    hkBool operator==(bool e) const;// public RVA = 0xBAE3B0
    hkBool operator!=(bool e) const;// public RVA = 0x3B2450
    char m_bool; // 0x0 Member
};

class hkVector4f
{
public:
    // no_addr static void * operator new(unsigned __int64 _a1, void * _a2);// public missing arg names
    static void* operator new(unsigned __int64 nbytes);// public RVA = 0x3B4480
    // no_addr static void operator delete(void * _a1, void * _a2);// public missing arg names
    static void operator delete(void* p, unsigned __int64 nbytes);// public RVA = 0x3B44B0
    // no_addr static void * operator new[](unsigned __int64 _a1, void * _a2);// public missing arg names
    // no_addr static void operator delete[](void * _a1, void * _a2);// public missing arg names
    class MustEndWithSemiColon
    {
    public:
    };
    // no_addr char operator==(const struct hkTrait::TraitBool<1> & _a1);// public missing arg names
    hkVector4f(const hkVector4f& v);// public RVA = 0x14A290
    hkVector4f* _CONSTRUCTOR(const hkVector4f& v);// public RVA = 0x14A290
    // no_addr void hkVector4f(const union __m128 & _a1);// public missing arg names
    hkVector4f(float a, float b, float c, float d);// public RVA = 0x14A260
    hkVector4f* _CONSTRUCTOR(float a, float b, float c, float d);// public RVA = 0x14A260
    hkVector4f();// public RVA = 0x14A240
    hkVector4f* _CONSTRUCTOR();// public RVA = 0x14A240
    // no_addr void operator=(const union __m128 & _a1);// public missing arg names
    void operator=(const hkVector4f& v);// public RVA = 0x14A730
    void set(float a, float b, float c, float d);// public RVA = 0x14A2A0
    void set(const hkSimdFloat32& a, const hkSimdFloat32& b, const hkSimdFloat32& c, const hkSimdFloat32& d);// public RVA = 0xBC8F60
    void setAll(const float& a);// public RVA = 0x14A2C0
    void setAll(const hkSimdFloat32& a);// public RVA = 0x3D1DA0
    void setZero();// public RVA = 0x14A2D0
    void zeroComponent(const int i);// public RVA = 0xDEEA20
    void add(const hkVector4f& a);// public RVA = 0x14A740
    void sub(const hkVector4f& a);// public RVA = 0x14A750
    void mul(const hkSimdFloat32& s);// public RVA = 0x14A760
    void mul(const hkVector4f& a);// public RVA = 0xBB0EE0
    void div(const hkVector4f& a);// public RVA = 0xD1FFB0
    void setAdd(const hkVector4f& v0, const hkSimdFloat32& v1);// public RVA = 0x3D1DB0
    void setAdd(const hkVector4f& v0, const hkVector4f& v1);// public RVA = 0x14A2E0
    void setSub(const hkVector4f& v0, const hkSimdFloat32& v1);// public RVA = 0x3D1DC0
    void setSub(const hkVector4f& v0, const hkVector4f& v1);// public RVA = 0x14A2F0
    void setMul(const hkSimdFloat32& r, const hkVector4f& v1);// public RVA = 0x14A770
    void setMul(const hkVector4f& v1, const hkSimdFloat32& r);// public RVA = 0x14A300
    void setMul(const hkVector4f& v0, const hkVector4f& v1);// public RVA = 0xBB0ED0
    void setDiv(const hkVector4f& v0, const hkVector4f& v1);// public RVA = 0xD1FF90
    void setReciprocal(const hkVector4f& a);// public RVA = 0xDEF5B0
    void setSqrt(const hkVector4f& a);// public RVA = 0xD214D0
    void setSqrtInverse(const hkVector4f& a);// public RVA = 0xD21510
    void addMul(const hkSimdFloat32& r, const hkVector4f& v1);// public RVA = 0xBC3990
    void addMul(const hkVector4f& v1, const hkSimdFloat32& r);// public RVA = 0x14A7A0
    void addMul(const hkVector4f& x, const hkVector4f& y);// public RVA = 0xD1F350
    void setAddMul(const hkVector4f& a, const hkVector4f& b, const hkSimdFloat32& r);// public RVA = 0x14A330
    void setAddMul(const hkVector4f& a, const hkVector4f& x, const hkVector4f& y);// public RVA = 0xBEA1A0
    void subMul(const hkSimdFloat32& r, const hkVector4f& a);// public RVA = 0xBC6860
    void subMul(const hkVector4f& v1, const hkSimdFloat32& r);// public RVA = 0x14A7C0
    void subMul(const hkVector4f& x, const hkVector4f& y);// public RVA = 0xD1F360
    void setSubMul(const hkVector4f& a, const hkVector4f& b, const hkSimdFloat32& r);// public RVA = 0x14A310
    void setSubMul(const hkVector4f& a, const hkVector4f& x, const hkVector4f& y);// public RVA = 0xC5F0C0
    void setCross(const hkVector4f& v0, const hkVector4f& v1);// public RVA = 0x14A350
    void setInterpolate(const hkVector4f& v0, const hkVector4f& v1, const hkSimdFloat32& t);// public RVA = 0x14A780
    const hkVector4fComparison less(const hkVector4f& a) const;// public RVA = 0xC63CD0
    const hkVector4fComparison lessEqual(const hkVector4f& a) const;// public RVA = 0x14AED0
    const hkVector4fComparison greater(const hkVector4f& a) const;// public RVA = 0xC55C50
    const hkVector4fComparison greaterEqual(const hkVector4f& a) const;// public RVA = 0x3D4080
    const hkVector4fComparison equal(const hkVector4f& a) const;// public RVA = 0x14AEB0
    const hkVector4fComparison notEqual(const hkVector4f& a) const;// public RVA = 0xC63CC0
    const hkVector4fComparison lessZero() const;// public RVA = 0xDCE340
    const hkVector4fComparison lessEqualZero() const;// public RVA = 0xCFA740
    const hkVector4fComparison greaterZero() const;// public RVA = 0xD1FF60
    const hkVector4fComparison greaterEqualZero() const;// public RVA = 0xC79470
    const hkVector4fComparison equalZero() const;// public RVA = 0x14AEF0
    const hkVector4fComparison notEqualZero() const;// public RVA = 0xD1FF70
    // no_addr const class hkVector4fComparison signBitSet();// public
    // no_addr const class hkVector4fComparison signBitClear();// public
    void setSelect(const hkVector4fComparison& comp, const hkVector4f& trueValue, const hkVector4f& falseValue);// public RVA = 0x14A380
    void zeroIfFalse(const hkVector4fComparison& comp);// public RVA = 0xBC8F80
    void zeroIfTrue(const hkVector4fComparison& comp);// public RVA = 0xC78AD0
    void setFlipSign(const hkVector4f& v, const hkSimdFloat32& sSign);// public RVA = 0xBC6760
    void setFlipSign(const hkVector4f& v, const hkVector4f& vSign);// public RVA = 0xD1F300
    void setFlipSign(const hkVector4f& v, const hkVector4fComparison& mask);// public RVA = 0xDD4990
    void setAbs(const hkVector4f& v);// public RVA = 0x14A3C0
    void setMin(const hkVector4f& a, const hkVector4f& b);// public RVA = 0x3D1DD0
    void setMax(const hkVector4f& a, const hkVector4f& b);// public RVA = 0x3D1DE0
    // no_addr void setClamped(const class hkVector4f & _a1, const class hkSimdFloat32 & _a2);// public missing arg names
    void setClamped(const hkVector4f& a, const hkVector4f& minVal, const hkVector4f& maxVal);// public RVA = 0xC55C60
    void setClampedZeroOne(const hkVector4f& a);// public RVA = 0xD1F2D0
    void setClampedToMaxLength(const hkVector4f& vSrc, const hkSimdFloat32& constMaxLen);// public RVA = 0x14C730
    void setRotatedDir(const hkQuaternionf& quat, const hkVector4f& direction);// public RVA = 0xBB0DD0
    void setRotatedDir(const hkMatrix3f& a, const hkVector4f& b);// public RVA = 0xBB0A40
    void setRotatedInverseDir(const hkQuaternionf& quat, const hkVector4f& direction);// public RVA = 0xBB0E50
    void setRotatedInverseDir(const hkMatrix3f& a, const hkVector4f& b);// public RVA = 0xBB0A80
    void setTransformedPos(const hkQTransformf& a, const hkVector4f& b);// public RVA = 0xBB0CB0
    void setTransformedPos(const hkQsTransformf& a, const hkVector4f& b);// public RVA = 0xBB0B80
    void setTransformedPos(const hkTransformf& a, const hkVector4f& b);// public RVA = 0xBB0AE0
    void setTransformedInversePos(const hkQTransformf& a, const hkVector4f& b);// public RVA = 0xBB0D40
    void setTransformedInversePos(const hkQsTransformf& a, const hkVector4f& b);// public RVA = 0xBB0C10
    void setTransformedInversePos(const hkTransformf& a, const hkVector4f& b);// public RVA = 0xBB0B20
    void _setRotatedDir(const hkQuaternionf& quat, const hkVector4f& direction);// public RVA = 0xBB1000
    void _setRotatedDir(const hkMatrix3f& r, const hkVector4f& b);// public RVA = 0x2FA7C0
    void _setRotatedInverseDir(const hkQuaternionf& quat, const hkVector4f& direction);// public RVA = 0xBB1080
    void _setRotatedInverseDir(const hkMatrix3f& r, const hkVector4f& b);// public RVA = 0xBB0FA0
    void _setTransformedPos(const hkQTransformf& a, const hkVector4f& b);// public RVA = 0xBB1290
    void _setTransformedPos(const hkQsTransformf& a, const hkVector4f& b);// public RVA = 0xBB1160
    void _setTransformedPos(const hkTransformf& t, const hkVector4f& b);// public RVA = 0x2FA800
    void _setTransformedInversePos(const hkQTransformf& a, const hkVector4f& b);// public RVA = 0xBB1310
    void _setTransformedInversePos(const hkQsTransformf& a, const hkVector4f& b);// public RVA = 0xBB11F0
    void _setTransformedInversePos(const hkTransformf& a, const hkVector4f& b);// public RVA = 0xBB1100
    void setPlaneConstant(const hkVector4f& p);// public RVA = 0xCF26A0
    const hkSimdFloat32 dot4xyz1(const hkVector4f& a) const;// public RVA = 0xCF2670
    const hkSimdFloat32 distanceTo(const hkVector4f& p) const;// public RVA = 0x3B77F0
    const hkSimdFloat32 distanceToSquared(const hkVector4f& p) const;// public RVA = 0x14BAD0
    void setXYZ_W(const hkVector4f& xyz, const hkSimdFloat32& w);// public RVA = 0xBC6720
    void setXYZ_W(const hkVector4f& xyz, const hkVector4f& w);// public RVA = 0xC556B0
    void setW(const hkSimdFloat32& w);// public RVA = 0xC78F90
    void setW(const hkVector4f& w);// public RVA = 0xDBF780
    // no_addr void setXYZ(const class hkSimdFloat32 & _a1);// public missing arg names
    void setXYZ(float v);// public RVA = 0x1044DE0
    void setXYZ(const hkVector4f& xyz);// public RVA = 0xBC3970
    void setXYZ_0(const hkVector4f& xyz);// public RVA = 0xBC6740
    // no_addr void addXYZ(const class hkVector4f & _a1);// public missing arg names
    // no_addr void subXYZ(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setBroadcastXYZ(const int _a1, const class hkVector4f & _a2);// public missing arg names
    void setInt24W(int value);// public RVA = 0xC78FE0
    int getInt24W() const;// public RVA = 0xC63790
    int getInt16W() const;// public RVA = 0xD1F380
    const float& operator()(int a) const;// public RVA = 0x14A3F0
    float& operator()(int a);// public RVA = 0x14A3E0
    const hkSimdFloat32 getComponent(const int I) const;// public RVA = 0x14AF40
    const hkSimdFloat32 getW() const;// public RVA = 0xC64400
    // no_addr float * getComponentAddress(int _a1);// public missing arg names
    // no_addr const float * getComponentAddress(int _a1);// public missing arg names
    void setComponent(const int I, const hkSimdFloat32& val);// public RVA = 0x14AF90
    // no_addr void broadcast(int _a1);// public missing arg names
    // no_addr void setBroadcast(const class hkVector4f & _a1, int _a2);// public missing arg names
    // no_addr void setBroadcast(const int _a1, const class hkVector4f & _a2);// public missing arg names
    static const hkVector4f& getZero();// public RVA = 0xBCE9D0
    static const hkVector4f& getConstant(hkVectorConstant vectorConstant);// public RVA = 0xDCE200
    // no_addr void reduceToHalfPrecision();// public
    union __m128 m_quad; // 0x0 Member
    // no_addr const union __m128 & getQuad();// public
    // no_addr union __m128 & getQuad();// public
    // no_addr void add4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void sub4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void mul4(const class hkSimdFloat32 & _a1);// public missing arg names
    // no_addr void mul4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void div4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void div4fast(const class hkVector4f & _a1);// public missing arg names
    hkSimdFloat32 dot3(const hkVector4f& v) const;// public RVA = 0x14B0C0
    // no_addr class hkSimdFloat32 dot4(const class hkVector4f & _a1);// public missing arg names
    // no_addr float dot3fpu(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setMul4(const class hkSimdFloat32 & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setMul4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void _setMul3(const class hkMatrix3f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setMul3(const class hkMatrix3f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void subMul4(const class hkSimdFloat32 & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void subMul4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setSubMul4(const class hkVector4f & _a1, const class hkVector4f & _a2, const class hkSimdFloat32 & _a3);// public missing arg names
    // no_addr void setSubMul4(const class hkVector4f & _a1, const class hkVector4f & _a2, const class hkVector4f & _a3);// public missing arg names
    // no_addr void setDot3(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setDot4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setSelect4(const class hkVector4fComparison & _a1, const class hkVector4f & _a2, const class hkVector4f & _a3);// public missing arg names
    // no_addr void select32(const class hkVector4f & _a1, const class hkVector4f & _a2, const class hkVector4fComparison & _a3);// public missing arg names
    // no_addr void setBroadcast3clobberW(const class hkVector4f & _a1, int _a2);// public missing arg names
    // no_addr void setXYZW(const class hkVector4f & _a1, const class hkSimdFloat32 & _a2);// public missing arg names
    // no_addr void setXYZW(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setXYZ0(const class hkVector4f & _a1);// public missing arg names
    // no_addr void addMul4(const class hkSimdFloat32 & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void addMul4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    void setZero4();// public RVA = 0x14A7E0
    // no_addr void zeroElement(int _a1);// public missing arg names
    // no_addr void setAll3(float _a1);// public missing arg names
    // no_addr void setSwapXY(const class hkVector4f & _a1);// public missing arg names
    void setNeg3(const hkVector4f& v);// public RVA = 0x14A7F0
    // no_addr void setNeg4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setNegMask4(const class hkVector4f & _a1, int _a2);// public missing arg names
    // no_addr void setDiv4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setDiv4fast(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr class hkSimdFloat32 getSimdAt(int _a1);// public missing arg names
    void normalize3();// public RVA = 0x14D0F0
    // no_addr void normalize4();// public
    // no_addr void fastNormalize3();// public
    // no_addr void setFastNormalize3NonZero(const class hkVector4f & _a1);// public missing arg names
    hkSimdFloat32 normalizeWithLength3();// public RVA = 0x14C7C0
    // no_addr class hkSimdFloat32 normalizeWithLength4();// public
    // no_addr class hkSimdFloat32 fastNormalizeWithLength3();// public
    // no_addr void fastNormalize3NonZero();// public
    // no_addr struct hkResult normalize3IfNotZero();// public
    // no_addr class hkBool isNormalized3(float _a1);// public missing arg names
    // no_addr class hkBool isNormalized4(float _a1);// public missing arg names
    hkSimdFloat32 length3() const;// public RVA = 0x14C840
    // no_addr class hkSimdFloat32 length4();// public
    hkSimdFloat32 lengthSquared3() const;// public RVA = 0x14BB10
    // no_addr class hkSimdFloat32 lengthSquared4();// public
    // no_addr class hkSimdFloat32 lengthInverse3();// public
    // no_addr class hkSimdFloat32 lengthInverse4();// public
    // no_addr void setMulSigns4(const class hkVector4f & _a1, const class hkSimdFloat32 & _a2);// public missing arg names
    // no_addr void setMulSigns4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setAdd4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setSub4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setSqrtInverse4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setSqrtInverse4_7BitAccuracy(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setReciprocal3(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setReciprocal4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setAddMul4(const class hkVector4f & _a1, const class hkVector4f & _a2, const class hkSimdFloat32 & _a3);// public missing arg names
    // no_addr void setAddMul4(const class hkVector4f & _a1, const class hkVector4f & _a2, const class hkVector4f & _a3);// public missing arg names
    // no_addr void setAbs4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setMin4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void setMax4(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
    unsigned int equals3(const hkVector4f& v, float epsilon) const;// public RVA = 0x14B0F0
    // no_addr unsigned int equals4(const class hkVector4f & _a1, float _a2);// public missing arg names
    // no_addr class hkVector4fComparison compareEqual4(const class hkVector4f & _a1);// public missing arg names
    // no_addr class hkVector4fComparison compareLessThan4(const class hkVector4f & _a1);// public missing arg names
    // no_addr class hkVector4fComparison compareLessThanEqual4(const class hkVector4f & _a1);// public missing arg names
    // no_addr class hkVector4fComparison compareGreaterThan4(const class hkVector4f & _a1);// public missing arg names
    // no_addr class hkVector4fComparison compareGreaterThanEqual4(const class hkVector4f & _a1);// public missing arg names
    // no_addr class hkVector4fComparison compareLessThanZero4();// public
    // no_addr unsigned int allLessThan3(const class hkVector4f & _a1);// public missing arg names
    // no_addr unsigned int allLessThan4(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setInterpolate4(const class hkVector4f & _a1, const class hkVector4f & _a2, const class hkSimdFloat32 & _a3);// public missing arg names
    hkSimdFloat32 distanceTo3(const hkVector4f& p) const;// public RVA = 0x3B97D0
    hkSimdFloat32 distanceToSquared3(const hkVector4f& p) const;// public RVA = 0x14BB40
    // no_addr class hkSimdFloat32 horizontalAdd3();// public
    // no_addr void setHorizontalMax4(const class hkVector4f & _a1);// public missing arg names
    // no_addr class hkSimdFloat32 getHorizontalMin3();// public
    // no_addr class hkSimdFloat32 getHorizontalMax3();// public
    // no_addr void _setMul4xyz1(const class hkTransformf & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void add3clobberW(const class hkVector4f & _a1);// public missing arg names
    hkBool isOk3() const;// public RVA = 0x14A810
    hkBool isOk4() const;// public RVA = 0x14A830
    // no_addr const class hkVector4fComparison isNegative();// public
    // no_addr const class hkVector4fComparison isPositive();// public
    // no_addr void load3(const double * _a1);// public missing arg names
    // no_addr void load3(const float * _a1);// public missing arg names
    // no_addr void load4(const double * _a1);// public missing arg names
    // no_addr void load4(const float * _a1);// public missing arg names
    // no_addr void load4a(const double * _a1);// public missing arg names
    // no_addr void load4a(const float * _a1);// public missing arg names
    // no_addr void store3(double * _a1);// public missing arg names
    // no_addr void store3(float * _a1);// public missing arg names
    // no_addr void store4(double * _a1);// public missing arg names
    // no_addr void store4(float * _a1);// public missing arg names
    // no_addr void store4a(double * _a1);// public missing arg names
    // no_addr void store4a(float * _a1);// public missing arg names
    // no_addr void storeX(double * _a1);// public missing arg names
    // no_addr void storeX(float * _a1);// public missing arg names
    // no_addr class hkSimdFloat32 horizontalAdd4();// public
    // no_addr int getMaxElementIndex4();// public
    // no_addr int getMajorAxis3();// public
    // no_addr void storeUncached(void * _a1);// public missing arg names
    // no_addr void _setMul4(const class hkMatrix3f & _a1, const class hkVector4f & _a2);// public missing arg names
    // no_addr void sub3clobberW(const class hkVector4f & _a1);// public missing arg names
    // no_addr void setAnd(const class hkVector4f & _a1, const class hkVector4f & _a2);// public missing arg names
};

enum hkResultEnum
{
    HK_SUCCESS,
    HK_FAILURE
};

struct hkResult
{
    hkResult(hkResultEnum b);// public RVA = 0x143DC0
    hkResult* _CONSTRUCTOR(hkResultEnum b);// public RVA = 0x143DC0
    hkResult();// public RVA = 0xBF51F0
    hkResult* _CONSTRUCTOR();// public RVA = 0xBF51F0
    bool operator==(hkResultEnum e) const;// public RVA = 0xBA9150
    bool operator!=(hkResultEnum e) const;// public RVA = 0x2E9BC0
    unsigned int isSuccess() const;// public RVA = 0x3B2470
    hkResultEnum m_enum; // 0x0 Member
};

class hkMemorySnapshot;

class hkMemoryAllocator
{
public:
    // VTable         : (none)
    // no_addr static void * operator new(unsigned __int64 _a1, void * _a2);// public missing arg names
    static void operator delete(void* _a1, unsigned __int64 _a2);// public RVA = 0xBA2990 missing arg names
    // no_addr static void operator delete(void * _a1, void * _a2);// public missing arg names
    class MustEndWithSemiColon
    {
    public:
    };
    // Typedef        : MemoryWalkCallback
    struct MemoryStatistics
    {
        MemoryStatistics();// public RVA = 0xBB13B0
        MemoryStatistics* _CONSTRUCTOR();// public RVA = 0xBB13B0
        static const __int64 INFINITE_SIZE; // RVA = 0x1691B00 Static Member
        __int64 m_allocated; // 0x0 Member
        __int64 m_inUse; // 0x8 Member
        __int64 m_peakInUse; // 0x10 Member
        __int64 m_available; // 0x18 Member
        __int64 m_totalAvailable; // 0x20 Member
        __int64 m_largestBlock; // 0x28 Member
    };
    struct ExtendedInterface
    {
        // VTable         : (none)
        virtual ~ExtendedInterface();// public RVA = 0xBCA870 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0xBCA870 vtable offset = 0x0
        virtual void garbageCollect() = 0;// public vtable offset = 0x8
        virtual void incrementalGarbageCollect(int _a1) = 0;// public vtable offset = 0x10 missing arg names
        virtual hkResult setMemorySoftLimit(unsigned __int64 _a1) = 0;// public vtable offset = 0x18 missing arg names
        virtual unsigned __int64 getMemorySoftLimit() = 0;// public vtable offset = 0x20
        virtual bool canAllocTotal(int _a1) = 0;// public vtable offset = 0x28 missing arg names
        virtual hkResult walkMemory(void (*_a1)(void*, unsigned __int64, bool, int, void*), void* _a2) = 0;// public vtable offset = 0x30 missing arg names
        virtual unsigned __int64 getApproxTotalAllocated() = 0;// public vtable offset = 0x38
        virtual void setScrubValues(unsigned int _a1, unsigned int _a2) = 0;// public vtable offset = 0x40 missing arg names
        virtual int addToSnapshot(hkMemorySnapshot& _a1, int _a2) = 0;// public vtable offset = 0x48 missing arg names
        // no_addr void ExtendedInterface(const struct hkMemoryAllocator::ExtendedInterface & _a1);// public missing arg names
        ExtendedInterface();// public RVA = 0xBCAAC0
        ExtendedInterface* _CONSTRUCTOR();// public RVA = 0xBCAAC0
        // no_addr struct hkMemoryAllocator::ExtendedInterface & operator=(const struct hkMemoryAllocator::ExtendedInterface & _a1);// public missing arg names
        // no_addr void __local_vftable_ctor_closure();// public
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    virtual ~hkMemoryAllocator();// public RVA = 0xBA8CA0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0xBA8CA0 vtable offset = 0x0
    virtual void* blockAlloc(int _a1) = 0;// public vtable offset = 0x8 missing arg names
    virtual void blockFree(void* _a1, int _a2) = 0;// public vtable offset = 0x10 missing arg names
    virtual void* bufAlloc(int& reqBytesInOut);// public RVA = 0xBA8CC0 vtable offset = 0x18
    void* _NV_bufAlloc(int& reqBytesInOut);// public RVA = 0xBA8CC0 vtable offset = 0x18
    virtual void bufFree(void* p, int numBytes);// public RVA = 0xBA8CD0 vtable offset = 0x20
    void _NV_bufFree(void* p, int numBytes);// public RVA = 0xBA8CD0 vtable offset = 0x20
    virtual void* bufRealloc(void* pold, int oldNumBytes, int& reqBytesInOut);// public RVA = 0xBA8DC0 vtable offset = 0x28
    void* _NV_bufRealloc(void* pold, int oldNumBytes, int& reqBytesInOut);// public RVA = 0xBA8DC0 vtable offset = 0x28
    virtual void blockAllocBatch(void** ptrsOut, int numPtrs, int blockSize);// public RVA = 0xBA8CE0 vtable offset = 0x30
    void _NV_blockAllocBatch(void** ptrsOut, int numPtrs, int blockSize);// public RVA = 0xBA8CE0 vtable offset = 0x30
    virtual void blockFreeBatch(void** ptrsIn, int numPtrs, int blockSize);// public RVA = 0xBA8D50 vtable offset = 0x38
    void _NV_blockFreeBatch(void** ptrsIn, int numPtrs, int blockSize);// public RVA = 0xBA8D50 vtable offset = 0x38
    virtual void getMemoryStatistics(hkMemoryAllocator::MemoryStatistics& _a1) const = 0;// public vtable offset = 0x40 missing arg names
    virtual int getAllocatedSize(const void* _a1, int _a2) const = 0;// public vtable offset = 0x48 missing arg names
    virtual void resetPeakMemoryStatistics();// public RVA = 0xBA29A0 vtable offset = 0x50
    void _NV_resetPeakMemoryStatistics();// public RVA = 0xBA29A0 vtable offset = 0x50
    virtual hkMemoryAllocator::ExtendedInterface* getExtendedInterface();// public RVA = 0xBA29B0 vtable offset = 0x58
    hkMemoryAllocator::ExtendedInterface* _NV_getExtendedInterface();// public RVA = 0xBA29B0 vtable offset = 0x58
    enum MemoryState
    {
        MEMORY_STATE_OK,
        MEMORY_STATE_OUT_OF_MEMORY
    };

    // no_addr void hkMemoryAllocator(const class hkMemoryAllocator & _a1);// public missing arg names
    hkMemoryAllocator();// public RVA = 0xBA2980
    hkMemoryAllocator* _CONSTRUCTOR();// public RVA = 0xBA2980
    // no_addr class hkMemoryAllocator & operator=(const class hkMemoryAllocator & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

struct hkContainerHeapAllocator
{
    // no_addr static void * operator new(unsigned __int64 _a1, void * _a2);// public missing arg names
    // no_addr static void * operator new(unsigned __int64 _a1);// public missing arg names
    // no_addr static void operator delete(void * _a1, void * _a2);// public missing arg names
    // no_addr static void operator delete(void * _a1, unsigned __int64 _a2);// public missing arg names
    // no_addr static void * operator new[](unsigned __int64 _a1, void * _a2);// public missing arg names
    // no_addr static void operator delete[](void * _a1, void * _a2);// public missing arg names
    class MustEndWithSemiColon
    {
    public:
    };
    struct Allocator : public hkMemoryAllocator
    {
        // hkMemoryAllocator offset = 0x0, length = 0x8
        // no_addr static void * operator new(unsigned __int64 _a1, void * _a2);// public missing arg names
        // no_addr static void * operator new(unsigned __int64 _a1);// public missing arg names
        // no_addr static void operator delete(void * _a1, void * _a2);// public missing arg names
        static void operator delete(void* p, unsigned __int64 nbytes);// public RVA = 0xBA2F70
        // no_addr static void * operator new[](unsigned __int64 _a1, void * _a2);// public missing arg names
        // no_addr static void operator delete[](void * _a1, void * _a2);// public missing arg names
        class MustEndWithSemiColon
        {
        public:
        };
        virtual void* blockAlloc(int numBytes) override;// public RVA = 0xBA2D90 vtable offset = 0x0
        void* _NV_blockAlloc(int numBytes);// public RVA = 0xBA2D90 vtable offset = 0x0
        virtual void blockFree(void* p, int numBytes) override;// public RVA = 0xBA2DC0 vtable offset = 0x0
        void _NV_blockFree(void* p, int numBytes);// public RVA = 0xBA2DC0 vtable offset = 0x0
        virtual void* bufAlloc(int& reqNumBytesInOut) override;// public RVA = 0xBA2E00 vtable offset = 0x0
        void* _NV_bufAlloc(int& reqNumBytesInOut);// public RVA = 0xBA2E00 vtable offset = 0x0
        virtual void bufFree(void* p, int numBytes) override;// public RVA = 0xBA2E30 vtable offset = 0x0
        void _NV_bufFree(void* p, int numBytes);// public RVA = 0xBA2E30 vtable offset = 0x0
        virtual void* bufRealloc(void* pold, int oldNumBytes, int& reqNumBytesInOut) override;// public RVA = 0xBA2E70 vtable offset = 0x0
        void* _NV_bufRealloc(void* pold, int oldNumBytes, int& reqNumBytesInOut);// public RVA = 0xBA2E70 vtable offset = 0x0
        virtual void getMemoryStatistics(hkMemoryAllocator::MemoryStatistics& u) const override;// public RVA = 0xBA2EC0 vtable offset = 0x0
        void _NV_getMemoryStatistics(hkMemoryAllocator::MemoryStatistics& u) const;// public RVA = 0xBA2EC0 vtable offset = 0x0
        virtual int getAllocatedSize(const void* obj, int nbytes) const override;// public RVA = 0xBA2EF0 vtable offset = 0x0
        int _NV_getAllocatedSize(const void* obj, int nbytes) const;// public RVA = 0xBA2EF0 vtable offset = 0x0
        // no_addr void Allocator(const struct hkContainerHeapAllocator::Allocator & _a1);// public missing arg names
        Allocator();// public RVA = 0xBA2A20
        Allocator* _CONSTRUCTOR();// public RVA = 0xBA2A20
        virtual ~Allocator();// public RVA = 0xBA2A30 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0xBA2A30 vtable offset = 0x0
        // no_addr struct hkContainerHeapAllocator::Allocator & operator=(const struct hkContainerHeapAllocator::Allocator & _a1);// public missing arg names
        // no_addr void __local_vftable_ctor_closure();// public
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    static hkContainerHeapAllocator::Allocator s_alloc; // RVA = 0x21024E8 Static Member
    hkMemoryAllocator& get(const void* _a1);// public RVA = 0x143DF0 missing arg names
};

// ???
namespace hkTrait
{
    template<int i>
    struct TraitBool
    {
        // Typedef        : type
        // Typedef        : Type
        enum UNKNOWN_ENUM // appears to have no name in symbols
        {
            result
        };

    };
}

// TODO fix templates
template<typename T1>
class hkArrayBase
{
public:
    // Typedef        : ThisType
    // no_addr static void * operator new(unsigned __int64 _a1, void * _a2);// public missing arg names
    // no_addr static void * operator new(unsigned __int64 _a1);// public missing arg names
    // no_addr static void operator delete(void * _a1, void * _a2);// public missing arg names
    // no_addr static void operator delete(void * _a1, unsigned __int64 _a2);// public missing arg names
    // no_addr static void * operator new[](unsigned __int64 _a1, void * _a2);// public missing arg names
    // no_addr static void operator delete[](void * _a1, void * _a2);// public missing arg names
    class MustEndWithSemiColon
    {
    public:
    };
    // no_addr void hkArrayBase<T1>(class hkFinishLoadedObjectFlag _a1);// public missing arg names
    // no_addr void hkArrayBase<T1>(const class hkArrayBase<T1> & _a1);// protected missing arg names
    // no_addr void hkArrayBase<T1>(struct T1 * _a1, int _a2, int _a3);// public missing arg names
    hkArrayBase<T1>();// public RVA = 0x14ABA0
    hkArrayBase<T1>* _CONSTRUCTOR();// public RVA = 0x14ABA0
    // no_addr class hkArrayBase<T1> & operator=(const class hkArrayBase<T1> & _a1);// protected missing arg names
    ~hkArrayBase<T1>();// public RVA = 0x14ABC0
    void _DESTRUCTOR();// public RVA = 0x14ABC0
    const T1& operator[](int i) const;// public RVA = 0x3B3840
    T1& operator[](int i);// public RVA = 0x14ABD0
    const T1& back() const;// public RVA = 0x14ABE0
    // no_addr struct T1 & back();// public
    int getSize() const;// public RVA = 0x14AC00
    int getCapacity() const;// public RVA = 0x14AC90
    hkBool isEmpty() const;// public RVA = 0x14AC10
    void clear();// public RVA = 0x14B390
    void _clearAndDeallocate(hkMemoryAllocator& alloc);// public RVA = 0x14B4A0
    // no_addr void _optimizeCapacity(class hkMemoryAllocator & _a1, int _a2, unsigned int _a3);// public missing arg names
    // no_addr void removeAt(int _a1);// public missing arg names
    // no_addr void removeAtAndCopy(int _a1, int _a2);// public missing arg names
    // no_addr void removeAtAndCopy(int _a1);// public missing arg names
    // no_addr int indexOf(const struct T1 & _a1, int _a2, int _a3);// public missing arg names
    // no_addr int lastIndexOf(const struct T1 & _a1);// public missing arg names
    // no_addr void popBack(int _a1);// public missing arg names
    void _pushBack(hkMemoryAllocator& alloc, const T1& t);// public RVA = 0x3B84C0
    // no_addr void pushBackUnchecked(const struct T1 & _a1);// public missing arg names
    hkResult _reserve(hkMemoryAllocator& alloc, int n);// public RVA = 0x14ACA0
    // no_addr struct hkResult _reserveExactly(class hkMemoryAllocator & _a1, int _a2);// public missing arg names
    // no_addr void _setSize(class hkMemoryAllocator & _a1, int _a2, const struct T1 & _a3);// public missing arg names
    // no_addr void _setSize(class hkMemoryAllocator & _a1, int _a2);// public missing arg names
    // no_addr struct hkResult _trySetSize(class hkMemoryAllocator & _a1, int _a2, const struct T1 & _a3);// public missing arg names
    // no_addr struct hkResult _trySetSize(class hkMemoryAllocator & _a1, int _a2);// public missing arg names
    // no_addr void setSizeUnchecked(int _a1, const struct T1 & _a2);// public missing arg names
    // no_addr void setSizeUnchecked(int _a1);// public missing arg names
    // no_addr struct T1 & _expandOne(class hkMemoryAllocator & _a1);// public missing arg names
    // no_addr struct T1 * _expandBy(class hkMemoryAllocator & _a1, int _a2);// public missing arg names
    // no_addr struct T1 * expandByUnchecked(int _a1);// public missing arg names
    // no_addr struct T1 * _expandAt(class hkMemoryAllocator & _a1, int _a2, int _a3);// public missing arg names
    // no_addr void _insertAt(class hkMemoryAllocator & _a1, int _a2, const struct T1 & _a3);// public missing arg names
    // no_addr void _insertAt(class hkMemoryAllocator & _a1, int _a2, const struct T1 * _a3, int _a4);// public missing arg names
    // no_addr void _append(class hkMemoryAllocator & _a1, const struct T1 * _a2, int _a3);// public missing arg names
    void _spliceInto(hkMemoryAllocator& alloc, int index, int numdel, const T1* p, int numtoinsert);// public RVA = 0x14BD80
    // no_addr void removeAllAndCopy(const struct T1 & _a1);// public missing arg names
    // no_addr class hkBool tryPushBack(const struct T1 & _a1);// public missing arg names
    // Typedef        : iterator
    // Typedef        : const_iterator
    // no_addr const struct T1 * begin();// public
    // no_addr struct T1 * begin();// public
    // no_addr const struct T1 * end();// public
    // no_addr struct T1 * end();// public
    static void copy(T1* dst, const T1* src, int n);// public RVA = 0x14B7A0
    // no_addr void setDataAutoFree(struct T1 * _a1, int _a2, int _a3);// public missing arg names
    // no_addr void setDataUserFree(struct T1 * _a1, int _a2, int _a3);// public missing arg names
    // no_addr void _setDataUnchecked(struct T1 * _a1, int _a2, int _a3);// public missing arg names
    // no_addr int getCapacityAndFlags();// public
    // no_addr void _setData(struct T1 * _a1, int _a2, int _a3, struct hkTrait::TraitBool<1> _a4);// protected missing arg names
    hkArrayBase<T1>& copyFromArray(hkMemoryAllocator& alloc, const hkArrayBase<T1>& a, hkTrait::TraitBool<0> _a3);// protected RVA = 0x14C120
    // no_addr class hkArrayBase<T1> & copyFromArray(class hkMemoryAllocator & _a1, const class hkArrayBase<T1> & _a2, struct hkTrait::TraitBool<1> _a3);// protected missing arg names
    enum UNKNOWN_ENUM // this enum doesn't have a name symbol?
    {
        CAPACITY_MASK = 0x3FFFFFFF,
        FLAG_MASK = 0xC0000000,
        DONT_DEALLOCATE_FLAG = 0x80000000,
        ALLOCATED_FROM_SPU = 0x40000000,
        FORCE_SIGNED = 0xFF
    };

    T1* m_data; // 0x0 Member
    int m_size; // 0x8 Member
    int m_capacityAndFlags; // 0xC Member
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

// TODO fix templates
template<typename T1, typename T2>
class hkArray : public hkArrayBase<T1>
{
public:
    // hkArrayBase<T1> offset = 0x0, length = 0x10
    // Typedef        : AllocatorType
    // Typedef        : Temp
    // Typedef        : Debug
    // Typedef        : Heap
    // no_addr void hkArray<T1,T2>(const class hkArray<T1,T2> & _a1);// protected missing arg names
    // no_addr void hkArray<T1,T2>(class hkFinishLoadedObjectFlag _a1);// public missing arg names
    // no_addr void hkArray<T1,T2>(struct T1 * _a1, int _a2, int _a3);// public missing arg names
    // no_addr void hkArray<T1,T2>(int _a1, const struct T1 & _a2);// public missing arg names
    // no_addr void hkArray<T1,T2>(int _a1);// public missing arg names
    hkArray<T1, T2>();// public RVA = 0x14B2C0
    hkArray<T1, T2>* _CONSTRUCTOR();// public RVA = 0x14B2C0
    ~hkArray<T1, T2>();// public RVA = 0x14C960
    void _DESTRUCTOR();// public RVA = 0x14C960
    hkArray<T1, T2>& operator=(const hkArray<T1, T2>& a);// public RVA = 0x14C9E0
    // no_addr class hkArray<T1,T2> & operator=(const class hkArrayBase<T1> & _a1);// public missing arg names
    // no_addr void swap(class hkArray<T1,T2> & _a1);// public missing arg names
    void clearAndDeallocate();// public RVA = 0x14C0A0
    // no_addr void optimizeCapacity(int _a1, unsigned int _a2);// public missing arg names
    void pushBack(const T1& e);// public RVA = 0x3B99D0
    // no_addr struct hkResult reserve(int _a1);// public missing arg names
    // no_addr struct hkResult reserveExactly(int _a1);// public missing arg names
    // no_addr void setSize(int _a1, const struct T1 & _a2);// public missing arg names
    // no_addr void setSize(int _a1);// public missing arg names
    // no_addr struct hkResult trySetSize(int _a1, const struct T1 & _a2);// public missing arg names
    // no_addr struct hkResult trySetSize(int _a1);// public missing arg names
    // no_addr struct T1 & expandOne();// public
    // no_addr struct T1 * expandBy(int _a1);// public missing arg names
    // no_addr struct T1 * expandAt(int _a1, int _a2);// public missing arg names
    // no_addr void insertAt(int _a1, const struct T1 * _a2, int _a3);// public missing arg names
    // no_addr void insertAt(int _a1, const struct T1 & _a2);// public missing arg names
    // no_addr void append(const struct T1 * _a1, int _a2);// public missing arg names
    void spliceInto(int i, int ndel, const T1* p, int numElems);// public RVA = 0x14C8B0
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
