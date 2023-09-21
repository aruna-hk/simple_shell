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

/**
* struct in_cmd - built in commands
* @cmd_name: - command_name
* @cmd: pinter to a function
*/
struct in_cmd
{
	char *cmd_name;
	int (*cmd)(char **, char *, int);
};
typedef struct in_cmd built_ins;


/**
* struct alias_cmd - alias commands structure
* @aliaas: alias cmd name
* @r_cmd: real command
* @next: next command
*/
struct alias_cmd
{
	char *aliaas;
	char *r_cmd;
	struct alias_cmd *next;
};
typedef struct alias_cmd ALIAS;
char *name_(char *name);
char *full_path(char *s_name, int flag);
char *get_f_path(char *a_path);
char *search_path(char *name);
char *get_dir(char *shorthand_name, int flag, int *id);
#endif
