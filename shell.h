#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a"
#define MAX_COMMAND_LENGTH 100
void shell_no_interactive(void);
char *read_stream(void);
int handle_builtin_commands(char **argv);
void execute_command(char **argv);
void read_user_input(void);
#endif
