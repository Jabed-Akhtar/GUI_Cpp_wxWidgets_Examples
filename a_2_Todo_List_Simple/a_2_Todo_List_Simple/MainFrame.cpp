/* Includes ------------------------------------------------------------------*/
#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>
#include "Task.h"

// Main Frame ===============
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateControls();
	BindEventHandler();
	AddSavedTasks();
}

void MainFrame::CreateControls()
{
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(30, 30), wxSize(340, 35));
	addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(30, 85), wxSize(100, 35));
	checkList = new wxCheckListBox(panel, wxID_ANY, wxPoint(30, 140), wxSize(340, 355));
	clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(30, 515), wxSize(100, 35));
}

void MainFrame::BindEventHandler()
{
	addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
	checkList->Bind(wxEVT_KEY_DOWN, &MainFrame::OnListKeyDown, this);
	clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnWindowClosed, this);
}

/*
* Add text into the App from text file (tasks.txt)
*/
void MainFrame::AddSavedTasks()
{
	std::vector<Task> tasks = loadTasksFromFile("tasks.txt");

	for (const Task& task : tasks)
	{
		int index = checkList->GetCount();
		checkList->Insert(task.description, index);
		checkList->Check(index, task.done);
	}
}

/*
* Add task on clicking 'Add' button
*/
void MainFrame::OnAddButtonClicked(wxCommandEvent& evt)
{
	AddTaskFromInput();
}

/*
* Remove selected task on pressing 'Delete' button on keyboard
*/
void MainFrame::OnListKeyDown(wxKeyEvent& evt)
{
	switch (evt.GetKeyCode())
	{
	case WXK_DELETE:
		DeleteSelectedTask();
		break;
	}
}

/*
* Clear all tasks
*/
void MainFrame::OnClearButtonClicked(wxCommandEvent& evt)
{
	if (checkList->IsEmpty())
	{
		return;
	}

	wxMessageDialog dialog(this, "Sure about deleting the selected tasks?",
		"Clear", wxYES_NO | wxCANCEL);
	int result = dialog.ShowModal();

	if (result == wxID_YES)
	{
		checkList->Clear();
	}
}

/*
* On closing the App / window, save the data into tasks.txt file
*/
void MainFrame::OnWindowClosed(wxCloseEvent& evt)
{
	std::vector<Task> tasks;

	for (int i = 0; i < checkList->GetCount(); i++)
	{
		Task task;
		task.description = checkList->GetString(i);
		task.done = checkList->IsChecked(i);
		tasks.push_back(task);
	}

	saveTasksToFile(tasks, "tasks.txt"); // Create or overwrite file
	evt.Skip();
}

/*
* Helper function to add task from Input field
*/
void MainFrame::AddTaskFromInput()
{
	wxString description = inputField->GetValue();

	if (!description.IsEmpty())
	{
		checkList->Insert(description, checkList->GetCount());
		inputField->Clear();
	}

	inputField->SetFocus();
}

/*
* Helper function to delete tasks
* Select the task > delete it using Keyboad Delete button
*/
void MainFrame::DeleteSelectedTask()
{
	int selectedIndex = checkList->GetSelection();

	if (selectedIndex == wxNOT_FOUND)
	{
		return;
	}

	checkList->Delete(selectedIndex);
}

/* ------------------------- END OF FILE ---------------------------------------*/
