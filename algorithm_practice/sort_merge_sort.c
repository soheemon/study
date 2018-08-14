/*
   분할: 해결하고자 하는 문제를 작은 크기의 동일한 문제들로 분할
   정복: 각각의 작은 문제를 순환적으로 해결
   합병: 작은 문제의 해를 합하여(merge) 원래 문제에 대한 해를 구함

   divide-and-conquer-approach
   
   분할(Divide): n keys를 두개의 n/2 keys로 나눈다.
   정복(Conquer): 합병정렬을 사용하여 두 개의 배열을 정렬한다.
   합병(Combine): 두 개의 정렬된 배열을 하나로 합치는 과정.
*/

#include <stdio.h>

void merge(int* array, int left, int mid, int right) {
	int tmp_array[100] = {0};

	int list_1 = left;
	int list_2 = mid + 1;
	int tmp_arr_index = left;


	int list_1_end = mid;
	int list_2_end = right;

	while(1){

		if(list_1 > list_1_end || list_2 > list_2_end) { // 어느 한쪽이 비어진다면 
			break;
		}

		if(array[list_1] <= array[list_2]) {
			tmp_array[tmp_arr_index] = array[list_1];
			list_1++;
		}else {
			tmp_array[tmp_arr_index] = array[list_2];
			list_2++;
		}

		tmp_arr_index++;

	}

	if(list_1 > list_1_end) {
		for(int spare_val_index = list_2; spare_val_index <= list_2_end; spare_val_index++, tmp_arr_index++)
			tmp_array[tmp_arr_index] = array[spare_val_index];
	}else {
		for(int spare_val_index = list_1; spare_val_index <= list_1_end; spare_val_index++, tmp_arr_index++)
			tmp_array[tmp_arr_index] = array[spare_val_index];
	}

	for(int list_index = left; list_index <= list_2_end; list_index++) {
		array[list_index] = tmp_array[list_index];
	}

}

void merge_sort(int* array, int start, int end) {

	/* base에 해당함 
	   end가 0이 되기 전까지 분할 */

	int mid = 0;
	if(start < end) { //키가 하나가 될 때 까지 분할
		mid = (start + end) / 2;
		merge_sort(array, start, mid);
		merge_sort(array, mid + 1, end);
		merge(array, start, mid, end);
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

	int not_sorted[100] = {2, 30, 1, 44, 4343, 2, 43, 5, 6, 7, 8, 6, 5, 1, 1, 1}; 
	int array_size = array_size_chk(not_sorted);
	merge_sort(not_sorted, 0, (array_size - 1));
	array_print(not_sorted);

}
