#include "main.h"
/**
* search_path - search file in system path
* @name: name of file
* Return: file path/ NULL
*/
char *search_path(char *name)
{
	struct stat file_d;
	char *env_p = getenv("PATH");
	char *env_dup, *f_tok, *path;

	env_dup = strdup(env_p);
	f_tok = strtok(env_dup, ":");
	while (f_tok != NULL)
	{
		path = malloc(strlen(f_tok) + strlen(name) + 4);
		if (path == NULL)
			free(env_dup);
		strcpy(path, f_tok);
		strcat(path, "/");
		strcat(path, name);
		if (stat(path, &file_d) == 0)
		{
			free(env_dup);
			return (path);
		}
		free(path);
		f_tok = strtok(NULL, ":");
	}
	free(env_dup);
	return (NULL);
}
