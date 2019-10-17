// Euler6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

int limit = 100;
unsigned long long sumOfSquares = 0;
unsigned long long squareOfSums = 0;
unsigned long long difference;

int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	for(x=0;x<limit+1;x++)
	{
		sumOfSquares+=x*x;
		printf("Number: %i, SumOfSquares: %llu\n", x, sumOfSquares);
		//getch();
	}
	for(x=0;x<limit+1;x++)
	{
		squareOfSums+=x;
	}
	squareOfSums*=squareOfSums;

	printf("\n\nFinal SumOfSquares: %llu\n", sumOfSquares);
	printf("Final SquareOfSums: %llu\n", squareOfSums);
	difference = squareOfSums-sumOfSquares;
	printf("Difference: %llu\n", difference);
	getch();
	return 0;
}

