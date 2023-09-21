#include "main.h"
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
int main(int args, char **arglist, char **envp)
{
	int p_count = 0, fd, n;
	char *fullpath;

	environ = envp;
	if (args >= 2)
	{
		fullpath = full_path(arglist[1], FILE_FLAG);
		fd = open(fullpath, O_RDONLY);
		if (fd == -1)
		{
			free(fullpath);
			openerr(arglist[0], p_count, arglist[1]);
			exit(errno);
		}
		dup2(fd, STDIN_FILENO);
		free(fullpath);
	}
	n = _start_prompt(arglist[0], &p_count);
	return (n);
}
