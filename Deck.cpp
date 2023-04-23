#include "Deck.h"


vector<Card> Deck::CreateDeck() {
	for (int e = 0; e < 4; e++) {
		for (int j = 1; j < 14; j++) {
			Card card;
			card.rank = j;
			card.suit = e;

			deck.push_back(card);
		}
	}
	return deck;
}
