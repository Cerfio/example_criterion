#include <criterion/criterion.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "prototype.h"
#include "structure.h"

bool fail_malloc = false;

void *fake_malloc(size_t size)
{
	if (fail_malloc == true)
		return (NULL);
	return (malloc(size));
}

Test(sample, game_end) {
	cr_assert(check_victory("test") == true);
}

Test(sample, game_no_end) {
	cr_assert(check_victory("test*") == false);
}

Test(sample, true_remplace_word) {
	char *test = strdup("****");
	int number = 3;

	replace_word(test, "test", "t", &number);
	cr_assert(strcmp(test, "t**t") == 0);
	cr_assert(number == 3);
}

Test(sample, false_remplace_word) {
	char *test = strdup("****");
	int number = 3;

	replace_word(test, "test", "p", &number);
	cr_assert(strcmp(test, "****") == 0);
	cr_assert(number == 2);
}

Test(sample, initialize_structure) {
	game_t game = initialize_game("test");

	cr_assert(strcmp(game.word, "test") == 0);
	cr_assert(strcmp(game.hide_word, "****") == 0);
	cr_assert(game.life == 10);
	cr_log_info ("Structure bien initialiser.");
}


Test(loop_game, end_game_lose) {
	game_t game = initialize_game("test");

	game.life = 0;
	cr_assert(loop_game(&game) == 2);
}

Test(check_malloc_loop_game, return_84) {
	game_t game = initialize_game("test");

	fail_malloc = true;
	cr_assert(loop_game(&game) == 84);
	fail_malloc = false;
}
