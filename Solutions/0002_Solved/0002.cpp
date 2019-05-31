// Project files and source edited and cleaned up from bad coding practices on 11Oct13.
// Problem solved prior to that date#include "stdafx.h"
#include <stdio.h>

int main() {
	unsigned long long oldNum = 1, newNum = 0, number = 1, sum = 0;

	printf("Will not add to sum if Fibonacci number is not even\n");
	while(number < 4000000) {
		unsigned long long tempNum;
		tempNum = number;
		number += oldNum;
		oldNum = tempNum;

		if(number%2 == 0)sum += number;
	}

	printf("\nDone! With a total sum of %llu", sum);
	return false;
}
