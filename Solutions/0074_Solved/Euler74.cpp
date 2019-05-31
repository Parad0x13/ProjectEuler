// Project Euler problem 74 solved 2151KST 27Oct13. I was the 12710 person to have solved this problem
/*	When I solved it the algorithm took 173.487 seconds, so improvement is needed	*/
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include "ProjectEulerTools.h"
#include <map>

using namespace std;
using namespace PET;
using namespace boost;
using namespace boost::multiprecision;

map<cpp_int, cpp_int> connections;
template<class T>
T nextInChain(T input) {
	T testConnection = connections[input];
	if(testConnection != 0)return testConnection;

	T retVal = T();
	string inputString = lexical_cast<string>(input);
	for(int d=0;d<inputString.size();d++) {
		T number = lexical_cast<T>(inputString[d]);
		retVal += factorial(number);
	}
	connections[input] = retVal;
	return retVal;
}

template<class T>
vector<T> chain(T input) {
	vector<T> retVal;
	retVal.push_back(input);
	for(;;) {
		T next = nextInChain(retVal.back());
		if(existsIn(next, retVal))break;
		retVal.push_back(next);
	}
	return retVal;
}

int main() {
	int max = 1000000;

	Timer *timer = new Timer();
	cpp_int val = power<cpp_int>(57, 81);

	timer->start();
	vector<vector<cpp_int> > chains;
	for(int d=1;d<max;d++) {
		if(d%10000==0)cout << "working on " << d << endl;
		chains.push_back(chain<cpp_int>(d));
	}
	timer->stopLog();

	int count = 0;
	for(size_t d=0;d<chains.size();d++) {
		if(chains[d].size() == 60)count++;
	}
	cout << "Found " << count << " chains of length 60" << endl;

	return false;
}
