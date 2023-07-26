#include "shell.h"

/**
 * shell_interactive - UNIX command line when interactive
 * This function displays a prompt and waits for the user to type.
 * The command line always ends with a new line.
 *
 * Return: void
 */

void shell_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do

	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		line = read_line();
		args = split_line(line);
		status = execute_args(args);

		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	}

	while (status == -1);
}

/**
 * read_line - Read a line from stdin
 *
 * Return: A pointer to the line from stdin
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		else
		{
			write(STDERR_FILENO, "error while reading line from stdin", 34);
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

/**
 * split_line - split a string into tokens
 * @line: The input string to be tokenized
 *
 * Return: An array of strings (tokens)
 */

char **split_line(char *line)
{
	const int buf_size = 64;
	const char *delimeters = " \t\n";

	int bufsize = buf_size;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		write(STDE_FILENO, "Allocation error\n", 17);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimeters);

	while (token)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			buf_size += buf_size;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				write(STDERR_FILENO, "Allocation error\n", 17);
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delimeters);
	}

	tokens[position] = NULL;

	return (tokens);
}

