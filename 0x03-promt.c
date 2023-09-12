#include "main.h"
int return_code(int n)
{
	if (n == 0)
		return (0);
	else if (n == 13)
		return (126);
	return (127);
}
/**
* _start_promt - shell entry point
* @name:number of arguements
*/
int _start_prompt(char *name, int *p_count)
{
	static int prev_return = 0;
	char *line = NULL;
	ssize_t nread;
	size_t r_read;
	char *p_string, *first_s, **arr;
	int child_id = 0, n = 0;

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
		first_s = _strtok(strdup(line), " ");
		if (strcmp(first_s, name) == 0 || strcmp(first_s, "exit") == 0)
		{
			arr = tokenizer(&line, " ");
			n = create_child(arr, p_count, name, &child_id, prev_return);
			continue;
		}
		n = comma_tok(name, &line, p_count);
		prev_return = n;
		n = return_code(n);
	}
	return (n);
}
