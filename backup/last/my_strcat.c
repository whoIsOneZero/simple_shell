#include "myshell.h"

/**
 * my_strncat - concatenates two strings
 * @dest:  first
 * @src: second
 * @n: max number of letters
 * Return: resulted string
 */
char *my_strncat(char *dest, char *src, int n)
{
	int j, i;
	char *temp = dest;

	j = 0;
	i = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (temp);
}
