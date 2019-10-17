// Euler14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

int chainLength(unsigned int input);

unsigned long long n;
//int n;
int x, limit = 1000000;
int increment;
int largestChain = 0, largestValue = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Calculating...\n");
	for(x=1;x<limit;x++)
	{
		if(chainLength(x)>largestChain)
		{
			largestChain = chainLength(x);
			largestValue = x;
			//printf("%i has the new largest chain of %i\n", largestValue, largestChain);
		}
	}

	printf("Number %i had the largest chain of %i\n", largestValue, largestChain);
	getch();
	return 0;
}

int chainLength(unsigned int input)
{
	//int d;
	int chain = 1;
	while(input!=1)
	{
		if(input%2==0)
			input=input/2;
		else
			input=input*3+1;
		chain++;
	}
	return chain;
}