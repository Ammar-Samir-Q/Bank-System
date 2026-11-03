#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsMainMenuScreen.h"
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsMainMenuScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
class clsTrasactionsScreen:protected clsScreen{
private:
enum enTransactionsOprions{eDeposit=1,eWithDraw=2,eTotalBalances=3,eTransfer=4,eTrasnferLog=5,eMainMenu=6};
static short _ReadTransactionsOption()
{
    cout<<"\t\t\t\t\tPlease Enter Your Choice [1/6]:\n";
    short Choice=clsInputValidate::ReadIntNumberBetween(1,6,"Please enter Number Between 1/6:");
    return Choice;
}
static void _ShowDepositScreen()
{
//cout<<"Deposit Screen Will Be Here..\n";
clsDepositScreen::ShowDepositScreen();
} 
static void _ShowWithDrawScreen()
{
//cout<<"WithDraw Screen Will Be Here..\n";
clsWithDrawScreen::ShowWithDrawScreen();
} 
static void _ShowTotalBalancesScreen()
{
//cout<<"TotalBalances Screen Will Be Here..\n";
clsTotalBalances::ShowTotalBalanceas();
} 
static void _GoBackToTransactionsMenu()
{
cout<<"Press Any Key To Go Back To Tranasctions Menu...\n";
system("pause>0");
system("cls");
ShowTransactionsScreen();
}
static void _ShowTransferScreen()
{
clsTransferScreen::ShowTransferScreen();
}
static void _ShowTrasferLogScreen()
{
clsTransferLogScreen::ShowTransferLogScreen();
}

static void _PerformTranactionsOption(enTransactionsOprions Choice)
{
switch (Choice)
{
case enTransactionsOprions::eDeposit:
    system("cls");    
    _ShowDepositScreen();
    _GoBackToTransactionsMenu();
    break;
case enTransactionsOprions::eWithDraw:
    system("cls");    
    _ShowWithDrawScreen();
    _GoBackToTransactionsMenu();
    break;
    case enTransactionsOprions::eTotalBalances:
    system("cls");    
    _ShowTotalBalancesScreen();
    _GoBackToTransactionsMenu();
    break; 

    case enTransactionsOprions::eTransfer:
    system("cls");    
    _ShowTransferScreen();
    _GoBackToTransactionsMenu();
    break;
    case enTransactionsOprions::eTrasnferLog:
    system("cls");    
    _ShowTrasferLogScreen();
    _GoBackToTransactionsMenu();
    case enTransactionsOprions::eMainMenu:   
    break;
default:
    break;
}



}
public:
static void ShowTransactionsScreen()
{
    if(!CheckAccessRights(clsBankUsers::enPremissions::pTransactions))
    {
        return;
    }

clsScreen::_DrawScreenHeader("Transactions Screen");
cout<<"\t\t\t\t\t"<<"===================================\n";
cout<<"\t\t\t\t\t"<<"          Transactions Menu        \n";
cout<<"\t\t\t\t\t"<<"===================================\n";
cout<<"\t\t\t\t\t"<<"[1]-Deposit."<<endl;
cout<<"\t\t\t\t\t"<<"[2]-WithDraw."<<endl;
cout<<"\t\t\t\t\t"<<"[3]-TotalBalances."<<endl;
cout<<"\t\t\t\t\t"<<"[4]-Transfer."<<endl;
cout<<"\t\t\t\t\t"<<"[5]-TransferLog."<<endl;
cout<<"\t\t\t\t\t"<<"[6]-Main Menu"<<endl;
cout<<"\t\t\t\t\t"<<"===================================\n";
_PerformTranactionsOption((enTransactionsOprions)_ReadTransactionsOption());
}













};