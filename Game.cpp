
#ifdef _WIN32
#include <Windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

#include "Game.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


bool gameEnd = false;

Game::Game(int dAm, Player p, Dealer d) {
	decksAm = dAm;
	player = p;
	dealer = d;
}

Game::Game() {
	decksAm = 0;
	gameEnd = true;
	pulledCard = NULL;

}


bool Game::getGameEnd() {return gameEnd;}
void Game::setGameEnd(bool end) {
	gameEnd = end;
}

int Game::getDecksAm() {return decksAm;}
void Game::setDecksAm(int am) {
	decksAm = am;
}


void Game::Shuffle() {
	srand(time(NULL)); // Sets the seed for the rand num generator

	vector<Card>::iterator cardIter = cards.begin();

	for(cardIter; cardIter < cards.end(); cardIter++) {
		srand(time(NULL));
		Swap(*cardIter, *(cardIter + rand()%(cards.end() - cardIter)));
	}
}

void Game::Swap(Card &c1, Card &c2) {
	Card temp = c1;
	c1 = c2;
	c2 = temp;
}

void Game::InitializeDecks() {
	cards.clear();
	for (int i = 0; i < decksAm; i++) {
		Deck deck;
		deck.CreateDeck();
		
		cards.insert(cards.end(), deck.deck.begin(), deck.deck.end());
	}
}

void Game::DrawCard() {
	Card* lastCard = &cards.back();
	pulledCard = lastCard;
	cards.pop_back();
}

void Game::HitPlayer() {
         DrawCard();
         player.pbToCards(*pulledCard);
	 player.EvalCard(pulledCard);
}

void Game::HitDealer() {
	 if (dealer.faceDownCard != NULL) {
		dealer.pbToCards(*dealer.faceDownCard);
		dealer.EvalCard(dealer.faceDownCard);
		dealer.faceDownCard = NULL;
		return;
	 }
         DrawCard();

	 if (dealer.getCards().size() == 1) {
		dealer.faceDownCard = pulledCard;
	 }
	 else {
         	dealer.pbToCards(*pulledCard);
		dealer.EvalCard(pulledCard);
	 }
}

void Game::ResetTable() {
	player.Reset();
	dealer.Reset();
}


void Game::PrintStateOfGame() {
	system(CLEAR);
	dealer.PrintAsciiCards();
        cout << "Dealer: " << dealer.getCardsTotal() << endl;
	player.PrintAsciiCards();
        cout << "Player: " << player.getCardsTotal() << "\n" << endl;
}

bool Game::HandleGameEnd(int result) {
	setGameEnd(true);
	if (result < 0) {
		if (dealer.faceDownCard != NULL) {
			HitDealer();
			PrintStateOfGame();
		}

		cout << "You lost " << player.HandleLose() << endl;;
	}
	else if (result > 0) {
		if (player.getCardsTotal() == 21 && player.getCards().size() == 2) {
			cout << "Blackjack! You won " << player.HandleBJ() << endl;
		}
		else {
			cout << "You won " << player.HandleWin() << endl;;
		}
	}
	else {
		if (player.getCardsTotal() == 21 && dealer.getCardsTotal() == 21) {
			if (player.getCards().size() == 2 && dealer.getCards().size() > 2) {
				cout << "Blackjack! You won " << player.HandleBJ() << endl;
			}
			else if (player.getCards().size() > 2 && dealer.getCards().size() == 2) {
				cout << "Dealer blackjack. You lost " << player.HandleLose() << endl;
			}
		}
		else cout << "Push! Returned " << player.HandlePush() << endl;
	}
	cout << "Current balance: " << player.getBalance() << endl;
	return false;
}

bool Game::EvalPlayerState() {
	if (player.getCardsTotal() <= 21) return true;
	else {
		cout << "You bust!" << endl;
		return HandleGameEnd(-1); // Lose
	}
}

bool Game::EvalDealerState() {
	if (dealer.getCardsTotal() > 21) {
		return HandleGameEnd(1); // Win
	}
	else {
		return EvalStateOfGame();
	}
}

bool Game::EvalStateOfGame() {
	return HandleGameEnd(player.getCardsTotal() - dealer.getCardsTotal());
};

bool Game::DealerTurn() {
	while(dealer.getCardsTotal() < 17) {
		Sleep(1000);
		HitDealer();
		PrintStateOfGame();
	}
	return EvalDealerState();
}

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
		cout << "Stand!" << endl;
		PrintStateOfGame();
		return false;
        default:
                PlayerTurn();
	}
	return false;
}

void Game::ServeFirstCards() {
	HitPlayer();
	HitDealer();
	HitPlayer();
	HitDealer();
}
