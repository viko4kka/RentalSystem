#include "AdminMainFrame.h"
#include <fstream>
#include "Car.h"
using namespace std;


wxBEGIN_EVENT_TABLE(AdminMainFrame, wxFrame)
EVT_BUTTON(wxID_ANY, AdminMainFrame::OnAddCar)
EVT_BUTTON(wxID_ANY, AdminMainFrame::OnRemoveCar)
EVT_BUTTON(wxID_ANY, AdminMainFrame::OnLogout)
wxEND_EVENT_TABLE()

AdminMainFrame::AdminMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
	InitializeLayout();
	//InitializeUI();
}

void AdminMainFrame::InitializeLayout()
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	panel->SetBackgroundColour(wxColor(53, 45, 77));

	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

	detailsPanel = new wxPanel(panel, wxID_ANY);
	detailsPanel->SetBackgroundColour(wxColor(146, 224, 169));

	wxBoxSizer* detailsSizer = new wxBoxSizer(wxVERTICAL);
	detailsText = new wxStaticText(detailsPanel, wxID_ANY, wxEmptyString);
	detailsSizer->Add(detailsText, 1, wxEXPAND | wxALL, 10);
	detailsPanel->SetSizer(detailsSizer);

	wxPanel* buttonsPanel = new wxPanel(panel, wxID_ANY);
	buttonsPanel->SetBackgroundColour(wxColor(109, 97, 146));

	wxBoxSizer* buttonsSizer = new wxBoxSizer(wxVERTICAL);
	addButton = new wxButton(buttonsPanel, wxID_ANY, "Add Car");
	removeButton = new wxButton(buttonsPanel, wxID_ANY, "Remove Car");
	wxButton* logoutButton = new wxButton(buttonsPanel, wxID_ANY, "Log out");
	buttonsSizer->AddStretchSpacer();
	buttonsSizer->Add(addButton, 0, wxALIGN_CENTER | wxALL, 10); // Wyœrodkowanie przycisków
	buttonsSizer->Add(removeButton, 0, wxALIGN_CENTER | wxALL, 10); // Wyœrodkowanie przycisków
	buttonsSizer->Add(logoutButton, 0, wxALIGN_CENTER | wxALL, 10);
	buttonsSizer->AddStretchSpacer();
	buttonsPanel->SetSizer(buttonsSizer);


	carList = new wxListBox(detailsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
	detailsSizer->Add(carList, 1, wxEXPAND | wxALL, 10); // Add carList to details panel sizer
	removeButton->Bind(wxEVT_BUTTON, &AdminMainFrame::OnRemoveCar, this);
	logoutButton->Bind(wxEVT_BUTTON, &AdminMainFrame::OnLogout, this);

	mainSizer->Add(detailsPanel, 1, wxEXPAND | wxALL, 10);
	mainSizer->Add(buttonsPanel, 0, wxEXPAND | wxALL, 10);

	panel->SetSizer(mainSizer);
}



void AdminMainFrame::OnAddCar(wxCommandEvent& event)
{
	// Functionality for adding a car goes here
	wxString mark = wxGetTextFromUser("Enter car mark:", "Add Car");
	wxString model = wxGetTextFromUser("Enter car model:", "Add Car");
	wxString color = wxGetTextFromUser("Enter car color:", "Add Car");
	wxString year = wxGetTextFromUser("Enter car year:", "Add Car");
	wxString automatic = wxGetTextFromUser("Enter if automatic (yes/no):", "Add Car");
	wxString owner = wxGetTextFromUser("Enter owner's name:", "Add Car");
	wxString price = wxGetTextFromUser("Enter car price:", "Add Car");


	wxString carDetails = mark + " " + model + " " + color + " " + year + " " + automatic + " " + owner + " " + price + "\n";

	// Open the file in append mode and write the car details
	std::ofstream outFile("Cars.txt", std::ios_base::app);
	if (outFile.is_open()) {
		outFile << carDetails;
		outFile.close();
		wxMessageBox("Car added successfully!", "Success");
	}
	else {
		wxMessageBox("Unable to open file for writing!", "Error");
	}

	Car car(mark.ToStdString(), model.ToStdString(), color.ToStdString(), year.ToStdString(), automatic.ToStdString(), owner.ToStdString(), price.ToStdString());
	addedCars.push_back(car);



	wxString details = wxString::Format(
		"Brand: %s \n Model: %s \n Color: %s \n Year: %s \n Automatic: %s \n Owner: %s \n Price: %S",
		car.GetMark(), car.GetModel(), car.GetColor(), car.GetYear(),
		car.GetIsAutomatic(), car.GetOwner(), car.GetPrice()
	);

	if (carList) {
		carList->Append(details);
	}
}

void AdminMainFrame::OnRemoveCar(wxCommandEvent& event)
{
	int selection = carList->GetSelection();
	if (selection != wxNOT_FOUND && selection < static_cast<int>(addedCars.get_size())) {
		// Remove car from the displayed list
		//addedCars.erase(addedCars.begin() + selection);
		carList->Delete(selection);

		// Rewrite data to "Cars.txt" without the removed car
		std::ofstream outFile("Cars.txt");
		if (outFile.is_open()) {
			//for (const auto& car : addedCars) {
			for(int i = 0;i<addedCars.get_size();++i){
				outFile << addedCars[i].GetMark() << " " << addedCars[i].GetModel() << " " << addedCars[i].GetColor() << " "
					<< addedCars[i].GetYear() << " " << addedCars[i].GetIsAutomatic() << " " << addedCars[i].GetOwner() << " "
					<< addedCars[i].GetPrice() << "\n";
			}
			outFile.close();
			wxMessageBox("Car removed successfully!", "Success");
		}
		else {
			wxMessageBox("Unable to open file for writing!", "Error");
		}
	}
	else {
		wxMessageBox("Please select a car to remove!", "Error");
	}
}

void AdminMainFrame::OnLogout(wxCommandEvent& event)
{
	LoginWindow* loginWindow = new LoginWindow();
	loginWindow->Show();
	loginWindow->Center();
	this->Hide();
}

void AdminMainFrame::OnCarSelected(wxCommandEvent& event) {
	int selection = carList->GetSelection();
	if (selection != wxNOT_FOUND && selection < static_cast<int>(addedCars.get_size())) {
		detailsPanelVisible = true;

		wxString details = wxString::Format(
			"Brand: %s\nModel: %s\nColor: %s\nAutomatic: %s\nOwner: %s\nPrice: %.2f",
			addedCars[selection].GetMark(), addedCars[selection].GetModel(), addedCars[selection].GetColor(),
			addedCars[selection].GetIsAutomatic(), addedCars[selection].GetOwner(), addedCars[selection].GetPrice()
		);

		detailsText->SetLabel(details);

		detailsPanel->Show();
		detailsPanel->SetBackgroundColour(wxColor(146, 224, 169));
		Layout();
	}
}