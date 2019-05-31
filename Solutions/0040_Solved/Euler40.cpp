// Project Euler problem 40 solved 1229KST 11Oct13. I was the 37247th person to have solved this problem
// This was surprisingly easy to solve. The reason for that was I didn't expect a string to be able
// to so easily store such a long value. I guess 1 Million isn't really as large a number as I thought!
#include <iostream>
#include <cmath>
#include <boost/lexical_cast.hpp>

using namespace std;

int main() {
	string numberLine;
	unsigned long final = 1000000;
	for(unsigned long d=1;d<final;d++) {
		string numberString = boost::lexical_cast<string>(d);
		numberLine += numberString;
	}
	long total =
	(numberLine[1-1]-'0') *
	(numberLine[100-1]-'0') *
	(numberLine[1000-1]-'0') *
	(numberLine[10000-1]-'0') *
	(numberLine[100000-1]-'0') *
	(numberLine[1000000-1]-'0');
	cout << total << endl;
	return false;
}
