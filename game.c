#include "game.h"
#include "board.h"
#include "tetromino.h"

#include <stdio.h>
#include <stdbool.h>
#include <time.h>


#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#endif


void handle_input(Tetromino *p);
void rotate(Tetromino *p);

// check the piece for collition.
bool check_collision(Tetromino *piece) {
    // Placeholder for collision detection logic
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece->shape[i][j]) { // If there's a block in this part of the tetromino
                int board_x = piece->x + j;
                int board_y = piece->y + i;

               //1. Check collition with the floor
                if (board_y >= BOARD_HEIGHT) {
                    return true;
                }
                //2. Check collition with the walls
                if (board_x < 0 || board_x >= BOARD_WIDTH) {
                    return true;
                }
                //3. Check collition with other locked pieces
                if (board_y >= 0 && board[board_y][board_x]) {
                    return true;
                }
            }
        }
    }
    return false;
}

// lock the piece on the board
void lock_piece(Tetromino *p) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (p->shape[y][x] == 1) {
                // IMPORTANT: We only write to the board if the block is on or below row 0
                if (p->y + y >= 0) {
                    board[p->y + y][p->x + x] = 1;
                }
            }
        }
    }
}

void clear_screen() {
   // This ANSI escape code clears the screen and moves the cursor to the top-left
   // Note: System("clear") did not clear the board properly on some terminals
    printf("\033[2J\033[H");
}

void start_game() {
    srand((unsigned int)time(NULL));

    // Start with a new piece
    Tetromino current_piece = create_random_tetromino();

    // The main game loop
    while (1) {
        handle_input(&current_piece);

        // --- 1. Game Logic (Move the piece down) ---
        Tetromino next_check_piece = current_piece;
        next_check_piece.y++;

         if (!check_collision(&next_check_piece)) {
            current_piece.y++; // SAFE: Move the actual piece down
        } else {
            printf("Collision detected at y=%d\n", current_piece.y);
            lock_piece(&current_piece);
            current_piece = create_random_tetromino(); // Spawn a new piece
        }
        // --- 2. Rendering (Clear and redraw) ---
        clear_screen();
        //draw_tetromino(&current_piece); // Draw the piece at its new position
        draw_board(&current_piece);                   // Draw the board (underneath the piece)

        // --- 3. Delay for a smooth drop rate ---
        #ifdef _WIN32
            Sleep(500); // 500 milliseconds
        #else
            usleep(500000); // 500,000 microseconds = 0.5 seconds
        #endif
    }
}

void handle_input(Tetromino *current_piece) {
    char input;
    // _getch() is a blocking call; need to check if a keyboard key was pressed.
    // https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/kbhit?view=msvc-170
    while (_kbhit()) {
        input = _getch(); // Read the key only if one is available
    }

    Tetromino next_check_piece = *current_piece;
    
    // move left
    if (input == 'a') {
        next_check_piece.x--;
    }
    // move right
    else if (input == 'd') {
        next_check_piece.x++;
    }
    // move down
    else if (input == 's') {
        next_check_piece.y++;
    }
    else if (input == 'w') {
        // rotate piece clockwise
        rotate(&next_check_piece);
    }
    // can we move the piece?
    if (!check_collision(&next_check_piece)) {
            *current_piece = next_check_piece; 
    }

}

void rotate(Tetromino *p) {
    int temp_shape[4][4];

    // Transpose the matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp_shape[j][i] = p->shape[i][j];
        }
    }

    // Reverse each row to get a clockwise rotation
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            p->shape[i][j] = temp_shape[i][3 - j];
        }
    }

    // Update rotation state
    p->rotation = (p->rotation + 1) % 4;
}

