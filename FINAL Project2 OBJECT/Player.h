#pragma once
#include <iostream>
#include <string >
using namespace std;
class Player
{
	string playerName;
	int playerID;
	char  status;
public:
	void setAll(string, int, char);
	string  getPlayerName();
	int getPlayerID();
	void  setStatus(char);
	char getStatus();
	void print();
	Player(string pN = "", int pI = 0, char s = 'i');
	

};