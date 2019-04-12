#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
	double _real;
	double _imag;
public:
	Complex(double = 0.0, double = 0.0);
	
	
	//friend operator functions
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
	
	
	//overloaded operator functions
	Complex add(const Complex&) const;
	Complex subtract(const Complex&) const;
	Complex operator+(const Complex& c) const{
		return add(c);
	}
	Complex operator-(const Complex& c) const{
		return subtract(c);
	}
	Complex operator*(const Complex&) const;
	bool operator==(const Complex&) const;
	bool operator!=(const Complex&) const;
	
	
	//getter & setter
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



//getter & setter
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




//overloaded operator functions
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
