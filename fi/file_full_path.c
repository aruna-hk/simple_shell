#include "main.h"
/**
* full_path - get full path of a file
* @s_name: short hand name
* @flag: file flag/ command flag
* Return: full path to the file
*/
char *full_path(char *s_name, int flag)
{
	int i = 0;
	char *full_path, *f_name;
	char *dup_name = strdup(s_name);
	char *dir = get_dir(s_name, flag, &i);

	if (i == 0)
	{
		f_name = name_(dup_name);
		full_path = malloc(strlen(dir) + strlen(f_name) + 4);
		full_path[0] = '\0';
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, f_name);
		free(dup_name);
		return (full_path);
	}
	free(dup_name);
	return (dir);
}
/**
* name_ -get the name of file from arg
* @name: provides name
* Return: real name
*/
char *name_(char *name)
{
	char *tok = strtok(name, "/");

	while (tok != NULL)
	{
		if (strcmp(tok, ".") != 0 && strcmp(tok, "..") != 0)
		{
			return (tok);
		}
		tok = strtok(NULL, "/");
	}
	return (NULL);
}
