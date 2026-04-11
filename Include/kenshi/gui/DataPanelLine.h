#include <mygui/MyGUI_TextBox.h>
#include <kenshi/util/StringPair.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/hand.h>

class ToolTip;
class DatapanelGUI;

class DataPanelLine : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // Typedef        : EventHandle_DatapanelLineVoid
    enum LineType
    {
        DPL_BASE,
        DPL_MEDICAL,
        DPL_FACTION,
        DPL_RESEARCH,
        DPL_BUTTON,
        DPL_EDIT,
        DPL_CHECK,
        DPL_DROPBOX,
        DPL_TEXT,
        DPL_TEXT_EDIT,
        DPL_SLIDER,
        DPL_PROGRESS,
        DPL_CUSTOM
    };

    // no_addr void DataPanelLine(const class DataPanelLine & _a1);// public missing arg names
    DataPanelLine(MyGUI::TextBox* a, MyGUI::TextBox* b, MyGUI::Button* check, int cat);// public RVA = 0x6F6270
    DataPanelLine* _CONSTRUCTOR(MyGUI::TextBox* a, MyGUI::TextBox* b, MyGUI::Button* check, int cat);// public RVA = 0x6F6270
    DataPanelLine(const std::string& a, const std::string& b, int category, const std::string& skinA, const std::string& skinB);// public RVA = 0x6F6100
    DataPanelLine* _CONSTRUCTOR(const std::string& a, const std::string& b, int category, const std::string& skinA, const std::string& skinB);// public RVA = 0x6F6100
    DataPanelLine(const std::string& key, const std::string& a, const std::string& b, int category, const std::string& skinA, const std::string& skinB);// public RVA = 0x6F6370
    DataPanelLine* _CONSTRUCTOR(const std::string& key, const std::string& a, const std::string& b, int category, const std::string& skinA, const std::string& skinB);// public RVA = 0x6F6370
    virtual ~DataPanelLine();// public RVA = 0x6F64F0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x6F64F0 vtable offset = 0x0
    virtual void setVisible(bool on);// public RVA = 0x6F5900 vtable offset = 0x8
    void _NV_setVisible(bool on);// public RVA = 0x6F5900 vtable offset = 0x8
    virtual void setEnabled(bool on);// public RVA = 0x6F5980 vtable offset = 0x10
    void _NV_setEnabled(bool on);// public RVA = 0x6F5980 vtable offset = 0x10
    virtual void refresh();// public RVA = 0x7067E0 vtable offset = 0x18
    void _NV_refresh();// public RVA = 0x7067E0 vtable offset = 0x18
    virtual void updateValuePtr(void* _a1);// public RVA = 0x402EE0 vtable offset = 0x20 missing arg names
    void _NV_updateValuePtr(void* _a1);// public RVA = 0x402EE0 vtable offset = 0x20 missing arg names
    // no_addr void addAWidget(class MyGUI::Widget * _a1, float _a2);// public missing arg names
    virtual void setToolTip(const std::string& s);// public RVA = 0x91E8D0 vtable offset = 0x30
    void _NV_setToolTip(const std::string& s);// public RVA = 0x91E8D0 vtable offset = 0x30
    virtual void setToolTip(const std::string& s, ToolTip* tooltip);// public RVA = 0x9200C0 vtable offset = 0x28
    void _NV_setToolTip(const std::string& s, ToolTip* tooltip);// public RVA = 0x9200C0 vtable offset = 0x28
    virtual void setToolTipMainBar(const std::string& s, bool updateable);// public RVA = 0x9202B0 vtable offset = 0x40
    void _NV_setToolTipMainBar(const std::string& s, bool updateable);// public RVA = 0x9202B0 vtable offset = 0x40
    virtual void setToolTipMainBar(const lektor<StringPair>& s, bool updateable);// public RVA = 0x920D80 vtable offset = 0x38
    void _NV_setToolTipMainBar(const lektor<StringPair>& s, bool updateable);// public RVA = 0x920D80 vtable offset = 0x38
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine);// public RVA = 0x6F8840 vtable offset = 0x48
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// public RVA = 0x6F8840 vtable offset = 0x48
    virtual void resize(int width, int height);// public RVA = 0x6F57C0 vtable offset = 0x50
    void _NV_resize(int width, int height);// public RVA = 0x6F57C0 vtable offset = 0x50
    virtual int getBottom();// public RVA = 0x6F5870 vtable offset = 0x58
    int _NV_getBottom();// public RVA = 0x6F5870 vtable offset = 0x58
    DataPanelLine::LineType getType() const;// public RVA = 0x3E6B30
    virtual hand getUserData();// public RVA = 0x402EF0 vtable offset = 0x60
    hand _NV_getUserData();// public RVA = 0x402EF0 vtable offset = 0x60
    int getNumWidgets() const;// public RVA = 0x978B00
    MyGUI::Widget* getWidget(int index) const;// public RVA = 0x978B20
    MyGUI::TextBox* w1; // 0x8 Member
    MyGUI::TextBox* w2; // 0x10 Member
    int category; // 0x18 Member
    MyGUI::delegates::CDelegate1<DataPanelLine*> callback; // 0x20 Member
    std::string keyValue; // 0x28 Member
    std::string s1; // 0x50 Member
    std::string s2; // 0x78 Member
    int lo; // 0xA0 Member
    int hi; // 0xA4 Member
    std::string skinW1; // 0xA8 Member
    std::string skinW2; // 0xD0 Member
    Ogre::vector<MyGUI::Widget*>::type widgets; // 0xF8 Member
    DataPanelLine::LineType classType; // 0x118 Member
    // no_addr class DataPanelLine & operator=(const class DataPanelLine & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_Faction : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    // no_addr void DataPanelLine_Faction(const class DataPanelLine_Faction & _a1);// public missing arg names
    DataPanelLine_Faction(const std::string& a, const std::string& b, int cat, float vv1, float vv2);// protected RVA = 0x707070
    DataPanelLine_Faction* _CONSTRUCTOR(const std::string& a, const std::string& b, int cat, float vv1, float vv2);// protected RVA = 0x707070
    float v1; // 0x120 Member
    float v2; // 0x124 Member
    MyGUI::Widget* bar; // 0x128 Member
    MyGUI::Widget* bar2; // 0x130 Member
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// protected RVA = 0x6F8C30 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// protected RVA = 0x6F8C30 vtable offset = 0x0
    MyGUI::Button* but; // 0x138 Member
    virtual ~DataPanelLine_Faction();// public RVA = 0x707210 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x707210 vtable offset = 0x0
    // no_addr class DataPanelLine_Faction & operator=(const class DataPanelLine_Faction & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_Research : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    // no_addr void DataPanelLine_Research(const class DataPanelLine_Research & _a1);// public missing arg names
    DataPanelLine_Research(const std::string& a, const std::string& b, int cat, float vv1, const std::string& _barColor, bool _Xbut);// protected RVA = 0x707220
    DataPanelLine_Research* _CONSTRUCTOR(const std::string& a, const std::string& b, int cat, float vv1, const std::string& _barColor, bool _Xbut);// protected RVA = 0x707220
    float v1; // 0x120 Member
    float v2; // 0x124 Member
    bool hasXBut; // 0x128 Member
    std::string barSkin; // 0x130 Member
    MyGUI::Widget* bar; // 0x158 Member
    MyGUI::Button* but; // 0x160 Member
    MyGUI::Button* Xbut; // 0x168 Member
    virtual void setToolTipMainBar(const std::string& s, bool updateable) override;// public RVA = 0x920340 vtable offset = 0x0
    void _NV_setToolTipMainBar(const std::string& s, bool updateable);// public RVA = 0x920340 vtable offset = 0x0
    virtual void setToolTipMainBar(const lektor<StringPair>& s, bool updateable) override;// public RVA = 0x920E10 vtable offset = 0x0
    void _NV_setToolTipMainBar(const lektor<StringPair>& s, bool updateable);// public RVA = 0x920E10 vtable offset = 0x0
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// public RVA = 0x6F7FB0 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// public RVA = 0x6F7FB0 vtable offset = 0x0
    virtual ~DataPanelLine_Research();// public RVA = 0x707610 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x707610 vtable offset = 0x0
    // no_addr class DataPanelLine_Research & operator=(const class DataPanelLine_Research & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_Button : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    // no_addr void DataPanelLine_Button(const class DataPanelLine_Button & _a1);// public missing arg names
    DataPanelLine_Button(const std::string& a, const std::string& b, int cat, float w, const std::string& skin);// protected RVA = 0x6F7120
    DataPanelLine_Button* _CONSTRUCTOR(const std::string& a, const std::string& b, int cat, float w, const std::string& skin);// protected RVA = 0x6F7120
    void pressCallback(MyGUI::Widget* _sender);// protected RVA = 0x6F5A00
    virtual hand getUserData() override;// public RVA = 0x707750 vtable offset = 0x0
    hand _NV_getUserData();// public RVA = 0x707750 vtable offset = 0x0
    hand userData; // 0x120 Member
    MyGUI::Button* button; // 0x140 Member
    float buttonWidth; // 0x148 Member
    float buttonHeight; // 0x14C Member
    std::string buttonSkin; // 0x150 Member
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// public RVA = 0x6F9230 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// public RVA = 0x6F9230 vtable offset = 0x0
    virtual void setToolTipMainBar(const std::string& s, bool updateable) override;// public RVA = 0x9203A0 vtable offset = 0x0
    void _NV_setToolTipMainBar(const std::string& s, bool updateable);// public RVA = 0x9203A0 vtable offset = 0x0
    virtual void setToolTipMainBar(const lektor<StringPair>& s, bool updateable) override;// public RVA = 0x920E70 vtable offset = 0x0
    void _NV_setToolTipMainBar(const lektor<StringPair>& s, bool updateable);// public RVA = 0x920E70 vtable offset = 0x0
    virtual ~DataPanelLine_Button();// public RVA = 0x7077A0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x7077A0 vtable offset = 0x0
    // no_addr class DataPanelLine_Button & operator=(const class DataPanelLine_Button & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_SliderEditable : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    void setEditableValuePtr(float* val, float lo, float hi);// public RVA = 0x6F51D0
    MyGUI::ScrollBar* getSlider();// public RVA = 0x780920
    MyGUI::EditBox* getEditBox();// public RVA = 0x780930
    // no_addr class MyGUI::EditBox * getNameBox();// public
    virtual void updateValuePtr(void* ptr) override;// public RVA = 0x6F5200 vtable offset = 0x0
    void _NV_updateValuePtr(void* ptr);// public RVA = 0x6F5200 vtable offset = 0x0
    void setValue(float v);// public RVA = 0x6F5AB0
    virtual void refresh() override;// public RVA = 0x6F5BB0 vtable offset = 0x0
    void _NV_refresh();// public RVA = 0x6F5BB0 vtable offset = 0x0
    void setPrecision(int dp);// public RVA = 0x6F5140
    // no_addr void DataPanelLine_SliderEditable(const class DataPanelLine_SliderEditable & _a1);// public missing arg names
    DataPanelLine_SliderEditable(const std::string& text, int category, bool showName, float min, float max, float* value);// protected RVA = 0x6F6B70
    DataPanelLine_SliderEditable* _CONSTRUCTOR(const std::string& text, int category, bool showName, float min, float max, float* value);// protected RVA = 0x6F6B70
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// protected RVA = 0x6F79F0 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// protected RVA = 0x6F79F0 vtable offset = 0x0
    void editCallback(MyGUI::EditBox* _sender);// protected RVA = 0x6F5D50
    void sliderCallback(MyGUI::ScrollBar* _sender, unsigned __int64 _position);// protected RVA = 0x6F5E40
    float width; // 0x120 Member
    bool showName; // 0x124 Member
    float min; // 0x128 Member
    float max; // 0x12C Member
    float* valuePtr; // 0x130 Member
    float scale; // 0x138 Member
    MyGUI::EditBox* nameText; // 0x140 Member
    MyGUI::EditBox* valueEditBox; // 0x148 Member
    MyGUI::ScrollBar* sliderBar; // 0x150 Member
    virtual ~DataPanelLine_SliderEditable();// public RVA = 0x7076E0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x7076E0 vtable offset = 0x0
    // no_addr class DataPanelLine_SliderEditable & operator=(const class DataPanelLine_SliderEditable & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_Text : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    // no_addr class MyGUI::EditBox * getEditBox();// public
    // no_addr void DataPanelLine_Text(const class DataPanelLine_Text & _a1);// public missing arg names
    DataPanelLine_Text(const std::string& key, const std::string& text, int category, bool wordWrap, const MyGUI::Align& textAlign);// protected RVA = 0x6F7470
    DataPanelLine_Text* _CONSTRUCTOR(const std::string& key, const std::string& text, int category, bool wordWrap, const MyGUI::Align& textAlign);// protected RVA = 0x6F7470
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// protected RVA = 0x6F9A20 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// protected RVA = 0x6F9A20 vtable offset = 0x0
    MyGUI::EditBox* editBox; // 0x120 Member
    MyGUI::Align textAlign; // 0x128 Member
    bool wordWrap; // 0x12C Member
    virtual ~DataPanelLine_Text();// public RVA = 0x7078D0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x7078D0 vtable offset = 0x0
    // no_addr class DataPanelLine_Text & operator=(const class DataPanelLine_Text & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_TextEditable : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    MyGUI::EditBox* getEditBox();// public RVA = 0x111C70
    MyGUI::EditBox* getNameBox();// public RVA = 0x96BC50
    // no_addr void DataPanelLine_TextEditable(const class DataPanelLine_TextEditable & _a1);// public missing arg names
    DataPanelLine_TextEditable(const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, const MyGUI::Align& textAlign, float width);// protected RVA = 0x6F7300
    DataPanelLine_TextEditable* _CONSTRUCTOR(const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, const MyGUI::Align& textAlign, float width);// protected RVA = 0x6F7300
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// protected RVA = 0x6F95F0 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// protected RVA = 0x6F95F0 vtable offset = 0x0
    void textChanged(MyGUI::EditBox* sender);// protected RVA = 0x6F5A30
    MyGUI::EditBox* editBox; // 0x120 Member
    MyGUI::EditBox* nameText; // 0x128 Member
    MyGUI::Align textAlign; // 0x130 Member
    bool showKey; // 0x134 Member
    bool multiLine; // 0x135 Member
    float width; // 0x138 Member
    virtual ~DataPanelLine_TextEditable();// public RVA = 0x707880 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x707880 vtable offset = 0x0
    // no_addr class DataPanelLine_TextEditable & operator=(const class DataPanelLine_TextEditable & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

namespace MyGUI
{
    // TODO where does this come from?
    class Slider;
}

class DataPanelLine_Slider : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    // no_addr void DataPanelLine_Slider(const class DataPanelLine_Slider & _a1);// public missing arg names
    DataPanelLine_Slider(const std::string& key, const std::string& text, float min, float max, int category, float scale);// protected RVA = 0x6F75C0
    DataPanelLine_Slider* _CONSTRUCTOR(const std::string& key, const std::string& text, float min, float max, int category, float scale);// protected RVA = 0x6F75C0
    void sliderValueChanged(MyGUI::Slider* _sender, int _value);// protected RVA = 0x6F5A60
    float scale; // 0x120 Member
    float min; // 0x124 Member
    float max; // 0x128 Member
    float* valuePtr; // 0x130 Member
    MyGUI::Slider* slider; // 0x138 Member
    virtual void updateValuePtr(void* ptr) override;// public RVA = 0x6F54E0 vtable offset = 0x0
    void _NV_updateValuePtr(void* ptr);// public RVA = 0x6F54E0 vtable offset = 0x0
    void setValue(float value);// public RVA = 0x6F5500
    float getValue() const;// public RVA = 0x6F5540
    virtual void refresh() override;// public RVA = 0x6F5590 vtable offset = 0x0
    void _NV_refresh();// public RVA = 0x6F5590 vtable offset = 0x0
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// public RVA = 0x6F9C70 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// public RVA = 0x6F9C70 vtable offset = 0x0
    virtual ~DataPanelLine_Slider();// public RVA = 0x707920 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x707920 vtable offset = 0x0
    // no_addr class DataPanelLine_Slider & operator=(const class DataPanelLine_Slider & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_Progress : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    void setProgress(float value, const std::string& text);// public RVA = 0x6F55D0
    // no_addr void DataPanelLine_Progress(const class DataPanelLine_Progress & _a1);// public missing arg names
    DataPanelLine_Progress(const std::string& key, int category, bool showKey);// protected RVA = 0x6F7720
    DataPanelLine_Progress* _CONSTRUCTOR(const std::string& key, int category, bool showKey);// protected RVA = 0x6F7720
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// protected RVA = 0x6F9F40 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// protected RVA = 0x6F9F40 vtable offset = 0x0
    MyGUI::EditBox* textBox; // 0x120 Member
    MyGUI::ProgressBar* progress; // 0x128 Member
    MyGUI::EditBox* progressText; // 0x130 Member
    bool showKey; // 0x138 Member
    virtual ~DataPanelLine_Progress();// public RVA = 0x707970 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x707970 vtable offset = 0x0
    // no_addr class DataPanelLine_Progress & operator=(const class DataPanelLine_Progress & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_CheckBox : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    virtual void updateValuePtr(void* ptr) override;// public RVA = 0x6F5760 vtable offset = 0x0
    void _NV_updateValuePtr(void* ptr);// public RVA = 0x6F5760 vtable offset = 0x0
    virtual void refresh() override;// public RVA = 0x6F5270 vtable offset = 0x0
    void _NV_refresh();// public RVA = 0x6F5270 vtable offset = 0x0
    void setValue(bool checked);// public RVA = 0x6F5230
    void setValuePtr(bool* valPtr);// public RVA = 0x6F52A0
    MyGUI::EditBox* getTextBox() const;// public RVA = 0x911610
    MyGUI::Button* getCheckBox() const;// public RVA = 0x780910
    // no_addr void DataPanelLine_CheckBox(const class DataPanelLine_CheckBox & _a1);// public missing arg names
    DataPanelLine_CheckBox(const std::string& key, int cat, bool* _val);// protected RVA = 0x6F6D20
    DataPanelLine_CheckBox* _CONSTRUCTOR(const std::string& key, int cat, bool* _val);// protected RVA = 0x6F6D20
    void notifyToggleCheck(MyGUI::Widget* _sender);// protected RVA = 0x6F7970
    virtual void createMe(DatapanelGUI* parent, float topReal, bool lastLine) override;// protected RVA = 0x6FAB60 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float topReal, bool lastLine);// protected RVA = 0x6FAB60 vtable offset = 0x0
    bool* valuePtr; // 0x120 Member
    MyGUI::EditBox* text; // 0x128 Member
    MyGUI::Button* button; // 0x130 Member
    virtual ~DataPanelLine_CheckBox();// public RVA = 0x7076F0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x7076F0 vtable offset = 0x0
    // no_addr class DataPanelLine_CheckBox & operator=(const class DataPanelLine_CheckBox & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_DropBox : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    void addAValue(const std::string& key, int val);// public RVA = 0x6F5CA0
    int getSelectedValue();// public RVA = 0x6FAFD0
    void setSelectedValue(int val);// public RVA = 0x6FB030
    std::string getSelectedText() const;// public RVA = 0x6F7030
    void clearValues();// public RVA = 0x6F52D0
    MyGUI::ComboBox* getComboBox();// public RVA = 0x4A6DE0
    // no_addr class MyGUI::Button * getGoBox();// public
    virtual void createMe(DatapanelGUI* parent, float top, bool lastLine) override;// public RVA = 0x6FB3C0 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* parent, float top, bool lastLine);// public RVA = 0x6FB3C0 vtable offset = 0x0
    virtual void updateValuePtr(void* ptr) override;// public RVA = 0x6F5320 vtable offset = 0x0
    void _NV_updateValuePtr(void* ptr);// public RVA = 0x6F5320 vtable offset = 0x0
    virtual void refresh() override;// public RVA = 0x6FB100 vtable offset = 0x0
    void _NV_refresh();// public RVA = 0x6FB100 vtable offset = 0x0
    // no_addr void DataPanelLine_DropBox(const class DataPanelLine_DropBox & _a1);// public missing arg names
    DataPanelLine_DropBox(const std::string& text, int category, int* valuePtr, float width, bool hasGobox);// protected RVA = 0x6F6EA0
    DataPanelLine_DropBox* _CONSTRUCTOR(const std::string& text, int category, int* valuePtr, float width, bool hasGobox);// protected RVA = 0x6F6EA0
    MyGUI::ComboBox* listBox; // 0x120 Member
    float listWidth; // 0x128 Member
    int* valPtr; // 0x130 Member
    bool hasGoBox; // 0x138 Member
    MyGUI::Button* goBox; // 0x140 Member
    void selectionChange(MyGUI::ComboBox* _sender, unsigned __int64 i);// protected RVA = 0x6FAF60
    void goPressed(MyGUI::Widget* _sender);// protected RVA = 0x6F5790
    virtual ~DataPanelLine_DropBox();// public RVA = 0x707700 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x707700 vtable offset = 0x0
    // no_addr class DataPanelLine_DropBox & operator=(const class DataPanelLine_DropBox & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class DataPanelLine_KeyConfig : public DataPanelLine
{
public:
    // DataPanelLine offset = 0x0, length = 0x120
    // no_addr void DataPanelLine_KeyConfig(const class DataPanelLine_KeyConfig & _a1);// public missing arg names
    DataPanelLine_KeyConfig(const std::string& cmd, const std::string& text, int cat);// public RVA = 0x3E7740
    DataPanelLine_KeyConfig* _CONSTRUCTOR(const std::string& cmd, const std::string& text, int cat);// public RVA = 0x3E7740
    const std::string& getCommand();// public RVA = 0x3E6B60
    int oldKey();// public RVA = 0x3E71B0
    void setKey(const std::string& s);// public RVA = 0x3EF2F0
    void eraseKey(const std::string& key);// public RVA = 0x3E6B70
    virtual void refresh() override;// public RVA = 0x3E7420 vtable offset = 0x0
    void _NV_refresh();// public RVA = 0x3E7420 vtable offset = 0x0
    void cancel();// public RVA = 0x3EE140
    virtual void createMe(DatapanelGUI* p, float vpos, bool lastLine) override;// protected RVA = 0x3EF3D0 vtable offset = 0x0
    void _NV_createMe(DatapanelGUI* p, float vpos, bool lastLine);// protected RVA = 0x3EF3D0 vtable offset = 0x0
    void clickButton(MyGUI::Widget* _sender);// protected RVA = 0x3EE1D0
    MyGUI::Button* btn0; // 0x120 Member
    MyGUI::Button* btn1; // 0x128 Member
    std::string command; // 0x130 Member
    virtual ~DataPanelLine_KeyConfig();// public RVA = 0x402F20 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x402F20 vtable offset = 0x0
    // no_addr class DataPanelLine_KeyConfig & operator=(const class DataPanelLine_KeyConfig & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};