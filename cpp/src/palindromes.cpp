#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a;
	while (cin >> a) {
		int temp = a;
		while (temp / 10 != 0)
		{
			b *= 10;
			b += temp % 10;
			temp /= 10;
		}
	}
}
