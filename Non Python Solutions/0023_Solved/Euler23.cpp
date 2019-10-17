// Project Euler problem 23 started 16Oct13 solved 0940KST 22Oct13. I was the 45083rd person to have solved this problem
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

typedef enum {
	PERFECT,
	DEFICIENT,
	ABUNDANT,
}SUM_TYPES;

template<class T>
vector<T> properDivisors(T input) {
	vector<T>retVal;
	// There is certainly room for improvement here
	for(T d = T()+1;d<input;d++) {
		if(input%d == 0)
			retVal.push_back(d);
	}
	return retVal;
}

template<class T>
int sumTypeOf(T input) {
	vector<T>divisors = properDivisors(input);
	T total = sum(divisors);
	if(total == input)return PERFECT;
	if(total < input)return DEFICIENT;
	if(total > input)return ABUNDANT;
}

int main() {
	int max = 28123;
	vector<unsigned int>abundants;
	for(int d=0;d<=max;d++) {
		if(sumTypeOf(d) == ABUNDANT)abundants.push_back(d);
	}
	// I don't know how to do this elegantly so I'll brute force it
	vector<unsigned int>summable;
	for(int d=0;d<abundants.size();d++) {
		for(int dd=0;dd<abundants.size();dd++) {
			unsigned int value = abundants[d] + abundants[dd];
			if(value <= max)summable.push_back(value);
			else break;
		}
	}
	removeRepeats(summable);

	unsigned int total = 0;
	for(unsigned int d=0;d<=max;d++) {
		if(!existsIn(d, summable))total += d;
	}
	cout << "Total sum: " << total << endl;
	return false;
}
