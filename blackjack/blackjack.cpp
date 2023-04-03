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

class Player {
        public:
                int balance;
                vector<Card> cards;
};

class Dealer {
        public:
                vector<Card> cards;
};

class Game {
	public:
		Dealer dealer;
		Player player;
		vector<Card> cards;
		void Shuffle();
		void Swap(Card &c1, Card &c2);
		void InitializeDecks();
		Card DrawCard();
		int EvalCard(Card* card);
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
		deck.CreateDeck();
		
		cards.insert(cards.end(), deck.deck.begin(), deck.deck.end());
	}
};

Card Game::DrawCard() {
	Card* pulledCard = &cards.back();
	cards.pop_back();
	
	return *pulledCard;
};

int Game::EvalCard(Card* card) {
	if ((*card).rank < 10) return (*card).rank;
	else return 10;
};


Game Initialize() {
	Game game;
	game.InitializeDecks();
	game.player.balance = 1000;
	return game;
};

void Input(Game &game) {
	cout << "Draw(d) or stand(s): ";
	char input;
	cin >> input;

	switch (input) {
	case('d'):
		game.DrawCard();

	case('s'):
		break;
	default:
		break;
	}
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
	
	Game game = Initialize();
	game.Shuffle();
	cout << "Decks in game: " << game.cards.size() / 52 << endl;
	cout << "Cards in the game: " << game.cards.size() << endl;

	//game.Shuffle();


	PrintAllCards(game);
	cout << "Last card: " << game.DrawCard().rank << endl;

	return 0;
}
