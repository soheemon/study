/* 동작: cell의 x, y값을 입력받아서
   입력받은 cell이 속하는 Blob의 크기를 count
*/

#include <stdio.h>
#include <stdint.h>

/* BACKGROUND_COLOR = 개수에 포함하지 않음
   IMAGE_COLOR = 개수에 포함시켜야 하는 cell
   COUNTED_CELL = 이미 개수에 포함된 cell
*/

#define BACKGROUND_COLOR 0
#define IMAGE_COLOR 1
#define COUNTED_CELL 2

/* 현재 셀을 기준으로 탐색을 시작함. */

#define CNT_WEST_CELL(x, y) count_image_cell(x+1, y) 
#define CNT_EAST_CELL(x, y) count_image_cell(x-1, y)
#define CNT_NORTH_CELL(x, y) count_image_cell(x, y+1)
#define CNT_SOUTH_CELL(x, y) count_image_cell(x, y-1)

#define CNT_NORTHWEST_CELL(x, y) count_image_cell(x-1, y+1)
#define CNT_NORTHEAST_CELL(x, y) count_image_cell(x+1, y+1)
#define CNT_SOUTHWEST_CELL(x, y) count_image_cell(x-1, y-1)
#define CNT_SOUTHEAST_CELL(x, y) count_image_cell(x+1, y-1)

static uint32_t grid[8][8] = {
	{1, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 0, 0},
	{1, 1, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1, 1}
};
static uint32_t N = 8;

uint32_t count_image_cell(uint32_t x, uint32_t y) {
	uint32_t result = 0;

	/* grid범위를 넘어갈경우 */

	if((x < 0) || (y < 0))
		return 0;

	if((x >= N) || (y >= N))
		return 0;

	if(grid[x][y] != IMAGE_COLOR)
		return 0;

	grid[x][y] = COUNTED_CELL;

	/* 현재셀을 포함해서 8방향으로 탐색을 시작함 */

	return 1 +
		CNT_NORTH_CELL(x, y) + CNT_NORTHEAST_CELL(x, y) +
		CNT_EAST_CELL(x, y) + CNT_SOUTHEAST_CELL(x, y) +
		CNT_SOUTH_CELL(x, y) + CNT_SOUTHWEST_CELL(x, y) +
		CNT_WEST_CELL(x, y) + CNT_NORTHWEST_CELL(x, y) ;

}

void main(void) {
	printf("%d\n", count_image_cell(0, 0));
}
