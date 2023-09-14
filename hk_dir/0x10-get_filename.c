#include "main.h"
/**
* get_file_name - gets file name
* @a_path: absolute path
* Return: filename | NULL
*/
char *get_file_name(char *a_path)
{
	char *tok;

	tok = strtok(a_path, "/");
	while (tok != NULL)
	{
		if (strcmp(tok, P_PWD) != 0 && strcmp(tok, WD) != 0)
			return (tok);
		tok = strtok(NULL, "/");
	}
	return (NULL);
}
