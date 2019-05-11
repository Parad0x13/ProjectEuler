// Project Euler problem 39 solved 1055KST Oct2513. I was the 33295th person to have solved this problem
#include <iostream>
#include <vector>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

typedef enum {
	TRIANGLE,
	EUCLID,
}tripleTypes;

template<class T>
class triple {
public:
	triple(T one, T two, T three, int type) {
		if(type == TRIANGLE) {
			T a, b, c;
			a = one;
			b = two;
			c = three;
			values.push_back(a);
			values.push_back(b);
			values.push_back(c);
		}
		else if(type == EUCLID) {
			T m = one;
			T n = two;
			T k = three;
			T a = k * (m * m - n * n);
			T b = k * (m * n)<<1;
			T c = k * (m * m + n * n);
			values.push_back(a);
			values.push_back(b);
			values.push_back(c);
		}
	}
	T perimeter() {
		return values[0]+values[1]+values[2];
	}
	bool isEqualTo(triple input) {
		for(int d=0;d<values.size();d++) {
			if(values[d] != input.values[d])return false;
		}
		return true;
	}
	void log() {
		cout << "triple(" << values[0] << ", " << values[1] << ", " << values[2] << ")" << endl;
	}
	vector<T>values;
};

// Resources: http://en.wikipedia.org/wiki/Pythagorean_triple
template<class T>
vector<triple<unsigned long> > triplesFor(T perimeter) {
	//	Since perimeter = 2m^2 +2mn I can check up to the square of m since
	//	any value greater will make one edge of the triangle longer than the
	//	perimeter to be searched for
	int mMax = sqrt(perimeter);
	int nMax = mMax;
	int kMax = mMax;	// Not sure what this is supposed to be... but setting to sqrt(perimeter) worked. I just don't know why it worked
	vector<triple<unsigned long> >triples;
	for(int n=1;n<=nMax;n++) {
		for(int m=1;m<=mMax;m++) {
			for(int k=1;k<=kMax;k++) {
				if(m>n && isOdd(m-n) && isCoprime(m, n)) {
					triple<unsigned long>triangle(m, n, k, EUCLID);
					// Explore why the perimeter is so large for most of the time!
					// Can severely decrease computation time if I knew why
					if(triangle.perimeter() == perimeter) {
						triples.push_back(triangle);
						cout << "Perimeter: " << perimeter << ") Found: ";
						triangle.log();
					}
				}
			}
		}
	}
	return triples;
}

int main() {
	int rangeMax = 1000;
	int maxTripleNumber = 0, maxTripleCount = 0;
	for(int d=3;d<=rangeMax;d++) {
		vector<triple<unsigned long> >triples = triplesFor(d);
		if(triples.size() > maxTripleCount) {
			maxTripleCount = triples.size();
			maxTripleNumber = d;
		}
	}
	cout << "Found " << maxTripleNumber << " creates " << maxTripleCount << " triples" << endl;

	return false;
}
