#include "myshell.h"
/**
 * my_hsh - keeps the shell in a loop
 * @argv: command-line arguments passed to the progra. dd.
 * @inform: holds SheLl-related infos. dd.
 * Return: [FAILURE] - 1 / an error code; [SUCCES] - 0
 */
int my_hsh(info_t *inform, char **argv)
{
	ssize_t read = 0; /*Result of reading user input*/
	int builtin = 0; /*Return value of built-in shell commands*/

	/*While no error when reading and "exit" not entered as cmd*/
	while (read != -1 && builtin != -2)
	{
		my_clear_info(inform);
		if (my_interactive(inform))
			my_puts("$ ");
		my_eputchar(BUF_FLUSH);
		read = my_get_input(inform);
		if (read != -1)
		{
			my_set_info(inform, argv);
			builtin = my_find_builtin(inform);
			if (builtin == -1)
				my_find_cmd(inform);
		}
		else if (my_interactive(inform))
			my_putchar('\n');
		my_free_info(inform, 0);
	}
	my_write_history(inform);
	my_free_info(inform, 1);
	if (!my_interactive(inform) && inform->status)
		exit(inform->status);
	if (builtin == -2)
	{
		if (inform->err_num == -1)
			exit(inform->status);
		exit(inform->err_num);
	}
	return (builtin);
}
