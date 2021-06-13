#include "CreditAccount.hpp"



CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	accountLimitCents = 500000;				// account limit as cents so there is no magic number
}

bool CreditAccount::withdrawMoney(Money amount) {
	// checks to see if the amount is not a negative
	if (amount.asCents() >= 0){
		balance.subtract(amount);		//subtracts the amount from balance
		return true;					//returns true if the withdrawal happens
	}

	else {
		return false;					// returns false if the withdrawal can't happen
	}

}

bool CreditAccount::depositMoney(Money amount) {
	//deposits money returning true or false

	Money temporaryBalance (0,0);
	temporaryBalance = balance;				// temporary copy of balance

	// checks if amount is not a negative
	if (amount.asCents() >= 0){
		temporaryBalance.add(amount);		// amount added for next if statement

		//checks if balance will exceed account limit with use of the temporary balance
		if (temporaryBalance.asCents() <= accountLimitCents){
			balance.add(amount);
			return true;					// returns true if deposit successful
		}
	}
	return false;							// returns true if deposit is unsuccessful

}
bool CreditAccount::revertWithdrawal(Money amount){
	//	helper function reverts transaction to original deposit if deposit in perform transaction fails
	// checks if amount is above zero
		if (amount.asCents() >= 0){
				balance.add(amount);
				return true;			// adds amount back and returns true for it occuring

		}
		return false;					// false if this funciton fails
}

CreditAccount::~CreditAccount() {

}
