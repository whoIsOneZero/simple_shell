#include "myshell.h"

/**
 * write_out - prints a char to the standard output
 * @the_msg: a pointer to the char to be printed
 *
 * Return: void
 */

void write_out(const char *the_msg)
{
	const char *this_char = the_msg;

	if (the_msg == NULL) /*Handle NULL case*/
	{
		write(STDOUT_FILENO, "(null)", 7);
		return;
	}
	while (*this_char != '\0')
	{
		/*Print each char iteratively*/
		write(1, this_char, 1);
		this_char++;
	}
}
