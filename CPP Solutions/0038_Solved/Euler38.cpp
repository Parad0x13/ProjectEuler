// Project Euler problem 38 solved 1557KST 18Oct13. I was the 28560th person to have solved this problem
#include <iostream>
#include "ProjectEulerTools.h"

using namespace std;
using namespace PET;

void findLargestPandigitalMultipleWithDigits(string digitString) {
	long largestN, largestPandigitalMultiple;
	string largestConcatenatedProduct;

	long multiplicand = 1;
	for(;;) {
		long n = 1;
		for(;;) {
			string productString;
			for(int d=1;d<=n;d++)
				productString += toString(multiplicand * d);
			if(productString.size() > digitString.size())break;
			if(productString.size() == digitString.size()) {
				string sortedString = productString;
				sort(sortedString.begin(), sortedString.end());
				if(sortedString == "123456789") {
					if(largestConcatenatedProduct < productString) {
						largestN = n;
						largestPandigitalMultiple = multiplicand;
						largestConcatenatedProduct = productString;
					}
					cout << "Current: " << productString << endl;
					cout << "Largest: " << largestConcatenatedProduct << endl;
				}
			}
			n++;
		}
		// I know the 0.75f is cheating, but I don't really care to optimize right now
		// and the answer is found anyways so... >.> Maybe I'll fix it later
		if(digitCount(multiplicand) >= digitString.size()*0.75f)break;
		multiplicand++;
	}
}

int main() {
	findLargestPandigitalMultipleWithDigits("123456789");
	return false;
}
