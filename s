#include "main.h"
void _usage_erro(int p, char *name, char *cmd)
{
	char *err_del = ": ", *err_usage = "usage VAIABLE", *set_ = "VALUE";
	char *num = print_number(p);

	write(2, name, strlen(name));
	write(2, err_del, strlen(err_del));
	write(2, num, strlen(num));
	write(2, err_usage, strlen(err_usage));
	if (strcmp("setenv", cmd) == 0)
		write(1, set_, strlen(set_));
	write(2, NEWL, strlen(NEWL));
	free(num);
}
/**
* _setenv - set pwd and olpwd after opening a directory
* @arr: array of arguements
* @p_name: shell name
* @p_count: process count
* Return: 0-sucess -1 failure
*/
int _setenv(char **arr, char *p_name, int p_count)
{
	int i;

	if (arr[1] == NULL|| arr[2] == NULL)
	{
		//_usage_erro(int p, char *name, char *cmd);
		return (0);
	}
	setenv(arr[1], arr[2], 1);
	return (0);
}
