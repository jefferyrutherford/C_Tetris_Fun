#include "game.h"
#include "board.h"
#include "tetromino.h"

// Get Plaform specific sleep function
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void clear_screen() {
   // This ANSI escape code clears the screen and moves the cursor to the top-left
   // Note: System("clear") did not clear the board properly on some terminals
    printf("\033[2J\033[H");
}

void start_game() {
    // Start with a new piece
    Tetromino current_piece = create_tetromino(SHAPE_I);

    // The main game loop
    while (1) {
        // --- 1. Game Logic (Move the piece down) ---
        current_piece.y++;

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
