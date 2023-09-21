#include "main.h"
/**
* add_begin - add node at the beggining of the list
* @head: ptr to the head of the list
* @path: nterger number to be inserted in the new node
* Return: null is malloc fails,, ptr to new node
*/
CMD *add_begin(CMD **head, char *path)
{
	CMD *new = malloc(sizeof(CMD));

	if (new == NULL)
		return (NULL);
	new->cmd_name = strdup(path);
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		return (*head);
	}
	new->next = *head;
	*head = new;
	return (*head);
}
