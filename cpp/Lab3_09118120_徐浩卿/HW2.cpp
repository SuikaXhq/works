#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial {
	double a[10];   //ax^n
public:
	Polynomial();
	Polynomial(double[], int);
	~Polynomial();
	const Polynomial& operator=(const Polynomial&);
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	friend ostream& operator<<(ostream&, const Polynomial&);
	void setCoefficient(int, double);
	double getCoefficient(int);
};
#endif

Polynomial::Polynomial() {
	for (int i = 0; i < 10; ++i) {
		a[i] = 0;
	}
}
Polynomial::Polynomial(double co[], int size) {
	for (int i = 0; i < 10; ++i) {
		a[i] = 0;
	}
	if (size <= 10) {
		for (int i = 0; i < size; ++i) {
			a[i] = co[i];
		}
	}
}
Polynomial::~Polynomial() {}

const Polynomial& Polynomial::operator=(const Polynomial& p) {
	for (int i = 0; i < 10; ++i) {
		a[i] = p.a[i];
	}
	return *this;
}
Polynomial Polynomial::operator+(const Polynomial& p) {
	double co[10] = {};
	for (int i = 0; i < 10; ++i) {
		co[i] = a[i] + p.a[i];
	}
	return Polynomial(co, 10);
}
Polynomial Polynomial::operator-(const Polynomial& p) {
	double co[10] = {};
	for (int i = 0; i < 10; ++i) {
		co[i] = a[i] - p.a[i];
	}
	return Polynomial(co, 10);
}
Polynomial& Polynomial::operator+=(const Polynomial& p) {
	for (int i = 0; i < 10; ++i) {
		a[i] += p.a[i];
	}
	return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& p) {
	for (int i = 0; i < 10; ++i) {
		a[i] -= p.a[i];
	}
	return *this;
}
void Polynomial::setCoefficient(int n, double value) {
	a[n] = value;
}
double Polynomial::getCoefficient(int n) {
	return a[n];
}

ostream& operator<<(ostream& output, const Polynomial& p) {
	int counter = 0;    //记录总项数
	int index = 0;
	for (int i = 0; i < 10; ++i) {
		if (p.a[i] != 0) {
			++counter;
			index = i;
		}
	}
	
	if (counter == 0) {
		output << 0;
		return output;
	}
	
	//输出第一项
	if (p.a[index] - 1 <= 0.00001 && p.a[index] - 1 >= -0.00001) {
		output << "x^" << index;
	} else if (p.a[index] + 1 <= 0.00001 && p.a[index] + 1 >= -0.00001) {
		output << "-x^" << index;
	} else {
		output << p.a[index] << "x^" << index;
	}
	
	//输出后续项
	for (int i = index-1; i > 1; --i) {
		
		if (p.a[i] > 0) {
			if (p.a[i] - 1 <= 0.00001 && p.a[i] - 1 >= -0.00001) {
				output << "+" << "x^" << i;
			} else {
				output << "+" << p.a[i] << "x^" << i;
			}
		}
		
		if (p.a[i] < 0) {
			if (p.a[i] + 1 <= 0.00001 && p.a[i] + 1 >= -0.00001) {
				output << "-" << "x^" << i;
			} else {
				output << p.a[i] << "x^" << i;
			}
		}
	}
	
	//常数项和一次项
	if (p.a[1] > 0) {
		output << "+" << p.a[1] << "x";
	}
	if (p.a[1] < 0) {
		output << p.a[1] << "x";
	}
	if (p.a[0] > 0) {
		output << "+" << p.a[0];
	}
	if (p.a[0] < 0) {
		output << p.a[0];
	}
	
	return output;
}

int main() {
	double co1[3] = {1, -2, 1};
	double co2[4] = {0.5, 2.1, 1.9, 1};
	Polynomial p1(co1, 3);
	Polynomial p2;
	Polynomial p3(co2, 4);
	
	cout << "p1 is " << p1 << "\np2 is " << p2 << "\np3 is " << p3 << endl;
	cout << "p1 + p3 = " << p1+p3 << endl;
	cout << "p1 - p3 = " << p1-p3 << endl;
	cout << "p2 -= p1" << endl;
	p2 -= p1;
	cout << "p2 += p3" << endl;
	p2 += p3;
	cout << "p1 = p2" << endl;
	p1 = p2;
	cout << "p1 is now " << p1 << endl;
}
