/**
  Demo for the war-game exercise.

  @author Oz Levi
  @since  2020-05
**/

struct Move {
	int x, y;
};

void play(Move move) {

}

play({1,2});


#include <iostream>
#include "GameGrid.hpp"     // You have to write this file

using namespace std;

int main() {
    //use it a singleton or an object?
	//warGame::GameGrid init(); // initilize game by default
								// print the grid and tells the first played to play

	GameGrid game(14,17);  // Initialize a game on a 14-by-17 grid

	Soldier soldier;
	Commander commander;
	Sniper sniper;
	Paramedic paramedic;

	//first player
	GameGrid.play(commander, {1,3}); //maybe include does string as enum/constans in the namescape and use them from there

	//sec player
	GameGrid.play(sniper, {3,5}); // can also adds cout and set the play function to return the grid

	//first player
	GameGrid.play(paramedic, {6,3}); //the commander can tel his soldiers to both move 

	//sec player
	GameGrid.play(soldier,{7,4});

	//exceptions like: game over, cant move there and ....
   return 0;
}

/*
NOTE: here there is no PLAYER
		we can by defining diff PLAYERs [some other charecters, or order order]
		and lets the sudents implents everthing there
		and finally sends the to the grid constructor
		which will use them in the plat method
 */