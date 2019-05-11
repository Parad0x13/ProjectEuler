// Project Euler problem 93 started 27Oct13
// There are 11 ways to order parenthesis with 4 terms as given by the 4th Super Catalan number
/*	abcd, (ab)cd, a(bc)d, ab(cd), (ab)(cd), (abc)d, ((ab)c)d, (a(bc))d, a(bcd), a((bc)d), a(b(cd))	*/
// Using {+, -, *, /} There will always be 4^n possible operation sequences where n is one less than the term count
/*	For example A ? B ? C ? D allows for 11 parenthesis orders with
	4^3=64 order possibilities or 64*11=704 possible equations		*/
#include <iostream>
#include <vector>
#include "ProjectEulerTools.h"
#include "confusingParser.h"

using namespace std;
using namespace PET;

template<class T>
vector<T> getAnswers(T _a, T _b, T _c, T _d) {
	vector<T> answers;
	string a = toString(_a);
	string b = toString(_b);
	string c = toString(_c);
	string d = toString(_d);
	int termCount = 4;
	int operationCount = power(4, termCount-1);
	for(int operationNumber=0;operationNumber<operationCount;operationNumber++) {
		string operationSequence = toString(toBase(operationNumber, 4));
		while(operationSequence.size() < 3)operationSequence.insert(0, "0");
		int operation1 = operationSequence[0]-'0';
		int operation2 = operationSequence[1]-'0';
		int operation3 = operationSequence[2]-'0';
		string op1, op2, op3;
		if(operation1 == 0)op1 = "+";
		else if(operation1 == 1)op1 = "-";
		else if(operation1 == 2)op1 = "*";
		else if(operation1 == 3)op1 = "/";
		if(operation2 == 0)op2 = "+";
		else if(operation2 == 1)op2 = "-";
		else if(operation2 == 2)op2 = "*";
		else if(operation2 == 3)op2 = "/";
		if(operation3 == 0)op3 = "+";
		else if(operation3 == 1)op3 = "-";
		else if(operation3 == 2)op3 = "*";
		else if(operation3 == 3)op3 = "/";

		string equation = a+op1+b+op2+c+op3+d;
		answers.push_back(evaluate<T>(equation));
	}
	return answers;
}

int main() {
	vector<double> allAnswers;
	//int max = 36;
	int max = 6;
	// Accidentally checked every combination. Only want to pick from the set of {a, b, c, d} not go through every value
	for(int a=1;a<=max;a++) {
		for(int b=a;b<=max;b++) {
			for(int c=b;c<=max;c++) {
				for(int d=c;d<=max;d++) {
					vector<double> answers = getAnswers<double>(a, b, c, d);
					for(int index=0;index<answers.size();index++)
						allAnswers.push_back(answers[index]);
				}
			}
		}
	}
	sort(allAnswers.begin(), allAnswers.end());
	log(allAnswers);

	return false;
}
