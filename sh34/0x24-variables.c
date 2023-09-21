#include "shell.h"
/**
* variable - replace variables in a line
* @line: line
* Return: replaced variables
*/
char *variable(char *line)
{
	char *l2, *l3, *env, cp[2], cp_[2];

	l3 = malloc(1);
	l3[0] = '\0';
	l2 = malloc(1);
	l2[0] = '\0';
	while (*line != '\0')
	{
		if (*line == '$')
		{
			line++;
			if (*line == '$')
				env = print_number(getpid());
			else
			{
				while (*line != '\0' && *line != ' ' && *line != '$')
				{
					cp_[0] = *line;
					cp_[1] = '\0';
					l3 = realloc(l3, strlen(l3) + 2);
					strcat(l3, cp_);
					line++;
				}
				env = getenv(l3);
			}
			if (env != NULL)
			{
				l2 = realloc(l2, strlen(l2) + strlen(env) + 3);
				strcat(l2, env);
			}
			l3 = realloc(l3, 1);
			continue;
		}
		cp[0] = *line;
		cp[1] = '\0';
		l2 = realloc(l2, strlen(l2) + 2);
		strcat(l2, cp);
		line++;
	}
	free(l3);
	return (l2);
}
