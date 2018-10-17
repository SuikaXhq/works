#include<iostream>

using namespace std;

int main()
{
	long a=0L;
	long b=0L;
	long c=0L;

	cout << "Enter an integer: ";
	cin >> a;
	c = a;
	cout << c << " "<<a;
 
	while(c>0)
	{
		b = b * 10 + c % 10;
		c = c / 10;
	}
	if (a == b)
		cout << "是回文数。" << endl;
	else
		cout << "不是回文数。" << endl;
	system("pause");
}