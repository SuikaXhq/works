// Ex. 7.21: Ex07_21.cpp
// What does this program do?
#include <iostream>
using namespace std;

void someFunction(int[], int, int);

int main()
{
	const int arraySize = 10;
	int a[arraySize] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "The values in the array are:" << endl;
	someFunction(a, 0, arraySize);
	cout << endl;
}

//What does this function do?
void someFunction(int b[], int current, int size)
{
	if (current < size)
	{
		someFunction(b, current + 1, size);
		cout << b[current] << "  ";
	}
}