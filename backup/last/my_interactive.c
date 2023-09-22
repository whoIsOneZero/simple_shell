#include "myshell.h"


/**
 * my_interactive - checks if  interactive  mode is on
 * @infos: the address
 *
 * Return: 1 if true, 0 otherwise
 */
int my_interactive(info_t *infos)
{
	return (isatty(STDIN_FILENO) && infos->readfd <= 2);
}
