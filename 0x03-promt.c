#include "main.h"
/**
* return_code - check errno and return corresponding return code
* @n: errno from callong function
* @b_in: check if built in cmd
* Return: calling function return code
*/
int return_code(int n, int *b_in)
{

	if (*b_in != 0)
		return (*b_in);
	else if (n == 0)
		return (0);
	else if (n == 13)
		return (126);
	return (127);
}
/**
* set_p_exit - set privious exit environment variable
* @n: previous exit status
* @name: shell name
* @p_count: process count
* Return: exit status
*/
int set_p_exit(int n, char *name, int p_count)
{
	char **m;

	m = malloc(sizeof(char *) * 4);
	m[0] = "setenv";
	m[1] = "?";
	m[2] = print_number(n);
	m[3] = NULL;
	_setenv(m, name, p_count);
	free(m);
	return (n);
}
/**
* _start_prompt - shell entry point
* @name: number of arguements
* @p_count: process count
* Return: 0/errno
*/
int _start_prompt(char *name, int *p_count)
{
	static int prev_return;
	ssize_t nread;
	size_t r_read;
	char *p_string, *first_s, **arr, *line = NULL;
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
		nread = _getline(&line, &r_read, stdin);
		if (nread == EOF)
			break;
		line[nread - 1] = '\0';
		while (*line == ' ')
			line++;
		if (*line == '\0')
			continue;
		line = remov_comment(&line);
		if (line == NULL)
			continue;
		first_s = _strtok(strdup(line), " ");
		if (strcmp(first_s, name) == 0 || strcmp(first_s, "exit") == 0)
		{
			arr = tokenizer(&line, " ");
			n = create_child(arr, p_count, name, &child_id, prev_return);
			continue;
		}
		n = logic(name, &line, p_count, &b_in);
		n = set_p_exit(n, name, *p_count);
		prev_return = n;
		n = return_code(n, &b_in);
	}
	return (n);
}
