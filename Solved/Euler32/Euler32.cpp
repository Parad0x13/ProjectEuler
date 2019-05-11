// Project Euler problem 32 solved at 1800KST 17Oct13. I was the 31533rd person to have solved this problem
/*	I admit that when I solved it the equation took 280.404 seconds which breaks the sites
	60 second rule. I will try to revise the algorithm more to make it work. Breakthroughs
	that I found while working on the algorithm were that I could easily discount multiplying
	past a certain number. I think I can speed the software up by finding exactly the minimum
	power I need to multiply up to.	*/
#include <iostream>
#include <vector>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

template<class T>
vector<T> pandigitalsWithDigits(string digitString) {
	vector<T>retVal;
	T digits = digitString.size();
	T multiplicand1, multiplicand2;
	for(multiplicand1 = T();multiplicand1 < pow(10, digits-1)-1;multiplicand1++) {
		T digits2 = digits-1 - digitCount(multiplicand1);
		for(multiplicand2 = T();multiplicand2 < pow(10, digits2)-1;multiplicand2++) {
			T m1 = digitCount(multiplicand1);
			T m2 = digitCount(multiplicand2);
			if(m1 + m2 < digits-1) {	// -1 because no product will be 0 digits in size
				T product = multiplicand1 * multiplicand2;
				if(product > pow(10, digits2))break;
				string full = toString(multiplicand1) + toString(multiplicand2) + toString(product);
				if(full.size() <= digits) {
					sort(full.begin(), full.end());
					if(full == digitString) {
						cout << multiplicand1 << "*" << multiplicand2 << "=" << product << endl;
						retVal.push_back(product);
					}
				}
			}
		}
	}
	return retVal;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	vector<unsigned long>pandigitals = pandigitalsWithDigits<unsigned long>("123456789");
	//vector<unsigned long>pandigitals = pandigitalsWithDigits<unsigned long>("12345678");
	cout << "Found: " << endl;
	log(pandigitals);
	cout << "Removing duplicates gives: " << endl;
	removeRepeats(pandigitals);
	log(pandigitals);
	cout << "With sum of: " << endl;
	cout << sum(pandigitals) << endl;

	timer->stop();
	timer->log();
	return false;
}
