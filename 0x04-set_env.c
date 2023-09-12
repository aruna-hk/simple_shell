#include "main.h"
/**
* set_variables - set pwd and olpwd after opening a directory
*/
int _setenv(char **arr, char *p_name, int p_count)
{
	char *env_tok, *new, **append;
	int i = 0;

	new = malloc(strlen(arr[1]) + strlen(arr[2]) + 3);
	if (new == NULL)
		return (-1);
	while (arr[i] != NULL)
		i++;
	if (i < 3)
	{
		char *num = print_number(p_count);
		write(2, p_name, strlen(p_name));
		write(2, num, strlen(num));
		write(2, NEWL, strlen(NEWL));
		return (-1);
	}
	i = 0;
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
