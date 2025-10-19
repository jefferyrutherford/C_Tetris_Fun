#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdio.h>
#include <stdlib.h>


#define TETROMINO_COUNT 4 // Update this when adding more shapes

// Enumeration for different tetromino types
typedef enum {
    SHAPE_I = 0,
    SHAPE_O,
    SHAPE_T,
    SHAPE_S

} TetrominoType;

typedef struct {
    TetrominoType type;
    int shape[4][4]; // 4x4 matrix to represent the shape
    int rotation; // Current rotation state (0-3)
    int x, y;     // Position on the board
} Tetromino;

Tetromino create_tetromino(TetrominoType type);
void draw_tetromino(Tetromino *p);
Tetromino create_random_tetromino();

#endif