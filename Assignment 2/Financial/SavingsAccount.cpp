#include "SavingsAccount.hpp"





SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	//initialising variables
	bonusCount = 1;
	this -> BonusValue = Money (10,0);
}

bool SavingsAccount::withdrawMoney(Money amount) {
	// withdraws money and its effects on the saving account and bonus value
	// returns true if successful
	if (amount.asCents() >= 0 && balance.asCents() >= amount.asCents()) {
		balance.subtract(amount);
		if (getBonusValue().getDollars() != 0){
			BonusValue.subtractDollars(2);
		}

	return true;
	}

	else {
		return false;
	}

}

bool SavingsAccount::depositMoney(Money amount) {
	// deposits and bonus value addition


	if (amount.asCents() >= 0 && bonusCount == 1){
		balance.add(amount);
		bonusCount++;
		return true;
	}
	else if (amount.asCents() >= 0 && bonusCount == 2){		// make sure this works for 1 negative and 1 postive value
															//and expected output
		balance.add(amount);
		balance.add(getBonusValue());
		bonusCount = 1;
		return true;
	}


	else {
	return false;
	}
}

Money SavingsAccount::getBonusValue() const {
	// gets bonus value money
	return BonusValue;
}

bool SavingsAccount::revertWithdrawal(Money amount){
	// reverts if the performing transaction fails when depositing
	if (amount.asCents() >= 0){
			balance.add(amount);
			BonusValue.addDollars(2);
			return true;
	}
	return false;
}

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


