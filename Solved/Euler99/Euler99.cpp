// Project Euler problem 99. Started 06Nov13 and solved 1500KST 17Nov13. I was the 14912th person to have solved this problem
/*	This problem took awhile to solve since I had my base and exponent swapped in my digit calculation equation.
	After I fixed it I moved the code to ProjectEulerTools.h
	Then I noticed that I got lucky when answering this problem since two lines have the same digit count. I then needed
	to solve which value was larger by checking the first few digits, which I didn't do since I already answered the question	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	Timer *timer = new Timer();
	timer->start();

	vector<string> lines = fileLines("base_exp.txt");

	size_t largest = 0;
	for(int d=0;d<lines.size();d++) {
		vector<string> input = split(lines[d], ',');
		size_t base = fromString<size_t>(input[0]);
		size_t exponent = fromString<size_t>(input[1]);
		size_t digits = digitCount(base, exponent);
		if(digits >= largest) {
			largest = digits;
			cout << "New largest of " << base << "^" << exponent << " on line " << d+1 << " contains " << digits << " digits" << endl;
		}
	}

	timer->stopLog();
	return false;
}
