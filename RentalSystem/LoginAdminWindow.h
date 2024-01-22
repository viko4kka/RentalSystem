#pragma once
#include <wx/wx.h>


class LoginAdminWindow : public wxFrame
{
public:
	LoginAdminWindow();

private:
	

	wxTextCtrl* txtAdminName;
	wxTextCtrl* txtAdminSurname;
	wxTextCtrl* txtAdminPassword;

	wxButton* loginButton;

	void OnLogin(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();

};

