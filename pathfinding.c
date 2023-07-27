#include "shell.h"

/**
 * get_path_from_env - retrives path from the evironment variables
 *
 * Return: NULL if the path is not found and path valie if it is found
 *
 */

char *get_path_from_env(void)
{
	int x = 0;
	char **environment = environ;
	char *path = NULL;

	while (*environment)
	{
		if (string_n_cmp(*environment, "PATH=", 5))
		{
			path = *environment;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		environment++;
	}
	return (NULL);
}
