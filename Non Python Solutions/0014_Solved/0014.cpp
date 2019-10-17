// Project files and source edited and cleaned up from bad coding practices on 11Oct13.
// Problem solved prior to that date
#include <stdio.h>

int chainLength(unsigned int input) {
	int chain = 1;
	while(input != 1) {
		if(input%2 == 0)input = input / 2;
		else input = input * 3 + 1;
		chain++;
	}
	return chain;
}

int main() {
	int limit = 1000000;
	int largestChain = 0, largestValue = 0;
	printf("Calculating...\n");
	for(int x=1;x<limit;x++) {
		int newLength = chainLength(x);
		if(newLength > largestChain) {
			largestChain = newLength;
			largestValue = x;
		}
	}

	printf("Number %i had the largest chain of %i\n", largestValue, largestChain);
	return false;
}
