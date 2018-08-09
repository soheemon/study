#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
   UNIDENTIFIED_CELL = 아직 한번도 가지않은 cell
   WALL = 벽
   NOT_EXIT_PATH = 탐색 후 출구까지 가는 경로가 아닌 cell
   VISITED_CELL = 탐색중인 cell. 한번 거쳤다
*/

#define UNIDENTIFIED_CELL 0 
#define WALL 1
#define NOT_EXIT_PATH 2
#define PATH 3

static uint32_t maze_size = 8;
static uint32_t maze_map[8][8] = {
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 1, 1, 0, 1, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 1},
		{0, 1, 0, 0, 1, 1, 0, 0},
		{0, 1, 0, 0, 0, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 1},
		{0, 1, 1, 1, 0, 1, 0, 0}
	};
bool findpath(uint32_t x, uint32_t y) {


	/* 미로밖으로 넘으려고 할때*/
	if(x < 0 || y < 0 || x >= maze_size || y >= maze_size)
		return false;

	/* 확인되지 않은 cell에서만 행한다.*/
	if(maze_map[x][y] != UNIDENTIFIED_CELL)
		return false;

	/* (7,7이 EXIT라고 가정할때) EXIT에 도달한다면 현재의 경로 까지가
	 EXIT로 가는 경로가 된다 이부분이 base가 된다.*/
	if(x == maze_size-1 && y == maze_size-1) {
		maze_map[x][y] = PATH;
		return true;
	}

	maze_map[x][y] = PATH;

	/* 현재 cell의 좌*/
	if(findpath(x-1, y) == true)
		return true;

	/* 현재 cell의 상*/
	else if(findpath(x, y+1) == true)
		return true;

	/* 현재 cell의 우*/
	else if(findpath(x+1, y) == true)
		return true;

	/* 현재 cell의 하*/
	else if(findpath(x, y-1) == true)
		return true;

	else {
		maze_map[x][y] = NOT_EXIT_PATH;
		return false;
	}

}

void print_maze() {
	for(int col = 0; col < maze_size; col++) {
		for(int row = 0; row < maze_size; row++) {
			printf("%d ", maze_map[row][col]);
		}
		printf("\n");
	}
}
void main(void) {
	printf("before\n");
	print_maze();
	findpath(0,0);
	printf("after\n");
	print_maze();
}
