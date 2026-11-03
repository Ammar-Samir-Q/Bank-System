#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsListCurrencyScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateRateScreen.h"
#include"clsCurrencyClaculatorScreen.h"
class clsCurrencyMenuScreen:protected clsScreen{
private:
enum enCurrency{eCurrnciesList=1,eFindCurrency=2,eUpdateRate=3,eCurrencyCaluclator=4,eMainMenu=5};
static short _ReadChoice()
{


cout<<"Please enter Your Choice [1/5]:\n";
return clsInputValidate::ReadIntNumberBetween(1,5,"Please Enter Number Between 1/5:");

}
static void _ShowCurrnciesListScreen()
{
//cout<<"Currenisce List Screen Will Be Here...\n";
clsListCurrencyScreen::showListCurrnecy();
}
static void _ShowFindCurrencyScreen()
{
//cout<<"Find Currency Screen Will Be Here...\n";
clsFindCurrencyScreen::ShowFindCurrencyScreen();
}
static void _ShowUpdateRateScreen()
{
//cout<<"Update Rate Screen Will Be Here...\n";
clsUpdateRateScreen::ShowUpdateRateScreen();
}

static void _ShowCurrencyCalculatorScreen()
{
//cout<<"Currency Calculator Screen Will Be Here...\n";
clsCurrencyCalculator::ShowClaculatorScreen();
}

static void _GoBackToCurrencyMenu()
{
cout<<"Press any key to go back to Currency menu...\n";
system("pause>0");
ShowCurrencyMenuScreen();
}

static void _PerformCurrenciesOption(enCurrency Choice)
{
switch (Choice)
{
case enCurrency::eCurrnciesList:
system("cls");    
_ShowCurrnciesListScreen();
_GoBackToCurrencyMenu();
    break;
case enCurrency::eFindCurrency:
system("cls");    
_ShowFindCurrencyScreen();
_GoBackToCurrencyMenu();
break;
case enCurrency::eUpdateRate:
system("cls");    
_ShowUpdateRateScreen();
_GoBackToCurrencyMenu();
    break;

case enCurrency::eCurrencyCaluclator:
system("cls");    
_ShowCurrencyCalculatorScreen();  
_GoBackToCurrencyMenu();  
break;

case enCurrency::eMainMenu:
system("cls");    

break;

default:
break;
}










}
public:
static void ShowCurrencyMenuScreen()
{
system("cls");
clsScreen::_DrawScreenHeader("Currency Menu Screen");

cout<<"\t\t\t\t\t===========================================================\n";
cout<<"\t\t\t\t\t[1]-List Currencies."<<endl;
cout<<"\t\t\t\t\t[2]-Find Currency ."<<endl;
cout<<"\t\t\t\t\t[3]-Update Rate ."<<endl;
cout<<"\t\t\t\t\t[4]-Currency Calcutaor ."<<endl;
cout<<"\t\t\t\t\t[5]-MainMenu ."<<endl;
cout<<"\t\t\t\t\t===========================================================\n";
_PerformCurrenciesOption((enCurrency)_ReadChoice());


}





};