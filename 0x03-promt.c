#include "shell.h"
/**
* _start_prompt - shell entry point
* @name:number of arguements
* @p_count: process count
* Return: 0/errno
*/
int _start_prompt(char *name, int *p_count)
{
	static int prev_return;
	ssize_t nread;
	size_t r_read;
	char *f, **arr, *line = NULL;
	int child_id = 0, n = 0, b_in = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			if (child_id == 0)
				write(1, P_STRING, strlen(P_STRING));
			else
				write(1, C_STRING, strlen(C_STRING));
		}
		nread = _getline(&line, &r_read, stdin);
		if (nread == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(1, NEWL, strlen(NEWL));
			break;
		}
		line[nread - 1] = '\0';
		while (*line == ' ')
			line++;
		line = remov_comment(&line);
		if (line == NULL)
			continue;
		f = strtok(strdup(line), " ");
		if ((strcmp(f, name) == 0 && strtok(NULL, " ") == NULL) || strcmp(f, "exit") == 0)
		{
			arr = tokenizer(&line, " ");
			n = create_child(arr, p_count, name, &child_id, prev_return);
			continue;
		}
		n = logic(name, &line, p_count, &b_in);
		prev_return = n;
	}
	return (n);
}
