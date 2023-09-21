#include "myshell.h"

/**
 * my_exit - exits
 * @infos: check header,general info
 * Return:  exit_status
 */
int my_exit(info_t *infos)
{
	int exitcheck;

	if (infos->argv[1])
	{
		exitcheck = my_erratoi(infos->argv[1]);
		if (exitcheck == -1)
		{
			infos->status = 2;
			my_print_error(infos, "Illegal number: ");
			my_eputs(infos->argv[1]);
			my_eputchar('\n');
			return (1);
		}
		infos->err_num = my_erratoi(infos->argv[1]);
		return (-2);
	}
	infos->err_num = -1;
	return (-2);
}
