/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"

#include <cassert>

namespace WarGame {

		DemoGame::DemoGame(): board (8, 8) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,1}] = new FootSoldier(1);
			board[{0,3}] = new FootCommander(1);
			board[{0,5}] = new FootSoldier(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{7,1}] = new FootSoldier(2);
			board[{7,3}] = new FootCommander(2);
			board[{7,5}] = new FootSoldier(2);
			assert(board.has_soldiers(2));

			// In your game, you can put more soldier types, such as the sniper and the paramedic types.
		}

		uint DemoGame::play() {
			board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks.
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {7,1}, Board::MoveDIR::Down);    // FootSoldier of player 2 moves forward and attacks.
			if (!board.has_soldiers(1)) return 2;

			board.move(1, {0,3}, Board::MoveDIR::Up);      // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {7,3}, Board::MoveDIR::Left);    // FootCommander of player 2 moves left, and all soldiers of player 2 attack.
			if (!board.has_soldiers(1)) return 2;

			/// Write more moves here..

			// If no player won, return "tie":
			return 0;
		}
}
