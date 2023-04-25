#ifndef DEALER_H
#define DEALER_H

#include "P.h"
#include <string>

class Dealer : public P {

        public:
		string dealerName;
		Card* faceDownCard;

		Dealer(string name);
		Dealer();
};

#endif
