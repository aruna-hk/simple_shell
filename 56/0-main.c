#include "shell.h"
/**
* main - shell entry point
* @argc: arguments count
* @argv: arguement vector
* @envp: environment variables
* Return: execution status of the shell
*/
int main(int argc, char **argv, char **envp)
{
	int fd, n;
	char *file_name;

	environ = envp;

	if (argc == 2)
	{
		file_name = get_f_path(argv[1], FILE_FLAG);
		fd = open(file_name, O_RDONLY);
		if (fd == -1)
		{
			perror(argv[0]);
			return (EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
	}
	n = prompt(argv[0]);
	exit(n);
}
