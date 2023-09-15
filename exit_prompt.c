#include "shell.h"

/**
* exit_cmd : Manages the exit of the cmd
* @cmd: The tokenized cmd
* @line: The read input from stdin
*
* Return: Nothing
*/
void exit_cmd(char **cmd, char *line)
{
	/*Free memory for the original input line*/
	free(line);

	/*Free memory for the command and its arguments*/
	free_buffs(cmd);

	/*Exit the program with a status code of 0 (indicating successful termination)*/
	exit(0);
}
