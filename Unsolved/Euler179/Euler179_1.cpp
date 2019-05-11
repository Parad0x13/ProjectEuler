// Project Euler problem 179 started 11Oct13. Gave up around 1am the next day...
/* Resources: http://www.cplusplus.com/forum/beginner/11510/	*/
#include <iostream>
#include <cmath>

using namespace std;

int divisorCount(unsigned int input) {
	if(input%10000 == 0)cout << "Working on " << input << endl;
	//unsigned int maxMultiple = input/2;
	//int maxMultiple = input/2;
	//int maxMultiple = ceil(sqrt(input))+1;
	int maxMultiple = sqrt(input);
	int currentDivisorCount = 0;
	for(int d=2;d<=maxMultiple;d++) {
		if(input%d == 0) {
			currentDivisorCount += 2;
			//currentDivisorCount++;
			//currentDivisorCount++;	// due to input/d being a divisor as well
		}
	}
	return currentDivisorCount+2;	// Additional for divisible by 1, another for divisible by itself
}

int main() {
	unsigned int max = 10000000;
	//unsigned int max = 20;
	int consecutiveDivisors = 0;
	int n = 0;
	cout << "Calculating..." << endl;
	for(unsigned int d=1;d<max;d++) {
		int nPrime = divisorCount(d);
		if(n == nPrime)
			consecutiveDivisors++;
		n = nPrime;
	}
	cout << "Counted " << consecutiveDivisors << " consecutive divisors" << endl;
	//cout << divisorCount(32);
	return false;
}
