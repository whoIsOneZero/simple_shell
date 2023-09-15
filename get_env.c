#include "myshell.h"

/**
 * _getenv - return the value of env variable
 * @name: the name of variable
 * Return: the value as list of char
 */

char *_getenv(const char *name)
{
	size_t var_len;
	char *equals;

	if (name == NULL || environ == NULL)
	{
		return NULL;
	}


	for (int i = 0; environ[i] != NULL; i++)
	{
		equals = strchr(environ[i], '=');

		if (equals != NULL)
		{
			var_len = equals - environ[i];

			if (strncmp(environ[i], name, var_len) == 0 && name[var_len] == '\0')
			{
				return (equals + 1);
			}
		}
	}

	/* If the environment variable is not found, return NULL */
	return NULL;
}
