#pragma once
#include <wx/wx.h>

#include "Car.h"


class RentedCar
{
public:
	RentedCar();
	RentedCar(const wxString& carMark, const wxString& carModel, const wxString& carYear);

	wxString GetMark()const;
	void SetMark(const wxString& carMark);

	wxString GetModel() const;
	void SetModel(const wxString& carModel);

	wxString GetYear() const;
	void SetYear(const wxString& carYear);

	friend ostream& operator<<(ostream& wy, const RentedCar& car);
	friend  istream& operator>>(istream& we, RentedCar& car);
	
	private:
		wxString carMark;
		wxString carModel;
		wxString  carYear;
};

