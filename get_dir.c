#include "main.h"
/**
* ss - reduce length of get_dir
* @name: name passed to getdir
* @p: int pointer
* Return: path
*/
char *ss(char *name, int *p)
{
	char *ret = malloc(strlen(name) + 2);

	ret[0] = '\0';

	*p = 1;

	strcpy(ret, "/");
	strcat(ret, name);
	return (ret);
}
/**
* get_dir - get directory to which the file is located
* @shorthand_name: name given
* @flag: cmd/file flag
* @id: identifies if full path specified by get dir
* Return: diretory /full part if specified
*/
char *get_dir(char *shorthand_name, int flag, int *id)
{
	char *sh_cpy, *tok, *pwd = getenv("PWD");
	int len;

	if (*shorthand_name == '/')
	{
		*id = 1;
		return (shorthand_name);
	}
	if (pwd == NULL)
		return (ss(shorthand_name, id));
	sh_cpy = strdup(shorthand_name);
	tok = strtok(sh_cpy, "/");
	if (strcmp(tok, shorthand_name) == 0 && flag == CMD_FLAG)
	{
		free(sh_cpy);
		*id = 1;
		return (search_path(shorthand_name));
	}
	while (tok != NULL)
	{
		if (strcmp(tok, P_PWD) == 0)
		{
			len = strlen(pwd) - 1;
			while (len >= 0)
			{
				if (pwd[len] == '/')
				{
					pwd[len] = '\0';
					break;
				}
				pwd[len] = '\0';
				len--;
			}
		}
		tok = strtok(NULL, "/");
	}
	free(sh_cpy);
	return (pwd);
}
