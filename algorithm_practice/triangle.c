/* SIZE x SIZE의 매트릭스에서
   마지막 열이 전부 채워진 삼각형 그리기
*/

#include <stdio.h>
#define SIZE 51 // 홀수임을 가정 
void print_triangle() {

	int black_col = (SIZE / 2) + 1;
	int black_row_start = black_col;
	int black_row_end = black_row_start;

	for(int col = 1; col <= SIZE; col++) {
		for(int row = 1; row <= SIZE; row++) {
			
			if((col >= black_col) && (row >= black_row_start) && (row <= black_row_end))
				printf("1");
			else 
				printf("0");
		}

		printf("\n");

		if(col >= black_col) {
			black_row_start--;
			black_row_end++;
		}
	}
}

void main(){
	print_triangle();
}
	
