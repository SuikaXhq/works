#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <typeinfo>
using namespace std;



/*************************************** Class Date Begin *******************************************/
//////////////////////////////////////////////////////////////////////////////////////////////////////

class Date {

	int month;
	int day;
	int year;

	static const int days[];
	
	void helpIncrement();    //+1 day

public:
	Date(int=1, int=1, int=1900);   //month, day, year

	//getter & setter
	void setDate(int, int, int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	static bool leapYear(int);
	bool endOfMonth() const;
	
	//operator functions
	friend ostream& operator<<(ostream&, const Date&);  //output
	Date& operator++();             //prefix ++
	Date operator++(int);           //postfix ++
	const Date& operator+=(int);    //add days on object
};



const int Date::days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

Date::Date(int month, int day, int year) {
	setDate(month, day, year);
}

	//getter & setter
void Date::setDate(int m, int d, int y) {

	if (m >= 1 && m <= 12) {
		month = m;
	} else {
		throw invalid_argument("Month must be 1-12");
	}

	if (y >= 1900) {
		year = y;
	} else {
		throw invalid_argument("Year must be >= 1900");
	}

	if ( 	(month == 2 && leapYear(year) && d >= 1 && d <= 29)
			||
			(d >= 1 && d <= days[month]) )
	{
		day = d;
	} else {
		throw invalid_argument("Day is out of range for current month and year");
	}
}
int Date::getDay() const{
	return day;
}
int Date::getMonth() const{
	return month;
}
int Date::getYear() const{
	return year;
}

bool Date::leapYear(int testYear) {
	if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0)) {  //leap year is a multiple of 4 and not a multiple of 100, or is a multiple of 400
		return true;
	} else {
		return false;
	}
}


void Date::helpIncrement() {
	
	if (!endOfMonth()) {
		++day;
	} else {    //carry for date
		if (month < 12) {
			++month;
			day = 1;
		} else {
			++year;
			month = 1;
			day = 1;
		}
	}
	
}

bool Date::endOfMonth() const{

	if (month == 2 && leapYear(year)) {
		return day == 29;   //29 days in Feb. in leap year
	} else {
		return day == days[month];
	}
	
}


	//operator functions
ostream& operator<<(ostream& output, const Date& date) {
	static string monthName[13] = {"", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	output << monthName[date.getMonth()] << ' ' << date.getDay() << ", " << date.getYear();
	return output;
}
Date& Date::operator++() {
	helpIncrement();
	return *this;
}
Date Date::operator++(int) {
	Date temp = *this;
	helpIncrement();
	return temp;
}
const Date& Date::operator+=(int addition) {
	for (int i = 0; i < addition; ++i) {
		helpIncrement();
	}
	
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************** Class Date End ******************************************/








/*************************************** Class Employee Begin ******************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Employee {
	
	string firstName;
	string lastName;
	string SSN; //social security number
	Date birthDate;
	
public:
	Employee(const string&, const string&, const string&, const Date&);
	
	//getter & setter
	void setFirstName(const string&);
	string getFirstName() const;
	
	void setLastName(const string&);
	string getLastName() const;
	
	void setSSN(const string&);
	string getSSN() const;

	void setBirthDate(const Date&);
	Date getBirthDate() const;
	
	//virtual functions to be inherited
	virtual double earnings() const = 0;
	virtual void print() const;
};



Employee::Employee(	const string& first,
					const string& last,
					const string& ssn,
					const Date& birth)
					:
					firstName(first),
					lastName(last),
					SSN(ssn),
					birthDate(birth)
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
void Employee::setBirthDate(const Date& birth) {
	birthDate = birth;
}
Date Employee::getBirthDate() const{
	return birthDate;
}

	//virtual functions to be inherited
void Employee::print() const {
	cout << getFirstName() << ' ' << getLastName() << "\nsocial security number: " << getSSN() << "\nbirth date: " << getBirthDate();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************** Class Employee End ******************************************/







/*************************************** Class SalariedEmployee Begin ******************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SalariedEmployee : public Employee {
	
	double weeklySalary;    //additional private member
	
public:
	SalariedEmployee(const string&, const string&, const string&, const Date&, double=0.0);

	//getter & setter
	void setWeeklySalary(double);
	double getWeeklySalary() const;
	
	//virtual functions inherited
	virtual double earnings() const;
	virtual void print() const;
};



SalariedEmployee::SalariedEmployee(	const string& first,
									const string& last,
									const string& ssn,
									const Date& birth,
									double salary)
									: Employee(first, last, ssn, birth)
{
	setWeeklySalary(salary);
}

		//getter & setter
void SalariedEmployee::setWeeklySalary(double salary) {
	if (salary >= 0.0) {
		weeklySalary = salary;
	} else {
		throw invalid_argument("Weekly salary must be >= 0.0");
	}
}
double SalariedEmployee::getWeeklySalary() const {
	return weeklySalary;
}


	//virtual functions inherited
double SalariedEmployee::earnings() const {
	return getWeeklySalary();
}
void SalariedEmployee::print() const {
	cout << "salaried employee: ";
	Employee::print();
	cout << "\nweekly salary: " << getWeeklySalary();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************** Class SalariedEmployee End ******************************************/







/*************************************** Class CommissionEmployee Begin ******************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CommissionEmployee : public Employee {
	
	double grossSales;
	double commissionRate;
	
public:
	CommissionEmployee(const string&, const string&, const string&, const Date&, double=0.0, double=0.0);
	
	//getter & setter
	void setCommissionRate(double);
	double getCommissionRate() const;
	
	void setGrossSales(double);
	double getGrossSales() const;
	
	//virtual functions inherited
	virtual double earnings() const;
	virtual void print() const;
};


CommissionEmployee::CommissionEmployee(	const string& first,
										const string& last,
										const string& ssn,
										const Date& birth,
										double sales,
										double rate)
										: Employee(first, last, ssn, birth)
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


	//virtual functions inherited
double CommissionEmployee::earnings() const {
	return getCommissionRate() * getGrossSales();
}
void CommissionEmployee::print() const {
	cout << "commission employee: ";
	Employee::print();
	cout << "\ngross sales: " << getGrossSales();
	cout << "; commission rate: " << getCommissionRate();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************** Class CommissionEmployee End ******************************************/







/*************************************** Class BasePlusCommissionEmployee Begin ******************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class BasePlusCommissionEmployee : public CommissionEmployee {
	
	double baseSalary;
	
public:
	BasePlusCommissionEmployee(const string&, const string&, const string&, const Date&, double=0.0, double=0.0, double=0.0);
	
	//getter & setter
	void setBaseSalary(double);
	double getBaseSalary() const;
	
	//virtual functions inherited
	virtual double earnings() const;
	virtual void print() const;
};



BasePlusCommissionEmployee::BasePlusCommissionEmployee(	const string& first,
														const string& last,
														const string& ssn,
														const Date& birth,
														double sales,
														double rate,
														double salary)
														: CommissionEmployee(first, last, ssn, birth, sales, rate)
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

	//virtual functions inherited
double BasePlusCommissionEmployee::earnings() const {
	return getBaseSalary() + CommissionEmployee::earnings();
}
void BasePlusCommissionEmployee::print() const {
	cout << "base-salaried ";
	CommissionEmployee::print();
	cout << "; base salary: " << getBaseSalary();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************** Class BasePlusCommissionEmployee End ******************************************/






bool isBirthMonth(const Date& today, const Employee* employee) {        //judge if the employee's birthday occurs in current month
	if (today.getMonth() == employee->getBirthDate().getMonth()) {
		return true;
	} else {
		return false;
	}
}


void printEarned(const Date& today, const Employee* employee) {     //print the employee's earning in this month
	double earned = employee->earnings();
	if (isBirthMonth(today, employee)) {
		cout << "HAPPY BIRTHDAY!" << endl;
		earned += 100;      //Bonus for birthday
	}
	cout << "earned $" << earned << endl;
}






int main() {
	
	cout << fixed << setprecision(2);
	vector<Employee*> employees(3);
	
	Date today, d1(4,29,1944), d2(5,16,1949), d3(8,17,1926);    //Random birthday
	
	//get current date
	time_t nowtime;
	struct tm* ptm;
	time(&nowtime);
	ptm = localtime(&nowtime);
	today.setDate(ptm->tm_mon+1, ptm->tm_mday, ptm->tm_year+1900);   //mon is 0-11, year is this year-1900
	
	
	employees[0] = new SalariedEmployee("John", "Smith", "111-11-1111", d1, 800);
	employees[1] = new CommissionEmployee("Sue", "Jones", "333-33-3333", d2, 10000, .06);
	employees[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", d3, 5000, .04, 300);
	
	cout << "Today is " << today << endl << endl;
	
		//output employees' earnings
	for (int i = 0; i < employees.size(); ++i) {
		employees[i]->print();
		cout << endl;
		printEarned(today, employees[i]);
		cout << endl;
	}
	
	
	/********************occasion in next month********************/
	
	cout << "**************************************************************" << endl;
	cout << "After a month: " << endl;
	cout << "**************************************************************" << endl;
	today += 30;
	cout << "Today is " << today << endl << endl;

		//output employees' earnings
	for (int i = 0; i < employees.size(); ++i) {
		employees[i]->print();
		cout << endl;
		printEarned(today, employees[i]);
		cout << endl;
	}
	
	
		//deleting object
	for (int i = 0; i < employees.size(); ++i) {
		cout << "deleting object of " << typeid(*employees[i]).name() << endl;
		delete employees[i];
	}
	
}
