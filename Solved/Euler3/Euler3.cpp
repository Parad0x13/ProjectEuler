// Project files and source edited and cleaned up from bad coding practices on 11Oct13.
// Problem solved prior to that date
#include <stdio.h>
#include <math.h>

int foundPrimes = 0, primes[9000000];

// Uses the Sieve Of Eratosthenes method
bool isprime(int num) {
	int d;
	for(d=0;d<foundPrimes;d++) {
		if(num%primes[d] == 0)return false;
	}

	return true;
}

int main() {
	unsigned long long theNumber = 600851475143, primeFactor = 0;

	primes[0] = 2;
	foundPrimes++;

	printf("Calculating...\n");
	int maxNeeded = sqrt((double)theNumber);
	for(int x=3;x<maxNeeded;x++) {
		if(isprime(x)) {
			foundPrimes++;
			primes[foundPrimes-1] = x;
			if(theNumber%x == 0)
				primeFactor = x;
		}
	}

	printf("Fully Calculated! Largest Prime Factor is %llu\n", primeFactor);
	return false;
}
