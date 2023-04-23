#ifndef PLAYER_H
#define PLAYER_H

#include "P.h"

class Player : public P {
                double balance;
		double bet;
        public:
		double getBalance();
		void setBalance(int bal);

		double getBet();
		bool setBet(double amount);

		double HandleWin();
		double HandleBJ();
		double HandleLose();
		double HandlePush();
		
		Player(int bal);
		Player();
};

#endif
