#include "shell.h"
/**
* add_node -add node at the end of list
* @head:double ptr to the head
* @tok_: data part of the new node
* Return: ptr to new node/null
*/
CMD *add_node(CMD **head, char *tok_)
{
	CMD *new = malloc(sizeof(CMD));
	CMD *lastnode;

	if (new == NULL)
		return (NULL);
	new->cmd_name = strdup(tok_);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	lastnode = *head;
	while (lastnode->next != NULL)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = new;
	return (*head);
}
