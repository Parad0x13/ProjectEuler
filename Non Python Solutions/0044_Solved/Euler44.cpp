// Project Euler problem 44 started 20Oct13 and solved 1502KST 25Oct13. I was the 25366th person to have solved this problem
/*	This could be improved by caching the pentagonal numbers, but it works fine without it for now	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	bool found = false;
	size_t PjNumber = 1, PkNumber;
	while(!found) {
		unsigned long long Pj = pentagonalNumber<unsigned long long>(PjNumber);
		unsigned long long Pk;
		PkNumber = 1;
		while(PkNumber < PjNumber) {
			Pk = pentagonalNumber<unsigned long long>(PkNumber);
			unsigned long long sum = Pj+Pk;
			unsigned long long difference = Pj-Pk;
			if(isPentagonal(sum) && isPentagonal(difference)) {
				cout << "Found " << Pj << ":" << Pk << endl;
				cout << Pj-Pk << endl;
				found = true;
			}
			PkNumber++;
		}
		PjNumber++;
	}
	return false;
}
