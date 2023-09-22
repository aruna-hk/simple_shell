#include "main.h"
/**
* logic -  handle cmd arguemen logic
* @name: shell name
* @line: address of read line
* @p_no: program number
* @b_in: built in identifier
* Return: 0-sucess/ erro no failure
*/
int logic(char *name, char *line, int *p_no, int *b_in)
{
	int i = 0, j = 0, l = 0, n = 0;
	char **tok = NULL;
	char **tok_and = NULL;
	char **tok_or = NULL;

	while (*line == ' ')
		line++;
	tok = tokenizer(line, ";");
	while (tok[i] != NULL)
	{
		tok_and = tokenizer(tok[i], "&");
		while (tok_and[j] != NULL)
		{
			tok_or = tokenizer(tok_and[j], "|");
			while (tok_or[l] != NULL)
			{
				n = exec_command(name, tok_or[l], p_no);
				if (n == 0)
					break;
				l++;
			}
			freegrid(tok_or);
			if (n != 0 && tok_and[j + 1] != NULL && tok[i + 1] == NULL)
				break;
			tok_or = NULL;
			l = 0;	
			j++;
		}
		freegrid(tok_and);
		tok_and = NULL;
		j = 0;
		i++;
	}
	freegrid(tok);
	tok = NULL;
	return (n);
}
