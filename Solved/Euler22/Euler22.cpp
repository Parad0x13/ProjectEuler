// Bryan Tremblay
// Solved 07Oct13 as the 59759th person. This was much easier than expected! I didn't write the string manipulation code, found it off the internet
#include <iostream>
#include <fstream>

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

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
	fileIn.open("names.txt");

	if(fileIn.is_open()) {
		string nameString;
		getline(fileIn, nameString);
		string::iterator end_pos = std::remove(nameString.begin(), nameString.end(), '"');
		nameString.erase(end_pos, nameString.end());
		vector<string>names = split(nameString, ',');
		sort(names.begin(), names.end());
		fileIn.close();
		return names;
	}
	else cout << "Unable to open input file" << endl;
}

int main(int argc, char **argv) {
	vector<string>names = inputFile();
	unsigned int totalScore = 0;
	for(int d=0;d<names.size();d++) {
		string name = names[d];
		unsigned int nameScore = 0;
		for(int dd=0;dd<name.size();dd++) {
			int letterValue = name[dd] - 'A' + 1;
			nameScore += letterValue;
		}
		totalScore += nameScore * (d+1);
	}
	cout << "Total Score: " << totalScore << endl;
}
