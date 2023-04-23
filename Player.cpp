#include "Player.h"

Player::Player(int bal) {
	balance = bal;
}

Player::Player() {
	balance = 0;
}

bool Player::SetBet(double amount) {
	if (balance >= amount) {
		bet = amount;
		balance -= amount;
		return true;
	}
	return false;
}

double Player::HandleWin() {
	double am = 2*bet;
	balance += am;
	bet = 0;
	return am;
}
double Player::HandleBJ() {
	double am = 2.5*bet;
	balance += am;
	bet = 0;
	return am;
}
double Player::HandleLose() {
	double am = bet;
	bet = 0;
	return am;
}
double Player::HandlePush() {
	double am = bet;
	balance += am;
	bet = 0;
	return am;
}
