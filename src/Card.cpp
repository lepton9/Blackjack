#include "Card.h"

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
