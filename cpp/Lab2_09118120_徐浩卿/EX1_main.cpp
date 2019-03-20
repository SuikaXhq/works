#include <iostream>
#include "EX1_SimpleCalculator.h"
using namespace std;

int main() {
	double a = 10.0;
	double b = 20.0;
	SimpleCalculator sc;
	cout << "The value of a is " << a << endl;
	cout << "The value of b is " << b << endl;
	double addition = sc.add(a, b);
	cout << "Adding a and b yields " << addition << endl;
	double subtraction = sc.subtract(a, b);
	cout << "Subtracting b from a yields " << subtraction << endl;
	double multiplication = sc.multiply(a, b);
	cout << "Multiplying a by b yields " << multiplication << endl;
	double division = sc.divide(a, b);
	cout << "Dividing a by b yields " << division << endl;
}
