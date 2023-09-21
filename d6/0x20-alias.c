#include "main.h"
static ALIAS *commands;
/**
 * print_list - print content of linked list and
 * return the number of nodes
 * Return: number of nodes
 */
size_t print_list(void)
{
	while (commands != NULL)
	{
		if ((commands->aliaas) != NULL)
		{
			write(1, commands->aliaas, strlen(commands->aliaas));
			write(1, ALIAS_DEL, strlen(ALIAS_DEL));
			write(1, Q, strlen(Q));
			write(1, commands->r_cmd, strlen(commands->r_cmd));
			write(1, Q, strlen(Q));
			write(1, NEWL, strlen(NEWL));
		}
		commands = commands->next;
	}
	return (0);
}
/**
* check_if_alias - check if command passed is alias commands
* @cmd: command name
* Return: real program name/ NULL if not alias
*/
char *check_if_alias(char *cmd)
{
	char *alias_alias = NULL;
	ALIAS *begin;

	begin = commands;
	while (commands != NULL)
	{
		if (strcmp(commands->aliaas, cmd) == 0)
		{
			alias_alias = commands->r_cmd;
			break;
		}
		commands = commands->next;
	}
	commands = begin;
	if (alias_alias != NULL)
	{
		while (commands != NULL)
		{
			if (strcmp(alias_alias, commands->aliaas) == 0)
				return (commands->r_cmd);
			commands = commands->next;
		}
	}
	commands = begin;
	return (alias_alias);
}
/**
* alias_ - create alias
* @arr: array of arguements
* @p_name:program name shell name
* @p_count: shell process count
* Return: 0-sucess
*/
int alias_(char **arr, char *p_name, int p_count)
{
	char **arr2, *num;
	int n;
	char *err_del = ": ", *err_msg = " not found";

	if (arr[1] == NULL)
		return (print_list());
	arr2 = tokenizer(arr[1], "=");
	if (arr2[1] == NULL)
	{
		while (commands != NULL)
		{
			if (strcmp(commands->aliaas, arr2[0]) == 0)
			{
				n = write(1, commands->aliaas, strlen(commands->aliaas));
				n = write(1, ALIAS_DEL, strlen(ALIAS_DEL));
				n = write(1, commands->r_cmd, strlen(commands->r_cmd));
				n = write(1, NEWL, strlen(NEWL));
				if (n == -1)
				{
					num = print_number(p_count);
					write(2, p_name, strlen(p_name));
					write(2, err_del, strlen(err_del));
					write(2, num, strlen(num));
					write(2, err_del, strlen(err_del));
				}
				return (0);
			}
			commands = commands->next;
		}
		write(1, arr[0], strlen(arr[0]));
		write(1, err_del, strlen(err_del));
		write(1, arr2[0], strlen(arr2[0]));
		write(1, err_msg, strlen(err_msg));
		write(1, NEWL, strlen(NEWL));
		return (0);
	}
	else
		commands = add_ALIAS(&commands, arr2[0], arr2[1]);
	return (0);
}
