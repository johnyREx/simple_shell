#include "shell.h"

/**
 * read_user_input - reads the user inpur passed
 *
 * Return: nothing
 */

void read_user_input(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *argv[2];

	while (1)
	{
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			write(STDOUT_FILENO, "\nExiting shell...\n", 20);
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strlen(command) == 0)
		{
			continue;
		}
		argv[0] = command;
		argv[1] = NULL;
		execute_command(argv);
	}
}
