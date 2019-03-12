#include <iostream>
#include "9.5_Complex.h"
using namespace std;

int main() {
	Complex c1(5, 2.1);
	Complex c2(1.8, -10.5);
	
	//Adding
	c1.print();
	cout << " + ";
	c2.print();
	cout << " = ";
	c1.add(c2).print();
	
	//Subtracting
	cout << endl;
	c1.print();
	cout << " - ";
	c2.print();
	cout << " = ";
	c1.subtract(c2).print();
	
	system("pause");
}
