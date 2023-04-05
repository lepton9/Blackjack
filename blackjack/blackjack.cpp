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
		Card* pulledCard;
		void Shuffle();
		void Swap(Card &c1, Card &c2);
		void InitializeDecks();
		void DrawCard();
		int EvalCard(Card* card);
		int EvalTotal(vector<Card> &cardsOnHand);
		void ResetTable();
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

void Game::DrawCard() {
	Card* lastCard = &cards.back();
	pulledCard = lastCard;
	cards.pop_back();
};

int Game::EvalCard(Card* card) {
	if ((*card).rank == 1) return 11; // Ace
	if ((*card).rank < 10) return (*card).rank;
	else return 10;
};

int Game::EvalTotal(vector<Card> &cardsOnHand) {
	int sum = 0;

	if (cardsOnHand.empty()) return sum;
	for (Card c : cardsOnHand) {
		sum += EvalCard(&c);
	}
	return sum;
};

void Game::ResetTable() {
	player.cards.clear();
	dealer.cards.clear();
};


Game InitializeGame() {
	Game game;
	game.InitializeDecks();
	
	Player p;
	p.balance = 1000;
	game.player = p;

	Dealer d;
	game.dealer = d;

	return game;
};

void PrintStateOfGame(Game &game) {
        cout << "Dealer: " << game.EvalTotal(game.dealer.cards) << endl;
        cout << "Player: " << game.EvalTotal(game.player.cards) << "\n" << endl;
};

void HandleGameEnd(Game &game, int result) {
	if (result < 0) {
		// lose
	}
	if (result > 0) {
		// win
		// check if blackjack
	}
	else {
		// draw
	}
};

void EvalPlayerState(Game &game) {
	if (game.EvalTotal(game.player.cards) <= 21) return;
	else {
		cout << "You bust!" << endl;
		HandleGameEnd(game, -1); // Lose
	}
};

void EvalStateOfGame(Game &game) {
	int playerTotal = game.EvalTotal(game.player.cards);
	int dealerTotal = game.EvalTotal(game.dealer.cards);

	HandleGameEnd(game, playerTotal - dealerTotal);
};

void DealerTurn(Game &game) {
	if (game.EvalTotal(game.dealer.cards) < 17) {
		game.DrawCard();
		game.dealer.cards.push_back(*game.pulledCard);
		cout << "Dealer drew: " << game.EvalCard(game.pulledCard) << endl;
		PrintStateOfGame(game);
	}
};

void PlayerTurn(Game &game) {
	cout << "Hit(h) or stand(s): ";
        char input;
        cin >> input;

        switch (input) {
        case('h'):
                game.DrawCard();
		game.player.cards.push_back(*game.pulledCard);
		PrintStateOfGame(game);
		EvalPlayerState(game);
		break;
        case('s'):
		EvalStateOfGame(game);
                break;
        default:
                break;
	}
};

void Input(Game &game) {
	DealerTurn(game);
	PlayerTurn(game);
};

void Update(Game &game) {

};

void Render(Game &game) {

};

void PrintAllCards(Game game) {
	for (int i = 0; i < game.cards.size(); i++) {
		cout << game.cards[i].rank << ", ";
	}
	cout << endl;
};

int main() {
	cout << "Initializing the game..." << endl;
	
	Game game = InitializeGame();

	cout << "Decks in game: " << game.cards.size() / 52 << endl;
	cout << "Cards in the game: " << game.cards.size() << endl;

	game.Shuffle();


	PrintAllCards(game);
	cout << "Player balance: " << game.player.balance << "\n" << endl;


	while(true) {
		Input(game);
		Update(game);
		Render(game);
	}

	return 0;
}
