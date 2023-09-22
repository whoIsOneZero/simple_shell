#include "myshell.h"
/**
 * my_strcmp - compares Two sTrings character by character. dd.
 * str1: first string to be compared. dd.
 * str2: second string to be compared. dd.
 * Return: [0] - 1st=2nd; [1] - 1st>2nd; [-1] - 1st<2nd
 */

int my_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

