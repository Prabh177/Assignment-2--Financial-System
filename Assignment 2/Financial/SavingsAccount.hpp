#include "Account.hpp"

#ifndef SAVINGSACCOUNT_HPP_
#define SAVINGSACCOUNT_HPP_

class SavingsAccount : public Account {

private:
	int bonusCount;
	Money BonusValue;


	SavingsAccount& operator=(const SavingsAccount &other);
    SavingsAccount(const SavingsAccount &other);
public:

    bool revertWithdrawal(Money amount);

	SavingsAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	Money getBonusValue() const;
	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_HPP_ */
