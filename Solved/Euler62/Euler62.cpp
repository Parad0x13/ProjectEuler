// Project Euler problem 62 solved 1435KST 09Dec13. I was the 14285th person to have solved this problem
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

template<class T>
T cubeOf(T input) {
	return input*input*input;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	string answerPermutation = "Nothing";
	vector<string> cubeStrings;
	for(int d=1000;d<10000;d++) {
		uint64_t cube = cubeOf<uint64_t>(d);
		string cubeString = toString(cube);
		sort(cubeString.begin(), cubeString.end());
		cubeStrings.push_back(cubeString);

		int count = existCount<string>(cubeString, cubeStrings);
		if(count == 5) {
			answerPermutation = cubeString;
			break;
		}
	}

	cout << "Found answer permutation of " << answerPermutation << endl;

	int d = 1;
	for(;;) {
		uint64_t cube = cubeOf<uint64_t>(d++);
		string cubeString = toString(cube);
		sort(cubeString.begin(), cubeString.end());
		if(cubeString == answerPermutation) {
			cout << "Smallest cube with answer permutation is " << cube << endl;
			break;
		}
	}

	timer->stopLog();
	return false;
}
