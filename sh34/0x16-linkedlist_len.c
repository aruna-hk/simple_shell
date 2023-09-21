#include "shell.h"
/**
* list_len - return numbere of elements in list
* @h: head ptr
* Return: 0 if empty, elements if not empty
*/
size_t list_len(const CMD *h)
{
	size_t elements = 0;

	if (h == NULL)
		return (elements);
	while (h != NULL)
	{
		elements++;
		h = h->next;
	}
	return (elements);
}
