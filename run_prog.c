#include "myshell.h"

/**
 * run_prog - executes a command (program) with given arguments
 * @prog: the program to run
 * @args: an array of arguments including the program file name
 * @env: environment variables
 * Return: 0 (success), -1 (failure)
 */
int run_prog(const char *prog, char *const args[], char *const env[])
{
	/*Create child process and run the command in it*/
	pid_t pid = fork();

	if (pid == -1) /*fork() failed*/
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0) /*child process created*/
	{
		/*Execute the specified program*/
		if (execve(prog, args, env) == -1)
		{
			perror("Error");
			return (-1);
		}
		exit(EXIT_SUCCESS);
	}

	/*Parent should wait for child process to complete exe*/
	wait(NULL);

	return (0);
}
