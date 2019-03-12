#ifndef COMPLEX_H
#define COMPLEX_H
class Complex {
	double _real;
	double _imag;
public:
	Complex(double = 0.0, double = 0.0);
	Complex add(const Complex&) const;
	Complex subtract(const Complex&) const;
	void print() const;
	double getRealPart() const;
	double getImaginaryPart() const;
	void setRealPart(double);
	void setImaginaryPart(double);
};
#endif
