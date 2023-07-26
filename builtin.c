#include "shell.h"

/**
 * handle_builtin_commands - handles shell builtin commands
 * @argv: command entered
 *
 * Return: 1 if the builtin is handled
 */

int handle_builtin_commands(char **argv)
{
	if (strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			if (chdir(argv[1]) == -1)
			{
				perror("cd");
			}
		}
		return (1);
	}
	else if (strcmp(argv[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}
