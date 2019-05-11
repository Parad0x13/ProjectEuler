// Project Euler problem 49 solved 2105KST 11Oct13. I was the 25503rd person to have solved this problem
#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;

vector<long long> removeMultiplesOf(vector<long long>values, long long multiple) {
	vector<long long>retVal;
	for(int d=0;d<values.size();d++) {
		int number = values[d];
		if(number <= multiple)retVal.push_back(number);
		else if((long long)number/(long long)multiple != (double)number/(double)multiple)
			retVal.push_back(number);
	}
	return retVal;
}

vector<long long> primesUpToValue(long long value) {
	vector<long long>numbers;
	for(long long d=2;d<=value;d++)numbers.push_back(d);
	for(long long d=2;d<=sqrt(value);d++) {
		numbers = removeMultiplesOf(numbers, d);
	}
	return numbers;
}

vector<int> generateFourDigitPrimes() {
	vector<int>fourDigitPrimes;
	vector<long long>primes = primesUpToValue(10000);
	for(int d=0;d<primes.size();d++) {
		if(primes[d] > 999 && primes[d] < 10000)
			fourDigitPrimes.push_back((int)primes[d]);
	}
	return fourDigitPrimes;
}

bool numbersArePermutations(int a, int b) {
	string aString = boost::lexical_cast<string>(a);
	string bString = boost::lexical_cast<string>(b);
	sort(aString.begin(), aString.end());
	sort(bString.begin(), bString.end());
	if(aString == bString)return true;
	return false;
}

// I don't like how this is done
bool vectorContainsNumber(vector<int>input, int number) {
	for(int d=0;d<input.size();d++) {if(input[d] == number)return true;}
	return false;
}

int main() {
	vector<int>fourDigitPrimes = generateFourDigitPrimes();
	int primeBase, primeStride;

	cout << "Calculating..." << endl;
	for(int d=0;d<fourDigitPrimes.size();d++) {
		for(int stride=1;stride<10000/3;stride++) {
			int maxIndex = d+stride*2;
			int basePrime = fourDigitPrimes[d];
			int projectedPrime2 = basePrime + stride*1;
			int projectedPrime3 = basePrime + stride*2;
			if(vectorContainsNumber(fourDigitPrimes, projectedPrime2) && vectorContainsNumber(fourDigitPrimes, projectedPrime3)) {
				if(numbersArePermutations(basePrime, projectedPrime2) && numbersArePermutations(basePrime, projectedPrime3)) {
					cout << basePrime << endl;
					cout << projectedPrime2 << endl;
					cout << projectedPrime3 << endl;
					cout << "Current Stride: " << stride << endl;
					cout << "Continuing search..." << endl;
				}
			}
		}
	}
	cout << "Search of full range complete, hopefully something was found" << endl;

	return false;
}
