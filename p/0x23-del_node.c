#include "main.h"
/**
* delete_node - delete node at give index
* @head: ptr to head double
* @index: index to insert
* Return:1-sucess/-1 failure
*/
int delete_node(ALIAS **head, unsigned int index)
{
	unsigned int count = 0;
	unsigned int nodes = 0;
	ALIAS *temp = NULL;
	ALIAS *temp2 = NULL;

	if (*head == NULL)
		return (-1);
	temp = *head;
	while (temp != NULL)
	{
		nodes++;
		temp = temp->next;
	}
	temp = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	if (index >= nodes)
		return (-1);
	while (temp != NULL)
	{
		if (count == index - 1)
		{
			temp2 = temp->next;
			if (temp2 == NULL)
				return (-1);
			temp->next = temp2->next;
			free(temp2);
			break;
		}
		count++;
		temp = temp->next;
	}
	return (1);
}
