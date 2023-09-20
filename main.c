#include "myshell.h"
#define MAX_DIGITS 12
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
	int counter;

	(void)ac; /*Suppress "unused parameter" warning*/
	(void)argv;
	counter = 0;
	while (1)
	{
		counter++;

		command = get_cmd(); /*Get command from the user*/
		if (command == NULL || _strcmp(command, "exit") == 0)/*exited:Ctrl+D*/
			break;
		if (_strcmp(command, "Next") == 0)/*Error of Empty space*/
			continue;
	
	splitter(command, " ", tokens, MAX_TOKENS);


	if (run_prog(tokens[0], tokens, env) == -1)
	{
		print_not_found(av[0], counter, command);
		free(command);
		continue;
	}
	free(command);

}
free(command);
return (0);
}




/**
 * print_not_found - prints massage when path not found
 * @av: av[0] of main
 * @counter: counter of argumwnts passed to shell
 * @command: the command that is not found
 */



void print_not_found(char *av, int counter, char *command)
{


	char temp[MAX_DIGITS], *error_prompt;



	intToString(counter, temp);
	error_prompt = malloc(sizeof(av) + (sizeof(" :") * 2) + sizeof(temp)
			      + sizeof(command));
	_strcpy(error_prompt, av);
	_strcat(error_prompt, ": ");
	_strcat(error_prompt, temp);
	_strcat(error_prompt, ": ");
	_strcat(error_prompt, command);
	_strcat(error_prompt, ": not found\n");

	write_out(error_prompt);
	free(error_prompt);



}
