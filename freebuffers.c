#include "shell.h"

/**
 * free_buffer_array - frees an array of buffers
 * @buffer: buffer to be freed
 *
 * Return: nothing
 */

void free_buffers(char **buffer)
{
	int i = 0;

	if (!buffer || buffer == NULL)
	{
		return;
	}
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
