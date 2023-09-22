#include "myshell.h"

/**
 * my_strncpy - to copy string
 * @dest:  destination. dd.
 * @src:  source. dd.
 * @n: number of chars
 * Return: the resulted string
 */

char *my_strncpy(char *dest, char *src, int n)
{
	char *temp = dest;
	int j, i;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (temp);
}
