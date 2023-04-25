#include "CardCount.h"
#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

	
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
	int i;
	if (cardValue == 1 || cardValue == 11) i = 1;
	else i = cardValue;

	runCount += cValues[i - 1];
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
	cout << "Running count: " << getRunCount() << endl;
	printf("True count: %0.2lf\n",getTrueCount());
	cout << "Decks: " << getDecksAm() << "\n" << endl;
}

void CardCount::inputCard(int cardValue) {
	cAmount -= 1;
	update(cardValue);
}

int CardCount::evalCard() {
	if ((*pulledCard)->rank >= 10) return 10;
	return (*pulledCard)->rank;
}

void CardCount::run() {
	int value = 0;
	while(true) {
		if (lastCard != *pulledCard) {
			Sleep(2000);
			*lastCard = **pulledCard;
			value = evalCard();
			inputCard(value);
			PrintCountState();
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


