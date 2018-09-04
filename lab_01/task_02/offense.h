#ifndef OFFENSE_H
#define OFFENSE_H

#include <string>

#include "player.h"

class Offense: public Player {
	public:
		int yards;
		Offense(string name);
		void setMinutesPlayed(int minutes);
		void setYards(int yards);
		void printStats() const;
	private:
		string name;
};

#endif
