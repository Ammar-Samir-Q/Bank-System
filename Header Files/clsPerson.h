#pragma once
#include<iostream>
using namespace std;
class clsPerson{

string _FirstName;
string _LastName;
string _Phone;
string _Email;

public:

clsPerson(string FirstName,string LastName,string Email,string Phone)
{
_FirstName=FirstName;
_LastName=LastName;
_Email=Email;
_Phone=Phone;
}


//Set Probrtey:
void setFirstName(string FirstName)
{
_FirstName=FirstName;
}
void setLastName(string LastName)
{
_LastName=LastName;
}
void setEmail(string Email)
{
_Email=Email;
}
void setPhone(string Phone)
{
_Phone=Phone;
}

//GetProbrtey:
string getFirstName()
{
    return _FirstName;
}
string getLastName()
{
    return _LastName;
}
string getEmail()
{
    return _Email;
}
string getPhone()
{
    return _Phone;
}

string FullName()
{
    return _FirstName+" "+_LastName;
}








};