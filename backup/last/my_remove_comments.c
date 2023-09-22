#include "myshell.h"

/**
 * my_remove_comments - replace # with '\0'
 * @buf:  string adress
 */
void my_remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
