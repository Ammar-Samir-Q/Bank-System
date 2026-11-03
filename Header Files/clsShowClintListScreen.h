#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClint.h"
#include<iomanip>
class clsShowClintList:protected clsScreen{
private:
    static void _PrintClintData(clsBankClint C)
{
    cout<<"|"<<left<<setw(20)<<C.AccountNumber();
    cout<<"|"<<left<<setw(20)<<C.FullName();
    cout<<"|"<<left<<setw(20)<<C.getPhone();
    cout<<"|"<<left<<setw(20)<<C.getEmail();
    cout<<"|"<<left<<setw(20)<<C.getPinCode();
    cout<<"|"<<left<<setw(20)<<C.getAccountBalance();
}
public:    
    static void ShowClintList()
    {
      if(!CheckAccessRights(clsBankUsers::enPremissions::pShowClint))
        {
            return;
        }
        vector<clsBankClint>vClints=clsBankClint::GetClintList();
        string Title="ClintListMenu";
        string SubTitle="Clints["+to_string(vClints.size())+"]";
        clsScreen::_DrawScreenHeader(Title,SubTitle);
    cout<<"\n\t\t\tClint List Of["<<vClints.size()<<"]  Clints.\n";
    cout<<"===============================================================================================================================\n";
    cout<<"|"<<left<<setw(20)<<"AccountNumber  ";
    cout<<"|"<<left<<setw(20)<<"FullName       ";
    cout<<"|"<<left<<setw(20)<<"Phone          ";
    cout<<"|"<<left<<setw(20)<<"Email          ";
    cout<<"|"<<left<<setw(20)<<"PinCode        ";
    cout<<"|"<<left<<setw(20)<<"AccountBalance ";
    cout<<"\n===============================================================================================================================\n";
    if(vClints.size()==0)
    {
    cout<<"There are not Clints\n";
    }
    for(clsBankClint &C:vClints)
    {
    _PrintClintData(C);
    cout<<endl;
    }
    
    cout<<"\n===============================================================================================================================\n";
}
    
};