#include "main.h"
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
	new[0] = '\0';
	strcpy(new, arr[1]);
	strcat(new, "=");
	strcat(new, arr[2]);
	while (environ[i] != NULL)
	{
		env_tok = _strtok(strdup(environ[i]), "=");
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
