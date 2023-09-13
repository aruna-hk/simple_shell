#include "main.h"
/**
* _printenv - print environment variables
* @arr: array os arguements strings
* Return: 0-sucess
*/
int _printenv(char **arr, char *sh_name, int p_count)
{
	int i = 0;

	arr = environ;

	while (arr[i] != NULL)
	{
		write(1, arr[i], strlen(arr[i]));
		write(1, NEWL, strlen(NEWL));
		i++;
	}
	return (0);
}
