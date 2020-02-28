// Project Euler problem 66 solved 1642KST 28Jan14. I was the 9308th person to have solved this problem.
#include <iostream>
#include "ProjectEulerTools.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace PET;
using namespace boost::multiprecision;

int main() {
	Timer *timer = new Timer();
	timer->start();

	cpp_int largestD = 0, largestX = 0;
	for(int D=2;D<=1000;D++) {
		if(!isPerfectSquare<int64_t>(D)) {
			vector<cpp_int> solution = fundamentalSolutionOfPellsEquationForSqrt<cpp_int>(D);
			if(solution[0] > largestX) {
				largestD = D;
				largestX = solution[0];
			}
			cout << "D(" << D << "): " << solution[0] << "/" << solution[1] << endl;
		}
	}
	cout << "Largest D happen to be " << largestD << endl;

	timer->stopLog();
	return false;
}
