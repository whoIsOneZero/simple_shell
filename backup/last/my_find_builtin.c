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
		{"exit", my_myexit},
		{"env", my_myenv},
		{"help", my_myhelp},
		{"history", my _myhistory},
		{"setenv", my_mysetenv},
		{"unsetenv", my_myunsetenv},
		{"cd", my_mycd},
		{"alias", my_myalias},
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

