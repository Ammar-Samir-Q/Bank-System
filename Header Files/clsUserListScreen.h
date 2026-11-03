#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsBankUsers.h"
class clsUserListScreen:protected clsScreen{

    private:
    static void _PrintUserData(clsBankUsers U)
{
    cout<<"|"<<left<<setw(20)<<U.getUserName();
    cout<<"|"<<left<<setw(20)<<U.FullName();
    cout<<"|"<<left<<setw(20)<<U.getPhone();
    cout<<"|"<<left<<setw(20)<<U.getEmail();
    cout<<"|"<<left<<setw(20)<<U.getPassword();
    cout<<"|"<<left<<setw(20)<<U.getPremissions();
}
public:    
    static void ShowUserList()
    {
        vector<clsBankUsers>vUsers=clsBankUsers::GetUsersList();
        string Title="UsersListMenu";
        string SubTitle="Users["+to_string(vUsers.size())+"]";
        clsScreen::_DrawScreenHeader(Title,SubTitle);
    cout<<"\n\t\t\tUser List Of["<<vUsers.size()<<"]  Users.\n";
    cout<<"===============================================================================================================================\n";
    cout<<"|"<<left<<setw(20)<<"UserName       ";
    cout<<"|"<<left<<setw(20)<<"FullName       ";
    cout<<"|"<<left<<setw(20)<<"Phone          ";
    cout<<"|"<<left<<setw(20)<<"Email          ";
    cout<<"|"<<left<<setw(20)<<"Password       ";
    cout<<"|"<<left<<setw(20)<<"UserPermissions";
    cout<<"\n===============================================================================================================================\n";
    if(vUsers.size()==0)
    {
    cout<<"There are not Users\n";
    }
    for(clsBankUsers &U:vUsers)
    {
    _PrintUserData(U);
    cout<<endl;
    }
    
    cout<<"\n===============================================================================================================================\n";
}
    







};