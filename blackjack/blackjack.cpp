#include <iostream>
#include <ctime>
#include <vector>

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
		vector<Card> deck;
		vector<Card> CreateDeck();
		void Shuffle(Card* c1, Card* c2);
};

vector<Card> Deck::CreateDeck() {
	for (int e = hearts; e != last; e++) {
		for (int j = 1; j < 14; j++) {
			Card card;
			card.rank = j;
			card.suit = e;

			deck.push_back(card);
		}
	}
	return deck;
};


void PrintAllCardsInDeck(Deck &d) {
	for (Card c : d.deck) {
		cout << c.SuitToString() << " " << c.rank << endl;
	}
}

class Game {
	public:
		vector<Card> cards;
		void Shuffle();
		void Swap(Card &c1, Card &c2);
		void InitializeDecks();
		Card DrawCard();
};

void Game::Shuffle() {
	srand(time(NULL)); // Sets the seed for the rand num generator

	vector<Card>::iterator cardIter = cards.begin();

	for(cardIter; cardIter < cards.end(); cardIter++) {
		srand(time(NULL));
		Swap(*cardIter, *(cardIter + rand()%(cards.end() - cardIter)));
	}
};

void Game::Swap(Card &c1, Card &c2) {
	Card temp = c1;
	c1 = c2;
	c2 = temp;
};

void Game::InitializeDecks() {
	for (int i = 0; i < 4; i++) {
		Deck deck;
		vector<Card> fullDeck = deck.CreateDeck();
		
		cards.insert(cards.end(), fullDeck.begin(), fullDeck.end());
	}
};

Card Game::DrawCard() {
	Card* pulledCard = &cards.back();
	cards.pop_back();
	
	return *pulledCard;
};

void Initialize() {

};

void Input() {
};

void Update() {
};

void Render() {
};

void PrintAllCards(Game game) {
	for (int i = 0; i < game.cards.size(); i++) {
		cout << game.cards[i].rank << endl;
	}
};

int main() {
	cout << "Initializing the game..." << endl;
	
	Game game;
	game.InitializeDecks();
	
	cout << "Decks in game: " << game.cards.size() / 52 << endl;
	cout << "Cards in the game: " << game.cards.size() << endl;

	game.Shuffle();


	PrintAllCards(game);
	cout << "Last card: " << game.DrawCard().rank << endl;

	return 0;
}
