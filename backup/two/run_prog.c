#include "myshell.h"

/**
 * run_prog - executes a command (program) with given arguments
 * @prog: the program to run
 * @args: an array of arguments including the program file name
 * @env: environment variables
 * Return: 0 (success), -1 (failure)
 */
int run_prog(char *prog, char *const args[], char *const env[])
{
	struct stat st;
	char *full_prog;
	pid_t pid;

	full_prog = malloc(sizeof(char) * (_strlen(prog) + 1));
	_strcpy(full_prog, prog);
	if (stat(prog, &st) != 0)
	{
		if (check_in_path(full_prog) != 0)
		{
			free(full_prog);
			return (-1);
		}
	}
	/*Create child process and run the command in it*/
	pid = fork();

	if (pid == -1) /*fork() failed*/
	{
		free(full_prog);
		return (-1);
	}
	if (pid == 0) /*child process created*/
	{

	/*Execute the specified program*/
		if (execve(full_prog, args, env) == -1)
		{
			free(full_prog);
			return (-1);
		} free(full_prog);
		exit(EXIT_SUCCESS);
	}

	/*Parent should wait for child process to complete exit*/
	wait(NULL);
	free(full_prog);
	return (0);
}
