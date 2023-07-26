#include "shell.h"

/**
 * handle_builtin - handles the builtin functions
 * @cmd: array of commands
 * @line: input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */

int handle_builtin(char **cmd, char *line)
{
	struct builtin builtins = {"env", "exit"};

	if (string_compare(*cmd, builtins.env) == 0)
	{
		print_env();
		return (1);
	}

	else if (string_compare(*cmd, builtins.exit) == 0)
	{
		handle_exit(cmd, line);
		return (1);
	}

	return (0);
}
