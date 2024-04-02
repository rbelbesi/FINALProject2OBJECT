#pragma once
#include "Team.h"
#include "Player.h"
#include <iostream>
#include <string >
using namespace std;
class FootballTeam :public Team
{
	int points, count, maxPlayers;
	Player* players = new Player[maxPlayers];
	virtual void print();


public:
	FootballTeam(string,string , int, int, int); //
	FootballTeam(const FootballTeam&);
	void updatePoints(int);
	int  getNumberOfPoints();
	int getCount();
	void addPlayer(string, int, char);
	void removePlayer(int);
	string retrievePlayerHasNumber(int);
	Player* retrievePlayers(char);
	bool operator==(FootballTeam&);
	FootballTeam moreNumberOfPoints(FootballTeam*);
	~FootballTeam();



};

