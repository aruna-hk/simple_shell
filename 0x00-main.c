#include "main.h"
/**
* get_f_path - gets_full file_path
* @name: absolute name path
* @flag: file/smc flag
* Return: full path of the file
*/
char *get_f_path(char *name, int flag)
{
	char *full_path;
	char *name_, *dir;

	dir = get_dir(strdup(name), flag);
	if (*name == '/')
		return (dir);
	name_ = get_file_name(strdup(name));
	full_path = malloc(strlen(dir) + strlen(name_) + 3);
	full_path[0] = '\0';
	strcpy(full_path, dir);
	strcat(full_path, "/");
	strcat(full_path, name_);
	free(name_);
	return (full_path);
}
/**
* openerr - write oped file error to standard error
* @prog_name: program name --shell name
* @p_count: program count
* @filename: file name
*/
void openerr(char *prog_name, int p_count, char *filename)
{
	char *err_msg;
	int n;
	char *num = print_number(p_count);

	err_msg = malloc(strlen(prog_name) + strlen(filename) + 35);
	err_msg[0] = '\0';
	strcpy(err_msg, prog_name);
	strcat(err_msg, " :");
	strcat(err_msg, num);
	strcat(err_msg, " :");
	strcat(err_msg, "cannot open ");
	strcat(err_msg, filename);
	strcat(err_msg, ": No such file\n");
	n = write(2, err_msg, strlen(err_msg));
	if (n == -1)
		perror("err_msg");
	free(num);
	free(err_msg);
}
/**
* main -sets up environment and choose execution path
* @args: number of arguements
* @arglist: arguement list
* Return: 0-sucess /exit status
*/
int main(int args, char **arglist, char **env)
{
	int open_home, p_count = 0, fd, n;
	char **homeset;
	char *full_path;
	char *homedir = set_home();

	dprintf(STDOUT_FILENO, "%d=\n", getpid());
	if (homedir != NULL)
	{
		open_home = chdir(homedir);
		if (open_home == -1)
			perror("can't set up home directory");
		homeset = malloc(sizeof(char *) * 4);
		homeset[0] = "setenv";
		homeset[1] = "PWD";
		homeset[2] = homedir;
		homeset[3] = NULL;
		_setenv(homeset, arglist[0], p_count);
		free(homeset);
	}
	if (args >= 2)
	{
		full_path = get_f_path(arglist[1], FILE_FLAG);
		fd = open(full_path, O_RDONLY);
		if (fd == -1)
		{
			openerr(arglist[0], p_count, arglist[1]);
			return (errno);
		}
		dup2(fd, STDIN_FILENO);
	}
	n = _start_prompt(arglist[0], &p_count);
	return (n);
}
