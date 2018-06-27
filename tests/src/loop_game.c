#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "structure.h"
#include "prototype.h"

void *fake_malloc(size_t size);

int loop_game(game_t *game)
{
	char *input = fake_malloc(sizeof(char) * 2);

	if (input == NULL)
		return (84);
	puts(game->hide_word);
  	while  (game->life != 0) {
		read(0, input, 1);
		input[1] = '\0';
		if (input[0] == '\n')
			continue;
		replace_word(game->hide_word, game->word, input, &game->life);
		if (check_victory(game->hide_word) == true) {
			free(input);
			return (1);
		}
	}
	free(input);
	return (2);
}
