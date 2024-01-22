#pragma once

#ifndef RENTALSYSTEMMAINFRAME_H
#define RENTALSYSTEMMAINFRAME_H

#include <wx/wx.h>
#include "Vector.h"
#include "Car.h"

class RentalSystemMainFrame : public wxFrame
{
public:
	RentalSystemMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnCarSelected(wxCommandEvent& event);
	void OnBackButton(wxCommandEvent& event);
	void OnChooseButton(wxCommandEvent& event);


	RentalSystemMainFrame();
	void OnLogin(wxCommandEvent& event);



private:
	wxListBox* carList;
	wxPanel* detailsPanel;
	wxStaticText* detailsText;
	wxButton* backButton;
	wxButton* chooseButton;
	wxButton* logoutButton;

	bool detailsPanelVisible = true;


	wxTextCtrl* txtUserName;
	wxTextCtrl* txtUserSurname;
	wxTextCtrl* txtPassword;

	void OnLogout(wxCommandEvent& event);
	


	Vector<Car> cars;

	wxDECLARE_EVENT_TABLE();

};




#endif