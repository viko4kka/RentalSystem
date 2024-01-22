#pragma once
#include <wx/wx.h>

using namespace std;

class CreateAccountWindow : public wxFrame
{
public:
	CreateAccountWindow();

	void OnSave(wxCommandEvent& event);

private:

	wxTextCtrl* txtNewUsername;
	wxTextCtrl* txtNewSurname;
	wxTextCtrl* txtNewpassword;
	wxCheckBox* adminCheckBox;


	void OnAdminCheck(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();

};

