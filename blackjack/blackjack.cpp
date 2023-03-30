#include <iostream>
using namespace std;

enum Suit { hearts, diamonds, clubs, spades, last };

class Card {
	public:
		unsigned int suit;
		unsigned int rank;
		string SuitToString();
};

string Card::SuitToString() {
	switch(suit) {
		case(0):
			return "hearts";
		case(1):
			return "diamonds";
		case(2):
			return "clubs";
		case(3):
			return "spades";
		default:
			return "";
	}
}


class Deck {
	public:
		Card deck[52];
		//Card* deck = cards; // Points to the first element of the array
		void CreateDeck();
		void Shuffle(Card* c1, Card* c2);
};

void Deck::CreateDeck() {
	for (int e = hearts; e != last; e++) {
		for (int j = 1; j < 14; j++) {
			Card card;
			card.rank = j;
			card.suit = e;
			deck[e*13 + j - 1] = card;
		}
	}	
};

void Deck::Shuffle(Card* firstCard, Card* lastCard) {
	for (int i = (lastCard-firstCard)-1; i>0; i--) {

	}

};

void PrintAllCards(Deck d) {
	for (Card c : d.deck) {
		cout << c.SuitToString() << " " << c.rank << endl;
	}
}

int main() {
	cout << "Making the deck" << endl;
	Deck d;
	d.CreateDeck();
	cout << d.deck << endl;
	PrintAllCards(d);

	cout << "Cards in the deck: " << (sizeof(d.deck) / sizeof(int)) / 2;
	
	//random_shuffle(&d.deck(0, &d.deck[51]))

	return 0;
}
