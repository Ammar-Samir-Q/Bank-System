#include<iostream>
#include"clsScreen.h"
#include"clsBankClint.h"
#include"clsInputValidate.h"
class clsDepositScreen :protected clsScreen {
private:
	static void _PrintClintCard(clsBankClint Clint)
	{
		cout << "=======================================\n";
		cout << "               Clint Card:             \n";
		cout << "=======================================\n";
		cout << "FirstName     : " << Clint.getFirstName() << endl;
		cout << "LastName      : " << Clint.getLastName() << endl;
		cout << "FullName      : " << Clint.FullName() << endl;
		cout << "Email         : " << Clint.getEmail() << endl;
		cout << "Phone         : " << Clint.getPhone() << endl;
		cout << "AccountNumber : " << Clint.AccountNumber() << endl;
		cout << "PassWord      : " << Clint.getPinCode() << endl;
		cout << "Balance       : " << Clint.getAccountBalance() << endl;
		cout << "=======================================\n";
	}





public:

	static void ShowDepositScreen()
	{
		clsScreen::_DrawScreenHeader("Deposit Screen");

		string AccountNumber;
		cout << "Please enter AccountNumber:\n";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClint::IsClintExsist(AccountNumber))
		{
			cout << "Can't Find AccountNumber Please try Again:\n";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClint Clint1 = clsBankClint::Find(AccountNumber);
		_PrintClintCard(Clint1);
		cout << "Enter How Many To Deposit: \n";
		double Amount = clsInputValidate::ReadDblNumber();
		cout << "Are you sure To Deposit To This Account:[y/n]?\n";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Clint1.Deposit(Amount);
			cout << "Deposit Done Succsfuly..\n";
			cout << "Account Now Have [" << Clint1.getAccountBalance() << "] In Balance\n";
		}
		else
		{
			cout << "Deposit Cancelled....\n";
		}


	}













};