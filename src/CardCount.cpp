#ifdef _WIN32
#include <Windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

#include "Game.h"
#include "CardCount.h"
#include <iostream>


using std::cout;
using std::endl;

int cardsPulled = 0;


CardCount::CardCount(int dAm, Card** pCard) {
	deckAmStart = dAm;
	decksRem = dAm;
	cAmount = dAm * 52;

	runCount = 0;
	trueCount = 0;

	pulledCard = pCard;
	lastCard = NULL;
}

int CardCount::getRunCount() {return runCount;}
double CardCount::getTrueCount() {return trueCount;}

int CardCount::getDecksAm() {return deckAmStart;}

void CardCount::update(int cValue) {
	calcRunCount(cValue);
	calcTrueCount();
}

int CardCount::calcRunCount(int cardValue) {
	runCount += cValues[cardValue - 1];
	return runCount;
}

double CardCount::calcTrueCount() {
	trueCount = runCount / calcDecksRem();
	return trueCount;
}

double CardCount::calcDecksRem() {
	decksRem = deckAmStart * ((double)cAmount / (double)(deckAmStart * 52));
	return decksRem;
}

void CardCount::PrintCountState() {
	Game::ClsFromCurPosTo({0, 5}, writePos);
	SetConsoleCursorPosition(Game::hConsole, writePos);

	cout << "Cards pulled: " << cardsPulled << endl;
	cout << "Cards remaining: " << 52*getDecksAm() - cardsPulled << endl;
	cout << "Decks: " << getDecksAm() << endl;
	cout << "Running count: " << getRunCount() << endl;
	printf("True count: %0.2lf\n",getTrueCount());
}

void CardCount::inputCard(int cardValue) {
	cardsPulled += 1;
	cAmount -= 1;
	update(cardValue);
}

int CardCount::evalCard() {
	if ((*pulledCard)->rank >= 10) return 10;
	return (*pulledCard)->rank;
}

void CardCount::run() {
	int value;
	while(true) {
		if (lastCard != *pulledCard) {
			lastCard = *pulledCard;
			value = evalCard();
			inputCard(value);
			PrintCountState();
			//Sleep(2000);
			
			Game::run = true;
		}
	}
}

/**
int main(int argc, char* argv[]) {
	CardCount cc(std::stoi(argv[1]));

	cc.PrintCountState();

	cc.inputCard(2);
	cc.PrintCountState();

	return 0;
}
**/


