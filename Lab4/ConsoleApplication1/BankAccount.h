//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef BankAccount_Header
#define BankAccount_Header

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount
{
private:
	string ownername;
	double savingAccount;
	double checkingAccount;

public:
	
	BankAccount()
	{
		ownername = "";
		savingAccount = 0;
		checkingAccount =0;

	};

	BankAccount(string name, double check, double save)
	{
		ownername = name;
		savingAccount = save;
		checkingAccount = check;

	};

	void WithdrawChecking(double amount)
	{
		if (amount > 0)
		{
			checkingAccount -= amount;
		}
	};
	
	void WithdrawSavings(double amount)
	{
		if (amount > 0)
		{
			savingAccount -= amount;
		};
	};

	void DepositChecking(double amount)
	{
		checkingAccount += amount;
	};

	void DepositSavings(double amount)
	{
		savingAccount += amount;
	};

	void TransferToChecking(double amount)
	{
		savingAccount -= amount;
		checkingAccount += amount;
		
	};

	void TransferToSavings(double amount)
	{
		checkingAccount -= amount;
		savingAccount += amount;
	}; 
	void DisplayBalances()
	{
		cout << fixed << setprecision(2);
		cout << left  << setw(16) << setfill('.') <<"Account Name"<<":";
		cout << right << setw(10) << setfill(' ') << ownername  << endl;
		cout << left  << setw(16) << setfill('.') << " Checking"<< ":";
		cout << right << setw(10) << setfill(' ') << checkingAccount << endl;
		cout << left  << setw(16) << setfill('.') << " Saving"<< ":" ;
		cout << right << setw(10) << setfill(' ') << savingAccount  << endl;
		cout << endl;
	};

};

#endif
