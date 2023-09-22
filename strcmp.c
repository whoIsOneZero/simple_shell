#include "myshell.h"

/**
 * _strcmp - compare to st.
 * @s1: the first string
 * @s2: the second string
 *
 * Return:  like real strcmp,0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
