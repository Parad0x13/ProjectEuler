// Project Euler problem 35 solved 1253KST 25Oct13. I was the 4026th person to have solved this problem
/*	When I solved the problem I advanced to level 2. Only 25921 members (7.41%)
	had made it that far at the time	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	vector<size_t>primes = primesUpTo<size_t>(1000000);
	vector<size_t>circularPrimes;
	for(size_t d=0;d<primes.size();d++) {
		size_t value = primes[d];
		vector<size_t>values = fromStrings<size_t>(circularValues(toString(value)));
		if(isSubset(values, primes)) {
			circularPrimes.push_back(d);
			cout << "Found: " << d << endl;
		}
	}
	cout << "Found " << circularPrimes.size() << " circular primes" << endl;
	return false;
}
