#include<iostream>
#include"Global.h"
#include"clsScreen.h"
#include"clsBankUsers.h"
#include"clsMainMenuScreen.h"
using namespace std;
class clsLoginScreen :protected clsScreen {
private:

	static bool _Login()
	{
		short FaildTryCounter = 0;
		bool IsLoginFalid = false;
		string UserName, PassWord;
		do {
			if (IsLoginFalid)
			{
				FaildTryCounter++;
				cout << "Invalid UserName/PassWord\n";
				cout << "Please TryAgain..\n";
				cout << "You Have [" << (4 - FaildTryCounter) << "]" << "Tries Left..\n\n";
			}
			if (FaildTryCounter == 4)
			{
				return false;
			}
			cout << "Enter UserName:\n";
			cin >> UserName;
			cout << "Enter PassWord:\n";
			cin >> PassWord;
			CurrentUser = clsBankUsers::Find(UserName, PassWord);
			IsLoginFalid = CurrentUser.IsEmpty();
		} while (IsLoginFalid);
		CurrentUser.SaveLog();
		clsMainMenu::ShowMainMenu();
		return true;
	}
public:
	static bool ShowLoginScreen()
	{
		clsScreen::_DrawScreenHeader("Login Screen");
		return _Login();



	}



};