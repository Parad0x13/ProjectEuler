// Project Euler problem 127 started 17Nov13
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

uint64_t maxValue = 1000;
uint64_t maxABC = maxValue*(maxValue-1)*(maxValue+maxValue-1);
vector<uint64_t> primes = primesUpTo<uint64_t>(10000000u);
//vector<uint64_t> primes = primesUpTo_MillerRabin<uint64_t>(10000000u);
//vector<uint64_t> primes = primesUpTo_MillerRabin<uint64_t>(maxABC);

template<class T>
T rad(T input) {
	T retVal = 1;
	vector<pair<T, T> > factors = primeFactors<T>(input, primes);
	for(int d=0;d<factors.size();d++) {
		retVal *= factors[d].first;
	}
	return retVal;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	uint64_t test = 0;
	test--;
	cout << test << endl;
	cout << "Max abc will be: " << maxABC << endl;
	cout << primes.back() << endl;
	//getchar();

	size_t sigma = 0;
	for(uint64_t b=1;b<maxValue;b++) {
		for(uint64_t a=1;a<b;a++) {
			uint64_t c = a+b;
			if(GCD(a, b) == GCD(a, c) == GCD(b, c) == 1) {
				uint64_t abc = a*b*c;
				//cout << abc << endl;
				//cout << "a: " << a << " b: " << b << " c: " << c << endl;
				if(rad(abc) < c) {
					sigma += c;
				}
			}
		}
	}

	cout << "sigma(c): " << sigma << endl;
	//cout << rad<size_t>(4320) << endl;

	timer->stopLog();
	return false;
}
