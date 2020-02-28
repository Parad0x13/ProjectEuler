// Project Euler problem 55 solved at 2305KST 09Oct13. I was the 26211th person to have solved this problem
// I found that when converting the reversed number strings to cpp_ints problems would be had if the prefix was a 0
// For instance the number 80 reversed as a string is 08 which is an octal number numerically. This threw an error
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
#include <algorithm>

using namespace std;
using namespace boost::multiprecision;

string stripPrefixZeros(string input) {
	string retVal = input;
	while(retVal[0] == '0')retVal.erase(0, 1);
	return retVal;
}

int palindromeIterationOf(unsigned int number) {
	int iteration = 0;
	int lychrelLimit = 50;
	cpp_int workingNumber = number;
	for(int d=0;d<lychrelLimit;d++) {
		string numberString = boost::lexical_cast<string>(workingNumber);
		string reversedNumberString = numberString;
		reverse(reversedNumberString.begin(), reversedNumberString.end());
		reversedNumberString = stripPrefixZeros(reversedNumberString);
		cpp_int reversedWorkingNumber = boost::lexical_cast<cpp_int>(reversedNumberString);
		cpp_int sum = workingNumber + reversedWorkingNumber;
		string sumString = boost::lexical_cast<string>(sum);
		string reversedSumString = sumString;
		reverse(reversedSumString.begin(), reversedSumString.end());
		reversedSumString = stripPrefixZeros(reversedSumString);
		cpp_int reversedSum = boost::lexical_cast<cpp_int>(reversedSumString);
		if(sum == reversedSum) {
			cout << number << ": " << sum << " at iteration: " << d+1 << endl;
			return d+1;
		}
		workingNumber = sum;
	}
	return -1;
}

int main() {
	int lychrelCount = 0;
	for(int d=1;d<10000;d++) {
		int iteration = palindromeIterationOf(d);
		if(iteration == -1)lychrelCount++;
	}
	cout << "Found: " << lychrelCount << " lychrel numbers" << endl;

	return false;
}
