// Project Euler problem 42 solved at 2207KST 09Oct13. I was the 35987th person to have solved this problem
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

vector<string> inputFile() {
	ifstream fileIn;
	fileIn.open("words.txt");

	if(fileIn.is_open()) {
		string wordsString;
		getline(fileIn, wordsString);
		string::iterator end_pos = std::remove(wordsString.begin(), wordsString.end(), '"');
		wordsString.erase(end_pos, wordsString.end());
		vector<string>words = split(wordsString, ',');
		fileIn.close();
		return words;
	}
	else cout << "Unable to open input file" << endl;
}

vector<unsigned int> triangleNumbers(int count) {
	vector<unsigned int>retVal;
	for(int d=1;d<=count;d++)retVal.push_back(0.5f*d*(d+1));
	return retVal;
}

vector<unsigned int>triNumbers;
bool isNumberTriangleNumber(unsigned int number) {
	if(triNumbers.size() == 0)triNumbers = triangleNumbers(100);
	assert(number <= triNumbers[triNumbers.size()-1]);
	for(int d=0;d<triNumbers.size();d++) {
		if(triNumbers[d] == number)return true;
	}
	return false;
}

unsigned int valueForWord(string word) {
	unsigned int totalValue = 0;
	for(int d=0;d<word.size();d++) {
		int letterValue = word[d] - 'A' + 1;
		totalValue += letterValue;
	}
	return totalValue;
}

int main() {
	vector<string>words = inputFile();
	//for(int d=0;d<words.size();d++)cout << words[d] << endl;
	//cout << isNumberTriangleNumber(55) << endl;
	//cout << valueForWord("AB") << endl;
	int totalTriangleWords = 0;
	for(int d=0;d<words.size();d++) {
		if(isNumberTriangleNumber(valueForWord(words[d])))
			totalTriangleWords++;
	}
	cout << "Found a total of " << totalTriangleWords << " triangle words" << endl;
	return false;
}
