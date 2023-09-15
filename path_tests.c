#include "shell.h"

/**
* test_path - Tests to verify if path is valid
* @path: tokenized path
* @cmd: user entered cmd
*
* Return: Path appended with cmd on success otherwise NULL on failure
*/
char *test_path(char **path, char *cmd)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = verif_path(path[i], cmd);
		if (access(output, F_OK | X_OK) == 0)
			/*command found*/
			return (output);
		free(output);
		i++;
	}
	/*Command not found*/
	return (NULL);
}
