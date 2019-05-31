// Project Euler problem 54 started 14Oct13 and solved 1654KST 14Nov13. I was the 15865th person to have solved this problem
// This question advanced me to level 3. At the time only 11990 members (3.52%) had made it that far
/*	Resources: http://www.codingthewheel.com/archives/poker-hand-evaluator-roundup/
	http://www.suffecool.net/poker/evaluator.html	*/
/*	At first I tried to make my own poker hand checker but that... was very very hard
	since I tried to do it by checking each card after sorting etc... I finally decided
	to use the Cactus Kiv method and although I ran into a few issues it fell together
	pretty easily. I did not make this for speed so relatively speaking it's a very slow
	poker hand solver. I don't like the fact that I have to use precomputed arrays though	*/
#include <iostream>
#include <bitset>
#include <map>
#include "ProjectEulerTools.h"
#include "arrays.h"

using namespace std;
using namespace PET;

vector<vector<string> >player1Hands;
vector<vector<string> >player2Hands;
void loadHands() {
	vector<string> lines = fileLines("poker.txt");
	for(int d=0;d<lines.size();d++) {
		vector<string> cards = split(lines[d], ' ');
		vector<string> player1;
		vector<string> player2;
		for(int dd=0;dd<5;dd++)player1.push_back(cards[dd]);
		cards.erase(cards.begin()+0, cards.begin()+5);
		for(int dd=0;dd<5;dd++)player2.push_back(cards[dd]);
		player1Hands.push_back(player1);
		player2Hands.push_back(player2);
	}
}

map<char, int>rank_bitmask;
map<char, int>suit_bitmask;
map<char, int>card_rank;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

uint32_t toCard(string input) {
	assert(input.size() == 2);
	char rank = input[0];
	char suit = input[1];

	uint32_t rank_mask = rank_bitmask[rank]<<16;
	uint32_t suit_mask = suit_bitmask[suit]<<12;
	uint32_t card_rank_mask = card_rank[rank]<<8;
	uint32_t prime_mask = primes[card_rank[rank]]<<0;

	return rank_mask | suit_mask | card_rank_mask | prime_mask;
}

void logCard(uint32_t card) {
	cout << bitset<3>(card>>(8*3)+5);
	cout << "[" << bitset<5>(card>>(8*3)) << " ";
	cout << bitset<8>(card>>(8*2)) << "] ";
	cout << "[" << bitset<4>(card>>(8*1)+4) << "]";
	cout << "[" << bitset<4>(card>>(8*1)) << "] ";
	cout << bitset<2>(card>>(8*0)+6);
	cout << "[" << bitset<6>(card>>(8*0)) << "]" << endl;
}

void logHand(uint32_t *hand) {
	for(int d=0;d<5;d++)logCard(hand[d]);
}

uint32_t *handWith(string a, string b, string c, string d, string e) {
	uint32_t *retVal = new uint32_t[5];
	retVal[0] = toCard(a);
	retVal[1] = toCard(b);
	retVal[2] = toCard(c);
	retVal[3] = toCard(d);
	retVal[4] = toCard(e);
	return retVal;
}

int evaluateHand(uint32_t *hand) {
	uint32_t flush = hand[0] & hand[1] & hand[2] & hand[3] & hand[4] & 0xF000;
	uint32_t lookupIndex = (hand[0] | hand[1] | hand[2] | hand[3] | hand[4]) >> 16;
	if(flush != 0)return flushes[lookupIndex];
	if(unique5[lookupIndex] != 0)return unique5[lookupIndex];
	int32_t product = (hand[0]&0xFF) * (hand[1]&0xFF) * (hand[2]&0xFF) * (hand[3]&0xFF) * (hand[4]&0xFF);
	int productsSize = sizeof(products)/sizeof(products[0]);
	int productIndex;
	for(int d=0;d<productsSize;d++) {
		if(products[d] == product) {
			productIndex = d;
			break;
		}
	}
	return values[productIndex];
}

void setupMaps() {
	rank_bitmask['2'] = 1;card_rank['2'] = 0;
	rank_bitmask['3'] = 2;card_rank['3'] = 1;
	rank_bitmask['4'] = 4;card_rank['4'] = 2;
	rank_bitmask['5'] = 8;card_rank['5'] = 3;
	rank_bitmask['6'] = 16;card_rank['6'] = 4;
	rank_bitmask['7'] = 32;card_rank['7'] = 5;
	rank_bitmask['8'] = 64;card_rank['8'] = 6;
	rank_bitmask['9'] = 128;card_rank['9'] = 7;
	rank_bitmask['T'] = 256;card_rank['T'] = 8;
	rank_bitmask['J'] = 512;card_rank['J'] = 9;
	rank_bitmask['Q'] = 1024;card_rank['Q'] = 10;
	rank_bitmask['K'] = 2048;card_rank['K'] = 11;
	rank_bitmask['A'] = 4096;card_rank['A'] = 12;

	suit_bitmask['C'] = 8;
	suit_bitmask['D'] = 4;
	suit_bitmask['H'] = 2;
	suit_bitmask['S'] = 1;
}

int main() {
	Timer *timer = new Timer();
	timer->start();

	setupMaps();

	int player1Wins = 0;
	loadHands();
	for(int d=0;d<player1Hands.size();d++) {
		uint32_t *p1Hand = handWith(player1Hands[d][0], player1Hands[d][1], player1Hands[d][2], player1Hands[d][3], player1Hands[d][4]);
		uint32_t *p2Hand = handWith(player2Hands[d][0], player2Hands[d][1], player2Hands[d][2], player2Hands[d][3], player2Hands[d][4]);
		int p1Eval = evaluateHand(p1Hand);
		int p2Eval = evaluateHand(p2Hand);
		if(p1Eval < p2Eval)player1Wins++;
	}
	cout << player1Wins << endl;

	timer->stopLog();
	return false;
}
