#include <wx/wx.h>

class App : public wxApp {
public:
    bool OnInit() {
        // Main window
        wxFrame* window = new wxFrame(NULL, wxID_ANY, "App | Hello World!", wxDefaultPosition, wxSize(400, 300));

        // wx-Box
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

        // Text
        wxStaticText* text = new wxStaticText(window, wxID_ANY, "Hi there :)",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
        text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

        // Add to wx-Box
        sizer->Add(text, 1, wxALIGN_CENTER);

        // Add to window
        window->SetSizer(sizer);
        window->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);
