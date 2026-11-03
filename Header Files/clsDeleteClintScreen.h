#pragma once
#include<iostream>
#include"clsBankClint.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
class clsDeleteClintScreen:protected clsScreen{
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

static void ShowDeleteClintScreen()
{
       if(!CheckAccessRights(clsBankUsers::enPremissions::pDeleteClint))
       {
           return;
       }

clsScreen::_DrawScreenHeader("Delete Clint Screen");
string AccountNumber;
cout<<"Please enter AccountNumber:\n";
AccountNumber=clsInputValidate::ReadString();
while(!clsBankClint::IsClintExsist(AccountNumber))
{
cout<<"Can't Find AccountNumber Please try Again:\n";
AccountNumber=clsInputValidate::ReadString();
}
clsBankClint Clint1=clsBankClint::Find(AccountNumber);
_PrintClintCard(Clint1);
cout<<"Are you sure To Delete This Account:[y/n]?\n";
char Answer='n';
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
 if (Clint1.Delete())
 {
    cout<<"Clint Deleted Succssfuly..\n";
   _PrintClintCard(Clint1);
 }
 else
 {
        cout<<"Error Clint Not Deleted";
 }
 
}





}





};