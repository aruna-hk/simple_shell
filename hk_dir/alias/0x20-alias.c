#include "main.h"
static ALIAS cmds;
/**
* alias_ - create alias
* @arr: array of arguements
*/
int alias_(char **arr, char *p_name, int p_count)
{
	char *arr2;
	char *err_del = ": ";
	char *err_msg = "not_found";

	if (arr[1] == NULL)
		return (print_list(const ALIAS *cmd));
	arr2 = tokenizer(arr[0], "=");
	if (arr2[1] == NULL)
	{
		while (cmd != NULL)
		{
			if (strcmp(cmd->aliaas, arr2[1]) == 0) 
			{
				write(1, cmd->alias, strlen(cmd->alias));
				write(1, ALIAS_DEL, strlen(ALIAS_DEL));
				write(1, NEWL, strlen(NEWL));
			}
			cmd = cmd->next;
		}
		write(1, arr[0], strlen(arr2[0]));
		write(1, err_del, strlen(err_del));
		write(1, err_msg, strlen(err_msg));
		write(1, NEWL, strlen(NEWL));
	}
	else
		cmds = add_ALIAS(cmds, arr2[0], arr[1]);
	return (0);
}
