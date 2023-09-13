#include "main.h"
/**
* logic -  handle cmd arguemen logic
* @name: shell name
* @line: address of read line
* @p_no: program number
* Return: 0-sucess/ erro no failure
*/
int logic(char *name, char **line, int *p_no, int *b_in)
{
	int i = 0, j = 0, l = 0;
	int n;
	char **tok;
	char **tok_;
	char **or_tok;

	tok = tokenizer(line, ";");
	while (tok[i] != NULL)
	{
		errno = 0;
		tok_ = tokenizer(&tok[i], "&&");
		j = 0;
		while (tok_[j] != NULL)
		{
			or_tok = tokenizer(&tok_[j], "||");
			l = 0;
			while (or_tok[l] != NULL)
			{
				n = exec_command(name, &or_tok[l], p_no, b_in);
				if (n == 0)
					break;
				l++;
			}
			if (n != 0 && tok[i + 1] == NULL)
			{
				*b_in = n;
				break;
			}
			j++;
		}
		i++;
	}
	if (n != 0)
		*b_in = n;
	return (n);
}
