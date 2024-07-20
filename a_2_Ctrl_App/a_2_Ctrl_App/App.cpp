/* Includes ------------------------------------------------------------------*/
#include "App.h"
#include "MainFrame.h"

// Entry point for the App ===============
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    // Main Frame for all components
    MainFrame* mainFrame = new MainFrame("Todo App");
    mainFrame->SetClientSize(600, 600);
    mainFrame->Center();
    mainFrame->Show();

    return true;
}

/* ------------------------- END OF FILE ---------------------------------------*/

