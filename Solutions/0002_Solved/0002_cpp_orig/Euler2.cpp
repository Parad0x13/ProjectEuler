// Euler2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long long oldNum = 1, newNum = 0, number = 1, tempNum, sum = 0;

	printf("Will not add to sum if Fibonacci number is not even\n\n");
	while(number<4000000)
	{
		printf("Fibonacci Number: %llu\nSum of: %llu\n\n", number, sum);
		tempNum = number;	// Stores current number
		number+=oldNum;		// Adds last two
		oldNum = tempNum;	// Sets oldNum to last number

		if(number%2==0)
			sum+=number;
	}

	printf("\nDone! With a total sum of %llu", sum);
	getch();
	return 0;
}

