#include "main.h"
/**
* remov_comment - remove comment from a line
* @line: line pointer
* Return: string
*/
char *remov_comment(char **line)
{
	char *clean;
	char *cm, *mv;

	clean = *line;
	cm = strdup(*line);
	mv = cm;
	if (*cm == '#')
		return (NULL);
	while (*cm != '\0')
	{
		if (*cm == '#')
		{
			cm--;
			if (*cm != ' ')
			{
				clean = *line;
				break;
			}
			else
			{
				clean = strtok(*line, "#");
				if (clean[strlen(clean) - 1]  == ' ')
					clean[strlen(clean) - 1] = '\0';
				break;
			}
		}
		cm++;
	}
	free(mv);
/*	clean = variable(clean);*/
	return (clean);
}
