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
#define P_STRING "$ "
#define C_STRING " ($) "

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
int unset(void);
char *variable(char *line);

char *remov_comment(char **line);
int logic(char *name, char *line, int *p_no, int *b_in);
void and_operator(char *line, char *name, int *pcount);
void check_or(char *linei, char *name, int *pcount);

int chec_if_del(char c, const char *del);
char *_strtok(char *str, const char *del);
void free_string_array(char ***array);

int alias_(char **arr, char *p_name, int p_count);
ALIAS *add_ALIAS(ALIAS **head, char *al_name, char *al_rp);
int delete_node(ALIAS **head, unsigned int index);
char *check_if_alias(char *cmd);


char *name_(char *name);
char *full_path(char *s_name, int flag);
char *get_f_path(char *a_path);
char *search_path(char *name);
char *get_dir(char *shorthand_name, int flag, int *id);



ssize_t _getline(char **store, size_t *n_read, FILE *ptr);
void comma_cmds(char **line, int *p_count, char *name);
int create_child(char **arr, int *p_count, char *name, int *c_id, int p_ret);
char *_strtok(char *string, const char *delim);
int (*get_built_in(char *s))(char **, char *, int);
int _printenv(char **arr, char *sh_name, int p_count);
int _setenv(char **arr, char *p_name, int p_count);
int change_dir(char **arr, char *p_name, int p_count);

/**
* struct cmd_tokens - tokenizer structure
* @cmd_name: command name token
* @next: arguements
*/
struct cmd_tokens
{
	char *cmd_name;
	struct cmd_tokens *next;
};
typedef struct cmd_tokens CMD;

void freegrid(char **arr);
void openerr(char *prog_name, int p_count, char *filename);
void _err_msg(char *name, int p_count, char *cmd_name);
char *print_number(int n);
void err_mesg(char *program, int p_count, char *cmd, int err_no);
int execute_line(char *p_name, char *f_path, char **arglist, int p_count);
char *get_file_name(char *a_path);
CMD *add_begin(CMD **head, char *path);
int exec_command(char *name, char *line, int *p_count, int *b_in);
CMD *add_node(CMD **head, char *tok_);
int child_n_exit(char *name, char *line, int *n);
char **arr_strings(CMD **ptr);
int _exit_(char *name, char *string);
size_t list_len(const CMD *h);
char **tokenizer(char *string, const char *delimiter);

int env_set(char *env, char *value);

int _start_prompt(char *name, int *p_count);
char *set_home(void);
void freeLinkedList(CMD **head);
char **dtokenizer(char *str, const char *del);
void p_e_error(char *name, int p_no, char **il_no);
int un_setenv(char **arr, char *p_name, int p_count);
#endif
