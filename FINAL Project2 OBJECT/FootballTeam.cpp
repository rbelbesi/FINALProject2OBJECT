#include "FootballTeam.h"
#include "Team.h"
#include <iostream>
#include <string >
using namespace std;

void FootballTeam::print()
{
	cout << "Team Name: " << getTeamName() << endl;
	string cn;
	int cid;
	teamCoach.getAll(cn, cid);
	cout << "Team Coach: " << cn;
	// the coach name ????
	cout << endl;
	cout << "Players:" << endl;
	for (int i = 0; i < count; i++)
	{
		players[i].print();
		//cout << endl;
		//cout << players->getStatus() << endl;
	}
}
FootballTeam::FootballTeam(string tN, string cn, int p, int cid, int mP) :Team(tN, cn, cid)
{
	points = p;
	count = 0;
	maxPlayers = mP;
	players = new Player[maxPlayers];

}
FootballTeam::FootballTeam(const FootballTeam& FBT): Team(FBT)
{
	(*this).points = FBT.points;
	(*this).count = FBT.count;
	(*this).maxPlayers = FBT.maxPlayers;

	players =new Player[maxPlayers];///deep copy
		for(int i=0;i<count;i++)     
			players[i] = FBT.players[i]; //note (not sure about it)

}


void FootballTeam::updatePoints(int up)
{
	points += up;
}

int FootballTeam::getNumberOfPoints()
{
	return points;
}

int FootballTeam::getCount()
{
	return count;
}

void FootballTeam::addPlayer(string pN, int pI, char s)
{
		if (count != maxPlayers)
		{	
			bool flag2 = true;
			while (flag2) {
				flag2 = false;
				for (int i = 0; i < count; i++)
				{
					if (pI == players[i].getPlayerID()) {
						cout << "Please choose other ID.\n";
						cin >> pI;
						flag2 = true;
						break;
					}//if
				}//if
				
			}//if
			players[count++].setAll(pN, pI, s);
		}//if (maxPlayers)

		else
		{
			cout << "You exceeded the max number of players." << endl;
		}//else 

}


void FootballTeam::removePlayer(int pI)
{// 5 8 2 4
	bool flag = false;
	
	for (int i = 0; i < count; i++) {
		if (players[i].getPlayerID() == pI)
		{
			string rem_player = players[i].getPlayerName();
			flag = true;
			for (int j = i; j < count; j++)//for shifting players & delete last one
				players[j] = players[j + 1];
			count--;
			cout << "removed..."<<rem_player<< endl;
			break;
		}//if 
	}//// for (int i = 0; i < count; i++)
	if (!flag)
		cout << "The player is not found in the players list." << endl;
}

string FootballTeam::retrievePlayerHasNumber(int pI)
{
	for (int i = 0; i < count; i++)
	{
		if (players[i].getPlayerID() == pI)
			return players[i].getPlayerName();
	}//for
	return "";
}

Player* FootballTeam::retrievePlayers(char s)
{
	int counter = 0;
	Player* p=new Player[count];

	for (int i = 0; i < count; i++)
	{
		if (players[i].getStatus() == s)
		{
			p[counter++] = players[i];
		}//if
	}//for
	return p;
}

bool FootballTeam::operator==(FootballTeam& FBT)
{

	return (this->count == FBT.count);
}

FootballTeam FootballTeam::moreNumberOfPoints(FootballTeam* FBT)
{

	if (this->points < FBT->points)
		return *FBT;
	else
		return *this;
}

FootballTeam::~FootballTeam()
{
	delete[]players;
}

