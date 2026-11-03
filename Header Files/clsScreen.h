#pragma once
#include<iostream>
#include"Global.h"
#include"clsDate.h"
#include"clsBankUsers.h"
using namespace std;
class clsScreen{

protected:
static void _DrawScreenHeader(string Title,string SubTitle="")
{
cout<<"\t\t\t\t\t======================================================\n";
cout<<"\t\t\t\t\t                        "<<Title<<"                   \n";
cout<<"\t\t\t\t\t                        "<<SubTitle<<"                \n";
cout<<"\t\t\t\t\t======================================================\n";
cout<<"\t\t\t\t\t       Date: "<<clsDate::DateToString(clsDate::GetSystemDate());
cout<<"      User: "<<CurrentUser.getUserName()<<endl;

}
static bool CheckAccessRights(clsBankUsers::enPremissions Premissions)
{
if(!CurrentUser.CheckAccessPremission(Premissions))
{
cout<<"\t\t\t\t\t==================================================\n";
cout<<"\t\t\t\t\t      Access Denied Please Contact Your Admin     \n";
cout<<"\t\t\t\t\t==================================================\n";
return false;
}
else 
{
    return  true;
}



}

};