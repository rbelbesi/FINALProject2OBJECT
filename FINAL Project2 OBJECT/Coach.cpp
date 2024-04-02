#include "Coach.h"
#include <iostream>
#include <string >
using namespace std;

void Coach::setAll(string cN, int cI)
{
	coachName = cN;
	coachID = cI;
}

void Coach::getAll(string& cN, int& cI)
{
	cN = coachName;
	cI = coachID;
}

Coach::Coach(string cN, int cI)
{
	setAll(cN, cI);
}

