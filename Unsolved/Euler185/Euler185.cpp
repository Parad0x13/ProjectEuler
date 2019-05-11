// Project Euler problem 185 started 25Nov13
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	Timer *timer = new Timer();
	timer->start();

	vector<pair<string, int> > guesses;
	guesses.push_back(pair<string, int>("90342", 2));
	guesses.push_back(pair<string, int>("70794", 0));
	guesses.push_back(pair<string, int>("39458", 2));
	guesses.push_back(pair<string, int>("34109", 1));
	guesses.push_back(pair<string, int>("51545", 2));
	guesses.push_back(pair<string, int>("12531", 1));

	map<char, int> possibilities;
	for(int d=0;d<guesses.size();d++) {
		for(int dd=0;dd<guesses[d].first.size();dd++) {
			char number = guesses[d].first[dd];
			int count = guesses[d].second;
			if(count > 0) {
				// Gave up here... too distracted to continue
			}
		}
	}

	timer->stopLog();
	return false;
}
