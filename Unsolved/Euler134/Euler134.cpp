// Project Euler problem 134 started 27Nov13
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	Timer *timer = new Timer();
	timer->start();

	//int max = 1000000;
	int max = 10000;
	vector<uint64_t> primes = primesInRange_MillerRabin<uint64_t>(5, max+100);

	uint64_t sigma = 0;

	int primeIndex = 0;
	while(primes[primeIndex] <= max) {
		uint64_t p1 = primes[primeIndex];
		uint64_t p2 = primes[primeIndex+1];
		string p1Str = toString(p1);

		uint64_t value = p2;
		for(;;) {
			string valueStr = toString(value);
			int delta = valueStr.size() - p1Str.size();
			valueStr.erase(valueStr.begin(), valueStr.begin() + delta);

			if(valueStr == p1Str) {
				//cout << p1 << ":" << p2 << " = " << value << endl;
				sigma += value;
				break;
			}
			value += p2;
		}

		primeIndex++;
	}
	cout << "Sigma: " << sigma << endl;

	timer->stopLog();
	return false;
}
