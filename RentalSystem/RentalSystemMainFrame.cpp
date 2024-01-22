#include "RentalSystemMainFrame.h"
#include "LoginWindow.h"
#include <wx/wx.h>
#include <wx/splitter.h>
#include <string.h>
#include "DataManagement.h"
#include "User.h"

using namespace std;


wxBEGIN_EVENT_TABLE(RentalSystemMainFrame, wxFrame)
EVT_LISTBOX(wxID_ANY, RentalSystemMainFrame::OnCarSelected)
EVT_BUTTON(wxID_ANY, RentalSystemMainFrame::OnBackButton)
EVT_BUTTON(wxID_ANY, RentalSystemMainFrame::OnChooseButton)
wxEND_EVENT_TABLE()

RentalSystemMainFrame::RentalSystemMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	panel->SetBackgroundColour(wxColor(53, 45, 77));

	//tworzenie glownego sizera
	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);


	// Tworzenie panelu na szczegó³y auta
	detailsPanel = new wxPanel(panel, wxID_ANY);
	detailsPanel->SetBackgroundColour(wxColor(146, 224, 169));

	// Tworzenie elementów na panelu szczegó³ów
	detailsText = new wxStaticText(detailsPanel, wxID_ANY, wxEmptyString);
	wxFont font = detailsText->GetFont();  //Pobieramy bie¿¹c¹ czcionkê
	font.SetPointSize(12); //Ustawiamy wielkosc
	detailsText->SetFont(font);

	// Tworzenie przycisków
	backButton = new wxButton(panel, wxID_ANY, "Back");
	chooseButton = new wxButton(panel, wxID_ANY, "Choose");


	// Ustalenie struktury okna
	wxBoxSizer* detailsSizer = new wxBoxSizer(wxVERTICAL);
	detailsSizer->Add(detailsText, 1, wxEXPAND | wxALL, 10);
	detailsPanel->SetSizer(detailsSizer);

	wxBoxSizer* buttonsSizer = new wxBoxSizer(wxHORIZONTAL);
	buttonsSizer->Add(backButton, 0, wxALL, 10);
	buttonsSizer->Add(chooseButton, 0, wxALL, 10);
	logoutButton = new wxButton(panel, wxID_ANY, "log out");

	wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
	leftSizer->Add(detailsPanel, 1, wxEXPAND | wxALL, 10);
	leftSizer->Add(buttonsSizer, 0, wxEXPAND);

	mainSizer->Add(leftSizer, 1, wxEXPAND);

	logoutButton->Bind(wxEVT_BUTTON, &RentalSystemMainFrame::OnLogout, this);
	chooseButton->Bind(wxEVT_BUTTON, &RentalSystemMainFrame::OnChooseButton, this);
	//// Ustalenie listy aut
	carList = new wxListBox(panel, wxID_ANY, wxDefaultPosition, wxSize(300, wxDefaultCoord), 0, nullptr, wxLB_SINGLE | wxLB_ALWAYS_SB);
	carList->Bind(wxEVT_LISTBOX, &RentalSystemMainFrame::OnCarSelected, this);

	buttonsSizer->Add(logoutButton, 0, wxALL, 10);
	mainSizer->Add(carList, 0, wxEXPAND | wxALL, 10);

	panel->SetSizer(mainSizer);

	DataManager management;

	cars = management.loadCarsData();

	for (int i = 0;i<cars.get_size();++i)
	{
		carList->Append(cars[i].GetMark() + " " + cars[i].GetModel());
	}


	//ustalanie szerokosci komorek
	wxClientDC dc(carList);
	int maxWidth = 0;
	for (unsigned int i = 0; i < carList->GetCount(); i++)
	{
		int width = 0;
		dc.GetTextExtent(carList->GetString(i), &width, nullptr);
		maxWidth = max(maxWidth, width);
	}



};


void RentalSystemMainFrame::OnCarSelected(wxCommandEvent& event)
{

	int selection = carList->GetSelection();
	if (selection != wxNOT_FOUND && selection < static_cast<int>(cars.get_size())) {
		detailsPanelVisible = true;

		wxString details = wxString::Format(
			"Brand: %s\nModel:  %s\nColor: %s\nYear: %s\nAutomatic: %s\nOwner: %s\nPrice: %s",
			cars[selection].GetMark(), cars[selection].GetModel(), cars[selection].GetColor(), cars[selection].GetYear(),
			cars[selection].GetIsAutomatic(), cars[selection].GetOwner(), cars[selection].GetPrice()
		);

		detailsText->SetLabel(details);

		detailsPanel->Show(); // Poka¿ panel z szczegó³ami
		detailsPanel->SetBackgroundColour(wxColor(146, 224, 169)); // Ustaw kolor t³a na zielony
		Layout(); // Ponowne ustawienie layoutu
	}
}

void RentalSystemMainFrame::OnBackButton(wxCommandEvent& event) {
	detailsPanelVisible = false; // Ustaw stan panelu na niewidoczny
	detailsPanel->Hide(); // Ukryj panel ze szczegó³ami auta
	detailsPanel->Refresh(); // Odœwie¿, aby zastosowaæ zmiany wizualne
}

void RentalSystemMainFrame::OnChooseButton(wxCommandEvent& event) {
	int selection = carList->GetSelection();
	if (selection != wxNOT_FOUND && selection < static_cast<int>(cars.get_size())) {
		detailsPanelVisible = true; // Ustaw stan panelu na widoczny
		detailsPanel->Show(); // Poka¿ panel ze szczegó³ami auta

		// Kod wyœwietlaj¹cy szczegó³y wybranego auta...

		// Wyœwietlenie komunikatu
		//wxMessageBox("Good choice, thanks for using our company", "Success", wxOK | wxICON_INFORMATION);

		DataManager dataManager;
		Vector<RentedCar> rentedCars = dataManager.loadRentedCarData();

		bool isCarRented = false;

			for (int i = 0;i<rentedCars.get_size();++i)
			{
				if (cars[selection].GetMark() == rentedCars[i].GetMark() && cars[selection].GetModel() == rentedCars[i].GetModel() && cars[selection].GetYear() == rentedCars[i].GetYear())
					isCarRented = true;
				else
					isCarRented = false;
			}

		if(isCarRented)
			wxMessageBox("Car is already rented!");
		else
		{
			RentedCar temp = RentedCar(cars[selection].GetMark(), cars[selection].GetModel(), cars[selection].GetYear());
			dataManager.saveRentedCarData(temp);

			wxMessageBox("You rented a car!");
		}
			
		

	}

}


//=======================================================================
RentalSystemMainFrame::RentalSystemMainFrame() :wxFrame(nullptr, wxID_ANY, "Login", wxDefaultPosition, wxDefaultSize)
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

	wxStaticText* userNameLabel = new wxStaticText(panel, wxID_ANY, "User name:");
	txtUserName = new wxTextCtrl(panel, wxID_ANY, "");

	wxStaticText* userSurnameLabel = new wxStaticText(panel, wxID_ANY, "User surname:");
	txtUserSurname = new wxTextCtrl(panel, wxID_ANY, "");

	wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password:");
	txtPassword = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);

	wxButton* loginButton = new wxButton(panel, wxID_ANY, "Login");

	vbox->Add(userNameLabel, 0, wxEXPAND | wxALL, 10);
	vbox->Add(txtUserName, 0, wxEXPAND | wxALL, 10);
	vbox->Add(userSurnameLabel, 0, wxEXPAND | wxALL, 10);
	vbox->Add(txtUserSurname, 0, wxEXPAND | wxALL, 10);
	vbox->Add(passwordLabel, 0, wxEXPAND | wxALL, 10);
	vbox->Add(txtPassword, 0, wxEXPAND | wxALL, 10);
	vbox->Add(loginButton, 0, wxALIGN_CENTER | wxALL, 10);

	panel->SetSizer(vbox);

	loginButton->Bind(wxEVT_BUTTON, &RentalSystemMainFrame::OnLogin, this);
}

void RentalSystemMainFrame::OnLogin(wxCommandEvent& event)
{
	string userName = txtUserName->GetValue().ToStdString();
	string userSurname = txtUserSurname->GetValue().ToStdString();
	string password = txtPassword->GetValue().ToStdString();
	bool isAdmin;

	string loadedUserName, loadedUserSurname, loadedPassword;

	//if (DataManager::loadUserData(loadedUserName, loadedUserSurname, loadedPassword))
	{
		User currentUser(loadedUserName, loadedUserSurname, loadedPassword, "true");
		if (currentUser.authenticate(userName, userSurname, password, isAdmin))
		{
			wxMessageBox("Login succesful!", "Success", wxOK | wxICON_ERROR);
		}
		else
		{
			wxMessageBox("Invalid username or password!", "Error", wxOK | wxICON_ERROR);

		}
	}
	// else
	{
		wxMessageBox("Error loading user daa!", "ERORR", wxOK | wxICON_ERROR);
	}


}

void RentalSystemMainFrame::OnLogout(wxCommandEvent& event)
{
	this->Hide();

	LoginWindow* login = new LoginWindow();
	login->Center();
	login->Show();
}

