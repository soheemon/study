/*
   Quick sort

   가장 우측의 값을 pivot값으로 지정해서
   왼쪽을 pivot보다 작은값, 오른쪽을 큰값으로 분할하여 정렬한다.
*/

#include <stdio.h>
void swap_val(int* value1, int* value2) {
	int tmp;
	tmp = *value1;
	*value1 = *value2;
	*value2 = tmp;
}

int partition(int* array, int first, int last) {
	int small_than_pivot_lst_idx = first - 1;
	int pivot = array[last];

	for(int chk_val_ptr = first; chk_val_ptr < last; chk_val_ptr++) {
		// pivot보다 작은 값이면 그값을 앞으로 옮긴다.

		if(array[chk_val_ptr] < pivot) { 		
			small_than_pivot_lst_idx++;
			swap_val(&array[small_than_pivot_lst_idx], &array[chk_val_ptr]);
		}
	}

	swap_val(array + (small_than_pivot_lst_idx + 1), array + last/*pivot*/);
	return small_than_pivot_lst_idx + 1;
}
void quick_sort(int* array, int first, int last) {

	if(first >= last)
		return ;

	else {
		int q = partition(array, first, last);
		quick_sort(array, first, q - 1); // 왼쪽부분 정렬
		quick_sort(array, q + 1, last); //오른쪽 부분 정렬
	}

}

void array_print(int* array) {
	int* index = array;

	while(*index != '\0') {
		printf("%d\n", *index);
		index++;
	}
	
}

int array_size_chk(int* array) {
	int* index = array;
	int size = 0;

	while(*index != '\0') {
		size++;
		index++;
	}

	return size;
}
void main(void) {
	int array[100] = {1, 100, 20, 30, 40, 50, 2, 3, 1, 333, 4};
	int array_size = array_size_chk(array);
	quick_sort(array, 0, (array_size - 1));
	array_print(array);
}
