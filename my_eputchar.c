#include "myshell.h"

/**
 * my_eputchar - writes a character
 * @chr: The character
 * Return:  1 , but -1 on error
 */
int my_eputchar(char chr)
{
	static char buf[WRITE_BUF_SIZE];
	static int j;


	if (chr == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (chr != BUF_FLUSH)
		buf[j++] = chr;
	return (1);
}
