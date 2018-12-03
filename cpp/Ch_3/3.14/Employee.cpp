//Employee.cpp
#include "Employee.h"
using namespace std;

Employee::Employee(string firstName, string lastName, int salary) {
	setFirstName(firstName);
	setLastName(lastName);
	setSalary(salary);
}

void Employee::setFirstName(string firstName) {
	firstName_ = firstName;
}
void Employee::setLastName(string lastName) {
	lastName_ = lastName;
}
void Employee::setSalary(int salary) {
	if (salary >= 0)
		monthlySalary_ = salary;
	else
		monthlySalary_ = 0;
}

string Employee::getFirstName() {
	return firstName_;
}
string Employee::getLastName() {
	return lastName_;
}
int Employee::getSalary() {
	return monthlySalary_;
}
//end Employee.cpp