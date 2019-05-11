// Project Euler problem 46 solved 2109KST 20Oct13. I was the 26832nd person to have solved this problem
#include <iostream>
#include <vector>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

long primeMax = 1000;
vector<long>primes = primesUpTo(primeMax);
void recalculatePrimes() {
	primeMax *= 1.5f;
	primes = primesUpTo(primeMax);
}

int main() {
	long d = 9;
	bool numberStillPossible = true;
	while(numberStillPossible) {
		if(d%2 != 0 && !existsIn(d, primes)) {
			long primeIndex = 0;
			long square = 1;
			long foundPrime = 0;
			long foundSquare = 0;
			while(foundPrime == 0 && foundSquare == 0) {
				square = 1;
				for(;;) {
					long value = primes[primeIndex] + 2 * (square*square);
					if(value == d) {
						foundPrime = primes[primeIndex];
						foundSquare = square;
						break;
					}
					if(value > d)break;
					square++;
				}
				if(primes[primeIndex] > d) {
					cout << "Last value of " << d << " has been found" << endl;
					numberStillPossible = false;
					break;
				}
				primeIndex++;
				if(primeIndex > primes.size()-1)recalculatePrimes();
			}
		}
		d++;
		if(d > primes.size()-1)recalculatePrimes();
	}
	return false;
}
