#include "main.h"
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
	char *f_path;
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
		f_path = full_path(strdup(tokens[0]), CMD_FLAG);
		if (f_path == NULL)
		{
			err_mesg(name, *p_count, tokens[0], errno);
			n = errno;
		}
		else
		{
			n = execute_line(name, f_path, tokens, *p_count);
			free(f_path);
		}
	}
	free_string_array(tokens);	
	return (n);
}
