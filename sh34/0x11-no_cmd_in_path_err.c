#include "shell.h"
/**
* _err_msg - error message
* @name: shell name
* @p_count: process count
* @cmd_name: command name
*/
void _err_msg(char *name, int p_count, char *cmd_name)
{
	int n;
	char *num = print_number(p_count);
	char *err = malloc(strlen(name) + strlen(cmd_name) + strlen(num) + 25);

	err[0] = '\0';
	strcpy(err, name);
	strcat(err, " :");
	strcat(err, num);
	strcat(err, " :");
	strcat(err, cmd_name);
	strcat(err, NO_CMD);

	n = write(2, err, strlen(err));
	if (n == -1)
		perror("FAILED TO WRITE ERROR MESSAGE\n");
}
