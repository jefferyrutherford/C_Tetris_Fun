#include "board.h" // Include the header file we just created

// The actual definition of the board array
int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};

// Function to draw the board to the console
void draw_board(Tetromino *p) {
    printf("\n");
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            // First, check if the falling piece occupies this cell
            int is_piece_cell = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (p->shape[i][j] == 1 &&
                        p->y + i == y &&
                        p->x + j == x) {
                        
                        is_piece_cell = 1;
                        break;
                    }
                }
                if (is_piece_cell) break;
            }

            if (is_piece_cell) {
                printf(" # "); // Draw the piece
            } else if (board[y][x] == 0) {
                printf(" . "); // Draw empty space
            } else {
                printf(" # "); // Draw a permanent block
            }
        }
        printf("\n");
    }
}

// A new function to initialize the board
void initialize_board() {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board[y][x] = 0; // Set all cells to empty
        }
    }
}