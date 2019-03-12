#include <iostream>
#include "9.14_HugeInteger.h"
using namespace std;

int main() {
	HugeInteger int1("123456789123");
	HugeInteger int2;
	int2.input("456789123456");
	HugeInteger int3;
	
	int1.output();
	cout << " + ";
	int2.output();
	cout << " = ";
	int1.add(int2).output();
	cout << endl;
	
	int1.output();
	cout << " - 15 = ";
	int1.subtract(15).output();
	cout << endl;

	int1.output();
	cout << " is " << (int1.isEqualTo(int2) ? "equal to " : "not equal to ");
	int2.output();
	cout << endl;
	
	int1.output();
	cout << " is " << (int1.isEqualTo(int1) ? "equal to " : "not equal to ");
	int1.output();
	cout << endl;
	
	int1.output();
	cout << " is " << (int1.isGreaterThan(int3) ? "greater than " : "less than or equal to ");
	int3.output();
	cout << endl;
	
	int3.output();
	cout << " is " << (int3.isLessThan(int2) ? "less than " : "greater than or equal to ");
	int2.output();
	cout << endl;
	
	int3.output();
	cout << " is " << (int3.isLessThanOrEqualTo(int3) ? "less than or equal to " : "greater than ");
	int3.output();
	cout << endl;
	
	int1.output();
	cout << " is " << (int1.isGreaterThanOrEqualTo(int2) ? "greater than or equal to " : "less than ");
	int2.output();
	cout << endl;
	
	system("pause");
}
