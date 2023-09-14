#include "main.h"
/**
* remove_comment - remove comment from a line
* @line: line pointer
* Return: string
*/
char *remov_comment(char **line)
{
	char *cm = strdup(*line);
	int i = 0;

	if (*line[i] == '#')
		return (NULL);

	while(*cm != '\0')
	{
		if (*cm == '#')
		{
			cm--;
			if (*cm != ' ')
				return (*line);
			return (strtok(*line, "#"));
		}
		cm++;
	}
	return (NULL);
}
