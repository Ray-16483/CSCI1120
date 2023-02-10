// Name:       ZHANG ZHIRUI
// Student ID: 1155174021
// Email:      1155174021@link.cuhk.edu.hk

#ifndef REVERSI_H
#define REVERSI_H

// Global constants
const int N = 12;         // board size

/* You may put in extra constants or constant arrays here. */ 


// Function prototypes
bool cin_failed();
void print_board(char board[][N]);
bool valid_move(char board[][N], char p, int y, int x, bool flip = false);
bool has_valid_moves(char board[][N], char p);
bool has_empty_cells(char board[][N]);

/* You may put in extra function prototypes here if you have written extra
   functions in stringcoin.cpp. */

#endif // REVERSI_H