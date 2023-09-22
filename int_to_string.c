#include "myshell.h"

/**
 * intToString - converts int to string
 * @num: the int
 * @str: the resulted string
 */


void intToString(int num, char *str)
{
	int i = 0, start, end;
	int isNegative = 0;

	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}

	if (num == 0)
	{
		str[i++] = '0';
	}

	while (num > 0)
	{
		int digit = num % 10;

		str[i++] = '0' + digit;
		num /= 10;
	}

	if (isNegative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	start = 0;
	end = i - 1;
	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
