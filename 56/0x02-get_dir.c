#include "shell.h"

/**
* get_dir - getdirectpory
* @shorthand_name: string to guide search of directory
* @flag: file/ cmd
* Return: directory name
*/
char *get_dir(char *shorthand_name, int flag)
{
	char *tok, *env;
	int len;
	char *pwd = getenv("PWD");

	if (pwd == NULL)
		return (shorthand_name);
	tok = strtok(shorthand_name, PATH);
	if (flag == CMD_FLAG && (strcmp(tok, WD) != 0) && (strcmp(tok, P_PWD) != 0))
	{
		tok = search_path(shorthand_name);
		return (tok);
	}
	if (*shorthand_name == '/')
		return (shorthand_name);
	env = strdup(pwd);
	while (tok != NULL)
	{
		if (strcmp(tok, WD) == 0)
			env = env;
		if (strcmp(tok, P_PWD) == 0)
		{
			len = strlen(env);
			while (env[len] != '/')
			{
				env[len] = '\0';
				len--;
			}
			env[len] = '\0';
		}
		tok = strtok(NULL, PATH);
	}
	return (env);
}
