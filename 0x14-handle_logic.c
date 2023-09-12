#include "main.h"
/**
**/
int comma_tok(char *name, char **line, int *p_no)
{
	int i = 0, j = 0, l = 0;
	int n;
	char **tok;
	char **tok_;
	char **or_tok;

	tok = tokenizer(line, ";");
	while (tok[i] != NULL)
	{
		tok_ = tokenizer(&tok[i], "&&");
		j = 0;
		while (tok_[j] != NULL)
		{
			or_tok = tokenizer(&tok_[j], "||");
			l = 0;
			while (or_tok[l] != NULL)
			{
				errno = 0;
				n = exec_command(name, &or_tok[l], p_no);
				if (n == 0)
					break;
				l++;
			}
			j++;
		}
		i++;
	}
	return (n);
}	
