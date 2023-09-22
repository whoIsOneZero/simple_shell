#include "myshell.h"

/**
 * my_eputs - prints string
 * @str:  string to print
 */

void my_eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		my_eputchar(str[j]);
		j++;
	}
}
