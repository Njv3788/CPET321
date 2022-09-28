/**********************************************************/
/*** Title: main.cpp           					        ***/
/*** Description: bank account #1                   	***/
/**********************************************************/
#include <iostream>
#include <iomanip>
#include "BankAccount.h"
using namespace std;

int main() {

	// Create Mike's and Linda's Bank Accounts
	BankAccount Mikes_Accts("Mike", 500.00, 1000.00);
	BankAccount Lindas_Accts("Linda", 1500.00, 2000.00);

	//**************************************//
	// Mike's Accounts
	//**************************************//

	// Display Mike's Accounts
	Mikes_Accts.DisplayBalances();

	// Pay Day #1
	// Deposit $450 to checking and $100 to savings
	Mikes_Accts.DepositChecking(450);
	Mikes_Accts.DepositSavings(100);
	Mikes_Accts.DisplayBalances();

	// Pay Some Bills
	Mikes_Accts.WithdrawChecking(39.50);
	Mikes_Accts.WithdrawChecking(78.42);
	Mikes_Accts.WithdrawChecking(103.17);
	Mikes_Accts.DisplayBalances();

	// Pay Day #2
	// Deposit $250 to checking and $50 to savings
	Mikes_Accts.DepositChecking(250);
	Mikes_Accts.DepositSavings(50);
	Mikes_Accts.DisplayBalances();
	//cout << Mikes_Accts;

	// Rent is due, transfer Savings-to-Checking
	Mikes_Accts.TransferToChecking(500);
	Mikes_Accts.WithdrawChecking(1205.00);
	Mikes_Accts.DisplayBalances();
	//cout << Mikes_Accts;

	// Pay Day #3
	// Deposit $675 to checking & transfer $375 to savings
	Mikes_Accts.DepositChecking(675);
	Mikes_Accts.TransferToSavings(375);
	Mikes_Accts.DisplayBalances();
	//cout << Mikes_Accts;

	//**************************************//
	// Linda's Accounts
	//**************************************//

	// Display Linda's Accounts
	Lindas_Accts.DisplayBalances();

	// Pay Day #1 for Linda
	//    -- Deposit $1450 to checking 
	//    -- Deposit $800 to savings
	//    -- Display Linda's Accounts (using DisplayBalances() function)
	Lindas_Accts.DepositChecking(1450);
	Lindas_Accts.DepositSavings(800);
	Lindas_Accts.DisplayBalances();

	// Pay Some Bills for Linda
	//    -- Withdraw $148.57 from checking 
	//    -- Withdraw $208.79 from checking 
	//    -- Withdraw $1105.25 from checking 
	//    -- Display Linda's Accounts (using the friend function)
	Lindas_Accts.WithdrawChecking(148.57);
	Lindas_Accts.WithdrawChecking(208.79);
	Lindas_Accts.WithdrawChecking(1105.25);
	Lindas_Accts.DisplayBalances();

	// Transfer Funds
	//    -- Transfer $850 from checking to savings
	//    -- Withdraw $575 from savings
	//    -- Display Linda's Accounts (using the friend function)
	Lindas_Accts.TransferToSavings(800);
	Lindas_Accts.WithdrawSavings(675);
	Lindas_Accts.DisplayBalances(); 

	return 0;
}
/**********************************************************/