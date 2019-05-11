// Project Euler problem 145 started 14Oct13
// Resources: http://www.mathblog.dk/project-euler-145-how-many-reversible-numbers-are-there-below-one-billion/
// I tried solving this but I got the wrong answer for below 1000 and I have no idea why...
// It seems I don't understand the requirements of the question or something
#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

bool stringHasLeadingZeros(string input) {
	bool initialValueReached = false;
	for(int d=0;d<input.size();d++) {
		if(input[d] == '0' && !initialValueReached)return true;
		else if(input[d] != '0')return false;
	}
	return false;
}

bool isReversable(unsigned long input) {
	string inputString = lexical_cast<string>(input);
	string inputStringReverse = inputString;
	reverse(inputStringReverse.begin(), inputStringReverse.end());
	if(!stringHasLeadingZeros(inputStringReverse)) {
		unsigned long inputReverse = lexical_cast<unsigned long>(inputStringReverse);
		unsigned long sum = input + inputReverse;
		string sumStringStart = lexical_cast<string>(sum);
		string sumStringEnd = sumStringStart;
		erase_all(sumStringEnd, "2");
		erase_all(sumStringEnd, "4");
		erase_all(sumStringEnd, "6");
		erase_all(sumStringEnd, "8");
		if(sumStringStart.size() == sumStringEnd.size()) {
			cout << input << " + " << inputReverse << " = " << sum << endl;
			return true;
		}
	}
	else return false;
}

int main() {
	int total = 0;
	int max = 1000;
	for(int d=0;d<=max;d++) {
		if(isReversable(d))
			total++;
	}
	cout << "Found a total of " << total << " reversable numbers" << endl;
	return false;
}
