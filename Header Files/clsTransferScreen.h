#pragma once
#include<iostream>
#include"clsScreen.h"
class clsTransferScreen:protected clsScreen{
private:
static void _PrintClintCard(clsBankClint Clint)
{
cout<<"=======================================\n";
cout<<"               Clint Card:             \n";
cout<<"=======================================\n";
cout<<"FullName      : "<<Clint.FullName()<<endl;
cout<<"AccountNumber : "<<Clint.AccountNumber()<<endl;
cout<<"Balance       : "<<Clint.getAccountBalance()<<endl;
cout<<"=======================================\n";
}
static string _ReadAccountNumber(string Messeage)
{
    string AccountNumber;
    cout<<Messeage<<endl;
    cin>>AccountNumber;
    while(!clsBankClint::IsClintExsist(AccountNumber))
    {
        cout<<"Account Number Not Found Please Try Again..."<<endl;
        cin>>AccountNumber;
    
    }

return AccountNumber;
}
static float _ReadBalance()
{
    float BalanceTransfer=0;
    cout<<"Enter How Many To Transfer:\n";
    cin>>BalanceTransfer;
    return BalanceTransfer;
}
public:

static void ShowTransferScreen()
{
clsScreen::_DrawScreenHeader("Transfer Screen");

string AccountNumber1,AccountNumber2;

AccountNumber1=_ReadAccountNumber("Please Enter Number To Transfer From");

clsBankClint ClintTrasferFrom=clsBankClint::Find(AccountNumber1);
_PrintClintCard(ClintTrasferFrom);

AccountNumber2=_ReadAccountNumber("Please enter Number To Transfer To");

clsBankClint ClintTrasferTo=clsBankClint::Find(AccountNumber2);
_PrintClintCard(ClintTrasferTo);

float BalanceTransfer=_ReadBalance();
while(ClintTrasferFrom.getAccountBalance()<BalanceTransfer)
{
    cout<<"Balance Bigger Than You Have..\n Enter How Many To Transfer:\n";
    cin>>BalanceTransfer;
}

cout<<"Are You Suer?[y/n]\n";
char Accept='n';
cin>>Accept;
if(tolower(Accept)=='y')
{
if(ClintTrasferFrom.Transfer(ClintTrasferTo,BalanceTransfer))
{
cout<<"Transfer Done Succfuly\n";

_PrintClintCard(ClintTrasferFrom);
_PrintClintCard(ClintTrasferTo);

}
else
{
    cout<<"Transfer Falid..";
}
}
else
{
    return;
}

}

};