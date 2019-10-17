// Project Euler problem 27 solved at 1543KST 17Oct13. I was the 38985th person to have solved this problem
// Ended up just solving this by brute force without optimizations. Ugly, but it worked
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	int range = 1000;
	long primeMax = 1000;
	int maxN = 0;
	long bestA = 0, bestB = 0;
	vector<long>primes = primesUpTo(primeMax);
	for(int a=-range;a<=range;a++) {
		for(int b=-range;b<=range;b++) {
			int n=0;
			long answer;
			for(;;) {
				answer = n*n + a*n + b;
				if(answer > primes[primes.size()-1]) {
					cout << "recalculating primes" << endl;
					n--;
					primeMax *= 1.5f;
					primes = primesUpTo(primeMax);
				}
				if(!existsIn(answer, primes))break;
				n++;
			}
			if(n > maxN) {
				maxN = n;
				bestA = a;
				bestB = b;
				cout << "largest sofar: " << a << ":" << b << ":" << n << endl;
			}
		}
	}
	cout << "Equation n^2+an+b where a(" << bestA << ") b(" << bestB << ") returns " << maxN << " primes" << endl;
	cout << "Product of a*b is: " << bestA*bestB << endl;

	return false;
}
