#include "shell.h"
/**
* get_file_name - gets file name
* @a_path: absolute path
* Return: filename | NULL
*/
char *get_file_name(char *a_path)
{
char *tok;

	tok = strtok(strdup(a_path), "/");
	while (tok != NULL)
	{
		if (strcmp(tok, P_PWD) != 0 && strcmp(tok, WD) != 0)
			return (tok);
		tok = strtok(NULL, "/");
	}
	return (NULL);
}

/**
* get_f_path - gets_full file_path
* @name: absolute name path
* @flag: file/smc flag
* Return: full path of the file
*/
char *get_f_path(char *name, int flag)
{
	char *full_path;
	char *name_, *dir;

	dir = get_dir(strdup(name), flag);
	if (*name == '/')
		return (dir);
	name_ = get_file_name(name);
	full_path = malloc(strlen(dir) + strlen(name_) + 3);
	full_path[0] = '\0';
	strcpy(full_path, dir);
	strcat(full_path, "/");
	strcat(full_path, name_);
	return (full_path);
}
