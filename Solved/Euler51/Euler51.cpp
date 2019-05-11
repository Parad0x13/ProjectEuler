// Project Euler problem 51 solved 1535KST 19Nov13. I was the 14359 person to have solved this problem
#include <iostream>
#include "ProjectEulerTools.h"
#include <string>

using namespace std;
using namespace PET;

vector<uint64_t> primes = primesInRange_MillerRabin<uint64_t>(100000, 1000000);	// Guessed the range

string booleanString(string input, int boolValue, char replacement) {
	string retVal;
	for(int d=input.size()-1;d>=0;d--) {
		if(power(2, d) & boolValue)
			retVal += input[input.size()-d-1];
		else
			retVal += replacement;
	}
	return retVal;
}

vector<string> allTemplates(string input) {
	vector<string> retVal;
	for(int d=0;d<power<int>(2, input.size());d++)
		retVal.push_back(booleanString(input, d, '~'));
	return retVal;
}

int wildcardPrimeCount(string value_template, bool logPrimes) {
	int count = 0;
	for(int digitToReplaceWith=0;digitToReplaceWith<10;digitToReplaceWith++) {
		string current = value_template;
		replace(current.begin(), current.end(), '~', toString(digitToReplaceWith)[0]);
		if(current[0] != '0') {
			if(isPrime<uint64_t>(fromString<uint64_t>(current))) {
				if(logPrimes)cout << "Found " << fromString<uint64_t>(current) << " is prime" << endl;
				count++;
			}
		}
	}
	return count;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	string winner_template;
	int count;
	for(uint32_t primeIndex=0;primeIndex<primes.size();primeIndex++) {
		vector<string> all = allTemplates(toString(primes[primeIndex]));
		uint32_t firstIndex = 1;
		uint32_t lastIndex = all.size()-1-1;
		for(int d=firstIndex;d<=lastIndex;d++) {
			string value_template = all[d];
			count = wildcardPrimeCount(value_template, false);
			if(count == 8) {
				winner_template = value_template;
				goto done;
			}
		}
	}done:

	cout << "value template: " << winner_template << " gives " << count << endl;
	wildcardPrimeCount(winner_template, true);

	timer->stopLog();
	return false;
}
