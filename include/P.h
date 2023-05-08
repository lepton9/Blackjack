#ifndef P_H
#define P_H

#include "Card.h"
#include <vector>
#include <string>

using std::vector;

class P {
		vector<Card> cards;
		int cardsTotal;
		vector<vector<string>> asciiCards;
	public:

		vector<Card> getCards();
		void pbToCards(Card card);
		int getCardsTotal();
		void addCardsTotal(int cValue);

		void Reset();
		void PrintAsciiCards();
		vector<vector<string>>* GetAsciiCards();
		void EvalCard(Card* card);
};

#endif
