#include "shell.h"

void free_buffers(char **buffer);

/**
 * tokenize_string - creates tokens from input string
 * @line: input string
 * Return: array of tokens
 */

char **tokenize_string(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int token_size = 1;
	size_t index = 0, flag = 0;

	buf = string_duplicate(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (string_locate(delim, *bufp) != NULL && flag == 0)
		{
			token_size++;
			flag = 1;
		}

		else if (string_locate(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}

	tokens = malloc(sizeof(char *) * (token_size + 1));
	if (!tokens)
	{
		free(buf);
		return (NULL);
	}

	token = strtok(buf, delim);

	while (token)
	{
		tokens[index] = string_duplicate(token);
		if (tokens[index] == NULL)
		{
			free_buffers(tokens);
			return (NULL);
		}

		token = strtok(NULL, delim);
		index++;
	}

	tokens[index] = NULL;
	free(buf);

	return (tokens);
}
