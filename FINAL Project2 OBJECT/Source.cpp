#include "Team.h"
#include "Coach.h"
#include "Player.h"
#include "FootballTeam.h"
#include <iostream>
#include <string >
using namespace std;
void getActivePlayersName(FootballTeam* F, char c = 'a')
{
	Player* p = new Player[F->getCount()];
	p = F->retrievePlayers(c);
	for (int i = 0; i < F->getCount(); i++)
	{
		if (p[i].getPlayerName() != "")
		{
			p[i].print();
		}//if
	}//for
}//getActivePlayersName
void printTeamInfo(Team* t)
{
	t->print();
	cout << endl;
}//team 


int main() {
	//1. Create a dynamic object of FootballTeam class with the following values: "Manchester City", "Guardiola", 32, 123, 50
	FootballTeam* manCity = new FootballTeam("Manchester City", "Guardiola", 32, 123, 50);
	//2. Create a dynamic object of FootballTeam class with the following values: "Barcelona", "Xavi", 37, 21, 75
	FootballTeam* barcelona = new FootballTeam("Barcelona", "Xavi", 37, 21, 75);

	manCity->addPlayer("Riyad Mahrez", 26, 'a');
	manCity->addPlayer("Julian Alvarez", 19, 'a');
	manCity->addPlayer("Erling Haaland", 9, 'a');
	manCity->addPlayer("Bernardo Silva", 20, 'i');
	manCity->addPlayer("Jack Grealish", 10, 'i');
	manCity->addPlayer("Kevin De Bruyne", 17, 'a');
	manCity->addPlayer("Kyle Walker", 2, 'i');
	barcelona->addPlayer("Marcos Alonso", 17, 'i');
	barcelona->addPlayer("Jordi Alba", 18, 'a');
	barcelona->addPlayer("Eric García", 25, 'a');
	barcelona->addPlayer("Sergio Busquets", 5, 'i');
	barcelona->addPlayer("Frenkie de Jong", 21, 'a');
	barcelona->addPlayer("Ousmane Dembélé", 7, 'a');
	barcelona->addPlayer("Ansu Fati", 10, 'a');
	barcelona->addPlayer("Memphis Depay", 14, 'a');
	int choice;
	do {

		cout << "***************************** Menu * ******************************\n";
		cout << "Enter 1: to add a player.\n"
			<< "Enter 2: to remove a player.\n"
			<< "Enter 3: to update points.\n"
			<< "Enter 4: to display teams points.\n"
			<< "Enter 5: to print the team name that has more points.\n"
			<< "Enter 6: to check whether the two teams have the same number of players.\n"
			<< "Enter 7: to display team info (team name, coach and players).\n"
			<< "Enter 8: to display active players.\n"
			<< "Press any Key to EXIT.\n";

		"********************************************************************\n";
		cin >> choice;
		switch (choice) {
			int c;
			//*******************Add Player*******************
		case 1:
		{
			cout << "Enter 1 to add a player to Manchester City, or\n"
				<< "Enter 2 to add a player to Barcelona.\n";
			int num;
			string name;
			char s;
			cin >> c;
			cout << "Enter player name, number and status (a: active or i: inactive).\n";
			cin >> name >> num >> s;
			switch (c) {
			case 1:
				//3. Add the player to Man. City team.
				manCity->addPlayer(name, num, s);
				cout << "Added... " << name << endl << endl;
				break;
			case 2:
				//4. Add the player to Barcelona team.
				barcelona->addPlayer(name, num, s);
				cout << "Added... " << name << endl << endl;
				break;
			}
			break;
		}
		//*******************Remove Player*******************
		case 2:
		{
			cout << "Enter 1 to remove a player from Manchester City, or\n"
				<< "Enter 2 to remove a player from Barcelona.\n";
			cin >> c;
			int num;
			cout << "\nEnter the player number you want to remove... ";
			cin >> num;
			switch (c) {
			case 1:
				//5. Print the player’s name you want to remove from Man. City team then remove the player from the team.
				manCity->removePlayer(num);
				//cout << "removed" << endl;
				break;
			case 2:
				//6. Print the player’s name you want to remove from Barcelona team then remove the player from the team.
				barcelona->removePlayer(num);
				//cout << "removed" << endl;
				break;
			}
			break;
		}
		//*******************Update Points*******************
		case 3:
		{
			cout << "Enter 1 to update the points for Manchester City, or\n"
				<< "Enter 2 to update the points for Barcelona.\n";
			cin >> c;
			int p;
			cout << "Enter the new point the Team has earned... ";
			cin >> p;
			if (c == 1) {
				//7. Update the points for Man. City team.

				manCity->updatePoints(p);
				cout << "Updated...\n\n";
			}
			else {
				//8. Update the points for Barcelona team.
				barcelona->updatePoints(p);
				cout << "Updated...\n\n";
			}
			break;
		}
		//*******************Display Points*******************
		case 4:
		{
			//9. Display the points for Man. City and Barcelona teams as in the sample output.
			cout << "Points for: " << endl;
			cout << "Manchester City: " << manCity->getNumberOfPoints() << endl;;
			cout << "Barcelona: " << barcelona->getNumberOfPoints() << endl;
			break;
		}
		//*******************More Points*******************
		case 5:
		{
			//10. Display the team’s name that has more points.

			cout << "The team has more points is: " << manCity->moreNumberOfPoints(barcelona).getTeamName() << endl;

			break;
		}
		//*******************Same #Players*******************
		case 6:
		{
			//11. Check whether the two teams have the same number of players.
			//barcelona->operator==(*manCity);
			if (barcelona->operator==(*manCity))
			{
				cout << "The two teams have the same number of players.\n";
			}//if
			else
			{
				cout << "The two teams have not the same number of players.\n";
			}//else 

			break;
		}
		//*******************Display Team Info*******************
		case 7:
		{
			cout << "Enter 1 to display Manchester City team info, or\n"
				<< "Enter 2 to display Barcelona team info.\n";
			cin >> c;

			if (c == 1) {

				//12. Display Man. City team info.
				printTeamInfo(manCity);

				cout << endl;

			}
			else {
				//13. Display Barcelona team info.

				printTeamInfo(barcelona);


			}
			break;
		}

		case 8:
		{
			cout << "Enter 1 to display active players in Manchester City team, or\n"
				<< "Enter 2 to display active players in Barcelona team.\n";
			cin >> c;
			//Player p;
			if (c == 1) {
				//14. Display player’s id and name of all active players in Man. City team.
				getActivePlayersName(manCity, 'a');
				cout << endl;
				//FootballTeam *a=	manCity->retrievePlayers('a');
			}
			else {
				//15. Display player’s id and name of all active players in Barcelona team.
				getActivePlayersName(barcelona, 'a');
				cout << endl;
			}
			break;
		}
		}
	} while (choice >= 1 && choice <= 8);
	return 0;
}