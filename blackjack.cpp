#ifdef _WIN32
#include <Windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

#include "AsciiCards.h"
#include "P.h"
#include "Player.h"
#include "Dealer.h"
#include "Card.h"
#include "Deck.h"
#include "Game.h"

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

Game InitializeGame(int am) {
	Player p(1000);
	Dealer d("dealer");
	
	Game game(am, p, d);
	game.InitializeDecks();

	return game;
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

bool ValidateBet(string betAmStr, double* betAmD) {
	string validChars = "1234567890";
	bool commaFound = false;
	
	for (char c : betAmStr) {
		if (c == '.') {
			if (commaFound) return false;
			commaFound = true;
			continue;
		}
		if (validChars.find(c) == std::string::npos) return false;
	}

	*betAmD = stod(betAmStr);
	
	if (*betAmD < 0) return false;

	return true;
}

int main(int argc, char *argv[]) {
	
	SetConsoleOutputCP(CP_UTF8);

	cout << "Initializing the game..." << endl;

	int decksAm;

	if (argc >= 2) {
		std::istringstream iss( argv[1] );

		if ((iss >> decksAm) && iss.eof() && decksAm > 0);
		else decksAm = 4;
	}
	else decksAm = 4;
	
	Game game = InitializeGame(decksAm);


	cout << "Decks in game: " << game.cards.size() / 52 << endl;
	cout << "Cards in the game: " << game.cards.size() << endl;

	cout << "Shuffling..." << endl;
	game.Shuffle();

	PrintAllCards(game);

	while(true) {
		string betAmStr;
		double betAmD;

		cout << "Balance: " << game.player.balance << endl;
		cout << "Set bet: ";
		cin >> betAmStr;
		cout << endl;
		
		if (!ValidateBet(betAmStr, &betAmD)) {
			cout << "Invalid bet amount " << betAmStr << endl;
			continue;
		}
		
		if (!game.player.SetBet(betAmD)) {
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
				break;
		}
		cout << "Exiting..." << endl;
		break;
	}

	return 0;

}
