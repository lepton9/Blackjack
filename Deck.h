#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

using std::vector;

class Deck {
	public:
		vector<Card> deck;
		vector<Card> CreateDeck();
};

#endif
