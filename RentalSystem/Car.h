#pragma once
#include <wx/string.h>
using namespace std;
class Car
{
public:


	Car() = default;

	Car(const wxString& mark, const wxString& model, const wxString& color, const wxString& year, const wxString& isAutomatic, const wxString& owner, const wxString& price);

	wxString GetMark()const;
	void SetMark(const wxString& mark);

	wxString GetModel() const;
	void SetModel(const wxString& model);

	wxString GetYear() const;
	void SetYear(const wxString& year);

	wxString GetColor() const;
	void SetColor(const wxString& color);

	wxString GetIsAutomatic() const;
	void SetIsAutomatic(const wxString& isAutomatic);

	wxString GetOwner() const;
	void SetOwner(const wxString& owner);

	wxString GetPrice() const;
	void SetPrice(const wxString& price);

	friend ostream& operator<<(ostream& wy, const Car& vec);
	friend  istream& operator>>(istream& we, Car& vec);

private:
	wxString mark;
	wxString model;
	wxString year;
	wxString color;
	wxString isAutomatic;
	wxString owner;
	wxString price;
	
};

