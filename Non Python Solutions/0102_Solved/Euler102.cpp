// Project Euler problem 102 solved at 2348KST on 11Oct13. I was the 10688th person to have solved this problem
/* Resources from:
	http://www.blackpawn.com/texts/pointinpoly/
	http://stackoverflow.com/questions/2049582/how-to-determine-a-point-in-a-triangle	*/
// To be honest I still don't understand Barycentric Coordinates... not at all
#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

typedef struct {
	float x, y;
}fPoint;

fPoint fPointWith(float x, float y) {
	fPoint retVal;
	retVal.x = x;
	retVal.y = y;
	return retVal;
}

float sign(fPoint p1, fPoint p2, fPoint p3) {
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool pointInTriangle(fPoint pt, fPoint v1, fPoint v2, fPoint v3) {
	bool b1, b2, b3;
	b1 = sign(pt, v1, v2) < 0.0f;
	b2 = sign(pt, v2, v3) < 0.0f;
	b3 = sign(pt, v3, v1) < 0.0f;
	return ((b1 == b2) && (b2 == b3));
}

class Triangle {
public:
	Triangle(fPoint a, fPoint b, fPoint c) : a(a), b(b), c(c) {}
	fPoint a, b, c;
};

vector<Triangle *> trianglesFromInputFile() {
	ifstream fileIn;
	fileIn.open("triangles.txt");

	vector<Triangle *>triangles;
	if(fileIn.is_open()) {
		string line;
		while(getline(fileIn, line)) {
			vector<string>numbers;
			boost::split(numbers, line, boost::is_any_of(","), boost::token_compress_on);
			assert(numbers.size() == 6);
			Triangle *triangle = new Triangle(
			fPointWith(boost::lexical_cast<float>(numbers[0]), boost::lexical_cast<float>(numbers[1])),
			fPointWith(boost::lexical_cast<float>(numbers[2]), boost::lexical_cast<float>(numbers[3])),
			fPointWith(boost::lexical_cast<float>(numbers[4]), boost::lexical_cast<float>(numbers[5])));
			triangles.push_back(triangle);
		}
	}
	else cout << "Unable to open input file" << endl;

	fileIn.close();
	return triangles;
}

int main() {
	vector<Triangle *>triangles = trianglesFromInputFile();
	int isInsideCount = 0;
	for(int d=0;d<triangles.size();d++) {
		bool isInside = pointInTriangle(fPointWith(0, 0), triangles[d]->a, triangles[d]->b, triangles[d]->c);
		if(isInside)isInsideCount++;
	}
	cout << "Found " << isInsideCount << " triangles that overlap the origin" << endl;
	return false;
}
