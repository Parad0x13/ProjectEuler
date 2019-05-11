// Euler145.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int revInt(int number);
int num, limit = 1000000000;

int _tmain(int argc, _TCHAR* argv[])
{
	for(int x=0;x<limit;x++)
	{
		num = x+revInt(x);
		//printf("X: %i, SumRev: %i\n", x, num);

		if(x%10000000==0)
			printf("10Million Calculations more...\n");
	}
	getch();
	return 0;
}

int revInt(int number)
{
	char string[32], stringRev[32];
	itoa(number, string, 10);
	int x = strlen(string);
	x--;
	for(int y=0;y<=x;y++)
		stringRev[x-y]=string[y];
	return(atoi(stringRev));
}
