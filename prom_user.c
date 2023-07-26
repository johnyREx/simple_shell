#include "shell.h"

/**
 * display_prompt - prints $ to take user input
 * Return: no return
 */

void display_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;

	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
