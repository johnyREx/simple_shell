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

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
		return;
	}

	
	if (child_pid == 0)
	{
		if (execve(path, cmd, env) == -1)
		{
			perror("Execution Error");
			free_buffers(cmd);
			exit(98);
		}
	}
	else
	{
		wait(&status);
	}
}
