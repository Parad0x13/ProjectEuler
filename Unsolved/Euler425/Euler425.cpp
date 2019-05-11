// Project Euler problem 425 started 20Oct13
/*	Theory:
	Connections between two numbers can be made in any sort of ways. For instance the number 2 can be connected to any digit
	1,3,4,5,6,7,8,9 which can then be connected to any futher two digit number 11,21,31,41,...,23,33,43,53, etc... There must
	be a faster way to determine for certain if two numbers are connected than by trying out each and every possible link	*/
/*	On second look I don't need to connect all possible variations, just those that are primes	*/
/*	Gave up...	*/
#include <iostream>
#include "ProjectEulerTools.h"

#define NO_CONNECTION -1

using namespace std;
using namespace PET;

template<class T>
vector<T> digitCountBoolean(T requiredDigitCount, vector<T>input) {
	vector<T>retVal;
	for(T d=T();d<input.size();d++) {
		T count = digitCount(input[d]);
		if(count == requiredDigitCount)retVal.push_back(input[d]);
		else if(count > requiredDigitCount)break;	// Assumes input list is sorted
	}
	return retVal;
}

int main() {
	vector<unsigned int>possibleToLink;
	vector<unsigned int>primes = primesUpTo((unsigned int)21);
	possibleToLink.push_back(2);
	unsigned int primeIndex = 0;
	for(;;) {
		unsigned int prime = primes[primeIndex];
		if(existsIn(prime, possibleToLink)) {
			// Rule A
			unsigned int currentDigitCount = digitCount(prime);
			vector<unsigned int>sameDigitCount = digitCountBoolean(currentDigitCount, primes);
			for(unsigned int d=0;d<currentDigitCount;d++) {
				for(unsigned int testDigit=0;testDigit<10;testDigit++) {
					unsigned int newValue = swapDigit(prime, d, testDigit);
					//if(existsIn(newValue, primes) && newValue > prime) {
					if(existsIn(newValue, primes)) {
						possibleToLink.push_back(newValue);
						cout << "Rule A: " << prime << ":" << newValue << endl;
					}
				}
			}
			// Rule B
			// Check A <-> B
			// No need to test for testDigit=0 since we don't need to test for prefix of 0
			for(unsigned int testDigit=1;testDigit<10;testDigit++) {
				unsigned int powerValue = power((unsigned int)10, currentDigitCount);
				unsigned int additionalValue = testDigit * powerValue;
				unsigned int newValue = prime + additionalValue;
				//cout << "testing: " << prime << "+" << additionalValue << "=" << newValue << endl;
				if(existsIn(newValue, primes)) {					
					possibleToLink.push_back(newValue);
					cout << "Rule B: " << prime << ":" << newValue << endl;
				}
			}
			// Check B <-> A
			// Will happen when B is checked
			removeRepeats(possibleToLink);
			sort(possibleToLink.begin(), possibleToLink.end());
		}
		primeIndex++;
		static int repeat = 0;
		if(primeIndex > primes.size()-1) {
			repeat++;
			primeIndex = 0;
			if(repeat == 1)
				break;
		}
	}
	removeRepeats(possibleToLink);
	log(possibleToLink);
	return false;
}
