#include "main.h"
void _usage_erro(int p, char *name, char *cmd)
{
	char *err_del = ": ", *err_usage = "usage VAIABLE", *set_ = "VALUE";
	char *num = print_number(p);

	write(2, name, strlen(name));
	write(2, err_del, strlen(err_del));
	write(2, num, strlen(num));
	write(2, err_usage, strlen(err_usage));
	if (strcmp("setenv", cmd) == 0)
		write(1, set_, strlen(set_));
	write(2, NEWL, strlen(NEWL));
}
/**
* _setenv - set pwd and olpwd after opening a directory
* @arr: array of arguements
* @p_name: shell name
* @p_count: process count
* Return: 0-sucess -1 failure
*/
int _setenv(char **arr, char *p_name, int p_count)
{
	char *env_tok, *new, **append;
	int i = 0;

	new = malloc(strlen(arr[1]) + strlen(arr[2]) + 3);
	if (new == NULL)
		return (-1);
	if (arr[1] == NULL|| arr[2] == NULL)
	{
		_usage_erro(p_count, p_name, arr[0]);
		return (-1);
	}
	new[0] = '\0';
	strcpy(new, arr[1]);
	strcat(new, "=");
	strcat(new, arr[2]);
	while (environ[i] != NULL)
	{
		env_tok = strtok(strdup(environ[i]), "=");
		if (strcmp(env_tok, arr[1]) == 0)
		{
			free(env_tok);
			environ[i] = new;
			return (1);
		}
		free(env_tok);
		i++;
	}
	append = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (environ[i] != NULL)
	{
		append[i] = environ[i];
		i++;
	}
	append[i] = new;
	append[i + 1] = NULL;
	environ = append;
	return (0);
}
