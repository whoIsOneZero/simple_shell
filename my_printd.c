#include "myshell.h"

/**
 * my_print_d - to print decimal number
 * @input: input
 * @fd:  file descriptor
 *
 * Return:f characters  number
 */
int my_print_d(int input, int fd)
{
	int (*_my_putchar)(char) = my_putchar;
	int j, counts = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		_my_putchar = my_eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		_my_putchar('-');
		counts++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			_my_putchar('0' + current / j);
			counts++;
		}
		current %= j;
	}

	_my_putchar('0' + current);
	counts++;

	return (counts);
}
