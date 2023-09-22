#include "myshell.h"


/**
 * my_putchar - prints out a character. dd.
 * @charac: char to be printed. dd.
 *
 * Return: [1]- success; [-1] - error and sets errno
 */
int my_putchar(char charac)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (charac == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (charac != BUF_FLUSH)
		buf[m++] = charac;
	return (1);
}

