#include "myshell.h"

/**
 * my_putsfd - prints an input string
 * @s: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int my_putsfd(char *s, int fd)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += my_putfd(*s++, fd);
	}
	return (i);
}
