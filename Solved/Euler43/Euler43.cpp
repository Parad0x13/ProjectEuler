// Project Euler problem 43 solved 0132KST 25Oct13. I was the 26241st person to have solved this problem
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

vector<int>primes = primesUpTo(17);
bool valid(string input) {
	int stride = 3;
	for(size_t d=1;d<input.size()-stride+1;d++) {
		string current = input.substr(d, stride);
		int prime = primes[d-1];
		size_t value = fromString<size_t>(current);
		if(value%prime != 0)return false;
	}
	return true;
}

int main() {
	vector<string>permutations = permutationsOf("0123456789");
	// A value prefixed with 0 cannot work since we need 10 digits
	vector<string>workingPermutations;
	for(size_t d=0;d<permutations.size();d++) {
		if(permutations[d][0] != '0')workingPermutations.push_back(permutations[d]);
	}
	permutations = workingPermutations;

	vector<string>subStringDivisibility;
	for(size_t d=0;d<permutations.size();d++) {
		if(valid(permutations[d])) {
			subStringDivisibility.push_back(permutations[d]);
			cout << "Found " << permutations[d] << endl;
		}
	}
	cout << "Found a total of " << subStringDivisibility.size() << endl;
	vector<unsigned long long>numbers = fromStrings<unsigned long long>(subStringDivisibility);
	cout << "Total sum of " << sum<unsigned long long>(numbers) << endl;

	return false;
}
