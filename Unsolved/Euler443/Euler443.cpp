// Project Euler problem 443 started 03Nov13
/*	10^15 is a VERY large number... There must be a way to find g(n-1) without calculating
	up to that point. I also searched oeis.org for g(n)'s sequence without any success.	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	Timer *timer = new Timer();
	timer->start();

	uint64_t n1 = 13;
	uint64_t max = 1000000000000000;

	for(uint64_t n=5;n<=max;n++)
		n1 = n1 + GCD(n, n1);

	cout << n1 << endl;

	timer->stopLog();
	return false;
}
