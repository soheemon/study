/* 상태공간 트리란
   찾는 해를 포함하는 트리.

   해가 존재한다면
   그것은 반드시 트리안에 어떤 한 노드에 해당한다.
   따라서 트리를 체계적으로 탐색한다면, 해를 구할 수 있다.

   설명:
   N x N 배열에서 직선상, 대각선상에 겹치지 않도록
   N개의 말을 놓는다
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* N x N 배열 */
#define N 10 

/* index는 각 열을 의미. data는 행을 의미. */
static uint32_t queen_node[N + 1] = {0};

bool promising(uint32_t column) {

	uint32_t col_val = 0;
	int row_val = 0;

	for(int cols = 1; cols < column; cols++) {
		/* 같은 열에 놓았는지 검사 */
		if (queen_node[cols] == queen_node[column])
			return false;

		/* 이전 말과 대각선상에 놓였는지 검사 */

		col_val = column - cols;
		row_val = queen_node[column] - queen_node[cols];
		row_val = row_val < 0 ? (row_val * -1) : row_val;

		if(col_val == row_val)
			return false;
	}

	return true;
}

void print_queen_node() {

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(j == queen_node[i])
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}

bool queens(uint32_t column) {

	/* 놓은 말이 충돌하는지 안하는지 확인*/
		if (promising(column) == false)
		return false;

	/* 종료조건을 만족했을때 출력하고 return true*/
	if(column == N) {
		print_queen_node();
		return true;
	}

	for (int row = 1; row <= N; row++) {
		/* column, row 번째에 말을 놓는다.*/
		/* 즉, 입력받은 column은 고정하고, row만 이동 */
		queen_node[column + 1] = row;

		/* 다음 행으로 recursion 호출 */
		if (queens(column + 1) == true)
			return true;
	}
	/* N개의 열에 시도해봤지만, 적절한것을 찾지 못했을때 */
		return false;
}

void main(void) {
	queens(0);
}
