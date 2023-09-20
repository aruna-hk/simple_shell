#include "shell.h"
/**
* execute_line - execute command with execve sys call
* @name: shell name
* @arr: program count
* Return: 0/ errro number
*/
int execute_line(char **arr, char *name)
{
	int sig, status;
	pid_t process;

	process = fork();

	if (process != 0)
	{
		wait(&sig);
		if (WIFEXITED(sig))
		{
			status = WEXITSTATUS(sig);
			return (status);
		}
	}
	else if (process == 0)
	{
		if (execve(arr[0], arr, environ) == -1)
		{
			perror(name);
			exit(127);
		}
		else
			exit(EXIT_SUCCESS);
	}
	return (0);
}
