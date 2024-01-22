#pragma once
#include <wx/wx.h>


class UserLoginWindow : public wxFrame
{
public:
	UserLoginWindow();



private:
	wxButton* userLoginButton;


	void OnUserLogin(wxCommandEvent& event);


	wxDECLARE_EVENT_TABLE();

};



