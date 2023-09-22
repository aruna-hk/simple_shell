#include "main.h"
/**
* p_e_error - display exit error msg
* @name: shell_name
* @p_no: process number
* @il_no: illegal string exit
*/
void p_e_error(char *name, int p_no, char **il_no)
{
	char *num = print_number(p_no), *err;

	int len = strlen(name) + strlen(num) + strlen(il_no[0]);

	len = len + strlen(il_no[1]) + 30;

	err = malloc(len);

	err[0] = '\0';

	strcpy(err, name);
	strcat(err, ": ");
	strcat(err, num);
	strcat(err, ": ");
	strcat(err, il_no[0]);
	strcat(err, ": ");
	strcat(err, "Illegal number");
	strcat(err, ": ");
	strcat(err, il_no[1]);
	strcat(err, "\n");
	write(2, err, strlen(err));
	free(err);
	free(num);
}

