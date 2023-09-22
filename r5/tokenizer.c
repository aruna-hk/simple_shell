#include "main.h"
/**
* tokenizer - create array of string tokens
* @str: string to tokenize a
* @del: delimitor
* Return: array of strings
*/
char **tokenizer(char *str, const char *del)
{
	int i = 1;
	char **arr;
	char *string = strdup(str);
	char *tok;

	arr = malloc(sizeof(char *) * 1);
	tok = strtok(string, del);
	while (tok != NULL)
	{
		arr[i - 1] = strdup(tok);
		arr = realloc(arr, ((i + 1) * sizeof(char *)));
		tok = strtok(NULL, del);
		i++;
	}
	arr[i - 1] = NULL;
	free(tok);
	free(string);
	return (arr);
}
