#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
	double _real;
	double _imag;
public:
	Complex(double = 0.0, double = 0.0);
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
	Complex operator*(const Complex&) const;
	Complex operator+(const Complex& c) const{
		return add(c);
	}
	Complex operator-(const Complex& c) const{
		return subtract(c);
	}
	bool operator==(const Complex&) const;
	bool operator!=(const Complex&) const;
	Complex add(const Complex&) const;
	Complex subtract(const Complex&) const;
	double getRealPart() const;
	double getImaginaryPart() const;
	void setRealPart(double);
	void setImaginaryPart(double);
};
#endif

Complex::Complex(double real, double imag) {
	setRealPart(real);
	setImaginaryPart(imag);
}

void Complex::setRealPart(double newReal) {
	_real = newReal;
}
void Complex::setImaginaryPart(double newImag) {
	_imag = newImag;
}
double Complex::getRealPart() const {
	return _real;
}
double Complex::getImaginaryPart() const {
	return _imag;
}

Complex Complex::add(const Complex& c) const{
	return Complex( getRealPart() + c.getRealPart(),
					getImaginaryPart() + c.getImaginaryPart());
}
Complex Complex::subtract(const Complex& c) const{
	return Complex( getRealPart() - c.getRealPart(),
					getImaginaryPart() - c.getImaginaryPart());
}
Complex Complex::operator*(const Complex& c) const{
	double real = _real*c._real - _imag*c._imag;
	double imag = _real*c._imag + _imag*c._real;
	return Complex(real, imag);
}
bool Complex::operator==(const Complex& c) const{
	static const double EPSILON = 0.00001;
	if (_real - c._real <= EPSILON && _real - c._real >= -EPSILON && _imag - c._imag <= EPSILON && _imag - c._imag >= -EPSILON) {
		return true;
	} else {
		return false;
	}
}
bool Complex::operator!=(const Complex& c) const{
	return !(*this == c);
}
ostream& operator<<(ostream& output, const Complex& c){
	output << '(' << c._real << ", " << c._imag << ')';
	return output;
}
istream& operator>>(istream& input, Complex& c) {
	cout << "Type in a complex number(in the form of \"(real, imaginary)\"): ";
	input.ignore();
	input >> c._real;
	input.ignore(2);
	input >> c._imag;
	input.ignore();
	return input;
}

int main() {
	Complex c1(5, 2.1);
	Complex c2(5, 2.1);
	Complex c3;
	
	cin >> c3;

	cout << "c1 is " << c1 << "\nc2 is " << c2 << "\nc3 is " << c3 << endl;

	//Adding
	cout << c1 <<  " + " << c2 << " = " << c1+c2 << endl;

	//Subtracting
	cout << c1 <<  " - " << c2 << " = " << c1-c2 << endl;
	
	cout << c1 << " * " << c3 << " = " << c1*c3 << endl;
	
	if (c1 == c2) {
		cout << "c1 == c2" << endl;
	}
	if (c1 != c3) {
		cout << "c1 != c3" << endl;
	}
}
