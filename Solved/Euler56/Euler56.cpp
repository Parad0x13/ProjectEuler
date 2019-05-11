// Project Euler problem 56 solved 0926KST 05Nov13. I was the 27782nd person to have solved this problem.
#include <iostream>
#include "ProjectEulerTools.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace PET;
using namespace boost::multiprecision;

int main() {
	Timer *timer = new Timer();
	timer->start();

	size_t maxSum = 0;
	int max = 100;
	for(int a=0;a<max;a++) {
		for(int b=0;b<max;b++) {
			cpp_int value = power<cpp_int>(a, b);
			size_t sum = digitSum(value);
			if(sum > maxSum)maxSum = sum;
		}
	}

	cout << "Found max sum of " << maxSum << endl;

	timer->stopLog();
	return false;
}
