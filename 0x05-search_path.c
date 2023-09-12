#include "main.h"
/**
* search_path - search file in system path
* @name: name of file
* Return : file path/ NULL
*/
char *search_path(char *name)
{
	struct stat *file_d; 
	char *env_p = getenv("PATH");

	char *f_tok, *path;

	name[strlen(name)] = '\0';
	file_d = malloc(sizeof(struct stat));
	f_tok = _strtok(strdup(env_p), ":");
	while (f_tok != NULL)
	{
		path = malloc(strlen(f_tok) + strlen(name) + 4);
		path[0] = '\0';
		strcpy(path, f_tok);
		strcat(path, "/");
		strcat(path, name);
		if (stat(path, file_d) == 0)
		{
			free(path);
			free(file_d);
			return (f_tok);
		}
		free(path);
		f_tok = _strtok(NULL, ":");
	}
	free(file_d);
	free(f_tok);
	return (NULL);
} 
