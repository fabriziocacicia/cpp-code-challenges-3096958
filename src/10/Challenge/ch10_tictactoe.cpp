// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

#define DOUBLER_AI
void make_move(char game[][3], char mark){ 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else
    
    // Write your code here and comment out the definition of TWO_PLAYERS above
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(game[row][col] == mark) {
                if(col + 1 < 3 && game[row][col + 1] == ' ') {
                    game[row][col + 1] = mark;
                    return;
                }

                if(row + 1 < 3 && game[row + 1][col] == ' ') {
                    game[row + 1][col] = mark;
                    return;
                }
            }
        }
    }

    if(game[0][0] == mark) {
        if(game[1][1] == ' ') {
            game[1][1] = mark;
            return;
        }
    }

    if(game[1][1] == mark) {
        if(game[2][2] == ' ') {
            game[2][2] = mark;
            return;
        }

        if(game[3][1] == ' ') {
            game[3][1] = mark;
        }
    }

    if(game[1][3] == mark) {
        if(game[1][1] == ' ') {
            game[1][1] = mark;
            return;
        }
    }

    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(game[row][col] == ' ') {
                game[row][col] = mark;
                return;
            }
        }
    }
    #endif
    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char game_state(char game[][3]){

    // Write your code here
    // Checks rows and cols
    for(int i = 0; i < 3; i++) {
        // Checks rows
         if(game[i][0] != ' ' && game[i][0] == game[i][1] && game[i][1] == game[i][2]) {
            return game[i][0];
        }

        // Checks cols
        if(game[0][i] != ' ' && game[0][i] == game[1][i] && game[1][i] == game[2][i]) {
            return game[0][i];
        }
    }

    // Checks diags
    if(game[1][1] != ' ') {
        if(game[0][0] == game[1][1] && game[1][1] == game[2][2]) {
            return game[1][1];
        }

        if(game[0][2] == game[1][1] && game[1][1] == game[2][0]) {
            return game[1][1];
        }
    }

    // No winner yet. If there are empty cells the game is still active
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(game[row][col] == ' ') {
                return 'a';
            }
        }
    }

    // No winner and no empty cells: tie
    return 't';
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(game_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << game_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
