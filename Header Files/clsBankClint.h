#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"clsString.h"
#include<fstream>
#include"clsPerson.h"
#include"Global.h"
class clsBankClint :public clsPerson {
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool MarkedForDelete = false;

	static vector<clsBankClint> _LoadClintDataFromFile()
	{
		vector<clsBankClint>vClints;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClint Clint = _ConvertLineToClintObject(Line);
				vClints.push_back(Clint);
			}
			MyFile.close();
		}
		return vClints;
	}

	static clsBankClint _ConvertLineToClintObject(string Line, string Spertor = "#//#")
	{
		vector<string>VClints = clsString::Split(Line, Spertor);
		return clsBankClint(enMode::UpdateMode, VClints[0], VClints[1], VClints[2], VClints[3], VClints[4]
			, VClints[5], stod(VClints[6]));
	}

	static clsBankClint _GetEmptyObject()
	{
		return clsBankClint(enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 0);
	}

	static string _ConvertClintObjectToLine(clsBankClint Clint, string Spertor = "#//#")
	{
		string ClintRecord = "";
		ClintRecord += Clint.getFirstName() + Spertor;
		ClintRecord += Clint.getLastName() + Spertor;
		ClintRecord += Clint.getEmail() + Spertor;
		ClintRecord += Clint.getPhone() + Spertor;
		ClintRecord += Clint.AccountNumber() + Spertor;
		ClintRecord += Clint.getPinCode() + Spertor;
		ClintRecord += to_string(Clint.getAccountBalance());
		return ClintRecord;
	}

	string _PrepareTrasferLog(clsBankClint ClintTo, float Amount, string Spertor = "#//#")
	{
		string ClintRecord = "";
		ClintRecord = clsDate::GetSystemDateAndTimeString() + Spertor;
		ClintRecord += AccountNumber() + Spertor;
		ClintRecord += ClintTo.AccountNumber() + Spertor;
		ClintRecord += to_string(Amount) + Spertor;
		ClintRecord += to_string(getAccountBalance()) + Spertor;
		ClintRecord += to_string(ClintTo.getAccountBalance()) + Spertor;
		ClintRecord += CurrentUser.getUserName();
		return ClintRecord;
	}

	void _RegisterTransferLog(clsBankClint ClintTo, float TransferBalance)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			string LogLine1 = _PrepareTrasferLog(ClintTo, TransferBalance);
			MyFile << LogLine1 << endl;
			MyFile.close();
		}
		else
		{
			MyFile.close();
			return;
		}
	}



	static void _SaveClintDataToFile(vector<clsBankClint>& vClints)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			string DataLine;
			for (clsBankClint& C : vClints)
			{
				if (C.MarkedForDelete == false)
				{
					DataLine = _ConvertClintObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}


	}
	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.close();
	}
	void _Update()
	{
		vector<clsBankClint>vClints;
		vClints = _LoadClintDataFromFile();
		for (clsBankClint& C : vClints)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClintDataToFile(vClints);
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClintObjectToLine(*this));
	}

public:
	struct stTransferLog {
		string Date;
		string SourceAccount;
		string DestnitionAccount;
		float BalanceAmount;
		float SourceBalance;
		float DestntionBalance;
		string UserName;
	};

	enum enSaveResults { SvFaliEmptyObject = 0, SvSucceeded = 1, SvFalidBecauseAccExsist = 3 };

	clsBankClint(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber
		, string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_Mode = Mode;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string getPinCode()
	{
		return _PinCode;
	}

	void setAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float getAccountBalance()
	{
		return _AccountBalance;
	}

	void Print()
	{
		cout << "=======================================\n";
		cout << "               Clint Card:             \n";
		cout << "=======================================\n";
		cout << "FirstName     : " << getFirstName() << endl;
		cout << "LastName      : " << getLastName() << endl;
		cout << "FullName      : " << FullName() << endl;
		cout << "Email         : " << getEmail() << endl;
		cout << "Phone         : " << getPhone() << endl;
		cout << "AccountNumber : " << AccountNumber() << endl;
		cout << "PassWord      : " << getPinCode() << endl;
		cout << "Balance       : " << getAccountBalance() << endl;
		cout << "=======================================\n";
	}

	static clsBankClint Find(string AccountNumber)
	{
		vector<clsBankClint>vClints;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClint Clint = _ConvertLineToClintObject(Line, "#//#");
				if (Clint.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Clint;
				}
				vClints.push_back(Clint);
			}
			MyFile.close();
		}
		return _GetEmptyObject();
	}

	static clsBankClint Find(string AccountNumber, string Password)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClint Clint = _ConvertLineToClintObject(Line, "#//#");
				if (Clint.AccountNumber() == AccountNumber && Clint.getPinCode() == Password)
				{
					MyFile.close();
					return Clint;
				}
			}
			MyFile.close();
		}
		return _GetEmptyObject();
	}
	static bool IsClintExsist(string AccountNumber)
	{
		clsBankClint Clint = Find(AccountNumber);
		return (!Clint.IsEmpty());
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
			if (IsClintExsist(_AccountNumber))
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
	static clsBankClint GetAddNewClint(string AccountNumber)
	{
		return clsBankClint(enMode::AddNewMode, " ", " ", " ", " ", AccountNumber, " ", 0);
	}

	bool Delete()
	{
		vector<clsBankClint>vClints;
		vClints = _LoadClintDataFromFile();
		for (clsBankClint& C : vClints)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C.MarkedForDelete = true;
				break;
			}
		}
		_SaveClintDataToFile(vClints);
		*this = _GetEmptyObject();
		return true;

	}

	static vector<clsBankClint> GetClintList()
	{
		return _LoadClintDataFromFile();
	}

	static int GetClintsBalances()
	{
		vector<clsBankClint>vClints = _LoadClintDataFromFile();
		int TotalBalances = 0;
		for (clsBankClint& C : vClints)
		{
			TotalBalances += C.getAccountBalance();
		}
		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool WithDraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}

	}

	bool Transfer(clsBankClint ToClint, float balance)
	{
		if (_AccountBalance >= balance)
		{
			WithDraw(balance);
			ToClint.Deposit(balance);

			_RegisterTransferLog(ToClint, balance);

			return true;
		}
		else
		{
			return false;
		}
	}

	static vector<stTransferLog> _GetTransferLogList()
	{
		vector<stTransferLog>vLogs;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open())
		{

			string Line;
			stTransferLog TL;
			while (getline(MyFile, Line))
			{
				TL = ConvertTransferLogToRecord(Line);
				vLogs.push_back(TL);
			}
		}
		MyFile.close();
		return vLogs;

	}
	static stTransferLog ConvertTransferLogToRecord(string Line)
	{
		stTransferLog TL;
		vector<string>vLogs = clsString::Split(Line, "#//#");
		TL.Date = vLogs[0];
		TL.SourceAccount = vLogs[1];
		TL.DestnitionAccount = vLogs[2];
		TL.BalanceAmount = stof(vLogs[3]);
		TL.SourceBalance = stof(vLogs[4]);
		TL.DestntionBalance = stof(vLogs[5]);
		TL.UserName = vLogs[6];

		return TL;
	}

};