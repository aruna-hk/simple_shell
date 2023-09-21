#include "main.h"
/**
* arr_strings - convert list to array of strings
* @ptr: token list
* Return: array of tokens
*/
char **arr_strings(CMD *ptr)
{
	int i = 0;

	size_t number = list_len(ptr);

	char **arr_of_strings = malloc((number + 1) * sizeof(char *));

	if (arr_of_strings == NULL)
		return (NULL);

	if (ptr == NULL)
	{
		free(arr_of_strings);
		return (NULL);
	}
	while (ptr != NULL)
	{
		arr_of_strings[i] = strdup(ptr->cmd_name);
		ptr = ptr->next;
		i++;
	}
	arr_of_strings[i] = NULL;
	return (arr_of_strings);
}
