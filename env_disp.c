#include "shell.h"
/**
 * print_env: Display the string environment to the stdout
 * 
 * Return: Always (0)
*/
void print_env(void)
{
	int i = 0;
	char *env = environ;
	char **env = environ;

	while (env[i])
	{
		/*Use the write function to print each environment variable and a newline*/
		write(STDOUT_FILENO, (const void *)env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
