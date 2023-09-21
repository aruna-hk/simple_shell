#include "shell.h"
/**
* remov_comment - remove comment from a line
* @line: line pointer
* Return: string
*/
char *remov_comment(char **line)
{
	char *clean;
	char *cm;

	clean = *line;
	cm = strdup(*line);
	if (*cm == '#' || *cm == '\0')
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
				clean = _strtok(*line, "#");
				if (clean[strlen(clean) - 1]  == ' ')
					clean[strlen(clean) - 1] = '\0';
				break;
			}
		}
		cm++;
	}
	clean = variable(clean);
	return (clean);
}
