#include <string.h>
#include "structure.h"

game_t initialize_game(const char *word)
{
	game_t game;
	int i = 0;

	game.life = 10;
	game.word = (char *)word;
	game.hide_word = strdup(word);
	while (game.hide_word[i]) {
		game.hide_word[i] = '*';
		i++;
	}
	return (game);
}
