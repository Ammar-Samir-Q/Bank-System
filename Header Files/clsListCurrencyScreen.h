#include<iostream>
#include"clsScreen.h"
#include"clsCurrncey.h"
#include<iomanip>
class clsListCurrencyScreen: protected clsScreen{
private:
static void _PrintCurrencyLine(clsCurrnecy C)
{
    cout<<"\t\t\t\t\t"<<"|"<<setw(30)<<left<<C.GetCountry();
    cout<<"|"<<setw(5)<<left<<C.GetCurrencyCode();
    cout<<"|"<<setw(35)<<left<<C.GetCurrnecyName();
    cout<<"|"<<setw(10)<<left<<C.GetRate();

}










public:
static void showListCurrnecy()
{
vector<clsCurrnecy>vCurrencies=clsCurrnecy::GetCurrencisList();

clsScreen::_DrawScreenHeader("Currencies List");

cout<<"\t\t\t\t\t"<<"============================================================================================================\n";
cout<<"\t\t\t\t\t"<<setw(30)<<left<<"|Country";
cout<<setw(5)<<left<<"  |Code  ";
cout<<setw(35)<<left<<"|Name";
cout<<setw(10)<<left<<"|Rate";
cout<<"\n\t\t\t\t\t"<<"============================================================================================================\n";

if(vCurrencies.size()==0)
{

    cout<<"No Data Found...\n";
}
else
{
for(clsCurrnecy &C:vCurrencies)
{

_PrintCurrencyLine(C);
cout<<endl;
}
}
cout<<"\t\t\t\t\t"<<"============================================================================================================\n";











}







};