#include "shell.h"

/**
 * new_process - Creates a new process to execute a command
 * @args: An Array of string containing the command arguments.
 *
 * Return: 1 on success, -1 on error
 */

int new_process(char **args)
{
	pid_t pid;
	int status;

	if (access(args[0], F_OK) == -1)
	{
		perror(args[0]);
		return (-1);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error in new_process");
			exit(EXIT_FAILURE);
		}

	}

	else if (pid < 0)
	{
		perror("Error in new_process: forking");
	}

	else
	{
		do

		{
			waitpid(pid, &status, WUNTRACED);
		}

		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
