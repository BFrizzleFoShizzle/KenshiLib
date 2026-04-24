#pragma once

#include "GUIWindow.h"
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <mygui/MyGUI_Widget.h>
#include <mygui/common/baselayout/BaseLayout.h>
#include <kenshi/util/hand.h>

#include <string>
#include <vector>

class NewGameWindow;

class TitleScreen : public GUIWindow, public wraps::BaseLayout
{
public:
    // GUIWindow offset = 0x0, length = 0x30
    // wraps::BaseLayout offset = 0x30, length = 0xA0
    static TitleScreen* getSingleton();// public RVA = 0x911620
    // no_addr void TitleScreen(const class TitleScreen & _a1);// public missing arg names
    TitleScreen();// public RVA = 0x917740
    TitleScreen* _CONSTRUCTOR();// public RVA = 0x917740
    virtual ~TitleScreen();// public RVA = 0x9125C0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x9125C0 vtable offset = 0x0
    virtual void clear() override;// public RVA = 0x911680 vtable offset = 0x0
    void _NV_clear();// public RVA = 0x911680 vtable offset = 0x0
    virtual void show(bool on) override;// public RVA = 0x9116D0 vtable offset = 0x0
    void _NV_show(bool on);// public RVA = 0x9116D0 vtable offset = 0x0
    virtual void update() override;// public RVA = 0x9120D0 vtable offset = 0x0
    void _NV_update();// public RVA = 0x9120D0 vtable offset = 0x0
    bool closeTheOtherBits();// public RVA = 0x9132E0
    void loadGame(MyGUI::Widget* _sender);// private RVA = 0x913650
    void importGame(MyGUI::Widget* _sender);// private RVA = 0x913760
    void showOptions(MyGUI::Widget* _sender);// private RVA = 0x913870
    void credits(MyGUI::Widget* _sender);// private RVA = 0x913980
    void exitGame(MyGUI::Widget* _sender);// private RVA = 0x9139D0
    // no_addr void newGame(class MyGUI::Widget * _a1);// private missing arg names
    void continueGame(MyGUI::Widget* _sender);// private RVA = 0x913490
    void hover(MyGUI::Widget* _sender, MyGUI::Widget* _a2);// private RVA = 0x911690
    void setCreditsVisible(bool value);// private RVA = 0x912A80
    NewGameWindow* newGameWindow; // 0xD0 Member
    MyGUI::Widget* creditsPanel; // 0xD8 Member
    MyGUI::TextBox* creditsText; // 0xE0 Member
    bool creditsLoaded; // 0xE8 Member
    float creditsPosition; // 0xEC Member
    // no_addr class TitleScreen & operator=(const class TitleScreen & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};