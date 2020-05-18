#include "Game.hpp"

namespace WarGame {

		Game::Game(uint numRows, uint numCols): board (numRows, numCols) {
			board[{0,1}] = new FootSoldier(1);
			board[{0,3}] = new FootCommander(1);
			board[{0,5}] = new FootSoldier(1);
		
			board[{13,1}] = new FootSoldier(2);
			board[{13,3}] = new FootCommander(2);
			board[{13,5}] = new FootSoldier(2);
		}

		uint Game::play() {
			std::pair<int,int> move_res;
			uint winner = winner(); // should be 0 - there is no winner yet.
			if (winner) return winner;
		
			move_res = board.move(1, {1,1}, Board::MoveDIR::Up);    // FootSoldier of player 1 moves forward.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			board.move(2, {12,1}, Board::MoveDIR::Down);  // FootSoldier of player 2 moves forward. if there is an enemy around he attacks.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			board.move(1, {0,2}, Board::MoveDIR::Up);    // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
			
			board.move(2, {13,2}, Board::MoveDIR::Down);    // FootCommander of player 2 moves forward, and all soldiers of player 2 attack.
			activate(move_res);	// active soldier ability
			if (winner) return winner;
		
			/// Write more moves here..
		
			return game.winner();
		}
		
}