#pragma once
/* Includes ------------------------------------------------------------------*/
#include <wx/wx.h>
#include <wx/tglbtn.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	void CreateControls();

	// Bind events
	void OnTextCtrl(wxCommandEvent& evt);
	void OnRadioBox(wxCommandEvent& evt);
	void OnSlider(wxCommandEvent& evt);
	void OnCheckbox(wxCommandEvent& evt);
	void OnChoice(wxCommandEvent& evt);
	void OnButton(wxCommandEvent& evt);
	void OnToggleButton(wxCommandEvent& evt);

	// Controls
	wxPanel* panel;
	wxStaticText* appStaticText;
	wxStaticText* wxTextCtrlText;
	wxTextCtrl* inputField;
	wxStaticText* wxRadioBoxText;
	wxRadioBox* radioBox;
	wxStaticText* wxSliderText;
	wxSlider* slider;
	wxStaticText* wxCheckBoxText;
	wxCheckBox* checkBox;
	wxStaticText* wxChoiceText;
	wxChoice* choice;
	wxStaticText* wxButtonText;
	wxButton* button;
	wxStaticText* wxToggleButtonText;
	wxToggleButton* toggleButton;

	wxCheckListBox* checkList;
	wxButton* clearButton;
};

/* ------------------------- END OF FILE ---------------------------------------*/
