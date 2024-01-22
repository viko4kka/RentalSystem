#include "RentalSystemApp.h"
#include "RentalSystemMainFrame.h"
#include "UserLoginWindow.h"
#include "LoginWindow.h"  //okno logowania
#include "User.h"
#include "DataManagement.h"

#include <wx/wx.h>

#include "AdminMainFrame.h"

using namespace std;

bool RentalSystemApp::OnInit()
{
	// Tworzymy i pokazujemy okno logowania
	userLoginWindow = new UserLoginWindow();
	userLoginWindow->Center();
	userLoginWindow->Show(true);

	// Tworzymy i pokazujemy okno logowania jako glówne okno aplikacji
	loginWindow = new LoginWindow();

	return true;


}

void RentalSystemApp::OnLoginSuccess()
{


	if (loginWindow)
	{
		loginWindow->Hide();
		if (!mainFrame)
		{
			mainFrame = new RentalSystemMainFrame("Car Rental System", wxDefaultPosition, wxSize(800, 600));
			mainFrame->Center();
		}
		mainFrame->Show(true);

	}
}

void RentalSystemApp::OnUserLogin()
{
	loginWindow = new LoginWindow();
	loginWindow->Center();
	loginWindow->Show(true);
}





wxIMPLEMENT_APP(RentalSystemApp);