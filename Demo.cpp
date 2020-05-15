/**
  Demo for the war-game exercise.

  @author Oz Levi
  @since  2020-05
**/

#include <iostream>
#include "Game.hpp"  
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;

/**
 *  Initialize the game board
 */
void initialize(wargame::Game& game) {
	/* Put the initial soldiers of player 1 on row 0: */
	game[{0,7}] = new FootSoldier(
		/*belongs to player*/1, 
		/*initial health points=*/100,
		/*damage per attack=*/10);
	game[{0,8}] = new FootCommander(
		/*belongs to player*/1, 
		/*initial health points=*/200,
		/*damage per attack=*/20);
	game[{0,9}] = new FootSoldier(
		/*belongs to player*/1, 
		/*initial health points=*/100,
		/*damage per attack=*/10);

	/* Put the initial soldiers of player 2 on row 13: */
	game[{13,7}] = new FootSoldier(
		/*belongs to player*/2, 
		/*initial health points=*/100,
		/*damage per attack=*/10);
	game[{13,8}] = new FootCommander(
		/*belongs to player*/2, 
		/*initial health points=*/200,
		/*damage per attack=*/20);
	game[{13,9}] = new FootSoldier(
		/*belongs to player*/2, 
		/*initial health points=*/100,
		/*damage per attack=*/10);
}


/**
 *  Play the game and return the winner (1 or 2).
 */
uint play(wargame::Game& game) {
	uint winner;
	winner = game.winner(); // should be 0 - there is no winner yet.
	if (winner) return winner;

	game.move(1, {0,7}, {3,7});    // FootSoldier of player 1 moves forward 3 rows, and attacks the soldier of player 2 at {13,0}.
	game.move(2, {13,7}, {11,8});  // FootSoldier of player 2 moves 3 positions (to {12,7},{12,8},{11,8}) and attacks the commander of player 1 at {0,8}
	if (winner = game.winner()) return winner;  // should not return - there is no winner yet.

	game.move(1, {0,8}, {1,8});    // FootCommander of player 1 moves forward 1 row, and all soldiers of player 1 attack.
	game.move(2, {0,8}, {1,8});    // FootCommander of player 1 moves forward 1 row, and all soldiers of player 1 attack.
	if (winner = game.winner()) return winner;  // should not return - there is no winner yet.

	/// Write more moves here..

	return game.winner();
}


int main() {
	wargame::Game game(14,17);  // Initialize a game on a 14-by-17 grid
	initialize(game);
	cout << "The winner is: " << play(game) << endl;
    return 0;
}
