// Project Euler problem 37 solved 1434KST 20Oct13. I was the 33773rd person to have solved this problem
/*	I'm almost certain it would have been easier to calculate backwards instead of forwards
	but I still solved it in less than a minute so I'm not too interested in changing the
	algorithm to do it. It's almost cheating that the question says only 11 primes have the
	requested property. It means I don't have to calculate past when I find that value	*/
#include <iostream>
#include <vector>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

typedef enum {
	LEFT,
	RIGHT,
}DIRECTIONS;

int main() {
	Timer *timer = new Timer();
	timer->start();

	long maxPrime = 100000;
	vector<long>primes = primesUpTo(maxPrime);
	vector<long>truncatablePrimes;
	long primeIndex = 0;
	//for(long d=0;d<primes.size();d++) {
	while(truncatablePrimes.size() < 11) {
		string primeString = toString(primes[primeIndex]);
		string testString;
		bool LRPrime = false, RLPrime = false;
		int LRSwitch;
		// Left to right check
		testString = primeString;
		LRSwitch = LEFT;
		for(;;) {
			long value = fromString<long>(testString);
			if(existsIn(value, primes)) {
				if(testString.size() == 1) {
					LRPrime = true;
					break;
				}
				else testString.erase(testString.begin());
			}
			else break;
		}
		// Right to left check
		testString = primeString;
		LRSwitch = RIGHT;
		for(;;) {
			long value = fromString<long>(testString);
			if(existsIn(value, primes)) {
				if(testString.size() == 1) {
					RLPrime = true;
					break;
				}
				else testString.erase(testString.size()-1);
			}
			else break;
		}
		if(LRPrime && RLPrime && primeString.size() > 1) {
			cout << "Found new truncatable prime: " << primes[primeIndex] << endl;
			truncatablePrimes.push_back(primes[primeIndex]);
		}
		primeIndex++;
		if(primeIndex > primes.size()-1) {
			maxPrime *= 1.5f;
			cout << "Increasing prime count to: " << maxPrime << endl;
			primes = primesUpTo(maxPrime);
			cout << "Done increasing prime count" << endl;
		}
	}
	cout << "Truncatable primes:" << endl;
	log(truncatablePrimes);
	cout << "Sum = " << sum(truncatablePrimes) << endl;

	timer->stop();
	timer->log();

	return	false;
}
