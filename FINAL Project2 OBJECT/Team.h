#pragma once
#include <iostream>
#include <string >
#include "Coach.h"

using namespace std;

class Team
{
	string teamName;
protected:
	Coach teamCoach;
public:
	
	void setAll(string, string, int);
	void setTeamName(string);
	string getTeamName();
	virtual void print()=0;
	Team(string, string, int);
	
};

