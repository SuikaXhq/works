#include <iostream>
#include "Complex.h"
using namespace std;


template <class T>
bool isEqualTo(const T& a, const T& b) {
	return a==b;
}

int main() {
	
	int x=3, y=4, z=3;
	cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;
	cout << "x " << (isEqualTo(x,y) ? "==" : "!=") << " y" << endl;
	cout << "x " << (isEqualTo(x,z) ? "==" : "!=") << " z" << endl;
	
	cout << endl;
	
	Complex i(1.2, -0.3), j(2.3, 0.2), k(1.2, -0.3);
	cout << "i = " << i << "\nj = " << j << "\nk = " << k << endl;
	cout << "i " << (isEqualTo(i,j) ? "==" : "!=") << " j" << endl;
	cout << "i " << (isEqualTo(i,k) ? "==" : "!=") << " k" << endl;
}
