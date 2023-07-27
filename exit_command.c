#include "shell.h"

/**
 * handle_exit - exit command and free buffers
 * @cmd: tokenized command
 * @line: line from getline
 *
 * Return: no return
 */

void handle_exit(char **cmd, char *line)
{
	free(line);
	free_buffers(cmd);
	exit(0);
}
