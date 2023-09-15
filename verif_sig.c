#include "shell.h"

/**
  verif_sig- it keeps track is interactive mode
 *@j: the signal number
 *Return: nothing
 */

void verif_sig(int j)
{
	/* Suppress the "unused parameter" warning*/
	(void)j;

	/*Write a newline character to STDERR to move the cursor to the next line*/
	write(STDERR_FILENO, "\n", 1);

	/*Write the shell prompt "$ " to STDERR to indicate that the shell is ready for input*/
	write(STDERR_FILENO, "$ ", 2);
}
