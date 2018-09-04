#ifndef DEFENSE_H
#define DEFENSE_H

#include <string>
#include "player.h"

class Defense: public Player {
	public:
		int tackles;
		Defense(string name);
		void setMinutes(int minutes);
		void setTackles(int tackles);
		void printStats() const;
	private:
		string name;
};

#endif
