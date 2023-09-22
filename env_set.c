#include "main.h"
/**
* _setenv - set pwd and olpwd after opening a directory
* @arr: array of arguements
* @p_name: shell name
* @p_count: process count
* Return: 0-sucess -1 failure
*/
int _setenv(char **arr, char *p_name, int p_count)
{
	char *num;
	char *err_del = ": ";
	char *usage = "setenv VARIABLE VALUE";

	if (arr[1] == NULL|| arr[2] == NULL)
	{
		num = print_number(p_count);
		write(2, p_name, strlen(p_name));
		write(2, err_del, strlen(err_del));
		write(2, num, strlen(num));
		write(2, usage, strlen(usage));
		write(2, NEWL, strlen(NEWL));
		return (0);
	}
	setenv(arr[1], arr[2], 1);
	return (0);
}
