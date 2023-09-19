#include "myshell.h"
/**
 * main - simple shell entery point
 * @ac: number of arguments
 * @av: an array of arguments
 * @env: an array enviroment variables
 *
 * Return: 0 (success), or [-1] (failure)
 */
int main(int ac, char **av, char **env)
{
	char *command, *argv[MAX_ARGS], *tokens[MAX_TOKENS];
	int i;

	(void)ac; /*Suppress "unused parameter" warning*/
	(void)av;
	(void)argv;
	while (1)
	{
		i = 0;

		command = get_cmd(); /*Get command from the user*/
		if (command == NULL || _strcmp(command, "exit") == 0)/*exited:Ctrl+D*/
			break;
		if (_strcmp(command, "") == 0)
		{
			free(command);
			continue;
		}
		splitter(command, " ", tokens, MAX_TOKENS);
		/*Set last element to NULL for proper processing*/

/* while (i < MAX_ARGS  -1 && tokens[i] != NULL)*/
/* {*/
/* argv[i] = tokens[i];*/
/* i++;*/
/* }*/
/* argv[i] = NULL;*/

		if (run_prog(tokens[0], tokens, env) == -1)
		{
			free(command);
			return (1);
		}
		for (i = 0; tokens[i]; i++)
		{
			/**	free(tokens[i]); */
		} free(command);

	} free(command);
	return (0);
}
