#pragma once
#ifndef ADMINMAINFRAME_H
#define ADMINMAINFRAME_H
#include <wx/wx.h>
#include <vector>
#include "Car.h"
#include "LoginWindow.h"
#include "Vector.h"

class AdminMainFrame : public wxFrame
{
public:
	AdminMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);


private:
	wxPanel* detailsPanel;
	wxStaticText* detailsText;
	wxButton* addButton;
	wxButton* removeButton;
	wxListBox* carList; // Deklaracja listy samochodów
	bool detailsPanelVisible;

	void InitializeLayout();
	

	void OnAddCar(wxCommandEvent& event);
	void OnRemoveCar(wxCommandEvent& event);
	void OnLogout(wxCommandEvent& event);
	void OnCarSelected(wxCommandEvent& evet);

	Vector<Car> addedCars; // Dodajemy wektor do przechowywania dodanych samochodów

	wxDECLARE_EVENT_TABLE();
};

#endif // ADMINMAINFRAME_H