#include "shell.h"
/**
* execute - cordinate execution of commands
* @str: strin input
* @name: shell name
* Return: err_number
*/
int execute(char *str, char *name)
{
	int i = 0;
	char **ar_ =  arr(strdup(str));

	while (ar_[i] != 0)
	{
		dprintf(STDOUT_FILENO, "%s\n", ar_[i]);
		i++;
	}
	return (execute_line(ar_, name));
}
