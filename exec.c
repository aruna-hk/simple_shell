#include "shell.h"

/**
 * execution - Executes the entered users commands
 *@cmd_ptr: The command
 *@ucmd: Pointer to commands
 * Return: 0
 */
void execution(char *cmd_ptr, char **ucmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(cmd_ptr);
	}
	if (child_pid == 0)
	{
		/*Child process*/
		execve(cmd_ptr, ucmd, env);

		/*If execve fails, print an error message*/
		perror(cmd_ptr);

		/*Free allocated memory and exit with an error code*/
		free(cmd_ptr);

		/*This function frees memory for ucmd*/
		free_buffs(ucmd);
		free_buffs(ucmd);

		/*Exit with an error code (e.g., 98)*/
		exit(98);
	}
	/*Parent process*/
	else
	/*Wait for the child process to complete*/
		wait(&status);
}
