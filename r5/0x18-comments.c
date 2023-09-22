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
				free(mv);
				return (*line);
			}
			else
			{
				clean = strtok(*line, "#");
				if (clean[strlen(clean) - 1]  == ' ')
					clean[strlen(clean) - 1] = '\0';
				free(mv);
				return (clean);
			}
		}
		cm++;
	}
	free(mv);
	return (*line);
}
