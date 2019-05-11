// Project Euler problem 57 solved 1350KST 27Oct13. I was the 19123rd person to have solved this problem
/*	I wonder if this could have been solved without a big number library	*/
#include <iostream>
#include <assert.h>
#include <boost/multiprecision/cpp_int.hpp>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;
using namespace boost::multiprecision;

template<class T>
void calculateNextInSequence(vector<T> &input) {
	assert(input.size() >= 2);
	input.push_back(2 * input[input.size()-1] + input[input.size()-2]);
}

int main() {
	vector<cpp_int> numerators;
	vector<cpp_int> denominators;
	numerators.push_back(3);
	numerators.push_back(7);
	denominators.push_back(2);
	denominators.push_back(5);

	for(int d=0;d<1000-2;d++) {
		calculateNextInSequence(numerators);
		calculateNextInSequence(denominators);
	}
	int count = 0;
	for(int d=0;d<numerators.size();d++)
		if(digitCount(numerators[d]) > digitCount(denominators[d]))count++;
	cout << "Found " << count << " numbers" << endl;

	return false;
}
