// Euler5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

unsigned long long number = 1;		// Projected smallest divisor of 1-20

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Calculating...\n");
	for(;;)
	{
		int x;
			if(	number%20==0&&
				number%19==0&&
				number%18==0&&
				number%17==0&&
				number%16==0&&
				number%15==0&&
				number%14==0&&
				number%13==0&&
				number%12==0&&
				number%11==0&&
				number%10==0&&
				number%9==0&&
				number%8==0&&
				number%7==0&&
				number%6==0&&
				number%5==0&&
				number%4==0&&
				number%3==0&&
				number%2==0){
				printf("Number %i is Divisable by all numbers 20 and below\n", number);
				break;}
			else
				number++;
	}
	getch();
	return 0;
}
