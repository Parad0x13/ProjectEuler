// Project Euler problem 303 started 10Oct13
// Up to the digit 98 everything is fine, but 99 doesn't want to compute quickly!
// Nor does 999! And from that I assume 9999 will NOT be solvable through brute force
// While coding this I found an interesting equation: 99 * 123456789 = 1222222221
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

/*	Theory behind this is the last digit HAS to be either 0, 1, or 2
	This means any multiplication of the input HAS to end in those numbers
	We can safely exclude any multiplier that does not fit
	E.G. any number ending in 9 can only end in 0, 1, or 2 if it is multiplied
		by a multiplier ending in the numbers 8, or 9
	Thus we only need to check values that end in those numbers
	I was able to decrease computation time from
		~52 seconds to ~18 seconds with this for f(99)
	Also found that I can stride the multiple to decrease time even more	*/

cpp_int cpp_int_power(cpp_int base, cpp_int power) {
    cpp_int retVal = base;
    for(unsigned int d=1;d<power;d++)retVal *= base;
    return retVal;
}

cpp_int smallDigitOf(int input) {
	static long tick = 0;
	cpp_int multiple = 1;
	int lastDigit = input%10;
	bool digitFound = false;

	while(!digitFound) {
		cpp_int mod = multiple%10;

		if(tick == 1000000) {
			cout << "Working on " << input << " Currently up to multiple: " << multiple << endl;
			tick = 0;
		}
 
		cpp_int value = input * multiple;
		string valueString = boost::lexical_cast<string>(value);

		bool isSmallDigit = true;
		for(int d=0;d<valueString.size();d++) {
			char character = valueString[d];
			if(character != '0' && character != '1' && character != '2') {
				isSmallDigit = false;
				break;
			}
		}
		if(isSmallDigit) {
			//cout << "Multiple for " << input << " is: " << multiple << " yielding:\t" << value << endl;
			cout << "Multiple for " << input << " is: " << multiple << " yielding:\t" << currentValue << endl;
			//return value;
			return currentValue;
		}

		int stride = 0;
		// 0 = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
		if(lastDigit == 0 && mod == 0)stride = 1;
		else if(lastDigit == 0 && mod == 1)stride = 1;
		else if(lastDigit == 0 && mod == 2)stride = 1;
		else if(lastDigit == 0 && mod == 3)stride = 1;
		else if(lastDigit == 0 && mod == 4)stride = 1;
		else if(lastDigit == 0 && mod == 5)stride = 1;
		else if(lastDigit == 0 && mod == 6)stride = 1;
		else if(lastDigit == 0 && mod == 7)stride = 1;
		else if(lastDigit == 0 && mod == 8)stride = 1;
		else if(lastDigit == 0 && mod == 9)stride = 1;
		// 1 = 0, 1, 2
		else if(lastDigit == 1 && mod == 0)stride = 1;
		else if(lastDigit == 1 && mod == 1)stride = 1;
		else if(lastDigit == 1 && mod == 2)stride = 8;
		// 2 = 0, 1, 5, 6
		else if(lastDigit == 2 && mod == 0)stride = 1;
		else if(lastDigit == 2 && mod == 1)stride = 4;
		else if(lastDigit == 2 && mod == 5)stride = 1;
		else if(lastDigit == 2 && mod == 6)stride = 4;
		// 3 = 4, 7
		else if(lastDigit == 3 && mod == 4)stride = 3;
		else if(lastDigit == 3 && mod == 7)stride = 6;
		// 4 = 3, 5, 8
		else if(lastDigit == 4 && mod == 3)stride = 2;
		else if(lastDigit == 4 && mod == 5)stride = 3;
		else if(lastDigit == 4 && mod == 8)stride = 5;
		// 5 = 2, 4, 6, 8
		else if(lastDigit == 5 && mod == 2)stride = 2;
		else if(lastDigit == 5 && mod == 4)stride = 2;
		else if(lastDigit == 5 && mod == 6)stride = 2;
		else if(lastDigit == 5 && mod == 8)stride = 4;
		// 6 = 2, 5, 7
		else if(lastDigit == 6 && mod == 2)stride = 3;
		else if(lastDigit == 6 && mod == 5)stride = 2;
		else if(lastDigit == 6 && mod == 7)stride = 5;
		// 7 = 3, 6
		else if(lastDigit == 7 && mod == 3)stride = 3;
		else if(lastDigit == 7 && mod == 6)stride = 7;
		// 8 = 4, 5, 9
		else if(lastDigit == 8 && mod == 4)stride = 1;
		else if(lastDigit == 8 && mod == 5)stride = 4;
		else if(lastDigit == 8 && mod == 9)stride = 5;
		// 9 = 8, 9
		else if(lastDigit == 9 && mod == 8)stride = 1;
		else if(lastDigit == 9 && mod == 9)stride = 9;
		else stride = 1;

		multiple += stride;
		//multiple += 1;
		tick++;
	}
	return -1;
}

vector<cpp_int>smallDigits;
void generateSmallDigits(int max) {
	smallDigits.clear();
	for(int d=1;d<=max;d++) {
		//cout << "Trying: " << d << endl;
		smallDigits.push_back(smallDigitOf(d));
	}
}

cpp_int test(int input) {
	static long tick = 0;
	int stride = 10;
	cpp_int multiple = 8;
	bool digitFound = false;
	while(!digitFound) {
		cpp_int value = input * multiple;
		string valueString = boost::lexical_cast<string>(value);

		bool isSmallDigit = true;
		for(int d=0;d<valueString.size();d++) {
			char character = valueString[d];
			if(character != '0' && character != '1' && character != '2') {
				isSmallDigit = false;
				break;
			}
		}
		if(isSmallDigit) {
			cout << "Multiple for " << input << " is: " << multiple << " yielding:\t" << value << endl;
			return value;
		}

		if(tick == 1000000) {
			cout << "Working on " << input << " Currently up to multiple: " << multiple << endl;
			tick = 0;
		}
		multiple += stride;
		tick++;
	}
}

int main() {
	clock_t start = clock();
	cout << smallDigitOf(99) << endl;
	//smallDigitOf(99);
	//generateSmallDigits(1000);
	//cout << test(99) << endl;
	//generateSmallDigits(1000);

	cpp_int sum = 0;
	for(int d=0;d<smallDigits.size();d++)
		sum += smallDigits[d];
	cout << "Sum: " << sum << endl;

	clock_t stop = clock();
	double delta = (stop-start) / (float)CLOCKS_PER_SEC;
	cout << "Time taken: " << delta << " seconds" << endl;
	return false;
}
