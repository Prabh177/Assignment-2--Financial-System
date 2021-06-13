#include "Account.hpp"

#ifndef CHEQUEACCOUNT_HPP_
#define CHEQUEACCOUNT_HPP_

class ChequeAccount : public Account {

private:
	Money *transactionFee;	//Declaring transaction Fee object stored on heap
	int depositLimitCents;		//integer of the cheque account's deposit limit so its not a magic number
	int transactionFeeDollars;	// the transaction Fee integer in dollars so there is no magic number

	ChequeAccount& operator=(const ChequeAccount &other);
    ChequeAccount(const ChequeAccount &other);
public:
	ChequeAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool revertWithdrawal(Money amount);
	bool depositMoney(Money amount);
	Money* getTransactionFee() const;
	virtual ~ChequeAccount();
};

#endif /* CHEQUEACCOUNT_HPP_ */
