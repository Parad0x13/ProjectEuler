// Project files and source edited and cleaned up from bad coding practices on 11Oct13.
// Problem solved prior to that date
#include <stdio.h>

int main() {
	int sum = 0, x;

	for(x=0;x<1000;x++) {
		if(x%3 == 0 || x%5 == 0)sum += x;
	}

	printf("Iteration: %i, Sum: %i\n", x, sum);
	return false;
}
