#include "main.h"
/**
* add_node -add node at the end of list
* @head:double ptr to the head
* @tok_: data part of the new node
* Return: ptr to new node/null
*/
ALIAS *add_ALIAS(ALIAS **head, char *al_name, char *al_rp)
{
	ALIAS *new = malloc(sizeof(ALIAS));
	ALIAS *lastnode;

	if (new == NULL)
		return (NULL);
	new->aliaas = strdup(tok_);
	new->r_cmd = strdup(al_rp);
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
