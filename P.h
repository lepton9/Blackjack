#ifndef P_H
#define P_H

#include "Card.h"
#include <vector>

using std::vector;

class P {
		vector<Card> cards;
		int cardsTotal;
	public:

		vector<Card> getCards();
		void pbToCards(Card card);
		int getCardsTotal();
		void addCardsTotal(int cValue);

		void Reset();
		void PrintAsciiCards();
		void EvalCard(Card* card);
};

#endif
