#pragma once
#include<iostream>
#include"clsBankUsers.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
class clsFindUserScreen:protected clsScreen{
private:
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
cout<<"Premissions   : "<<User.getPremissions()<<endl;
cout<<"=======================================\n";
}
public:
static void ShowFindUserScreen()
{
clsScreen::_DrawScreenHeader("Find User Screen");
    string UserName;
    cout<<"Please enter UserName:\n";
    UserName=clsInputValidate::ReadString();
    while(!clsBankUsers::IsUserExsist(UserName))
    {
    cout<<"Can't Find UserName Please try Again:\n";
    UserName=clsInputValidate::ReadString();
    }
    clsBankUsers Clint1=clsBankUsers::Find(UserName);
    if(!Clint1.IsEmpty())
    {
        cout<<"User Found (:\n";
    }
    else
    {
        cout<<"User Not Found ):\n";
    }
    _PrintUserCard(Clint1);


}







};