#include "board.h"
#include "tetromino.h"



const int I_SHAPE[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

const int O_SHAPE[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};

const int S_SHAPE[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
};

const int T_SHAPE[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0}
};

Tetromino create_random_tetromino() {
    TetrominoType random_type = (TetrominoType)(rand() % TETROMINO_COUNT);
    return create_tetromino(random_type);
}

//ToDo Add other shapes here...

Tetromino create_tetromino(TetrominoType type) {
    Tetromino new_piece;
    
    //Set initial position
    new_piece.x = BOARD_WIDTH / 2 - 2; // Centered at the top
    new_piece.y = 0;
    new_piece.rotation = 0;
    new_piece.type = type;

    // Initialize shape based on type
    switch (type) {
        case SHAPE_I:
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    new_piece.shape[i][j] = I_SHAPE[i][j];
            break;
        case SHAPE_O:
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    new_piece.shape[i][j] = O_SHAPE[i][j];
            break;
        case SHAPE_T:
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    new_piece.shape[i][j] = T_SHAPE[i][j];
            break;
        case SHAPE_S:
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    new_piece.shape[i][j] = S_SHAPE[i][j];
            break;
        //ToDo Add other shapes here...
        default:
            // Default to an empty shape if type is unknown
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    new_piece.shape[i][j] = 0;
            break;
    }
    return new_piece;
}

void draw_tetromino(Tetromino *p) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (p->shape[y][x] == 1) {
                // Only draw if the position is on the board
                if (p->y + y >= 0 && p->y + y < BOARD_HEIGHT && 
                    p->x + x >= 0 && p->x + x < BOARD_WIDTH) {
                    
                    board[p->y + y][p->x + x] = 1; // 1 to represent a block
                }
            }
        }
    }
}