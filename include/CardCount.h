#ifndef CARDCOUNT_H
#define CARDCOUNT_H

#include <sstream>
#include "Card.h"

class CardCount {
			      //   1   2   3   4   5   6   7  8    9   10 J Q K
	//const int cValues[10] = {-60, 37, 45, 52, 70, 46, 27, 0, -17, -50}; // Griffin Ultimate
	const int cValues[10] = {-1, 1, 1, 1, 1, 1, 0, 0, 0, -1}; // Hi Lo

	int deckAmStart;
	double decksRem;
	int cAmount;
	
	int runCount;
	double trueCount;
	
	bool stop;

	Card** pulledCard;
	Card* lastCard;
	
	public:
		COORD writePos = {0, 0};

		CardCount(int dAm, Card** pCard);
		//CardCount(int dAm, BlackJack bj);

		int getRunCount();
		double getTrueCount();
		int getDecksAm();
		void update(int cValue);
		void calcRunCount(int cardValue);
		void calcTrueCount();
		double calcDecksRem();
		void PrintCountState();
		void inputCard(int cardValue);
		int evalCard();
		void run();
		void Reset();
		void stopTrue();
};

#endif
