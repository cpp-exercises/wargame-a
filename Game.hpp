#pragma once
/**
 * Header file for the war game.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "Board.hpp"
#include "Soldier.hpp"

namespace WarGame {
	class Game {
	 private:
		Board board;
	 public:

 		/**
		 *  Game Constructor will initilize board and place soldiers.
		 */
		Game(uint numRows, uint numCols);
		/*
		{
			board(numRows, numCols) 
			board[(0,1)] = new FootSoldier(1);
			board[(0,3)] = new FootCommander(1);
			board[(0,5)] = new FootSoldier(1);
		
			board[(13,1)] = new FootSoldier(2);
			board[(13,3)] = new FootCommander(2);
			board[(13,5)] = new FootSoldier(2);
		}
		*/

		/**
		 *  Play the game and return the winner (1 or 2).
		 */
		uint play(); 
		/*
		{
			std::pair<int,int> move_res;
			uint winner = winner(); // should be 0 - there is no winner yet.
			if (winner) return winner;
		
			move_res = board.move(1, make_pair(1,1), Board::MoveDIR::Up);    // FootSoldier of player 1 moves forward.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			board.move(2, make_pair(12,1), Board::MoveDIR::Down);  // FootSoldier of player 2 moves forward. if there is an enemy around he attacks.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			board.move(1,  make_pair(0,2), Board::MoveDIR::Up);    // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			board.move(2,  make_pair(13,2), Board::MoveDIR::Down);    // FootCommander of player 2 moves forward, and all soldiers of player 2 attack.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
		
			/// Write more moves here..
		
			return game.winner();
		}
		*/

		// operator for reading which soldiers are on the game-board.
		// will help you check your game moves
		// will return "FootSoldier" / "Empty" ....
    	Soldier* operator[](std::pair<int,int> location) const;

		// Check if the game is over, and if so - who is the winner.
		// returns 0 if the game is not over (i.e., both players have remaining soldiers).
		// returns 1 if the game is over and player 1 won.
		// returns 2 if the game is over and player 2 won.
		uint winner() const ;

		//activate the special ability of the soldier placed in the given location.
		void activate(std::pair<int,int> location);
	};
}
