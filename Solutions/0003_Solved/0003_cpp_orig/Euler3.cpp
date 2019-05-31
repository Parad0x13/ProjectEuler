// Euler3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <math.h>

bool isprime(int num);

int foundPrimes = 0, primes[9000000];
int x;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long long theNumber = 600851475143, primeFactor = 0;
	//unsigned long long theNumber = 13195, primeFactor = 0;

	primes[0] = 2;		// Initialize the first prime, thus is 2
	foundPrimes++;

	printf("Calculating...\n");
	for(x=3;x<sqrt((double)theNumber);x++)	// You only have to calculate up to sqrt(theNumber)
	{
		if(isprime(x))		// If it is a prime
		{
			foundPrimes++;
			primes[foundPrimes-1]=x;
			if(theNumber%x==0)
			{
				primeFactor = x;
				//printf("New primeFactor: %llu\n", primeFactor);
			}
		}
		//if(x%100000==0)
		//	printf("1HT Calculations finding %i primes sofar\n", foundPrimes);
	}

	printf("Fully Calculated! Largest PrimeFactor is %llu\n", primeFactor);
	getch();
	return 0;
}

// Uses the Sieve Of Eratosthenes method
bool isprime(int num)
{
	int d;
	for(d=0;d<foundPrimes;d++)		// Filters through the entire primes[] database
	{
		if(num%primes[d]==0)		// If prime/d is divisable with no leftovers then return false
			return false;
	}

	// If havn't returned false
	return true;
}