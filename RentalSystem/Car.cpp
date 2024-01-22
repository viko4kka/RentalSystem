#include "Car.h"
#include <wx/wx.h>

Car::Car(const wxString& mark, const wxString& model, const wxString& color, const wxString& year, const wxString& isAutomatic, const wxString& owner, const wxString& price)
	: mark(mark), model(model), color(color), year(year), isAutomatic(isAutomatic), owner(owner), price(price) {}

wxString Car::GetMark() const
{
	return mark;
}

void Car::SetMark(const wxString& newMark)
{
	mark = newMark;
}

wxString Car::GetModel() const
{
	return model;
}

void Car::SetModel(const wxString& newModel)
{
	model = newModel;
}

wxString Car::GetYear() const
{
	return year;
}

void Car::SetYear(const wxString& newYear)
{
	year = newYear;
}


wxString Car::GetColor() const
{
	return color;
}

void Car::SetColor(const wxString& newColor)
{
	color = newColor;
}

wxString Car::GetIsAutomatic() const
{
	return isAutomatic;
}

void Car::SetIsAutomatic(const wxString& newIsAutomatic)
{
	isAutomatic = newIsAutomatic;
}

wxString Car::GetOwner() const
{
	return owner;
}

void Car::SetOwner(const wxString& newOwner)
{
	owner = newOwner;
}

wxString Car::GetPrice() const
{
	return price;
}

void Car::SetPrice(const wxString& newPrice)
{
	price = newPrice;
}

ostream& operator<<(ostream& wy, const Car& car)
{
	wxString details = wxString::Format(
		"%s %s %s %s %s %s %s\n",
		car.GetMark(), car.GetModel(), car.GetColor(), car.GetYear(),
		car.GetIsAutomatic(), car.GetOwner(), car.GetPrice()
	);

	return wy << details;
}
istream& operator>>(istream& we, Car& car)
{
	char buf[1024];
	we >> buf;
	car.mark = buf;
	we >> buf;
	car.model = buf;
	we >> buf;
	car.year = buf;
	we >> buf;
	car.color = buf;
	we >> buf;
	car.isAutomatic = buf;
	we >> buf;
	car.owner = buf;
	we >> buf;
	car.price = buf;
	return we;
}



//mark(mark), model(model), color(color), year(year), isAutomatic(isAutomatic), owner(owner), price(price) {}
