/**
 * This is the implementation file for the Defense class for CSC 4111 Lab 1
 * Task 2.
 *
 * @author Derek Sifford
 */

#include "defense.h"

/**
 * Constructor for Defense class.
 * @param name The player's name.
 */
Defense::Defense(string n): Player(n) {
	name = n;
};

/**
 * Prints Defense Player stats (overrides Player method).
 */
void Defense::printStats() const {
	std::cout << "Name: " << name
	          << "\tNumber: " << number
	          << "\tMinutes: " << minutes
	          << "\tTackles: " << tackles
	          << std::endl;
}

/**
 * Setter for minutes.
 * @param mins The minutes to set.
 */
void Defense::setMinutesPlayed(int mins) {
	minutes = mins;
};

/**
 * Setter for tackles
 * @param tackleNum The number of tackles to set.
 */
void Defense::setTackles(int tackleNum) {
	tackles = tackleNum;
};
