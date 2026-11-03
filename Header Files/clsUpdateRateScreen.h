#include<iostream>
#include"clsScreen.h"
#include"clsCurrncey.h"
class clsUpdateRateScreen: protected clsScreen{
private:
static string _ReadCurrencyCode()
{
    string Code;
cout<<"Enter Currency Code:\n";
cin>>Code;


return Code;

} 
static double _ReadUpdateRateAmount()
{
    double NewRate;
cout<<"Enter New Rate:\n";
cin>>NewRate;
return NewRate;
}


public:
static void ShowUpdateRateScreen()
{
clsScreen::_DrawScreenHeader("Update Rate");
string Code=_ReadCurrencyCode();
while(!clsCurrnecy::IsCurrencyExist(Code))
{
    cout<<"Code Not Found...\n";
Code=_ReadCurrencyCode();
}
clsCurrnecy Currnecy=clsCurrnecy::FindByCode(Code);
clsCurrnecy::PrintCurrencyCard(Currnecy);
double NewRate=_ReadUpdateRateAmount();
cout<<"Are You Sure Update This Rate?[y/n]\n";
char Answer='n';
cin>>Answer;
if(tolower(Answer)=='y')
{
Currnecy.UpdateRate(NewRate);
cout<<"Updated Succssfuly..\n";
clsCurrnecy::PrintCurrencyCard(Currnecy);
}
else
{
    cout<<"Update cancceld...\n";
}

}



};