// Project Euler problem 282
// Started 10Oct13 but I found that Ackermann Functions need a lot more of my research to understand...
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int ackermannFunction(cpp_int m, cpp_int n) {
	//cout << "Trying: " << m << " " << n << endl;
	if(m == 0)
		return n+1;
	if(m > 0 && n == 0)
		return ackermannFunction(m-1, 1);
	if(m > 0 && n > 0)
		return ackermannFunction(m-1, ackermannFunction(m, n-1));
}

int main() {
	/*cpp_int total = 0;
	for(int n=0;n<6;n++) {
		cpp_int value = ackermannFunction(n, n);
		cout << "(" << n << ", " << n << "): " << value << endl;
		total += value;
	}
	cout << "Total: " << total << endl;*/

	cout << ackermannFunction(4, 2) << endl;

	return false;
}
