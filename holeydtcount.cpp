// holeydtcount.cpp
// Kohlby Vierthaler
// 2024/10/04
// Source file for Recursive Backtracking

#include "holeydtcount.hpp"

#include <vector> // For board representation
using std::vector;


// Wrapper function implementation
// Preconditions: holes must be in range, 
// dim_x and dim_y must be positive integers

// Sets up board and calls workhorse function
int holeyDTCount(int dim_x, int dim_y,
int hole1_x, int hole1_y,
int hole2_x, int hole2_y) {

    vector<vector<int>> board(dim_x, vector<int>(dim_y, 0));
    board[hole1_x][hole1_y] = 1;
    board[hole2_x][hole2_y] = 1;
    int squares = (dim_x * dim_y) - 2;

    return holeyDTCount_recurse(board, dim_x, dim_y, squares);
}

// Workhorse function implementation
// Preconditions: board must be valid,
// dim_x, dim_y, and squaresLeft must be positive integers

// Recurses through a board and returns the number of
// solutions to a holey domino tiling
int holeyDTCount_recurse(vector<vector<int>> &board, 
int dim_x, int dim_y, int squaresLeft) {
    
    
    // check for full solution
    if (squaresLeft == 0) {
        return 1;
    }

    int total = 0;

    // iterate through board
    for (int i = 0; i < dim_x; ++i) {
        for (int j = 0; j < dim_y; ++j) {

            // find first available square
            if (board[i][j] == 0) {

                // check board bounds, then try horizontal placement
                if (j + 1 < dim_y && board[i][j + 1] == 0) {
                    board[i][j] = 1;
                    board[i][j + 1] = 1;
                    total += holeyDTCount_recurse(board, dim_x, dim_y, squaresLeft - 2);
                    board[i][j] = 0;
                    board[i][j + 1] = 0;
                }

                // check board bounds, then try vertical placement
                if (i + 1 < dim_x && board[i + 1][j] == 0) {
                    board[i][j] = 1;
                    board[i + 1][j] = 1;
                    total += holeyDTCount_recurse(board, dim_x, dim_y, squaresLeft - 2);
                    board[i][j] = 0;
                    board[i + 1][j] = 0;
                } 

                return total;
            }
        }
    }

    return total;
}