// Project Euler problem 83 solved 1548KST 06Nov13. I was the 8432nd person to have solved this problem
#include <iostream>
#include "ProjectEulerTools.h"
#include "NodeManager.h"

using namespace std;
using namespace PET;

int main() {
	Timer *timer = new Timer();
	NodeManager *manager = new NodeManager();
	timer->start();

	vector<int> square;

	vector<string> lines = fileLines("matrix.txt");
	//vector<string> lines = fileLines("example_matrix.txt");
	for(int d=0;d<lines.size();d++) {
		string line = lines[d];
		vector<string> nums = PET::split(line, ',');
		for(int d=0;d<nums.size();d++)
			square.push_back(fromString<int>(nums[d]));
	}
	cout << "Node count: " << square.size() << endl;

	int width = sqrt(square.size()), height = width;

	vector<Node *> nodes;

	// Create nodes
	int nameCounter = 1;
	for(int x=0;x<width;x++) {
		for(int y=0;y<height;y++) {
			string name = toString(nameCounter++);
			Node *node = new Node(name);
			nodes.push_back(node);
			manager->addNode(node);
		}
	}
	Node *endNode = new Node("end");
	manager->addNode(endNode);

	// Create connections
	for(int x=0;x<width;x++) {
		for(int y=0;y<height;y++) {
			Node *a = NULL, *b = NULL, *c = NULL, *d = NULL, *e = NULL;
			a = nodes[y*width+x];
			if(x < width-1)b = nodes[y*width+x+1];
			if(x > 0)e = nodes[y*width+x-1];
			if(y < height-1)c = nodes[(y+1)*width+x];
			if(y > 0)d = nodes[(y-1)*width+x];
			if(a != NULL && b != NULL)
				manager->addLink(a->identifier, b->identifier, square[y*width+x], MonoDirectional);
			if(a != NULL && c != NULL)
				manager->addLink(a->identifier, c->identifier, square[y*width+x], MonoDirectional);
			if(a != NULL && d != NULL)
				manager->addLink(a->identifier, d->identifier, square[y*width+x], MonoDirectional);
			if(a != NULL && e != NULL)
				manager->addLink(a->identifier, e->identifier, square[y*width+x], MonoDirectional);
		}
	}
	manager->addLink(nodes.back()->identifier, endNode->identifier, square[width*height-1], MonoDirectional);

	NodeConnectionGroup *shortestRoute = manager->shortestConnectionsBetween(nodes[0]->identifier, endNode->identifier);
	shortestRoute->log();

	timer->stopLog();
	return false;
}
