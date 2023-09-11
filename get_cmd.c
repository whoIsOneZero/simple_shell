#include "myshell.h"

/**
 * get_cmd - reads the string (command) from stdin
 *
 * Return: a pointer to the command, in order to be freed
 */

char *get_cmd(void)
{
	char *cmd = NULL; /*command*/
	size_t bufsize = 0; /*The size of the buffer pointed to*/
	ssize_t bytes_read; /*Num of chars read from stdin including \n*/

	prompt_user();
	fflush(stdout);

	bytes_read = getline(&cmd, &bufsize, stdin);

	if (bytes_read == -1)
	{
		/* Check if getline returns -1 due to EOF (Ctrl+D)*/
		write(1, "\n", 1);
		fflush(stdin);
		return NULL;
	}

	if (bytes_read > 0 && cmd[bytes_read - 1] == '\n')
	{
		cmd[bytes_read - 1] = '\0';
	}

	return (cmd);
}
