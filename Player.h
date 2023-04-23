#ifndef PLAYER_H
#define PLAYER_H

#include "P.h"

class Player : public P {

        public:
                double balance;
		double bet;

		bool SetBet(double amount);
		double HandleWin();
		double HandleBJ();
		double HandleLose();
		double HandlePush();
		
		Player(int bal);
		Player();
};

#endif
