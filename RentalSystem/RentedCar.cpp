#include "RentedCar.h"

RentedCar::RentedCar(){}

RentedCar::RentedCar(const wxString& carMark, const wxString& carModel, const wxString& carYear) : carMark(carMark), carModel(carModel), carYear(carYear){}

wxString RentedCar::GetMark() const
{
	return carMark;
}

void RentedCar::SetMark(const wxString& newCarMark)
{
	carMark = newCarMark;
}

wxString RentedCar::GetModel() const
{
	return carModel;
}

void RentedCar::SetModel(const wxString& newCarModel)
{
	carModel = newCarModel;
}

wxString RentedCar::GetYear() const
{
	return carYear;
}

void RentedCar::SetYear(const wxString& newCarYear)
{
	carYear = newCarYear;
}

ostream& operator<<(ostream& wy, const RentedCar& car)
{
	wxString details = wxString::Format(
		"%s %s %s\n",
		car.GetMark(), car.GetModel(), car.GetYear()
	);

	return wy << details;
}
istream& operator>>(istream& we, RentedCar& car)
{
	char buf[1024];
	we >> buf;
	car.carMark = buf;
	we >> buf;
	car.carModel = buf;
	we >> buf;
	car.carYear = buf;
	return we;
}