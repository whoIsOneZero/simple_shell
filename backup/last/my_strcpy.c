#include "myshell.h"

/**
 * my_strcpy - for copying a string. dd.
 * @dest: wher to copy to. dd.
 * @src: where to copy from. dd.
 * Return: a pointer to the copied string
 */
char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

