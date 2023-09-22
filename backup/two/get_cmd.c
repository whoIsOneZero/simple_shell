#include "myshell.h"

/**
 * get_cmd - reads the string (command) from stdin
 *
 * Return: a pointer to the command, in order to be freed
 */

char *get_cmd(void)
{
	char *cmd = NULL; /*command*/
	size_t bufsize ; /*The size of the buffer pointed to*/
	ssize_t bytes_read; /*Num of chars read from stdin including \n*/
	int i;

	prompt_user();
	fflush(stdout);
	bytes_read = getline(&cmd, &bufsize, stdin);

	if (bytes_read == -1)
	{
		if (feof(stdin))
		{
		/* Check if getline returns -1 due to EOF (Ctrl+D)*/
			free(cmd);
			return (NULL);
		}
		else
		{
			perror("Read_FAIL");
			free(cmd);
			return ("Next"); /*Go to next line*/
		}
	}

	/*Replace new line with null terminating charac*/
	if (bytes_read > 0 && cmd[bytes_read - 1] == '\n')
	{
		cmd[bytes_read - 1] = '\0';
	}

	for (i = 0; isspace(cmd[i]); i++) /*Skip all leading spaces*/
		continue;

	if (cmd[i] == '\0') /*Treat the empty lines as spaces*/
	{
		free(cmd);
		return ("Next"); /*Go to next line*/
	}
	return (cmd);
}
