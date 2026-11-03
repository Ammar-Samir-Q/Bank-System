#pragma once
#include<iostream>
#include"clsBankUsers.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
class clsUpdateUser:protected clsScreen{
private:
static void _ReadUserInfo(clsBankUsers&User)
{
cout<<"Please enter FirstName:\n";
User.setFirstName(clsInputValidate::ReadString());
cout<<"Please enter LastName:\n";
User.setLastName(clsInputValidate::ReadString());
cout<<"Please enter Email:\n";
User.setEmail(clsInputValidate::ReadString());
cout<<"Please enter Phone\n";
User.setPhone(clsInputValidate::ReadString());
cout<<"Please enter Password:\n";
User.setPasswords(clsInputValidate::ReadString());
cout<<"Please enter Pemissions:\n";
User.setPremissions(ReadPermissionsToSet());
}
static void _PrintUserCard(clsBankUsers User)
{
cout<<"=======================================\n";
cout<<"               User Card:             \n";
cout<<"=======================================\n";
cout<<"FirstName     : "<<User.getFirstName()<<endl;
cout<<"LastName      : "<<User.getLastName()<<endl;
cout<<"FullName      : "<<User.FullName()<<endl;
cout<<"Email         : "<<User.getEmail()<<endl;
cout<<"Phone         : "<<User.getPhone()<<endl;
cout<<"UserName      : "<<User.getUserName()<<endl;
cout<<"PassWord      : "<<User.getPassword()<<endl;
cout<<"Balance       : "<<User.getPremissions()<<endl;
cout<<"=======================================\n";
}
static int ReadPermissionsToSet()
{
    int Premissions=0;
    char Answer='n';
cout<<"Give All Premissions?[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    return -1;
}
cout<<"Can ShowClintsList[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    Premissions+=clsBankUsers::enPremissions::pShowClint;
}
cout<<"Can AddClint ?[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    Premissions+=clsBankUsers::enPremissions::pAddClint;
}
cout<<"Can DeleteClint[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    Premissions+=clsBankUsers::enPremissions::pDeleteClint;
}
cout<<"Can UpdateClint[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    Premissions+=clsBankUsers::enPremissions::pUpdateClint;
}
cout<<"Can FindClint[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    Premissions+=clsBankUsers::enPremissions::pFindClint;
}
cout<<"Can Transactions[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    Premissions+=clsBankUsers::enPremissions::pTransactions;
}
cout<<"Can ManageUsers[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    Premissions+=clsBankUsers::enPremissions::pShowClint;
}
cout<<"Can ShowLogRegister[y/n]\n";
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
    Premissions+=clsBankUsers::enPremissions::pLogRegister;
}



return Premissions;
}

public:
static void ShowUpdateUserScreen()
{
    clsScreen::_DrawScreenHeader("Update User Screen");

    string UserName;
    cout<<"Please enter UserName:\n";
    UserName=clsInputValidate::ReadString();
    while(!clsBankUsers::IsUserExsist(UserName))
    {
    cout<<"Can't Find UserName Please try Again:\n";
    UserName=clsInputValidate::ReadString();
    }
    clsBankUsers User=clsBankUsers::Find(UserName);
    _PrintUserCard(User);
    cout<<"\n====================================\n";
    cout<<"               UpdateClint              ";
    cout<<"\n====================================\n";
    _ReadUserInfo(User);
    clsBankUsers::enSaveResults SaveResults;
    SaveResults=User.Save();
    switch(SaveResults)
    {
    case clsBankUsers::enSaveResults::SvSucceeded:
    cout<<"Update Done Succssfuly..\n";
    _PrintUserCard(User);
    break;
    case  clsBankUsers::enSaveResults::SvFaliEmptyObject:
    cout<<"Account not Saved because its Empty...\n";
    break;
    }




}







};