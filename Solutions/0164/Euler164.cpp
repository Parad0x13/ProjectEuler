#include <iostream>
#include <vector>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

bool isAcceptable(int input) {
	int compareSize = 3;
	for(int d=0;d<digitCount(input)-compareSize;d++) {
		//
	}
	return false;
}

int main() {
	int min = 10000;
	int max = 100000;
	vector<int> numbers;
	vector<int> unacceptable;
	for(int d=min;d<max;d++)numbers.push_back(d);
	for(int d=0;d<numbers.size();d++) {
		if(!isAcceptable(numbers[d]))
			unacceptable.push_back(numbers[d]);
	}
	cout << numbers.size() << ":" << unacceptable.size() << endl;
	return false;
}
