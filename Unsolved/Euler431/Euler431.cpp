// Project Euler problem 431 started 21Nov13
/*	So I decided to attempt a problem well beyond what I though I was capable of, but I'm glad I did.
	I couldn't figure out how to calculate the area above the cone when the cone was off center so I
	submitted a question to http://math.stackexchange.com/questions/575563/area-above-oblique-conical-section
	I spent a long time in Blender making that picture! I also cut out paper versions of the cone to
	try visualizing things using a rubber band as the cross section. That didn't help. My only success
	is using the equations for volume of a cylinder vs volume of a cone to create the volume above a cone
	equation. It's not much but I was able to approximate the number provided on the website at least	*/
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

long double volume_cylinder(long double radius, long double height) {
	return (long double)(M_PI * radius*radius * height);
}

long double volume_aboveCone(long double radius, long double repose) {
	long double height = radius * tan(repose*M_PI/180.0f);
	return (long double)(2.0f/3.0f * M_PI * radius*radius * height);
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	cout << volume_aboveCone(3, 30) << endl;	// Resolution isn't very good, 4 digits?

	timer->stopLog();
	return false;
}
