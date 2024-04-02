#include "Player.h"
#include <iostream>
#include <string >
using namespace std;
void Player::setAll(string pN, int pI, char s)
{
	playerName = pN;
	playerID = pI;
	status = s;
}

string Player::getPlayerName()
{
	return playerName;
}

int Player::getPlayerID()
{
	return playerID;
}

void Player::setStatus(char s)
{
	status = s;
}

char Player::getStatus()
{
	return status;
}

void Player::print()
{
	cout << playerID << "\t" << playerName << endl;
}

Player::Player(string pN, int pI, char s)
{
	setAll(pN, pI, s);
}
