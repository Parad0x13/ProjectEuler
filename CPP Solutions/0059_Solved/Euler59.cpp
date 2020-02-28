// Project Euler problem 59 solved 1519KST 27Oct13. I was the 20122nd person to have solved this problem
/*	Ran into some problem when I didn't stop adding characters to fit the data length. For instance
	if the key was 8 characters long and the code was only 5 characters long I would accidentally add
	3 extra erronous characters to the end of the decrypted code.	*/
	// And a bible passage? Really?
#include <iostream>
#include <vector>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	vector<string> lines = fileLines("cipher1.txt");
	vector<int> data = fromStrings<int>(split(lines[0], ','));

	vector<string> requiredWords;
	requiredWords.push_back(" ");
	requiredWords.push_back("a");
	requiredWords.push_back("e");
	requiredWords.push_back("i");
	requiredWords.push_back("o");
	requiredWords.push_back("u");

	vector<string> forbiddenWords;
	forbiddenWords.push_back("|");
	forbiddenWords.push_back("`");
	forbiddenWords.push_back("\x7f");

	vector<string> words;
	words.push_back(" ");

	string key = "aaa";
	for(;;) {
		string answer;
		for(int d=0;d<data.size();d+=key.size()) {
			for(int keyIndex=0;keyIndex<key.size();keyIndex++) {
				if(d+keyIndex <= data.size()-1)
					answer += data[d+keyIndex]^key[keyIndex];
			}
		}

		bool wordFound = false;
		for(int d=0;d<words.size();d++) {
			if(answer.find(words[d]) != string::npos)
				wordFound = true;
		}
		for(int d=0;d<requiredWords.size();d++) {
			if(answer.find(requiredWords[d]) == string::npos)
				wordFound = false;
		}
		for(int d=0;d<forbiddenWords.size();d++) {
			if(answer.find(forbiddenWords[d]) != string::npos)
				wordFound = false;
		}
		if(wordFound) {
			cout << answer << endl;
			cout << "Tried key: " << key << endl;
			size_t sum = 0;
			for(int d=0;d<answer.size();d++)sum += (int)answer[d];
			cout << "Sum: " << sum << endl;
			cout << "size: " << answer.size() << endl;
			cout << "datasize: " << data.size() << endl;
			getchar();
		}

		// I don't like how this is done
		key[2]++;
		if(key[2] > 'z') {
			key[1]++;
			key[2] = 'a';
		}
		if(key[1] > 'z') {
			key[0]++;
			key[1] = 'a';
		}
		if(key[0] > 'z')
			break;
	}
	cout << "Search ended" << endl;

	return false;
}
