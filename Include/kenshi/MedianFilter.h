#pragma once

#include <deque>

class MedianFilter
{
public:
    // no_addr void MedianFilter(const class MedianFilter & _a1);// public missing arg names
    MedianFilter();// public RVA = 0x528370
    MedianFilter* _CONSTRUCTOR();// public RVA = 0x528370
    void setup(int numFrames, int numSamples, bool _isPositionsFilter);// public RVA = 0x51C020
    void reset();// public RVA = 0x5283B0
    void applySilent(float delta_mouse_x);// public RVA = 0x5283C0
    void apply(float& delta_mouse_x);// public RVA = 0x52A140
    bool isPositionsFilter; // 0x0 Member
    int edgeSkips; // 0x4 Member
    int maxLength; // 0x8 Member
    std::deque<float, std::allocator<float> > mHistoryBufferX; // 0x10 Member
    ~MedianFilter();// public RVA = 0x528430
    void _DESTRUCTOR();// public RVA = 0x528430
    // no_addr class MedianFilter & operator=(const class MedianFilter & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class MedianFilter2DVector
{
public:
    // no_addr void MedianFilter2DVector(const class MedianFilter2DVector & _a1);// public missing arg names
    MedianFilter2DVector();// public RVA = 0x6644C0
    MedianFilter2DVector* _CONSTRUCTOR();// public RVA = 0x6644C0
    void setup(int numFrames, int numSamples, bool positions);// public RVA = 0x663BF0
    void reset();// public RVA = 0x664470
    // no_addr void applySilent(class Ogre::Vector3 _a1);// public missing arg names
    // no_addr void apply(class Ogre::Vector3 & _a1);// public missing arg names
    MedianFilter filters[0x2]; // 0x0 Member
    ~MedianFilter2DVector();// public RVA = 0x6644A0
    void _DESTRUCTOR();// public RVA = 0x6644A0
    // no_addr class MedianFilter2DVector & operator=(const class MedianFilter2DVector & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};