#include "main.h"
/**
* arr_strings - convert list to array of strings
* @ptr: token list
* Return: array of tokens
*/
char **arr_strings(CMD **ptr)
{
	int i = 0;
	CMD *head = *ptr;
	size_t number = list_len(head);

	char **arr_of_strings = malloc((number + 1) * sizeof(char *));

	if (arr_of_strings == NULL)
	{
		freeLinkedList(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		free(arr_of_strings);
		return (NULL);
	}
	while (head != NULL)
	{
		arr_of_strings[i] = strdup(head->cmd_name);
		head = head->next;
		i++;
	}
	arr_of_strings[i] = NULL;
	freeLinkedList(ptr);
	return (arr_of_strings);
}
