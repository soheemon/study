/* 
목적: SIZE x SIZE의 매트릭스에서
   SIZE수만큼 마지막 열이 *로 전부 채워진 삼각형 그리기

동작:
   1,1 2,1 3,1 4,1 5,1
   1,2 2,2 3,2 4,2 5,2
   1,3 2,3 3,3 4,3 5,3
   1,4 2,4 3,4 4,4 5,4
   1,5 2,5 3,5 4,5 5,5
   
   5 x 5 매트릭스가 있다고 할때
   맨 마지막줄에 다섯개의 별이 찍히려면
   첫번째 1,2열은 공백이 되어야 하고
   세번째 열부터 *을 찍기 시작해야 한다.
   
   이때 별을 찍기 시작할 줄을 blank_col이라고 하며 SIZE를 2로 나누어서 +1한값으로 계산한다.
   별을 찍을 세로줄을 black_col이라고 할때 가로줄을 black_row_start라고 하며 정 중앙에 찍혀야 하기 때문에 초기에는 같은값을 가진다.
   
   현재 컬럼의 상태(col)이 초기에 정한 black_col 이상이고, 가로줄이 별을 찍을 값의 범위안일때 *을 찍는다.
*/

#include <stdio.h>
#define SIZE 5 // 맨 마지막 줄에서 *의 갯수이다. 홀수임을 가정 
void print_triangle() {

	int black_col = (SIZE / 2) + 1; // SIZE가 5일때 3이된다.
	int black_row_start = black_col; // 공백과 별이 섞여서 출력되기 시작할(피라미드를 그리기 시작할) 가로줄
	int black_row_end = black_row_start; // 공백과 별이 섞여서 출력될 줄의 길이

	for(int col = 1; col <= SIZE; col++) { // 세로줄
		for(int row = 1; row <= SIZE; row++) { //가로줄
			
			if((col >= black_col) && (row >= black_row_start) && (row <= black_row_end))
				printf("*");
			else 
				printf(" ");
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
	
