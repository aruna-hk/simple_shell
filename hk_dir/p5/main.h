#ifndef SHELL_HEADER
#define SHELL_HEADER
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

#define NEWL "\n"
extern char **environ;

char *full_path(char *s_name, int flag);
char *get_dir(char *shorthand_name, int flag, int *id);
void freegrid(char **arr);
char **dtokenizer(char *str, const char *del);
char *search_path(char *name);

#endif
