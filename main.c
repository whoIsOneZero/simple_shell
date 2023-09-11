#include "myshell.h"
/**
 * main - simple shell entery point
 * @ac:number of arguments
 * @av: array of arguments
 * @env: enviroment variables
 */

int main(int ac, char **av, char **env)
{
	char *command, *argv[3];
	size_t bufsize = 0;
	ssize_t bytes_read;
	pid_t pid;


	(void)ac;
	(void)av;
	while (1)
	{
		prompt_user();
		fflush(stdout);

		bytes_read = getline(&command, &bufsize, stdin);


		if (bytes_read == -1)
		{
			/* Check if getline returns -1 due to EOF (Ctrl+D)*/
			putchar('\n');
			fflush(stdin);
			break;
		}

		if (bytes_read > 0 && command[bytes_read - 1] == '\n')
		{
			command[bytes_read - 1] = '\0';
		}

		argv[0] = command;
		argv[1] = "/usr/";
		argv[2] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		wait(NULL);
		/* handle the entered command on the next line */
		if (pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror("Error:");
			}
			break;
		}
	}


	free(command);

	return (0);
}
