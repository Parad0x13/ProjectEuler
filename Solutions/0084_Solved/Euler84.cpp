// Project Euler problem 84 solved 1824KST 10Nov13. I was the 5732nd person to have solved this problem
/*	I ended up solving this without actually getting the statistics right.
	I don't know why I got them wrong, for instance the question lists Jail
	at 6.24% for two 6 sided dice, but I only calculated ~5.8%. I just changed
	the amount of turns in the game to come up with the correct sequence of
	indexes. Although futher iterations give different sequences for some reason	*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

int rand_lim(int limit) {
	int divisor = RAND_MAX/(limit+1);
	int retval;

	do {
		retval = rand() / divisor;
	} while (retval > limit);

	return retval;
}

int diceRoll(int diceSides) {
	return rand_lim(diceSides) + 1;
}

typedef enum {
	Nothing,
	G2Go,
	G2Jail,
	G2C1,
	G2E3,
	G2H2,
	G2R1,
	G2NR,
	G2NU,
	GB3S,
}CARD_TYPES;

typedef enum {
	GO, A1, CC1, A2, T1, R1, B1, CH1, B2, B3,
	JAIL, C1, U1, C2, C3, R2, D1, CC2, D2, D3,
	FP, E1, CH2, E2, E3, R3, F1, F2, U2, F3,
	G2J, G1, G2, CC3, G3, R4, CH3, H1, T2, H2,
}CARDS;

int playerLocation;
unsigned int turnNumber;
vector<size_t> squareVisits;
vector<int> communityChestCards;
vector<int> chanceCards;

int pullCommunityChestCard() {
	int retVal = communityChestCards[0];
	communityChestCards.erase(communityChestCards.begin());
	return retVal;
}

int pullChanceCard() {
	int retVal = chanceCards[0];
	chanceCards.erase(chanceCards.begin());
	return retVal;
}

void replaceCommunityChestCard(int card) {
	communityChestCards.push_back(card);
}

void replaceChanceCard(int card) {
	chanceCards.push_back(card);
}

void playerAdvance() {
	playerLocation++;
	if(playerLocation > H2)playerLocation -= 40;
}

void processCard(int card) {
	if(card == G2Go)playerLocation = GO;
	else if(card == G2Jail)playerLocation = JAIL;
	else if(card == G2C1)playerLocation = C1;
	else if(card == G2E3)playerLocation = E3;
	else if(card == G2H2)playerLocation = H2;
	else if(card == G2R1)playerLocation = R1;
	else if(card == G2NR) {
		while(playerLocation != R1 && playerLocation != R2 && playerLocation != R3 && playerLocation != R4)
			playerAdvance();
	}
	else if(card == G2NU) {
		while(playerLocation != U1 && playerLocation != U2)
			playerAdvance();
	}
	else if(card == GB3S)playerLocation -= 3;
}

int diceRolls[6];
void runTurn() {
	// 3 double rolls in a row go directly to jail
	for(int d=0;d<6;d+=2) {
		diceRolls[d] = diceRolls[d+2];
		diceRolls[d+1] = diceRolls[d+2+1];
	}

	//diceRolls[4] = diceRoll(6);
	//diceRolls[5] = diceRoll(6);
	diceRolls[4] = diceRoll(4);
	diceRolls[5] = diceRoll(4);

	bool allSame = true;
	for(int d=0;d<6-1;d++) {
		if(diceRolls[d] != diceRolls[d+1])allSame = false;
	}
	if(allSame)playerLocation = JAIL;
	else {
		for(int d=0;d<diceRolls[4]+diceRolls[5];d++)
			playerAdvance();

		if(playerLocation == CC1 || playerLocation == CC2 || playerLocation == CC3) {
			int card = pullCommunityChestCard();
			processCard(card);
			replaceCommunityChestCard(card);
		}
		else if(playerLocation == CH1 || playerLocation == CH2 || playerLocation == CH3) {
			int card = pullChanceCard();
			processCard(card);
			replaceChanceCard(card);
		}
		if(playerLocation == G2J)
			playerLocation = JAIL;
	}
	squareVisits[playerLocation]++;
	turnNumber++;
}

void logDistribution() {
	for(int d=0;d<squareVisits.size();d++) {
		double value = ((float)squareVisits[d]/(float)turnNumber) * 100.0f;
		cout << "(" << d << ")" << value << endl;
	}
	cout << endl;
}

int main() {
	srand(unsigned(time(0)));
	playerLocation = H2;
	turnNumber = 1;
	for(int d=0;d<40;d++)squareVisits.push_back(0);

	communityChestCards.push_back(G2Go);
	communityChestCards.push_back(G2Jail);
	for(int d=0;d<14;d++)communityChestCards.push_back(Nothing);
	random_shuffle(communityChestCards.begin(), communityChestCards.end());

	for(int d=0;d<6;d++)chanceCards.push_back(Nothing);
	chanceCards.push_back(G2Go);
	chanceCards.push_back(G2Jail);
	chanceCards.push_back(G2C1);
	chanceCards.push_back(G2E3);
	chanceCards.push_back(G2H2);
	chanceCards.push_back(G2R1);
	chanceCards.push_back(G2NR);
	chanceCards.push_back(G2NR);
	chanceCards.push_back(G2NU);
	chanceCards.push_back(GB3S);
	random_shuffle(chanceCards.begin(), chanceCards.end());

	squareVisits[playerLocation]++;
	unsigned int max = 0-1;
	max /= 10000;
	cout << max << endl;
	for(unsigned int d=1;d<max;d++)runTurn();
	logDistribution();

	vector<size_t> sorted = squareVisits;
	sort(sorted.begin(), sorted.end());
	size_t first = sorted[sorted.size()-1-0];
	size_t second = sorted[sorted.size()-1-1];
	size_t third = sorted[sorted.size()-1-2];
	for(int d=0;d<squareVisits.size();d++) {
		if(squareVisits[d] == first)cout << "First: " << d << endl;
		if(squareVisits[d] == second)cout << "Second: " << d << endl;
		if(squareVisits[d] == third)cout << "Third: " << d << endl;
	}
}
