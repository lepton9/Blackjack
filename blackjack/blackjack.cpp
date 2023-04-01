#include <iostream>
#include <ctime>
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


void PrintAllCards(Deck &d) {
	for (Card c : d.deck) {
		cout << c.SuitToString() << " " << c.rank << endl;
	}
}

class Game {
	public:
		Deck decks[4];
		void Shuffle();
		void Swap(Card &c1, Card &c2);
		void InitializeDecks();
		Card DrawCard();
};

void Game::Shuffle() {
	srand(time(NULL)); // Sets the seed for the rand num generator
	int maxCards = (sizeof(decks) / sizeof(Card));
	Card *pfCard = &decks[0].deck[0]; // Points to the first card of the first deck
	for(int ci = 0; ci < maxCards; ci++) {
		Swap(*(pfCard + ci), *(pfCard + (rand()%(maxCards - ci + 1) + ci)));
	}	
};

void Game::Swap(Card &c1, Card &c2) {
	Card temp = c1;
	c1 = c2;
	c2 = temp;
};

void Game::InitializeDecks() {
	for (int i = 0; i < 4; i++) {
		Deck d;
		d.CreateDeck();
		decks[i] = d;
	}
};

Card Game::DrawCard() {

};

void Initialize() {

};

void processInput() {
};

void Update() {
};

void Render() {
};

int main() {
	cout << "Initializing the game..." << endl;
	
	Game game;
	game.InitializeDecks();

	cout << "Decks in game: " << (sizeof(game.decks) / sizeof(Deck)) << endl;
	cout << "Cards in game: " << (sizeof(game.decks) / sizeof(Card)) << endl;
	
	game.Shuffle();

	return 0;
}
