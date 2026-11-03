#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class clsUtlity{
enum enPrimes {Prime=1,notPrime=2};
enum enCharcterTybe{CaptialLetters=1,SmallLetters=2,SpecilCharcter=3,Digit=4};

static string _GenerateKey()
{
string key;
key=GenerateWord(enCharcterTybe::CaptialLetters,4)+"-";
key+=GenerateWord(enCharcterTybe::CaptialLetters,4)+"-";
key+=GenerateWord(enCharcterTybe::CaptialLetters,4)+"-";
key+=GenerateWord(enCharcterTybe::CaptialLetters,4);
return key;
}

public:
static void Srand()
{
    srand((unsigned)time(NULL));
}

static string EncryptText(string text,int key)
{
for(int i=0;i<=text.length();i++)
{
text[i]=char((int)text[i]+key);
}
return text;
}

static string DscryptText(string text,int key)
{
for(int i=0;i<=text.length();i++)
{
text[i]=char((int)text[i]-key);
}
return text;
}

static int RandomNumber(int From, int To)
{
//Function to generate a random number
int randNum = rand() % (To - From + 1) + From;
return randNum;
}

static char GetRandomCharcter(enCharcterTybe CharcterTybe)
{
switch(CharcterTybe)
{
case enCharcterTybe::CaptialLetters:return char(RandomNumber(65,90));
break;
case enCharcterTybe::Digit:return char(RandomNumber(48,57));
break;
case enCharcterTybe::SmallLetters:return char(RandomNumber(97,122));
break;
case enCharcterTybe::SpecilCharcter:return char(RandomNumber(33,47));
break;
}
return 0;
}

static string GenerateWord(enCharcterTybe tybe,int length)
{
    string word;
for(int cou=1;cou<=length;cou++)
{
word+=GetRandomCharcter(CaptialLetters);
}
return word;
}

static void GenerateRandomKeys(short int NumberOfKeys)
{    
for(int cou=1;cou<=NumberOfKeys;cou++)
{
cout<<"Key: "<<"["<<cou<<"]"<<":";
cout<<_GenerateKey();
cout<<endl;
}
}

static int TimesRepated(int arr[100],int Length,int NumberToCheck)
{
    int num=0,counter=0;
for(int i=0;i<=Length-1;i++)
{
if(arr[i]==NumberToCheck)
{
counter++;
}
}
return counter;
}

static void FillArrayWithRandomNumbers(int arr[100],int ArryLength)
{
for(int cou=0;cou<=ArryLength-1;cou++)
{

arr[cou]=RandomNumber(0,100);

}
}

static int MaxArray(int arr[100],int Length)
{
    int max=0;
for(int i=0;i<=Length-1;i++)
{
if(arr[i]>max)
{
max=arr[i];
}
}
return max;
}

static int MinArray(int arr[100],int Length)
{
    int min=0;
    min=arr[0];
for(int i=0;i<=Length-1;i++)
{
if(arr[i]<min)
{
min=arr[i];
}
}
return min;
}

static int SumArry(int arr[100],int ArryLength)
{
    int sum=0;
for(int cou=0;cou<=ArryLength-1;cou++)
{
sum+=arr[cou];
}
return sum;

}

static float AvrageOfArrys(int arr[100],int ArryLength)
{
float Reasult=(float)SumArry(arr,ArryLength)/(ArryLength);
return (float)Reasult;
}

static void CopyArry(int ArrSource[100],int ArrDenimetion[100],int ArryLength)
{
for(int cou=0;cou<=ArryLength-1;cou++)
{
ArrDenimetion[cou]=ArrSource[cou];
}

}

static enPrimes CheckPrime(int num)
{
int M=round(num/2);
for(int cou=2;cou<=M;cou++)
{
if (num%cou==0)
{return enPrimes::notPrime;}

}
return enPrimes::Prime;
}

static void CopyOnlyPrimeArry(int ArrSource[100],int ArrDenimetion[100],int ArryLength,int &ArryLength2)
{
    int couArr2=0;
for(int cou=0;cou<=ArryLength-1;cou++)
{
    if(CheckPrime(ArrSource[cou])==enPrimes::Prime)
{
ArrDenimetion[couArr2]=ArrSource[cou];
couArr2++;
}

}
ArryLength2=--couArr2;
}

static void Sum2Arrys(int arr1[100],int arr2[100],int arr3[100],int ArryLength)
{
    int sum=0;
for(int i=0;i<ArryLength;i++)
{
 arr3[i]=(arr1[i]+arr2[i]);
}
}

static void Swap(int& A, int& B)
{
int Temp;
Temp = A;
A = B;
B = Temp;
}

static void ShuffleArray(int arr[100], int arrLength)
{
for (int i = 0; i < arrLength; i++)
{
Swap(arr[RandomNumber(1, arrLength) - 1],
arr[RandomNumber(1, arrLength) - 1]);
}
}

static void FillArrayWithKeys(string arr[100],int Length)
{
for(int i=0;i<Length;i++)
{
arr[i]=_GenerateKey();
}
}

static int FindNumberPostionInArray(int arr[100],int Length,int Number)
{
for(int i=0;i<Length;i++)
{
if(arr[i]==Number)
{
return i;
}
}
return -1;
}

static bool NumberFoundInArray(int arr[100],int Length,int number)
{
return FindNumberPostionInArray(arr,Length,number)!=-1;
}

static void AddArrayElement(int number,int arr[100],int &Length)
{
Length++;
arr[Length-1]=number;
}

static void CopyOnlyDisicntNumbers(int ArrSource[100],int ArrDenimetion[100],int ArryLength,int &ArrDenimetionLength)
{
for(int cou=0;cou<=ArryLength-1;cou++)
{
    if(!NumberFoundInArray(ArrDenimetion,ArryLength,ArrSource[cou]))
{
    AddArrayElement(ArrSource[cou],ArrDenimetion,ArrDenimetionLength);
}
else
continue;
}}

static bool ISPalindromeArray(int arrSource[100],int Length)
{
    for(int i=0;i<Length;i++)
{
if(arrSource[Length-1-i]!=arrSource[i])
{
return false;
}
}
return true;
}

static int CountOddNumbersInArray(int ArrSource[100],int ArryLength)
{
    int OddCounter=0;
for(int cou=0;cou<=ArryLength-1;cou++)
{
    if((ArrSource[cou]%2)!=0)
{
OddCounter++;
}
}
return OddCounter;
}

static int CountEvenNumbersInArray(int ArrSource[100],int ArryLength)
{
    int EvenCounter=0;
for(int cou=0;cou<=ArryLength-1;cou++)
{
    if((ArrSource[cou]%2)==0)
{
EvenCounter++;
}
}
return EvenCounter;
}

static int CountPostiveNumbersInArray(int ArrSource[100],int ArryLength)
{
    int Counter=0;
for(int cou=0;cou<=ArryLength-1;cou++)
{
    if((ArrSource[cou]>=0))
{
Counter++;
}
}
return Counter;
}

static int CountNegtiveNumbersInArray(int ArrSource[100],int ArryLength)
{
    int Counter=0;
for(int cou=0;cou<=ArryLength-1;cou++)
{
    if((ArrSource[cou]<0))
{
Counter++;
}
}
return Counter;
}
static string NumberToText(int Number)
{
    if(Number==0)
    {
        return " ";
    }
    if(Number>=1 && Number<=19)
    {
    string arr[]={" "," One "," Two "," Three "," Four "," Five "," Six "," Seven "," Eight "," Nine "," Ten ",
    " Eleven "," Tweleve "," Thirteen "," Fourteen "," Fifteen "," SixTeen "," SevenTeen "," EightTeen "," NineTeen "};
    return arr[Number];
    }
 if(Number>=20&&Number<=99)
 {
 string arr[]={" "," "," Twenty "," Thirty "," Fourty "," Fifty "," Sixty "," Seventy "," Eighty"," Ninty "};
 return arr[Number/10]+" "+NumberToText(Number%10);
 }
 if(Number>=100&&Number<=199)
 {
 return "OneHandurd"+NumberToText(Number%100);
 }
 if(Number>=200&&Number<=999)
 {
 return NumberToText(Number/100)+"Handurds"+NumberToText(Number%100);
 }
 if(Number>=1000&&Number<=1999)
 {
 return "One Thousends"+NumberToText(Number%1000);
 }
 if(Number>=2000&&Number<=999999)
 {
 return NumberToText(Number/1000)+"Thousnds"+NumberToText(Number%1000);
 }
 if(Number>=999999&&Number<=1999999)
 {
     return "One Million"+NumberToText(Number%1000000);
 }
 if(Number>=2000000&&Number<=9999999)
 {
 return NumberToText(Number/1000000)+"Millions"+NumberToText(Number%1000000);
 }
 if(Number>=10000000&&Number<=19999999)
 {
     return "One Billion"+NumberToText(Number%10000000);
 }
 else
 {
     return NumberToText(Number/10000000)+"Billions"+NumberToText(Number%10000000);
 }
 }
};