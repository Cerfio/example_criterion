#include <stdio.h>

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
