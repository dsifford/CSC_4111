/**
 * This is the implementation file for the Offense class for CSC 4111 Lab 1
 * Task 2.
 *
 * @author Derek Sifford
 */

#include "offense.h"

/**
 * Constructor for Offense class.
 * @param name The player's name.
 */
Offense::Offense(string n): Player(n) {
	name = n;
};

/**
 * Prints Defense Player stats (overrides Player method).
 */
void Offense::printStats() const {
	std::cout << "Name: " << name
	          << "\tNumber: " << number
	          << "\tMinutes: " << minutes
	          << "\tYards: " << yards
	          << std::endl;
}

/**
 * Setter for minutes.
 * @param mins The minutes to set.
 */
void Offense::setMinutesPlayed(int mins) {
	minutes = mins;
}

/**
 * Setter for yards.
 * @param yrds The number of yards to set.
 */
void Offense::setYards(int yrds) {
	yards = yrds;
}
