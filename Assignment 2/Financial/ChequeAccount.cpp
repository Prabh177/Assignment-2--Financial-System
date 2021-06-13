#include "ChequeAccount.hpp"


ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {
	 transactionFee = new Money(1,0);		//Pointer to Money therefore an object being stored on the heap
	 depositLimitCents = 300000;			// deposit limit as cents so no magic number
	 transactionFeeDollars = 1;				// transaction fee dollars so no magic number
}

bool ChequeAccount::withdrawMoney(Money amount) {

	// checking if there is enough balance for the transaction to complete AND amount amount is not a negative

	if (amount.asCents() + transactionFee -> asCents() <= balance.asCents() && amount.asCents() >= 0){
		balance.subtract(amount);								// subtracts amount
		balance.subtract(*transactionFee);						// subtracts transaction fee
		transactionFee -> addDollars(transactionFeeDollars);	// transaction Fee increases by 1 dollar

		return true;											// returns true if withdrawal is possible and occurs
	}
	else {
		return false;											// returns false if the withdrawal doesn't happen
	}
}

bool ChequeAccount::depositMoney(Money amount) {

	// checks the amount deposited does not cause it to exceed balance limit AND checks if amount isn't is not negative

	if (amount.asCents() <= depositLimitCents && amount.asCents() >= 0){
		balance.add(amount);						// adds the amount
		return true;								// amount has been deposited
	}

	return false;									// deposit doesn't occur therefore false
}

Money* ChequeAccount::getTransactionFee() const {
	return transactionFee;									//returns transactionFee object from heap
}



bool ChequeAccount::revertWithdrawal(Money amount) {
	// Helper function checks if amount withdrawn is not a negative
	// function reverts any withdrawals to original amount if perform transaction deposits in a transaction has failed
	if (amount.asCents() >= 0){
		balance.add(amount);						// returns the amount removed from a transactoin withdraw
		balance.add(*transactionFee);				// returns transaction fee into account
		transactionFee->subtractDollars(transactionFeeDollars); 	// returns transactionFee also to original state
		return true;		// revert has occured
	}
	return false;			// revert hasn't occured
}

ChequeAccount::~ChequeAccount() {
	delete transactionFee;			// transactionFee object stored on heap and therefore a destructor
}

