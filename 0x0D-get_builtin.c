#include "main.h"
/**
* get_built_in -- find and return pointer to--------
* respective function to getting necessary value with va_arg-
* @s: sign character
* Return: pointer to operators function/NULL
*/
int (*get_built_in(char *s))(char **, char *, int)
{
	int i = 0;

	built_ins cmds[] = {
		{"cd",  change_dir},
		{"env", _printenv},
		{'\0', NULL},
	};
	while (cmds[i].cmd_name != NULL)
	{
		if (strcmp(s, cmds[i].cmd_name) == 0)
		{
			return (cmds[i].cmd);
		}
		i++;
	}
	return (NULL);
}
