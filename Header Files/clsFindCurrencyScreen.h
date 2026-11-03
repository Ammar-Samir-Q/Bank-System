#include<iostream>
#include"clsScreen.h"
#include"clsCurrncey.h"
#include"clsInputValidate.h"
class clsFindCurrencyScreen:protected clsScreen{
private:
enum enFindTybe{ByCode=1,ByCountry=2};
static short _ReadChoice()
{
cout<<"Enter Your Choice [1/2]:\n";
return clsInputValidate::ReadIntNumberBetween(1,2,"Please enter Number Between 1/2:");
}

static void _FindByCode()
{
    string Code;
 cout<<"Please enter Code:\n";
 cin>>Code;
    clsCurrnecy Currency=clsCurrnecy::FindByCode(Code);
    if(!Currency.IsEmpty())
    {
        cout<<"Currency Found...\n";
        clsCurrnecy::PrintCurrencyCard(Currency);
        return;
    }
    else
    {
        cout<<"Currency not Found...\n";
    }
}

static void _FindByCountry()
{
    string Country;
 cout<<"Please enter Country:\n";
 cin>>Country;
    clsCurrnecy Currency=clsCurrnecy::FindByCountry(Country);
    if(!Currency.IsEmpty())
    {
        clsCurrnecy::PrintCurrencyCard(Currency);
        return;
    }
    else
    {
        cout<<"Currency not Found...\n";
    }
}

static void PerformFindOprtion(enFindTybe Choice)
{
switch (Choice)
{
case enFindTybe::ByCode:
 _FindByCode();    
    break;
case enFindTybe::ByCountry:
_FindByCountry();
break;

default:
    break;
}







}





public:
static void ShowFindCurrencyScreen()
{
cout<<"Find By [1]Code [2]Country\n:";
PerformFindOprtion((enFindTybe)_ReadChoice());

}





};