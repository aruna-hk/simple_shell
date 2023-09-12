#include "main.h"
/**
* get_file_name - gets file name
* @a_path: absolute path
*/
char *get_file_name(char *a_path)
{
	char *tok;

	tok = strtok(a_path, "/");
	while (tok != NULL)
	{
		if (strcmp(tok, P_PWD) != 0 && strcmp(tok, P_W_D) != 0)
			return (tok);
		tok = strtok(NULL, "/");
	}
	return (NULL);
}
