/***************************************************************
 * Name:      Quadratic_equation_wxwidgetsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Talipov S.N. (talipovsn@gmail.com)
 * Created:   2020-03-02
 * Copyright: Talipov S.N. (https://github.com/tsnsoft)
 * License:
 **************************************************************/

#include "Quadratic_equation_wxwidgetsMain.h"
#include <wx/msgdlg.h>

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

//(*InternalHeaders(Quadratic_equation_wxwidgetsFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Quadratic_equation_wxwidgetsFrame)
const long Quadratic_equation_wxwidgetsFrame::ID_STATICTEXT1 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_STATICTEXT2 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_STATICTEXT3 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_STATICTEXT4 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_STATICTEXT5 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_TEXTCTRL1 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_TEXTCTRL2 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_TEXTCTRL3 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_TEXTCTRL4 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_TEXTCTRL5 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_BUTTON1 = wxNewId();
const long Quadratic_equation_wxwidgetsFrame::ID_STATICBITMAP1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Quadratic_equation_wxwidgetsFrame,wxFrame)
    //(*EventTable(Quadratic_equation_wxwidgetsFrame)
    //*)
END_EVENT_TABLE()

Quadratic_equation_wxwidgetsFrame::Quadratic_equation_wxwidgetsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Quadratic_equation_wxwidgetsFrame)
    Create(parent, id, _("Решение квадратного уравнения"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(382,237));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("D:\\Documents\\talipov.s\\CPP\\Quadratic_equation_wxwidgets\\qe.jpg"))));
    	SetIcon(FrameIcon);
    }
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("a="), wxPoint(32,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("b="), wxPoint(32,72), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("c="), wxPoint(32,96), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("x1="), wxPoint(200,40), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("x2="), wxPoint(200,64), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    TextCtrl_a = new wxTextCtrl(this, ID_TEXTCTRL1, _("0"), wxPoint(56,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl_b = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxPoint(56,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl_c = new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxPoint(56,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl_x1 = new wxTextCtrl(this, ID_TEXTCTRL4, _("0"), wxPoint(224,32), wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl_x2 = new wxTextCtrl(this, ID_TEXTCTRL5, _("0"), wxPoint(224,64), wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    Button_Calc = new wxButton(this, ID_BUTTON1, _("Решить"), wxPoint(56,136), wxSize(280,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("D:\\Documents\\talipov.s\\CPP\\Quadratic_equation_wxwidgets\\qe.jpg"))), wxPoint(160,184), wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Quadratic_equation_wxwidgetsFrame::OnButton_CalcClick);
    //*)
}

Quadratic_equation_wxwidgetsFrame::~Quadratic_equation_wxwidgetsFrame()
{
    //(*Destroy(Quadratic_equation_wxwidgetsFrame)
    //*)
}

// Решение квадратного уравнения
void Quadratic_equation_wxwidgetsFrame::OnButton_CalcClick(wxCommandEvent& event)
{
    try {
        ostringstream x1_, x2_; x1_.precision(3); x2_.precision(3);
        double a = strtod(TextCtrl_a->GetValue(), NULL);
        double b = strtod(TextCtrl_b->GetValue(), NULL);
        double c = strtod(TextCtrl_c->GetValue(), NULL);
        double d, x1, x2;
        d = b*b - 4*a*c;
        x1 = (-b-sqrt(d))/(2*a);
        x2 = (-b+sqrt(d))/(2*a);
        if (isnan(x1) || isnan(x2) || isinf(x1) || isinf(x2)) { throw logic_error(""); }
        x1_ << x1; x2_ << x2;
        TextCtrl_x1->SetValue(x1_.str());
        TextCtrl_x2->SetValue(x2_.str());
    } catch (...) {
        TextCtrl_x1->SetValue("???");
        TextCtrl_x2->SetValue("???");
    }
}

// Выход из программы
void Quadratic_equation_wxwidgetsFrame::OnCloseWindow(wxCloseEvent& event)
{
    Close();
}
