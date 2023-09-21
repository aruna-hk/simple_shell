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
	int i = 0, j = 0, l = 0, n;
	char **tok;
	char **tok_;
	char **or_tok;

	tok = dtokenizer(line, ";");
	while (tok[i] != NULL)
	{
		errno = 0;
		tok_ = dtokenizer(tok[i], "&&");
		j = 0;
		while (tok_[j] != NULL)
		{
			or_tok = dtokenizer(tok_[j], "||");
			l = 0;
			while (or_tok[l] != NULL)
			{
				n = exec_command(name, or_tok[l], p_no, b_in);
				if (n == 0)
					break;
				l++;
			}
			freegrid(or_tok);	
			if (n != 0 && tok_[j + 1] != NULL && tok[i + 1] == NULL)
			{
				*b_in = n;
				break;
			}
			j++;
		}
		freegrid(tok_);	
		i++;
	}
	freegrid(tok);
	if (n != 0 && (i > 1 || j > 1 || l > 1))
		*b_in = n;
	return (n);
}
