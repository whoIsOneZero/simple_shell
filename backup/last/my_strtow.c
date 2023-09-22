#include "myshell.h"

/**
 * **my_strtow - for splitting a given string into two words.
 * @s: string to be splitter
 * @delim: delimiter to use (string). dd.
 * Return: [SUCCESS]- pointer to arr of s; [FAIL]- NULL
 */

char **my_strtow(char *s, char *delim)
{
	int a, b, c, m, num = 0;
	char **s;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (a = 0; s[a] != '\0'; a++)
		if (!is_delim(s[a], delim) && (is_delim(s[a + 1], delim) || !s[a + 1]))
			num++;

	if (num == 0)
		return (NULL);
	s = malloc((1 + num) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < num; b++)
	{
		while (is_delim(s[a], delim))
			a++;
		c = 0;
		while (!is_delim(s[a + c], delim) && s[a + c])
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}

