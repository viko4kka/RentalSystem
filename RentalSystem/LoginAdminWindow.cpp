#include "LoginAdminWindow.h"
#include <wx/wx.h>

using namespace std;

LoginAdminWindow::LoginAdminWindow() : wxFrame(nullptr, wxID_ANY, "Login Admin Window", wxDefaultPosition, wxSize(800, 600))
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	panel->SetBackgroundColour(wxColor(53, 45, 77));

	wxStaticText* adminNameLabel = new wxStaticText(panel, wxID_ANY, "Admin Name: ");
	adminNameLabel->SetForegroundColour(wxColor(255, 255, 255));
	adminNameLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
	txtAdminName = new wxTextCtrl(panel, wxID_ANY, "");

	wxStaticText* adminSurnameLabel = new wxStaticText(panel, wxID_ANY, "Admin Surname: ");
	adminSurnameLabel->SetForegroundColour(wxColor(255, 255, 255));
	adminSurnameLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
	txtAdminSurname = new wxTextCtrl(panel, wxID_ANY, "");

	wxStaticText* adminPasswordLabel = new wxStaticText(panel, wxID_ANY, "Admin password: ");
	adminPasswordLabel->SetForegroundColour(wxColor(255, 255, 255));
	adminPasswordLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
	txtAdminPassword = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);

	loginButton = new wxButton(panel, wxID_ANY, "Login");
	loginButton->SetBackgroundColour(wxColor(146, 224, 169));

	vbox->Add(adminNameLabel, 0, wxEXPAND | wxALL, 10);
	vbox->Add(txtAdminName, 0, wxEXPAND | wxALL, 10);
	vbox->Add(adminSurnameLabel, 0, wxEXPAND | wxALL, 10);
	vbox->Add(txtAdminSurname, 0, wxEXPAND | wxALL, 10);
	vbox->Add(adminPasswordLabel, 0, wxEXPAND | wxALL, 10);
	vbox->Add(txtAdminPassword, 0, wxEXPAND | wxALL, 10);
	vbox->Add(loginButton, 0, wxALIGN_CENTER | wxALL, 10);
	

	panel->SetSizer(vbox);
	Center();

	loginButton->Bind(wxEVT_BUTTON, &LoginAdminWindow::OnLogin, this);
}

void LoginAdminWindow::OnLogin(wxCommandEvent& event)
{
	wxString adminName = txtAdminName->GetValue();
	wxString adminSurname = txtAdminSurname->GetValue();
	wxString adminPassword = txtAdminPassword->GetValue();

	//if()
	////T
}


wxBEGIN_EVENT_TABLE(LoginAdminWindow, wxFrame)
EVT_BUTTON(wxID_ANY, LoginAdminWindow::OnLogin)
wxEND_EVENT_TABLE()
