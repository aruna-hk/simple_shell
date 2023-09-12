#include "main.h"

static char *ptr;
/**
* _strtok_- string tokenizer support function
* @string_del: string to delimit
* @string: current pos of pointer in string
* @delim: delimitor
* @i: string pos
* Return: NULL/ ptr to string
*/
char *_strtok_s(char *string_del, char *string, const char *delim, int i)
{

	char *rr;

	strncpy(string_del, string, strlen(delim));
	string_del[strlen(delim)] = '\0';
	if (strcmp(string_del, delim) == 0)
	{
		rr = malloc(i + 1);
		if (rr == NULL)
		{
			free(string_del);
			perror("malloc");
			return (NULL);
		}
		strncpy(rr, ptr, i);
		rr[i] = '\0';
		ptr = string + strlen(delim);
		while (*ptr == *delim)
			ptr += 1;
		if (*ptr == '\0')
			ptr = NULL;
		free(string_del);
		return (rr);
	}
	free(string_del);
	free(ptr);
	return (NULL);
}
/**
* _strtok - string tokenizer
* @string: takes string as arguement
* @delim: delimitore
* Return: string ptr/ null
*/
char *_strtok(char *string, const char *delim)
{
	char *ret, *string_del, *pp;
	int i = 0;
	int del_len = strlen(delim);

	if (string == NULL)
		string = ptr;
	if (string == NULL)
		return (NULL);
	string_del = malloc(del_len + 1);
	if (string_del == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	strncpy(string_del, string, del_len);
	string_del[del_len] = '\0';
	while (strcmp(string_del, delim) == 0)
	{
		string += del_len;
		strncpy(string_del, string, del_len);
		string_del[del_len] = '\0';
	}
	ptr = string;
	pp = string;
	while (*string != '\0')
	{
		if (*string == *delim)
		{
			ret = _strtok_s(string_del, string, delim, i);
			if (ret != NULL)
				return (ret);
			free(string_del);
		}
		i++;
		string++;
	}
	free(string_del);
	ptr = NULL;
	return (pp);
}
