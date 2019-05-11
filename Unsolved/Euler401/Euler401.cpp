// Project Euler problem 401. Started 30Oct13
#include <iostream>
#include "ProjectEulerTools.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace PET;
using namespace boost::multiprecision;

// Only need primes up to sqrt(10^15) which is ~31,622,777
//size_t primeMax = 31622777;
//cpp_int primeMax = sqrt(power(10, 15));
size_t primeMax = 10000;
vector<size_t> primes;
cpp_int squareMax = 31622777;
vector<cpp_int> squares;

template<class T>
vector<T> divisorsOf(T input) {
	vector<T>retVal;
	vector<T>primeDivisors = primeFactors(input, primes);
	vector<pair<T, T> >pairs;
	while(primeDivisors.size() > 0) {
		T value = primeDivisors[0];
		T valueCount = count(primeDivisors.begin(), primeDivisors.end(), value);
		removeFromVector(value, primeDivisors);
		pairs.push_back(pair<T, T>(value, valueCount));
	}
	vector<pair<T, T> >pairMultiples;
	for(T d=0;d<pairs.size();d++)
		pairMultiples.push_back(pair<T, T>(pairs[d].first, 0));
	bool allDivisorsFound = false;
	while(!allDivisorsFound) {
		T value = 1;
		for(T d=0;d<pairMultiples.size();d++)
			value *= power(pairMultiples[d].first, pairMultiples[d].second);
		retVal.push_back(value);

		T lastIndex = pairMultiples.size()-1;
		pairMultiples[lastIndex].second++;
		for(T index=lastIndex;index>=0;index--) {
			if(pairMultiples[index].second > pairs[index].second) {
				pairMultiples[index].second = 0;
				if(index == 0)allDivisorsFound = true;
				else pairMultiples[index-1].second++;
			}
		}
	}

	sort(retVal.begin(), retVal.end());
	return retVal;
}

template<class T>
T sigma2(T input) {
	vector<T> divisors = divisorsOf(input);
	T retVal = 0;
	for(int d=0;d<divisors.size();d++) {
		retVal += divisors[d]*divisors[d];
	}
	return retVal;
}

int main() {
	Timer *timer = new Timer();

	timer->start();
	cout << "Calculating " << primeMax << " primes" << endl;
	primes = primesUpTo<size_t>(primeMax);
	cout << "Primes calculated" << endl;
	timer->stopLog();

	timer->start();
	cout << "Calculating " << squareMax << " squares" << endl;
	for(cpp_int d=0;d<squareMax;d++)squares.push_back(d*d);
	cout << "Squares calculated" << endl;
	timer->stopLog();

	cout << squares.back() << endl;
	// ERROR - There's a problem here with cpp_int...
	cout << sigma2<cpp_int>(6) << endl;
	//cout << sigma2<int>(6) << endl;

	return false;
}
