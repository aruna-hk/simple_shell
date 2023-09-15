#include "shell.h"

/**
* tokenizer - Tokenizes user input
* @line: to be tokenized (enterd by the user)
*
* Return: An array of strings 
*/
char **tokenizer(char *line)
{
	char *buffer = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	/*Duplicate the input string to avoid modifying the original*/
	buffer = _strdup(line);
	if (!buffer)
		return (NULL);
	bufp = buffer;
	/*Calculate the number of tokens*/
	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	/*Allocate memory for the tokens array*/
	tokens = malloc(sizeof(char *) * (tokensize + 1));

	/*Tokenize the input string and store tokens in the array*/
	token = strtok(buffer, delim);
	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			/**
			 * Clean up and return NULL
			*/
			free(tokens);
			return (NULL);
		}
		
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	/* Memory allocation failed for a token*/
	free(buffer);
	return (tokens);
}
