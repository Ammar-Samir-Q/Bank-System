#pragma once
#include<iostream>
#include"clsBankUsers.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsAddNewUser :protected clsScreen {
private:
	static void _ReadUserInfo(clsBankUsers& User)
	{
		cout << "Please enter FirstName:\n";
		User.setFirstName(clsInputValidate::ReadString());
		cout << "Please enter LastName:\n";
		User.setLastName(clsInputValidate::ReadString());
		cout << "Please enter Email:\n";
		User.setEmail(clsInputValidate::ReadString());
		cout << "Please enter Phone\n";
		User.setPhone(clsInputValidate::ReadString());
		cout << "Please enter Password:\n";
		User.setPasswords(clsInputValidate::ReadString());
		cout << "Please enter Pemissions:\n";
		User.setPremissions(ReadPermissionsToSet());
	}
	static void _PrintUserCard(clsBankUsers User)
	{
		cout << "=======================================\n";
		cout << "               User Card:             \n";
		cout << "=======================================\n";
		cout << "FirstName     : " << User.getFirstName() << endl;
		cout << "LastName      : " << User.getLastName() << endl;
		cout << "FullName      : " << User.FullName() << endl;
		cout << "Email         : " << User.getEmail() << endl;
		cout << "Phone         : " << User.getPhone() << endl;
		cout << "UserName      : " << User.getUserName() << endl;
		cout << "PassWord      : " << User.getPassword() << endl;
		cout << "Balance       : " << User.getPremissions() << endl;
		cout << "=======================================\n";
	}
	static int ReadPermissionsToSet()
	{
		int Premissions = 0;
		char Answer = 'n';
		cout << "Give All Premissions?[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "Can ShowClintsList[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premissions += clsBankUsers::enPremissions::pShowClint;
		}
		cout << "Can AddClint ?[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premissions += clsBankUsers::enPremissions::pAddClint;
		}
		cout << "Can DeleteClint[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premissions += clsBankUsers::enPremissions::pDeleteClint;
		}
		cout << "Can UpdateClint[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premissions += clsBankUsers::enPremissions::pUpdateClint;
		}
		cout << "Can FindClint[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premissions += clsBankUsers::enPremissions::pFindClint;
		}
		cout << "Can Transactions[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premissions += clsBankUsers::enPremissions::pTransactions;
		}
		cout << "Can ManageUsers[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premissions += clsBankUsers::enPremissions::pShowClint;
		}

		cout << "Can ShowLogRegister[y/n]\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premissions += clsBankUsers::enPremissions::pLogRegister;
		}

		return Premissions;
	}


public:
	static void ShowAddNewUserMenu()
	{
		string Title = "AddNewUser";
		clsScreen::_DrawScreenHeader(Title);
		string UserName;
		cout << "Please enter UserName:\n";
		UserName = clsInputValidate::ReadString();
		while (clsBankUsers::IsUserExsist(UserName))
		{
			cout << "UserName [" << UserName << "] is Already Used Please Choose Another one:\n";
			UserName = clsInputValidate::ReadString();
		}
		clsBankUsers NewUser = clsBankUsers::GetAddNewUser(UserName);
		_ReadUserInfo(NewUser);
		clsBankUsers::enSaveResults SaveResults;
		SaveResults = NewUser.Save();
		switch (SaveResults)
		{
		case clsBankUsers::enSaveResults::SvSucceeded:
			cout << "User Add Succssfuly..\n";
			_PrintUserCard(NewUser);
			break;
		case  clsBankUsers::enSaveResults::SvFaliEmptyObject:
			cout << "User not Added because its Empty...\n";
			break;
		case clsBankUsers::enSaveResults::SvFalidBecauseAccExsist:
			cout << "User not Added because its already Exist\n";
			break;
		}







	}





};












