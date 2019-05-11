// Project Euler problem 433 started 21Nov13
/*	At first I thought this was going to be very easy but realized the version of the Euler equation
	they want me to use takes different step count for GCD_Euler(x, y) than from GCD_Euler(y, x)
	This means I have to check each order instead of skipping common GCDs
	and (5*10^6)^2 is a... large number, for example the brute calculation count is as such:
	(5*10^1)^2 == 2500 = (summation)8597
	(5*10^2)^2 == 250000 = (summation)1328294
	(5*10^3)^2 == 25000000 = (summation)181119556
	(5*10^4)^2 == 2500000000 = (summation)22960202052	// Approaching Limit of computational ability (260seconds)
	(5*10^5)^2 == 250000000000
	(5*10^6)^2 == 25000000000000		*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

template<class T>
T GCD_EulerCount(T x, T y) {
	T x0 = x;
	T y0 = y;
	T count = 0;
	while(y0 > 0) {
		T x1 = y0;
		T y1 = x0%y0;
		x0 = x1;
		y0 = y1;
		count++;
	}
	return count;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	uint64_t sum = 0;
	uint32_t n = 5*power(10, 3);
	for(uint32_t a=1;a<=n;a++) {
		for(uint32_t b=1;b<=n;b++)
			sum += GCD_EulerCount(a, b);
	}
	cout << sum << endl;

	timer->stopLog();
	return false;
}
