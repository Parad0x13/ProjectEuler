// Project Euler problem 89 solved 2302KST 11Oct13. I was the 10319th person to have solved this problem
/*	I = 1
	V = 5
	X = 10
	L = 50
	C = 100
	D = 500
	M = 1000
	Rule 1: Only I, X, and C can be used as the leading numeral in part of a subtractive pair
	Rule 2: I can only be placed before V and X
	Rule 3: X can only be placed before L and C
	Rule 4: C can only be placed before D and M	*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int valueForLetter(char letter) {
	if(letter == 'I')return 1;
	if(letter == 'V')return 5;
	if(letter == 'X')return 10;
	if(letter == 'L')return 50;
	if(letter == 'C')return 100;
	if(letter == 'D')return 500;
	if(letter == 'M')return 1000;
}

// Does not need to tightly follow the rules
int intForRomanNumeral(string numeral) {
	int total = 0;
	for(int d=0;d<numeral.size();d++) {
		bool isSubtractive = false;
		int currentValue = valueForLetter(numeral[d]);
		int nextValue = 0;
		if(numeral.size() > d+1)nextValue = valueForLetter(numeral[d+1]);
		if(nextValue > currentValue)isSubtractive = true;
		if(isSubtractive) {
			total += (nextValue-currentValue);
			d++;
		}
		else total += currentValue;
	}
	return total;
}

// Must tightly follow the rules
string numeralForNumber(int number) {
	if(number >= 10000)return "Come on now... enter a lower number!";
	string retVal;
	int digitCount = floor(log10(abs(number))) + 1;
	for(int d=digitCount-1;d>=0;d--) {
		int power = ceil(pow(10, d));
		int digit = number/power%10;
		if(power == 1) {
			if(digit == 0)retVal += "";
			else if(digit == 1)retVal += "I";
			else if(digit == 2)retVal += "II";
			else if(digit == 3)retVal += "III";
			else if(digit == 4)retVal += "IV";
			else if(digit == 5)retVal += "V";
			else if(digit == 6)retVal += "VI";
			else if(digit == 7)retVal += "VII";
			else if(digit == 8)retVal += "VIII";
			else if(digit == 9)retVal += "IX";
		}
		else if(power == 10) {
			if(digit == 0)retVal += "";
			else if(digit == 1)retVal += "X";
			else if(digit == 2)retVal += "XX";
			else if(digit == 3)retVal += "XXX";
			else if(digit == 4)retVal += "XL";
			else if(digit == 5)retVal += "L";
			else if(digit == 6)retVal += "LX";
			else if(digit == 7)retVal += "LXX";
			else if(digit == 8)retVal += "LXXX";
			else if(digit == 9)retVal += "XC";
		}
		else if(power == 100) {
			if(digit == 0)retVal += "";
			else if(digit == 1)retVal += "C";
			else if(digit == 2)retVal += "CC";
			else if(digit == 3)retVal += "CCC";
			else if(digit == 4)retVal += "CD";
			else if(digit == 5)retVal += "D";
			else if(digit == 6)retVal += "DC";
			else if(digit == 7)retVal += "DCC";
			else if(digit == 8)retVal += "DCCC";
			else if(digit == 9)retVal += "CM";
		}
		else if(power == 1000) {
			if(digit == 0)retVal += "";
			else if(digit == 1)retVal += "M";
			else if(digit == 2)retVal += "MM";
			else if(digit == 3)retVal += "MMM";
			else if(digit == 4)retVal += "MMMM";
			else if(digit == 5)retVal += "MMMMM";
			else if(digit == 6)retVal += "MMMMMM";
			else if(digit == 7)retVal += "MMMMMMM";
			else if(digit == 8)retVal += "MMMMMMMM";
			else if(digit == 9)retVal += "MMMMMMMMM";
			// Rules don't dictate what comes next
		}
	}
	return retVal;
}

vector<string> numeralsFromFile() {
	ifstream fileIn;
	fileIn.open("roman.txt");

	vector<string>retVal;
	if(fileIn.is_open()) {
		string line;
		while(getline(fileIn, line))retVal.push_back(line);
	}
	else cout << "Unable to open input file" << endl;

	fileIn.close();
	return retVal;
}

vector<string> compressNumerals(vector<string>numerals) {
	vector<string>retVal;
	for(int d=0;d<numerals.size();d++) {
		int value = intForRomanNumeral(numerals[d]);
		string compressedNumeral = numeralForNumber(value);
		retVal.push_back(compressedNumeral);
	}
	return retVal;
}

int main() {
	vector<string>numerals = numeralsFromFile();
	vector<string>compressedNumerals = compressNumerals(numerals);
	string concatenatedNumerals;
	for(int d=0;d<numerals.size();d++)concatenatedNumerals += numerals[d];
	string concatenatedCompressedNumerals;
	for(int d=0;d<compressedNumerals.size();d++)concatenatedCompressedNumerals += compressedNumerals[d];
	cout << "Delta: " << concatenatedNumerals.size()-concatenatedCompressedNumerals.size() << endl;
}
