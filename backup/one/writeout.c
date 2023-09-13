#include "myshell.h"

/**
 * write_out - prints a char to the standard output
 * @the_msg: a pointer to the char to be printed
 *
 * Return: void
 */

void write_out(const char *the_msg)
{
	write(STDOUT_FILENO, the_msg, strlen(the_msg));
}
