#pragma once
#include<iostream>
#include"clsBankClint.h"
#include"clsScreen.h"
#include"clsString.h"
#include<iomanip>

class clsTransferLogScreen: protected clsScreen{
private:
static void _PrintLogLine(clsBankClint::stTransferLog TL)
{

cout<<"\t\t\t\t\t|"<<setw(20)<<left<<TL.Date;
cout<<setw(10)<<left<<"|"+TL.SourceAccount;
cout<<setw(10)<<left<<"|"+TL.DestnitionAccount;
cout<<setw(20)<<left<<"|"+to_string(TL.BalanceAmount);
cout<<setw(20)<<left<<"|"+to_string(TL.SourceBalance);
cout<<setw(20)<<left<<"|"+to_string(TL.DestntionBalance);
cout<<setw(10)<<left<<"|"+TL.UserName;
}

public:
static void ShowTransferLogScreen()
{
clsScreen::_DrawScreenHeader("Transfer Log Screen");

vector<clsBankClint::stTransferLog>vLogs=clsBankClint::_GetTransferLogList();

cout<<"\t\t\t\t\t=================================================================================================================\n";
cout<<"\t\t\t\t\t"<<setw(20)<<left<<"|Date";
cout<<setw(10)<<left<<" |Acc.S";
cout<<setw(10)<<left<<" |Acc.D";
cout<<setw(20)<<left<<" |Balance";
cout<<setw(20)<<left<<" |Balance.S";
cout<<setw(20)<<left<<" |Balance.D";
cout<<setw(10)<<left<<" |UserName\n";
cout<<"\t\t\t\t\t=================================================================================================================\n";

if(vLogs.size()==0)
{
cout<<"\n\t\t\t\t\tNo Logs Found....\n";
}
else
{
   for(clsBankClint::stTransferLog &TL : vLogs)
{
   _PrintLogLine(TL);
   cout<<endl;
}
  
cout<<"\t\t\t\t\t=================================================================================================================\n";




}





}






}; 