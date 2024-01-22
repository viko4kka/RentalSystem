#include "LoginWindow.h"
#include "RentalSystemApp.h"
#include "CreateAccountWindow.h"
#include "User.h"
#include "AdminMainFrame.h"



using namespace std;

LoginWindow::LoginWindow() :wxFrame(nullptr, wxID_ANY, "Login", wxDefaultPosition, wxSize(800, 600))
{
    // Tworzymy panele
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    panel->SetBackgroundColour(wxColor(53, 45, 77));

    // Tworzenie panela na dane logowania
    wxPanel* loginPanel = new wxPanel(panel, wxID_ANY);
    wxBoxSizer* loginSizer = new wxBoxSizer(wxVERTICAL);

    // Tworzymy elementy interfejsu u¿ytkownika
    wxStaticText* userNameLabel = new wxStaticText(panel, wxID_ANY, "User name:");
    userNameLabel->SetForegroundColour(wxColor(255, 255, 255));
    userNameLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
    txtUserName = new wxTextCtrl(panel, wxID_ANY, "");
    txtUserName->SetBackgroundColour(wxColor(109, 97, 146));

    wxStaticText* userSurnameLabel = new wxStaticText(panel, wxID_ANY, "User surname:");
    userSurnameLabel->SetForegroundColour(wxColor(255, 255, 255));
    userSurnameLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
    txtUserSurname = new wxTextCtrl(panel, wxID_ANY, "");
    txtUserSurname->SetBackgroundColour(wxColor(109, 97, 146));

    wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password:");
    passwordLabel->SetForegroundColour(wxColor(255, 255, 255));
    passwordLabel->SetFont(wxFont(wxFontInfo(12).Bold()));
    txtPassword = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    txtPassword->SetBackgroundColour(wxColor(109, 97, 146));

    wxButton* loginButton = new wxButton(panel, wxID_ANY, "Login");
    loginButton->SetBackgroundColour(wxColor(146, 224, 169));

    createAccountButton = new wxButton(panel, wxID_ANY, "Create Account");
    createAccountButton->SetBackgroundColour(wxColor(146, 224, 169));




    // Dodajemy elementy do sizerów
    vbox->Add(userNameLabel, 0, wxEXPAND | wxALL, 10);
    vbox->Add(txtUserName, 0, wxEXPAND | wxALL, 10);
    vbox->Add(userSurnameLabel, 0, wxEXPAND | wxALL, 10);
    vbox->Add(txtUserSurname, 0, wxEXPAND | wxALL, 10);
    vbox->Add(passwordLabel, 0, wxEXPAND | wxALL, 10);
    vbox->Add(txtPassword, 0, wxEXPAND | wxALL, 10);
    vbox->AddSpacer(20);
    vbox->Add(createAccountButton, 0, wxLEFT, 15);
    vbox->Add(loginButton, 0, wxLEFT, 15);
    vbox->Add(loginPanel, 0, wxALIGN_CENTER | wxALL, 10);
    loginPanel->SetSizer(loginSizer);



    // Przypisanie zdarzenia klikniêcia przycisku do funkcji OnLogin
    loginButton->Bind(wxEVT_BUTTON, &LoginWindow::OnLogin, this);
    createAccountButton->Bind(wxEVT_BUTTON, &LoginWindow::OnCreateAccount, this);
    panel->SetSizer(vbox);

    

}


void LoginWindow::OnLogin(wxCommandEvent& event)
{

    // Pobranie danych z pól tekstowych (txtUserName, txtUserSurname, txtPassword)
    string userName = txtUserName->GetValue().ToStdString();
    string userSurname = txtUserSurname->GetValue().ToStdString();
    string password = txtPassword->GetValue().ToStdString();
    bool isAdmin;

    // Sprawdzenie autoryzacji
    // Za³ó¿my, ¿e masz obiekt `currentUser` z danymi u¿ytkownika oraz metodê `authenticate()`
    if (currentUser.authenticate(userName, userSurname, password, isAdmin)) {
        wxMessageBox("Login successful!", "Success", wxOK | wxICON_INFORMATION);

        this->Hide();

        if (isAdmin) {

            AdminMainFrame* adminFrame = new AdminMainFrame("Admin Panel", wxDefaultPosition, wxSize(800, 600));
            adminFrame->Center();
            adminFrame->Show(true);
        }
        else {

            // Pobierz wskaŸnik do aplikacji
            RentalSystemApp* app = dynamic_cast<RentalSystemApp*>(wxTheApp);
            if (app) {
                // Jeœli autoryzacja siê powiod³a, wywo³aj funkcjê OnLoginSuccess w klasie RentalSystemApp
                app->OnLoginSuccess();
            }
        }


    }
    else {
        wxMessageBox("Invalid username or password!", "Error", wxOK | wxICON_ERROR);
    }


};


void LoginWindow::OnCreateAccount(wxCommandEvent& event)
{
    CreateAccountWindow* createAccountWindow = new CreateAccountWindow();
    createAccountWindow->Center();
    createAccountWindow->Show(true);
    this->Hide();
}



wxBEGIN_EVENT_TABLE(LoginWindow, wxFrame)
EVT_BUTTON(wxID_ANY, LoginWindow::OnLogin) // Przypisanie zdarzenia klikniêcia do funkcji OnLogin
wxEND_EVENT_TABLE()