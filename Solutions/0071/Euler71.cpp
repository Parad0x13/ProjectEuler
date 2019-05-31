/* Project Euler problem 71 started 06Feb14	*/
// I know there is an easier way to calculate this than by brute force...
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	Timer *timer = new Timer();
	timer->start();

	unsigned found = 0;
	unsigned max = 100000;
	for(unsigned n=1;n<=max;n++) {
		for(unsigned d=n;d<=max;d++) {
			if(n < d && GCD(n, d) == 1) {
				found++;
				//cout << n << "/" << d << endl;
			}
		}
	}
	cout << "Found: " << found << " items" << endl;

	timer->stopLog();
	return false;
}
