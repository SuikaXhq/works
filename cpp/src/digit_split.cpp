#include <iostream>
using namespace std;

int main()
{
	int input;
	int temp[5];
	while (cin >> input)
	{
		for (int i = 4;i >= 0;i--) {
			temp[i] = input % 10;
			input /= 10;
		}
		for (int i:temp)
			cout << i << "   ";
		cout << "\n";
	}
	return 0;
}