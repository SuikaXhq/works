#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;


/*************************************** Class Employee Begin ******************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Employee {

	string firstName;
	string lastName;
	string SSN; //social security number

public:
	Employee(const string&, const string&, const string&);

	//getter & setter
	void setFirstName(const string&);
	string getFirstName() const;

	void setLastName(const string&);
	string getLastName() const;

	void setSSN(const string&);
	string getSSN() const;

	//functions to be inherited
	double earnings() const;
	void print() const;
};



Employee::Employee(	const string& first,
					const string& last,
					const string& ssn)
					:
					firstName(first),
					lastName(last),
					SSN(ssn)
{
	//empty
}

	//getter & setter
void Employee::setFirstName(const string& first) {
	firstName = first;
}
string Employee::getFirstName() const {
	return firstName;
}
void Employee::setLastName(const string& last) {
	lastName = last;
}
string Employee::getLastName() const {
	return lastName;
}
void Employee::setSSN(const string& ssn) {
	SSN = ssn;
}
string Employee::getSSN() const {
	return SSN;
}

	//functions to be inherited
void Employee::print() const {
	cout << getFirstName() << ' ' << getLastName() << "\nsocial security number: " << getSSN();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************** Class Employee End ******************************************/





/*************************************** Class CommissionEmployee Begin ******************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CommissionEmployee{

	double grossSales;
	double commissionRate;
	Employee employee;

public:
	CommissionEmployee(const string&, const string&, const string&, double=0.0, double=0.0);

	//getter & setter
	void setCommissionRate(double);
	double getCommissionRate() const;

	void setGrossSales(double);
	double getGrossSales() const;
	
	//getter & setter from base class
	void setFirstName(const string&);
	string getFirstName() const;

	void setLastName(const string&);
	string getLastName() const;

	void setSSN(const string&);
	string getSSN() const;

	//functions inherited
	double earnings() const;
	void print() const;
};


CommissionEmployee::CommissionEmployee(	const string& first,
										const string& last,
										const string& ssn,
										double sales,
										double rate)
										: employee(first, last, ssn)
{
	setGrossSales(sales);
	setCommissionRate(rate);
}


	//getter & setter
void CommissionEmployee::setCommissionRate(double rate) {
	if (rate > 0.0 && rate < 1.0) {
		commissionRate = rate;
	} else {
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
	}
}
double CommissionEmployee::getCommissionRate() const {
	return commissionRate;
}

void CommissionEmployee::setGrossSales(double sales) {
	if (sales >= 0.0) {
		grossSales = sales;
	} else {
		throw invalid_argument("Gross sales must be >= 0.0");
	}
}
double CommissionEmployee::getGrossSales() const {
	return grossSales;
}

	//getter & setter from base class
void CommissionEmployee::setFirstName(const string& first) {
	employee.setFirstName(first);
}
string CommissionEmployee::getFirstName() const {
	return employee.getFirstName();
}
void CommissionEmployee::setLastName(const string& last) {
	employee.setLastName(last);
}
string CommissionEmployee::getLastName() const {
	return employee.getLastName();
}
void CommissionEmployee::setSSN(const string& ssn) {
	employee.setSSN(ssn);
}
string CommissionEmployee::getSSN() const {
	return employee.getSSN();
}

	//functions inherited
double CommissionEmployee::earnings() const {
	return getCommissionRate() * getGrossSales();
}
void CommissionEmployee::print() const {
	cout << "commission employee: ";
	employee.print();
	cout << "\ngross sales: " << getGrossSales();
	cout << "; commission rate: " << getCommissionRate();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************** Class CommissionEmployee End ******************************************/







/*************************************** Class BasePlusCommissionEmployee Begin ******************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class BasePlusCommissionEmployee {

	double baseSalary;
	CommissionEmployee commissionEmployee;

public:
	BasePlusCommissionEmployee(const string&, const string&, const string&, double=0.0, double=0.0, double=0.0);

	//getter & setter
	void setBaseSalary(double);
	double getBaseSalary() const;
	
	//getter & setter from base class
	void setCommissionRate(double);
	double getCommissionRate() const;

	void setGrossSales(double);
	double getGrossSales() const;

	void setFirstName(const string&);
	string getFirstName() const;

	void setLastName(const string&);
	string getLastName() const;

	void setSSN(const string&);
	string getSSN() const;

	//functions inherited
	double earnings() const;
	void print() const;
};



BasePlusCommissionEmployee::BasePlusCommissionEmployee(	const string& first,
														const string& last,
														const string& ssn,
														double sales,
														double rate,
														double salary)
														: commissionEmployee(first, last, ssn, sales, rate)
{
	setBaseSalary(salary);
}


	//getter & setter
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
	if (salary >= 0.0) {
		baseSalary = salary;
	} else {
		throw invalid_argument("Base salary must be >= 0.0");
	}
}
double BasePlusCommissionEmployee::getBaseSalary() const {
	return baseSalary;
}


	//getter & setter from base class
void BasePlusCommissionEmployee::setCommissionRate(double rate) {
	commissionEmployee.setCommissionRate(rate);
}
double BasePlusCommissionEmployee::getCommissionRate() const {
	return commissionEmployee.getCommissionRate();
}

void BasePlusCommissionEmployee::setGrossSales(double sales) {
	commissionEmployee.setGrossSales(sales);
}
double BasePlusCommissionEmployee::getGrossSales() const {
	return commissionEmployee.getGrossSales();
}

void BasePlusCommissionEmployee::setFirstName(const string& first) {
	commissionEmployee.setFirstName(first);
}
string BasePlusCommissionEmployee::getFirstName() const {
	return commissionEmployee.getFirstName();
}
void BasePlusCommissionEmployee::setLastName(const string& last) {
	commissionEmployee.setLastName(last);
}
string BasePlusCommissionEmployee::getLastName() const {
	return commissionEmployee.getLastName();
}
void BasePlusCommissionEmployee::setSSN(const string& ssn) {
	commissionEmployee.setSSN(ssn);
}
string BasePlusCommissionEmployee::getSSN() const {
	return commissionEmployee.getSSN();
}


	//functions inherited
double BasePlusCommissionEmployee::earnings() const {
	return getBaseSalary() + commissionEmployee.earnings();
}
void BasePlusCommissionEmployee::print() const {
	cout << "base-salaried ";
	commissionEmployee.print();
	cout << "; base salary: " << getBaseSalary();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************** Class BasePlusCommissionEmployee End ******************************************/


int main() {
	CommissionEmployee* employee2 = new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
	BasePlusCommissionEmployee* employee3 = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);
	
	employee2->print();
	cout << endl;
	cout << "earned: $" << employee2->earnings() << endl << endl;
	employee3->print();
	cout << endl;
	cout << "earned: $" << employee3->earnings() << endl;
	
	delete employee2;
	delete employee3;
}
