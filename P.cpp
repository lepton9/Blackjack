#include "P.h"
#include "AsciiCards.h"
#include <iostream>

using std::cout;
using std::endl;

//int cardHeight = GetAsciiCard().size();
int cardHeight = 6;
int cardsTotal = 0;

void P::Reset() {
	cards.clear();
	cardsTotal = 0;
}

void P::PrintAsciiCards() {
	vector<vector<string>> asciiCards;
	for (Card card : cards) {
		asciiCards.push_back(GetAsciiCard(card.suit, card.rank));
	}
	if (asciiCards.size() < 2) {
		asciiCards.push_back(GetAsciiCard()); // Blank card
	}

	for (int i = 0; i < cardHeight; i++) {
		for (vector<string> asciiCard : asciiCards) {
			cout << asciiCard[i];
		}
		cout << endl;
	}
}


void P::EvalCard(Card* card) {
	if ((*card).rank == 1) { // Ace
		if (cardsTotal + 11 > 21) {
			cardsTotal += 1;
			return;
		}
		cardsTotal += 11;
		return;
	}
	if ((*card).rank < 10) cardsTotal += (*card).rank;
	else cardsTotal += 10;
}
