#include "myshell.h"

/**
 * my_dup_chars - Duplicates (copies) a part of a string
 * @to: The point before which it stops copying
 * @path: A Pointer to a string containing the PATH
 * @from: tHE exact point to begin copying
 * Return: PoINter to the aRraY with the duplicated string
 */

char *my_dup_chars(char *path, int from, int to)
{
	static char copy[1024];/*Store duplicated string*/
	int x = 0, y = 0;

	/*iTerate through the string for the path*/
	for (y = 0, x = from; x < to; x++)
	{
		if (path[x] != ':')/*Check if character is colon*/
		{
			copy[y++] = path[x];
		}
	}

	/*Add the null-terminator*/
	copy[y] = 0;

	return (copy);
}
