#pragma once
#include"clsScreen.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include"clsBankUsers.h"
class clsRegisterScreen:protected clsScreen{
private:
static void _PrintLogLine(clsBankUsers::stLogRegister U)
{
cout<<"\t\t\t\t\t|"<<setw(30)<<U.Date;
cout<<"|"<<setw(15)<<U.UserName;
cout<<"|"<<setw(15)<<U.Password;
cout<<"|"<<setw(12)<<U.Premissions<<"|";
}
static void _PrintLogRegister()
{
    vector<clsBankUsers::stLogRegister>vUsers=clsBankUsers::GetLogRegisterList();
cout<<"\t\t\t\t\t==============================================================================\n";
cout<<"\t\t\t\t\t|"<<setw(30)<<"Date";
cout<<"|"<<setw(15)<<"UserName";
cout<<"|"<<setw(15)<<"Password";
cout<<"|"<<setw(12)<<"Premissions|\n";
cout<<"\t\t\t\t\t==============================================================================\n";

if(vUsers.size()==0)
{
cout<<"\n\n\n\n\nNo Logs Avalaible..\n";
}
else
 {
for(clsBankUsers::stLogRegister &U:vUsers)
{
_PrintLogLine(U);
cout<<endl;
}

 }


 cout<<"\t\t\t\t\t==============================================================================\n";

}





public:
static void ShowRegisterScreen()
{
if(!clsScreen::CheckAccessRights(clsBankUsers::enPremissions::pLogRegister))
{
return;
}
clsScreen::_DrawScreenHeader("Log Register Menu");
_PrintLogRegister();
}











};