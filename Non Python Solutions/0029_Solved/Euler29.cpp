// Project Euler Problem 29
// Using Boost 1.54.0 for arbitrary math
// Solved 1010am Korea Time 09Oct13. I was the 46814th person to have solved this problem
#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int cpp_int_power(cpp_int number, cpp_int power) {
	cpp_int retVal = number;
	for(unsigned int d=1;d<power;d++)retVal *= number;
	return retVal;
}

int main() {
	int lowerBound = 2;
	int upperBound = 100;

	// I dislike how I had to sort and check for redundancies in the vector
	// I'm 100% new to boost/multiprecision so I don't know how to work it correctly
	vector<cpp_int>numbers;
	for(int base=lowerBound;base<=upperBound;base++) {
		cpp_int number = 0;
		for(int exponent=lowerBound;exponent<=upperBound;exponent++) {
			cpp_int value = cpp_int_power(base, exponent);
			bool containsNumber = false;
			for(unsigned int d=0;d<numbers.size();d++) {
				if(numbers[d] == value) {
					containsNumber = true;
					break;
				}
			}
			if(!containsNumber) {
				if(numbers.size() == 0)numbers.push_back(value);
				for(int d=0;d<numbers.size();d++) {
					if(value > numbers[d]) {
						numbers.insert(numbers.begin() + d, value);
						break;
					}
				}
			}
		}
	}
	// Reverse because I can't easily add lower values to the front of the vector
	reverse(numbers.begin(), numbers.end());

	cout << "Distinct terms in range [" << lowerBound << ", " << upperBound << "]: " << numbers.size() << endl;

	return false;
}
