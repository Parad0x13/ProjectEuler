// Project Euler problem 179 started 20Oct13
/*	Calculating divisors is easy for low values... very hard for large values. It turns out there
	are a few ways this can be done quickly:
		Quadratic Sieve, Elliptic Curves, Number Field Sieve and others:
		http://crypto.stackexchange.com/questions/377/which-algorithms-are-used-to-factorize-large-integers
	However to implement one of these will require it's OWN research entirely	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

template<class T>
T positiveDivisors(T input) {
	T count = T();
	for(T d=input;d>0;d--) {
		if(input%d == 0)count++;
	}
	return count;
}

vector<long>primes = primesUpTo<long>(10000000);
template<class T>
T positiveDivisors2(T input) {
	T remainder = input;
	int primeIndex = 0;
	vector<T>primeFactors;
	while(remainder != 1) {
		T prime = primes[primeIndex];
		int count = 0;
		while(remainder%prime == 0) {
			remainder /= prime;
			count++;
		}
		if(count > 0)
			primeFactors.push_back(count);
		primeIndex++;
	}
	T total = 1;
	for(int d=0;d<primeFactors.size();d++)
		total *= (primeFactors[d] + 1);
	return total;
}

int main() {
	cout << "Start" << endl;
	unsigned long long max = 10000000;
	long prevN = -1;
	long count = 0;
	for(unsigned long long d=1;d<max;d++) {
		long n = positiveDivisors2(d);
		if(n == prevN)count++;
		prevN = n;
	}
	cout << "Found: " << count << endl;
	return false;
}
