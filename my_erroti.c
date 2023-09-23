#include "myshell.h"

/**
 * my_erratoi - string to an integer
 * @str:  string to convert
 * Return:  converted number.
 */

int my_erratoi(char *str)
{
	int j = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;
	for (j = 0;  str[j] != '\0'; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			result *= 10;
			result += (str[j] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
