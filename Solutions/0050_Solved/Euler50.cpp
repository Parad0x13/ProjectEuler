// Project Euler problem 50 started 13Oct13 then worked on 25Oct13
// Finally solved 1559KST 04Nov13. I was the 27350th person to have solved this problem
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	vector<size_t> primes = primesUpTo<size_t>(1000000);
	size_t largestPrime = primes.back();
	size_t largestSum, largestSumBaseIndex, largestConsecutiveCount = 0;
	for(int d=0;d<primes.size();d++) {
		size_t tempSum = 0;
		size_t tempBaseIndex = d;
		size_t consecutiveCount = 0;
		for(;;) {
			size_t currentPrime = primes[tempBaseIndex];
			size_t temp = tempSum + currentPrime;

			if(consecutiveCount > largestConsecutiveCount) {
				if(existsIn(tempSum, primes)) {
					largestConsecutiveCount = consecutiveCount;
					largestSum = tempSum;
					largestSumBaseIndex = d;
				}
			}

			if(temp > largestPrime)break;
			if(tempBaseIndex > primes.size()-1)break;
			tempSum = temp;
			tempBaseIndex++;
			consecutiveCount++;
		}
	}
	cout << "found that prime " << primes[largestSumBaseIndex] << " has " << largestConsecutiveCount << " consecutive primes summing to " << largestSum << endl;
	return false;
}
