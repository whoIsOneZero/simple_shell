#include "myshell.h"

/**
 * my_atoi - string to integer
 * @str: string
 * Return: the converted result, 0 if string is not numbers
 */

int my_atoi(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int converted = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			converted *= 10;
			converted += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -converted;
	else
		output = converted;

	return (output);
}
