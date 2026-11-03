#pragma once
#include<iostream>
#include"clsBankClint.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
class clsFindClint:protected clsScreen{
private:
static void _PrintClintCard(clsBankClint Clint)
{
cout<<"=======================================\n";
cout<<"               Clint Card:             \n";
cout<<"=======================================\n";
cout<<"FirstName     : "<<Clint.getFirstName()<<endl;
cout<<"LastName      : "<<Clint.getLastName()<<endl;
cout<<"FullName      : "<<Clint.FullName()<<endl;
cout<<"Email         : "<<Clint.getEmail()<<endl;
cout<<"Phone         : "<<Clint.getPhone()<<endl;
cout<<"AccountNumber : "<<Clint.AccountNumber()<<endl;
cout<<"PassWord      : "<<Clint.getPinCode()<<endl;
cout<<"Balance       : "<<Clint.getAccountBalance()<<endl;
cout<<"=======================================\n";
}
public:
static void ShowFindClintScreen()
{
    if(!CheckAccessRights(clsBankUsers::enPremissions::pFindClint))
    {
        return;
    }


clsScreen::_DrawScreenHeader("Find Clint Screen");
    string AccountNumber;
    cout<<"Please enter AccountNumber:\n";
    AccountNumber=clsInputValidate::ReadString();
    while(!clsBankClint::IsClintExsist(AccountNumber))
    {
    cout<<"Can't Find AccountNumber Please try Again:\n";
    AccountNumber=clsInputValidate::ReadString();
    }
    clsBankClint Clint1=clsBankClint::Find(AccountNumber);
    if(!Clint1.IsEmpty())
    {
        cout<<"Clint Found (:\n";
    }
    else
    {
        cout<<"Clint Not Found ):\n";
    }
    _PrintClintCard(Clint1);


}







};