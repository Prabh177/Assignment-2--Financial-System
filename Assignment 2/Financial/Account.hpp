#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_
#include "Money.hpp"
class Account{



private:
	// Integers stored in account class for unique ID and the input of customer ID
	int customerID;
	int accountID;
	static int nextAccountID;

	Account& operator=(const Account &other);
	Account(const Account &other);

protected:
	Money balance;


public:


	Account(const int customerID);
	virtual bool withdrawMoney(Money amount) = 0;
	virtual bool depositMoney(Money amount) = 0;

	//Helper used to deposit withdrawed money back without additional changes, if transaction is unsuccessful
	virtual bool revertWithdrawal(Money amount) = 0;

	int getCustomerID() const;
	int getAccountID() const;
	Money getBalance() const;
	virtual ~Account();


};

#endif /* ACCOUNT_HPP_ */
