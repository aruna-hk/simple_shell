#include "main.h"
/**
* exec_command - tokenize command and pass the command array to execve
* @name: shell_name
* @line: pointer to read_line
* @p_count: pointer to program count
* @b_in: inbuilt command identifier
* Return: 0 or errno
*/
int exec_command(char *name, char *line, int *p_count)
{
	char **tokens = tokenizer(line, " ");
	char *f_path;
	struct stat file_d;
	int n;
	int (*builtin)(char **, char *, int);

	(*p_count)++;


	if (get_built_in(tokens[0]) != NULL)
	{
		builtin = get_built_in(tokens[0]);
		n = builtin(tokens, name, *p_count);
	}
	else if (*tokens[0] == '/')
	{
		if (stat(tokens[0], &file_d) == 0)
		{
			n = execute_line(name, tokens[0], tokens, *p_count);
			if (n != 0)
				err_mesg(name, *p_count, tokens[0], errno);
		}
		
	}
	else
	{
		f_path = full_path(tokens[0], CMD_FLAG);
		if (f_path == NULL)
			 err_mesg(name, *p_count, tokens[0], errno);
		else
		{
			n = execute_line(name, f_path, tokens, *p_count);
			free(f_path);
		}
	}
	freegrid(tokens);
	return (n);
}
