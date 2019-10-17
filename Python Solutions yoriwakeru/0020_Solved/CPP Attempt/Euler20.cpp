// Euler20.cpp : Defines the entry point for the console application.
//

// Will return the incorrect number if value exceeds allocated memtype
// Need to use a large number cruncher library or something

#include "stdafx.h"
#include <conio.h>

int max = 100;
unsigned long long num = 1;

int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	printf("Calculating...\n");
	for(x=max;x>0;x--)
		num=num*x;
	printf("Sum: %llu\n", num);
	getch();
	return 0;
}
