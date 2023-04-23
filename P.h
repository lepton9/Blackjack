#ifndef P_H
#define P_H

#include "Card.h"
#include <vector>

using std::vector;

class P {
	
	public:
		vector<Card> cards;
		int cardsTotal;

		void Reset();
		void PrintAsciiCards();
		void EvalCard(Card* card);
};

#endif
