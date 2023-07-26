#include "shell.h"

/**
 * execute_command - a function that executes commands
 * when the shell is interactive
 * @argv: the command passed to the shell
 *
 * Return: Nothing
 */

void execute_command(char **argv)
{
	int status;
	char *err_msg;
	char *newline;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			err_msg = ("./shell: No such file or directory");
			write(STDERR_FILENO, err_msg, strlen(err_msg));
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			newline = "\n";
			write(STDERR_FILENO, newline, strlen(newline));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
