#include "myshell.h"


/**
 * my_help - cd for process
 * @infos: check header,general info
 * Return: 0
 */

int my_help(info_t *infos)
{
	char **arg_array;

	arg_array = infos->argv;
	my_puts("to be contioued \n");
	if (0)
		my_puts(*arg_array);
	return (0);
}
