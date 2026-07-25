#pragma once

#include <ogre/OgreVector3.h>
#include <kenshi/util/hand.h>
#include <mygui/MyGUI_Colour.h>
#include <mygui/common/baselayout/BaseLayout.h>

class ScreenLabelInterface : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void ScreenLabelInterface(const class ScreenLabelInterface & _a1);// public missing arg names
    ScreenLabelInterface();// protected RVA = 0x6E1AF0
    ScreenLabelInterface* _CONSTRUCTOR();// protected RVA = 0x6E1AF0
    virtual ~ScreenLabelInterface();// public RVA = 0x6E1B50 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x6E1B50 vtable offset = 0x0
    virtual void update() = 0;// public vtable offset = 0x8
    virtual void setVisible(bool value);// public RVA = 0x6E1B70 vtable offset = 0x10
    void _NV_setVisible(bool value);// public RVA = 0x6E1B70 vtable offset = 0x10
    virtual void setPosition(const Ogre::Vector3& value);// public RVA = 0x6E1B90 vtable offset = 0x18
    void _NV_setPosition(const Ogre::Vector3& value);// public RVA = 0x6E1B90 vtable offset = 0x18
    bool visible; // 0x8 Member
    Ogre::Vector3 position; // 0xC Member
    bool needUpdate; // 0x18 Member
    // no_addr class ScreenLabelInterface & operator=(const class ScreenLabelInterface & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class ScreenLabel : public ScreenLabelInterface
{
public:
    // ScreenLabelInterface offset = 0x0, length = 0x20
    enum RisingSpeed
    {
        RS_STOPPED,
        RS_SLOW,
        RS_NORMAL,
        RS_FAST
    };

    enum LabelSize
    {
        LS_SMALL,
        LS_MEDIUM,
        LS_LARGE
    };

    virtual void setTracking(const hand& handle, const Ogre::Vector3& offset);// public RVA = 0x6E1BB0 vtable offset = 0x20
    void _NV_setTracking(const hand& handle, const Ogre::Vector3& offset);// public RVA = 0x6E1BB0 vtable offset = 0x20
    virtual void setCaption(const std::string& value);// public RVA = 0x6E3E10 vtable offset = 0x28
    void _NV_setCaption(const std::string& value);// public RVA = 0x6E3E10 vtable offset = 0x28
    virtual void setRisingSpeed(ScreenLabel::RisingSpeed value);// public RVA = 0x6E1C10 vtable offset = 0x30
    void _NV_setRisingSpeed(ScreenLabel::RisingSpeed value);// public RVA = 0x6E1C10 vtable offset = 0x30
    virtual void setColor(const MyGUI::Colour& value);// public RVA = 0x6E1C30 vtable offset = 0x38
    void _NV_setColor(const MyGUI::Colour& value);// public RVA = 0x6E1C30 vtable offset = 0x38
    virtual void setPosition(const Ogre::Vector3& value) override;// public RVA = 0x6E1C80 vtable offset = 0x0
    void _NV_setPosition(const Ogre::Vector3& value);// public RVA = 0x6E1C80 vtable offset = 0x0
    virtual void update() override;// public RVA = 0x6E9B60 vtable offset = 0x0
    void _NV_update();// public RVA = 0x6E9B60 vtable offset = 0x0
    // no_addr void ScreenLabel(const class ScreenLabel & _a1);// public missing arg names
    ScreenLabel(const std::string& caption, const MyGUI::Colour& textColour, ScreenLabel::LabelSize textSize, ScreenLabel::RisingSpeed risingSpeed);// protected RVA = 0x6E2FD0
    ScreenLabel* _CONSTRUCTOR(const std::string& caption, const MyGUI::Colour& textColour, ScreenLabel::LabelSize textSize, ScreenLabel::RisingSpeed risingSpeed);// protected RVA = 0x6E2FD0
    virtual ~ScreenLabel();// protected RVA = 0x6E2B60 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x6E2B60 vtable offset = 0x0
    void destroy();// protected RVA = 0x6E9AC0
    std::string caption; // 0x20 Member
    MyGUI::TextBox* textWidget; // 0x48 Member
    MyGUI::Colour color; // 0x50 Member
    float risingSpeed; // 0x60 Member
    float risingHeight; // 0x64 Member
    ScreenLabel::LabelSize labelSize; // 0x68 Member
    hand trackingHandle; // 0x70 Member
    Ogre::Vector3 trackingOffset; // 0x90 Member
    bool destroyed; // 0x9C Member
    static std::string FontSizes[0x0]; // RVA = 0x1F26A40 Static Member
    static float RisingSpeeds[0x0]; // RVA = 0x1F1CB48 Static Member
    // no_addr class ScreenLabel & operator=(const class ScreenLabel & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class ScreenLabelDebug : public ScreenLabel
{
public:
    // ScreenLabel offset = 0x0, length = 0xA0
    virtual void update() override;// public RVA = 0x6E9EE0 vtable offset = 0x0
    void _NV_update();// public RVA = 0x6E9EE0 vtable offset = 0x0
    const std::string& getCaption() const;// public RVA = 0x6E1CF0
    // no_addr void ScreenLabelDebug(const class ScreenLabelDebug & _a1);// public missing arg names
    ScreenLabelDebug(const std::string& caption, float time);// protected RVA = 0x6E3150
    ScreenLabelDebug* _CONSTRUCTOR(const std::string& caption, float time);// protected RVA = 0x6E3150
    virtual ~ScreenLabelDebug();// protected RVA = 0x6E2BF0 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x6E2BF0 vtable offset = 0x0
    float timeLeft; // 0xA0 Member
    // no_addr class ScreenLabelDebug & operator=(const class ScreenLabelDebug & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class FloatingProgressBar : public ScreenLabelInterface
{
public:
    // ScreenLabelInterface offset = 0x0, length = 0x20
    class ProgressBarWidget : private wraps::BaseLayout
    {
    public:
        // wraps::BaseLayout offset = 0x0, length = 0xA0
        // no_addr void ProgressBarWidget(const class FloatingProgressBar::ProgressBarWidget & _a1);// public missing arg names
        ProgressBarWidget();// public RVA = 0x6E76F0
        ProgressBarWidget* _CONSTRUCTOR();// public RVA = 0x6E76F0
        virtual ~ProgressBarWidget();// public RVA = 0x6E31D0 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0x6E31D0 vtable offset = 0x0
        void setVisible(bool value);// public RVA = 0x6E1F00
        void setProgress(int value);// public RVA = 0x6E1F20
        void setPosition(int x, int y);// public RVA = 0x6E1F40
        void setCaption(const std::string& value);// public RVA = 0x6E1F70
        MyGUI::ProgressBar* bar; // 0xA0 Member
        MyGUI::TextBox* label; // 0xA8 Member
        // no_addr class FloatingProgressBar::ProgressBarWidget & operator=(const class FloatingProgressBar::ProgressBarWidget & _a1);// public missing arg names
        // no_addr void __local_vftable_ctor_closure();// public
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    // no_addr void FloatingProgressBar(const class FloatingProgressBar & _a1);// public missing arg names
    FloatingProgressBar();// public RVA = 0x6EA070
    FloatingProgressBar* _CONSTRUCTOR();// public RVA = 0x6EA070
    virtual ~FloatingProgressBar();// public RVA = 0x6E2C10 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x6E2C10 vtable offset = 0x0
    void setProgress(float value);// public RVA = 0x6E2AF0
    void setCaption(const std::string& value);// public RVA = 0x6E3E60
    virtual void update() override;// public RVA = 0x6E7930 vtable offset = 0x0
    void _NV_update();// public RVA = 0x6E7930 vtable offset = 0x0
    static float ProgressScale; // RVA = 0x1F1CB58 Static Member
    std::string caption; // 0x20 Member
    int progress; // 0x48 Member
    FloatingProgressBar::ProgressBarWidget* bar; // 0x50 Member
    // no_addr class FloatingProgressBar & operator=(const class FloatingProgressBar & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};