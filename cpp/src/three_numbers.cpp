#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	int c;
	int max;
	int min;
	cout << "Input three different integers: ";
	cin >> a >> b >> c;
	if (a > b) {
		max = a;
		min = b;
	} else {
		max = b;
		min = a;
	}
	if (max < c)
		max = c;
	if (min > c)
		min = c;
	cout << "Sum is " << a + b + c;
	cout << "\nAverage is " << (a + b + c) / 3.0;
	cout << "\nProduct is " << a * b * c;
	cout << "\nSmallest is " << min;
	cout << "\nLargest is " << max << "\n";
	return 0;
}