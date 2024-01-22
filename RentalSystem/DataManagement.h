
#pragma once

#ifndef DATAMANAGEMENT_H
#define DATAMANAGEMENT_H

using namespace std;
#include <string>
#include <fstream>
#include "User.h"
#include "Admin.h"
#include "Vector.h"
#include "Car.h"
#include "RentedCar.h"

class DataManager {
public:
	 static bool saveUserData(const User& user);
	 static Vector<User> loadUserData();
	static Vector<Car> loadCarsData();

	 static bool saveRentedCarData(const RentedCar& car);
     static Vector<RentedCar> loadRentedCarData();	
};

#endif // DATAMANAGEMENT_H

