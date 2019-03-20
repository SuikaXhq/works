#include <iostream>
#include <iomanip>
using namespace std;
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
class SavingsAccount{
	double savingsBalance;
public:
	static double annualInterestRate;
	SavingsAccount();
	SavingsAccount(double);
	double calculateMonthlyInterest();
	void static modifyInterestRate(double);
	double getBalance();
	void setBalance(double);
};
#endif

double SavingsAccount::annualInterestRate = 0.0;
SavingsAccount::SavingsAccount() : savingsBalance(0) {}
SavingsAccount::SavingsAccount(double balance) {
	setBalance(balance);
}

double SavingsAccount::calculateMonthlyInterest() {
	double monthlyInterest = getBalance() * annualInterestRate / 1200;
	setBalance(getBalance() + monthlyInterest);
	return monthlyInterest;
}

void SavingsAccount::modifyInterestRate(double rate) {
	if (rate < 0) {
		cerr << "Illegal argument rate = " << rate << "(<0)\n";
		return;
	}
	
	annualInterestRate = rate;
}

void SavingsAccount::setBalance(double balance) {
	if (balance < 0) {
		cerr << "Illegal argument balance = " << balance << "(<0)\n";
		return;
	}
	
	savingsBalance = balance;
}

double SavingsAccount::getBalance() {
	return savingsBalance;
}


int main() {
	SavingsAccount saver1(2000.00);
	SavingsAccount saver2(3000.00);
	cout << "Account 1 is initialized with " << fixed << setprecision(2) << saver1.getBalance() << "$" << endl;
	cout << "Account 2 is initialized with " << setprecision(2) << saver2.getBalance() << "$" << endl;
	
	SavingsAccount::modifyInterestRate(3);
	cout << "Annual interest rate = 3:\n";
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	cout << "Account 1 now has " << setprecision(2) << saver1.getBalance() << "$" << endl;
	cout << "Account 2 now has " << setprecision(2) << saver2.getBalance() << "$" << endl;
	
	SavingsAccount::modifyInterestRate(4);
	cout << "Annual interest rate = 4:\n";
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	cout << "Account 1 now has " << setprecision(2) << saver1.getBalance() << "$" << endl;
	cout << "Account 2 now has " << setprecision(2) << saver2.getBalance() << "$" << endl;
}
