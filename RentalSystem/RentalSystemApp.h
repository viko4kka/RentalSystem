#pragma once
#ifndef RENTALSYSTEMAPP_H
#define RENTALSYSTEMAPP_H

#include <wx/wx.h>
#include "RentalSystemMainFrame.h"
#include "LoginWindow.h"
#include "UserLoginWindow.h"


class RentalSystemApp : public wxApp
{
public:
	virtual bool OnInit() override;
	void OnLoginSuccess();

	void OnUserLogin();


private:
	UserLoginWindow* userLoginWindow;
	LoginWindow* loginWindow;
	RentalSystemMainFrame* mainFrame;


};

#endif // RENTALSYSTEMAPP_H