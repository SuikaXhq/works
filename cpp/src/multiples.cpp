#include <iostream>
using namespace std;

int main()
{
	int a;
	int b;
	cin >> a >> b;
	if (a % b ==0)
		cout << a << " is a multiple of " << b << ".\n";
	else
		cout << a << " is not a multiple of " << b << ".\n";
	return 0;
}
