#include "myshell.h"

/**
 * my_unsetenv - delete environment variable
 * @infos: check header,general info
 * Return: 0
 */


int my_unsetenv(info_t *infos)
{
	int i;

	if (infos->argc == 1)
	{
		my_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= infos->argc; i++)
		my_unsetenv(infos, infos->argv[i]);

	return (0);
}
