#pragma once
#include <wx/wx.h>
#ifndef USER_H
#define USER_H
#include <string>
using namespace std;


class User {
private:
    string userName;
    string userSurname;
    string password;
    string isAdmin;



public:
    User();
    User(const string& userName, const string& userSurname, const string& password, const string& isAdmin);
    bool authenticate(const string& userName, const string& userSurname, const string& password, bool& isAdmin);

    friend ostream& operator<<(ostream& wy, const User& user);
    friend istream& operator>>(istream& we, User& user);
};

#endif // USER_H