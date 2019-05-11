// Project Euler problem 54 started 14Oct13
/*	Resources: http://www.codingthewheel.com/archives/poker-hand-evaluator-roundup/
	http://www.suffecool.net/poker/evaluator.html	*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef enum {
	TIE = 100,
	PLAYER_ONE = 101,
	PLAYER_TWO = 102,
}WINNER_TYPES;

// Clubs, Diamonds, Hearts, then Spades
typedef enum {
	_2C, _3C, _4C, _5C, _6C, _7C, _8C, _9C, _TC, _JC, _QC, _KC, _AC,
	_2D, _3D, _4D, _5D, _6D, _7D, _8D, _9D, _TD, _JD, _QD, _KD, _AD,
	_2H, _3H, _4H, _5H, _6H, _7H, _8H, _9H, _TH, _JH, _QH, _KH, _AH,
	_2S, _3S, _4S, _5S, _6S, _7S, _8S, _9S, _TS, _JS, _QS, _KS, _AS,
}CARD_NAMES;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

map<string, int>card_order;
map<string, int>card_value_order;

bool cardCompare(const string &left, const string &right) {
	return card_order[left] < card_order[right];
}

bool cardValueCompare(const string &left, const string &right) {
	return card_value_order[left] < card_value_order[right];
}

vector<string>royalFlushes;
vector<string>straightFlushes;

class PokerHand {
public:
	PokerHand(vector<string>_cards) : cards(_cards) {
		isRoyalFlush = isStraightFlush = isFourOfAKind = isFullHouse = false;
		isFlush = isStraight = isThreeOfAKind = isTwoPairs = isOnePair = false;
		sort(cards.begin(), cards.end(), cardCompare);
		string cardsInfo = cardString();
		// Royal Flush Search
		for(int d=0;d<royalFlushes.size();d++) {if(cardsInfo == royalFlushes[d])isRoyalFlush = true;}
		// Straight Flush Search
		string values, suits;
		for(int d=0;d<cardsInfo.size();d++) {
			if(d%2==0)values.push_back(cardsInfo[d]);
			else suits.push_back(cardsInfo[d]);
		}
		if(suits == "CCCCC" || suits == "DDDDD" || suits == "HHHHH" || suits == "SSSSS") {
			for(int d=0;d<straightFlushes.size();d++) {
				if(values == straightFlushes[d])
					isStraightFlush = true;
			}
		}
		// 4 of a kind search... to implement
		// need to implement the rest of the hand types too... >.>
	}
	void log() {for(int d=0;d<cards.size();d++)cout << cards[d] << " ";cout << endl;}
	string cardString() {string retVal;for(int d=0;d<cards.size();d++)retVal += cards[d];return retVal;}
	bool isRoyalFlush, isStraightFlush, isFourOfAKind, isFullHouse;
	bool isFlush, isStraight, isThreeOfAKind, isTwoPairs, isOnePair;
private:
	vector<string>cards;
};

vector<PokerHand *>player1Hands;
vector<PokerHand *>player2Hands;

void inputFile() {
	ifstream fileIn;
	fileIn.open("poker.txt");

	if(fileIn.is_open()) {
		string pokerHands;
		while(getline(fileIn, pokerHands)) {
			vector<string>cards = split(pokerHands, ' ');
			vector<string>player1Hand(&cards[0], &cards[5]);
			vector<string>player2Hand(&cards[5], &cards[10]);

			player1Hands.push_back(new PokerHand(player1Hand));
			player2Hands.push_back(new PokerHand(player2Hand));
		}
	}
	else cout << "Unable to open input file" << endl;

	fileIn.close();
}

void setupCardInfo() {
	card_order["2C"] = _2C;
	card_order["3C"] = _3C;
	card_order["4C"] = _4C;
	card_order["5C"] = _5C;
	card_order["6C"] = _6C;
	card_order["7C"] = _7C;
	card_order["8C"] = _8C;
	card_order["9C"] = _9C;
	card_order["TC"] = _TC;
	card_order["JC"] = _JC;
	card_order["QC"] = _QC;
	card_order["KC"] = _KC;
	card_order["AC"] = _AC;

	card_order["2D"] = _2D;
	card_order["3D"] = _3D;
	card_order["4D"] = _4D;
	card_order["5D"] = _5D;
	card_order["6D"] = _6D;
	card_order["7D"] = _7D;
	card_order["8D"] = _8D;
	card_order["9D"] = _9D;
	card_order["TD"] = _TD;
	card_order["JD"] = _JD;
	card_order["QD"] = _QD;
	card_order["KD"] = _KD;
	card_order["AD"] = _AD;

	card_order["2H"] = _2H;
	card_order["3H"] = _3H;
	card_order["4H"] = _4H;
	card_order["5H"] = _5H;
	card_order["6H"] = _6H;
	card_order["7H"] = _7H;
	card_order["8H"] = _8H;
	card_order["9H"] = _9H;
	card_order["TH"] = _TH;
	card_order["JH"] = _JH;
	card_order["QH"] = _QH;
	card_order["KH"] = _KH;
	card_order["AH"] = _AH;

	card_order["2S"] = _2S;
	card_order["3S"] = _3S;
	card_order["4S"] = _4S;
	card_order["5S"] = _5S;
	card_order["6S"] = _6S;
	card_order["7S"] = _7S;
	card_order["8S"] = _8S;
	card_order["9S"] = _9S;
	card_order["TS"] = _TS;
	card_order["JS"] = _JS;
	card_order["QS"] = _QS;
	card_order["KS"] = _KS;
	card_order["AS"] = _AS;

	card_value_order["2"] = 1;
	card_value_order["3"] = 2;
	card_value_order["4"] = 3;
	card_value_order["5"] = 4;
	card_value_order["6"] = 5;
	card_value_order["7"] = 6;
	card_value_order["8"] = 7;
	card_value_order["9"] = 8;
	card_value_order["T"] = 9;
	card_value_order["J"] = 10;
	card_value_order["Q"] = 11;
	card_value_order["K"] = 12;
	card_value_order["A"] = 13;

	royalFlushes.push_back("TCJCQCKCAC");
	royalFlushes.push_back("TDJDQDKDAD");
	royalFlushes.push_back("THJHQHKHAH");
	royalFlushes.push_back("TSJSQSKSAS");

	straightFlushes.push_back("23456");
	straightFlushes.push_back("34567");
	straightFlushes.push_back("45678");
	straightFlushes.push_back("56789");
	straightFlushes.push_back("6789T");
	straightFlushes.push_back("789TJ");
	straightFlushes.push_back("89TJQ");
	straightFlushes.push_back("9TJQK");
	straightFlushes.push_back("TJQKA");
}

int main() {
	setupCardInfo();
	inputFile();
	player1Hands[0]->log();
	player2Hands[0]->log();
	return false;
}
