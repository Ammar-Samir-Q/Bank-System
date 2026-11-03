#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"
#include"clsPerson.h"
#include"clsUtlity.h"
#include"clsDate.h"

class clsBankUsers :public clsPerson {
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Premissions;
	bool MarkedForDelete = false;

	static vector<clsBankUsers> _LoadUserDataFromFile()
	{
		vector<clsBankUsers>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUsers User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}


	static clsBankUsers _ConvertLineToUserObject(string Line, string Spertor = "#//#")
	{
		vector<string>vUsers = clsString::Split(Line, Spertor);
		return clsBankUsers(enMode::UpdateMode, vUsers[0], vUsers[1], vUsers[2], vUsers[3], vUsers[4], clsUtlity::DscryptText(vUsers[5], 2), stoi(vUsers[6]));
	}
	static clsBankUsers _GetEmptyObject()
	{
		return clsBankUsers(enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 0);
	}

	string _PrepareLogLine()
	{
		string Spretor = "#//#";
		string LogLine = "";
		LogLine = clsDate::GetSystemDateAndTimeString() + Spretor;
		LogLine += _UserName + Spretor;
		LogLine += clsUtlity::EncryptText(_Password, 3) + Spretor;
		LogLine += (to_string(_Premissions));
		return LogLine;
	}

	static string _ConvertUserObjectToLine(clsBankUsers User, string Seperator = "#//#")
	{
		string UserRecord = "";
		UserRecord += User.getFirstName() + Seperator;
		UserRecord += User.getLastName() + Seperator;
		UserRecord += User.getEmail() + Seperator;
		UserRecord += User.getPhone() + Seperator;
		UserRecord += User.getUserName() + Seperator;
		UserRecord += clsUtlity::EncryptText(User._Password, 3) + Seperator;
		UserRecord += to_string(User.getPremissions());

		return UserRecord;
	}
	static string _ConvertUserObjectToLogLine(clsBankUsers User, string Seperator = "#//#")
	{

		string UserRecord = "";
		UserRecord += User.getUserName() + Seperator;
		UserRecord += User.getPassword() + Seperator;
		UserRecord += to_string(User.getPremissions());

		return UserRecord;
	}
	static void _SaveUserDataToFile(vector<clsBankUsers>& vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open())
		{
			string DataLine;
			for (clsBankUsers& U : vUsers)
			{
				if (U.MarkedForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}


	}
	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.close();
	}
	void _Update()
	{
		vector<clsBankUsers>vUsers;
		vUsers = _LoadUserDataFromFile();
		for (clsBankUsers& U : vUsers)
		{
			if (U.getUserName() == this->getUserName())
			{
				U = *this;
				break;
			}
		}
		_SaveUserDataToFile(vUsers);
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}



public:
	enum enSaveResults { SvFaliEmptyObject = 0, SvSucceeded = 1, SvFalidBecauseAccExsist = 3 };
	enum enPremissions { pAll = -1, pShowClint = 1, pAddClint = 2, pDeleteClint = 4, pUpdateClint = 8, pFindClint = 16, pTransactions = 32, pManageUsers = 64, pLogRegister = 128 };
	struct stLogRegister
	{
		string UserName;
		string Password;
		string Date;
		int Premissions;
	};


	clsBankUsers(enMode Mode, string FirstName, string LastName, string Phone, string Email, string UserName, string Password, int Premissions) :
		clsPerson(FirstName, LastName, Phone, Email) {
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Premissions = Premissions;
	}
	bool CheckAccessPremission(enPremissions Premissions)
	{
		if (this->getPremissions() == enPremissions::pAll)
		{
			return true;
		}
		if ((Premissions & this->getPremissions()) == Premissions)
		{
			return true;
		}
		else
		{
			return false;
		}



	}
	void SaveLog()
	{
		fstream MyFile;
		MyFile.open("LogRegister.txt", ios::app);
		if (MyFile.is_open())
		{
			string LogLine = _PrepareLogLine();
			MyFile << LogLine << endl;
		}
	}
	string getUserName()
	{
		return _UserName;
	}
	string getPassword()
	{
		return _Password;
	}
	int getPremissions()
	{
		return _Premissions;
	}
	void setPasswords(string Password)
	{
		_Password = Password;
	}
	void setPremissions(int Premissions)
	{
		_Premissions = Premissions;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	void Print()
	{
		cout << "============================================\n";
		cout << "               User Card:             \n";
		cout << "============================================\n";
		cout << "FirstName      : " << getFirstName() << endl;
		cout << "LastName       : " << getLastName() << endl;
		cout << "FullName       : " << FullName() << endl;
		cout << "Email          : " << getEmail() << endl;
		cout << "Phone          : " << getPhone() << endl;
		cout << "UserName       : " << getUserName() << endl;
		cout << "PassWord       : " << getPassword() << endl;
		cout << "Premissions    : " << getPremissions() << endl;
		cout << "============================================\n";
	}

	static clsBankUsers Find(string UserName)
	{
		vector<clsBankUsers>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUsers User = _ConvertLineToUserObject(Line, "#//#");
				if (User._UserName == UserName)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyObject();
	}

	static clsBankUsers Find(string UserName, string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUsers User = _ConvertLineToUserObject(Line, "#//#");
				if (User._UserName == UserName && User.getPassword() == Password)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyObject();
	}
	static bool IsUserExsist(string UserName)
	{
		clsBankUsers User = Find(UserName);
		return (!User.IsEmpty());
	}
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:

			return enSaveResults::SvFaliEmptyObject;
			break;

		case enMode::UpdateMode:

			_Update();
			return enSaveResults::SvSucceeded;

		case enMode::AddNewMode:
			if (IsUserExsist(_UserName))
			{
				return enSaveResults::SvFalidBecauseAccExsist;
			}
			else
			{
				_AddNew();
				return enSaveResults::SvSucceeded;
			}

		default:
			return enSaveResults::SvFaliEmptyObject;
		}
	}
	static clsBankUsers GetAddNewUser(string UserName)
	{
		return clsBankUsers(enMode::AddNewMode, " ", " ", " ", " ", UserName, " ", 0);
	}
	static vector<clsBankUsers> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}
	bool Delete()
	{
		vector<clsBankUsers>vUsers;
		vUsers = _LoadUserDataFromFile();
		for (clsBankUsers& U : vUsers)
		{
			if (U._UserName == _UserName)
			{
				U.MarkedForDelete = true;
				break;
			}
		}
		_SaveUserDataToFile(vUsers);
		*this = _GetEmptyObject();
		return true;

	}

	static stLogRegister ConvertLogRegisterToRecord(string Line)
	{
		stLogRegister L;
		vector<string>vLogRegisters = clsString::Split(Line, "#//#");
		L.Date = vLogRegisters[0];
		L.UserName = vLogRegisters[1];
		L.Password = clsUtlity::DscryptText(vLogRegisters[2], 3);
		L.Premissions = stoi(vLogRegisters[3]);

		return L;
	}


	static vector<stLogRegister> GetLogRegisterList()
	{
		vector<stLogRegister>vUsers;
		fstream MyFile;
		MyFile.open("LogRegister.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				stLogRegister Log = ConvertLogRegisterToRecord(Line);
				vUsers.push_back(Log);
			}
		}
		MyFile.close();
		return vUsers;
	}



};