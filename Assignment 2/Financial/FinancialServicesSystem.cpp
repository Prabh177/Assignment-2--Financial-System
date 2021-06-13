#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>




FinancialServicesSystem::FinancialServicesSystem() {
	//initialising variables
	sizeCustomer= 0;
	sizeAccount = 0;
	sizeTransaction = 0;


}

int FinancialServicesSystem::findHighestID(){
	//cycles through to find the highest transaction ID from transaction Vector
	int highestID = 0;
	for (int i = 0; i < sizeTransaction; i++) {
		if (highestID < vectorTransactions[i]-> getID()) {
			highestID = vectorTransactions[i]-> getID();
		}
	}
	return highestID;
}


std::string FinancialServicesSystem::author(){
	// returns MY UPI
	return "pjan912";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {
	// function checks to see if the input customer ID is already in the vectorCustomers
	// then adds the customer if not present in the vector returning true
	if (sizeCustomer == 0){
		vectorCustomers.push_back(customer);
		sizeCustomer = vectorCustomers.size();
		return true;
	}
	else if(verifyCustomer(customer->getID()) == false) {
		vectorCustomers.push_back(customer);
		sizeCustomer = vectorCustomers.size();
		return true;
	}
	return false;
}

bool FinancialServicesSystem::addAccount(Account* account) {
	// function checks to see if the input account ID and customer is already in the vectorAccounts and vectorCustomers
	// then adds the account if not present in the vector returning true
	if (verifyCustomer(account->getCustomerID()) == true){
		if (sizeAccount == 0){
				vectorAccounts.push_back(account);
				sizeAccount = vectorAccounts.size();
				return true;
			}

		else if(verifyAccount(account->getAccountID()) == false) {
				vectorAccounts.push_back(account);
				sizeAccount = vectorAccounts.size();
				return true;
				}
	}

	return false;

}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {
	// function checks to see if the input account ID is already in the vectorAccounts, customer is in the vectorCustomers
	// account is already in the vector accounts
	// then adds the account if not present in the vector returning true

	Account* FromAccount = transaction -> getFromAccount();
	int accountIDFrom = FromAccount -> getAccountID();

	Account* ToAccount = transaction -> getToAccount();
		int accountIDTo = ToAccount -> getAccountID();

	if (transaction -> getState() == PENDING && verifyAccount(accountIDFrom) == true && verifyAccount(accountIDTo) == true){
			if (sizeTransaction == 0){
					vectorTransactions.push_back(transaction);
					sizeTransaction = vectorTransactions.size();
					return true;
				}

			else{

				for (int i = 0; i < sizeTransaction; i++) {
						Transaction* inventoryTransaction = vectorTransactions[i];

					if (inventoryTransaction->getID() != transaction->getID()) {
							vectorTransactions.push_back(transaction);
							sizeTransaction = vectorTransactions.size();
							return true;
					}

				}
			}
		}
	return false;
}

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {
	//Cycles through transaction vector and performs pending transactions returning a vector
	//of transactions which were successfully completed recently

	std::vector<Transaction*> tempVector;

	for (int i=0; i< findHighestID(); i++){
		if (verifyTransaction(i+1)==true){

			for (int j= 0; j < sizeTransaction; j++){

				if (vectorTransactions[j]-> getID() == i + 1 && vectorTransactions[j]->getState()==PENDING) {

					if(vectorTransactions[j]-> performTransaction() == true) {
						tempVector.push_back(vectorTransactions[j]);
					}
				}
			}
		}
	}
	return tempVector;
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {
	// Goes through all account vectors and add the money objects as one big total money object

	Money balance = Money (0,0);
	for (int i = 0; i < sizeAccount ; i++){

		if (customerID == vectorAccounts[i]-> getCustomerID())	{

			if ( vectorAccounts[i]->getBalance().asCents() >= 0 ){
				balance.add(vectorAccounts[i]->getBalance());
			}

			else {
				int bal = vectorAccounts[i]->getBalance().asCents() * (-1);
				Money money (bal/100,bal%100);
				balance.subtract(money);
			}
		}
	}
	return balance;
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {
	//checks to see if the customerID is in the customer vector already returning true if it is

	for (int i = 0; i < sizeCustomer; i++ ){
		Customer* inventoryCustomer = vectorCustomers[i];

		if (inventoryCustomer -> getID() == customerID){
			return true;
		}

	}
	return false;

}

bool FinancialServicesSystem::verifyAccount(int accountID) const {
	//checks to see if the accountID is in the account vector already returning true if it is

	for (int i = 0; i < sizeAccount; i++ ){
			Account* inventoryAccount = vectorAccounts[i];

			if (inventoryAccount -> getAccountID() == accountID){
				return true;
			}

		}
	return false;
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {
	//checks to see if the transactionID is in the transaction vector already returning true if it is

		for (int i = 0; i < sizeTransaction; i++ ){
				Transaction* inventoryTransaction = vectorTransactions[i];

				if (inventoryTransaction -> getID() == transactionID){
				return true;
		}

	}

	return false;
}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	//returns vector of accounts

	return vectorAccounts;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	//returns vector of customers

	return vectorCustomers;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	//returns vector of transactions

	return vectorTransactions;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {
	// returns vector of transactions in this current state

	std::vector<Transaction*> vector;
	for (int i = 0; i < sizeTransaction; i++){
		Transaction* temporary = vectorTransactions[i];

		if (state == COMPLETED && temporary -> getState() == COMPLETED){
			vector.push_back(temporary);
		}

		else if (state == PENDING && temporary -> getState() == PENDING){
			vector.push_back(temporary);
		}

		else if (state == FAILED && temporary -> getState() ==FAILED){
			vector.push_back(temporary);
		}
	}
	return vector;
}

FinancialServicesSystem::~FinancialServicesSystem() {

}

