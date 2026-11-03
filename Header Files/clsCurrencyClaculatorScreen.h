#include<iostream>
#include"clsScreen.h"
#include"clsCurrncey.h"
class clsCurrencyCalculator:protected clsScreen{
private:
static clsCurrnecy _GetCurrency(string Messeage)
{
    string Code;
cout<<Messeage<<endl;
cin>>Code;
while(!clsCurrnecy::IsCurrencyExist(Code))
{
    cout<<"code Not Found Please try Again..\n";
    cout<<"Enter Currency Code:\n";
    cin>>Code;

}
return clsCurrnecy::FindByCode(Code);

} 
static int _CalcuteFromCodeToUSD(double Amount,clsCurrnecy CFrom)
{
return Amount/(CFrom.GetRate());
}
static void _PrintClacutionResult(clsCurrnecy CurrFrom,clsCurrnecy CurrTo,float Amount)
{
float AmountInUSD=CurrFrom.ConvertToUSD(Amount);
cout<<"Converting From "<<CurrFrom.GetCurrencyCode()<<" To USD "<<" = "<<AmountInUSD<<" USD"<<endl;
if(CurrTo.GetCurrencyCode()=="USD")
{
    return;
}
float CurrAmount=CurrFrom.CovertToOtherCurrency(Amount,CurrTo);
cout<<"Converting From "<<CurrFrom.GetCurrencyCode()<<" To "<<CurrTo.GetCurrencyCode()<<" = "<<CurrAmount<<CurrTo.GetCurrencyCode()<<endl;



}





public:
static void ShowClaculatorScreen()
{
clsScreen::_DrawScreenHeader("Claculator Screen");
char Continue='y';
while (Continue=='y'||Continue=='Y')
{
clsCurrnecy CurrencyFrom=_GetCurrency("Enter Currency 1 Code:");
clsCurrnecy CurrencyTo=_GetCurrency("Enter Currency 2 Code: ");
double Amount;
cout<<"Enter How Many To Exchange:\n";
cin>>Amount;
_PrintClacutionResult(CurrencyFrom,CurrencyTo,Amount);
cout<<"Do You Want To Recalacute Again:[y/n]:";
cin>>Continue;
}

}









};