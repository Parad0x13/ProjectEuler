// Project Euler problem 349 solved 1505KST 25Nov13. I was the 894th person to have solved this problem
/*	I know that 10^18 iterations is impossible to compute by brute force and the answer is possible to acertain
	because at around 10000 iterations the ant breaks off into a highway that has a period of 104 and continues
	forever. I thought I could solve the equation by finding all black tiles up to an iteration, i, where:
	(10^18-i)%104 = 0. That would find the remainder of iterations that can be applied to the highway. I
	calculated this at first to be 11064, the answer then was 115384615384614953 but that was not correct
	I also tried other things, but they didn't work either		*/
/*	I ended up solving it in the coolest possible way possible ever. My algorithm was to find an initial
	iteration value that left an iteration count which would divide 104 evenly. I chose 11064 and everything
	should have went alright. I put my answer into Project Euler and I got the evil red cross of incorrectness
	Then a new guy that works with me asked for me to explain my algorithm and as I was going over my logic
	he concluded it was sound as well and we were both scratching our heads to figure out why it wasn't working
	What possible thing did I leave out? Well we decided to review my code since he was new to C++ and as I was
	going over my function for finding the amount of black tiles before the highway started I noticed that a loop
	was checking <= instead of just <. I asked him to change my code and recompile and I got a value 1 less than
	what I tried as an answer. I though "How stupid would it be if this was the right answer?" so we plugged it
	into Project Euler and BAM! Green checkmark of beauty. I jumped up and ran around the room. The highest
	previous answer I had successfully answered was 123 so solving 349 was a huge success to me. So because of
	this question I looked intelligent to a new coworker and succeeded in inflating my ego just a little bit more	*/
#include <iostream>
#include <cstring>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CW,
	CCW,
}DIRECTIONS_ROTATIONS;

// Cheap way of doing things, not very elegant
int blackAfterIterations(int iterations) {
	int maxX = 400, maxY = 400, resolution = maxX*maxY;
	int antX = maxX/2, antY = maxY/2, antDirection = UP;
	bool grid[maxX][maxY];
	memset(grid, false, resolution);
	for(int d=0;d<iterations;d++) {
		bool newStatus;
		int newRotation;
		if(grid[antX][antY]) {newStatus = false;newRotation = CCW;}
		else {newStatus = true;newRotation = CW;}
		grid[antX][antY] = newStatus;
		if(newRotation == CW) {
			if(antDirection == UP)antDirection = RIGHT;
			else if(antDirection == RIGHT)antDirection = DOWN;
			else if(antDirection == DOWN)antDirection = LEFT;
			else if(antDirection == LEFT)antDirection = UP;
		}
		else if(newRotation = CCW) {
			if(antDirection == UP)antDirection = LEFT;
			else if(antDirection == RIGHT)antDirection = UP;
			else if(antDirection == DOWN)antDirection = RIGHT;
			else if(antDirection == LEFT)antDirection = DOWN;
		}
		if(antDirection == UP)antY++;
		else if(antDirection == DOWN)antY--;
		else if(antDirection == LEFT)antX--;
		else if(antDirection == RIGHT)antX++;
	}
	unsigned count = 0;
	for(int x=0;x<maxX;x++) {
		for(int y=0;y<maxY;y++)
			if(grid[x][y] == true)count++;
	}
	return count;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	uint64_t max = power<uint64_t>(10, 18);
	uint64_t iterationsBeforeHighwayPeriod = 11064;		// (10^18-11064)%104 = 0
	uint64_t highwayPeriodIntervals = (max-iterationsBeforeHighwayPeriod)/104;
	uint64_t totalHighwayIterations = highwayPeriodIntervals * 104;
	uint64_t beforeHW_BWCount = blackAfterIterations(iterationsBeforeHighwayPeriod);
	// Found that every 104 iterations in the highway period leaves exactly 12 new black tiles
	uint64_t HW_BWCount = highwayPeriodIntervals * 12;
	uint64_t total_BWCount = beforeHW_BWCount + HW_BWCount;
	cout << total_BWCount << endl;

	timer->stopLog();
	return false;
}
