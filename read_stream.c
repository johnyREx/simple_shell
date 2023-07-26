#include "shell.c"

/**
 * read_stream - Read a line from stream
 *
 * Return: pointer that points to the read line
 */

char *read_stream(void)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		char *err_message = "Allocation error in read_stream";

		write(STDERR_FILENO, err_message, strlen(err_message));
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		characetr = getchar();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}

		else
		{
			line[i] = character;
		}

		i++;

		if (i >= bufsize)
		{
			bufsize += 1024;
			line = realloc(line, sizeof(char) * bufsize);
			if (line == NULL)
			{
				char *err_message = "Reallocation erro in read_stream";

				write(STDERR_FILENO, err_message, strlen(err_message));
				exit(EXIT_FAILURE);
			}
		}
	}
}
