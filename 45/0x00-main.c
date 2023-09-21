#include "shell.h"

/**
* main -sets up environment and choose execution path
* @args: number of arguements
* @arglist: arguement list
* Return: 0-sucess /exit status
*/
int main(int args, char **arglist)
{
	int p_count = 0, fd, n;
	char *full_path;

	if (args >= 2)
	{
		full_path = get_dir(arglist[1], FILE_FLAG);
		fd = open(full_path, O_RDONLY);
		if (fd == -1)
		{
			perror(arglist[0]);
			return (errno);
		}
		dup2(fd, STDIN_FILENO);
	}
	n = _start_prompt(arglist[0], &p_count);
	exit(n);
}
