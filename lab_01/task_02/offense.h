#ifndef OFFENSE_H
#define OFFENSE_H

#include <string>

#include "player.h"

class Offense: public Player {
	public:
		Offense(string name);
		void setMinutesPlayed(int minutes);
		void setYards(int yards);
		void printStats() const;
	private:
		int yards;
		string name;
};

#endif
