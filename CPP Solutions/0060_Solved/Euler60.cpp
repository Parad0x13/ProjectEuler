// Project Euler problem 60 solved 2211KST 04Nov13. I was the 11316th person to have solved this problem
/*	I hate that I nested 5 loops... horrible horrible way of doing this		*/
#include <iostream>
#include "ProjectEulerTools.h"
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace PET;
using namespace boost;

// Permutation n!/(n-k)!
template<class T>
vector<T> combinatoric_permutations_2(vector<T> &values) {
	vector<T> retVal;
	for(size_t index=0;index<values.size();index++) {
		for(size_t current=index+1;current<values.size();current++) {
			string a = lexical_cast<string>(values[index]);
			string b = lexical_cast<string>(values[current]);
			string c = a+b;
			string d = b+a;
			retVal.push_back(lexical_cast<T>(c));
			retVal.push_back(lexical_cast<T>(d));
		}
	}

	return retVal;
}

template<class T>
bool allPrime(vector<T> &input) {
	for(size_t d=0;d<input.size();d++) {
		if(!isPrime<uint64_t>(input[d]))return false;
	}
	return true;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	int max = 8389;		// Cheating
	vector<unsigned int> primes = primesUpTo<unsigned int>(max);

	for(int a=0;a<primes.size();a++) {
		unsigned int primeA = primes[a];
		for(int b=a;b<primes.size();b++) {
			unsigned int primeB = primes[b];

			vector<unsigned int> inputs;
			inputs.push_back(primeA);
			inputs.push_back(primeB);
			vector<unsigned int> combinations = combinatoric_permutations_2(inputs);
			if(!allPrime(combinations))continue;

			for(int c=b;c<primes.size();c++) {
				unsigned int primeC = primes[c];

				vector<unsigned int> inputs;
				inputs.push_back(primeA);
				inputs.push_back(primeB);
				inputs.push_back(primeC);
				vector<unsigned int> combinations = combinatoric_permutations_2(inputs);
				if(!allPrime(combinations))continue;

				for(int d=c;d<primes.size();d++) {
					unsigned int primeD = primes[d];

					vector<unsigned int> inputs;
					inputs.push_back(primeA);
					inputs.push_back(primeB);
					inputs.push_back(primeC);
					inputs.push_back(primeD);
					vector<unsigned int> combinations = combinatoric_permutations_2(inputs);
					if(!allPrime(combinations))continue;

					for(int e=d;e<primes.size();e++) {
						unsigned int primeE = primes[e];
						if(primeA != primeB != primeC != primeD != primeE) {
							vector<unsigned int> inputs;
							inputs.push_back(primeA);
							inputs.push_back(primeB);
							inputs.push_back(primeC);
							inputs.push_back(primeD);
							inputs.push_back(primeE);
							vector<unsigned int> combinations = combinatoric_permutations_2(inputs);
							if(allPrime(combinations)) {
								cout << "Winner: " << endl;
								cout << primeA << ":" << primeB << ":" << primeC << ":" << primeD << ":" << primeE << endl;
								cout << "Sum: " << sum(inputs) << endl;
								goto end;
							}
						}
					}
				}
			}
		}
	}
end:
	cout << "Finished" << endl;

	timer->stopLog();
	return false;
}
