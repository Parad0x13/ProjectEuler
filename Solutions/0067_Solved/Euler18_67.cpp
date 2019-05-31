// Bryan Anthony Tremblay
// Project Euler problem 18 and 67. Started 09Oct13
/*	The method I used to solve this was to turn the triangle into a 'solve the least difficult
	path' equation that can be easily solved by Dijkstra. This was my first Dijkstra algorithm
	attempt and it's very crude. I wrote a nicer one to use as a library in other projects.
	That code is not used here though. The solver will find the path of least resistance
	starting from the top of the triangle down to an imaginary node that is connected to
	every node on the bottom row. This turns the triangle into a point A to B equation.
	I also had to invert the values since Dijkstra searches for least resistance and the
	problem requested the MOST resistance. I didn't want to use negative values because I
	tried it once and it didn't seem to give correct answers. So instead I settled on something
	that I knew would work with the currently running crude Dijkstra solver	*/
/*	So the day I started this project I gave up after a few hours because the code
	just would not compute the correct answer. Little did I know that at that time
	I had already created a fully functioning Dijkstra solver that in fact had actually
	solved the problem! The issue was that I was formatting the output incorrectly.
	A few days later I decided to write a much cleaner Dijkstra solver (which I did)
	to solve the problems. As soon as I was done writing and testing the solver I
	took a look at my original code again and realized "This should work!". I then
	fixed the output of the code and voila... I got Problem 18 correct. I had to fix
	and add some code to allow the importing of triangles.txt but after almost an hour
	I finally solved problem 67 as well. All without the pretty Dijkstra Solver I built	*/
// Project Euler problem 18 solved 1608KST 16Oct13. I was the 65005th person to have solved this problem
// Project Euler problem 67 solved 1645KST 16Oct13. I was the 47104th person to have solved this problem
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <limits>

#define INF 999999	// I want INT_MAX or something like that...

using namespace std;

string intToString(int integer) {
	stringstream ss;
	ss << integer;
	return ss.str();
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string>elems;
	split(s, delim, elems);
	return elems;
}

template<size_t SZ>
void renderTriangle(int (&numbers)[SZ]) {
	int elementCount = sizeof(numbers) / sizeof(numbers[0]);
	cout << "Element Count: " << elementCount << endl;
	int numbersLeft = elementCount;
	int height = 0;
	while(numbersLeft > 0) {
		height++;
		numbersLeft -= height;
	}
	int largestNumberWidth = 0;
	for(int d=0;d<elementCount;d++) {
		int width = intToString(numbers[d]).size();
		if(width > largestNumberWidth)largestNumberWidth = width;
	}
	int index = 0;
	for(int d=0;d<=height;d++) {
		for(int dd=0;dd<d;dd++) {
			string value = intToString(numbers[index++]);
			while(value.size() < largestNumberWidth)value.insert(0, " ");
			cout << value << ",";
		}
		cout << endl;
	}
}

class Node;
class NodeConnection {
public:
	NodeConnection(Node *a, Node *b, float distance) : a(a), b(b), distance(distance) {
		//
	}
	Node *neighborOf(Node *node) {
		assert(node == a || node == b);
		if(node == a)return b;
		return a;
	}
	Node *a, *b;
	float distance;
};

int globalTag = 100;
class Node {
public:
	Node(float actualDistance) : actualDistance(actualDistance) {tag = globalTag++;name = intToString(tag);};
	Node(string name) : name(name) {tag = globalTag++;}
	void connectOneWay(Node *node, float distance) {
		NodeConnection *connection = new NodeConnection(this, node, distance);
		connections.push_back(connection);
	}
	void connectBothWays(Node *node, float distance) {
		this->connectOneWay(node, distance);
		node->connectOneWay(this, distance);
	}
	float distanceTo(Node *node) {
		NodeConnection *connection;
		for(int d=0;d<connections.size();d++) {
			if(connections[d]->a == this && connections[d]->b == node)connection = connections[d];
			if(connections[d]->b == this && connections[d]->a == node)connection = connections[d];
		}
		if(connection)return connection->distance;
		return INF;
	}
	vector<NodeConnection *>connections;
	int tag;
	float weightedDistance, actualDistance;
	bool visited;
	Node *parent;
	string name;
};

vector<Node *> sequenceOfShortestDistanceInTree(Node *start, Node *end, vector<Node *>nodeTree) {
	for(int d=0;d<nodeTree.size();d++)nodeTree[d]->weightedDistance = INF;
	for(int d=0;d<nodeTree.size();d++)nodeTree[d]->visited = false;
	start->weightedDistance = 0;
	start->visited = true;

	Node *currentNode = start;
	while(currentNode != end) {
		for(int d=0;d<currentNode->connections.size();d++) {
			NodeConnection *connection = currentNode->connections[d];
			Node *neighbor = currentNode->connections[d]->neighborOf(currentNode);
			if(!neighbor->visited) {
				float distance = currentNode->weightedDistance + connection->distance;
				if(distance < neighbor->weightedDistance) {
					neighbor->weightedDistance = distance;
					neighbor->parent = currentNode;
				}
			}
		}
		Node *nextNode = end;
		for(int d=0;d<nodeTree.size();d++) {
			if(nodeTree[d] != currentNode && !nodeTree[d]->visited)
				if(nodeTree[d]->weightedDistance < nextNode->weightedDistance)nextNode = nodeTree[d];
		}
		nextNode->visited = true;
		currentNode = nextNode;
	}

	vector<Node *>sequence;
	sequence.push_back(end);
	currentNode = end;
	while(currentNode != start) {
		sequence.push_back(currentNode->parent);
		currentNode = currentNode->parent;
	}
	reverse(sequence.begin(), sequence.end());

	return sequence;
}

vector<Node *> nodeTreeForTriangle(int *numbers, int count) {
	int elementCount = count;
	int numbersLeft = elementCount;
	int height = 0;
	while(numbersLeft > 0) {
		height++;
		numbersLeft -= height;
	}

	vector<Node *>retVal;
	int tag = 100;
	for(int d=0;d<elementCount;d++)retVal.push_back(new Node(numbers[d]));
	int index = 0;
	for(int level=0;level<height;level++) {
		for(int x=0;x<level;x++) {
			int number = numbers[index];
			Node *currentNode = retVal[index];
			Node *leftNode = NULL, *rightNode = NULL;
			int leftIndex = index + level;
			int rightIndex = index + level + 1;
			if(level < height)leftNode = retVal[leftIndex];
			if(x < level && level < height)rightNode = retVal[rightIndex];
			if(leftNode != NULL)
				currentNode->connectOneWay(leftNode, leftNode->actualDistance);
			if(rightNode != NULL)
				currentNode->connectOneWay(rightNode, rightNode->actualDistance);
			index++;
		}
	}
	Node *finalNode = new Node(0);
	for(int d=0;d<height;d++)
		retVal[elementCount-1-d]->connectOneWay(finalNode, finalNode->actualDistance);
	retVal.push_back(finalNode);

	return retVal;
}

vector<int> inputFile() {
	ifstream fileIn;
	fileIn.open("triangle.txt");

	vector<int>numbers;
	if(fileIn.is_open()) {
		while(fileIn.good()) {
			string numberString;
			getline(fileIn, numberString);
			vector<string>temp = split(numberString, ' ');
			for(int d=0;d<temp.size();d++)
				numbers.push_back(atoi(temp[d].c_str()));
		}
		fileIn.close();
		return numbers;
	}
	else cout << "Unable to open input file" << endl;
}

int main() {
	int triangle1[] = {
	3,
	7,4,
	2,4,6,
	8,5,9,3};
	int triangle2[] = {
	75,
	95,64,
	17,47,82,
	18,35,87,10,
	20, 4,82,47,65,
	19, 1,23,75, 3,34,
	88, 2,77,73, 7,63,67,
	99,65, 4,28, 6,16,70,92,
	41,41,26,56,83,40,80,70,33,
	41,48,72,33,47,32,37,16,94,29,
	53,71,44,65,25,43,91,52,97,51,14,
	70,11,33,28,77,73,17,78,39,68,17,57,
	91,71,52,38,17,14,91,43,58,50,27,29,48,
	63,66, 4,68,89,53,67,30,73,16,69,87,40,31,
	 4,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23};
	vector<int>triangle3Vector = inputFile();
	int *triangle3 = &triangle3Vector[0];
	float invert = 1000;
	int elementCount1 = sizeof(triangle1) / sizeof(triangle1[0]);
	int elementCount2 = sizeof(triangle2) / sizeof(triangle2[0]);
	int elementCount3 = triangle3Vector.size();
	for(int d=0;d<elementCount1;d++)triangle1[d] = invert-triangle1[d];
	for(int d=0;d<elementCount2;d++)triangle2[d] = invert-triangle2[d];
	for(int d=0;d<elementCount3;d++)triangle3[d] = invert-triangle3[d];

	vector<Node *>tree = nodeTreeForTriangle(triangle2, elementCount2);
	Node *first = tree[0];
	Node *last = tree[tree.size()-1];
	vector<Node *>sequence = sequenceOfShortestDistanceInTree(first, last, tree);
	float totalDistance = 0;
	for(int d=0;d<sequence.size();d++)totalDistance += invert-sequence[d]->actualDistance;
	cout << "Problem 18's Distance: " << totalDistance-invert << endl;

	vector<Node *>tree2 = nodeTreeForTriangle(triangle3, elementCount3);
	first = tree2[0];
	last = tree2[tree2.size()-1];
	vector<Node *>sequence2 = sequenceOfShortestDistanceInTree(first, last, tree2);
	totalDistance = 0;
	for(int d=0;d<sequence2.size();d++)totalDistance += invert-sequence2[d]->actualDistance;
	cout << "Problem 67's Distance: " << totalDistance-invert << endl;
}
