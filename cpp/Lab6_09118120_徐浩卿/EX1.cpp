#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



template <class T>
void quickSort(T* arr, int start, int end) {    // arr : The array to be sorted,
												// start : The start index of the part to be sorted,
												// end : The end index of the part to be sorted
	if (start >= end)return;     // end condition
	
	srand(time(0));
	int r = start + rand() % (end - start + 1);     //select a random pivot
	T pivot = arr[r];
	arr[r] = arr[start];

	int left = start;   // left cursor index
	int right = end;    // right cursor index
	
	while (left < right) {
		
		while (left < right && arr[right] >= pivot)--right;
		arr[left] = arr[right];
		while (left < right && arr[left] <= pivot)++left;
		arr[right] = arr[left];

	}
	
	arr[left] = pivot;
	
	quickSort(arr, start, left-1);
	quickSort(arr, right+1, end);
	
}


template <class T>
void printArray(T* arr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
}

int main() {
	
	const int SIZE = 8; // size of array
	
	int a[ SIZE ] = { 6, 5, 3, 2, 1, 7, 8, 4 };
	
	// display int array in original order
	cout << "int data elements in original order\n";
    printArray( a, SIZE ); // print int array
    
    quickSort( a, 0, SIZE-1 ); // sort int array
    
	// display int array in sorted order
    cout << "\nint data elements in ascending order\n";
    printArray( a, SIZE );
	cout << "\n\n";
	
	// initialize float array
	float b[ SIZE ] = { 12.3, 77.2, 36.9, 28.4, 9.7, 50.5, 21.9, 43.6 };
	
	// display float array in original order
	cout << "float point data elements in original order\n";
	printArray( b, SIZE ); // print float array
	
	quickSort( b, 0, SIZE-1 ); // sort float array
	
	// display sorted float array
	cout << "\nfloat point data elements in ascending order\n";
	printArray( b, SIZE );
	cout << endl;
	
}
