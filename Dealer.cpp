#include "Dealer.h"

Dealer::Dealer(string name) {
	dealerName = name;
	faceDownCard = NULL;
}

Dealer::Dealer() {
	dealerName = "";
	faceDownCard = NULL;
}
