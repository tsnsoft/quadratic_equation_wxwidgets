/***************************************************************
 * Name:      Quadratic_equation_wxwidgetsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Talipov S.N. (talipovsn@gmail.com)
 * Created:   2020-03-02
 * Copyright: Talipov S.N. (https://github.com/tsnsoft)
 * License:
 **************************************************************/

#include "Quadratic_equation_wxwidgetsApp.h"

//(*AppHeaders
#include "Quadratic_equation_wxwidgetsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Quadratic_equation_wxwidgetsApp);

bool Quadratic_equation_wxwidgetsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Quadratic_equation_wxwidgetsFrame* Frame = new Quadratic_equation_wxwidgetsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
