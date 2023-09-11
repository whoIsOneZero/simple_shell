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
	pid_t pid;


	(void)ac;
	(void)av;
	while (1)
	{
		command = get_cmd();
		if (comand == NULL)
		{
			break;
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
