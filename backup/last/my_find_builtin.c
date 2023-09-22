#include "myshell.h"
/**
 * my_find_builtin - search for & execute built-in commands. dd .
 * @inform: Information about e current shell state. dd.
 *
 * Return: [1]- found, execution failed. [2]- command is "exit"
 * [-1]- prog not found. [0]- found & executed
 */
int my_find_builtin(info_t *inform)
{
	int z, prog_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", my_exit},
		{"env", my_env},
		{"help", my_help},
		{"history", my_history},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", my_cd},
		{"alias", my_alias},
		{NULL, NULL}
	};

	for (z = 0; builtintbl[z].type; z++)
		if (my_strcmp(inform->argv[0], builtintbl[z].type) == 0)
		{
			inform->line_count++;
			prog_ret = builtintbl[z].func(inform);
			break;
		}
	return (prog_ret);
}
