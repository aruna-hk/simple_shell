#include "main.h"
/**
 * print_list - print content of linked list and
 * return the number of nodes
 * @h: list pinter
 * Return: number of nodes
 */
size_t print_list(const ALIAS *head)
{
	size_t len;

	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		if ((head->aliaas) != NULL)
		{
			write(1, head->aliaas, strlen(head->aliaas));
			write(1, ALIAS_DEL, strlen(ALIAS_DEL));
			write(1, Q, strlen(Q));
			write(1, head->r_cmd, strlen(head->r_cmd));
			write(1, Q, strlen(Q));
			write(1, NEWL, strlen(NEWL));
		}
		head = head->next;
	}
	return (0);
}
