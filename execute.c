#include "shell.h"
/**
* execute - cordinate execution of commands
* @str: strin input
* @name: shell name
* Return: err_number
*/
int execute(char *str, char *name)
{
	char **ar_ =  arr(strdup(str));

	return (execute_line(ar_, name));
}
