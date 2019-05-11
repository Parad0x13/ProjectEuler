// Project Euler problem 58. Started 20Oct13 and solved 1640KST 04Nov13. I was the 18365th person to have solved this problem
/*	Calculating large primes happens to be an issue... Going to try implementing
	Miller Rabin primality test. Yep! After implementing Miller Rabin I solved this
	extremely quickly	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

template<class T>
vector<T> cornerValuesForLayer(T layer) {
	vector<T>retVal;
	// Bottom right edge consists of odd square values
	T size = (layer<<1)-1;
	T oddRoot = ((layer+1)<<1)-1;
	T oddSquare = oddRoot*oddRoot;
	retVal.push_back(oddSquare);				// BR
	retVal.push_back(retVal.back() - size-1);	// BL
	retVal.push_back(retVal.back() - size-1);	// TL
	retVal.push_back(retVal.back() - size-1);	// TR
	return retVal;
}

int main() {
	Timer *timer = new Timer();

	timer->start();
	int cornerPrimes = 0;
	int currentLayer = 1;
	double ratio = 100.0f, prevRatio = ratio;
	while(ratio > 10.0f) {
		unsigned int diagonalCount = currentLayer*4+1;
		vector<long>corners = cornerValuesForLayer<long>(currentLayer);
		for(int corner=0;corner<4;corner++)
			if(isPrime<uint64_t>(corners[corner]))cornerPrimes++;
		ratio = (cornerPrimes/(double)diagonalCount)*100.0f;
		prevRatio = ratio;
		currentLayer++;
	}
	unsigned int length = (currentLayer<<1)-1;
	cout << "Layer " << currentLayer << " has edge length of " << length << " and ratio: " << ratio << endl;
	timer->stopLog();
	return false;
}
