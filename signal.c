#include "shell.h"

/**
 * handle_signal - track if shell is interactive mode
 * @m: signal number
 * Return: void
 */

void handle_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
