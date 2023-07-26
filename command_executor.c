#include "shell.c"

/**
 * execute_args - Map if command is a biultin or a process
 * @args: Command and its flags
 *
 * Return: 1 on success, 0 otherwise
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	int (*buitlin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};

	unsigned int i;

	if (args[0] == NULL)
	{
		return (-1);
	}

	for (i = 0; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	return (new_process(args));
}
