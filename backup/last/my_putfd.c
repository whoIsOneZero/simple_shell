#include "myshell.h"

/**
 * my_putfd - write char to fd
 * @chr: character to print
 * @fd: file  descriptor
 *
 * Return: 1, but -1 on error
 */

int my_putfd(char chr, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (chr != BUF_FLUSH)
		buf[j++] = chr;
	return (1);
}
