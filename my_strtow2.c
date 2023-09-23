#include "myshell.h"

/**
 * **my_strtow2 - another that separates stringsinto words
 * @s: the string to be split
 * @delim: the delimeter (string). dd.
 * Return: [SUCCESS] - ptr to arr of str; [FAILURE] - NULL
 */
char **my_strtow2(char *s, char delim)
{
	int a, b, c, m, num = 0;
	char **str;

	if (s == NULL || s[0] == 0)
		return (NULL);
	for (a = 0; s[a] != '\0'; a++)
		if ((s[a] != delim && s[a + 1] == delim) ||
				    (s[a] != delim && !s[a + 1]) || s[a + 1] == delim)
			num++;
	if (num == 0)
		return (NULL);
	str = malloc((1 + num) * sizeof(char *));
	if (!str)
		return (NULL);
	for (a = 0, b = 0; b < num; b++)
	{
		while (s[a] == delim && s[a] != delim)
			a++;
		c = 0;
		while (s[a + c] != delim && s[a + c] && s[a + c] != delim)
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
