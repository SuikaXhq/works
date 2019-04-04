#include <iostream>
using namespace std;

class A {
//	int x;
public:
	A() {
		cout << "A 0" << endl;
	}
	void a() {
		cout << 'a' << endl;
	}
	~A() {
		cout << "A 1" << endl;
	}
};

class B {
public:
	B() {
		cout << "B 0" << endl;
	}
	~B() {
		cout << "B 1" << endl;
	}
};

class AA : public A {
	B b;
public:
	AA() {
		cout << "AA 0" << endl;
	}
	void aa() {
		cout << "aa" << endl;
	}
	~AA() {
		cout << "AA 1" << endl;
	}
};

int main() {
	AA aa;
	A a;
	aa.aa();
	aa.a();
	a=aa;
	a.aa();
}
