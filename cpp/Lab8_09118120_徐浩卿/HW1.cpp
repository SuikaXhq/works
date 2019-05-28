#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;







/**************************** Class Account ****************************/


class Account {

	string firstName;
	string lastName;
	int ID;
	double balance;

public:
	Account(int=0, string="", string="", double=0.0);
	friend istream& operator>>(istream&, Account&);
	friend ostream& operator<<(ostream&, const Account&);

	//getter & setter
	void setFirstName(string);
	void setLastName(string);
	void setID(int);
	void setBalance(double);

	string getFirstName() const;
	string getLastName() const;
	int getID() const;
	double getBalance() const;
};


	Account::Account(int id, string first, string last, double initialBalance) : ID(id), firstName(first), lastName(last), balance(initialBalance)
	{
		//empty
	}



	istream& operator>>(istream& input, Account& s) {
		int id;
		string first, last;
		double balance;

		input >> id >> first >> last >> balance;
		s.setFirstName(first);
		s.setLastName(last);
		s.setID(id);
		s.setBalance(balance);

		return input;
	}

	ostream& operator<<(ostream& output, const Account& s) {
		output << s.getID() << ' ' << s.getFirstName() << ' ' << s.getLastName() << ' ' << s.getBalance() << endl;
		return output;
	}





		// getter & setter
	void Account::setFirstName(string first) 	 {firstName = first;}
	void Account::setLastName(string last)		 {lastName = last;}
	void Account::setID(int id) 				 {ID = id;}
	void Account::setBalance(double newBalance)	 {balance = newBalance;}

	string Account::getFirstName() const 		 {return firstName;}
	string Account::getLastName() const 		 {return lastName;}
	int Account::getID() const 					 {return ID;}
	double Account::getBalance() const 			 {return balance;}


/**************************** Class Account End ****************************/






void update(ifstream&, ifstream&, ofstream&);
void createOldMaster(ofstream&);
void createTransaction(ofstream&);
void printNewMaster(ifstream&);



int main() {
	
	string oldmastFileName = "oldmast.dat";
	string newmastFileName = "newmast.dat";
	string transFileName = "trans.dat";
	
	//creating records
	ofstream outOldMaster(oldmastFileName, ios::out);
	ofstream outTransaction(transFileName, ios::out);
	
	if (!outOldMaster || !outTransaction) {      // confirm the files are available
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	
	createOldMaster(outOldMaster);
	createTransaction(outTransaction);
	
	outOldMaster.close();
	outTransaction.close();
	
	
	
	//updating information
	cout << "\nUpdating..." << endl;
	ifstream inOldMaster(oldmastFileName, ios::in);
	ifstream inTransaction(transFileName, ios::in);
	ofstream outNewMaster(newmastFileName, ios::out);
	
	if (!inOldMaster || !inTransaction || !outNewMaster) {      // confirm the files are available
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	
	update(inOldMaster, inTransaction, outNewMaster);

	inOldMaster.close();
	inTransaction.close();
	outNewMaster.close();
	
	
	
	// checking newmast.dat
	cout << "\nHere is the new masters:" << endl;
	ifstream inNewMaster(newmastFileName, ios::in);
	
	if (!inNewMaster) {      // confirm the file is available
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	
	printNewMaster(inNewMaster);
	
	inNewMaster.close();

}








void update(ifstream& inMainFile, ifstream& inOperation, ofstream& output) {
	
	Account tempAccount;
	unsigned tempID = -1;
	double change = 0;
	inOperation >> tempID >> change;
	while (inMainFile >> tempAccount) {
		
		if (tempID != -1 && tempID < tempAccount.getID()) {
			cout << "Unmatched transaction record for account number " << tempID << endl;
			inOperation >> tempID >> change;
		}
		while (tempID == tempAccount.getID()) {
			tempAccount.setBalance(tempAccount.getBalance() + change);
			inOperation >> tempID >> change;        // scan next transaction record
		}
		output << tempAccount;
		
	}
	
	while (inOperation) {       // deal with transactions that account number > all of the accounts
		cout << "Unmatched transaction record for account number " << tempID << endl;
		inOperation >> tempID >> change;
	}
	
}





void createOldMaster(ofstream& outMainFile) {
	cout << "Enter main account records(input Ctrl+Z to end):" << endl;
	Account temp;
	while (cin >> temp) {
		outMainFile << temp;
	}
	cin.clear();
}








void createTransaction(ofstream& outOperation) {
	cout << "Enter transaction records(input Ctrl+Z to end):" << endl;
	unsigned ID;
	double change;
	while (cin >> ID >> change) {
		outOperation << ID << ' ' << change << endl;
	}
	cin.clear();
}







void printNewMaster(ifstream& inNewMainFile) {
	Account temp;
	while (inNewMainFile >> temp) {
		cout << temp;
	}
}
