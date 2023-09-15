#include "shell.h"

/**
* find_path - The path from the context environment
* Return: Path if context environment is found otherwise NULL.
*/
char *find_path(void)
{
	int x;
	char **env = environ, *path = NULL;

	/*Iterate through the environment variables*/
	while (*env)
	{

		/*Check if the current environment variable starts with "PATH="*/
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;

			/*Move the pointer past "PATH=" to get the actual path value*/
			while (*path && x < 5)
			{
				path++;
				x++;
			}

			/*Return the path value*/
			return (path);
		}

		/* Move to the next environment variable*/
		env++;
	}

	/*If "PATH" environment variable is not found, return NULL*/
	return (NULL);
}
