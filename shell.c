#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct flags
{
	bool interactive;
} flags;

struct info
{
	int final_exit;
	int ln_count;
} info;

typedef struct information
{
	int argc;
	char **argv;
	char *args;
	char *chemin;
	unsigned int line_count;
	int histcount;
	int linecount_flag;
	char **environ;
	int env_changed;
	char **cmd_entree;
	int err_num;
	int readfd;
	int status;
	int *fname;
	int cmd_buf_type;
<<<<<<< HEAD
} my_info
=======
} my_info;
>>>>>>> c3f8e3667044da196eddccc97df5662330c8f9f7

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#define ENTREE 1024
#define TAILLE_ENTREE 1024
#define FLASH -1
#define LINE 0

int check_builtin(char **cmd, char *buf);
void display_prompt(void);
void handle_signal(int m);
char **tokenize_string(char *line);
char **test_path_validity(char **path, char *command);
char *append_path(char *path, char *cmd);
int handle_builtin(char **cmd, char *line);
void handle_exit(char **cmd, char *line);
ssize_t my_input(my_info *info, char **entree, size_t *longueur);


int string_compare(const char *strl, const char *str2);
int string_length(const char *s);
int string_n_compare(const char *str1, const char *str2, size_t n);
char *string_duplicate(const char *s);
char *string_locate(const char *s, char c);

void free_buffer_array(char **buffer);

char *get_path_from_env(void);
void execute_command(char *path, char **cmd);
void print_string_to_stdout(char *s);
int _putchar(char c);

#endif
