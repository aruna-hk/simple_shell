#include "shell.h"
/**
* arr - return arrays_string
* @string: input line
* Return: arr toks
*/
char **arr(char *string)
{
	char **arr_r;

	arr_r = malloc(sizeof(char *) * 2);

	arr_r[0] = string;
	arr_r[1] = NULL;
	return (arr_r);
}
