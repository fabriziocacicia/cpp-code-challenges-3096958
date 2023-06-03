// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        // Write your code here
        char next_episode_game[N][M];
        for(int row = 0; row < N; row++) {
            for(int col = 0; col < M; col++) {
                next_episode_game[row][col] = game[row][col];
            }
        }
        // Foreach cell checks how many living neighbours
        for(int cell_row = 0; cell_row < N; cell_row++) {
            int top = cell_row == 0 ? N - 1 : cell_row - 1;
            int bottom = cell_row == N - 1 ? 0 : cell_row + 1;

            for(int cell_col = 0; cell_col < M; cell_col++) {
                // New cell. Reset all and count again.
                int neighbours = 0;

                int left = cell_col == 0 ? M - 1 : cell_col - 1;
                int right = cell_col == M - 1 ? 0 : cell_col + 1;

                int around_rows[3] = {top, cell_row, bottom};
                int around_cols[3] = {left, cell_col, right};

                for(auto & around_row : around_rows) {
                    for(auto & around_col : around_cols) {
                        if(around_row == cell_row && around_col == cell_col) {
                            continue;
                        }
                        if(game[around_row][around_col] == 'X') {
                            neighbours++;
                        }
                    }
                }

                if(game[cell_row][cell_col] == '-' && neighbours == 3) {
                    next_episode_game[cell_row][cell_col] = 'X';
                } 

                if(game[cell_row][cell_col] == 'X') {
                    if(neighbours < 2 || neighbours > 3) {
                        next_episode_game[cell_row][cell_col] = '-';
                    }
                }
            }
        }

        for(int row = 0; row < N; row++) {
            for(int col = 0; col < M; col++) {
                game[row][col] = next_episode_game[row][col];
            }
        }

        
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
