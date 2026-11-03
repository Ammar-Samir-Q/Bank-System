#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUserListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
class clsManageUsers:protected clsScreen{
private:
enum enManageUsersOptions{eUsersList=1,eAddNewUser=2,eDeleteUser=3,eUpdateUser=4,eFindUser=5,eMainMenu=6};
static short _ReadManageUsersOption()
{
    cout<<"\t\t\t\t\tPlease Enter Your Choice [1/6]:\n";
    short Choice=clsInputValidate::ReadIntNumberBetween(1,6,"Please enter Number Between 1/6:");
    return Choice;
}
static void _PerformManageUsersMenuOptions(enManageUsersOptions Choice)
{
switch (Choice)
{
case enManageUsersOptions::eUsersList:
   system("cls"); 
    _ShowUsersListScreen();
    _GoBackToManageUsersMenu();
    break;
case enManageUsersOptions::eAddNewUser:
 system("cls"); 
 _ShowAddNewUserScreen();
 _GoBackToManageUsersMenu();
    break;
case enManageUsersOptions::eDeleteUser:
 system("cls"); 
 _ShowDeleteUserScreen();
 _GoBackToManageUsersMenu();
    break;
case enManageUsersOptions::eUpdateUser:
system("cls"); 
_ShowUpdateUserScreen();
 _GoBackToManageUsersMenu();
    break;
case enManageUsersOptions::eFindUser:
system("cls"); 
_ShowFindScreen();
 _GoBackToManageUsersMenu();
    break;
case enManageUsersOptions::eMainMenu:
    break;
default:
    break;
}
}
static void _GoBackToManageUsersMenu()
{
cout<<"Press Any Key To Go Back To Manage Users Menu...\n";
system("pause>0");
system("cls");
ShowManageUsersScreen();
}
static void _ShowUsersListScreen()
{
   // cout<<"UsersList Screen Will Be Here...\n";
   clsUserListScreen::ShowUserList();
}
static void _ShowAddNewUserScreen()
{
    //cout<<"Add New User Screen Will Be Here...\n";
    clsAddNewUser::ShowAddNewUserMenu();
}
static void _ShowDeleteUserScreen()
{
   // cout<<"Delete User Screen Will Be Here...\n";
   clsDeleteUserScreen::ShowDeleteUserScreen();
}
static void _ShowUpdateUserScreen()
{
   // cout<<"Update User Screen Will Be Here...\n";
   clsUpdateUser::ShowUpdateUserScreen();
}
static void _ShowFindScreen()
{
    //cout<<"Find User Screen Will Be Here...\n";
    clsFindUserScreen::ShowFindUserScreen();
}



public:
static void ShowManageUsersScreen()
{
    if(!CheckAccessRights(clsBankUsers::enPremissions::pManageUsers))
    {
        return;
    }


clsScreen::_DrawScreenHeader("Manage Users Screen");
cout<<"\t\t\t\t\t======================================\n";
cout<<"\t\t\t\t\t         Manage Users Manage          \n";
cout<<"\t\t\t\t\t======================================\n";
cout<<"\t\t\t\t\t[1]-Show Users List."<<endl;
cout<<"\t\t\t\t\t[2]-Add New User.   "<<endl;
cout<<"\t\t\t\t\t[3]-Delete User.    "<<endl;
cout<<"\t\t\t\t\t[4]-Update User.    "<<endl;
cout<<"\t\t\t\t\t[5]-Find   User.    "<<endl;
cout<<"\t\t\t\t\t[6]-Main Menu.      "<<endl;
cout<<"\t\t\t\t\t======================================\n";
_PerformManageUsersMenuOptions((enManageUsersOptions)_ReadManageUsersOption());


}














};