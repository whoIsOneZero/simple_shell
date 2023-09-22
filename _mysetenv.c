#include "myshell.h"

/**
 * _mysetenv - make a new environment variable.
 * @infos: check header,general info
 *  Return: 0
 */

int _mysetenv(info_t *infos)
{
	if (infos->argc != 3)
	{
		my_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (my_setenv(infos, infos->argv[1], infos->argv[2]))
		return (0);
	return (1);
}
