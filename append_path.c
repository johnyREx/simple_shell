#include "shell.h"

/**
 * append_path - concatenates the path and command
 * @path: path
 * @cmd: command
 *
 * Return: buffer on success, NULL on failure
 */

char *append_path(char *path, char *cmd)
{
	char *buffer;
	size_t i = 0, j = 0;

	if (cmd == NULL)
		cmd = "";

	if (path == NULL)
		path = "";

	buffer = malloc(sizeof(char) * (string_length(path) + string_length(cmd) + 2));

			if (!buffer)
				return (NULL);

			while (path[i])
			{
				buffer[i] = path[i];
				i++;
			}

			if (path[i - 1] != '/')
			{
				buffer[i] = '/';
				i++;
			}

			while (cmd[i])
			{
				buffer[i + j] = cmd[j];
				j++;
			}

			while (cmd[j])
			{
				buffer[i + j] = cmd[j];
				j++;
			}

			buffer[i + j] = '\0';
			return (buffer);

}
