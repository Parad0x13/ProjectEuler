// Project Euler problem 69 solved 1632KST 12Nov13. I was the 16428th person to have solved this problem
/*	Citation for Euler's Product formula: http://en.wikipedia.org/wiki/Euler%27s_totient_function
	Citation for Pi product formula notation: http://en.wikipedia.org/wiki/Arithmetical_function#Notation	*/
/*	Initially I tried computing every prime factorization of every number up to 1 million but found that
	that took a VERY long time. Like 20 minutes of time to do. I noticed while the numbers were filling
	in on the screen that numbers like 990990 or 870870 or 690690 were coming up and decided that I would
	experiment with only searching d up to 1000 but checking d*1000+d and right away found that the number
	510510 had the highest prime totient value. I tried this number on the site and found it to be correct.
	I don't know WHY this works, but it does. I've left the slow code annotated as well for record	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

uint32_t largestSearch = 1000000;
vector<size_t> primes = primesUpTo<size_t>(largestSearch);

double eulers_totient(int index) {
	vector<size_t> factors = distinctPrimeFactors<size_t>(index, primes);
	double retVal = index;
	for(int d=0;d<factors.size();d++)retVal *= 1-1/(double)factors[d];
	return retVal;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	double largestTotientPrime = 0;
	uint32_t largestTotientPrimeIndex;
	for(uint32_t d=1;d<1000;d++) {	// Brute force check to 1000000
		uint32_t num = d*1000+d;
		double totient = eulers_totient(num);	// Brute force would check totient of d
		double tPrime = num/totient;			// Brute force would check prime of totient of d
		if(tPrime > largestTotientPrime) {
			largestTotientPrime = tPrime;
			largestTotientPrimeIndex = num;
			cout << "Found totient " << largestTotientPrime << " at index " << largestTotientPrimeIndex << endl;
		}
	}
	cout << "Largest totient " << largestTotientPrime << " found at index " << largestTotientPrimeIndex << endl;

	timer->stopLog();
	return false;
}
