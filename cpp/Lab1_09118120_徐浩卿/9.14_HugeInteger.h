#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
class HugeInteger {
	int integer[40];
	int compareTo(HugeInteger&);
public:
	HugeInteger(int = 0);
	HugeInteger(const char*);
	
	HugeInteger add(const HugeInteger&);
	HugeInteger add(int);
	HugeInteger add(const char*);
	HugeInteger subtract(const HugeInteger&);
	HugeInteger subtract(int);
	HugeInteger subtract(const char*);
	
	bool isEqualTo(HugeInteger&);
	bool isNotEqualTo(HugeInteger&);
	bool isGreaterThan(HugeInteger&);
	bool isLessThan(HugeInteger&);
	bool isGreaterThanOrEqualTo(HugeInteger&);
	bool isLessThanOrEqualTo(HugeInteger&);
	bool isZero();
	
	void input(const char*);
	void output();
};
#endif
