//tester.cpp
#include "Employee.h"
#include <iostream>
using namespace std;
void showYearlySalary(Employee);

int main() {
	Employee employee1{"John", "Smith", 50000};
	Employee employee2{ "Catherine", "Jobs", 40000 };
	showYearlySalary(employee1);
	showYearlySalary(employee2);
	employee1.setSalary( int(employee1.getSalary() * 1.1) );
	employee2.setSalary( int(employee2.getSalary() * 1.1) );
	cout << "After modifying: " << endl;
	showYearlySalary(employee1);
	showYearlySalary(employee2);
	system("pause");
}

void showYearlySalary(Employee employee) {
	cout << employee.getFirstName() << ' ' << employee.getLastName() << "'s yearly salary is " << employee.getSalary() * 12 << endl;
}
//end tester.cpp