#pragma once
#include <wx/wx.h>
#include "User.h"

class LoginWindow : public wxFrame
{
public:
	LoginWindow();



private:

	User currentUser;

	wxTextCtrl* txtUserName;
	wxTextCtrl* txtUserSurname;
	wxTextCtrl* txtPassword;
	wxButton* createAccountButton;


	void OnLogin(wxCommandEvent& event);
	void OnCreateAccount(wxCommandEvent& event);



	wxDECLARE_EVENT_TABLE();
};

