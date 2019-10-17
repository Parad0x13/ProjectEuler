// Project Euler problem 47 solved 1202KST 23Oct13. I was the 26052nd person to have solved this problem
/*	I don't like how long it takes to solve this equation, and how I just guess
	on numbers until it worked. For instance I had no idea how many primes I should
	have calculated so I kept changing the number until it finally worked. Had I
	known how many primes I should calculate to I could prevent waste calculations	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	vector<size_t>primes = primesUpTo<size_t>(500000);

	int stride = 4;
	unsigned long d = 1;
	vector<vector<size_t> >factorVectors;
	for(;;) {
		for(int currentD=0;currentD<stride;currentD++) {
			if(factorVectors.size() < d+currentD) {
				vector<size_t>factors = distinctPrimeFactors<size_t>(d+currentD, primes);
				factorVectors.push_back(factors);
			}
		}
		bool allDistinct = true;
		for(int index=0;index<stride-1;index++) {
			if(!areDistinct(factorVectors[index+d-1], factorVectors[index+d-1+1]))
				allDistinct = false;
		}
		bool correctFactorCount = true;
		if(allDistinct) {
			for(int index=0;index<stride;index++) {
				if(factorVectors[index+d-1].size() != stride)
					correctFactorCount = false;
			}
		}
		else {
			cout << "Not all distinct" << endl;
		}
		if(correctFactorCount) {
			cout << "Correct starting at " << d << " with stride " << stride << endl;
			break;
		}
		d++;
	}

	return false;
}
