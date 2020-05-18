#pragma once
/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "Board.hpp"

namespace WarGame {
	class DemoGame {
	 private:
		Board board;
	 public:

 		/**
		 *  Game Constructor will initilize board and place soldiers.
		 */
		DemoGame();
		
		/**
		 *  Play the game and return the winner (1 or 2).
		 */
		uint play(); 
	};
}
