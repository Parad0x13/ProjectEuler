// Project Euler problem 53 solved 0343KST 27Oct13. I was the 29473rd person to have solved this problem.
/*	Without boost's arbitrary math I don't know how I would have solved this...	*/
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

template<class T>
T factorial(T input) {
	if(input == 0)return 1;
	if(input == 1)return 1;
	return input*factorial<T>(input-1);
}

template<class T>
T combinations(T n, T r) {
	return (factorial<T>(n)/(factorial<T>(r)*factorial<T>(n-r)));
}

int main() {
	int max = 100;
	int overCount = 0;
	for(int n=1;n<=max;n++) {
		for(int r=1;r<=n;r++) {
			if(combinations<cpp_int>(n, r) > 1000000)overCount++;
		}
	}
	cout << overCount << endl;
}
