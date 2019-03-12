#include <iostream>
#include "9.5_Complex.h"
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

void Complex::print() const {
	std::cout << '(' << getRealPart() << ", " << getImaginaryPart() << ')';
}
