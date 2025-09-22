#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdio.h>

// Enumeration for different tetromino types
typedef enum {
    SHAPE_I,
    SHAPE_O,
    SHAPE_T,
    SHAPE_S,
    SHAPE_Z,
    SHAPE_J,
    SHAPE_L,

} TetrominoType;

typedef struct {
    TetrominoType type;
    int shape[4][4]; // 4x4 matrix to represent the shape
    int rotation; // Current rotation state (0-3)
    int x, y;     // Position on the board
} Tetromino;

Tetromino create_tetromino(TetrominoType type);
void draw_tetromino(Tetromino *p);

#endif