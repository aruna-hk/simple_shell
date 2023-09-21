#include "shell.h"
/**
* exec_command - tokenize command and pass the command array to execve
* @name: shell_name
* @line: pointer to read_line
* @p_count: pointer to program count
* @b_in: inbuilt command identifier
* Return: 0 or errno
*/
int exec_command(char *name, char **line, int *p_count, int *b_in)
{
	char **tokens = tokenizer(line, " ");
	char *f_path = NULL, *full_path, *f_name;
	int n;
	int (*builtin)(char **, char *, int);

	if (check_if_alias(tokens[0]) != NULL)
		tokens[0] = check_if_alias(tokens[0]);
	(*p_count)++;
	if (get_built_in(tokens[0]) != NULL)
	{
		builtin = get_built_in(tokens[0]);
		n = builtin(tokens, name, *p_count);
		*b_in = 0;
	}
	else if (*tokens[0] == '/')
		n = execute_line(name, tokens[0], tokens, *p_count);
	else
	{
		f_path = get_dir(strdup(tokens[0]), CMD_FLAG);
		if (f_path == NULL)
		{
			errno = 2;
			err_mesg(name, *p_count, tokens[0], errno);
			n = 127;
		}
		else
		{
			full_path = malloc(strlen(f_path) + strlen(tokens[0]) + 3);
			f_name = get_file_name(strdup(tokens[0]));
			full_path[0] = '\0';
			strcpy(full_path, f_path);
			strcat(full_path, "/");
			strcat(full_path, f_name);
			n = execute_line(name, full_path, tokens, *p_count);
		}
	}
	return (n);
}
