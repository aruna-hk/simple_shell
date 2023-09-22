#include "main.h"
/**
*/
char *line_clean(char *line)
{
        while (*line == ' ')
                line++;

        if (*line == '\0')
                return (NULL);

        return (line);
}    

/**
* _start_prompt - shell entry point
* @name:number of arguements
* @p_count: process count
* Return: 0/errno
*/
int _start_prompt(char *name, int *p_count)
{
	static int prev_return;
	char *line = NULL;
	ssize_t nread;
	size_t r_read;
	char *p_string, *first_s, **arr;
	int child_id = 0, n = 0, b_in = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			if (child_id == 0)
				p_string = "$ ";
			else
				p_string = " ($) ";
			write(1, p_string, strlen(p_string));
		}
		nread = getline(&line, &r_read, stdin);
		if (nread == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(1, NEWL, strlen(NEWL));
			break;
		}
		line[nread - 1] = '\0';
		line = line_cleanup(line);
	}
	return (n);
}
