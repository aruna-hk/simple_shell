#include "main.h"
/**
* set_home - set home working directory
* Return: directory to set to home
*/
char *set_home(void)
{
	char *working_dir;
	int i = 0;

	while (environ[i] != NULL)
	{
		working_dir = strtok(strdup(environ[i]), "=");
		if (strcmp(working_dir, "PWD") == 0)
		{
			working_dir = strtok(NULL, ":");
			return (working_dir);
		}
		free(working_dir);
		i++;
	}
	working_dir = getenv("HOME");
	return (working_dir);
}
