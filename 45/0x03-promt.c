#include "shell.h"
/**
* _start_prompt - shell entry point
* @nme:number of arguements
* @p_count: process count
* Return: 0/errno
*/
int _start_prompt(char *nme, int *p_count)
{
	static int prev_return;
	ssize_t nread;
	size_t r_read;
	char *f, **arr, *f2, *line = NULL;
	int child_id = 0, n = 0, b_in = 0;
	int i =0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			if (child_id == 0)
				write(1, P_STRING, strlen(P_STRING));
			else
				write(1, C_STRING, strlen(C_STRING));
		}
		nread = getline(&line, &r_read, stdin);
		if (nread == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(1, NEWL, strlen(NEWL));
			break;
		}
		line[nread - 1] = '\0';
		while (*line == ' ')
			line++;
		if (*line == '\0')
			continue;
		f = strtok(strdup(line), " ");
		if ((strcmp(f, nme) == 0 && f2 == NULL) || strcmp(f, "exit") == 0)
		{
			n = create_child(nme, f, strtok(NULL, " "));
			continue;
		}
	}
	return (0);
}
