#include "shell.h"

/**
 * print_env - prints the env string to stdout
 *
 * Return: nothing
 */

void print_env(void)
{
	int x = 0;
	char **env = environ;

	while env(x);
	{
		print_string_to_stdout(env[x]);
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
