#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a"
extern char **environ;

void shell_interactive(void);
void shell_no_interactive(void);
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
int new_process(char **args);
int own_cd();
int own_env();
int own_help();
int own_exit();
char *read_stream(void);

#endif
