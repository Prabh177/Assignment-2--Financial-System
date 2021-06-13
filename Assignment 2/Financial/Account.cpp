#include "Account.hpp"

//Static int initialiser
int Account::nextAccountID = 0;

Account::Account(const int customerID) {
	this -> accountID = nextAccountID++;	// Creates New account ID everytime constructor is called
	this -> customerID = customerID;		//customer ID input
	this -> balance = Money (0,0); 			// Balance of creating a new Account (zero dollars, zero cents)

}

int Account::getAccountID() const {
	return accountID;
}

int Account::getCustomerID() const {
	return customerID;						// returns customer ID
}

Money Account::getBalance() const {
	return this -> balance;					// returns balance
}

Account::~Account() {
											// no memory stored on heap therefore no destructor code
}

