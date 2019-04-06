#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <string>
#include <iomanip>
using namespace std;


/****************************** Class Account Begin ********************************/
/////////////////////////////////////////////////////////////////////////////////////

class Account {

	double balance;
	
public:
	Account(double=0);
	virtual bool debit(double);		//withdraw money, return true iff balance >= debit amount
	virtual void credit(double);	//deposit money
	virtual string getClassName();
	
	//getter & setter
	void setBalance(double);
	double getBalance() const;
};


Account::Account(double initialBalance) {
	setBalance(initialBalance);
}
bool Account::debit(double debitAmount) {
	
	if (debitAmount < 0) {
		throw invalid_argument("Debit amount must be >= 0.");
	}
	
	if (getBalance() >= debitAmount) {
		setBalance(getBalance() - debitAmount);
		return true;
	} else {
		return false;
	}
}
void Account::credit(double creditAmount) {
	if (creditAmount >= 0) {
		setBalance(getBalance() + creditAmount);
	} else {
		throw invalid_argument("Credit amount must be >= 0.");
	}
}
string Account::getClassName() {
	return "Account";
}



//getter & setter
void Account::setBalance(double b) {
	if (b >= 0) {
		balance = b;
	} else {
		throw invalid_argument("Balance must be >= 0.");
	}
}
double Account::getBalance() const {
	return balance;
}

/////////////////////////////////////////////////////////////////////////////////////
/****************************** Class Account End ********************************/






/****************************** Class Saving Account Begin ********************************/
////////////////////////////////////////////////////////////////////////////////////////////

class SavingAccount : public Account {
	
	double interestRate;	//interest = balance * interestRate%
	
public:
	SavingAccount(double=0, double=0);
	virtual double calculateInterest() const;	//interest = balance * interestRate%
	virtual string getClassName();
	
	//getter & setter
	void setInterestRate(double);
	double getInterestRate() const;
};


SavingAccount::SavingAccount(double initialBalance, double rate) : Account(initialBalance) {
	setInterestRate(rate);
}
double SavingAccount::calculateInterest() const {
	return getBalance() * getInterestRate() / 100;
}
string SavingAccount::getClassName() {
	return "SavingAccount";
}



//getter & setter
void SavingAccount::setInterestRate(double rate) {
	if (rate >= 0) {
		interestRate = rate;
	} else {
		throw invalid_argument("Interest rate must be >= 0.");
	}
}
double SavingAccount::getInterestRate() const {
	return interestRate;
}

//////////////////////////////////////////////////////////////////////////////////////////
/****************************** Class Saving Account End ********************************/







/****************************** Class Checking Account Begin ********************************/
//////////////////////////////////////////////////////////////////////////////////////////////

class CheckingAccount : public Account {
	
	double transactionFee;
	
public:
	CheckingAccount(double=0, double=0);
	virtual bool debit(double);		//withdraw money, return true iff balance >= debit amount, charge fee when finish withdraw
	virtual void credit(double);	//deposit money, charge fee when finish deposit
	virtual string getClassName();
	
	//getter & setter
	void setTransactionFee(double);
	double getTransactionFee();
};


CheckingAccount::CheckingAccount(double initialBalance, double fee) : Account(initialBalance) {
	setTransactionFee(fee);
}
bool CheckingAccount::debit(double debitAmount) {
	if (Account::debit(debitAmount)) {
		Account::debit(transactionFee);
		return true;
	} else {
		return false;
	}
}
void CheckingAccount::credit(double creditAmount) {
	Account::credit(creditAmount);
	Account::debit(transactionFee);
}
string CheckingAccount::getClassName() {
	return "CheckingAccount";
}



//getter & setter
void CheckingAccount::setTransactionFee(double fee) {
	if (fee >= 0) {
		transactionFee = fee;
	} else {
		throw invalid_argument("Transaction fee must be >= 0.");
	}
}
double CheckingAccount::getTransactionFee() {
	return transactionFee;
}

////////////////////////////////////////////////////////////////////////////////////////////
/****************************** Class Checking Account End ********************************/



int main() {
	vector<Account*> accounts(5);
	
	accounts[1] = new SavingAccount(25, 3);
	accounts[2] = new CheckingAccount(80, 1);
	accounts[3] = new SavingAccount(200, 1.5);
	accounts[4] = new CheckingAccount(400, 0.5);
	
	cout << fixed << setprecision(2);
	
	for (int i = 1; i <= 4; ++i) {
		
		double creditAmount, debitAmount;
		cout << "Account " << i << " balance: $" << accounts[i]->getBalance() << endl;
		
		if (accounts[i]->getClassName() == "SavingAccount") {
			
			cout << "Enter an amount to withdraw from Account " << i << ": ";
			cin >> debitAmount;
			accounts[i]->debit(debitAmount);
			cout << "Enter an amount to deposit from Account " << i << ": ";
			cin >> creditAmount;
			accounts[i]->credit(creditAmount);
			
			double interest = ((SavingAccount*)accounts[i])->calculateInterest();
			cout << "Adding $" << interest << " interest to Account " << i << " (a SavingAccount)" << endl;
			accounts[i]->credit(interest);
			
		} else {
			
			cout << "Enter an amount to withdraw from Account " << i << ": ";
			cin >> debitAmount;
			cout << "$" << ((CheckingAccount*)accounts[i])->getTransactionFee() << " transaction fee charged." << endl;
			accounts[i]->debit(debitAmount);
			cout << "Enter an amount to deposit from Account " << i << ": ";
			cin >> creditAmount;
			accounts[i]->credit(creditAmount);
			cout << "$" << ((CheckingAccount*)accounts[i])->getTransactionFee() << " transaction fee charged." << endl;
			
		}
		
		cout << "Updated Account " << i << " balance: $" << accounts[i]->getBalance() << endl;
		cout << endl;
	}
	
	
	for (int i = 1; i <= 4; ++i) {
		delete accounts[i];
	}
}
