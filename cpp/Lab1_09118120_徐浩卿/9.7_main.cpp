#include <iostream>
#include "9.7_Time.h"
using namespace std;

int main() {
	Time time1(23,59,58);
	for (int i = 0; i < 10; i++) {
		time1.printStandard();
		cout << endl;
		tick(time1);
	}
	cout << endl;
	Time time2(22,0,58);
	for (int i = 0; i < 10; i++) {
		time2.printStandard();
		cout << endl;
		tick(time2);
	}
	system("pause");
}
