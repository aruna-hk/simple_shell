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
#define P_W_D "."
#define CMD_FLAG  1
#define FILE_FLAG 0
#define HOME "/home"
#define NO_CMD ": not found\n"

int comma_tok(char *name, char **line, int *p_no);
#define NEWL "\n"
extern char **environ;

struct in_cmd
{
	char *cmd_name;
	int (*cmd)(char **, char *, int);
};
typedef struct in_cmd built_ins;


void and_operator(char *line, char *name, int *pcount);
void check_or(char *linei, char *name, int *pcount);


ssize_t _getline(char **store, size_t *n_read, FILE *ptr);
void comma_cmds(char **line, int *p_count, char *name);
int create_child(char **arr, int *p_count, char *name, int *c_id, int p_ret);
char *_strtok(char *string, const char *delim);
int (*get_built_in(char *s))(char **, char *, int);
int _printenv(char **arr);
int _setenv(char **arr, char *p_name, int p_count);
int change_dir(char **arr, char *p_name, int p_count);

char *get_f_path(char *name, int flag);
struct cmd_tokens
{
	char *cmd_name;
	struct cmd_tokens *next;
};
typedef struct cmd_tokens CMD;

void openerr(char *prog_name, int p_count, char *filename);
void _err_msg(char *name, int p_count, char *cmd_name);
char *print_number(int n);
void err_mesg(char *program, int p_count, char *cmd, int err_no);
int execute_line(char *p_name, char *f_path, char **arglist, int p_count);
char *get_file_name(char *a_path);
CMD *add_begin(CMD **head, char *path);
int exec_command(char *name, char **line, int *p_count);
CMD *add_node(CMD **head, char *tok_);
char *get_dir(char *shorthand_name, int flag);
int child_n_exit(char *name, char *line, int *n);
char *search_path(char *name);
char **arr_strings(CMD *ptr);
int _exit_(char *name, char *string);
size_t list_len(const CMD *h);
char **tokenizer(char **string, const char *delimiter);

int _start_prompt(char *name, int *p_count);
char *set_home(void);
