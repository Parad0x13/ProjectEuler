// Project Euler problem 41 started 22Oct13 and solved 2009KST 03Nov13. I was the 30817th to have solved this problem
/*	Largest pandigital number in base 10 has exactly 10 digits [0 - 9]
	To find the largest pandigital prime you have to calculate primes
	up to 10^10-1, which is... a lot. More so than can be calculated
	easily. Instead I think I should implement a faster prime testing
	algorithm based off the size of the prime to be tested. I left the
	code running and it calculated 10^9 primes in 30 minutes...		*/
/*	On 03Nov13 I tried to limit the search to all permutations of 0-9
	against a now working Miller-Rabin test. However it seems for some
	reason no pandigitals exist that include 10 digits?		*/
/*	Yep! Turns out the largest pandigital prime only has 7 digits : 3	*/

#include <iostream>
#include "ProjectEulerTools.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace PET;
using namespace boost::multiprecision;
using namespace boost;

int main() {
	Timer *timer = new Timer();
	timer->start();

	cpp_int largest = 0;
	string permutationString = "1234567";
	vector<string> possibles = permutationsOf(permutationString);
	cout << possibles.size() << endl;
	vector<string> temp;
	for(size_t d=0;d<possibles.size();d++) {
		stripPrefixZeros(possibles[d]);
		if(possibles[d].size() == permutationString.size())temp.push_back(possibles[d]);
	}
	possibles = temp;
	sort(possibles.begin(), possibles.end());
	cout << possibles.size() << endl;

	reverse(possibles.begin(), possibles.end());
	cout << possibles[0] << endl;
	for(size_t d=0;d<possibles.size();d++) {
		cpp_int current = lexical_cast<cpp_int>(possibles[d]);
		if(isPrime<cpp_int>(current)) {
			if(current > largest)largest = current;
		}
	}
	cout << "Found the largest value of " << largest << endl;

	timer->stop();
	timer->log();

	return false;
}
