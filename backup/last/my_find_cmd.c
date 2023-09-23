#include "myshell.h"

/**
 * my_find_cmd - find and execute with dir's listed in PATH
 * @inform: info about e current shell state. dd.
 */

void my_find_cmd(info_t *inform)
{
	char *path = NULL;
	int a, b;

	inform->path = inform->argv[0];
	if (inform->linecount_flag == 1)
	{
		inform->line_count++;
		inform->linecount_flag = 0;
	}
	for (a = 0, b = 0; inform->arg[a]; a++)
		if (!my_is_delim(inform->arg[a], " \t\n"))
			b++;
	if (!b)
		return;

	path = my_find_path(inform, my_getenv(inform, "PATH="), inform->argv[0]);
	if (path)
	{
		inform->path = path;
		my_fork_cmd(inform);
	}
	else
	{
		if ((my_interactive(inform) || my_getenv(inform, "PATH=")
					|| inform->argv[0][0] == '/') && my_is_cmd(inform, inform->argv[0]))
			my_fork_cmd(inform);
		else if (*(inform->arg) != '\n')
		{
			inform->status = 127;
			my_print_error(inform, "not found\n");
		}
	}
}

