// Project Euler problem 128 started 22Nov13KST
// Worked on 29Jan14KST and 30Jan14KST
/*	I broke each layer into 12 distinct 'groups' where each group had a different rule to determine
	the location in the layer (n starting at 1) and know what were the adjacent 6 tiles were
	to calculate neighbors.	I realized that each layer had exactly 1 tile in each odd numbered
	group starting at the top of the layer and labeling it group 1 and every even
	group consisted of n-2 tiles. I wanted an easy way to know what group an index belonged to and
	couldn't find an equation so I submitted a question to math exchange to help find out:
		http://math.stackexchange.com/questions/577304/equation-to-determine-group-from-index	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

// Max digit in each layer (OEIS_A003215):
//		3n(n+1)+1
// Top digit in each layer (OEIS_A077588):
//		3n^2-3n+2 except when n=0

int maxDigitInLayer(int n) {
	return 3*n*(n+1)+1;
}

int topDigitInLayer(int n) {
	return 3*n*n - 3*n + 2;
}

int layer(int tile) {
	int n = 0;
	for(;;) {
		if(maxDigitInLayer(n) >= tile)
			return n+1;
		n++;
	}
}

int index(int tile) {
	int n = layer(tile);
	int top = topDigitInLayer(n-1);
	int index = tile-top;
	if(index < 0)index = 0;
	//cout << "tile: " << tile << " layer: " << n << " topvalue: " << top << " give index of: " << index << endl;
	return index;
}

int groupsPrecede(int i, int n) {
	return (i+1)/(n+1);
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	for(int tile=20;tile<=37;tile++) {
		int l = layer(tile);
		int n = max(0, l-2);
		int i = index(tile);
		int k = groupsPrecede(i, n);
		int k1 = groupsPrecede(i, n+1);
		int g = -1;
		if(i+1 == k1)g = 2*k+1;
		else if(i+1 > k1)g = 2*k+2;
		cout << "tile " << tile << " is in layer " << l << " with n of " << n << " giving k of " << k << endl;
	}

	timer->stopLog();
	return false;
}
