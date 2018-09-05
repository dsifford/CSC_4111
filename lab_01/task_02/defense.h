#ifndef DEFENSE_H
#define DEFENSE_H

#include <string>
#include "player.h"

class Defense: public Player {
	public:
		Defense(string name);
		void printStats() const;
		void setMinutesPlayed(int minutes);
		void setTackles(int tackles);
	private:
		int tackles;
		string name;
};

#endif
