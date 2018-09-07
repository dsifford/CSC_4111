/**
 * This is the header file for the offense class for CSC 4111 Lab 1 Task 2
 *
 * @author Derek Sifford
 */
#ifndef OFFENSE_H
#define OFFENSE_H

#include <string>

#include "player.h"

class Offense: public Player {
	public:
		/**
		 * Constructor
		 * @param name The player's name.
		 */
		Offense(string name);
		/**
		 * Prints Offense Player stats (overrides inherited method).
		 */
		void printStats() const;
		/**
		 * Setter for minutes.
		 * @param mins The minutes to set.
		 */
		void setMinutesPlayed(int mins);
		/**
		 * Setter for yards.
		 * @param mins The yards to set.
		 */
		void setYards(int yrds);
	private:
		int yards;   // The number of yards the player rushed.
		string name; // The player's name.
};

#endif
