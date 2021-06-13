#include "Transaction.hpp"
#include <string>

int Transaction :: nextTransactionID = 0;

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount) {
	// initialising variables
	transactionID = nextTransactionID++;
	this -> state = PENDING;
	tempAmount = amount;


	this -> FromAccount = fromAccount;
	this -> ToAccount = toAccount;

	// situations of amount if dollars or cents is a negative

	if (amount.getDollars() < 0 && amount.getCents() >= 0) {
		this -> tempAmount = Money (0, amount.getCents());
	}
	else if (amount.getCents() < 0 && amount.getDollars() >= 0){
		this -> tempAmount = Money (amount.getDollars(), 0);
	}
	else if (amount.getDollars() <= 0 && amount.getCents() <= 0 ){
		this -> tempAmount = Money (0,0);
	}
	else{
		this -> tempAmount = amount;
	}
}

bool Transaction::performTransaction(){
	// function performs pending transactions returns true if it is successful

	if (state == PENDING) {
		if(FromAccount -> withdrawMoney(tempAmount) == false) {
			this -> state = FAILED;
			return false;
		}

		if(ToAccount -> depositMoney(tempAmount) == false) {
			FromAccount -> revertWithdrawal(tempAmount);		// use to revert to original amount if deposit is unsuccessful
			this -> state = FAILED;
			return false;
		}

		this -> state = COMPLETED;
		return true;
	}
	else if(state == COMPLETED){
		return false;
	}

	else {
		this -> state = FAILED;
		return false;
	}
}

TransactionState Transaction::getState() const {
	// returns state of transaction

	if (state == COMPLETED){
		return COMPLETED;
	}
	else if (state == PENDING) {
		return PENDING;
	}
	else {
		return FAILED;
	}
}

Money Transaction::getAmount() const {
	// returns the amount of the transaction

	return this -> tempAmount;
}

Account* Transaction::getToAccount() const {
	// gets the to account
	return ToAccount;
}

Account* Transaction::getFromAccount() const {
// return from account

	return FromAccount;
}


int Transaction::getID() const {
	// returns transaction ID
	return transactionID;
}

Transaction::~Transaction() {

}

