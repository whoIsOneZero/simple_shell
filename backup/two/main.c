#include "myshell.h"
/**
 * main - simple shell entery point
 * @ac: number of arguments
 * @av: an array of arguments
 * @env: an array enviroment variables
 *
 * Return: 0 (success), -1 (failure)
 */

int main(int ac, char **av, char **env)
{
	char *command, *argv[3];
	pid_t pid;

	(void)ac; /*Suppress "unused parameter" warning*/
	(void)av;
	while (1)
	{
		command = get_cmd(); /*Get command from the str*/
		if (command == NULL) /*Shell exited: Ctrl+D*/
		{
			break;
		}

		argv[0] = command;
		argv[1] = "/usr/";
		argv[2] = NULL;

		if (run_prog(argv[0], argv, env) == -1)
		{
			free(command);
			return (1);
		}
	free(command);
	}
	return (0);
}
