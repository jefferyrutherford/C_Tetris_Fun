#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "tetromino.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

// Declare a 2D array to represent the game board
// Use 'extern' to indicate that the actual definition is in another file
extern int board[BOARD_HEIGHT][BOARD_WIDTH];

void draw_board(Tetromino *current_piece);
void initialize_board();


#endif