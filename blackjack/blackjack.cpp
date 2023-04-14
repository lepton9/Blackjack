#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <ctime>
#include <vector>
#include "AsciiCards.h"

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
			return "clubs";
		case(1):
			return "diamonds";
		case(2):
			return "hearts";
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


class P {
	public:
		vector<Card> cards;
		int cardsTotal = 0;

		void PrintAsciiCards() {
			int cardHeight = 5;
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
		};


		void EvalCard(Card* card) {
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
		};

};

class Player : public P {
        public:
                double balance = 1000;
		double bet = 0;

		bool SetBet(double amount) {
			if (balance >= amount) {
				bet = amount;
				balance -= amount;
				return true;
			}
			return false;
		}

		double HandleWin() {
			double am = 2*bet;
			balance += am;
			bet = 0;
			return am;
		}
		double HandleBJ() {
			double am = 2.5*bet;
			balance += am;
			bet = 0;
			return am;
		}
		double HandleLose() {
			double am = bet;
			bet = 0;
			return am;
		}
		double HandlePush() {
			double am = bet;
			balance += am;
			bet = 0;
			return am;
		}
};

class Dealer : public P {
        public:
                string dealerName = "dealer";
		Card* faceDownCard = NULL;
};


class Game {
	public:
		Dealer dealer;
		Player player;
		vector<Card> cards;
		Card* pulledCard;
		bool gameEnd = false;

		void Shuffle();
		void Swap(Card &c1, Card &c2);
		void InitializeDecks();
		void DrawCard();
		void HitPlayer();
		void HitDealer();
		int EvalCard(Card* card);
		int EvalTotal(vector<Card> &cardsOnHand);
		bool HandleGameEnd(int result);
		bool EvalPlayerState();
		bool EvalDealerState();
		bool EvalStateOfGame();
		bool DealerTurn();
		bool PlayerTurn();
		void ServeFirstCards();

		void PrintStateOfGame();
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
	cards.clear();
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

void Game::HitPlayer() {
         DrawCard();
         player.cards.push_back(*pulledCard);
	 player.EvalCard(pulledCard);
};

void Game::HitDealer() {
	 if (dealer.faceDownCard != NULL) {
		dealer.cards.push_back(*dealer.faceDownCard);
		dealer.EvalCard(dealer.faceDownCard);
		dealer.faceDownCard = NULL;
		return;
	 }
         DrawCard();

	 if (dealer.cards.size() == 1) {
		dealer.faceDownCard = pulledCard;
	 }
	 else {
         	dealer.cards.push_back(*pulledCard);
		dealer.EvalCard(pulledCard);
	 }
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
	game.player = p;

	Dealer d;
	game.dealer = d;

	return game;
};

void Game::PrintStateOfGame() {
	system("clear");
	dealer.PrintAsciiCards();
        cout << "Dealer: " << EvalTotal(dealer.cards) << endl;
	player.PrintAsciiCards();
        cout << "Player: " << EvalTotal(player.cards) << "\n" << endl;
};

bool Game::HandleGameEnd(int result) {
	gameEnd = true;
	if (result < 0) {
		if (dealer.faceDownCard != NULL) {
			HitDealer();
			PrintStateOfGame();
		}

		cout << "You lost " << player.HandleLose() << endl;;
	}
	else if (result > 0) {
		if (EvalTotal(player.cards) == 21) {
			cout << "Blackjack! You won " << player.HandleBJ() << endl;
		}
		else {
			cout << "You won " << player.HandleWin() << endl;;
		}
	}
	else {
		cout << "Push! Returned " << player.HandlePush() << endl;;
	}

	return false;
};

bool Game::EvalPlayerState() {
	if (EvalTotal(player.cards) <= 21) return true;
	else {
		cout << "You bust!" << endl;
		return HandleGameEnd(-1); // Lose
	}
};

bool Game::EvalDealerState() {
	if (EvalTotal(dealer.cards) > 21) {
		return HandleGameEnd(1); // Win
	}
	else {
		return EvalStateOfGame();
	}
};

bool Game::EvalStateOfGame() {
	int playerTotal = EvalTotal(player.cards);
	int dealerTotal = EvalTotal(dealer.cards);

	return HandleGameEnd(playerTotal - dealerTotal);
};

bool Game::DealerTurn() {
	while(EvalTotal(dealer.cards) < 17) {
		Sleep(1000);
		HitDealer();
		PrintStateOfGame();
	}
	return EvalDealerState();
};

bool Game::PlayerTurn() {

	if (!EvalPlayerState()) {
		return false;
	}

	cout << "Hit(h) or stand(s): ";
        char input;
        cin >> input;

        switch (input) {
        case('h'):
		cout << "Hit!" << endl;
                HitPlayer();
		PrintStateOfGame();
		return EvalPlayerState();
        case('s'):
		cout << "Stand" << endl;
		PrintStateOfGame();
		return false;
        default:
                return false;
	}
};

void Game::ServeFirstCards() {
	HitPlayer();
	HitDealer();
	HitPlayer();
	HitDealer();
};


void Input(Game &game) {

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

void Begin(Game &game) {
	if (game.cards.size() < 20) {
		cout << "Shuffling new set of decks..." << endl;
		game.InitializeDecks();
		game.Shuffle();
		Sleep(1000);
	}

	game.ServeFirstCards();
	game.PrintStateOfGame();
	while(game.PlayerTurn());
	if (!game.gameEnd) game.DealerTurn();
};

void NewGame(Game &game) {
	game.gameEnd = false;
	game.ResetTable();
	Begin(game);
};

int main() {
	cout << "Initializing the game..." << endl;
	
	Game game = InitializeGame();

	cout << "Decks in game: " << game.cards.size() / 52 << endl;
	cout << "Cards in the game: " << game.cards.size() << endl;

	cout << "Shuffling..." << endl;
	game.Shuffle();


	PrintAllCards(game);

	while(true) {
		string betAmStr;
		int betAm;

		cout << "Balance: " << game.player.balance << endl;
		cout << "Set bet: ";
		cin >> betAmStr;
		cout << endl;

		try {
			betAm = stod(betAmStr);
		}
		catch (...) {
			cout << "Invalid bet amount!" << endl;
			continue;
		}

		if (!game.player.SetBet(betAm)) {
			cout << "Not enough money to bet " << betAmStr << endl;
			continue;
		}

		NewGame(game);
	
		char ng;
		cout << "New game? [y/n]: ";
		cin >> ng;
		cout << endl;

		switch(ng) {
			case('y'):
				continue;
			case('n'):
				cout << "Exiting..." << endl;
				break;
			default:
				break;
		}
		break;
	}

	return 0;

}
