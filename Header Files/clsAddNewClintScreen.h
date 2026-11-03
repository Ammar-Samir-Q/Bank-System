#pragma once
#include<iostream>
#include"clsBankClint.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsAddNewClint:protected clsScreen{
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
static void ShowAddNewClintMenu()
{
    if(!CheckAccessRights(clsBankUsers::enPremissions::pAddClint))
    {
        return;
    }


   string Title="AddNewClint";
    clsScreen::_DrawScreenHeader(Title);
        string AccountNumber;
        cout<<"Please enter AccountNumber:\n";
        AccountNumber=clsInputValidate::ReadString();
        while(clsBankClint::IsClintExsist(AccountNumber))
        {
        cout<<"AccountNumber ["<<AccountNumber<<"] is Already Used Please Choose Another one:\n";
        AccountNumber=clsInputValidate::ReadString();
        }
        clsBankClint NewClint=clsBankClint::GetAddNewClint(AccountNumber);
        _ReadClintInfo(NewClint);
        clsBankClint::enSaveResults SaveResults;
        SaveResults=NewClint.Save();
        switch(SaveResults)
        {
        case clsBankClint::enSaveResults::SvSucceeded:
        cout<<"Clint Add Succssfuly..\n";
        _PrintClintCard(NewClint);
        break;
        case  clsBankClint::enSaveResults::SvFaliEmptyObject:
        cout<<"Clint not Added because its Empty...\n";
        break;
        case clsBankClint::enSaveResults::SvFalidBecauseAccExsist:
        cout<<"Clint not Added because its already Exist\n";
        break;
        }
        
        
    
    
    
    
    
    }





};












