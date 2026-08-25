#pragma once

#include <mygui/MyGUI_Widget.h>
#include "GUIWindow.h"
#include <kenshi/util/lektor.h>
#include <kenshi/util/StringPair.h>
#include <string>


class DataPanelLine;
class DataPanelLine_Faction;
class DataPanelLine_Research;
class DataPanelLine_Button;
class DataPanelLine_SliderEditable;
class DataPanelLine_Text;
class DataPanelLine_TextEditable;
class DataPanelLine_Slider;
class DataPanelLine_Progress;
class DataPanelLine_CheckBox;
class DataPanelLine_DropBox;

class DatapanelGUI : public GUIWindow
{
public:
    // GUIWindow offset = 0x0, length = 0x30
    // Typedef        : dataPanelMouseFunc
    // Typedef        : CloseButtonFunc
    // Typedef        : ChangeTabFunc
    MyGUI::delegates::CMultiDelegate2<DatapanelGUI*, int> tabEvent; // 0x30 Member
    bool frequentUpdatesWanted; // 0x48 Member
    void setFrequentUpdateMode();// public RVA = 0x43FDC0
    virtual void setPositionReal(float x, float y) override;// public RVA = 0x6F53B0 vtable offset = 0x0
    void _NV_setPositionReal(float x, float y);// public RVA = 0x6F53B0 vtable offset = 0x0
    virtual void setPosition(int x, int y) override;// public RVA = 0x6F5450 vtable offset = 0x0
    void _NV_setPosition(int x, int y);// public RVA = 0x6F5450 vtable offset = 0x0
    virtual void resize(int w, int h) override;// public RVA = 0x6F5460 vtable offset = 0x0
    void _NV_resize(int w, int h);// public RVA = 0x6F5460 vtable offset = 0x0
    virtual void clear() override;// public RVA = 0x6FC730 vtable offset = 0x0
    void _NV_clear();// public RVA = 0x6FC730 vtable offset = 0x0
    virtual void clearPage(int cat);// public RVA = 0x6FC960 vtable offset = 0x68
    void _NV_clearPage(int cat);// public RVA = 0x6FC960 vtable offset = 0x68
    virtual void hideAllWidgets();// public RVA = 0x6F5EA0 vtable offset = 0x70
    void _NV_hideAllWidgets();// public RVA = 0x6F5EA0 vtable offset = 0x70
    virtual void create();// public RVA = 0x6FA4D0 vtable offset = 0x78
    void _NV_create();// public RVA = 0x6FA4D0 vtable offset = 0x78
    virtual void show(bool on) override;// public RVA = 0x6F4F80 vtable offset = 0x0
    void _NV_show(bool on);// public RVA = 0x6F4F80 vtable offset = 0x0
    void show_NonSmooth(bool on);// public RVA = 0x6F4FE0
    virtual void update() override;// public RVA = 0x6F9510 vtable offset = 0x0
    void _NV_update();// public RVA = 0x6F9510 vtable offset = 0x0
    void setPanelName(const std::string& name);// public RVA = 0x6F6A20
    virtual void showTabs(bool on);// public RVA = 0x6F66F0 vtable offset = 0x80
    void _NV_showTabs(bool on);// public RVA = 0x6F66F0 vtable offset = 0x80
    virtual void addTab(int id, const std::string& name, const std::string& icon);// public RVA = 0x6FB130 vtable offset = 0x88
    void _NV_addTab(int id, const std::string& name, const std::string& icon);// public RVA = 0x6FB130 vtable offset = 0x88
    virtual void setTabEnabled(int id, const bool& enabled);// public RVA = 0x6FA940 vtable offset = 0x90
    void _NV_setTabEnabled(int id, const bool& enabled);// public RVA = 0x6FA940 vtable offset = 0x90
    virtual void setTabName(int id, const std::string& name);// public RVA = 0x6FA9F0 vtable offset = 0x98
    void _NV_setTabName(int id, const std::string& name);// public RVA = 0x6FA9F0 vtable offset = 0x98
    void setCaption(const std::string& s);// public RVA = 0x6F78F0
    void setCloseCallback(MyGUI::delegates::IDelegate2<MyGUI::Window*, std::string const&>* close);// public RVA = 0x6F78B0
    virtual void setAutomaticRefresh(bool on);// public RVA = 0x6F4F60 vtable offset = 0xA0
    void _NV_setAutomaticRefresh(bool on);// public RVA = 0x6F4F60 vtable offset = 0xA0
    virtual void setAutomaticTargeting(bool on);// public RVA = 0x6F5130 vtable offset = 0xA8
    void _NV_setAutomaticTargeting(bool on);// public RVA = 0x6F5130 vtable offset = 0xA8
    virtual DataPanelLine* _zeroLines(int cat);// public RVA = 0x6FBE70 vtable offset = 0xB0
    DataPanelLine* _NV__zeroLines(int cat);// public RVA = 0x6FBE70 vtable offset = 0xB0
    DataPanelLine* setLine(const std::string& keyValue, const std::string& s1, const std::string& s2, const std::string& skinA, const std::string& skinB, int category);// public RVA = 0x6FD7C0
    DataPanelLine* setLine(const std::string& keyValue, const std::string& s1, const std::string& s2, int category, bool last, bool keyVisible);// public RVA = 0x6FD4B0
    DataPanelLine* setLine(const std::string& s1, const std::string& s2, const std::string& skinA, const std::string& skinB, int category);// public RVA = 0x6FE610
    DataPanelLine* setLine(const std::string& s1, const std::string& s2, float barValue, int category);// public RVA = 0x6FDFE0
    DataPanelLine* setLine(const std::string& s1, const std::string& s2, int category, bool last, bool keyVisible);// public RVA = 0x6FD780
    DataPanelLine* setLineStatInfo(const std::string& s1, const std::string& s2, int category);// public RVA = 0x6FE650
    DataPanelLine_Faction* setLineFaction(const std::string& s1, const std::string& s2, int category, float v1, float v2);// public RVA = 0x6FD8D0
    DataPanelLine_Research* setLineResearch(const std::string& s1, const std::string& s2, int category, float v1, const std::string& barColor, bool XButton);// public RVA = 0x6FE510
    DataPanelLine_Research* setLineResearch(const std::string& key, const std::string& s1, const std::string& s2, int category, float v1, const std::string& barColor, bool Xbutton);// public RVA = 0x6FE2F0
    DataPanelLine_Button* setLineTextButton(const std::string& text, const std::string& caption, int category, float buttonWidth, const std::string& skin);// public RVA = 0x6FDCF0
    DataPanelLine_Button* setLineButton(const std::string& key, const std::string& caption, int category);// public RVA = 0x6FDE60
    DataPanelLine_Button* setLineToggleButton(const std::string& key, const std::string& caption, int category);// public RVA = 0x6FDF20
    DataPanelLine_SliderEditable* setLineSliderEditable(const std::string& key, int category, bool showName, float min, float max, float* value);// public RVA = 0x6FE1E0
    DataPanelLine_Text* setLineText(const std::string& key, const std::string& caption, int category, bool wordWrap, const MyGUI::Align& textAlign);// public RVA = 0x6FCC80
    DataPanelLine_TextEditable* setLineTextEditable(const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, const MyGUI::Align& textAlign, float width);// public RVA = 0x6FCAC0
    DataPanelLine_Slider* setLineSlider(const std::string& key, const std::string& caption, float min, float max, int category, float* value, float scale);// public RVA = 0x6FCDA0
    DataPanelLine_Progress* setLineProgress(const std::string& key, int category, float progressValue, const std::string& progressText, bool showKey);// public RVA = 0x6FCF00
    void removeLine(const std::string& s1, int category);// public RVA = 0x6FC1F0
    DataPanelLine_CheckBox* setLineCheckbox(const std::string& s1, bool* val, int category);// public RVA = 0x6FDB70
    DataPanelLine_DropBox* setLineDropBox(const std::string& key, int category, int* valPtr, bool goBox, float width);// public RVA = 0x6FDC30
    void addSpace(int category, float h);// public RVA = 0x6FD190
    void setLines(const lektor<StringPair>& data, int category);// public RVA = 0x6FE580
    virtual void setCategoryIcon(int cat, const std::string& image);// public RVA = 0x6F53A0 vtable offset = 0xB8
    void _NV_setCategoryIcon(int cat, const std::string& image);// public RVA = 0x6F53A0 vtable offset = 0xB8
    virtual void changeCategory(int cat);// public RVA = 0x6FC560 vtable offset = 0xC0
    void _NV_changeCategory(int cat);// public RVA = 0x6FC560 vtable offset = 0xC0
    virtual int getCurrentCategory() const;// public RVA = 0x70B6E0 vtable offset = 0xC8
    int _NV_getCurrentCategory() const;// public RVA = 0x70B6E0 vtable offset = 0xC8
    void addCustomLine(DataPanelLine* line);// public RVA = 0x6FE560
    virtual void autoChangeSelectedObject(const hand& obj) override;// public RVA = 0x6F5370 vtable offset = 0x0
    void _NV_autoChangeSelectedObject(const hand& obj);// public RVA = 0x6F5370 vtable offset = 0x0
    virtual hand getObject() const;// public RVA = 0x70B6F0 vtable offset = 0xD0
    hand _NV_getObject() const;// public RVA = 0x70B6F0 vtable offset = 0xD0
    virtual void setObject(const hand& obj);// public RVA = 0x6F9580 vtable offset = 0xD8
    void _NV_setObject(const hand& obj);// public RVA = 0x6F9580 vtable offset = 0xD8
    virtual void setLineSpacing(float numLinesPerScreen);// public RVA = 0x6F5030 vtable offset = 0xE0
    void _NV_setLineSpacing(float numLinesPerScreen);// public RVA = 0x6F5030 vtable offset = 0xE0
    virtual void setMouseOverCallback(void (*evt)(std::string, void*), void* datas);// public RVA = 0x6F50C0 vtable offset = 0xE8
    void _NV_setMouseOverCallback(void (*evt)(std::string, void*), void* datas);// public RVA = 0x6F50C0 vtable offset = 0xE8
    virtual DataPanelLine* getLine(const std::string& key, int cat);// public RVA = 0x6FC000 vtable offset = 0xF0
    DataPanelLine* _NV_getLine(const std::string& key, int cat);// public RVA = 0x6FC000 vtable offset = 0xF0
    bool lineExists(const std::string& key, int cat);// public RVA = 0x6FC100
    // no_addr float lineThickness();// public
    int getContentHeight(int cat) const;// public RVA = 0x6F6080
    void tabButton(MyGUI::Widget* _sender, int _a2, int _a3, MyGUI::MouseButton _a4);// public RVA = 0x6FAAD0
    int getNumLines(int cat);// public RVA = 0x6F5FA0
    DataPanelLine* getLineByNum(int cat, int i);// public RVA = 0x6FBD30
    MyGUI::Widget* scrollWin; // 0x50 Member
    // no_addr int getScrollOffset();// public
    // no_addr void setScrollOffset(int _a1);// public missing arg names
    // no_addr void DatapanelGUI(const class DatapanelGUI & _a1);// public missing arg names
    DatapanelGUI(const std::string& name, MyGUI::Widget* _parent, bool _scrolling);// protected RVA = 0x6FBBB0
    DatapanelGUI* _CONSTRUCTOR(const std::string& name, MyGUI::Widget* _parent, bool _scrolling);// protected RVA = 0x6FBBB0
    DatapanelGUI(float _x, float _y, float _w, float _h, bool _scrolling, const std::string& layr);// protected RVA = 0x6FBA00
    DatapanelGUI* _CONSTRUCTOR(float _x, float _y, float _w, float _h, bool _scrolling, const std::string& layr);// protected RVA = 0x6FBA00
    virtual ~DatapanelGUI();// protected RVA = 0x6FCFC0 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x6FCFC0 vtable offset = 0x0
    bool premadeParentWindow; // 0x58 Member
    bool scrolling; // 0x59 Member
    bool isWindow; // 0x5A Member
    DataPanelLine* createLine(DataPanelLine* line, int category, bool lastLine);// protected RVA = 0x6FC270
    float getNextVerticalPos(int category);// protected RVA = 0x6F6A40
    void closeButtonCallback(MyGUI::Window* _a1, const std::string& _a2);// protected RVA = 0x6F50E0 missing arg names
    void mouseOverCallback(MyGUI::Widget* _sender);// protected RVA = 0x6F6010
    void notifyMouseWheel(MyGUI::Widget* _sender, int _rel);// protected RVA = 0x6F50F0
    MyGUI::types::TCoord<int> getCoords(float left, float top, float width, float height);// protected RVA = 0x6F5700
    std::map<int, std::map<std::string, DataPanelLine*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataPanelLine*>, Ogre::GeneralAllocPolicy > >, std::less<int>, Ogre::STLAllocator<std::pair<int const, std::map<std::string, DataPanelLine*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, DataPanelLine*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > > content; // 0x60 Member
    std::map<int, DataPanelLine*, std::less<int>, Ogre::STLAllocator<std::pair<int const, DataPanelLine*>, Ogre::GeneralAllocPolicy > > bottomLine; // 0x88 Member
    int currentCategory; // 0xB0 Member
    bool dataExists(int cat, const std::string& name);// protected RVA = 0x6F5220
    // no_addr void _hideWidgets();// protected
    void (*mouseOverEvent)(std::string, void*); // 0xB8 Member
    void* mouseOverEventDatas; // 0xC0 Member
    bool automaticRefresh; // 0xC8 Member
    bool automaticTarget; // 0xC9 Member
    MyGUI::Window* tabWin; // 0xD0 Member
    lektor<MyGUI::Button*> tabs; // 0xD8 Member
    void clearCategoryTabs();// protected RVA = 0x6F5680
    std::string panelName; // 0xF0 Member
    float x; // 0x118 Member
    float y; // 0x11C Member
    float w; // 0x120 Member
    float h; // 0x124 Member
    float DATALINESPACING; // 0x128 Member
    float DATALINETHICKNESS; // 0x12C Member
    bool basicSpacing; // 0x130 Member
    std::string layer; // 0x138 Member
    MyGUI::ScrollView* scrollView; // 0x160 Member
    // no_addr class DatapanelGUI & operator=(const class DatapanelGUI & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};