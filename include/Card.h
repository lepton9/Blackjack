#ifndef CARD_H
#define CARD_H

#include <string>

using std::string;

class Card {
	public:
		unsigned int suit;
		unsigned int rank;
		string SuitToString();
};

#endif
