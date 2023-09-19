#include "main.h"
static char *pos_string;

/**
* chec_if_del - check if a character is a delimiter
* @c: character to check
* @del: delimitor
* Return: 0-if present -1 if not
*/
int chec_if_del(char c, const char *del)
{
	while (*del != '\0')
	{
		if (*del == c)
			return (0);
		del++;
	}
	return (-1);
}
/**
* _strtok - string tokenizer
* @str: string to tokenize
* @del: delimitor
* Return: NULL if no tokens / string token
*/
char *_strtok(char *str, const char *del)
{
	char *tok;
	char cp[2];

	int len = strlen(del);

	int i = 0;

	tok = malloc(1);
	tok[0] = '\0';
	cp[0] = '\0';
	if (str == NULL)
		str = pos_string;
	if (*str == '\0')
		return (NULL);
	while (chec_if_del(*str, del) == 0)
		str++;
	if (*str == '\0')
		return (NULL);
	while (*str != '\0')
	{
		if (chec_if_del(*str, del) == 0)
		{
			while (chec_if_del(*str, del) == 0)
				*str++;
			pos_string = str;
			return (tok);
		}
		cp[0] = *str;
		cp[1] = '\0';
		tok = realloc(tok, strlen(tok) + strlen(cp) + 2);
		strcat(tok, cp);
		cp[0] = '\0';
		str++;
	}
	pos_string = str;
	return (tok);
}
