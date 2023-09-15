#include "main.h"
/**
* remove_comment - remove comment from a line
* @line: line pointer
* Return: string
*/
char *remov_comment(char **line, int nread)
{
	char *clean;
	int i = 0;
	char *cm;

	cm = strdup(*line);
	if (*cm == '#')
		return (NULL);
	while(*cm != '\0')
	{
		if (*cm == '#')
		{
			cm--;
			if (*cm != ' ')
				return (*line);
			else
			{
				clean = strtok(*line, "#");
				if (clean[strlen(clean) - 1]  == ' ')
					clean[strlen(clean) - 1] = '\0';
				return (clean);
			}
			
		}
		cm++;
	}
	return (*line);
}
