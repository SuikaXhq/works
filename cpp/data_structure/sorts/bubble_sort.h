/*
 * bubble_sort.h
 */
 #ifndef BUBBLE_SORT_H
 #define BUBBLE_SORT_H
 
int* bubble_sort(int* array, int n) {
	//复杂度O(n^2)
	for (int i = n-1; i > 0; i--) {
		int count = 0;  //标记交换数, O(1)
		
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j+1]) {    //O(1)
                count++;
                
                int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;  //O(4)
			}
		}
		
		if (0 == count)break;	//O(1)
	}
	
	return array;   //O(1)
}

#endif
