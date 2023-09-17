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
	char *command, *argv[MAX_ARGS], *tokens[MAX_TOKENS];
	/*pid_t pid;*/ /*Unused variable*/
	int i;

	(void)ac; /*Suppress "unused parameter" warning*/
	(void)av;
	while (1)
	{
		i = 0;

		command = get_cmd(); /*Get command from the str*/
		if (command == NULL || _strcmp(command, "exit") == 0) /* exited: Ctrl+D*/
			break;
		if (_strcmp(command, "") == 0)
		{
			free(command);
			continue;

		}

		splitter(command, " ", tokens, MAX_TOKENS);

		/*Set last element to NULL for proper processing*/
		while (i < MAX_ARGS - 1 && tokens[i] != NULL)
		{
			argv[i] = tokens[i];
			i++;
		}
		argv[i] = NULL;

		if (run_prog(argv[0], argv, env) == -1)
		{
			free(command);
			return (1);
		}
		while (i >= 0)
		{
			argv[i] = NULL;
			tokens[i] = NULL;
			i--;
		}
		free(command);

	}

	free(command);

	return (0);
}
