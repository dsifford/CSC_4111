
#include "offense.h"

Offense::Offense(string n) : Player(n) {
	name = n;
};

void Offense::setMinutesPlayed(int mins) {
	minutes = mins;
}

void Offense::setYards(int yrds) {
	yards = yrds;
}

void Offense::printStats() const {
	std::cout << "Name: " << name 
			  << "\tNumber: " << number 
			  << "\tMinutes: " << minutes 
			  << "\tYards: " << yards
			  << std::endl;
}
