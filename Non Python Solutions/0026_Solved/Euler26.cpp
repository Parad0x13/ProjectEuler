// Project Euler problem 26 solved 2313KST 03Nov13. I was the 36636th person to have solved this problem
/*	While working on figuring out how to solve this problem I hadn't even though
	of trying long division. It ended up being really easy once I implemented it
	but I know there are better ways out there to do this. For instance I know by
	reading some forums that you can determine the cycle instead of actually solving
	the long division. One way to speed this up would be starting the search at the top
	of max then working downwards. The max repeat cycle is n-1 so as soon as I find
	a cycle of n-1 that's the answer		*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

template<class T>
T cycleOf(T input) {
	int numerator, denominator;
	numerator = 1;
	denominator = input;
	int cycle = 0;

	string answer;
	answer += ".";
	vector<int> remainders;
	bool evenDivisor = false;

	for(;;) {
		numerator *= 10;

		int fitCount = numerator / denominator;
		int fitValue = denominator * fitCount;
		int remainder = numerator % denominator;

		numerator = remainder;

		if(remainder == 0) {
			evenDivisor = true;
			break;
		}
		if(existsIn(remainder, remainders))break;
		remainders.push_back(remainder);
		answer += toString(fitCount);
		cycle++;
	}

	//cout << "Answer: " << answer << endl;

	if(evenDivisor)return 0;
	return cycle;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	int max = 1000;
	int maxCycleDenominator = 0, maxCycle = 0;

	for(int d=2;d<max;d++) {
		int cycle = cycleOf(d);
		if(cycle > maxCycle) {
			maxCycleDenominator = d;
			maxCycle = cycle;
		}
	}

	cout << "Found 1/" << maxCycleDenominator << " gives a cycle of " << maxCycle << endl;

	timer->stopLog();
	return false;
}
