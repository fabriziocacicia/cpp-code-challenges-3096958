// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;

    // Write your code here
    const int COL = 0;
    const int ROW = 1;

    const char col = knight[0];
    const char row = knight[1];

    std::vector<std::string> possible_moves;

    for(int i = 0; i < 8; i++) {
        possible_moves.push_back(knight);
    }

    possible_moves[0][COL] -= 2;
    possible_moves[0][ROW] += 1;
    possible_moves[1][COL] -= 1;
    possible_moves[1][ROW] += 2;
    possible_moves[2][COL] += 1;
    possible_moves[2][ROW] += 2;
    possible_moves[3][COL] += 2;
    possible_moves[3][ROW] += 1;
    possible_moves[4][COL] += 2;
    possible_moves[4][ROW] -= 1;
    possible_moves[5][COL] += 1;
    possible_moves[5][ROW] -= 2;
    possible_moves[6][COL] -= 1;
    possible_moves[6][ROW] -= 2;
    possible_moves[7][COL] -= 2;
    possible_moves[7][ROW] -= 1;

    for(int i = 0; i < 8; i++) {
        if(possible_moves[i][COL] < 'a' || possible_moves[i][COL] > 'h') {
            continue;
        }

        if(possible_moves[i][ROW] - '0' < 1 || possible_moves[i][ROW] - '0' > 8) {
            continue;
        }

        moves.push_back(possible_moves[i]);
    }


    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}