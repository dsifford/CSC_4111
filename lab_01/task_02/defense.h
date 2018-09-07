/**
 * This is the header file for the defense class for CSC 4111 Lab 1 Task 2
 *
 * @author Derek Sifford
 */
#ifndef DEFENSE_H
#define DEFENSE_H

#include <string>
#include "player.h"

class Defense: public Player {
	public:
		/**
		 * Constructor
		 * @param name The player's name.
		 */
		Defense(string name);
		/**
		 * Prints Offense Player stats (overrides inherited method).
		 */
		void printStats() const;
		/**
		 * Setter for minutes.
		 * @param mins The minutes to set.
		 */
		void setMinutesPlayed(int minutes);
		/**
		 * Setter for tackles.
		 * @param mins The tackles to set.
		 */
		void setTackles(int tackles);
	private:
		int tackles; // The number of tackles the player has.
		string name; // The player's name.
};

#endif
