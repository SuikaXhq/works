#include <iostream>
#include "bubble_sort.h"
using namespace std;

int main() {
	int array[] = {5,6,3,2,1,9,7,8,4,0};
	bubble_sort(array, 10);
	for (int i = 0; i < 10; i++)cout<<array[i]<<' ';
	system("pause");
}
