// Project Euler problem 119 solved 1107KST 12Nov13. I was the 5938th person to have solved this problem
/*	I probably could solve this with uint64_t like I set out to do but I didn't want to
	test multiple numbers as the answer in the event the math went awry. So instead I
	thought it would be safer to use boost's cpp_int and initially calculated to max 100^100
	This is in no way optimized, but I thought heck it doesn't matter since the question is done	*/
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;
using namespace boost::multiprecision;

int main() {
	Timer *timer = new Timer();
	timer->start();

	vector<cpp_int> vals;
	int baseMax = 100, exponentMax = 10;
	for(int b=2;b<=baseMax;b++) {
		for(int e=1;e<=exponentMax;e++)
			vals.push_back(power<cpp_int>(b, e));
	}
	removeRepeats(vals);

	int foundCount = 0;
	for(int d=0;d<vals.size();d++) {
		cpp_int startBase = vals[d];
		cpp_int base = digitSum(startBase);
		cpp_int total = 0;
		int exponent = 2;
		while(total < vals.back()) {
			if(base == 1)break;
			total = power<cpp_int>(base, exponent);
			if(existsIn(total, vals) && total == startBase) {
				foundCount++;
				cout << "(" << foundCount << ")Found " << base << "^" << exponent << " = " << total << endl;
			}
			exponent++;
		}
	}

	timer->stopLog();
	return false;
}
