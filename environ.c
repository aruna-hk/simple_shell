#include "shell.h"

/**
 *verif- Verifies whether its a built in function
 *@ucmd: tokenized user input
 *@buffer: line drived from the getline function
 *Return: 1 if ucmd excuted 0 if ucmd is not executed
 */
int verif(char **ucmd, char *buffer)
{
	if (handle_builtin(ucmd, buffer))

	/*If the command is a built-in, handle it and return 1*/
		return (1);
	else if (**ucmd == '/')
	{
		/*If the command starts with '/', assume it's an absolute path and execute it*/
		execute(ucmd[0], ucmd);
		execution(ucmd[0], ucmd);
		return (1);
	}
	
	/*If the command is not a built-in and doesn't start with '/', return 0*/
	return (0);
}
