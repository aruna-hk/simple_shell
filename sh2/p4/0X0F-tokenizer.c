#include "main.h"
/**
* free_list - frees linked list
* @head: list ptr
*/
void free_list(CMD *head)
{
	CMD *temp;

	if (head == NULL)
	{
		free(head);
	}
	while (head != NULL)
	{
		temp = head->next;
		free(head->cmd_name);
		free(head);
		head = temp;
	}
	free(temp);

}
/**
* tokenizer - tokenize command from user
* @string: cmd from user
* @delimiter: split according to delimiter
* Return: 2 d array of strings
*/
char **tokenizer(char **string, const char *delimiter)
{
	CMD *head = NULL;
	char *tok;
	char **arrstring;

	tok = strtok(*string, delimiter);
	while (tok != NULL)
	{
		if (tok[strlen(tok) - 1] == '\n')
			tok[strlen(tok) - 1] = '\0';
		if (add_node(&head, tok) == NULL)
			return (NULL);
		tok = strtok(NULL, delimiter);
	}
	free(tok);
	arrstring = arr_strings(head);
	free_list(head);
	return (arrstring);
}
