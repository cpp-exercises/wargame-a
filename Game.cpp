#include "Game.hpp"

namespace WarGame {

		Game::Game(uint numRows, uint numCols)
		{
			borad = new Board(numRows, numCols);
			borad[(0,1)] = new FootSoldier(1);
			borad[(0,3)] = new FootCommander(1);
			borad[(0,5)] = new FootSoldier(1);
		
			borad[(13,1)] = new FootSoldier(2);
			borad[(13,3)] = new FootCommander(2);
			borad[(13,5)] = new FootSoldier(2);
		}

		uint play(); 
		{
			std::pair<int,int> move_res;
			uint winner = winner(); // should be 0 - there is no winner yet.
			if (winner) return winner;
		
			move_res = borad.move(1, make_pair(1,1), Board::MoveDIR::Up);    // FootSoldier of player 1 moves forward.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			borad.move(2, make_pair(12,1), Board::MoveDIR::Down);  // FootSoldier of player 2 moves forward. if there is an enemy around he attacks.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			borad.move(1,  make_pair(0,2), Board::MoveDIR::Up);    // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			borad.move(2,  make_pair(13,2), Board::MoveDIR::Down);    // FootCommander of player 2 moves forward, and all soldiers of player 2 attack.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
		
			/// Write more moves here..
		
			return game.winner();
		}
		
}