#include "myshell.h"


/**
 * my_cd - to change directory
 * @infos: check header,general info
 * Return: 0
 */

int my_cd(info_t *infos)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		my_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!infos->argv[1])
	{
		dir = my_getenv(infos, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = my_getenv(infos, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (my_strcmp(infos->argv[1], "-") == 0)
	{
		if (!my_getenv(infos, "OLDPWD="))
		{
			my_puts(s);
			my_putchar('\n');
			return (1);
		}
		my_puts(my_getenv(infos, "OLDPWD=")), my_putchar('\n');
		chdir_ret =
			chdir((dir = my_getenv(infos, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(infos->argv[1]);
	if (chdir_ret == -1)
	{
		my_print_error(infos, "can't cd to ");
		my_eputs(infos->argv[1]), my_eputchar('\n');
	}
	else
	{
		my_setenv(infos, "OLDPWD", my_getenv(infos, "PWD="));
		my_setenv(infos, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
