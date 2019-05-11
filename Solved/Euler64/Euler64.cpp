// Project Euler problem 64 solved 1120KST 12Dec13. I was the 10203rd person to have solved this problem
#include <iostream>
#include <limits>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	Timer *timer = new Timer();
	timer->start();

	int max = 10000;
	int oddCount = 0;
	for(int d=1;d<=max;d++) {
		ContinuedFraction *test = continuedFractionOfSquareRoot(d);
		int period = test->period.size();
		if(isOdd(period))
			oddCount++;
	}
	cout << "Found " << oddCount << " numbers below " << max << " with odd continuous fraction periods" << endl;

	timer->stopLog();
	return false;
}
