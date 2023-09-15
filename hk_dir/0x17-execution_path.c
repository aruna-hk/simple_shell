#include "main.h"
static ALIAS *commands = NULL;

void *check_if_alias_present(char ***cmd, ALIAS *com)
{
        int i = 0;

        while (com != NULL)
        {
                if (strcmp((com->aliaas), *cmd[i]) == 0)
                {
                        *cmd[i] = com->r_cmd;
                }
                com = com->next;
        }
}

/**
* exec_command - tokenize command and pass the command array to execve
* @name: shell_name
* @line: pointer to read_line
* @p_count: pointer to program count
* Return: 0 or errno
*/
int exec_command(char *name, char **line, int *p_count, int *b_in)
{
	char **tokens = tokenizer(line, " ");
	char *f_path, *full_path, *f_name;
	int n;
	int (*builtin)(char **, char *, int);

	check_if_alias_present(&tokens, commands);
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
			err_mesg(name, *p_count, tokens[0], errno);
			n = errno;
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
/**
* alias_ - create alias
* @arr: array of arguements
*/
int alias_(char **arr, char *p_name, int p_count)
{
        char **arr2;
        char *err_del = ": ";
	int i = 0;
        char *err_msg = "not_found";

	if (arr[1] == NULL)
		return(print_list(commands));
        arr2 = tokenizer(&arr[1], "=");
        if (arr2[1] == NULL)
        {
                while (commands != NULL)
                {
                        if (strcmp(commands->aliaas, arr2[1]) == 0)  
                        {
                                write(1, commands->aliaas, strlen(commands->aliaas));
                                write(1, ALIAS_DEL, strlen(ALIAS_DEL));
                                write(1, commands->r_cmd, strlen(commands->r_cmd));
                                write(1, NEWL, strlen(NEWL));
                        }
                        commands = commands->next;
                }
                write(1, arr[0], strlen(arr2[0]));
                write(1, err_del, strlen(err_del));
                write(1, err_msg, strlen(err_msg));
                write(1, NEWL, strlen(NEWL));
        }
        else
	{
		while (commands != NULL)
		{
			if (strcmp(commands->aliaas, arr2[1]) == 0)
			{
				commands->aliaas = arr2[0];
				return (0);
			}
			commands = commands->next;
			i++;
		}
                commands = add_ALIAS(&commands, arr2[0], arr2[1]);
	}
        return (0);
}
