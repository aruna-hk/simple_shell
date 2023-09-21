#include "shell.h"
void free_nodes(CMD *head);
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
	free_nodes(head);
	return (arrstring);
}

void free_nodes(CMD *head) {
    while (head != NULL) {
        CMD *temp = head;
        head = head->next;
        free(temp->cmd_name);
        free(temp);         
    }
}

