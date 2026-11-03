#include<iostream>
#include"clsScreen.h"
#include"clsBankClint.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsUtlity.h"
class clsTotalBalances:protected clsScreen{
private:
static void _PrintClintBalancesLine(clsBankClint C)
{
    cout<<"|"<<left<<setw(20)<<C.AccountNumber();
    cout<<"|"<<left<<setw(30)<<C.FullName();
    cout<<"|"<<left<<setw(20)<<C.getAccountBalance();
}

public:
static void ShowTotalBalanceas()
{
        vector<clsBankClint>vClints=clsBankClint::GetClintList();
        clsScreen::_DrawScreenHeader("Total Balances Screen","Clints of ["+to_string(vClints.size())+"]");


    cout<<"\n\t\t\tBalance List Of["<<vClints.size()<<"]  Clints.\n";
    cout<<"==========================================================\n";
    cout<<"|"<<left<<setw(20)<<"AccountNumber  ";
    cout<<"|"<<left<<setw(30)<<"FullName       ";
    cout<<"|"<<left<<setw(20)<<"AccountBalance ";
    cout<<"\n==========================================================\n";
    if(vClints.size()==0)
    {
    cout<<"There are no Clints\n";
    }
    int TotalBalnces=clsBankClint::GetClintsBalances();
    for(clsBankClint &C:vClints)
    {
    _PrintClintBalancesLine(C);
    cout<<endl;
    }
    cout<<"==========================================================\n";
    cout<<"\t\t TotalBalnaces: ("<<TotalBalnces<<")"<<endl;
    cout<<"  ("<<clsUtlity::NumberToText(TotalBalnces)<<")"<<endl;
    system("pause>0");




}


};
