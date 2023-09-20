#include "shell.h"

/**
* _getline - getline from a file stream
* @store: pointer to buffer to store the line
* @n_read: length of line
* @ptr: file stream
* Return: -1 --failure/ number of characters read
*/
ssize_t _getline(char **store, size_t *n_read, FILE *ptr)
{
	ssize_t nn_read;
	char *rr_buffer;
	int file_descriptor = fileno(ptr), i = 0;

	*n_read = 0;
	*store = NULL;
	rr_buffer = malloc(3);
	rr_buffer[0] = '\0';
	*store = malloc(3);
	*store[0] = '\0';
	while (1)
	{
		nn_read = read(file_descriptor, rr_buffer, 1);
		if (nn_read != 1)
			break;
		if (*rr_buffer != '\0')
			*n_read += nn_read;
		if (*rr_buffer == '\0')
		{
			free(rr_buffer);
			return (*n_read);
		}
		rr_buffer[nn_read] = '\0';
		if (strcmp(rr_buffer, "\n") == 0 && i == 0)
		{
			*store = realloc(*store, *n_read + 4);
			strcat(*store, "\n");
			free(rr_buffer);
			return (*n_read);
		}
		strcat(*store, rr_buffer);
		*store = realloc(*store, *n_read + 2);
	}
	free(rr_buffer);
	return (-1);
}
