#include "shell.h"

/**
 * main - main fuction
 * @ac: argument counter
 * @av: argument vector
 * @envp: environment vector
 *
 * Return: 0 on success
 */

int main(int ac, char **av, char *envp[])
{
	char *line = NULL;
	char *path_command = NULL;
	char *path = NULL;
	size_t buffer_size = 0;
	ssize_t line_size = 0;
	char **command, **paths = NULL;
	(void)envp;
	(void)av;

	if (ac < 1)
	{
		return (-1);
	}
	signal(SIGINT, handle_signal);
	while (1)
	{
		free_buffer_array(command);
		free_buffer_array(paths);
		free(path_command);
		display_prompt();

		line_size = getline(&line, &buffer_size, stdin);

		if (line_size < 0)
		{
			break;
		}
		info.ln_count++;
		if (line[line_size - 1] == '\n')
		{
			line[line_size - 1] = '\0';
		}
		command = tokenize_string(line);
		if (command == NULL || *command == NULL || **command == '\0')
		{
			continue;
		}
		if (check_builtin(command, line))
		{
			path = get_path_from_env();
			paths = tokenize_string(path);
			path_command = path_test_validity(paths, command[0]);
		}
		if (!path)
		{
			perror(av[0]);
		}
		else
		{
			execute_command(path_command, command);
		}
	}
	if (line_size < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
