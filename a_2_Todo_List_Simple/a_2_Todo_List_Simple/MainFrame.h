#pragma once
/* Includes ------------------------------------------------------------------*/
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	void CreateControls();
	void BindEventHandler();
	void AddSavedTasks();		// Add texts into App from text file

	// Events
	void OnAddButtonClicked(wxCommandEvent& evt);
	void OnListKeyDown(wxKeyEvent& evt);
	void OnClearButtonClicked(wxCommandEvent& evt);
	void OnWindowClosed(wxCloseEvent& evt);

	// Helper functions
	void AddTaskFromInput();
	void DeleteSelectedTask();

	// Controls
	wxPanel* panel;
	wxTextCtrl* inputField;
	wxButton* addButton;
	wxCheckListBox* checkList;
	wxButton* clearButton;
};

/* ------------------------- END OF FILE ---------------------------------------*/
