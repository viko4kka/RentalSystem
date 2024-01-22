#include "User.h"
#include <wx/wx.h>
#include <list>
#include "DataManagement.h"
#include "LoginWindow.h"
#include "Vector.h"
using namespace std;

User::User()
{
    
}

User::User(const string& userName, const string& userSurname, const string& password, const string& isAdmin)
    : userName(userName), userSurname(userSurname), password(password), isAdmin(isAdmin) {}

bool User::authenticate(const string& userName, const string& userSurname, const string& password, bool& isAdmin) {
    DataManager manager;
    Vector<User> users = manager.loadUserData();

    for (int i = 0; i<users.get_size();++i)
    {
        if (users[i].userName._Equal(userName) && users[i].userSurname._Equal(userSurname) && users[i].password._Equal(password))
        {
            if (users[i].isAdmin == "true")
                isAdmin = true;
            else
                isAdmin = false;

            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& wy, const User& user)
{
    //string userName;
    //string userSurname;
    //string password;
    //string isAdmin;
    wxString details = wxString::Format(
        "%s %s %s %s\n",
        user.userName, user.userSurname, user.password, user.isAdmin
    );

    return wy << details;
}
istream& operator>>(istream& we, User& user)
{
    we >> user.userName >> user.userSurname >> user.password >> user.isAdmin;
    return we;
}