#ifndef _SHELLH_
#define _SHELLH_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PATH "/"
#define P_PWD ".."
#define WD "."
#define Q "'"
#define CMD_FLAG  1
#define ALIAS_DEL "="
#define FILE_FLAG 0
#define HOME_FLAG 2
#define PWD_FLAG 3
#define HOME "/home"
#define NO_CMD ": not found\n"
#define P_STRING "$ "
#define C_STRING " ($)"

#define NEWL "\n"
extern char **environ;

char *get_dir(char *shorthand_name, int flag);
char *search_path(char *name);
char *get_f_path(char *name, int flag);
int prompt(char *name);
int execute_line(char **arr, char *name);
char **arr(char *string);
int execute(char *str, char *name);
#endif
