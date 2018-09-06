#include <string>

#include "defense.h"

Defense::Defense(string n): Player(n) {
	name = n;
};

void Defense::printStats() const {
	std::cout << "Name: " << name
	          << "\tNumber: " << number
	          << "\tMinutes: " << minutes
	          << "\tTackles: " << tackles
	          << std::endl;
}

void Defense::setMinutesPlayed(int mins) {
	minutes = mins;
};

void Defense::setTackles(int tackleNum) {
	tackles = tackleNum;
};
