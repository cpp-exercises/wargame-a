#include <string>
#include <vector>
#include <stdexcept>

namespace WarGame {
class Board
{
 private:
    std::vector<std::vector<void*>> board;
 public:
    enum MoveDIR { Up, Down, Right, Left };
    
    Board(uint numRows, uint numCols) : board(numRows, std::vector<void*>(numCols, nullptr)){};

    // operator for putting soldiers on the game-board during initialization.
    void*& operator[](std::pair<int,int> location);
    
    // operator for reading which soldiers are on the game-board.
    void* operator[](std::pair<int,int> location) const;
    
    
    // Try to move the soldier of player "player"
    //     from the "source" location to the "target" location.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    //  * The specific soldier at the source location cannot move to the target location
    //    (it is not a legal move for him - e.g. too far away).
    std::pair<int,int> move(int player_number, std::pair<int,int> source, MoveDIR dest);
    // You have to implement this function.
    // HINT: Do not write code that depends on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
    //throw new std::invalid_argument{};
};
}