/**
  Demo for the war-game exercise.

  @author Oz Levi
  @since  2020-05
**/

#include <iostream>
#include "DemoGame.hpp"  

using namespace std;

int main() {
	WarGame::DemoGame demoGame(8,8);  // Initialize a game on a 8-by-8 board
	cout << "The winner is:\n " << demoGame.play() << endl;
    return 0;
}
