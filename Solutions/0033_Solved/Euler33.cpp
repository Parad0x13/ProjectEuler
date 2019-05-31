// Project Euler problem 33 solved 1405KST 24Oct13. I was the 33023rd person to have solved this problem
/*	Built this specifically to be able to solve larger digit problems instead of just 2 digit ones	*/
#include <iostream>
#include <string>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

template<class T>
bool haveDigitInCommon(T a, T b) {
	string aString = toString(a);
	string bString = toString(b);
	for(size_t d=0;d<aString.size();d++) {
		if(bString.find(aString[d]) != string::npos)return true;
	}
	return false;
}

template<class T>
bool testDigits(T a, T b) {
	string aString = toString(a);
	string bString = toString(b);
	for(size_t digitIndex_a=0;digitIndex_a<aString.size();digitIndex_a++) {
		for(size_t digitIndex_b=0;digitIndex_b<bString.size();digitIndex_b++) {
			if(aString[digitIndex_a] == bString[digitIndex_b]) {
				string aStringNew = aString;
				string bStringNew = bString;
				aStringNew.erase(digitIndex_a, 1);
				bStringNew.erase(digitIndex_b, 1);
				T aNew = fromString<T>(aStringNew);
				T bNew = fromString<T>(bStringNew);
				// I don't like how this is done
				if((double)a/(double)b == (double)aNew/(double)bNew)
					return true;
			}
		}
	}
	return false;
}

int main() {
	int numerator = 99, denominator = 99;
	//int numerator = 22, denominator = 22;
	vector<int>numeratorMatches;
	vector<int>denominatorMatches;

	// Rule - Must have 2 digits in numerator and denominator
	while(denominator >= 11) {
		while(numerator >= 11) {
			bool shouldCheck = true;
			// Rule - Trivial division by 10 check
			if(numerator % 10 == 0 || denominator % 10 == 0)shouldCheck = false;
			// Rule - Fraction must be less than 1 in value
			if(numerator >= denominator)shouldCheck = false;
			if(shouldCheck) {
				if(haveDigitInCommon(numerator, denominator)) {
					numeratorMatches.push_back(numerator);
					denominatorMatches.push_back(denominator);
				}
			}
			numerator--;
		}
		denominator--;
		numerator = denominator;
	}

	vector<int>finalNumerators;
	vector<int>finalDenominators;
	for(size_t d=0;d<numeratorMatches.size();d++) {
		if(testDigits(numeratorMatches[d], denominatorMatches[d])) {
			finalNumerators.push_back(numeratorMatches[d]);
			finalDenominators.push_back(denominatorMatches[d]);
		}
	}

	int numeratorTotal = 1;
	int denominatorTotal = 1;
	cout << "Found these equations to follow the rules:" << endl;
	for(size_t d=0;d<finalNumerators.size();d++) {
		cout << finalNumerators[d] << "/" << finalDenominators[d] << endl;
		numeratorTotal *= finalNumerators[d];
		denominatorTotal *= finalDenominators[d];
	}
	cout << endl;

	int gcd = GCD(numeratorTotal, denominatorTotal);
	cout << "Found the final equation:" << endl;
	cout << numeratorTotal/gcd << "/" << denominatorTotal/gcd << endl;

	return false;
}
