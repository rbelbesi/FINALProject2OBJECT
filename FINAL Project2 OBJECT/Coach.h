#pragma once
#include <iostream>
#include <string >
using namespace std;
class Coach
{
	string coachName;
	int coachID;

public:
	//virtual void print();
	void setAll(string, int);
	void getAll(string&, int&);
	Coach(string , int);

};

