#include "Account.hpp"

#ifndef CREDITACCOUNT_HPP_
#define CREDITACCOUNT_HPP_

class CreditAccount : public Account {

private:
	int accountLimitCents;		// stored account limit for no magic number

	CreditAccount& operator=(const CreditAccount &other);
    CreditAccount(const CreditAccount &other);
public:
	CreditAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);

	bool revertWithdrawal(Money amount);
	virtual ~CreditAccount();
};

#endif /* CREDITACCOUNT_HPP_ */
