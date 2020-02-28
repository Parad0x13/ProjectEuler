// Project Euler problem 297 started 17Nov13.
/*	I did some tests on how long loops took to run to see if it's even possible to run 10^17 many loops.
	Turns out... no... no it doesn't seem to be possible... by a long shot. I subsequently posted a
	question here: http://stackoverflow.com/questions/20031684/why-a-uint32-t-vs-uint64-t-speed-difference
	asking what is happening in loops running over uint32_t vs uint64_t	*/
/*	There must be a more elegant way to calculate this than by brute force	*/
// Found this pattern on OEIS: http://oeis.org/A007895
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

vector<uint64_t> fib;

// Test array lookup of vector vs regular array

template<class T>
T nextLowestFib(T input) {
	//static map<T, T> memo;
	//if(memo.count(input) > 0)return memo[input];

	int maxIndex = 0;
	while(fib[maxIndex] <= input)maxIndex++;

	//memo[input] = fib[maxIndex-1];

	return fib[maxIndex-1];
}

template<class T>
vector<T> zeckendorf(T input) {
	vector<T> retVal;
	T value = input;
	while(value > 0) {
		retVal.push_back(nextLowestFib(value));
		value -= retVal.back();
	}

	return retVal;
}

template<class T>
T zeckendorfCount(T input) {
	T retVal = 0;
	T value = input;
	while(value > 0) {
		value -= nextLowestFib(value);
		retVal++;
	}

	return retVal;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	fib.push_back(1);fib.push_back(2);
	while(fib.back() < power<uint64_t>(10, 17)) {
		size_t lastIndex = fib.size()-1;
		fib.push_back(fib[lastIndex] + fib[lastIndex-1]);
	}

	for(int d=0;d<100;d++)
		cout << zeckendorfCount(d) << endl;

	uint64_t total = 0;
	for(uint64_t d=1;d<power<uint64_t>(10, 17);d++)
		total += zeckendorfCount(d);
	cout << "total " << total << endl;

	timer->stopLog();
	return false;
}
