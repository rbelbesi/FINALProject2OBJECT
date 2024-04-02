#include "Team.h"
#include "Coach.h"
#include <iostream>
#include <string >
using namespace std;



void Team::setAll(string tN, string cN, int cI)
{
    teamName = tN;
    teamCoach.setAll(cN, cI);

}

void Team::setTeamName(string tN)
{
    teamName = tN;
}

string Team::getTeamName()
{
    return teamName;
}

Team::Team(string tN, string cN, int cI) :teamCoach(cN, cI)
{
    setAll(tN, cN, cI);
}

