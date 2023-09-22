#include "myshell.h"

/**
 * my_isalpha - if char is alphabetic.
 * @chr: char in question
 * Return: 1 if true, else 0
 */

int my_isalpha(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	else
		return (0);
}
