#include "UserLoginWindow.h"
#include "LoginWindow.h"
#include "RentalSystemApp.h"

UserLoginWindow::UserLoginWindow() : wxFrame(nullptr, wxID_ANY, "Hello", wxDefaultPosition, wxSize(800, 600))
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	panel->SetBackgroundColour(wxColor(53, 45, 77));

	userLoginButton = new wxButton(panel, wxID_ANY, "Log in like User");
	userLoginButton->SetBackgroundColour(wxColor(146, 224, 169));


	vbox->AddStretchSpacer();
	vbox->Add(userLoginButton, 0, wxALIGN_CENTER | wxALL, 20);

	vbox->AddStretchSpacer();

	panel->SetSizer(vbox);

	userLoginButton->Bind(wxEVT_BUTTON, &UserLoginWindow::OnUserLogin, this);


}

void UserLoginWindow::OnUserLogin(wxCommandEvent& event)
{
	// Przechodzimy do okna logowania u¿ytkownika
	LoginWindow* loginWindow = new LoginWindow();
	loginWindow->Center();
	loginWindow->Show();

	this->Hide();
}




wxBEGIN_EVENT_TABLE(UserLoginWindow, wxFrame)
EVT_BUTTON(wxID_ANY, UserLoginWindow::OnUserLogin)
wxEND_EVENT_TABLE()
