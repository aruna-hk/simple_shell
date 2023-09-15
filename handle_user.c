#include "shell.h"

/**
* prompt_user - prints $ to let user type their input
* prints The cmd prompt 
* Return: Nothing
*/
void prompt_user(void)
{

	/*Check if STDIN and STDOUT are associated with a terminal (interactive mode)*/
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;

	/*If the shell is in interactive mode, print the prompt "$ " to STDERR*/
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
