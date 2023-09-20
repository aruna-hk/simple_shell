#include "shell.h"
/**
* prompt - start ptomt
* @name: shell name
* Return: err_no
*/
int prompt(char *name)
{
	char *line = NULL;
	ssize_t r_read, n;
	size_t n_read;
	char *p_string = "$ ";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, p_string, strlen(p_string));
		r_read = getline(&line, &n_read, stdin);
		if (r_read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(1, NEWL, strlen(NEWL));
			break;
		}
		line[r_read - 1] = '\0';
		while (*line == '\0')
			line++;
		if (*line == '\0')
			continue;
		n = execute(line, name);
	}
	if (!isatty(STDIN_FILENO))
		dup2(STDIN_FILENO, 0);
	return (n);
}
