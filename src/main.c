#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h> 

typedef struct {
	char *word;
	char *hide_word;
	int life;
	clock_t time;
}game_t;

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
	game.time = clock();
	return (game);
}

bool check_victory(const char *word)
{
	int i = 0;

	while (word[i]) {
		if (word[i] == '*')
			return (false);
		i++;
	}
	return (true);
}

void replace_word(char *hide_word, const char *show_word, const char *replace, int *life)
{
	int i = 0;
	int save_life = *life + 1;

	while (show_word[i]) {
		if (show_word[i] == replace[0]) {
			hide_word[i] = replace[0];
			*life = save_life;
		}
		i++;
	}
	*life = *life - 1;
	puts(hide_word);
}

int loop_game(game_t *game)
{
	char *input = malloc(sizeof(char) * 2);

	if (input == NULL)
		return (84);
	puts(game->hide_word);
  	while  (game->life != 0) {
		game->time = clock();
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

int main(int ac, char **av)
{
	game_t game;
	int return_function;

	if (ac != 2) {
		puts("Veuillez rentrer un mot");
		return (84);
	}
	game = initialize_game(av[1]);
	return_function = loop_game(&game);
	if (return_function == 1)
		puts("You are Win");
	else if (return_function == 2) {
		puts("You are Lose\nThe word is ");
		puts(game.word);
	}
	else
		puts("Problem during program");
	printf("Vous avez mis %f\n", (double)game.time/CLOCKS_PER_SEC);
	free(game.hide_word);
	return(return_function);
}
