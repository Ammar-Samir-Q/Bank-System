#pragma once
#include<iostream>
#include"clsScreen.h"
#include<fstream>

class clsCurrnecy:protected clsScreen{
private:
enum enMode{eUpdateMode=1,eEmptyMode=2};
enMode _Mode;
string _Country;
string _CurrnecyCode;
string _CurrnecyName;
double _Rate;


string _ConvertCurrencyRecordToLine(clsCurrnecy C,string Speretor="#//#")
{
string cLine;
cLine=C.GetCountry()+Speretor;
cLine+=C.GetCurrencyCode()+Speretor;
cLine+=C.GetCurrnecyName()+Speretor;
cLine+=to_string(C.GetRate());

return cLine;
}

void _SaveCurrencyDataToFile(vector<clsCurrnecy>vCurrency)
{
fstream MyFile;
MyFile.open("Currencies.txt",ios::out);
if(MyFile.is_open())
{
    string DataLine;
    for(clsCurrnecy &C:vCurrency)
    {
        DataLine=_ConvertCurrencyRecordToLine(C);
        MyFile<<DataLine<<endl;
    }

}

MyFile.close();
}

static clsCurrnecy _ConvertCurrencyLineToRecord(string Line)
{
vector<string>vCurrency=clsString::Split(Line,"#//#");

return clsCurrnecy(enMode::eUpdateMode,vCurrency[0],vCurrency[1],vCurrency[2],stof(vCurrency[3]));
}

static  vector <clsCurrnecy> _LoadCurrencysDataFromFile()
{

    vector <clsCurrnecy> vCurrencys;

    fstream MyFile;
    MyFile.open("Currencies.txt", ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;

        while (getline(MyFile, Line))
        {

            clsCurrnecy Currency = _ConvertCurrencyLineToRecord(Line);

            vCurrencys.push_back(Currency);
        }

        MyFile.close();

    }

    return vCurrencys;

}

void _Update()
{
vector<clsCurrnecy>_vCurrency=_LoadCurrencysDataFromFile();


for(clsCurrnecy &C:_vCurrency)
{
if(C.GetCurrencyCode()==_CurrnecyCode)
{
C=*this;
break;
}
}
_SaveCurrencyDataToFile(_vCurrency);
}







static clsCurrnecy _GetEmptyObject()
{
return clsCurrnecy(enMode::eEmptyMode,"","","",0);
}

public:

clsCurrnecy(enMode Mode,string Country,string CurrnecyCode,string CurrnceyName,double Rate)
{
_Mode=Mode;
_Country=Country;
_CurrnecyCode=CurrnecyCode;
_CurrnecyName=CurrnceyName;
_Rate=Rate;
}

bool IsEmpty()
{
return (_Mode==enMode::eEmptyMode);
}

//get
string GetCountry()
{
    return _Country;
}
string GetCurrencyCode()
{
    return _CurrnecyCode;
}
string GetCurrnecyName()
{
    return _CurrnecyName;
}
float GetRate()
{
    return _Rate;
}

void UpdateRate(float NewRate)
{
_Rate=NewRate;
_Update();
}

static clsCurrnecy FindByCode(string CurrencyCode)
{
CurrencyCode=clsString::UpperAllString(CurrencyCode);
fstream MyFile;
MyFile.open("Currencies.txt",ios::in);
if(MyFile.is_open())
{
 string Line;
 while(getline(MyFile,Line))
 {
    clsCurrnecy C=_ConvertCurrencyLineToRecord(Line);
    if((C.GetCurrencyCode())==CurrencyCode)
    {
        MyFile.close();
        return C;
    }

 }

}



MyFile.close();
return _GetEmptyObject();
}

static clsCurrnecy FindByCountry(string CurrencyName)
{
    CurrencyName=clsString::UpperAllString(CurrencyName);
fstream MyFile;
MyFile.open("Currencies.txt",ios::in);
if(MyFile.is_open())
{
 string Line;
 while(getline(MyFile,Line))
 {
    clsCurrnecy C=_ConvertCurrencyLineToRecord(Line);
    C.GetCountry()=clsString::UpperAllString(C.GetCountry());
    if((C.GetCountry())==CurrencyName)
    {
        MyFile.close();
        return C;
    }

 }

}
MyFile.close();
return _GetEmptyObject();
}

static bool IsCurrencyExist(string CurrencyCode)
{
clsCurrnecy C=FindByCode(CurrencyCode);
return (!C.IsEmpty());
}

static vector<clsCurrnecy> GetCurrencisList()
{
    return _LoadCurrencysDataFromFile();
}

static void PrintCurrencyCard(clsCurrnecy Currency)
{
cout<<"=============================================\n";
cout<<"                CurrencyCard                 \n";
cout<<"=============================================\n";
cout<<"Country  : "<<Currency.GetCountry()<<endl;
cout<<"Code     : "<<Currency.GetCurrencyCode()<<endl;
cout<<"Name     : "<<Currency.GetCurrnecyName()<<endl;
cout<<"Rate(1$) : "<<Currency.GetRate()<<endl;
cout<<"=============================================\n";
}

float ConvertToUSD(float Amount)
{
return (float)(Amount/GetRate());
}

float CovertToOtherCurrency(float Amount,clsCurrnecy CurrencyTo)
{
float AmountInUSd=ConvertToUSD(Amount);
if(CurrencyTo.GetCurrencyCode()=="USD")
{
    return AmountInUSd;
}
return (float)(AmountInUSd*CurrencyTo.GetRate());


}
};