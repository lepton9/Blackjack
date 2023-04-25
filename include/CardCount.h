#ifndef CARDCOUNT_H
#define CARDCOUNT_H

#include "Card.h"

class CardCount {
			      //   1   2   3   4   5   6   7  8    9   10 J Q K
	const int cValues[10] = {-60, 37, 45, 52, 70, 46, 27, 0, -17, -50};

	int deckAmStart;
	double decksRem;
	int cAmount;
	
	int runCount;
	double trueCount;

	Card** pulledCard;
	Card* lastCard;
	
	public:

		CardCount(int dAm, Card** pCard);

		int getRunCount();
		double getTrueCount();
		int getDecksAm();
		void update(int cValue);
		int calcRunCount(int cardValue);
		double calcTrueCount();
		double calcDecksRem();
		void PrintCountState();
		void inputCard(int cardValue);
		int evalCard();
		void run();
};

#endif
