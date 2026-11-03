#pragma once
#include<iostream>
#include"clsBankUsers.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
class clsDeleteUserScreen:protected clsScreen{
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

static void ShowDeleteUserScreen()
{
clsScreen::_DrawScreenHeader("Delete Clint Screen");
string UserName;
cout<<"Please enter UserName:\n";
UserName=clsInputValidate::ReadString();
while(!clsBankUsers::IsUserExsist(UserName))
{
cout<<"Can't Find UserName Please try Again:\n";
UserName=clsInputValidate::ReadString();
}
clsBankUsers User1=clsBankUsers::Find(UserName);
_PrintUserCard(User1);
cout<<"Are you sure To Delete This Account:[y/n]?\n";
char Answer='n';
cin>>Answer;
if(Answer=='y'||Answer=='Y')
{
 if (User1.Delete())
 {
    cout<<"User Deleted Succssfuly..\n";
   _PrintUserCard(User1);
 }
 else
 {
        cout<<"Error User Not Deleted";
 }
 
}





}





};