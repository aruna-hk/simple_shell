#include "main.h"
/**
* return_code - check errno and return corresponding return code
* @n: errno from callong function
* @b_in: built in identifier
* Return: calling function return code
*/
int return_code(int n, int *b_in)
{
	if (*b_in != 0)
		return (*b_in);
	if (n == 0)
		return (0);
	else if (n == 13)
		return (126);
	return (127);
}
/**
* _start_prompt - shell entry point
* @name:number of arguements
* @p_count: process count
* Return: 0/errno
*/
int _start_prompt(char *name, int *p_count)
{
	ssize_t nread;
	size_t r_read;
	char *p_string, *first_s, *line = NULL, *line_;
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
			free(line);
			if (isatty(STDIN_FILENO))
				write(1, NEWL, strlen(NEWL));
			break;
		}
		line[nread - 1] = '\0';
		line_ = line;
		while (*line_ == ' ')
			line_++;
		if (*line_ == '\0')
		{
			free(line);
			continue;
		}
		first_s = strtok(strdup(line), " ");
		if (strcmp(first_s, "exit") == 0)
		{
			free(first_s);
			free(line);
			exit(0);
		}
		free(first_s);
		n = logic(name, line, p_count, &b_in);
	}
	return (n);
}
