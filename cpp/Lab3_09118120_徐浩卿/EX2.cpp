#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
using namespace std;

class HugeInt {
	friend ostream& operator<<(ostream&, const HugeInt&);
	short data[30];
	HugeInt(short[]);   //为operator+创建的构造函数
public:
	HugeInt(long = 0);
	HugeInt(const char*);
	int compareTo(const HugeInt&) const;
	friend HugeInt operator+(const HugeInt&, const HugeInt&);
	friend bool operator==(const HugeInt&, const HugeInt&);
	friend bool operator!=(const HugeInt&, const HugeInt&);
	friend bool operator>(const HugeInt&, const HugeInt&);
	friend bool operator<(const HugeInt&, const HugeInt&);
	friend bool operator>=(const HugeInt&, const HugeInt&);
	friend bool operator<=(const HugeInt&, const HugeInt&);
	int getLength() const;
};
#endif

HugeInt::HugeInt(long n) {
	int index = 0;
	while (n != 0) {
		data[index] = n % 10;
		n /= 10;
		++index;
	}

	for (; index < 30; ++index) {   //补齐数组
		data[index] = 0;
	}
}

HugeInt::HugeInt(const char* n) {
	int length = 0;
	int index = 0;
	while (n[length] != '\0')++length;
	if (length <= 30) {
		for (; index < length; ++index) {
			data[index] = n[length-1-index] - 48;
		}
	}
	for (; index < 30; ++index) {   //补齐数组
		data[index] = 0;
	}
}

HugeInt::HugeInt(short n[]) {
	for (int i = 0; i < 30; ++i) {
		data[i] = n[i];
 	}
}

int HugeInt::getLength() const {
	int index = 29;
	while (index >= 0 && data[index] == 0) {
		--index;
	}
	return index+1;
}

int HugeInt::compareTo(const HugeInt& n) const{
	for (int i = 29; i >= 0; --i) {
		if (data[i] > n.data[i]) {
			return 1;
		}
		if (data[i] < n.data[i]) {
			return -1;
		}
	}
	return 0;
}

ostream& operator<<(ostream& output, const HugeInt& n) {
	int index = 29;
	while (index >= 0 && n.data[index] == 0)--index;
	if (index == -1) {
		output << 0;
		return output;
	}
	for (; index >= 0; --index) {
		output << n.data[index];
	}
	return output;
}
HugeInt operator+(const HugeInt& n1, const HugeInt& n2){
	short newInt[30] = {};
	bool carry = false; //进位标记
	for (int i = 0; i < 30; ++i) {
		newInt[i] = n1.data[i] + n2.data[i] + (carry ? 1 : 0);
		carry = false;
		
		if (newInt[i] >= 10) {
			carry = true;
			newInt[i] -= 10;
		}
	}
	return HugeInt(newInt);
}

bool operator==(const HugeInt& n1, const HugeInt& n2) {
	return (n1.compareTo(n2) == 0);
}
bool operator!=(const HugeInt& n1, const HugeInt& n2) {
	return (n1.compareTo(n2) != 0);
}
bool operator>(const HugeInt& n1, const HugeInt& n2) {
	return (n1.compareTo(n2) == 1);
}
bool operator<(const HugeInt& n1, const HugeInt& n2) {
	return (n1.compareTo(n2) == -1);
}
bool operator>=(const HugeInt& n1, const HugeInt& n2) {
	return (n1.compareTo(n2) != -1);
}
bool operator<=(const HugeInt& n1, const HugeInt& n2) {
	return (n1.compareTo(n2) != 1);
}

int main() {
	HugeInt n1(135091);
	HugeInt n2(340190);
	HugeInt n3("99999999999999999999999999999");
	HugeInt n4("1");
	HugeInt result;
	
	cout << result;
	cout << "n1 is " << n1 << "\nn2 is " << n2 << "\nn3 is " << n3 << "\nn4 is " << n4 << "\nresult is " << result << endl;
	if (n1 == n2)cout << "n1 == n2" << endl;
	if (n1 != n2)cout << "n1 != n2" << endl;
	if (n1 < n2)cout << "n1 < n2" << endl;
	if (n1 <= n2)cout << "n1 <= n2" << endl;
	if (n1 > n2)cout << "n1 > n2" << endl;
	if (n1 >= n2)cout << "n1 >= n2" << endl;
	result = n1 + n2;
	cout << n1 << " + " << n2 << " = " << result << endl;
	cout << n3 << " + " << n4 << " = " << (n3+n4) << endl;
	result = n1 + 9;
	cout << n1 << " + 9 = " << result << endl;
	result = n2 + "10000";
	cout << n2 << " + 10000 = " << result << endl;
}
