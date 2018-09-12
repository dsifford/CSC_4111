/*
 * @Author C. Dorman
 */

#include <iostream>
#include <string>
#ifdef _WIN32
	// Needed for Derek. Linux > Windows.
	#include <windows.h>
#endif
#include "defense.h"
#include "derek.h"
#include "offense.h"
#include "player.h"
using namespace std;

#define NUM_PLAYERS 7

int main() {

	// Create the players for the team.
	Offense player("Bob");
	Defense player1("Jane");
	Offense player2("Sai");
	Defense player3("Chin");
	Offense player4("Kali");
	Offense player5("Tom");

	Derek player6;

	Player *team[NUM_PLAYERS]; // Make a team of pointers to players.

	team[0] = &player;
	team[1] = &player1;
	team[2] = &player2;
	team[3] = &player3;
	team[4] = &player4;
	team[5] = &player5;
	team[6] = &player6;

	// Set the player numbers
	for (int i = 0; i < NUM_PLAYERS; i++) {
		team[i]->setNumber(i + 10);
	}

	// Set the player minutes.
	for (int i = 0; i < NUM_PLAYERS; i++) {
		team[i]->setMinutesPlayed(i * 7 + (i + 1) * i + 1);
	}

	// Set the player's stats.
	player.setYards(34);
	player1.setTackles(5);
	player2.setYards(23);
	player3.setTackles(7);
	player4.setYards(132);
	player5.setYards(20);
	player6.setYards(12345);

	// Print out each player's stats.
	for (int i = 0; i < NUM_PLAYERS; i++) {
		team[i]->printStats();
	}

#ifdef _WIN32
	system("pause");
#endif

}
