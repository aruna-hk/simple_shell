#include "shell.h"

/**
* free_buffer - frees the buffer
* @buffer: the freed buffer
*
* Return: Nothing
*/
void free_buffs(char **buffer)
{
	int i = 0;

	if (!buffer || buffer == NULL)
		return;

	/* Loop through the array of strings and free each string*/
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	
	/*Free the array itself*/
	free(buffer);
}
