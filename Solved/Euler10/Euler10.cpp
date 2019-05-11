// Euler10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <math.h>

bool isprime(int num);
bool isprime2(unsigned int num);

int test = 0, x = 0, limit = 2000000;
unsigned long long value = 0;			// Float just will not do!
int foundPrimes = 0;
int primes[9000000];

int _tmain(int argc, _TCHAR* argv[])
{
	primes[0] = 2;		// Initialize the first prime, thus is 2
	foundPrimes++;
	value+=2;

	printf("Calculating...\n");
	for(x=3;x<limit;x++)	// Start after 2
	{
		if(isprime(x))		// If it is a prime
		{
			foundPrimes++;
			primes[foundPrimes-1]=x;
			value+=(unsigned long long)x;					// If it is a prime, just add it to the total
			//printf("%i is a prime\n", x);
			//getch();
		}
		if(x%100000==0)
			printf("%i, Value Sofar: %llu\n", x, value);
	}

	printf("Prime# %i is %i\n", foundPrimes, primes[foundPrimes-1]);
	printf("There are %i primes up to %i\n", foundPrimes, limit);

	//for(x=0;x<foundPrimes;x++)
	//	value+=primes[x];

	printf("Total value of %llu", value);
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


// Fast but not quite accurate enough yet
bool isprime2(unsigned int num)
{
	if(num<10)
	{
		if(num == 2)
			return true;
		if(num == 3)
			return true;
		if(num == 5)
			return true;
		if(num == 7)
			return true;
	}
	else
	if(num%2==0||num%3==0||num%5==0||num%7==0)
		return false;
	else
		return true;
}
