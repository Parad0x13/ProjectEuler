// Project Euler problem 61 started 20Nov13 and solved 21Nov13 0820KST. I was the 11518th person to have solved this problem
/*	I would have solved this a day earlier had the site not gone down. However even though I was able
	to calculate the answer, I was unable to ONLY calculate the answer. I also calculated 4 other
	incorrect 'answers' in my code which I couldn't track down why there were being generated. I eventually
	got fed up and by trial and error found the second answer to be correct. I'm not very happy with
	this situation but I decided to look into the forums to exact better ways of solving this equation
	before I played with the code too much and lost a possible correct answer without knowing it, thus
	pushing back the possibility of me solving this equation indefinitely.	*/
#include <iostream>
#include "ProjectEulerTools.h"
#include <assert.h>

using namespace std;
using namespace PET;

typedef enum {
	PREFIX,
	SUFFIX,
}AFFIX_TYPES;

string getAffix(int affixType, string fullString, int affixLength) {
	assert(fullString.size() >= affixLength);
	if(affixType == PREFIX)
		return fullString.substr(0, affixLength);
	else if(affixType == SUFFIX)
		return fullString.substr(fullString.size()-affixLength, affixLength);
}

vector<string> findAffixs(int affixType, string affix, vector<string> strings) {
	vector<string> retVal;
	for(int d=0;d<strings.size();d++) {
		string affixTest = getAffix(affixType, strings[d], affix.size());
		if(affixTest == affix)retVal.push_back(strings[d]);
	}
	return retVal;
}

class Node {
public:
	Node(string value, int index) : value(value), index(index) {parent = NULL;}
	void addChild(Node *child) {
		child->index = index+1;
		child->parent = this;
		children.push_back(child);
	}
	void logName() {cout << "Node(" << index << "): " << value << endl;}
	void log() {
		logName();
		if(children.size() > 0) {
			for(int d=0;d<children.size();d++)
				cout << "\t" << children[d]->value << endl;
		}
		else
			cout << "\tNo Children" << endl;
		for(int d=0;d<children.size();d++)
			children[d]->log();
	}
	vector<Node *> allAtIndex(int _index) {
		vector<Node *> retVal;
		if(index == _index)retVal.push_back(this);
		else {
			for(int d=0;d<children.size();d++) {
				vector<Node *> fromChild = children[d]->allAtIndex(_index);
				for(int dd=0;dd<fromChild.size();dd++)
					retVal.push_back(fromChild[dd]);
			}
		}
		return retVal;
	}
	int index;
	Node *parent;
	vector<Node *> children;
	string value;
};

Node *getChain(string current, int chainIndex, int affixLength, vector<string> toSearch, int canQuitIndex) {
	Node *retVal = new Node(current, chainIndex);
	if(chainIndex > canQuitIndex)return retVal;
	vector<string> fixedSearch = toSearch;
	removeFromVector<string>(current, fixedSearch);
	vector<string> affixs = findAffixs(PREFIX, getAffix(SUFFIX, current, affixLength), fixedSearch);
	vector<string> newSearch = affixs;

	if(newSearch.size() > 0) {
		for(int d=0;d<newSearch.size();d++) {
			Node *child = getChain(newSearch[d], chainIndex+1, affixLength, fixedSearch, canQuitIndex);
			retVal->addChild(child);
		}
	}
	return retVal;
}

vector<string> closedChainList(Node *chain, int endIndex, int affixLength) {
	vector<string> retVal;

	Node *correctNode = NULL;
	string correctSuffix = getAffix(PREFIX, chain->value, affixLength);

	vector<Node *> allAtIndex = chain->allAtIndex(endIndex);
	for(int d=0;d<allAtIndex.size();d++) {
		string currentSuffix = getAffix(SUFFIX, allAtIndex[d]->value, affixLength);
		if(currentSuffix == correctSuffix) {
			correctNode = allAtIndex[d];
			break;
		}
	}

	if(correctNode != NULL) {
		Node *current = correctNode;
		bool shouldContinue = true;
		while(shouldContinue) {
			retVal.push_back(current->value);
			if(current->parent == NULL)shouldContinue = false;
			if(shouldContinue)current = current->parent;
		}
	}

	reverse(retVal.begin(), retVal.end());

	return retVal;
}

vector<string> triangles;
vector<string> squares;
vector<string> pentagonals;
vector<string> hexagonals;
vector<string> heptagonals;
vector<string> octagonals;
bool checkChainList(vector<string> chainList) {
	// Needs to ensure a value from each type of polygonal number is present
	if(commonCount(chainList, triangles) == 0)return false;
	if(commonCount(chainList, squares) == 0)return false;
	if(commonCount(chainList, pentagonals) == 0)return false;
	if(commonCount(chainList, hexagonals) == 0)return false;
	if(commonCount(chainList, heptagonals) == 0)return false;
	if(commonCount(chainList, octagonals) == 0)return false;
	return true;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	vector<string> toSearch;

	// I don't like doing it this way, a much more elegant way to do it is possible
	int value = 0, n = 0;
	while(value < 10000) {
		value = n*(n+1)/2;
		if(value >= 1000 && value <= 9999)triangles.push_back(toString(value));
		n++;
	}
	value = 0, n = 0;
	while(value < 10000) {
		value = n*n;
		if(value >= 1000 && value <= 9999)squares.push_back(toString(value));
		n++;
	}
	value = 0, n = 0;
	while(value < 10000) {
		value = n*(3*n-1)/2;
		if(value >= 1000 && value <= 9999)pentagonals.push_back(toString(value));
		n++;
	}
	value = 0, n = 0;
	while(value < 10000) {
		value = n*(2*n-1);
		if(value >= 1000 && value <= 9999)hexagonals.push_back(toString(value));
		n++;
	}
	value = 0, n = 0;
	while(value < 10000) {
		value = n*(5*n-3)/2;
		if(value >= 1000 && value <= 9999)heptagonals.push_back(toString(value));
		n++;
	}
	value = 0, n = 0;
	while(value < 10000) {
		value = n*(3*n-2);
		if(value >= 1000 && value <= 9999)octagonals.push_back(toString(value));
		n++;
	}
	for(int d=0;d<triangles.size();d++)toSearch.push_back(triangles[d]);
	for(int d=0;d<squares.size();d++)toSearch.push_back(squares[d]);
	for(int d=0;d<pentagonals.size();d++)toSearch.push_back(pentagonals[d]);
	for(int d=0;d<hexagonals.size();d++)toSearch.push_back(hexagonals[d]);
	for(int d=0;d<heptagonals.size();d++)toSearch.push_back(heptagonals[d]);
	for(int d=0;d<octagonals.size();d++)toSearch.push_back(octagonals[d]);
	removeRepeats(toSearch);

	for(int d=0;d<toSearch.size();d++) {
		Node *chain = getChain(toSearch[d], 0, 2, toSearch, 5);
		vector<string> chainList = closedChainList(chain, 5, 2);
		if(chainList.size() > 0) {
			if(checkChainList(chainList)) {
				cout << "Found:" << endl;
				vector<int> nums = fromStrings<int>(chainList);
				cout << "Sum: " << sum(nums) << endl;
			}
		}
	}

	timer->stopLog();
	return false;
}
