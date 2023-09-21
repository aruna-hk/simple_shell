#include "main.h"
/**
* exec_command - tokenize command and pass the command array to execve
* @name: shell_name
* @line: pointer to read_line
* @p_count: pointer to program count
* @b_in: inbuilt command identifier
* Return: 0 or errno
*/
int exec_command(char *name, char *line, int *p_count, int *b_in)
{
	char **tokens = dtokenizer(line, " ");
	char *f_path;
	struct stat file_info;
	int n;
	int (*builtin)(char **, char *, int);

	(*p_count)++;
	if (*tokens[0] == '/')
	{
		
		n = execute_line(name, tokens[0], tokens, *p_count);
	}
	else
	{
		f_path = full_path(tokens[0], CMD_FLAG);
		if (f_path == NULL)
		{
			err_mesg(name, *p_count, tokens[0], errno);
			n = 127;
		}
		else
		{
			//if (stat(f_path, &file_info) == 0)
			n = execute_line(name, f_path, tokens, *p_count);
			free(f_path);
		}
	}
	freegrid(tokens);
	return (n);
}
