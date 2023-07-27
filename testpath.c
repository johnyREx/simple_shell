#include "shell.h"

/**
 * test_path_validity - checks the validity of the path
 * @path: the separated path
 * @command: command
 *
 * Return: valid path or NULL if not found
 */

char *path_test_validity(char **path, char *command)
{
	int i = 0;
	char *output_value;

	while (path[i])
	{
		output_value = append_path(path[i], command);
		if (access(output_value, F_OK | X_OK) == 0)
			return (output_value);
		free(output_value);
		i++;
	}

	return (NULL);
}
