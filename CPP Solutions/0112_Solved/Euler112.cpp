// Project Euler problem 112 solved 1147KST 13Nov13. I was the 12061st person to have solved this problem
/*	At first I thought manually checking each number would be a horrible and inefficient way of
	doing it and would lead to no computable answer. I was wrong, it was easy and gave the answer
	right away. I wonder if there is a computational way of doing this equation, and not brute force	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

typedef enum {
	INCREASING,
	DECREASING,
	INCREASING_DECREASING,
	BOUNCING,
}NUMBER_TYPES;

template<class T>
int numberType(T input) {
	string inputString = toString(input);
	int pinnedAs = INCREASING_DECREASING;
	for(int d=0;d<inputString.size()-1;d++) {
		// No need to convert to int value, chars are in order so < and > will work
		if(inputString[d] < inputString[d+1]) {
			if(pinnedAs != DECREASING)pinnedAs = INCREASING;
			else {
				pinnedAs = BOUNCING;
				break;
			}
		}
		else if(inputString[d] > inputString[d+1]) {
			if(pinnedAs != INCREASING)pinnedAs = DECREASING;
			else {
				pinnedAs = BOUNCING;
				break;
			}
		}
	}
	return pinnedAs;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	int bouncyCount = 0;
	double ratio = 0;
	int d = 100;
	for(;;) {
		if(numberType(d) == BOUNCING)bouncyCount++;
		if((bouncyCount/(double)d)*100.0f == 99.0f)break;
		d++;
	}
	cout << d << endl;

	timer->stopLog();
	return false;
}
