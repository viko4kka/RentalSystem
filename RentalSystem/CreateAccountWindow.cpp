#include "CreateAccountWindow.h"

#include "AdminMainFrame.h"
#include "DataManagement.h"
#include "RentalSystemApp.h"

CreateAccountWindow::CreateAccountWindow() : wxFrame(nullptr, wxID_ANY, "Create Account", wxDefaultPosition, wxSize(800, 600))
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

	panel->SetBackgroundColour(wxColor(53, 45, 77));

	wxStaticText* userNameLabel = new wxStaticText(panel, wxID_ANY, "Enter you username: ");
	userNameLabel->SetForegroundColour(wxColor(255, 255, 255));
	userNameLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
	txtNewUsername = new wxTextCtrl(panel, wxID_ANY, "");
	txtNewUsername->SetBackgroundColour(wxColor(109, 97, 146));



	wxStaticText* userSurnameLabel = new wxStaticText(panel, wxID_ANY, "Enter your surname: ");
	userSurnameLabel->SetForegroundColour(wxColor(255, 255, 255));
	userSurnameLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
	txtNewSurname = new wxTextCtrl(panel, wxID_ANY, "");
	txtNewSurname->SetBackgroundColour(wxColor(109, 97, 146));


	wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Enter you password: ");
	passwordLabel->SetForegroundColour(wxColor(255, 255, 255));
	passwordLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
	txtNewpassword = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
	txtNewpassword->SetBackgroundColour(wxColor(109, 97, 146));


	adminCheckBox = new wxCheckBox(panel, wxID_ANY, "Are Admin?");
	adminCheckBox->SetBackgroundColour(wxColor(53, 45, 77)); // Ustawienie koloru t³a dla checkboxa
	adminCheckBox->SetForegroundColour(wxColor(255, 255, 255)); // Ustawienie koloru tekstu dla checkboxa


	wxButton* saveButton = new wxButton(panel, wxID_ANY, "Save");
	saveButton->Bind(wxEVT_BUTTON, &CreateAccountWindow::OnSave, this);
	saveButton->SetBackgroundColour(wxColor(146, 224, 169));

	vbox->Add(userNameLabel, 0, wxALL, 10);
	vbox->Add(txtNewUsername, 0, wxALL | wxEXPAND, 10); 
	vbox->Add(userSurnameLabel, 0, wxALL, 10);
	vbox->Add(txtNewSurname, 0, wxALL | wxEXPAND, 10); 
	vbox->Add(passwordLabel, 0, wxALL, 10);
	vbox->Add(txtNewpassword, 0, wxALL | wxEXPAND, 10); 
	vbox->Add(adminCheckBox, 0, wxEXPAND | wxALL, 10);
	vbox->AddSpacer(20);
	vbox->Add(saveButton, 0, wxALIGN_CENTER | wxALL, 10);

	panel->SetSizer(vbox);

	adminCheckBox->Bind(wxEVT_CHECKBOX, &CreateAccountWindow::OnAdminCheck, this);

}

void CreateAccountWindow::OnSave(wxCommandEvent& event)
{
	string newUserName = txtNewUsername->GetValue().ToStdString();
	string newUserSurname = txtNewSurname->GetValue().ToStdString();
	string newPassword = txtNewpassword->GetValue().ToStdString();
	bool isAdmin = adminCheckBox->GetValue();
	string isAdminStr = (isAdmin) ? "true" : "false";
	DataManager manager;


	User tempUser = User(newUserName, newUserSurname, newPassword, isAdminStr);
	bool saveResult = DataManager::saveUserData(tempUser);

	if (saveResult) {
		wxMessageBox("Account created successfully", "Success", wxOK | wxICON_INFORMATION);
		this->Hide(); // Hide the CreateAccountWindow

		// Check if the user is an admin, then show AdminMainFrame, else show RentalSystemMainFrame
		if (isAdmin) {

			AdminMainFrame* adminFrame = new AdminMainFrame("Admin Panel", wxDefaultPosition, wxSize(800, 600));
			adminFrame->Center();
			adminFrame->Show(true);
		}
		else {

			RentalSystemMainFrame* rentalFrame = new RentalSystemMainFrame("Car Rental System", wxDefaultPosition, wxSize(800, 600));
			rentalFrame->Center();
			rentalFrame->Show(true);
		}

	}
	else {
		wxMessageBox("Failed to create account!", "Error", wxOK | wxICON_ERROR);
	}


}

void CreateAccountWindow::OnAdminCheck(wxCommandEvent& event)
{
	bool isAdmin = adminCheckBox->GetValue(); // Pobranie stanu zaznaczenia checkboxa


	if (isAdmin) {
		std::cout << "Admin privileges granted." << std::endl;
	}
	else {
		std::cout << "Admin privileges not granted." << std::endl;
	}
}

wxBEGIN_EVENT_TABLE(CreateAccountWindow, wxFrame)
EVT_BUTTON(wxID_ANY, CreateAccountWindow::OnSave)
wxEND_EVENT_TABLE()




