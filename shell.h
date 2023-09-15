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

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

void print_env(void);

/* string verifiers and handlers */
void execution(char *cmd_ptr, char **ucmd);
int _strncmp(char *str1, char *str2, int n);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
int _strlen(char *str);
char *_strchr(char *str, char c);
char *find_path(void)


/*Buitins verifier and handlers*/
char **tokenizer(char *line);
int handle_builtin(char **cmd, char *line);
void prompt_user(void);
int verif(char **ucmd, char *buffer);
void exit_cmd(char **cmd, char *line);
char *test_path(char **path, char *cmd);
char *verif_path(char *path, char *cmd)
void verif_sig(int j);



/* helper function to free memory */
void free_buffs(char **buffer);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;
struct flags
{
	bool interactive;
} flags;

#endif 
