#pragma once
#include<iostream>
#include"clsBankClint.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
class clsUpdateClint:protected clsScreen{
private:
static void _ReadClintInfo(clsBankClint&Clint)
{
cout<<"Please enter FirstName:\n";
Clint.setFirstName(clsInputValidate::ReadString());
cout<<"Please enter LastName:\n";
Clint.setLastName(clsInputValidate::ReadString());
cout<<"Please enter Email:\n";
Clint.setEmail(clsInputValidate::ReadString());
cout<<"Please enter Phone\n";
Clint.setPhone(clsInputValidate::ReadString());
cout<<"Please enter PinCode:\n";
Clint.setPinCode(clsInputValidate::ReadString());
cout<<"Please enter Balance:\n";
Clint.setAccountBalance(clsInputValidate::ReadFloatNumber());
}
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
static void ShowUpdateClintScreen()
{
    if(!CheckAccessRights(clsBankUsers::enPremissions::pUpdateClint))
    {
        return;
    }

    clsScreen::_DrawScreenHeader("Update Clint Screen");

    string AccountNumber;
    cout<<"Please enter AccountNumber:\n";
    AccountNumber=clsInputValidate::ReadString();
    while(!clsBankClint::IsClintExsist(AccountNumber))
    {
    cout<<"Can't Find AccountNumber Please try Again:\n";
    AccountNumber=clsInputValidate::ReadString();
    }
    clsBankClint Clint=clsBankClint::Find(AccountNumber);
    _PrintClintCard(Clint);
    cout<<"\n====================================\n";
    cout<<"               UpdateClint              ";
    cout<<"\n====================================\n";
    _ReadClintInfo(Clint);
    clsBankClint::enSaveResults SaveResults;
    SaveResults=Clint.Save();
    switch(SaveResults)
    {
    case clsBankClint::enSaveResults::SvSucceeded:
    cout<<"Update Done Succssfuly..\n";
    _PrintClintCard(Clint);
    break;
    case  clsBankClint::enSaveResults::SvFaliEmptyObject:
    cout<<"Account not Saved because its Empty...\n";
    break;
    }




}







};