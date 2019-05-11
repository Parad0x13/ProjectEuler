// Project Euler problem 442 started 27Oct13
/*	Instead of trying to calculate by brute force I could probably try and find
	exactly how many numbers contain each power of 11 and not test a single number.
	I submitted a question to math.stackexchange.com asking if there is any simple
	equation to calculate a simple case of the term '11':
		http://math.stackexchange.com/questions/540479/help-with-creating-equation	*/
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;
using namespace boost;
using namespace boost::multiprecision;

vector<string>powersOf11;
bool isElevenFree(string input) {
	for(int d=0;d<powersOf11.size();d++) {
		if(input.find(powersOf11[d]) != std::string::npos)return false;
	}
	return true;
}

int main() {
	Timer *timer = new Timer();

	int powerLimit = 18;
	for(int d=1;d<powerLimit;d++)powersOf11.push_back(lexical_cast<string>(power<cpp_int>(11, d)));
	log(powersOf11);

	//cpp_int max = power<cpp_int>(10, 18);
	cpp_int max = 5 * power<cpp_int>(10, 5);
	cpp_int count = 0;
	cpp_int d = 0;
	timer->start();
	while(count < max) {
		d++;
		//if(d > 110000 && d < 119999)continue;

		if(isElevenFree(lexical_cast<string>(d))) {
			string name = lexical_cast<string>(d);
			if(count == max-1)cout << name << " is eleven free" << endl;
			count++;
		}
	}
	timer->stopLog();
	return false;
}
