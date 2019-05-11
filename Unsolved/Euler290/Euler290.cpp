// Project Euler problem 290 started 10Oct13
// Turns out 10^18 is a very large number to loop through >.> another method will be needed
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/math/special_functions/pow.hpp>

using namespace std;
using namespace boost::multiprecision;
//using namespace boost::math;

cpp_int sumOfDigits(cpp_int input) {
	cpp_int total = 0;
	string inputString = boost::lexical_cast<string>(input);
	for(int d=0;d<inputString.size();d++) {
		int digit = inputString[d] - '0';
		total += digit;
	}
	return total;
}

// I don't want to do it this way
// But I can't figure out how to do it in boost
cpp_int power(cpp_int base, cpp_int exponent) {
	cpp_int retVal = 1;
	for(long d=0;d<exponent;d++)retVal *= base;
	return retVal;
}

int main() {
	cpp_int n = 0;
	cpp_int max = power(10, 18);
	cout << max << endl;
	while(n < max) {
		n++;
	}

	return false;
}
