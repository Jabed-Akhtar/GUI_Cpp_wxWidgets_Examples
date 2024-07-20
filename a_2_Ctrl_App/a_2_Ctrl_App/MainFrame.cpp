/* Includes ------------------------------------------------------------------*/
#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>

// Main Frame ===============
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateControls();
}

void MainFrame::CreateControls()
{
	wxFont statusbarText(wxFontInfo(wxSize(0, 24)));
	wxFont appText(wxFontInfo(wxSize(0, 30)));
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));
	wxFont subCtrlFont(wxFontInfo(wxSize(0, 20)));

	CreateStatusBar();
	GetStatusBar()->SetMinHeight(40);
	GetStatusBar()->SetFont(statusbarText);

	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	/***** wxStaticText *****/
	appStaticText = new wxStaticText(
		panel,
		wxID_ANY,
		"Ctrl App :)",
		wxPoint(30, 30),
		wxSize(540, 35),
		wxALIGN_CENTER
		);
	appStaticText->SetFont(appText);

	/***** wxTextCtrl *****/
	wxTextCtrlText = new wxStaticText(
		panel,
		wxID_ANY,
		"wxTextCtrl:",
		wxPoint(30, 85),
		wxSize(150, 35),
		wxALIGN_RIGHT
	);
	wxTextCtrlText->SetFont(mainFont);
	inputField = new wxTextCtrl(
		panel,
		wxID_ANY,
		"Default text.",
		wxPoint(200, 85),
		wxSize(370, 35),
		wxTE_LEFT
	);
	
	/***** wxRadioButton *****/
	wxRadioBoxText = new wxStaticText(
		panel,
		wxID_ANY,
		"wxRadioBox:",
		wxPoint(30, 140),
		wxSize(150, 35),
		wxALIGN_RIGHT
	);
	wxRadioBoxText->SetFont(mainFont);
	
	wxArrayString choices;
	choices.Add("Item#1");
	choices.Add("Item#2");
	choices.Add("Item#3");

	radioBox = new wxRadioBox(
		panel,
		wxID_ANY,
		"Choose one",
		wxPoint(200, 140),
		wxSize(370, -1),
		choices
	);
	radioBox->SetFont(subCtrlFont);
	
	/***** wxSlider *****/
	wxSliderText = new wxStaticText(
		panel,
		wxID_ANY,
		"wxSlider:",
		wxPoint(30, 250),
		wxSize(150, 35),
		wxALIGN_RIGHT
	);
	wxSliderText->SetFont(mainFont);
	
	slider = new wxSlider(
		panel,
		wxID_ANY,
		5,
		0,
		100,
		wxPoint(200, 250),
		wxSize(370, 35),
		wxSL_VALUE_LABEL
	);

	/***** wxCheckBox *****/
	wxCheckBoxText = new wxStaticText(
		panel,
		wxID_ANY,
		"wxCheckBox:",
		wxPoint(30, 305),
		wxSize(150, 35),
		wxALIGN_RIGHT
	);
	wxCheckBoxText->SetFont(mainFont);

	checkBox = new wxCheckBox(
		panel,
		wxID_ANY,
		"Door closed!",
		wxPoint(200, 305),
		wxSize(370, 35),
		wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER
	);

	/***** wxChoice *****/
	wxChoiceText = new wxStaticText(
		panel,
		wxID_ANY,
		"wxChoice:",
		wxPoint(30, 360),
		wxSize(150, 35),
		wxALIGN_RIGHT
	);
	wxChoiceText->SetFont(mainFont);

	wxArrayString choices_wxChoice;
	choices_wxChoice.Add("---");
	choices_wxChoice.Add("Item#1");
	choices_wxChoice.Add("Item#2");
	choices_wxChoice.Add("Item#3");

	choice = new wxChoice(
		panel,
		wxID_ANY,
		wxPoint(200, 360),
		wxSize(370, 35),
		choices_wxChoice,
		wxCB_SORT
	);
	choice->SetSelection(0);

	/***** wxChoice *****/
	wxButtonText = new wxStaticText(
		panel,
		wxID_ANY,
		"wxButton:",
		wxPoint(30, 415),
		wxSize(150, 35),
		wxALIGN_RIGHT
	);
	wxButtonText->SetFont(mainFont);

	button = new wxButton(
		panel,
		wxID_ANY,
		"Button",
		wxPoint(200, 415),
		wxSize(370, 35)
	);

	/***** wxToggleButton *****/
	wxToggleButtonText = new wxStaticText(
		panel,
		wxID_ANY,
		"wxToggleButton:",
		wxPoint(30,470),
		wxSize(150, 35),
		wxALIGN_RIGHT
	);
	wxToggleButtonText->SetFont(mainFont);

	toggleButton = new wxToggleButton(
		panel,
		wxID_ANY,
		"Button Toggle OFF",
		wxPoint(200, 470),
		wxSize(370, 35)
	);

	// binding events
	inputField->Bind(wxEVT_TEXT, &MainFrame::OnTextCtrl, this);
	radioBox->Bind(wxEVT_RADIOBOX, &MainFrame::OnRadioBox, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSlider, this);
	checkBox->Bind(wxEVT_CHECKBOX, &MainFrame::OnCheckbox, this);
	choice->Bind(wxEVT_CHOICE, &MainFrame::OnChoice, this);
	button->Bind(wxEVT_BUTTON, &MainFrame::OnButton, this);
	toggleButton->Bind(wxEVT_TOGGLEBUTTON, &MainFrame::OnToggleButton, this);
}

void MainFrame::OnTextCtrl(wxCommandEvent& evt)
{
	wxString str = wxString::Format("Text in TextCtrl: %s", evt.GetString());
	wxLogStatus(str);
}

void MainFrame::OnRadioBox(wxCommandEvent& evt)
{
	wxString str = wxString::Format("RadioBox selected: %s", evt.GetString());
	wxLogStatus(str);
}

void MainFrame::OnSlider(wxCommandEvent& evt)
{
	wxString str = wxString::Format("Slider value: %d", evt.GetInt());
	wxLogStatus(str);
}

void MainFrame::OnCheckbox(wxCommandEvent& evt)
{
	wxString str = wxString::Format("Checkbox value: %d", evt.GetInt());
	wxLogStatus(str);

	if (evt.GetInt() == 0)
	{
		checkBox->SetLabelText("Door closed!");
	}
	else if (evt.GetInt() == 1)
	{
		checkBox->SetLabelText("Door opened!");
	}
	else
	{
		checkBox->SetLabelText("Door left unlocked!");
	}
}

void MainFrame::OnChoice(wxCommandEvent& evt)
{
	wxString str = wxString::Format("Slider value: %s", evt.GetString());
	wxLogStatus(str);
}

void MainFrame::OnButton(wxCommandEvent& evt)
{
	wxString str = wxString::Format("Button Pressed!");
	wxLogStatus(str);
}

void MainFrame::OnToggleButton(wxCommandEvent& evt)
{
	if (evt.GetInt() == 0)
	{
		toggleButton->SetLabelText("Button Toggle OFF");
	}
	else if (evt.GetInt() == 1)
	{
		toggleButton->SetLabelText("Button Toggle ON");
	}

	wxString str = wxString::Format("Toggle-Button value: %d", evt.GetInt());
	wxLogStatus(str);
}

/* ------------------------- END OF FILE ---------------------------------------*/
