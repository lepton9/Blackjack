#ifndef GAME_H
#define GAME_H


#include "Player.h"
#include "Dealer.h"
#include "Card.h"
#include "Deck.h"

#include <vector>

using std::vector;

class Game {
		bool gameEnd;
		int decksAm;

	public:
		Dealer dealer;
		Player player;
		vector<Card> cards;
		Card* pulledCard;
	
		Game(int dAm, Player p, Dealer d);
		Game();

		bool getGameEnd();
		void setGameEnd(bool end);

		int getDecksAm();
		void setDecksAm(int am);

		void Shuffle();
		void Swap(Card &c1, Card &c2);
		void InitializeDecks();
		void DrawCard();
		void HitPlayer();
		void HitDealer();
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

#endif
