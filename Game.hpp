#pragma once
/**
 * Header file for the war game.
 * 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

namespace wargame {

	struct Location {
		uint row, col;
	};

	struct Game {
		uint numRows, numCols;
		std::vector<std::vector<Soldier*>> board;

		Game(uint numRows, uint numCols);

		// operator for putting soldiers on the game-board during initialization.
		Soldier*& operator[](Location location);

		// operator for reading which soldiers are on the game-board.
		Soldier* operator[](Location location) const;

		// Try to move the soldier of player "player"
		//     from the "source" location to the "target" location.
		// If the move is illegal, it throws "std::invalid_argument". 
		// Illegal moves include:
		//  * There is no soldier in the source location (i.e., the soldier pointer is null);
		//  * The soldier in the source location belongs to the other player.
		//  * There is already another soldier (of this or the other player) in the target location.
		//  * The specific soldier at the source location cannot move to the target location
		//    (it is not a legal move for him - e.g. too far away).
		void move(uint player, Location source, Location target);

		// Check if the game is over, and if so - who is the winner.
		// returns 0 if the game is not over (i.e., both players have remaining soldiers).
		// returns 1 if the game is over and player 1 won.
		// returns 2 if the game is over and player 2 won.
		uint winner() const ;
	};
}
