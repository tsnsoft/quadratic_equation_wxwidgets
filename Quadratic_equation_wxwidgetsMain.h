/***************************************************************
 * Name:      Quadratic_equation_wxwidgetsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Talipov S.N. (talipovsn@gmail.com)
 * Created:   2020-03-02
 * Copyright: Talipov S.N. (https://github.com/tsnsoft)
 * License:
 **************************************************************/

#ifndef QUADRATIC_EQUATION_WXWIDGETSMAIN_H
#define QUADRATIC_EQUATION_WXWIDGETSMAIN_H

//(*Headers(Quadratic_equation_wxwidgetsFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Quadratic_equation_wxwidgetsFrame: public wxFrame
{
    public:

        Quadratic_equation_wxwidgetsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Quadratic_equation_wxwidgetsFrame();

    private:

        //(*Handlers(Quadratic_equation_wxwidgetsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton_CalcClick(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnQ(wxCloseEvent& event);
        void OnExit(wxCloseEvent& event);
        void OnClose1(wxCloseEvent& event);
        void OnCloseWindow(wxCloseEvent& event);
        //*)

        //(*Identifiers(Quadratic_equation_wxwidgetsFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON1;
        static const long ID_STATICBITMAP1;
        //*)

        //(*Declarations(Quadratic_equation_wxwidgetsFrame)
        wxButton* Button_Calc;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxTextCtrl* TextCtrl_a;
        wxTextCtrl* TextCtrl_b;
        wxTextCtrl* TextCtrl_c;
        wxTextCtrl* TextCtrl_x1;
        wxTextCtrl* TextCtrl_x2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // QUADRATIC_EQUATION_WXWIDGETSMAIN_H
