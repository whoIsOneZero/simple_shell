#include "myshell.h"

/**
 * my_find_path - search for the command in the Dirs. in pATh
 * @prog: the executable (command) to be foind
 * @path: The PATH (environmental variable)
 * @info: apointer to the info_t struct
 * Return: [CMD FOUND] - the full path; [NOT FOUND] - NULL
 */
char *my_find_path(info_t *info, char *path, char *prog)
{
	int a = 0, current = 0;
	char *path;

	if (!path)
	{
		return (NULL);
	}
	/*If prog starts with "./" and is a valid command*/
	if ((my_strlen(prog) > 2) && my_starts_with(prog, "./"))
	{
		if (my_is_cmd(info, prog))
			return (prog);
	}

	while (1)
	{
		if (!path[a] || path[a] == ':')
		{
			path = my_dup_chars(path, current, a);
			if (!*path)
				my_strcat(path, prog);
			else
			{
				my_strcat(path, "/");
				my_strcat(path, prog);
			}

			if (my_is_cmd(info, path))
				return (path);
			if (!path[a])
				break;
			current = a;
		} a++;
	}
	return (NULL);

}
