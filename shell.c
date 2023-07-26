#include "shell.h"

/**
 * main - a function that displays an intaractive shell prompt
 * @argc: number of arguments passed
 * @argv: pointer to the arguments passsed
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char *line_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = "\n";
	int num_tokens = 0;
	char *token;
	int i;
	int is_interactive;
	(void)argc;

	is_interactive = isatty(STDIN_FILENO);
	while (is_interactive || (nchars_read = getline(&line, &n, stdin)) != -1)
	{
		if (is_interactive)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
			nchars_read = getline(&line, &n, stdin);
			if (nchars_read == -1)
			{
				write(STDERR_FILENO, "Exit shell...\n", 13);
				return (-1);
			}
		}
		line_copy = malloc(sizeof(char) * nchars_read);
		if (line_copy == NULL)
		{
			perror("hsh: Memory allocation error");
			return (-1);
		}
		strcpy(line_copy, line);
		token = strtok(line, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens = 0;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(line_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		if (argv[0] == NULL)
		{
			for (i = 0; argv[i] != NULL; i++)
			{
				free(argv[i]);
			}
			free(argv);
			continue;
		}
		if (handle_builtin_commands(argv))
		{
			for (i = 0; argv[i] != NULL; i++)
			{
				free(argv[i]);
			}
			free(argv);
			continue;
		}
		execute_command(argv);
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(line);
		free(line_copy);
	}
	read_user_input();
	return (0);
}
