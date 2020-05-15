/**
 * Implementation of bull-pgia game
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include "Game.hpp"

using namespace std;

namespace wargame {
	Game::Game(uint numRows, uint numCols): 
		numRows(numRows), numCols(numCols), 
		board(numRows, vector<Soldier*>(numCols, nullptr)) {	}

	void Game::move(Location source, Location target) {
		// You have to implement this function.
		// HINT: Do not write code that depends on the type of soldier!
		// Your code should be generic. All handling of different types of soldiers 
		//      must be handled by polymorphism.
		throw new std::invalid_argument{};
	}

	uint Game::winner() const {
		// You have to implement this function.
		return 0;
	}
}
