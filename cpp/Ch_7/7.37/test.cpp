#include<iostream>
using namespace std;
int* recursiveMinimum(int[], int, int);

const int arrSize = 10;

int main() {
	int arr[arrSize] = { 16,20,8,45,63,12,89,48,76,32 };
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << ' ';
	cout << endl;
	cout << "The minimum is " << *recursiveMinimum(arr, 0, arrSize - 1) << endl;
	system("pause");
}

int* recursiveMinimum(int arr[], int start, int end) {
	if (start == end)
		return &arr[start];

	if (arr[start] >= arr[end])
		return recursiveMinimum(arr, start + 1, end);
	else
		return recursiveMinimum(arr, start, end - 1);
}