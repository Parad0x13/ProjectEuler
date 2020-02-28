// Project Euler problem 123 solved 2307KST 27Oct13. I was the 5990th person to have solved this problem
/*	Granted my initial solve took much longer than a minute to run... : ( I kept that code as findHardWay()
	I then found out on the forum that you could highly simplify the equation and rewrote it accordingly	*/
#include <iostream>
#include "ProjectEulerTools.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace PET;
using namespace boost::multiprecision;

void findHardWay() {
	vector<size_t> primes = primesUpTo<size_t>(1000000);

	cpp_int largest = power<cpp_int>(10, 10);
	size_t offset = 21034;	// Got this through trial and error : ( Also this is cheating...
	size_t stride = 1;
	for(size_t index=offset;index<primes.size();index+=stride) {
		if(index%2 != 0)continue;	// Can only be caught on odd numbers
		size_t n = index+1;
		cpp_int pn = primes[index];
		cpp_int mod = (power<cpp_int>(pn-1, n) + power<cpp_int>(pn+1, n))%(pn*pn);
		if(index%stride == 0)cout << n << ":" << mod << endl;
		if(mod > largest) {
			cout << "Found " << mod << endl;
			break;
		}
	}
}

// ((Pn-1)^2 + (Pn+1)^2)%Pn^2 can be simplified:
// If n is even then modulus will equal 2P*n
// If n is odd then modulus will alway equal 2
template<class T>
T simplifiedAnswer(T P, T n) {
	if(n % 2 == 0)return 2;
	return P*n<<1;
}

void findEasyWay() {
	vector<size_t> primes = primesUpTo<size_t>(1000000);

	cpp_int largest = power<cpp_int>(10, 10);
	for(size_t index=0;index<primes.size();index++) {
		cpp_int pn = primes[index];
		size_t n = index+1;
		cpp_int mod = simplifiedAnswer<cpp_int>(pn, n);
		if(mod > largest) {
			cout << "Found mod of " << mod << " at prime index " << n << endl;
			break;
		}
	}
}

int main() {
	findEasyWay();

	return false;
}
