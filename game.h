#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "tetromino.h"

void start_game();
bool check_collision(Tetromino *piece);
#endif
