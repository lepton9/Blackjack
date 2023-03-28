#include <iostream>
using namespace std;

enum Suit { hearts, diamonds, clubs, spades, last };

class Card {
	public:
		int suit;
		int rank;
};


class Deck {
	public:
		Card deck[52];
		//Card* deck = cards; // Points to the first element of the array
		void CreateDeck();
		void Shuffle();
};

void Deck::CreateDeck() {
	for (int e = hearts; e != last; e++) {
		for (int j = 1; j < 14; j++) {
			Card card;
			card.rank = j;
			card.suit = e;
			*(deck + e*13 + j) = card;
		}
	}	
};

void Deck::Shuffle() {

};

int main() {
	cout << "Making the deck" << endl;
	Deck d;
	d.CreateDeck();
	cout << d.deck << endl;
	for (Card c : d.deck) {
		cout << c.suit << " " << c.rank << endl;
	}
	cout << d.deck[52].suit << " " << d.deck[52].rank << endl;
	cout << (sizeof(d.deck) / sizeof(int)) / 2;
	return 0;
}
