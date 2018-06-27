#include <stdbool.h>

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
