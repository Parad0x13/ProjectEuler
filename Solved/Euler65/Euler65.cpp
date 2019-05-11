// Project Euler problem 65 solved 2039KST 04Nov13. I was the 13848th person to have solved this problem
#include <iostream>
#include "ProjectEulerTools.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace PET;
using namespace boost::multiprecision;

// http://oeis.org/search?q=1%2C1%2C2%2C3%2C8%2C11%2C19%2C87%2C106%2C193&sort=&language=english&go=Search
template<class T>
void generateNext(vector<T> &a) {
	size_t n = a.size();
	int option = n%3;
	if(option == 0)a.push_back(a[n-1] + a[n-2]);
	else if(option == 1)a.push_back(2*(n-1)*a[n-1]/3 + a[n-2]);
	else if(option == 2)a.push_back(a[n-1] + a[n-2]);
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	vector<cpp_int> numerators;
	numerators.push_back(1);
	numerators.push_back(1);

	vector<cpp_int> denominators;
	denominators.push_back(1);
	denominators.push_back(0);

	for(int d=0;d<100;d++) {
		generateNext(numerators);
		generateNext(denominators);
	}

	cout << "Sum of digits of last numerator: " << sumOfDigits(numerators.back()) << endl;

	timer->stopLog();
	return false;
}
