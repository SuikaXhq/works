#include <iostream>
#include <ctime>
using namespace std;

void quick_sort(int*, int, int);


int main() {
	int a[] = {6,8,7,9,4,0,1,2,5,3};
	quick_sort(a, 0, 9);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << ", ";
	}
}


void quick_sort(int* arr, int start, int end) {
	if (start < end) {
		
		// get pivot
		srand(time(0));
		int pivot_index = start + rand() % (end - start + 1);
		int pivot = arr[pivot_index];
		arr[pivot_index] = arr[end];    // move the pivot element to the end
		
		// partitial sort
		int left=start, right=end;
		while (left < right) {
			while (left < right && arr[left] <= pivot)++left;
			arr[right] = arr[left];
			while (left < right && arr[right] >= pivot)--right;
			arr[left] = arr[right];
		}
		arr[left] = pivot;  // left == right
		
		quick_sort(arr, start, left-1);
		quick_sort(arr, left+1, end);
		
	}
}
