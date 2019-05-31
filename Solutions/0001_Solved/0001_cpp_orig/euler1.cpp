// euler1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0, sum = 0;

	/*for(x=1;x<1000;x++)
	{
		if(x*3<1000)
			sum+=x*3;
		if(x*5<1000&&x%3!=0)
			sum+=x*5;
	}*/
	for(x=0;x<1000;x++)
	{
		if(x%3==0||x%5==0)
			sum+=x;
	}

	printf("Iteration: %i, Sum: %i\n", x, sum);
	getch();
	return 0;
}

