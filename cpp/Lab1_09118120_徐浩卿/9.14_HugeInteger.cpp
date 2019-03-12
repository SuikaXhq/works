#include <iostream>
#include "9.14_HugeInteger.h"
#include <cstring>
#include <cstdlib>
using namespace std;

HugeInteger::HugeInteger(int data) {
	for (int i = 0; i < 40; i++)integer[i] = 0;
	int digit = 0;
	while (data != 0) {	//integer[0]为个位
		integer[digit] = data % 10;
		data /= 10;
		digit++;
	}
}
HugeInteger::HugeInteger(const char* data) {
	for (int i = 0; i < 40; i++)integer[i] = 0;
	input(data);
}
HugeInteger HugeInteger::add(const HugeInteger& hi) {	//hi = "huge integer"
	bool carry = false; //进位标记
	for (int i = 0; i < 40; i++) {
		integer[i] += hi.integer[i] + (carry ? 1 : 0);
		carry = false;
		if (integer[i] > 9) {
			carry = true;
			integer[i] -= 10;
		}
	}
	return *this;
}
HugeInteger HugeInteger::add(int i) {
	return add(HugeInteger(i));
}
HugeInteger HugeInteger::add(const char* c) {
	return add(HugeInteger(c));
}
HugeInteger HugeInteger::subtract(const HugeInteger& hi) {
	bool carry = false; //退位标记
	for (int i = 0; i < 40; i++) {
  	integer[i] -= hi.integer[i] + (carry ? 1 : 0);
		carry = false;
		if (integer[i] < 0) {
			carry = true;
			integer[i] += 10;
		}
	}
	return *this;
}
HugeInteger HugeInteger::subtract(int i) {
	return subtract(HugeInteger(i));
}
HugeInteger HugeInteger::subtract(const char* c) {
	return subtract(HugeInteger(c));
}

int HugeInteger::compareTo(HugeInteger& hi) {
	int *p1 = &integer[39];
	int *p2 = &hi.integer[39];
	for (int i = 0; i < 40; i++) {
		if (*p1 < *p2) {
			return -1;  //-1表示小于
		}
		if (*p1 > *p2) {
			return 1;   //1表示大于
		}
		p1--;
		p2--;
	}
	return 0;   //0表示等于
}
bool HugeInteger::isEqualTo(HugeInteger& hi) {
	return !compareTo(hi);
}
bool HugeInteger::isNotEqualTo(HugeInteger& hi) {
	return compareTo(hi);
}
bool HugeInteger::isGreaterThan(HugeInteger& hi) {
	return (compareTo(hi) == 1 ? true : false);
}
bool HugeInteger::isLessThan(HugeInteger& hi) {
	return (compareTo(hi) == -1 ? true : false);
}
bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger& hi) {
	return !isLessThan(hi);
}
bool HugeInteger::isLessThanOrEqualTo(HugeInteger& hi) {
	return !isGreaterThan(hi);
}
bool HugeInteger::isZero() {
	for (int i = 0; i < 40; i++) {
		if (integer[i] != 0) {
			return false;
		}
	}
	return true;
}
void HugeInteger::input(const char* data) {
	int digit = strlen(data);
	for (int i = 0; i < digit; i++) {
		integer[i] = data[digit - 1 - i] - 48;	//char -> int 
	}
}
void HugeInteger::output() {
	if (isZero()) {
		cout << 0;
		return;
	}
	int index = 39;
	while (integer[index] == 0)index--;
	for (; index + 1; cout << integer[index], index--);
}
