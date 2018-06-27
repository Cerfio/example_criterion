#pragma once
#include <stdbool.h>
#include "structure.h"

bool check_victory(const char *word);
game_t initialize_game(const char *word);
int loop_game(game_t *game);
void replace_word(char *hide_word, const char *show_word, const char *replace, int *life);
