// Project Euler problem 97 solved 1627KST 05Nov13. I was the 24484th person to have solved this problem
/*	I don't know why exactly I couldn't use uint64_t for power algorithm and had to use cpp_int...	*/
#include <iostream>
#include "ProjectEulerTools.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace PET;
using namespace boost::multiprecision;

// http://mathforum.org/library/drmath/view/66970.html
void calculateViaPower() {
	cpp_int base = 2, exponent = 7830457u;

	cpp_int total = 1;
	// uint64_t works up to power<uint64_t>(10, 9) but not greater than that for some reason
	cpp_int range = power<cpp_int>(10, 10);
	int index = 0;
	while(exponent > 0) {
		cpp_int multiple = ((exponent & 1) * power<cpp_int>(2, index));
		cpp_int value = 1;
		if(multiple == 1)value = base;
		else if(multiple > 1) {
			for(size_t d=0;d<multiple;d++) {
				value *= base;
				value %= range;
			}
		}
		total *= value;
		total %= range;
		exponent >>= 1;
		index++;
	}
	total *= 28433;
	total += 1;
	total %= range;
	cout << total << endl;
}

void calculateViaSimple() {
	uint64_t b = 2, e = 7830457;
	uint64_t a = 1, r = 10000000000u;
	for(uint64_t d=0;d<e;d++) {
		a *= b;
		a %= r;
	}
	a *= 28433;
	a += 1;
	a %= r;
	cout << a << endl;
}

int main() {
	Timer *timer = new Timer();
	timer->start();
	calculateViaSimple();
	timer->stopLog();
}
