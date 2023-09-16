#include "main.h"
/**
* variables - replace variables in a line
* @line
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
			{
				env = getenv("PID");
				line++;
			}
			else
			{
				while (*line != '\0' && *line != ' ' && *line != '$')
				{
					cp_[0] = '\0';
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
			l3[0] = '\0';
			continue;
		}
		cp[0] = *line;
		cp[1] = '\0';
		l2 = realloc(l2, strlen(l2) + 2);
		strcat(l2, cp);
		line++;
	}
	return (l2);
}
