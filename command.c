#include "shell.h"

/**
 * own_cd - Implements the 'cd' command.
 *
 * Return: Always return 0
 */

int own_cd(void)
{
	write(1, "Please wait... \n", 18);
	return (0);
}

/**
 * own_env - Implements the 'env' command.
 *
 * Return: Always return 0
 */

int own_env(void)
{
	write(1, "Please wait ... \n", 19);
	return (0);
}

/**
 * own_help - Implements the 'help' command.
 *
 * Return: Always return 0
 */

int own_help(void)
{
	write(1, "Please wait ... \n", 19);
	return (0);
}

/**
 * own_exit - Implements the 'exit' command.
 *
 * Return: Always return 0
 */

int own_exit(void)
{
	write(1, "Please wait... \n", 18);
	return (0);
}
