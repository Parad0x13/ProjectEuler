// Project Euler problem 349, started 09Oct13
// I know I cannot accomplish this with a fixed grid, the ant will escape into a ladder eventually
// To solve this problem I'll have to find a way to calculate when the pattern starts
// then extrapolate after the ladder has formed
#include <iostream>

using namespace std;

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CW,
	CCW,
}DIRECTIONS;

bool grid[100][100] = {0};
unsigned int x = 50, y = 50;
int direction = UP;

void rotateDirection(int rotate) {
	if(rotate == CW) {
		if(direction == UP) {y++;direction = RIGHT;}
		else if(direction == DOWN) {y--;direction = LEFT;}
		else if(direction == LEFT) {x--;direction = UP;}
		else if(direction == RIGHT) {x++;direction = DOWN;}
	}
	else if(rotate == CCW) {
		if(direction == UP) {y++;direction = LEFT;}
		else if(direction == DOWN) {y--;direction = RIGHT;}
		else if(direction == LEFT) {x--;direction = DOWN;}
		else if(direction == RIGHT) {x++;direction = UP;}
	}
}

void iterate() {
	if(grid[x][y] == false)rotateDirection(CW);
	else if(grid[x][y] == true)rotateDirection(CCW);
	grid[x][y] = !grid[x][y];
	cout << x << ":" << y << endl;
}

unsigned int blackCount() {
	unsigned int retVal = 0;
	for(int d=0;d<100;d++) {
		for(int dd=0;dd<100;dd++) {
			if(grid[d][dd] == true)retVal++;
		}
	}
	return retVal;
}

int main() {
	for(int d=0;d<10000;d++)
		iterate();
	cout << "Total count: " << blackCount() << endl;
	return false;
}
