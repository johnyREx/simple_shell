#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main- Entry point of the shell
 * @argc: The number of command line arguments
 * @argv: An array of strings consisting of command line arguments
 *
 * Return: EXIT SUCCESS if the shell runs successfully.
 */

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		shell_interactive();
	}

	else if (argc == 2)
	{
		freopen(argv[1], "r", stdin);
		shell_no_interactive();
	}

	else
	{
		fprint(stderr, "Usage: %s [file]\n", argv[0]);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
