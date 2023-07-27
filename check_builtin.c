#include "shell.h"

/**
 * check_builtin - checks if a function uis builtin
 * @cmd: separates inputs
 * @buffer: line from getline
 *
 * Return: 1 if built in othewise 0
 */

int check_builtin(char **cmd, char *buffer)
{
	if (handle_builtin(cmd, buffer))
	{
		return (1);
	}
	else if (**cmd == '/')
	{
		execute_command(cmd[0], cmd);
		return (1);
	}
	return (0);
}
