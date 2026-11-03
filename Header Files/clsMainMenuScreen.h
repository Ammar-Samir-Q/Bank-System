#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsDeleteClintScreen.h"
#include"clsShowClintListScreen.h"
#include"clsAddNewClintScreen.h"
#include"clsUpdateClintScreen.h"
#include"clsFindClintScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyMenuScreen.h"
using namespace std;
class clsMainMenu:protected clsScreen{
    private:
     enum enMainMenueOptions{eShowClintList=1,eAddNewClint=2,eDeleteClint=3,eUpdateClint=4,eFindClint=5,eTransactions=6,eManageUsers=7,eLoginRegister=8,eCurrencyMenu=9,eLogout=10};
     static short _ReadMainMenuOption()
    {
        cout<<"\t\t\t\t\tPlease Enter Your Choice [1/10]:\n";
        short Choice=clsInputValidate::ReadIntNumberBetween(1,10,"Please enter Number Between 1/10:");
        return Choice;
    }
     static void _ShowAllClintScreen()
        {
            //cout<<"\nShow All clint Screen Will be here....\n";
            clsShowClintList::ShowClintList();

        }
     static void _GoBackToMainMenu()
     {
        cout<<"Press Any key To Back To MainMenu...\n";
        system("pause>0");
        ShowMainMenu();
     }   
     static void _ShowAddClintScreen()
     {
      
      // cout<<"\n Add Clint Screen Will Be Here.... \n";
     clsAddNewClint::ShowAddNewClintMenu();
   }
     static void _ShowDeleteClintScreen()
     {
         // cout<<"\n Delete Clint Screen Will Be Here.... \n";
            clsDeleteClintScreen::ShowDeleteClintScreen();
      }
     static void _ShowUpdateClintScreen()
     {
        //cout<<"\n Update Clint Screen Will Be Here.... \n";
        clsUpdateClint::ShowUpdateClintScreen();
     }
     static void _ShowFindClintScreen()
     {
        //cout<<"\n Find Clint Screen Will Be Here.... \n";
        clsFindClint::ShowFindClintScreen();
     }
     static void _ShowTransactionsScreen()
     {
       // cout<<"\n Transactions Screen Will Be Here.... \n";
       clsTrasactionsScreen::ShowTransactionsScreen();
     }
     static void _ShowManageUsersScreen()
     {
       // cout<<"\n Manage Users Screen Will Be Here.... \n";
       clsManageUsers::ShowManageUsersScreen();
     }
     static void _LogOut()
     {
        //cout<<"\nEnd Screen Will Be Here.... \n";
        CurrentUser=clsBankUsers::Find("","");
     }
     static void _ShowLogReigsterMenu()
     {
      clsRegisterScreen::ShowRegisterScreen();
     }
     static void _ShowCurrencyMenu()
     {
         // cout<<"Currency Menu Will Be Here...\n";
         clsCurrencyMenuScreen::ShowCurrencyMenuScreen();
     }
     static void _PerformMainMenuOption(enMainMenueOptions Choice)
    {
            switch (Choice)
            {
                case enMainMenueOptions::eShowClintList:
                system("cls");
                _ShowAllClintScreen();
                _GoBackToMainMenu();
                break;
                case enMainMenueOptions::eAddNewClint:
                system("cls");
                _ShowAddClintScreen();
                _GoBackToMainMenu();
                break;
                case enMainMenueOptions::eDeleteClint:
                system("cls");
                _ShowDeleteClintScreen();
                _GoBackToMainMenu();
                break;
                case enMainMenueOptions::eUpdateClint:
                system("cls");
                _ShowUpdateClintScreen();
                _GoBackToMainMenu();
                break;
                case enMainMenueOptions::eFindClint:
                system("cls");
                _ShowFindClintScreen();
                _GoBackToMainMenu();
                break;
                case enMainMenueOptions::eTransactions:
                system("cls");
                _ShowTransactionsScreen();
                _GoBackToMainMenu();
                break;
                case enMainMenueOptions::eManageUsers:
                system("cls");
                _ShowManageUsersScreen();
                _GoBackToMainMenu();
                break;
                case enMainMenueOptions::eLoginRegister:
                system("cls");
                _ShowLogReigsterMenu();
                _GoBackToMainMenu();
                case enMainMenueOptions::eCurrencyMenu:
                system("cls");
                _ShowCurrencyMenu();
                _GoBackToMainMenu();
                case enMainMenueOptions::eLogout:
                system("cls");
                _LogOut();
                break;



            }


    }


    public:
   static void ShowMainMenu()
    {
        system("cls");
        clsScreen::_DrawScreenHeader("Main Screen");
        cout<<"\t\t\t\t\t"<<"======================MainMenue====================\n";
        cout<<"\t\t\t\t\t"<<"[1]-Show Clints List.\n";
        cout<<"\t\t\t\t\t"<<"[2]-Add New Clint.\n";
        cout<<"\t\t\t\t\t"<<"[3]-Delete Clint.\n";
        cout<<"\t\t\t\t\t"<<"[4]-Update Clint.\n";
        cout<<"\t\t\t\t\t"<<"[5]-Find Clint.\n";
        cout<<"\t\t\t\t\t"<<"[6]-Transactions\n";
        cout<<"\t\t\t\t\t"<<"[7]-Manage Users.\n";
        cout<<"\t\t\t\t\t"<<"[8]-Show Log Register.\n";
        cout<<"\t\t\t\t\t"<<"[9]-Show Currency Menu.\n";
        cout<<"\t\t\t\t\t"<<"[10]-logout.\n";
        cout<<"\t\t\t\t\t"<<"======================================================\n";
        _PerformMainMenuOption((enMainMenueOptions)_ReadMainMenuOption());
    }











};