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
	char **str;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (a = 0; s[a] != '\0'; a++)
		if (!my_is_delim(s[a], delim) && (my_is_delim(s[a + 1], delim) || !s[a + 1]))
			num++;

	if (num == 0)
		return (NULL);
	str = malloc((1 + num) * sizeof(char *));
	if (!str)
		return (NULL);
	for (a = 0, b = 0; b < num; b++)
	{
		while (my_is_delim(s[a], delim))
			a++;
		c = 0;
		while (!my_is_delim(s[a + c], delim) && s[a + c])
			c++;
		str[b] = malloc((c + 1) * sizeof(char));
		if (!str[b])
		{
			for (c = 0; c < b; c++)
				free(str[c]);
			free(str);
			return (NULL);
		}

		for (m = 0; m < c; m++)
			str[b][m] = s[a++];
		str[b][m] = 0;
	}
	str[b] = NULL;
	return (str);
}
