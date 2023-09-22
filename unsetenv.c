#include "main.h"
/**
* usage_error -unset env erro messsag
* @p_name: shell name
* @p_count: process count
*/
void usage_error(char *p_name, int p_count)
{
	char *err_del = ": ";
	char *num;
	char *usage = "unsetenv VARIABLE";

	num = print_number(p_count);
	write(2, p_name, strlen(p_name));
	write(2, err_del, strlen(err_del));
	write(2, num, strlen(num));
	write(2, err_del, strlen(err_del));
	write(2, usage, strlen(usage));
	write(2, NEWL, strlen(NEWL));
	free(num);
}
/**
* un_setenv -unset environment
* @arr: array of arguements and command o
* @p_name: shell name
* @p_count: process count
* Return: 0
*/
int un_setenv(char **arr, char *p_name, int p_count)
{
	if (arr[1] == NULL)
	{
		usage_error(p_name, p_count);
		return (0);
	}
	unsetenv(arr[1]);
	return (0);
}
