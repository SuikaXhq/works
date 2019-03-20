#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String {
	friend ostream& operator<<(ostream&, const String&);
	friend String operator+(const String&, const String&);
	char* sPtr;
	int length;
public:
	String(const char* const = "");
	String(const String&);
	~String();
	const String& operator=(const String&);
};
#endif

String::String(const char* const s) {
	const char* temp = s;
	length = 0;
	while (*temp != '\0') {
		++temp;
		++length;
	}
	temp = 0;
	
	sPtr = new char[length+1];	//sPtr实际长度比length多1，即length表示字符数
	for (int i = 0; i < length+1; ++i) {
		sPtr[i] = s[i];
	}
}

String::String(const String& s) {
	length = s.length;
	sPtr = new char[length+1];
	for (int i = 0; i < length+1; ++i) {
		sPtr[i] = s.sPtr[i];
	}
}

String::~String() {
	delete sPtr;
	sPtr = 0;
}

const String& String::operator=(const String& s) {
	if (this == &s) {
		return *this;
	}

	if (s.length == length) {
		for (int i = 0; i < length+1; ++i) {
			sPtr[i] = s.sPtr[i];
		}
	} else {
		length = s.length;
		delete sPtr;
		sPtr = new char[length+1];
		for (int i = 0; i < length+1; ++i) {
			sPtr[i] = s.sPtr[i];
		}
	}

	return *this;
}

ostream& operator<<(ostream& output, const String& s) {
	output << s.sPtr;
	return output;
}

String operator+(const String& s1, const String& s2) {
	char* newString = new char[s1.length + s2.length + 1];
	for (int i = 0; i < s1.length; ++i) {
		newString[i] = s1.sPtr[i];
	}
	for (int i = 0; i < s2.length+1; ++i) {
		newString[s1.length + i] = s2.sPtr[i];
	}

	return String(newString);
}

int main() {
	String s1, s2("Today is");
	String s3(" 2019/3/20");
	cout << "string2 = " << s2 << endl;
	cout << "string3 = " << s3 << endl;

	s1 = s2 + s3;
	cout << "string1 = string2 + string3" << endl;
	cout <<	"string1 = " << s1 << endl;
	system("pause");
}