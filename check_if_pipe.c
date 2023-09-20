#include "shell.h"
/**
* check_pipe - chekc if piped input
* @str: line
* Return: 0-if -1 if not
*/
int check_pipe(char *str)
{
	while (*str != '\0')
	{
		if (*str == '|')
			return (0);
		str++;
	}
	return (-1);
}
