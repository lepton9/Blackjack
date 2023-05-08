#ifndef GAME_H
#define GAME_H


#include "Player.h"
#include "Dealer.h"
#include "Card.h"
#include "Deck.h"

#include <sstream>
#include <vector>
#include <string>

using std::vector;

class Game {
		bool gameEnd;
		int decksAm;

	public:
		Dealer dealer;
		Player player;
		vector<Card> cards;
		Card* pulledCard;
		static COORD writePos;

		static HANDLE hConsole;
		static bool run; // Flag to know if to continue the game
		static bool ccOn;
		static COORD lastLinePrinted;

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
		void PrintAsciiCards(vector<vector<string>>* asciiCards);

		static bool EqualCOORD(COORD a, COORD b);
		static void ClsFromCurPosTo(COORD from, COORD to);
		static COORD GetConsoleCursorPosition();

		void RunFalseWaitCC();

		void ResetTable();
};

#endif
