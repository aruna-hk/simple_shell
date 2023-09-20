#include "shell.h"
/**
* _printenv - print environment variables
* @arr: array os arguements strings
* @sh_name: shell name
* @p_count: process count
* Return: 0-sucess
*/
int _printenv(char **arr, char *sh_name, int p_count)
{
	int i = 0, n;
	char *num, *del = ": ";

	arr = environ;
	while (arr[i] != NULL)
	{
		n = write(1, arr[i], strlen(arr[i]));
		n = write(1, NEWL, strlen(NEWL));
		if (n == -1)
		{
			num = print_number(p_count);
			write(2, sh_name, strlen(sh_name));
			write(2, del, strlen(del));
			write(2, num, strlen(num));
			perror(NULL);
		}
		i++;
	}
	return (0);
}
