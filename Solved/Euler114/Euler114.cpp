// Project Euler problem 114 solved 1325KST 12Nov13. I was the 5319th person to have solved this problem
/*	I was astounded when I clicked the check answer button and found I had got it correct
	I didn't expect that the sequence I had found (http://oeis.org/A005252) was the right one.
	I still have no idea why this sequence is correct but by experimenting I was able to solve it	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	Timer *timer = new Timer();
	timer->start();

	vector<uint64_t> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	for(int n=4;n<60;n++)a.push_back(2*a[n-1]-a[n-2]+a[n-4]);
	cout << a[50+1] << endl;

	timer->stopLog();
	return false;
}
