#include "Player.h"

Player::Player(int bal) {
	balance = bal;
}

Player::Player() {
	balance = 0;
}


double Player::getBalance() {return balance;}

void Player::setBalance(int bal) {
	balance = bal;
}

double Player::getBet() {return bet;}

bool Player::setBet(double amount) {
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
