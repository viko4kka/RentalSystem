#include "DataManagement.h"
#include <fstream>
#include "Vector.h"
using namespace std;


bool DataManager::saveUserData(const User& user) {
    ofstream file("Users.txt", ios::app);
    if (!file.is_open()) {
        return false;
    }

    file << user;
    file.close();
    return true;
}

Vector<User> DataManager::loadUserData() {

    Vector<User> users;
    std::ifstream file("Users.txt");
    if (!file.is_open()) {
        exit(1);
    }
    file >> users;
    /*else
    {
        string userName, userSurname, password, isAdmin;

        while (file >> userName >> userSurname >> password >> isAdmin)
        {
            users.push_back(User(userName, userSurname, password, isAdmin));
        }
    }*/
    file.close();
    return users;
}

Vector<Car> DataManager::loadCarsData() {

    Vector<Car> cars;
    std::ifstream file("Cars.txt");
    if (!file.is_open()) {
        exit(1);
    }
    else
    {
        string mark, model, color, year, isAutomatic, owner, price;

        while (file >> mark >> model >> color >> year >> isAutomatic >> owner >> price)
        {
            cars.push_back(Car(mark, model, color, year, isAutomatic, owner, price));
        }
    }
    file.close();
    return cars;
}



bool DataManager::saveRentedCarData(const RentedCar& car)
{
    ofstream file("RentedCars.txt", ios::app);
    if (!file.is_open()) {
        return false;
    }

    file << car;
    file.close();
    return true;
}


Vector<RentedCar> DataManager::loadRentedCarData()
{
    Vector<RentedCar> rentedCars;
    std::ifstream file("RentedCars.txt");
    if (!file.is_open()) {
        exit(1);
    }
    else
    {
        string RentedCarMark, RentedCarModel, RentedCarYear;

        while (file >> RentedCarMark >> RentedCarModel >> RentedCarYear )
        {
            rentedCars.push_back(RentedCar(RentedCarMark, RentedCarModel, RentedCarYear));
        }
    }
    file.close();
    return rentedCars;
}



