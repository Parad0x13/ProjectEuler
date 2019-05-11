// Project Euler problem 45 solved 1632KST 22Oct13. I was the 34326th person to have solved this problem
/*	I initially ended up solving this problem by finding the NEXT
	triangle/pentagonal/hexagonal pair as well. My code is slow lol
	Reading on the forums it seems this equation has some roots in
	diophantine equations. More research needed		*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

int main() {
	size_t count = 60000;		// Guessed value
	vector<size_t>triangles = firstTriangleNumbers<size_t>(count);
	vector<size_t>pentagonals = firstPentagonalNumbers<size_t>(count);
	vector<size_t>hexagonals = firstHexagonalNumbers<size_t>(count);

	vector<size_t>common;
	for(size_t d=0;d<count;d++) {
		if(existsIn(triangles[d], pentagonals) && existsIn(triangles[d], hexagonals))
			common.push_back(triangles[d]);
	}
	log(common);
	return false;
}
