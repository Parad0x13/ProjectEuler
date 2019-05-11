// Project Euler problem 15 solved at 1350KST. I was the 79067th person to have solved this problem
// The answer to this question is the center number of a pascal triangle of size 20
// With help from http://www.robertdickau.com/lattices.html
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int factorial(cpp_int n) {
	if(n == 0 || n == 1)return 1;
	else return factorial(n - 1) * n;
}

// n!/(r!(n-r)!)
cpp_int binomialCoefficient(cpp_int n, cpp_int r) {
	return factorial(n)/(factorial(r)*factorial(n-r));
}

// (2n)!/(n!)^2
cpp_int centralBinomialCoefficient(cpp_int n) {
	return factorial(2*n)/(factorial(n)*factorial(n));
}

int main() {
	for(int d=0;d<21;d++)cout << centralBinomialCoefficient(d) << endl;
	return false;
}
