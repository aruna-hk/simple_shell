#include "main.h"
/**
* p_error - print error incase of failure to change directory
* @p_name: program name
* @p_count: proces count
* @to: changind dir to
*/
void p_error(char *p_name, int p_count, char *to)
{
	char *cmd = "cd";
	char *errm = "can't cd to ";
	char *err_del = ": ";
	char *num = print_number(p_count);

	write(2, p_name, strlen(p_name));
	write(2, err_del, strlen(err_del));
	write(2, num, strlen(num));
	write(2, err_del, strlen(err_del));
	write(2, cmd, strlen(cmd));
	write(2, err_del, strlen(err_del));
	write(2, errm, strlen(errm));
	write(2, to, strlen(to));
	write(2, NEWL, strlen(NEWL));
	free(num);
}
/**
* home - change dirctory tho home
* @to: to dirtory home
* @p_name: chell name
* @p_count: process count
* Return: exit code
*/
int home(char *to, char *p_name, int p_count)
{
	char *env = getenv("HOME");
	int n;

	if (env == NULL)
		env = getenv("PWD");
	n = chdir(env);
	if (n == 0)
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getenv("HOME"), 1);
	}
	else
		p_error(p_name, p_count, to);
	return (0);
}
/**
* old_wd - change to old working directory
* @olwd: oldworkind directory
* @to: changrin to
* @p_name: shell name
* @p_count: process count
* Return: exit status
*/
int old_wd(char *olwd, char *to, char *p_name, int p_count)
{
	int n = 0;

	char *wd = getenv("PWD");

	if (olwd == NULL)
	{
		olwd = wd;
		write(1, olwd, strlen(olwd));
		write(1, NEWL, strlen(NEWL));
		return (0);
	}
	n = chdir(olwd);
	if (n == 0)
	{
		write(1, olwd, strlen(olwd));
		write(1, NEWL, strlen(NEWL));
		setenv("PWD", olwd, 1);
		setenv("OLDPWD", wd, 1);
	}
	else
		p_error(p_name, p_count, to);
	return (0);
}
/**
* step_back - step back one step ..//../
* @to: to directory
* @p_name: shell name
* @p_count: process count
* Return: exit status
*/
int step_back(char *to, char *p_name, int p_count)
{
	int len;
	char *wd = getenv("PWD");
	char *str = strdup(getenv("PWD"));

	len = strlen(str) - 1;

	while (str[len] != '/')
	{
		str[len] = '\0';
		len--;
	}
	str[len] = '\0';
	len = chdir(str);
	if (len == 0)
	{
		setenv("OLDPWD", wd, 1);
		setenv("PWD", str, 1);
	}
	else
		p_error(p_name, p_count, to);
	free(str);
	return (0);
}
/**
* change_dir - changes directory
* @arr: array of arguements
* @p_name: shell name
* @p_count: process count
* Return: exit status
*/
int change_dir(char **arr, char *p_name, int p_count)
{
	char *path;
	int i;
	char *env = getenv("PWD");

	if (arr[1] == NULL)
	{
		setenv("OLDPWD", env, 1);
		setenv("PWD", getenv("HOME"), 1);
		return (home(arr[1], p_name, p_count));
	}
	if (strcmp(arr[1], "-") == 0)
	{
		return (old_wd(getenv("OLDPWD"), arr[1], p_name, p_count));
	}
	if (strcmp(arr[1], "..") == 0 || strcmp(arr[1], "../") == 0)
		return (step_back(arr[1], p_name, p_count));
	if (*arr[1] == '/')
	{
		i = chdir(arr[1]);
		if (i == 0)
		{
			setenv("PWD", arr[1], 1);
			setenv("OLDPWD", env, 1);
		}
		else
			p_error(p_name, p_count, arr[1]);
		return (0);
	}
	path = full_path(arr[1], FILE_FLAG);
	i = chdir(path);
	if (i == 0)
	{
		setenv("OLDPWD", env, 1);
		setenv("PWD", path, 1);
	}
	else
		p_error(p_name, p_count, arr[1]);
	free(path);
	return (0);
}
