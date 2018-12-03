//Employee.h
#include <string>
using namespace std;

class Employee
{
public:
	Employee(string, string, int);
	void setFirstName(string);
	void setLastName(string);
	void setSalary(int);
	string getFirstName();
	string getLastName();
	int getSalary();
private:
	string firstName_;
	string lastName_;
	int monthlySalary_;
};
//end Employee.h
