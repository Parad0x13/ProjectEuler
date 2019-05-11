// Porject Euler problem 92 solved 2157KST 11Oct13. I was the 19941st person to have solved this problem
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int chainFromChain(unsigned int input) {
	int total = 0;
	int n = input;
	do {
		int digit = n%10;
		//cout << digit << endl;
		total += digit*digit;
		n /= 10;
	} while(n > 0);
	return total;
}

int main() {
	unsigned int endIn89 = 0;
	unsigned int max = 10000000;
	//unsigned int max = 100;
	for(unsigned int d=1;d<max;d++) {
		unsigned int value = d;
		while(value != 1 && value != 89) {
			//cout << value << endl;
			value = chainFromChain(value);
		}
		if(value == 89) {
			//cout << "Found: " << d << endl;
			endIn89++;
		}
	}
	cout << "Found " << endIn89 << " numbers who's chains end in 89" << endl;

	//cout << chainFromChain(46) << endl;

	return false;
}
