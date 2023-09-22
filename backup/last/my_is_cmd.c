#include "myshell.h"

/**
 * my_is_cmd - check if file specified by PATH is an executable program
 * @path: the absolute path to file which may be an executable or not
 * @inform: pointer to information about the structure
 * Return: [IS EXECUTABLE] - 1; [NOT EXEC.] - 0
 */
int my_is_cmd(info_t *inform, char *path)
{
	struct stat st;

	void(inform); /*Suppress unused parameter warning*/

	if (!path || stat(path, &st)) /*If path NULL, system call fails*/
		return (0);

	if (st.st_mode & S_IFREG) /*If it's a regular file*/
	{
		return (1);
	}

	/*Not an executable*/
	return (0);
}
