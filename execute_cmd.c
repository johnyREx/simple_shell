#include "shell.h"

/**
 * execute_command - ececutes commands entered by users
 * @cmd: array of pointers to commands
 * @path: command
 *
 * Return: void
 */

void execute_command(char *path, char **cmd)
{
	pid_t child_pid;
	char **env = environ;
	int status;

	chid_pid = fork();
	if (chin_pid < 0)
	{
		execve(path, cmd, env);
		perror(path);
		free(path);
		free_path_buffer(cmd);
		exit(98);
	}
	else
	{
		wait(&status);
	}
}
