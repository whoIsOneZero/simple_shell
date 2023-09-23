#include "myshell.h"



/**
 * my_puts - 'echo' a string to stdout. dd.
 * @s: string you want to print. dd.
 */



void my_puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		my_putchar(s[i]);
		i++;
	}
}

