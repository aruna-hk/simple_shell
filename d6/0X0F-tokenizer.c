#include "main.h"
/**
* free_grid - free alocated multidimensional array-- case 2d
* @grid: takes 2d array as arguement
* @height: number of rows arguemnt
*/

void freeLinkedList(CMD **head)
{
    CMD *current = *head;
    CMD *next;

    while (current != NULL)
	{
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
/**
* tokenizer - tokenize command from user
* @string: cmd from user
* @delimiter: split according to delimiter
* Return: 2 d array of strings
*/
char **tokenizer(char *string, const char *delimiter)
{
	char *tok_s = strdup(string);
	CMD *head = NULL;
	char *tok;
	char **arrstring;

	tok = strtok(tok_s, delimiter);
	while (tok != NULL)
	{
		if (tok[strlen(tok) - 1] == '\n')
			tok[strlen(tok) - 1] = '\0';
		if (add_node(&head, tok) == NULL)
			return (NULL);
		tok = strtok(NULL, delimiter);
	}
	free(tok_s);
	arrstring = arr_strings(&head);
	return (arrstring);
}
