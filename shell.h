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

/** Structures */
struct flags
{
    bool interactive;
} flags;

struct info
{
    int final_exit;
    int ln_count;
} info;

typedef struct informations
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
} my_info;

/* Environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#define ENTREE 1024
#define TAILLE_ENTREE 1024
#define FLASH -1
#define CMD_NORM 0
#define LINE 0

/* Builtins */
int check_builtin(char **cmd, char *buf);
void display_prompt(void);
void handle_signal(int m);
char **tokenize_string(char *line);
char *test_path_validity(char **path, char *command);
char *append_path(char *path, char *cmd);
int handle_builtin(char **cmd, char *line);
void handle_exit(char **cmd, char *line);
ssize_t my_input(my_info *info, char **entree, size_t *longueur);
void print_env(void);


/* String functions */
int string_compare(const char *str1, const char *str2);
int string_length(const char *s);
int string_n_compare(const char *str1, const char *str2, size_t n);
char *string_duplicate(const char *s);
char *string_locate(const char *s, char c);

/* Free memory */
void free_buffers(char **buffer);
char *path_test_validity(char **path, char *command);

/* Other functions */
char *get_path_from_env(void);
void execute_command(char *path, char **cmd);
void print_string_to_stdout(char *s);
int _putchar(char c);
char *path_test_validity(char **path, char *command);

#endif /* SHELL_H */
