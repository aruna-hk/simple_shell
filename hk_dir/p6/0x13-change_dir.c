#include "main.h"
/**
* cd - change directory
* @d_name: directory to change to
* @name: shell_name
* @proc_count: process count
* @to_dir: arr of cd arguements
* Return: -1 failure/0-sucess
*/
int cd(char *d_name, char *name, int proc_count, char **to_dir)
{
	int dc;
	char *num, *del = ": ", *del_ = "cd: can't cd to ";
	char *currentpwd = getenv("PWD");
	char **dc_env;

	dc_env = malloc(sizeof(char *) * 4);
	dc  = chdir(d_name);
	if (dc == -1)
	{
		free(dc_env);
		num = print_number(proc_count);
		write(2, name, strlen(name));
		write(2, del, strlen(del));
		write(2, num, strlen(num));
		write(2, del, strlen(del));
		write(2, del_, strlen(del_));
		write(2, to_dir[1], strlen(to_dir[1]));
		write(2, NEWL, strlen(NEWL));
		return (errno);
	}
	else
	{
		dc_env[0] = "setenv";
		dc_env[1] = "OLDPWD";
		dc_env[2] = currentpwd;
		dc_env[3] = NULL;
		_setenv(dc_env, name, proc_count);

		dc_env[0] = "setenv";
		dc_env[1] = "PWD";
		dc_env[2] = d_name;
		dc_env[3] = NULL;
		_setenv(dc_env, name, proc_count);
		free(dc_env);
	}
	return (0);
}
/**
* concat_dir_name - get full_directory name to change to
* @current_dir: current dir
* @name_ofdir: arguement name
* Return: directory full path
*/
char *concat_dir_name(char *current_dir, char *name_ofdir)
{
	char *f_path;
	char *name = get_file_name(name_ofdir);

	f_path = malloc(strlen(current_dir) + strlen(name) + 5);
	f_path[0] = '\0';

	strcpy(f_path, current_dir);
	strcat(f_path, "/");
	strcat(f_path, name);

	return (f_path);
}
/**
* dirto - gets directory to change to
* Return: directory to change to
*/
char *dirto(int flag)
{
	char *dir_to;

	if (flag == HOME_FLAG)
	{
		dir_to = getenv("HOME");
		if(dir_to == NULL)
			dir_to = (getenv("PWD"));
	}
	else
	{
		dir_to = getenv("OLDPWD");
		if (dir_to == NULL)
			dir_to = getenv("PWD");
		write(1, dir_to, strlen(dir_to));
		write(1, NEWL, strlen(NEWL));
	}
	return (dir_to);
}		
/**
* change_dir - changes current working directory
* @arr: array of arguements
* @p_name: shell name
* @p_count: process count
* Return: 0- sucess -1 faiulure
*/
int change_dir(char **arr, char *p_name, int p_count)
{
	int d_len, p;
	char *dir_to;

	if (arr[1] == NULL)
		dir_to = dirto(HOME_FLAG);
	else if (strcmp(arr[1], "-") == 0)
		dir_to = dirto(PWD_FLAG);
	else if (strcmp(arr[1], "..") == 0 && arr[2] == NULL)
	{
		if (strcmp(getenv("PWD"), PATH) == 0 || strcmp(getenv("PWD"), HOME) == 0)
			dir_to = PATH;
		else
		{
			dir_to = getenv("PWD");
			d_len = strlen(dir_to);
			while (dir_to[d_len] !=  '/')
			{
				dir_to[d_len] = '\0';
				d_len--;
			}
			dir_to[d_len] = '\0';
		}
	}
	else
		dir_to = full_path(strdup(arr[1]), FILE_FLAG);
	p =  cd(dir_to, p_name, p_count, arr);
	return (p);
}
